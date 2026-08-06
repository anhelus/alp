# 6.12 Il Preprocessore

Prima che il compilatore veda il codice sorgente, un programma chiamato **preprocessore** lo elabora, eseguendo direttive che iniziano con il carattere `#`. Il risultato è un file "pulito" che viene poi passato al compilatore vero e proprio.

## `#include`: includere file

La direttiva più comune. Sostituisce la riga con il contenuto del file specificato:

```c
#include <stdio.h>   // cerca nei path di sistema
#include "mio.h"     // cerca prima nella cartella corrente, poi nei path di sistema
```

## `#define`: definire costanti e macro

### Costanti simboliche

```c
#define MAX_STUDENTI 100
#define PI 3.14159
```

Il preprocessore sostituisce ogni occorrenza di `MAX_STUDENTI` con `100` prima della compilazione.

### Macro con parametri

```c
#define QUADRO(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
```

!!! warning "Le parentesi nelle macro sono essenziali"
    Senza le parentesi attorno ai parametri e all'espressione, una macro può produrre risultati inaspettati:

    ```c
    #define QUADRO_SBAGLIATO(x) x * x
    // QUADRO_SBAGLIATO(2 + 3) diventa 2 + 3 * 2 + 3 = 11, non 25
    ```

### Macro su più righe

Si usa il backslash `\` per continuare su riga successiva:

```c
#define STAMPA_SU_ERRORE(msg) \
    fprintf(stderr, "Errore: %s\n", msg)
```

## `#undef`: rimuovere una definizione

```c
#define DEBUG 1
// ... codice che usa DEBUG ...
#undef DEBUG
// DEBUG non e' piu' definito
```

## Compilazione condizionale

### `#ifdef` / `#ifndef` / `#endif`

```c
#ifdef DEBUG
    printf("Variabile x = %d\n", x);
#endif
```

Se `DEBUG` non è definito, la riga di `printf` non viene compilata. Utile per codice di debug da attivare/disattivare senza modificare il sorgente: basta commentare o meno il `#define`.

### `#if` / `#elif` / `#else`

```c
#if defined(_WIN32) || defined(_WIN64)
    #define PIATTAFORMA "Windows"
#elif defined(__linux__)
    #define PIATTAFORMA "Linux"
#elif defined(__APPLE__)
    #define PIATTAFORMA "macOS"
#else
    #define PIATTAFORMA "Sconosciuta"
#endif
```

## Il problema della doppia inclusione

Quando un file header viene incluso più volte, si hanno errori di ridefinizione. La soluzione sono le **guardie di inclusione** (già viste nella lezione 6.1):

```c
#ifndef NOME_FILE_H
#define NOME_FILE_H

// contenuto del header

#endif
```

In alternativa, molti compilatori supportano `#pragma once`:

```c
#pragma once
// contenuto del header
```

## Operatori del preprocessore

* **`#` (stringify)**: converte il parametro di una macro in una stringa letterale:

    ```c
    #define STAMPA_INT(x) printf(#x " = %d\n", x)
    // STAMPA_INT(eta) diventa printf("eta" " = %d\n", eta)
    ```

* **`##` (concatenazione)**: unisce due token in uno solo:

    ```c
    #define CREA_FUNZIONE(nome, tipo) \
        tipo calcola_##nome(tipo a, tipo b) { return a + b; }

    CREA_FUNZIONE(intero, int)
    // genera: int calcola_intero(int a, int b) { return a + b; }
    ```

## Esempio pratico

```c
#include <stdio.h>

#define DEBUG

#ifdef DEBUG
    #define LOG(msg) printf("[DEBUG] %s\n", msg)
#else
    #define LOG(msg) // non fa nulla
#endif

#define SOGLIA 100
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int x = 50, y = 150;

    LOG("Avvio del programma");

    int massimo = MAX(x, y);
    printf("Il massimo e' %d\n", massimo);

    if (massimo > SOGLIA) {
        LOG("Valore sopra la soglia");
    }

    return 0;
}
```

