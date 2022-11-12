# 20 - Tecniche di I/O in C

## 20.1 - Il concetto di *stream*

Il linguaggio C adotta estensivamente il concetto di *stream* (traducibile in italiano con *flusso*) per gestire i meccanismi di interazione di un programma con le sorgenti di input (*ingresso*) o le destinazioni in output (*uscita*). Abbiamo già usato uno stream, ad esempio, con la funzione `printf`: in questo caso, infatti, abbiamo creato un flusso dati verso l'utente, mostrando a schermo un certo output definito all'interno del nostro programma.

Concettualmente, uno stream è assimilabile ad una sorta di "intermediario", che permette al nostro programma di gestire indirettamente la sorgente (o destinazione) dei dati. In altre parole, il programma *non* interagisce direttamente con i dispositivi di input ed output, ma bensì esclusivamente con lo stream. Ciò permette quindi di "astrarsi" dall'effettivo dispositivo di interazione, consentendo di utilizzare oggetti e metodi affini in casi eterogenei, come uso di tastiera, stampanti, o anche (e soprattutto) *file*.

## 20.2 - I file in C

Intuitivamente, sappiamo che i file altro non sono se non degli *insiemi di dati*, organizati e memorizzati in memoria in maniera ordinata. In particolare, il C riconosce due tipi di file: 

* i primi sono i file di *testo*, normalmente intelliggibili dall'essere umano, e formati da sequenze di caratteri organizzate in linee, ognuna delle quali termina con l'escape character `\n`;
* i second sono i file *binari*, costituiti da sequenze di bit di lunghezza arbitraria, e contenenti dati relativi a programmi, librerie, o altro ancora.

Ad ogni modo, i contenuti di un file sono accessibili in C secondo due diverse modalità:

* accedendo ad un file in maniera *sequenziale*, possiamo accedere a ciascun elemento "scorrendo" i precedenti;
* accedendo ad un file in maniera *casuale*, o *diretta*, siamo in grado di accedere direttamente all'elemento che ci interessa.

### 20.2.1 - Accesso al file

#### 20.2.1.1 - Puntatore a `FILE`

Per accedere ad un file, C ci mette a disposizione un apposito puntatore al tipo `FILE`, definito nell'header `stdio.h`, che restituisce la locazione iniziale del file a cui si vuole accedere. Questa sintassi va quindi *sempre* utilizzata qualora si voglia interagire con un file:

```c
#include <stdio.h>

// ...

FILE *fp;
```

#### 20.2.1.2 - Apertura del file con `fopen`

Per aprire il file, è necessario utilizzare la funzione `fopen`, contenuta in `stdio.h` che permette di operare in diverse modalità usando una sintassi del tipo:

```c
FILE fopen(file_name, mode);
```

In particolare:

* `file_name` è un array di `char` che indica il nome del file da aprire;
* `mode` è un array di `char` che indica la modalità con cui il file sarà aperto.

Per quello che riguarda la modalità di apertura del file, si può scegliere una tra le seguenti:

| Modo | Descrizione | File già esistente? |
| ---- | ----------- | ------------------ |
| `r` | Apertura di un file in sola lettura. | Sì, necessario. |
| `r+` | Apertura di un file esistente in lettura/scrittura. | Sì, necessario. |
| `w` | Creazione di un nuovo file in scrittura. Se il file esiste, ne viene cancellato il contenuto. | Non necessario. |
| `w+` | Creazione di un nuovo file in lettura/scrittura. Se il file esiste, ne viene cancellato il contenuto. | Non necessario. |
| `a` | Aggiunta di nuovi contenuti a partire dalla fine del file. Se il file non esiste, viene creato. | Non necessario. |
| `a+` | Aggiunta e lettura di nuovi contenuti a partire dalla fine del file. Se il file non esiste, viene creato. | Non necessario. |

In aggiunta al mode, è possibile specificare il tipo di file da aprire, specificando la lettera `b` (binario) o `t` (testo). Se quest'ultimo valore non viene specificato, viene supposto il valore `t`.

Ad esempio, per aprire il file di testo `prova.txt` in modalità di lettura/scrittura, si usano le seguenti istruzioni:

```c
FILE *fp;

if (fp=fopen("prova.txt", "w+t") == NULL) {
	printf("Errore nell'apertura del file desiderato.");
}
```

!!!note "Nota"
	Nelle istruzioni precedenti, è bene notare come venga controllata l'esistenza del file. Con la modalità `w` un controllo di questo tipo è ridondante, ma nel caso si utilizzi la modalità `r` tale controllo può rivelarsi critico.

#### 20.2.1.3 - Chiusura di un file con `fclose`

