# 15 - Nozioni fondamentali su C

In questo breve capitolo illustriamo alcuni concetti fondamentali da tenere a mente quando scriviamo un programma in C.

## 9.1 - Nozioni generali sulla struttura del programma

La struttura di un programma C si basa su una serie di concetti ben definiti. Vediamoli rapidamente.

### 9.1.1 - Modularità

I programmi scritti in C devono essere pensati come *modulari*, ovvero suddivisi in opportune sezioni (chiamate appunto *moduli*) ognuna delle quali contiene informazioni ed istruzioni necessarie ad espletare una certa funzione.

Ad esempio, se scrivessimo un ipotetico programma *Calcolatrice*, potremmo decidere di tenere separati i moduli *Algebra*, che si occuperà delle operazioni algebriche, e *Trigonometria*, delegato alla gestione delle operazioni di natura trigonometrica.

!!!note "Modularità e funzionalità"
    Idealmente, ciascun modulo deve espletare un'unica funzione ben definita, e non essere in alcun modo interdipendente dagli altri moduli. Tuttavia, molto spesso è impossibile evitare completamente dette interdipendenze, per cui ci si assicura prevalentemente che il loro impatto sia minimo.

### 9.1.2 - File header e file sorgente

Quando abbiamo introdotto l'[Hello, World](../16_intro/lecture.md) abbiamo visto che nella prima riga di codice era importato il file `stdio.h`, che abbiamo contestualmente detto essere rappresentativo di una libreria delegata alla gestione delle operazioni di input ed output da e verso diversi tipi di sorgente.

Un file di questo tipo (ovvero un file con estensione `.h`) è chiamato file *header*, e contiene al suo interno una serie di *prototipi*, ovvero le definizioni di un insieme di funzioni. Ad ogni file header corrisponde un file *sorgente*, la cui estensione è `.c`, nella quale le funzioni sono effettivamente implementate.

Semplificando: in un file header, vi sono soltanto le "firme" delle funzioni, mentre nel file sorgente dette funzioni vengono effettivamente implementate.

!!!tip "Suggerimento"
    Il motivo alla base della separazione tra file header e sorgenti è da ricercarsi nel concetto di modularità: infatti, in questo modo è possibile separare l'effettiva implementazione di una serie di funzioni dal codice che le userà, interfacciandovisi esclusivamente mediante l'header.

#### 9.1.2.1 - Un esempio

Facciamo un breve esempio. Immaginiamo di voler scrivere il nostro programma *calcola* che implementa al suo interno due funzioni: `aggiungi`, che somma due numeri, e `moltiplica`, che moltiplica detti numeri tra loro. Per implementarlo, avremo bisogno di tre file:

* un file `calcolatrice.c`, nel quale sono contenuti i corpi delle funzioni `aggiungi` e `moltiplica`;
* un file `calcolatrice.h`, ovvero l'header relativo al sorgente `calcolatrice.c`;
* un file `calcola.c`, che rappresenta la parte di codice al cui interno è contenuto il `main`.

Quindi, il file `calcolatrice.h` conterrà due definizioni:

```c
int aggiungi(int a, int b);
int moltiplica(int a, int b);
```

Il file `calcolatrice.c` conterrà invece il corpo delle due funzioni definite nell'header:

```c
#include "calcola.h"

aggiungi(int a, int b) {
    return a + b;
}

moltiplica(int a, int b) {
    return a * b;
}
```

Il file `calcola.c` conterrà invece il metodo `main`:

```c
#include <stdio.h>
#include "calcola.h"

int main() {
    int somma = aggiungi(2, 3);
    int prodotto = moltiplica(2, 3);
    printf("La somma di 2 e 3 e': %d \n", somma);
    printf("Il prodotto di 2 per 3 e': %d \n", prodotto);
}
```

Alcune note:

* nel file header inseriamo *esclusivamente* i *prototipi* delle funzioni, senza alcuna implementazione;
* nel file sorgente includiamo l'header ed implementiamo le funzioni, omettendo il tipo di ritorno (`int` in entrambi i casi);
* nel file principale includiamo l'header da noi definito *specificando i doppi apici*; in questo modo, possiamo richiamare le funzioni definite in `calcola.h`.

### 9.1.3 - Direttive

Abbiamo visto in precedenza come l'uso della direttiva `#include` permetta di "incorporare" all'interno del nostro programma funzioni definite ed implementate esternamente. Tuttavia, la direttiva `#include` non è l'unica esistente: ne esistono infatti di diverse, alcune delle quali più utilizzate di altre, ma tutte molto importanti.

