# 6.14 Liste Concatenate

Le **liste concatenate** sono una struttura dati dinamica in cui ogni elemento (nodo) contiene un valore e un puntatore al nodo successivo. A differenza degli array, la memoria non è contigua e la lista può crescere e restringersi a piacere.

## Il nodo della lista

Per implementare una lista, partiamo da una `struct` che rappresenta un nodo:

```c
typedef struct Nodo {
    int dato;
    struct Nodo* prossimo;
} Nodo;
```

`prossimo` è un puntatore al nodo successivo. L'ultimo nodo della lista ha `prossimo == NULL`.

## Operazioni fondamentali

### Creare un nuovo nodo

```c
Nodo* crea_nodo(int valore) {
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    if (nuovo != NULL) {
        nuovo->dato = valore;
        nuovo->prossimo = NULL;
    }
    return nuovo;
}
```

### Inserire in testa

```c
Nodo* inserisci_testa(Nodo* testa, int valore) {
    Nodo* nuovo = crea_nodo(valore);
    if (nuovo != NULL) {
        nuovo->prossimo = testa;
    }
    return nuovo; // nuovo diventa la nuova testa
}
```

### Inserire in coda

```c
Nodo* inserisci_coda(Nodo* testa, int valore) {
    Nodo* nuovo = crea_nodo(valore);
    if (nuovo == NULL) return testa;

    if (testa == NULL) return nuovo; // lista vuota

    Nodo* corrente = testa;
    while (corrente->prossimo != NULL) {
        corrente = corrente->prossimo;
    }
    corrente->prossimo = nuovo;
    return testa;
}
```

### Stampare la lista

```c
void stampa_lista(const Nodo* testa) {
    const Nodo* corrente = testa;
    while (corrente != NULL) {
        printf("%d -> ", corrente->dato);
        corrente = corrente->prossimo;
    }
    printf("NULL\n");
}
```

### Cercare un elemento

```c
int cerca(const Nodo* testa, int valore) {
    const Nodo* corrente = testa;
    while (corrente != NULL) {
        if (corrente->dato == valore) return 1; // trovato
        corrente = corrente->prossimo;
    }
    return 0; // non trovato
}
```

### Rimuovere un elemento

```c
Nodo* rimuovi(Nodo* testa, int valore) {
    if (testa == NULL) return NULL;

    // Se il nodo da rimuovere e' la testa
    if (testa->dato == valore) {
        Nodo* nuova_testa = testa->prossimo;
        free(testa);
        return nuova_testa;
    }

    Nodo* corrente = testa;
    while (corrente->prossimo != NULL && corrente->prossimo->dato != valore) {
        corrente = corrente->prossimo;
    }

    if (corrente->prossimo != NULL) {
        Nodo* da_rimuovere = corrente->prossimo;
        corrente->prossimo = da_rimuovere->prossimo;
        free(da_rimuovere);
    }

    return testa;
}
```

### Deallocare l'intera lista

```c
void libera_lista(Nodo* testa) {
    Nodo* corrente = testa;
    while (corrente != NULL) {
        Nodo* prossimo = corrente->prossimo;
        free(corrente);
        corrente = prossimo;
    }
}
```

!!! warning "Non perdere il riferimento"
    Quando si scorre la lista per deallocarla, serve una variabile temporanea per il nodo successivo: se facessimo `free(corrente); corrente = corrente->prossimo;` accederemmo a memoria già liberata.

## Esempio completo

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* prossimo;
} Nodo;

Nodo* crea_nodo(int valore) {
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    if (nuovo != NULL) {
        nuovo->dato = valore;
        nuovo->prossimo = NULL;
    }
    return nuovo;
}

Nodo* inserisci_testa(Nodo* testa, int valore) {
    Nodo* nuovo = crea_nodo(valore);
    if (nuovo != NULL) {
        nuovo->prossimo = testa;
    }
    return nuovo;
}

void stampa_lista(const Nodo* testa) {
    for (const Nodo* c = testa; c != NULL; c = c->prossimo) {
        printf("%d -> ", c->dato);
    }
    printf("NULL\n");
}

void libera_lista(Nodo* testa) {
    while (testa != NULL) {
        Nodo* prox = testa->prossimo;
        free(testa);
        testa = prox;
    }
}

int main() {
    Nodo* lista = NULL;

    lista = inserisci_testa(lista, 30);
    lista = inserisci_testa(lista, 20);
    lista = inserisci_testa(lista, 10);

    printf("Lista: ");
    stampa_lista(lista); // 10 -> 20 -> 30 -> NULL

    libera_lista(lista);
    return 0;
}
```

!!! tip "Array o lista?"
    Usiamo un array quando il numero di elementi è noto a priori e l'accesso casuale è frequente. Una lista è più adatta quando dobbiamo inserire/rimuovere elementi frequentemente in posizioni arbitrarie e la dimensione può variare dinamicamente.

