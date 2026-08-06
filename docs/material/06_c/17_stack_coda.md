# 6.17 Stack e Coda con Liste Concatenate

Stack e coda sono strutture dati astratte che possiamo implementare con le liste concatenate viste nella lezione 6.14. La differenza sta nella **politica di accesso**: chi esce per primo?

## Stack (pila) — LIFO

Lo stack segue la politica **Last In, First Out**: l'ultimo elemento inserito è il primo a uscire. Come una pila di piatti.

Operazioni principali:

* **`push`**: inserisce un elemento in cima
* **`pop`**: rimuove e restituisce l'elemento in cima
* **`peek`**: restituisce l'elemento in cima senza rimuoverlo
* **`is_empty`**: verifica se lo stack è vuoto

### Implementazione

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* prossimo;
} Nodo;

typedef struct {
    Nodo* cima;
} Stack;
```

### Operazioni

```c
void push(Stack* s, int valore) {
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    if (nuovo == NULL) return;

    nuovo->dato = valore;
    nuovo->prossimo = s->cima;
    s->cima = nuovo;
}

int pop(Stack* s) {
    if (s->cima == NULL) {
        fprintf(stderr, "Stack vuoto!\n");
        exit(1);
    }

    Nodo* da_rimuovere = s->cima;
    int valore = da_rimuovere->dato;
    s->cima = da_rimuovere->prossimo;
    free(da_rimuovere);
    return valore;
}

int peek(const Stack* s) {
    if (s->cima == NULL) {
        fprintf(stderr, "Stack vuoto!\n");
        exit(1);
    }
    return s->cima->dato;
}

int is_empty(const Stack* s) {
    return s->cima == NULL;
}

void libera_stack(Stack* s) {
    while (s->cima != NULL) {
        pop(s);
    }
}
```

### Esempio

```c
int main() {
    Stack s = { NULL };

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Cima: %d\n", peek(&s)); // 30

    while (!is_empty(&s)) {
        printf("%d\n", pop(&s)); // 30, 20, 10
    }

    libera_stack(&s);
    return 0;
}
```

!!! tip "Usi dello stack"
    Lo stack è usato dal sistema operativo stesso per gestire le chiamate a funzione (call stack), e in informatica per valutare espressioni, implementare undo/redo, e negli algoritmi di backtracking.

## Coda (queue) — FIFO

La coda segue la politica **First In, First Out**: il primo elemento inserito è il primo a uscire. Come una fila alla cassa.

Operazioni principali:

* **`enqueue`**: inserisce un elemento in coda
* **`dequeue`**: rimuove e restituisce l'elemento in testa
* **`front`**: restituisce l'elemento in testa senza rimuoverlo
* **`is_empty`**: verifica se la coda è vuota

### Implementazione

Per la coda servono due puntatori: `testa` (da cui si estrae) e `coda` (in cui si inserisce).

```c
typedef struct Nodo {
    int dato;
    struct Nodo* prossimo;
} Nodo;

typedef struct {
    Nodo* testa;
    Nodo* coda;
} Coda;
```

### Operazioni

```c
void enqueue(Coda* q, int valore) {
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    if (nuovo == NULL) return;

    nuovo->dato = valore;
    nuovo->prossimo = NULL;

    if (q->coda != NULL) {
        q->coda->prossimo = nuovo;
    } else {
        q->testa = nuovo; // primo elemento
    }
    q->coda = nuovo;
}

int dequeue(Coda* q) {
    if (q->testa == NULL) {
        fprintf(stderr, "Coda vuota!\n");
        exit(1);
    }

    Nodo* da_rimuovere = q->testa;
    int valore = da_rimuovere->dato;
    q->testa = da_rimuovere->prossimo;

    if (q->testa == NULL) {
        q->coda = NULL; // coda diventata vuota
    }

    free(da_rimuovere);
    return valore;
}

int front(const Coda* q) {
    if (q->testa == NULL) {
        fprintf(stderr, "Coda vuota!\n");
        exit(1);
    }
    return q->testa->dato;
}

int coda_is_empty(const Coda* q) {
    return q->testa == NULL;
}

void libera_coda(Coda* q) {
    while (q->testa != NULL) {
        dequeue(q);
    }
}
```

### Esempio

```c
int main() {
    Coda c = { NULL, NULL };

    enqueue(&c, 10);
    enqueue(&c, 20);
    enqueue(&c, 30);

    printf("Front: %d\n", front(&c)); // 10

    while (!coda_is_empty(&c)) {
        printf("%d\n", dequeue(&c)); // 10, 20, 30
    }

    libera_coda(&c);
    return 0;
}
```

!!! tip "Usi della coda"
    Le code sono ovunque: code di stampa, buffer per dati in arrivo da rete, scheduling dei processi in un sistema operativo, algoritmi BFS (visita in ampiezza) su grafi.

## Confronto

| Struttura | Politica | Inserimento | Estrazione | Tipico uso |
|-----------|----------|-------------|------------|------------|
| Stack | LIFO | push (in cima) | pop (dalla cima) | Undo, chiamate funzioni |
| Coda | FIFO | enqueue (in coda) | dequeue (in testa) | Code di stampa, BFS |

