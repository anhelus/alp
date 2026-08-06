# 6.3 Funzioni in C

Nella sezione 2 abbiamo introdotto il concetto di funzione dal punto di vista della programmazione strutturata. Vediamo ora nel dettaglio la sintassi e le particolarità delle funzioni in C.

## Sintassi di base

Una funzione in C si definisce con:

```c
tipo_ritorno nome_funzione(tipo_param1 param1, tipo_param2 param2, ...) {
    // corpo della funzione
    return valore; // se il tipo_ritorno non e' void
}
```

Esempio:

```c
int massimo(int a, int b) {
    if (a > b) return a;
    return b;
}
```

## Funzioni `void`

Una funzione che non restituisce alcun valore ha tipo di ritorno `void`:

```c
void stampa_separatore() {
    printf("--------\n");
}
```

## Passaggio per valore

In C, tutti i parametri sono passati **per valore**: la funzione riceve una copia dell'argomento. Modificare il parametro all'interno della funzione non ha effetto sulla variabile originale:

```c
void raddoppia(int x) {
    x = x * 2; // modifica solo la copia locale
}

int main() {
    int n = 5;
    raddoppia(n);
    printf("%d\n", n); // stampa 5, non 10
    return 0;
}
```

Per modificare una variabile dall'esterno, dobbiamo passare un **puntatore** (simulando un passaggio per riferimento):

```c
void raddoppia(int* x) {
    *x = *x * 2; // modifica la variabile originale tramite puntatore
}

int main() {
    int n = 5;
    raddoppia(&n);
    printf("%d\n", n); // stampa 10
    return 0;
}
```

## Prototipi

In C, una funzione deve essere dichiarata (o definita) prima di essere chiamata. Se vogliamo definire le funzioni in qualsiasi ordine, usiamo i **prototipi**:

```c
#include <stdio.h>

// Prototipo (dichiarazione)
int somma(int a, int b);

int main() {
    printf("%d\n", somma(3, 4)); // OK: il prototipo e' noto
    return 0;
}

// Definizione
int somma(int a, int b) {
    return a + b;
}
```

## Funzioni ricorsive

Una funzione che chiama se stessa si dice **ricorsiva**. Serve sempre una **condizione di terminazione** per evitare chiamate infinite:

```c
int fattoriale(int n) {
    if (n <= 1) return 1;       // caso base
    return n * fattoriale(n - 1); // passo ricorsivo
}
```

## Funzioni con array come parametri

Quando passiamo un array a una funzione, questo **decade** a puntatore. La funzione non conosce la dimensione dell'array, quindi va passata esplicitamente:

```c
void stampa_array(int arr[], size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numeri[] = {10, 20, 30, 40};
    size_t n = sizeof(numeri) / sizeof(numeri[0]);
    stampa_array(numeri, n);
    return 0;
}
```

Le due dichiarazioni `int arr[]` e `int* arr` sono equivalenti come parametri di funzione.

!!! note ""
    La dimensione dell'array nell'intestazione (`int arr[4]`) viene **ignorata** dal compilatore. Il parametro è sempre un puntatore, indipendentemente dalla dimensione indicata tra le parentesi quadre.

## Variabili locali e statiche

Le variabili definite all'interno di una funzione sono **locali**: vengono create all'ingresso e distrutte all'uscita. La keyword `static` permette di mantenere il valore tra chiamate successive:

```c
int contatore() {
    static int c = 0;
    c++;
    return c;
}
```

`contatore()` restituirà `1`, `2`, `3`, ... a ogni chiamata, perché `c` mantiene il suo valore tra le invocazioni.


