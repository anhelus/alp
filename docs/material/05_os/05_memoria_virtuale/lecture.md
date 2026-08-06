# 5.5 Gestione della Memoria e Memoria Virtuale

## Il problema

I programmi devono risiedere in memoria per essere eseguiti. Più programmi devono coesistere (multiprogrammazione), ma la memoria fisica è limitata. Il sistema operativo deve gestire l'allocazione della memoria in modo efficiente e sicuro.

## Spazio di indirizzamento

Ogni processo ha il proprio **spazio di indirizzamento virtuale** (es: 0x00000000 — 0xFFFFFFFF su 32 bit). Questo spazio è diviso in:

* **Text**: codice del programma (sola lettura)
* **Data**: variabili globali e statiche
* **Heap**: memoria allocata dinamicamente (malloc/new)
* **Stack**: chiamate a funzione, variabili locali

```
Indirizzo alto
+---------------+
|    Stack      |  ← cresce verso il basso
|       ↓       |
|      ...      |
|       ↑       |
|    Heap       |  → cresce verso l'alto
+---------------+
|    Data       |
+---------------+
|    Text       |
+---------------+
Indirizzo basso
```

## Partizionamento della memoria

### Partizionamento fisso

La memoria è divisa in partizioni di dimensione fissa, ciascuna contenente un processo.

**Vantaggi**: semplice.
**Svantaggi**: frammentazione interna (uno spazio inutilizzato all'interno di una partizione).

### Partizionamento variabile

Le partizioni sono create su richiesta, della dimensione esatta del processo.

**Vantaggi**: nessuna frammentazione interna.
**Svantaggi**: frammentazione esterna (spazi liberi sparsi, non contigui).

## Frammentazione

* **Frammentazione interna**: memoria allocata ma non usata (es: partizione da 10 KB per un processo da 7 KB → 3 KB sprecati).
* **Frammentazione esterna**: spazi liberi non contigui, nessuno sufficientemente grande per un nuovo processo.

La **compattazione** (riorganizzare i processi per rendere contiguo lo spazio libero) risolve la frammentazione esterna ma è costosa.

## Paginazione

La **paginazione** è la tecnica più diffusa per gestire la memoria. Divide:

* la **memoria fisica** in blocchi di dimensione fissa detti **frame** (tipicamente 4 KB);
* la **memoria virtuale** in blocchi della stessa dimensione detti **pagine**.

Ogni pagina virtuale può risiedere in qualsiasi frame fisico. La **page table** traduce gli indirizzi virtuali in indirizzi fisici.

```
Indirizzo virtuale
+--------+----------+
| Pagina | Offset   |
+--------+----------+
    │
    ↓ Page table
+--------+----------+
| Frame  | Offset   |
+--------+----------+
Indirizzo fisico
```

**Vantaggi**: niente frammentazione esterna, protezione tra processi.

## Memoria virtuale con paginazione su richiesta

Non tutte le pagine di un processo devono stare contemporaneamente in RAM. Il sistema carica una pagina solo quando viene effettivamente acceduta (**demand paging**).

Quando un processo accede a una pagina non in RAM:

1. La MMU (Memory Management Unit) rileva un **page fault**.
2. Il kernel sospende il processo.
3. Il kernel carica la pagina dal disco (swap) in un frame libero.
4. Aggiorna la page table.
5. Riprende il processo.

!!! tip "Beneficio"
    Un processo può essere molto più grande della RAM fisica. Il sistema carica solo le pagine effettivamente usate, risparmiando memoria.

## Algoritmi di sostituzione delle pagine

Quando non ci sono frame liberi, bisogna rimuovere una pagina per far posto alla nuova. Quale?

* **FIFO** (First-In, First-Out): si rimuove la pagina più vecchia. Semplice, ma soggetto all'**anomalia di Belady** (aumentare i frame può aumentare i page fault).
* **LRU** (Least Recently Used): si rimuove la pagina non usata da più tempo. Buona approssimazione dell'ottimale, costosa da implementare.
* **Optimal** (OPT): si rimuove la pagina che non verrà usata per più tempo. Teoricamente ottimale, ma impossibile da implementare (richiede conoscenza del futuro).
* **Clock** (Second Chance): variante approssimata di LRU. Ogni pagina ha un bit di riferimento. Si scorrono le pagine in cerchio; con bit=0 si rimuove, con bit=1 si azzera e si passa avanti.

## Segmentazione

La **segmentazione** divide la memoria in segmenti logici (codice, dati, stack), ciascuno con nome e dimensione variabile. L'indirizzo virtuale è una coppia `(segmento, offset)`.

**Vantaggi**: rispecchia la struttura logica del programma (protezione e condivisione facili).
**Svantaggi**: frammentazione esterna (segmenti di dimensione variabile).

I sistemi moderni combinano paginazione e segmentazione: i segmenti contengono pagine.

## Memoria virtuale: vantaggi

1. **Isolamento**: ogni processo ha il proprio spazio di indirizzamento — un crash non influisce sugli altri processi.
2. **Protezione**: una pagina può avere permessi (lettura, scrittura, esecuzione). W^X (Write XOR Execute) impedisce di scrivere codice e poi eseguirlo.
3. **Condivisione**: pagine diverse possono puntare allo stesso frame fisico (memoria condivisa tra processi, librerie condivise).
4. **Programmi più grandi della RAM**: il sistema carica solo le pagine necessarie.
5. **Semplificazione del linking**: ogni programma pensa di partire da indirizzo 0.


