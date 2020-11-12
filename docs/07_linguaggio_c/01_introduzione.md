## Cosa è C?

Il linguaggio C è un linguaggio ad alto livello inizialmente sviluppato da Dennis M. Ritchie nell'ambito dello sviluppo del sistema operativo UNIX ai Bell Labs. La sua prima implementazione risale al 1972 su un computer DEC PDP-11. Il primo draft disponibile venne reso disponibile al grande pubblico nel 1978, in quello che è conosciuto al giorno d'oggi come *K&R standard*; venne poi formalizzato dall'*American National Standard Institute* (*ANSI*) nel 1988.

Al giorno d'oggi, C è uno dei linguaggi di programmazioni maggiormente utilizzati. Le sue applicazioni sono estese, e vanno dai sistemi operativi, ai compilatori, ai text editor, passando per database e programmi ottimizzati per smartphone.

Vediamo insieme la struttura di un primo programma in C.

## Hello, C!

La *Via dell'Informatico* ci impone di partire in maniera abbastanza classica, andando a definire un primo, rudimentale, ma famigerato programma: l'*Hello, World*.

```c
#include <stdio.h>

int main() {
	// Ora sono un programmatore!
	printf("Hello, World! \n");

	return 0;
}
```

Ecco fatto, semplice, vero?

Beh, certo, però, nonostante la loro semplicità, in queste poche righe di codice sono racchiusi tutti i concetti fondamentali a scrivere programmi ben più complessi.

Vediamole una ad una.

### `#include`

La prima istruzione è una *direttiva*. Se ricordate, è proprio una di quelle parti di codice che vengono *pre-elaborate* dal compilatore.

In particolare, questa è una direttiva `include`, che prevede un parametro che può essere incluso tra i simboli `<` e `>`, oppure tra doppi apici, e rappresenta il nome di un file. Quando il compilatore incontra una `include`, cerca il file specificato (in questo caso, `stdio.h`, che fa parte dello "standard" dettato dal C), e ne copia integralmente il contenuto nel file che andrà poi al front end del compilatore.

L'uso dei simboli `<` e `>` non è intercambiabile con quello dei doppi apici: infatti, nel primo caso, la ricerca avviene all'interno della directory in cui si trovano i file di intestazione della libreria standard di C (torneremo in avanti sul concetto di libreria), mentre nel secondo la ricerca avviene all'interno della directory corrente.

### `int main()`

Questa istruzione è la firma di una particolare funzione, ovvero il `main()`.

La funzione `main` sarebbe una normalissima funzione, se non fosse per un piccolo dettaglio: rappresenta infatti il *punto di accesso* di un programma, ovvero la parte di codice che verrà effettivamente eseguita a runtime, richiamando e componendo alla bisogna le altre istruzioni e funzioni invocate dal programma.

### `// Questo è un commento`

Le istruzioni che hanno preposti due caratteri di slash (`//`) sono chiamate *commenti*. Queste righe permettono al programmatore di inserire dei "suggerimenti" per spiegare meglio il codice ad altri sviluppatori (o per ricordare in futuro cosa si era fatto).

Questo tipo di commento è a singola linea; esistono anche i commenti multilinea:

```c
/*
 * Questo è un commento multilinea!
 */

// E questo è un commento a linea singola!
```

### `printf("Hello, World! \n")`

Questa istruzione richiama una funzione integrata nel file `stdio.h` che abbiamo invocato in precedenza nella direttiva `include`, ovvero la funzione `printf`. Questa accetta in ingresso una stringa (logicamente equivalente ad un array di char), ovvero `"Hello, World! \n"`, e la stampa a schermo (spesso in una shell).

Interessante notare la presenza di un *escape character*, ovvero `\n`, che indica al compilatore di andare a capo dopo il termine della stringa.

### `return 0`

La funzione `main()` prevede in uscita un valore intero; di conseguenza, il `return 0` indica il termine del `main()` stesso. Per convenzione, il `return 0` indica il successo del programma, mentre altri valori di ritorno possono indicare degli errori intercorsi durante l'esecuzione.
