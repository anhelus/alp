# 6.13 Qualificatori di Tipo e Tipi `size_t`

Il C mette a disposizione alcune parole chiave che **qualificano** il comportamento dei tipi di dato, modificandone la semantica.

## `const`: valori immutabili

La parola chiave `const` dichiara che una variabile non può essere modificata dopo l'inizializzazione. Il compilatore impedirà qualsiasi tentativo di assegnazione.

```c
const int MAX_TENTATIVI = 3;
MAX_TENTATIVI = 5; // ERRORE in compilazione
```

### Puntatori e `const`

La combinazione di `const` con i puntatori è fonte di frequenti confusioni. La posizione di `const` determina cosa è costante:

```c
int valore = 42;
int altro = 100;

const int* p1 = &valore;  // il dato puntato e' costante
// *p1 = 50;              // ERRORE: non posso modificare il valore puntato
p1 = &altro;              // OK: posso cambiare a cosa punta

int* const p2 = &valore;  // il puntatore e' costante
*p2 = 50;                 // OK: posso modificare il valore puntato
// p2 = &altro;           // ERRORE: non posso cambiare a cosa punta

const int* const p3 = &valore; // sia puntatore che dato sono costanti
```

!!! tip "Leggere le dichiarazioni da destra a sinistra"
    Per capire un tipo complesso, leggiamo da destra a sinistra:

    * `const int* p` → "p è un puntatore a intero costante" (il dato è const)
    * `int* const p` → "p è un puntatore costante a intero" (il puntatore è const)

### `const` nei parametri di funzione

Usiamo `const` per garantire che una funzione non modifichi i dati passati tramite puntatore:

```c
void stampa_stringa(const char* str) {
    // Non possiamo modificare *str per errore
    printf("%s\n", str);
}
```

Questa è una buona pratica che rende il codice più sicuro e auto-documentante.

## `volatile`: valori che cambiano esternamente

Il qualificatore `volatile` informa il compilatore che una variabile può cambiare valore in momenti imprevisti, al di fuori del flusso di controllo del programma. Questo impedisce al compilatore di ottimizzare via accessi che ritiene "ridondanti".

Si usa in contesti come:

* **Variabili modificate da un interrupt**: un gestore di interrupt cambia il valore, il programma principale lo legge.
* **Registri di dispositivi hardware**: il valore di un registro mappato in memoria può cambiare indipendentemente dal software.
* **Variabili condivise tra thread** (in assenza di primitive di sincronizzazione).

```c
volatile int flag_interrupt = 0;

void interrupt_handler() {
    flag_interrupt = 1; // modificato dall'esterno
}

int main() {
    while (!flag_interrupt) {
        // Senza volatile, il compilatore potrebbe ottimizzare
        // questo loop in un ciclo infinito, pensando che
        // flag_interrupt non cambi mai
    }
    return 0;
}
```

!!! note ""
    `volatile` non è una primitiva di sincronizzazione. Per la programmazione concorrente servono strumenti più specifici (mutex, atomics).

## Il tipo `size_t`

`size_t` è un tipo intero senza segno definito in `<stddef.h>` (e incluso da `<stdio.h>`, `<stdlib.h>`, `<string.h>`, ecc.). Rappresenta la dimensione di un oggetto in byte ed è il tipo restituito dall'operatore `sizeof`.

```c
size_t n = sizeof(int);
printf("sizeof(int) = %zu byte\n", n);
```

Vantaggi di usare `size_t`:

* **Portabilità**: si adatta all'architettura (64 bit su sistemi a 64 bit, 32 bit su sistemi a 32 bit).
* **Semantica**: comunica che il valore rappresenta una dimensione, non un numero generico.
* **Correttezza**: è un tipo senza segno, quindi non può rappresentare dimensioni negative.

Lo vediamo spesso nei parametri di funzioni di libreria:

```c
void* malloc(size_t size);
void* calloc(size_t num, size_t size);
char* strcpy(char* dest, const char* src);
size_t strlen(const char* str);
```

Per stampare una variabile `size_t` con `printf` usiamo lo specificatore `%zu`.

!!! warning "Attenzione ai confronti misti"
    Confrontare `size_t` (senza segno) con `int` (con segno) può dare risultati inaspettati:

    ```c
    size_t a = 5;
    int b = -1;
    if (a > b) { // FALSO! b viene convertito a size_t (grandissimo)
        // ...
    }
    ```

    In questi casi, il compilatore dovrebbe emettere un warning. Utilizzare sempre lo stesso tipo in confronti e operazioni aritmetiche.

