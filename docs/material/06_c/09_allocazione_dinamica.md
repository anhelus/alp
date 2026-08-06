# 6.10 Allocazione Dinamica della Memoria

Finora abbiamo lavorato con variabili la cui memoria viene gestita automaticamente: le variabili locali vivono sullo stack e vengono distrutte quando si esce dal loro ambito, mentre gli array hanno una dimensione fissa decisa in fase di compilazione. In molti casi, però, non sappiamo a priori quanta memoria ci servirà: pensiamo a un programma che legge un file di dimensioni sconosciute o a un editor di testo che deve gestire righe di lunghezza variabile.

Per questi scenari, il C mette a disposizione l'**allocazione dinamica**, che ci permette di richiedere e rilasciare memoria a piacere durante l'esecuzione del programma, su un'area di memoria chiamata **heap** (o *mucchio*).

## La libreria `<stdlib.h>`

Le funzioni per l'allocazione dinamica sono definite nell'header `<stdlib.h>`. Le quattro funzioni fondamentali sono:

* **`malloc`**: alloca un blocco di memoria di una data dimensione, senza inizializzarlo.
* **`calloc`**: alloca un blocco di memoria per un array di elementi, inizializzando tutto a zero.
* **`realloc`**: ridimensiona un blocco di memoria già allocato.
* **`free`**: rilascia un blocco di memoria precedentemente allocato, restituendolo al sistema.

## `malloc`: allocare memoria

```c
#include <stdlib.h>

int* p = (int*)malloc(10 * sizeof(int));
```

Questa chiamata chiede al sistema di riservare spazio per 10 interi. `malloc` restituisce un puntatore a `void` (`void*`), che viene convertito implicitamente dal C (il cast esplicito `(int*)` non è obbligatorio ma rende il codice più leggibile).

!!! warning "Controllare sempre il valore di ritorno"
    `malloc` può fallire se non c'è abbastanza memoria disponibile, restituendo `NULL`. È obbligatorio controllare sempre questo valore prima di usare il puntatore:

    ```c
    int* p = malloc(10 * sizeof(int));
    if (p == NULL) {
        fprintf(stderr, "Errore: memoria insufficiente.\n");
        return 1;
    }
    ```

A differenza degli array statici, la memoria allocata con `malloc` **non viene inizializzata**: i valori contenuti sono indeterminati (spazzatura).

## `calloc`: allocare e inizializzare a zero

`calloc` si usa quando vogliamo che la memoria sia azzerata prima dell'uso. Riceve il numero di elementi e la dimensione di ciascuno:

```c
int* p = (int*)calloc(10, sizeof(int));
// Tutti i 10 interi sono inizializzati a 0
```

## `free`: rilasciare la memoria

Ogni blocco allocato con `malloc`, `calloc` o `realloc` deve essere rilasciato con `free` quando non serve più:

```c
free(p);
```

!!! warning "Memory leak"
    Se dimentichiamo di chiamare `free`, la memoria rimane occupata fino alla terminazione del programma. In programmi di lunga durata (server, editor), accumulare memoria non rilasciata causa un **memory leak** che può portare all'esaurimento della RAM.

Dopo aver chiamato `free`, il puntatore non è più valido. Usarlo causerebbe *undefined behavior*. È buona pratica impostarlo a `NULL` dopo il rilascio:

```c
free(p);
p = NULL;
```

## `realloc`: ridimensionare un blocco

`realloc` permette di cambiare la dimensione di un blocco di memoria già allocato, preservando il contenuto esistente (per la minore delle due dimensioni):

```c
int* p = malloc(5 * sizeof(int));
// ... uso p con 5 elementi ...

int* temp = realloc(p, 10 * sizeof(int));
if (temp == NULL) {
    // realloc ha fallito: p è ancora valido
    fprintf(stderr, "Errore nel ridimensionamento.\n");
} else {
    p = temp; // p ora punta al nuovo blocco (da 10 elementi)
}
```

!!! tip "Usare una variabile temporanea per `realloc`"
    Assegnare direttamente `p = realloc(p, ...)` è pericoloso: se `realloc` fallisce e restituisce `NULL`, perdiamo il puntatore originale e non possiamo più liberare la memoria. Usiamo sempre una variabile temporanea per controllare il valore di ritorno.

## Esempio completo

Vediamo un programma che alloca dinamicamente un array di interi, lo popola con i primi `n` numeri naturali e poi ne stampa la somma:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Quanti numeri vuoi sommare? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Input non valido.\n");
        return 1;
    }

    int* numeri = (int*)malloc(n * sizeof(int));
    if (numeri == NULL) {
        fprintf(stderr, "Errore di allocazione.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        numeri[i] = i + 1;
    }

    int somma = 0;
    for (int i = 0; i < n; i++) {
        somma += numeri[i];
    }

    printf("La somma dei primi %d numeri e' %d.\n", n, somma);

    free(numeri);
    return 0;
}
```

## Riepilogo delle buone pratiche

* Controllare sempre che `malloc`, `calloc` e `realloc` non restituiscano `NULL`.
* Rilasciare sempre la memoria con `free` quando non serve più.
* Dopo `free`, impostare il puntatore a `NULL` per evitare usi accidentali.
* Usare una variabile temporanea con `realloc` per non perdere il puntatore originale in caso di fallimento.
* Preferire `calloc` quando abbiamo bisogno che la memoria sia inizializzata a zero.


