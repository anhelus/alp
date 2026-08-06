# 5.3 Gestione dei Processi

## Cos'è un processo?

Un **processo** è un programma in esecuzione. Mentre un programma è un file statico sul disco (codice + dati), un processo è un'entità dinamica che include:

* il **codice** del programma (text section);
* i **dati** (variabili globali, heap, stack);
* lo stato della CPU (**contesto**, registri, program counter);
* le **risorse** allocate (file aperti, connessioni di rete, memoria).

!!! note "Programma vs processo"
    Un programma può avere più processi associati (es: aprire 3 finestre del browser = 3 processi dello stesso programma). Viceversa, un processo può essere generato da un programma.

## Stati di un processo

Durante la sua vita, un processo passa attraverso diversi **stati**:

```
  NEW ──→ READY ──→ RUNNING ──→ TERMINATED
              ↑          │
              │          ↓
              └── READY ← BLOCKED
```

* **NEW**: il processo viene creato.
* **READY**: il processo è pronto per essere eseguito, in attesa della CPU.
* **RUNNING**: il processo è in esecuzione sulla CPU (solo uno per core).
* **BLOCKED** (o WAITING): il processo è in attesa di un evento (I/O, segnale).
* **TERMINATED**: il processo ha terminato l'esecuzione.

### Transizioni di stato

1. **NEW → READY**: il caricamento del programma in memoria è completato.
2. **READY → RUNNING**: lo scheduler assegna la CPU al processo.
3. **RUNNING → READY**: scade il quanto di tempo (time slice) o arriva un processo a priorità maggiore.
4. **RUNNING → BLOCKED**: il processo richiede un'operazione di I/O o attende un evento.
5. **BLOCKED → READY**: l'evento atteso si verifica (es: lettura da disco completata).
6. **RUNNING → TERMINATED**: il processo termina o viene terminato.

## Il Process Control Block (PCB)

Il **PCB** è una struttura dati del kernel che contiene tutte le informazioni necessarie per gestire un processo:

* **ID del processo** (PID): identificatore univoco;
* **stato**: current, ready, blocked, etc.;
* **program counter**: indirizzo della prossima istruzione;
* **registri CPU**: copia del contesto quando il processo non è in esecuzione;
* **limiti di memoria**: base e limite dello spazio di indirizzamento;
* **lista dei file aperti**: descrittori di file;
* **informazioni di scheduling**: priorità, tempo di CPU usato;
* **informazioni di contabilità**: tempo di esecuzione, tempo di attesa.

Il PCB viene salvato e ripristinato a ogni **context switch**.

## Context switch

Il **context switch** è l'operazione con cui il kernel sospende un processo e ne avvia un altro:

1. Salva lo stato del processo corrente (registri, PC) nel suo PCB.
2. Carica lo stato del nuovo processo dal suo PCB.
3. Aggiorna i registri e il program counter.
4. Riprende l'esecuzione del nuovo processo.

Il context switch è puro **overhead**: la CPU non esegue lavoro utile durante questa operazione. Il tempo dipende dall'hardware e dalla complessità del sistema (tipicamente 1-10 μs).

## Creazione e terminazione

### Creazione

Un processo può crearne un altro (processo **padre** e processo **figlio**). In Unix/Linux la chiamata di sistema è `fork()`, che crea una copia quasi identica del processo padre. Il figlio può poi eseguire un programma diverso con `exec()`.

### Terminazione

Un processo termina quando:

* completa la sua esecuzione (chiamata `exit()` in Unix);
* viene terminato da un segnale (`SIGKILL`, `SIGTERM`);
* si verifica un errore irreversibile;
* il processo padre termina (in alcuni sistemi, i figli vengono terminati).

Un processo terminato ma non ancora "raccolto" dal padre (tramite `wait()`) è detto **zombie**. Un processo orfano (il padre termina prima del figlio) viene adottato dal processo `init` (PID 1).

## Processi vs Thread

Un **thread** è un'unità di esecuzione all'interno di un processo. Un processo può avere più thread che condividono lo stesso spazio di indirizzamento e le stesse risorse.

| Caratteristica | Processo | Thread |
|----------------|----------|--------|
| Spazio di indirizzamento | Separato | Condiviso |
| PCB | Proprio | Condivide quello del processo |
| Comunicazione | IPC (pipe, socket, memoria condivisa) | Memoria condivisa direttamente |
| Context switch | Più costoso | Più leggero |

## Chiamate di sistema in Unix/Linux

| Funzione | Descrizione |
|----------|-------------|
| `fork()` | Crea un nuovo processo |
| `exec()` | Sostituisce il programma in esecuzione |
| `exit()` | Termina il processo |
| `wait()` | Attende la terminazione di un figlio |
| `kill()` | Invia un segnale a un processo |
| `getpid()` | Ottiene il PID del processo corrente |


