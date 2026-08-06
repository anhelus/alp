# 5.4 Scheduling della CPU

## Il ruolo dello scheduler

Lo **scheduler** è il componente del kernel che decide **quale processo** in stato READY deve ricevere la CPU e per **quanto tempo**. Obiettivo: massimizzare l'utilizzo della CPU garantendo tempi di risposta accettabili.

## Criteri di scheduling

* **Utilizzo CPU**: tenere la CPU occupata il più possibile (0-100%).
* **Throughput**: numero di processi completati per unità di tempo.
* **Tempo di turnaround**: intervallo tra la creazione e la terminazione del processo.
* **Tempo di attesa**: tempo totale che un processo passa nella ready queue.
* **Tempo di risposta**: tempo dalla richiesta alla prima risposta (interattività).
* **Fairness**: evitare che un processo resti a lungo senza CPU (starvation).

## Tipi di scheduler

* **Long-term scheduler** (scheduler di lungo periodo): decide quali programmi ammettere nel sistema (controlla il grado di multiprogrammazione).
* **Short-term scheduler** (scheduler di breve periodo, o **dispatcher**): decide quale processo eseguire ora, ad ogni interrupt o scadenza del quanto di tempo.
* **Medium-term scheduler**: rimuove temporaneamente processi dalla memoria (swapping) per alleggerire il carico.

## Algoritmi di scheduling

### FCFS (First-Come, First-Served)

I processi vengono eseguiti nell'ordine di arrivo. Scheduler non preemptive.

**Vantaggi**: semplice, fairness nell'ordine di arrivo.
**Svantaggi**: effetto *convoy* — un processo lungo blocca tutti i successivi; tempo di attesa medio alto.

```
Processi: P1 (24 ms), P2 (3 ms), P3 (3 ms)
Ordine FCFS: P1 → P2 → P3
Tempo attesa: P1=0, P2=24, P3=27 → media = 17 ms
```

### SJF (Shortest-Job-First)

Esegue il processo con il tempo di CPU rimanente più breve.

**Vantaggi**: tempo di attesa medio minimo (ottimale).
**Svantaggi**: richiede di conoscere il tempo di esecuzione futuro (stima basata sul passato); possibile starvation per i processi lunghi.

```
Ordine SJF: P2 (3 ms) → P3 (3 ms) → P1 (24 ms)
Tempo attesa: P2=0, P3=3, P1=6 → media = 3 ms
```

### Priority Scheduling

Ogni processo ha una priorità. Viene eseguito il processo a priorità più alta.

**Vantaggi**: gestisce processi critici in tempo reale.
**Svantaggi**: rischio di **starvation** (processi a bassa priorità mai eseguiti). Soluzione: **aging** (aumentare gradualmente la priorità dei processi in attesa).

### Round Robin (RR)

Variante preemptive di FCFS: ogni processo riceve un quanto di tempo fisso (**time quantum**, o *time slice*). Se il processo non termina entro il quanto, viene messo in coda e passa al successivo.

**Vantaggi**: buon tempo di risposta (interattività), fairness.
**Svantaggi**: il tempo medio di turnaround peggiora con quanti piccoli; l'overhead di context switch aumenta.

```
Time quantum = 4 ms
P1 (24 ms), P2 (3 ms), P3 (3 ms)

Tempo 0: P1 (4/24) → P2 (3/3) → P3 (3/3) → P1 (4/24) → P1 (4/24) → ...
Tempo attesa: P1=6, P2=4, P3=7 → media = 5.67 ms
```

L'efficacia del Round Robin dipende dal quanto di tempo:

* quanto **troppo grande**: degenera in FCFS;
* quanto **troppo piccolo**: troppo context switch.

Regola pratica: il quanto dovrebbe essere leggermente maggiore del 70-80% dei burst di CPU, tipicamente 10-100 ms.

### Multilevel Queue

La ready queue è divisa in più code, ciascuna con il proprio algoritmo di scheduling. Esempio:

* **Code interattive** (foreground): Round Robin, priorità alta;
* **Code batch** (background): FCFS, priorità bassa.

Le code possono avere priorità fissa (rischio di starvation per la coda batch) o condividere la CPU a percentuali (es: 80% foreground, 20% background).

### Multilevel Feedback Queue

Come Multilevel Queue, ma i processi possono **migrare** tra le code. Un processo che consuma troppo CPU viene spostato in una coda a priorità più bassa. Un processo in attesa da troppo tempo può essere promosso. È l'algoritmo più flessibile, usato dalla maggior parte dei sistemi operativi moderni.

## Tabella riassuntiva

| Algoritmo | Preemptive | Tempo medio attesa | Complessità |
|-----------|-----------|-------------------|-------------|
| FCFS | No | Alto | Bassa |
| SJF | Opzionale | Minimo | Media (stima necessaria) |
| Priority | Opzionale | Dipende | Media |
| Round Robin | Sì | Medio | Media |
| Multilevel Feedback | Sì | Basso | Alta |

