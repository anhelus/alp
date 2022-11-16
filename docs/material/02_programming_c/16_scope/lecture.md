# 16 - Visibilità di una variabile

Nella [lezione 9](../../01_intro/08_functions/lecture.md) abbiamo trattato dell'ambito di una variabile. Estendiamo il discorso, e parliamo del concetto di *visibilità* di una variabile nel linguaggio C.

Per comprendere il concetto, facciamo un esempio.

## 16.1 - Un esempio

Supponiamo di scrivere un programma C che definisca due funzioni in aggiunta al `main`, le quali accettano come parametro in ingresso un numero intero rappresentativo del lato di un quadrato. Le due funzioni dovranno, rispettivamente, calcolare l'area ed il perimetro del quadrato; provvediamo quindi all'implementazione delle stesse. In particolare, facciamo in modo che all'interno della funzione `calcola_area_quadrato` vengano mostrati a schermo i valori dell'area e del perimetro del quadrato.

```c linenums="1"
#include <stdio.h>

int calcola_area_quadrato(int lato) {
    int area = lato * lato;
    printf("Valore area: %d", area);
    printf("Valore perimetro: %d", perimetro);
    return area;
}

int calcola_perimetro_quadrato(int lato) {
    int perimetro = lato * 4;
    return perimetro;
}
```

Proviamo adesso a richiamare entrambe le funzioni dal `main`.

```c linenums="1"
int main() {
    int lato = 5;
    int area = calcola_area_quadrato(lato);
    int perimetro = calcola_perimetro_quadrato(lato);
    return 0;
}
```

Provando ad eseguire questo programma con Visual Studio Community, otterremo in uscita due errori del tipo:

```sh
E0020: identificatore "perimetro" non definito
C2065: 'perimetro': identificatore non dichiarato
```

I due errori precedenti ci suggeriscono che la variabile `perimetro` non sia "visibile", e di conseguenza *accessibile*, dall'interno dell'ambito definito dalla funzione `calcola_area_quadrato`. Per risolvere questo errore, possiamo provare a stampare i valori a schermo direttamente dal `main`.

Modifichiamo la funzione `calcola_area_quadrato` come segue:

```c linenums="1"
int calcola_area_quadrato(int lato) {
    int area = lato * lato;
    return area;
}
```

Modifichiamo adesso il `main`:

```c linenums="1"
int main() {
    int lato = 5;
    int area = calcola_area_quadrato(lato);
    int perimetro = calcola_perimetro_quadrato(lato);
    printf("Valore area: %d\n", area);
    printf("Valore perimetro: %d\n", perimetro);
    return 0;
}
```

Questa volta, vedremo che l'output a schermo è correttamente dato da:

```sh
Valore area: 25
Valore perimetro: 20
```

Abbiamo quindi visto come il concetto di ambito di una variabile possa essere foriero di errori se non compreso alla perfezione. Inoltre, è preferibile prestare particolare attenzione ai *nomi* assegnati alle variabili, che idealmente non dovrebbero "sovrapporsi" onde evitare confusione (torneremo su quest'ultimo aspetto in seguito quando parleremo di passaggio *per valore* e *per reference*). Inoltre, è opportuno tenere sempre a mente che, in caso di ambiguità, verrà *sempre* data precedenza alla variabile locale.

!!!tip "Ambito delle variabili nel `main`"
    Contrariamente a quanto si potrebbe pensare, il `main` *non definisce un ambito globale per le variabili*. Per verificarlo, proviamo a modificare la funzione calcola_area_quadrato come segue:
    > ```c
      int calcola_area_quadrato(int l) {
          printf("Lato: %d\n", lato);
          int area = l * l;
          return area;
      }
      ```
    Noteremo anche in questo caso la coppia di errori `E0020` e `C2065`, che ci indicheranno la mancanza di visibilità dell'identificativo `lato`.

## 16.2 - Un altro esempio

Approfondiamo ulteriormente il concetto di visibilità con un altro esempio.

Supponiamo, in questo caso, di definire all'interno di un programma C una funzione `incrementa`. Questa funzione, come suggerisce il nome stesso, ha al suo interno una variabile (locale) di tipo intero chiamata `contatore`, la quale aumenta di uno ogni volta che `incrementa` viene chiamata.

```c linenums="1"
#include<stdio.h> 

int incrementa() {
    int contatore = 0;
    contatore++;
    return contatore;
}
```

Proviamo a chiamare due volte questa funzione dal `main`. Cosa ci aspettiamo?

```c linenums="1"
int main() {
    printf("Valore contatore: %d \n",  incrementa());
    printf("Valore contatore: %d \n", incrementa());
    return 0;
}
```

Ovviamente, vedremo a schermo due volte il valore `1`: ciò è legato al fatto che la variabile `contatore` ha visibilità *limitata* all'ambito della funzione `incrementa`, e quindi viene "eliminata" (o, per meglio dire, *distrutta*) una volta usciti dall'ambito della funzione stessa.

In tal senso, possiamo definire una variabile a visibilità più "ampia", andando a modificare il codice come segue:

```c linenums="1"
#include <stdio.h>

int contatore = 0;

void incrementa() {
	contatore++;
}

int main() {
    incrementa();
    printf("Valore contatore: %d \n", contatore);
    incrementa();
    printf("Valore contatore: %d \n", contatore);
    return 0;
}
```

In questo caso, abbiamo definito una variabile *globale* chiamata `contatore`, di valore iniziale pari a `0`, che viene incrementata ad ogni chiamata della funzione `incrementa()`. Ovviamente, l'output sarà quello atteso, e vedremo che al termine dell'esecuzione del programma il valore di `contatore` sarà pari a `2`.

!!!note "Il valore di ritorno `void`"
    Notiamo che la funzione `incrementa` non restituisce alcun valore, in quanto opera su una variabile di tipo globale. In questo caso, indichiamo come tipo di ritorno `void` (letteralmente *vuoto* in inglese).