Una volta terminato l'utilizzo del file, è necessario chiamare la funzione `fclose` che, come dice il nome stesso, permette di chiudere lo stream relativo al file stesso. In tal senso, la sintassi che si utilizza è la seguente:

```c
int fclose(FILE *fp);
```

La funzione `fclose` restituisce un valore intero pari a `0` se il tutto è andato a buon fine.

Proviamo ad estendere il programma precedente integrando la `fclose` al termine del file.

```c
FILE *fp;

if (fp=fopen("prova.txt", "w+t") == NULL) {
	printf("Errore nell'apertura del file desiderato.");
}

// Uso del file...

fclose(fp);
```

### 20.2.2 - Scrittura su file

La funzione `fprintf` permette di scrivere su di un file a seguito dell'apertura dello stesso. Come appare evidente anche dall'assonanza, questa funzione è simile alla classica `prinft`, ed adotta una sintassi del tipo:

```c
int fprintf(FILE *fp, char *format, [args])
```

Le differenze principali rispetto alla `printf` sono quindi due:

* il primo sta nel fatto che la funzione accetta come primo argomento un puntatore a file;
* il secondo invece sta nel fatto che la funzione restituisce un intero come valore di ritorno, rappresentativo del numero di caratteri scritto nello stream.

!!!note "Nota"
	Qualora la `fprintf` restituisca un valore pari alla costante `EOF`, vorrà dire che vi è stato un errore nella scrittura dei dati.

Facciamo un esempio:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp;

	if (fp=fopen("prova.txt", "w+t") == NULL) {
		printf("Errore nell'apertura del file desiderato.");
	}

	fprintf(fp, "Il file esiste!");

	fclose(fp);
}
```

### 20.2.3 - Lettura di un input

#### 20.2.3.1 - Lettura di uno stream da tastiera: la funzione `scanf`

La funzione `scanf` ci permette di acquisire una sequenza di caratteri (lettere o cifre) dalla tastiera, memorizzandola in un'opportuna variabile; per i più attenti, apparirà chiaro come questa sia una sorta di funzione "duale" alla `printf`.

La sintassi della `scanf` è quella riportata di seguito:

```c
scanf(char* format, [args]);
```

Notiamo innazitutto che *non* vi è un valore di ritorno atteso. Infatti, le variabili da "popolare" saranno specificate mediante un puntatore tra gli `args` passati dopo la serie di specificatori di formato associati all'argomento `format`.

Ad esempio, usando l'istruzione:

```c
int x;
scanf("%d%, &x);
```

faremo in modo che il valore numerico digitato da tastiera venga salvato nella variabile `x`. In alternativa, se volessimo salvare un intero ed un decimale, e salvarli nelle variabili `x` ed `y`, dovremmo scrivere:

```c
int x;
int y;
scanf("%d %f", &x, &y);
```

!!!note "Nota"
	Nel tempo, l'uso di `scanf` è diventato "sconsigliato". Per approfondire, [leggete qui](https://stackoverflow.com/questions/3744776/simple-c-scanf-does-not-work).

#### 20.2.3.2 - Lettura di un file: la funzione `fscanf`

In maniera alquanto "prevedibile", la funzione `fscanf` permette di leggere il contenuto di un file; rappresenta quindi la funzione duale alla `fprintf`, o equivalente alla `scanf` per file. 

Vediamo quindi qual è il prototipo della funzione:

```c
int fscanf(FILE *fp, char *format, [args]);
```

In questo caso, viene restituito un valore intero, che rappresenta il numero di caratteri letti dalla funzione. Inoltre, come primo argomento, avremo sempre il puntatore al file da leggere.

### 20.2.4 - Fine di un file: la funzione `feof`

Chiudiamo questa carrellata con la funzione `feof`, che ci permette di capire se ci troviamo o meno alla fine del file. Il corpo di questa funzione è definito come:

```c
int feof(FILE *fp);
```

In particolare, la funzione restituirà 0 se non è ancora stata raggiunta la fine del file, o 1 altrimenti. 

L'uso della `feof` può essere utile nel momento in cui, ad esempio, si legge un file carattere per carattere all'interno di un ciclo, e si vuole uscire dallo stesso quando il file termina. Ad esempio:

```c
#include <stdio.h>
#include <stdlib.h>
#define N 5

int main() {
	FILE *fp;
	char cognome[20];
	char nome[20];
	int i, voto;

	if((fp=fopen("alunni.txt", "rt"))==NULL) {
		printf("Errore nell'apertura del file'");
		exit(1);
	}

	while(!feof(fp)){
		fscanf(fp,"%s %s %d\n", &cognome, &nome, &voto);
		printf("cognome: %s, nome: %s, voto: %d\n", cognome, nome, voto);
	}
	fclose(fp);

return 0;
}
```
