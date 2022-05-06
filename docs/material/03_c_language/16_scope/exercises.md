# E16 - Ambito di una variabile

## E15.1

Scrivere in linguaggio C un programma che definisca due funzioni.

* Nella prima, chiamata `calcola_area_quadrato`, viene calcolata e stampata a schermo l'area di un quadrato.
* Nella seconda, chiamata `calcola_perimetro_quadrato`, viene calcolato e stampato a schermo il perimetro dello stesso quadrato.

Entrambe le funzioni accettano come argomento il parametro `lato` di tipo intero.

Utilizzare, ove possibile, un approccio modulare, suddividendo il codice in header e sorgenti.

### S15.1 - Soluzione

Possiamo organizzare il codice rispettando la struttura suggerita da Visual Studio Community o, in alternativa, creando all'interno della stessa cartella tre file, un `main.c`, che sarà il file sorgente principale, un `funzioni.c`, che sarà il sorgente per le funzioni che scriveremo nel codice, ed un `funzioni.h`, che sarà l'header relativo alle stesse funzioni.

Di seguito una possibile implementazione.

#### File `main.c`

Il file `main.c` conterrà le istruzioni principali del nostro programma.

```c
/**
 * File main.c.
 *
 * Rappresenta il punto di accesso principale al programma.
 */
#include <stdio.h>
#include "funzioni.h"

int lato = 5;

int main() {
	int area = calcola_area_quadrato(lato);
	int perimetro = calcola_perimetro_quadrato(lato);
	return 0;
}
```

All'interno del file sorgente andremo a:

* creare una variabile globale chiamata `lato` a cui sarà assegnato il valore 5;
* definire la funzione `main`.

All'interno della funzione `main`:

* invochiamo la funzione `calcola_area_quadrato` passando come argomento `lato`;
* invochiamo la funzione `calcola_perimetro_quadrato` passando come argomento `lato`.

#### File `funzioni.h`

Il file `funzioni.h` è un classico file header, nel quale andremo ad inserire i prototipi delle due funzioni che andremo poi ad implementare nel codice.

```c
#ifndef FUNZIONI_H
#define FUNZIONI_H

int calcola_area_quadrato(int lato);
int calcola_perimetro_quadrato(int lato);

#endif
```

#### File `funzioni.c`

Il file `funzioni.c` conterrà l'implementazione delle funzioni definite nell'header.

```c
#include "funzioni.h"
#include <stdio.h>

int calcola_area_quadrato(int lato) {
    int area = lato * lato;
    printf("Valore area: %d\n", area);
    return area;
}

int calcola_perimetro_quadrato(int lato) {
    int perimetro = lato * 4;
    printf("Valore perimetro: %d\n", perimetro);
    return perimetro;
}
```

Le funzioni in sé sono abbastanza semplici da interpretare, infatti entrambe calcolano rispettivamente area e perimetro di un quadrato, stampano il valore a schermo e restituiscono il valore calcolato.
