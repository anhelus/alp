# 6.1 Introduzione al C

Esploriamo alcuni concetti fondamentali della programmazione in C, essenziali per scrivere dei programmi non solo funzionanti, ma anche manutenibili e robusti. In questa prima lezione, partiremo dai concetti fondamentali dell'organizzazione del codice.

## Fondamenti di Organizzazione del Codice

Man mano che un programma cresce in dimensioni e complessità, scriverlo in un unico, monolitico file diventa insostenibile. La programmazione strutturata ci fornisce gli strumenti per suddividere un problema complesso in parti più piccole e gestibili.

### Le Parole Riservate (Keyword)

Ogni linguaggio di programmazione possiede un vocabolario di base, un insieme di parole con un significato speciale e predefinito che non può essere alterato. In C, queste parole sono chiamate **keyword** (o parole chiave). Esempi comuni sono `int`, `char`, `for`, `while`, `if`, `return` e `struct`.

Queste keyword sono riservate esclusivamente per il loro scopo specifico definito dal linguaggio. Ciò significa che **non possono essere usate per nessun altro fine**, come ad esempio nominare una variabile o una funzione. Un tentativo come il seguente produrrà un errore di compilazione, perché `for` è una parola riservata per la creazione di cicli:

```c
// Codice NON valido!
int for = 10; 
```

### La Programmazione Modulare: Dividere per Governare

L'approccio modulare consiste nel suddividere il codice sorgente di un programma in più file, chiamati **moduli**. Ciascun modulo ha la responsabilità di fornire una specifica funzionalità, raggruppando dati e funzioni correlati. Ad esempio, in un'applicazione di calcolo scientifico, potremmo avere:

*   Un modulo `algebra.c` per le operazioni algebriche.
*   Un modulo `trigonometria.c` per le funzioni trigonometriche.
*   Un modulo `main.c` che funge da punto di ingresso e coordina l'uso degli altri moduli.

Questa separazione rende il codice più facile da leggere, da manutenere e da riutilizzare.

### Moduli, Prototipi e File Header

Per far sì che i moduli possano comunicare tra loro, il C utilizza una convenzione basata su due tipi di file:

1.  **File Header (`.h`)**: Funge da "interfaccia" pubblica di un modulo. Non contiene il codice effettivo delle funzioni, ma solo le loro **dichiarazioni**, chiamate **prototipi**. Un prototipo informa il compilatore su come una funzione può essere usata: il suo nome, il tipo di valore che restituisce e i parametri che accetta.
2.  **File Sorgente (`.c`)**: Contiene l'**implementazione** vera e propria, ovvero il codice, delle funzioni dichiarate nel file header corrispondente.

Quando un file (`programma.c`) ha bisogno di usare una funzione definita in un altro (`aritmetica.c`), non ha bisogno di conoscerne l'implementazione. Gli basta includere il file header (`aritmetica.h`) per "imparare" i prototipi delle funzioni che può usare.

**Esempio Pratico:**

*   **`aritmetica.h` (L'interfaccia)**
    ```c
    // Questo file contiene solo le dichiarazioni (prototipi).
    // Informa il resto del mondo che queste due funzioni esistono.
    int aggiungi(int a, int b);
    int moltiplica(int a, int b);
    ```

*   **`aritmetica.c` (L'implementazione)**
    ```c
    #include "aritmetica.h" // Includiamo la sua stessa interfaccia

    int aggiungi(int a, int b) {
        return a + b;
    }

    int moltiplica(int a, int b) {
        return a * b;
    }
    ```

*   **`programma.c` (Il client/utilizzatore)**
    ```c
    #include <stdio.h>
    #include "aritmetica.h" // Includiamo l'interfaccia del modulo che vogliamo usare

    int main() {
        int somma = aggiungi(2, 3);
        int prodotto = moltiplica(2, 3);
        printf("Somma: %d\n", somma);
        printf("Prodotto: %d\n", prodotto);
        return 0;
    }
    ```

Per compilare questo programma modulare, è necessario fornire al compilatore tutti i file sorgente (`.c`) necessari:

```bash
gcc programma.c aritmetica.c -o mio_programma
```

### Le Guardie di Inclusione (Header Guards)

Un problema comune in progetti complessi è l'**inclusione multipla**: lo stesso file header potrebbe essere incluso più volte all'interno di una singola unità di compilazione, portando a errori di ridefinizione. Per prevenire questo problema, si usa una costruzione del preprocessore chiamata **guardia di inclusione** (o *header guard*).

!!! tip "Buona pratica"
    È buona norma inserire una guardia in ogni file header:

```c
#ifndef ARITMETICA_H
#define ARITMETICA_H

// Contenuto del file header (prototipi, etc.)
int aggiungi(int a, int b);
int moltiplica(int a, int b);

#endif // ARITMETICA_H
```
Questo meccanismo assicura che il contenuto del file venga processato dal compilatore una sola volta, anche se viene incluso decine di volte.

