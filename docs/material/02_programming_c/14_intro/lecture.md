# 14 - Introduzione al linguaggio C

!!!tip "Materiale e link utili"
    | Materiale | Disponibilità | Link |
    | --------- | :-------------: | ---- |
    | Slides mostrate a lezione | :white_check_mark:{ .heart } | [Download](../../slides/02_intro_c.pdf) |
    | Video esplicativo | :x: | Link non disponibile |

Il linguaggio C è un linguaggio a livello medio-alto inizialmente sviluppato da Dennis M. Ritchie ai Bell Labs. La primissima implementazione del C risale al 1972, ma fu soltanto nel 1978 che venne reso disponibile al grande pubblico il primo draft del linguaggio, in quello che oggi è conosciuto come *K&R standard*. La formalizzazione vera e propria del linguaggio avvenne poi da parte dell'ANSI (*American National Standard Institute*) nel 19814.

Al giorno d'oggi, il C è ancora uno tra i linguaggi di programmazione più utilizzati, ed ha applicazioni praticamente ovunque, dai sistemi operativi ai compilatori, passando per database, programmi per smartphone ed editor di testo.

## 14.1 - Il programma *Hello, world!*

Dopo questa breve (ma dovuta) introduzione "storica", partiamo con quella che è da sempre la maniera "classica" di apprendere un linguaggio di programmazione, ovvero scrivendo il nostro primo programma, chiamato per convenzione *Hello, world!* (*Ciao, mondo!*).

Apriamo Visual Studio (o un editor equivalente) e scriviamo:

```c linenums="1"
#include <stdio.h>

int main() {
	// Questo è un commento!
	printf("Hello, World! \n");

	return 0;
}
```

Proviamo ad eseguire il programma usando il tasto *Run* o premendo F5, e sulla console dovrebbe apparire la scritta `Hello, World!`.

## 14.2 - Descrizione del codice

Nonostante la loro semplicità, in queste poche righe di codice sono riacchiusi i principali concetti sintattici che saranno usati per scrivere programmi ben più complessi. Vediamoli uno per uno.

### 14.2.1 - La direttiva `#include`

L'istruzione alla riga 1 è chiamata *direttiva*, ed è una parte di codice che viene elaborata in automatico dal programma delegato alla "comprensione" del linguaggio C (ovvero, al compilatore). In altre parole, ogni volta che si specifica una direttiva, viene effettuata una determinata azione: in questo caso, viene incluso tutto il codice contenuto all'interno del file `stdio.h`, che altro non è che una delle librerie *standard* del C, delegata alle operazioni di input ed output da e verso diverse fonti (come schermo, tastiera, stampante, file, etc.).

!!!note "Nota"
	Spesso, la direttiva `#include` prevede l'utilizzo o dei simboli di maggiore e minore (come in questo caso), oppure di due doppi apici. Nel primo caso, la ricerca del file specificato avviene all'interno dei file "standard" del C, mentre nel secondo all'interno della directory attuale.

### 14.2.2 - Il `metodo main`

Alla riga 3 vediamo quello che è l'unico metodo presente in tutti i programmi scritti in C, ovvero il `main`. Nonostante questo sia in tutto e per tutto una funzione, con parametri accettati in ingresso ed un valore di ritorno, il `main` rappresenta il punto di accesso del programma, ovvero la parte di codice che verrà effettivamente eseguita a runtime, richiamando e "componendo", alla bisogna, le altre istruzioni e funzioni invocate dal programma.

### 14.2.3 - Commenti

Alla riga 4 vi è una stringa che ha preposti due caratteri di slash (ovvero `//`); una stringa di questo tipo è chiamata *commento*, e permette di inserire dei "suggerimenti" per facilitare la comprensione del codice. Il commento alla riga 4 è un commento a singola linea; ne esistono anche di *multilinea*, che iniziano con la sequenza `/*` e terminano con la sequenza `*/`:

```c
/*
 * Questo è un commento multilinea!
 */

// E questo è un commento a linea singola!
```

### 14.2.4 - L'istruzione `printf`

L'istruzione alla riga 5 richiama una funzione definita all'interno del file `stdio.h` che abbiamo invocato in precedenza nella direttiva `include`, ovvero la funzione `printf`. Questa accetta in ingresso una *stringa* (in questo caso `"Hello, World! \n"`) e la stampa sul terminale dello schermo.

### 14.2.5 - L'istruzione di ritorno `return`

Nella testa della funzione `main` vediamo come viene indicato un valore di ritorno di tipo intero. Di conseguenza, l'istruzione `return 0` indica il valore che sarà restituito al termine della funzione `main`.

!!!note "Nota"
	Per convenzione, restituire il valore `0` indica che il programma è uscito con successo, mentre altri valori di ritorno, come `-1`, indicano l'insorgenza di errori durante l'esecuzione del programma.