Ad esempio, gli header includono normalmente un riferimento ad almeno altre tre direttive, definite *header guards*, ovvero:

* `#define`: questa direttiva permette di definire un valore di sistema valido all'interno del programma;
* `#ifndef`: questa direttiva controlla se il valore immediatamente alla sua destra non è già stato definito mediante la direttiva `#define`, ed è data dalla crasi della direttiva `#if` (equivalente appunto ad una verifica condizionale) e della direttiva `#define` "negata". Infatti, se analizziamo attentamente il nome della direttiva, possiamo vedere un'assonanza con i termini *if not defined*;
* `#endif`: questa direttiva indica il termine della condizione di controllo.

In base a queste nozioni, normalmente si modifica un header come segue:

```c
#ifndef HEADER.H
#define HEADER.H

// Prototipi delle funzioni...

#endif
```

Possiamo trasformare quindi il nostro `calcolatrice.h` come segue:

```c
// calcola.h
#ifndef CALCOLA_H
#define CALCOLA_H

int aggiungi(int a, int b);
int moltiplica(int a, int b);

#endif
```

!!!tip "Perché si usano le header guards?"
    Il motivo alla base dell'uso delle header guards riguarda la necessità di evitare l'inclusione ripetuta dello stesso codice. Infatti, potrebbe capitare che l'header `calcolatrice.h` venga incluso in diverse parti del nostro codice, come ad esempio altri header; per evitare che in fase di compilazione del codice il codice incluso nel file sorgente `calcolatrice.c` venga "copiato" più volte, si preferisce usare una header guard che fa sì che la direttiva `#define` non venga chiamata più volte con lo stesso argomento.

Per una lista completa di direttive C, potete consultare [questo indirizzo](https://en.wikibooks.org/wiki/C_Programming/Preprocessor_directives_and_macros).

## 9.2 - Nozioni generali sulla sintassi

Vediamo adesso alcune nozioni generali da osservare sulla sintassi dei programmi in C.

### 9.2.1 - Parole riservate

In C, come in ogni altro linguaggio di programmazione, esiste una serie di **parole riservate**, o **keyword** che, indicando delle specifiche funzionalità del linguaggio di programmazione, non possono *in alcun modo* essere utilizzate dall'utente. Normalmente, queste parole chiave si riferiscono ai tipi di una variabile, o indicano l'inizio di una struttura condizionale o di un ciclo, oppure ancora sono utilizzate per particolari funzionalità (come ad esempio le direttive viste in precedenza).

Ad esempio, se provassimo a creare una variabile chiamandola `int`, avremmo un errore:

```c
int int = 10;
```

```bash
error C2632: 'int' non può essere seguito da 'int'
error C2513: 'int': nessuna variabile dichiarata prima di '='
```

Un elenco di keyword per il linguaggio C è disponibile a [questo indirizzo](https://www.ibm.com/docs/en/developer-for-zos/14.2.0?topic=programs-c-reserved-keywords).

### 9.2.2 - Ambito e parentesi

In C, come in molti altri linguaggi, l'uso delle parentesi *non* è arbitrario, e segue una specifica convenzione. In particolare:

* le parentesi tonde devono essere utilizzate per delimitare i parametri di ingresso di una funzione, o anche una particolare espressione logica od aritmetica;
* le parentesi quadre definiscono un ambito locale.

In altre parole, possiamo usare le parentesi tonde quando definiamo i parametri all'interno del prototipo di una funzione:

```c
int nome_funzione(tipo_1 nome_par_1, tipo_2 nome_par_2);
```

oppure ancora quando valutiamo una condizione o creiamo un ciclo:

```c
if (variabile_a < variabile_b) // ... 
```

```c
for (int i=0; i<= 10; i++) // ...
```

Le parentesi graffe indicano invece l'ambito di una funzione o di una struttura condizionale od iterativa. Ad esempio:

```c
aggiungi (int a, int b) { // qui inizia l'ambito della funzione aggiungi...
    return a + b;
} // e qui termina!

if (a < b) { //qui inizia l'ambito della struttura condizionale...
    int c = a + b;
} // e qui termina!
```

!!!note "E le parentesi quadre?"
    Le parentesi quadre hanno un utilizzo specifico per la definizione e l'accesso agli elementi di un array; ne parleremo più avanti.
