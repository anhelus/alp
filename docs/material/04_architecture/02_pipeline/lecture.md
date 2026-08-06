# 4.2 Ciclo di Istruzione e Pipeline

## Dal ciclo fetch-execute alla pipeline

Nella [lezione precedente](../01_von_neumann/lecture.md) abbiamo visto che la CPU esegue le istruzioni seguendo il ciclo fetch-execute. Ogni istruzione richiede più passi (fetch, decode, execute, write-back). In una CPU **sequenziale**, ogni passo deve terminare prima che il successivo possa iniziare: se ogni passo impiega un ciclo di clock e ci sono 4 passi, servono 4 cicli per istruzione.

## La pipeline

La **pipeline** è una tecnica che permette a più istruzioni di essere elaborate contemporaneamente, sovrapponendo l'esecuzione dei loro passi. Funziona come una catena di montaggio: mentre la prima istruzione è in fase di execute, la seconda può essere in fase di decode, e la terza in fase di fetch.

```
Ciclo:    1       2       3       4       5       6       7
Istr 1:   F  D  E  W
Istr 2:      F  D  E  W
Istr 3:         F  D  E  W
Istr 4:            F  D  E  W
```

In una pipeline a 4 stadi, dopo il caricamento iniziale, una istruzione completa ogni ciclo di clock — idealmente **4 volte più veloce** di una CPU sequenziale.

!!! tip "Throughput vs latenza"
    La pipeline **non riduce la latenza** di una singola istruzione (servono comunque 4 cicli per completarla), ma aumenta il **throughput**: il numero di istruzioni completate per unità di tempo.

## Stadi tipici di una pipeline

Una pipeline RISC classica ha 5 stadi:

1. **IF** (Instruction Fetch): prelievo dell'istruzione dalla memoria
2. **ID** (Instruction Decode): decodifica e lettura dei registri
3. **EX** (Execute): esecuzione nell'ALU o calcolo indirizzo
4. **MEM** (Memory Access): accesso alla memoria dati (se necessario)
5. **WB** (Write-Back): scrittura del risultato nel registro

## Hazard della pipeline

Non sempre è possibile mantenere la pipeline piena. Esistono tre tipi di **hazard** (rischi) che causano *stall* (blocchi) o *flush* (svuotamenti).

### Hazard strutturali

Si verificano quando due istruzioni contemporanee richiedono la stessa risorsa hardware.

**Esempio**: se la CPU ha una sola memoria per istruzioni e dati (architettura Von Neumann classica), una istruzione in IF e una in MEM non possono accedere contemporaneamente.

**Soluzioni**: separare cache istruzioni e dati (architettura Harvard), duplicare le risorse.

### Hazard sui dati (data hazards)

Si verificano quando un'istruzione dipende dal risultato di una precedente non ancora completata.

```
ADD R1, R2, R3   ; R1 = R2 + R3
SUB R4, R1, R5   ; R4 = R1 - R5  (dipende da R1!)
```

La SUB legge R1 prima che ADD lo abbia scritto.

**Soluzioni**:

* **Bypass/forwarding**: il risultato dell'ALU viene reindirizzato direttamente allo stadio successivo, senza attendere la scrittura nel registro.
* **Stall (bolla)**: si inserisce un ciclo di attesa (NOP) per dare tempo al dato di essere pronto.

### Hazard di controllo (control hazards)

Si verificano con istruzioni di salto (branch). La CPU non sa quale istruzione prelevare dopo un salto finché non lo decodifica ed esegue.

```
JUMP label     ; salta a label
ADD R1, R2, R3 ; non so se eseguirla finché JUMP non è decodificato
```

**Soluzioni**:

* **Branch prediction**: si prevede se il salto verrà preso o meno, e si inizia a eseguire il ramo previsto.
* **Flush**: se la predizione è sbagliata, si svuota la pipeline e si ricarica l'istruzione corretta.
* **Branch delay slot**: in alcune architetture (MIPS), l'istruzione dopo il salto viene comunque eseguita.

## Profondità della pipeline

CPU moderne hanno pipeline molto profonde (14-20 stadi in Intel Pentium 4, 10-14 in architetture recenti):

**Vantaggi**: maggiore frequenza di clock, più istruzioni contemporanee.

**Svantaggi**: hazard più frequenti, maggiore complessità, maggiore penalità in caso di salti sbagliati.

## Architetture superscalari e VLIW

### Superscalare

Una CPU **superscalare** ha **più unità funzionali** in parallelo (più ALU, più unità di load/store). Può emettere e completare più istruzioni per ciclo (IPC > 1). Il compito di trovare istruzioni indipendenti da eseguire in parallelo è svolto dall'hardware.

### VLIW (Very Long Instruction Word)

L'istruzione contiene **più operazioni** da eseguire in parallelo. Il compito di schedulare le operazioni è del compilatore, non dell'hardware. Esempi: architetture Intel Itanium, DSP embedded.

## RISC vs CISC

| Caratteristica | RISC | CISC |
|----------------|------|------|
| Istruzioni | Poche, semplici, formato fisso | Molte, complesse, formato variabile |
| Pipeline | Ottimizzata, stadi uniformi | Complessa, stadi non uniformi |
| Codice | Più istruzioni per programma | Meno istruzioni per programma |
| Esempi | ARM, RISC-V, MIPS | x86, x86-64 |

!!! note "x86: CISC esternamente, RISC internamente"
    I processori x86 moderni traducono le istruzioni CISC in micro-operazioni RISC interne (`μops`), che vengono poi eseguite su un'architettura superscalare. Uniscono i vantaggi di entrambi i mondi.


