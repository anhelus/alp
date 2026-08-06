# 6.16 Puntatori a Funzione

In C, una funzione non è solo codice: ha anche un **indirizzo di memoria**, proprio come una variabile. Possiamo memorizzare questo indirizzo in un puntatore e chiamare la funzione attraverso di esso. I puntatori a funzione sono alla base di meccanismi potenti come le **callback** e la programmazione guidata dagli eventi.

## Sintassi

La dichiarazione di un puntatore a funzione specifica il tipo di ritorno e i tipi dei parametri:

```c
// puntatore a funzione che prende due int e restituisce un int
int (*pf)(int, int);
```

Le parentesi attorno a `(*pf)` sono obbligatorie: senza, `int *pf(int, int)` dichiarerebbe una funzione che restituisce un puntatore a int.

Assegnamo e usiamo il puntatore:

```c
int somma(int a, int b) { return a + b; }

int (*pf)(int, int) = &somma; // o semplicemente = somma

int risultato = pf(3, 4);     // chiamata tramite puntatore (8 è ok)
int risultato2 = (*pf)(3, 4); // forma equivalente
```

## Array di puntatori a funzione

Possiamo creare tabelle di funzioni, utili per implementare menu o macchine a stati:

```c
void funzione_a() { printf("Hai scelto A\n"); }
void funzione_b() { printf("Hai scelto B\n"); }
void funzione_c() { printf("Hai scelto C\n"); }

int main() {
    void (*menu[3])() = { funzione_a, funzione_b, funzione_c };

    int scelta;
    printf("Scegli (0-2): ");
    scanf("%d", &scelta);

    if (scelta >= 0 && scelta < 3) {
        menu[scelta](); // chiama la funzione corrispondente
    }
    return 0;
}
```

## Callback: `qsort`

La funzione `qsort` della libreria standard (<stdlib.h>) ordina un array utilizzando un **algoritmo di ordinamento rapido** (quicksort). Non sapendo a priori il tipo di dato, `qsort` accetta un **puntatore a funzione di confronto** che il programmatore fornisce.

```c
void qsort(void* base, size_t num, size_t size,
           int (*confronta)(const void*, const void*));
```

* `base`: puntatore all'array da ordinare
* `num`: numero di elementi
* `size`: dimensione in byte di ogni elemento
* `confronta`: funzione di callback che confronta due elementi

### Esempio: ordinare interi

```c
#include <stdio.h>
#include <stdlib.h>

int confronta_int(const void* a, const void* b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;

    if (ia < ib) return -1;
    if (ia > ib) return 1;
    return 0;

    // Versione compatta (attenzione a overflow):
    // return *(const int*)a - *(const int*)b;
}

int main() {
    int numeri[] = {42, 3, 17, 8, 99, 56};
    size_t n = sizeof(numeri) / sizeof(numeri[0]);

    qsort(numeri, n, sizeof(int), confronta_int);

    for (size_t i = 0; i < n; i++) {
        printf("%d ", numeri[i]);
    }
    printf("\n");
    return 0;
}
```

!!! tip "Perché `const void*`?"
    La funzione di confronto riceve puntatori generici (`void*`) e deve convertirli al tipo specifico. Il `const` assicura che la funzione di confronto non modifichi gli elementi. Il cast `(const int*)` è necessario per dereferenziare.

### Esempio: ordinare stringhe

```c
int confronta_stringhe(const void* a, const void* b) {
    const char* sa = *(const char**)a;
    const char* sb = *(const char**)b;
    return strcmp(sa, sb);
}

int main() {
    const char* frutti[] = {"banana", "mela", "albicocca", "pera", "dattero"};
    size_t n = sizeof(frutti) / sizeof(frutti[0]);

    qsort(frutti, n, sizeof(const char*), confronta_stringhe);
    // Nota: sizeof(const char*) e' la dimensione di un puntatore, non della stringa

    for (size_t i = 0; i < n; i++) {
        printf("%s\n", frutti[i]);
    }
    return 0;
}
```

!!! warning "Array di stringhe vs array di char"
    `frutti` è un array di puntatori a char (`const char*[]`). Ogni elemento è un puntatore, non una stringa. Per questo passiamo `sizeof(const char*)` a `qsort` e la funzione di confronto lavora con `const char**`.

## Esempio: calcolatrice con puntatori a funzione

```c
#include <stdio.h>
#include <stdlib.h>

int somma(int a, int b)     { return a + b; }
int differenza(int a, int b) { return a - b; }
int prodotto(int a, int b)   { return a * b; }
int quoziente(int a, int b)  { return b ? a / b : 0; }

int main() {
    int (*ops[4])(int, int) = { somma, differenza, prodotto, quoziente };
    const char* nomi[] = {"somma", "differenza", "prodotto", "quoziente"};

    int a = 20, b = 4;
    for (int i = 0; i < 4; i++) {
        printf("%s: %d\n", nomi[i], ops[i](a, b));
    }
    return 0;
}
```

