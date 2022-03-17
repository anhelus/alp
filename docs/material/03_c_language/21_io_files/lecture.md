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

TODO: da qui

La funzione fclose serve a chiudere un file dopo averlo utilizzato, di modo da rendere lo stream disponibile per altri utilizzo.

La sintassi è la seguente:

```c
int fclose(FILE *fp)
```

La funzione restituisce un valore intero. se tutto è andato a buon fine, viene restituito 0; in alternativa, viene restituito EOF, che è un valore costante.

Volendo estendere il programma precedente:

```c
FILE *fp;

if (fp=fopen("prova.txt", "w+t") == NULL) {
	printf("Errore nell'apertura del file desiderato.");
}

// uso

fclose(fp);
```

!!! note "Nota"
Tutti i file vengono chiusi in maniera automatica se il programma termina regolarmente; in questi casi, non è necessaria la funzione fclose.

### fprintf

La funzione fprintf permette di scrivere sul file in modo formattato dopo l'apertura dello stesso con fopen. Questa funzione è molto simile quindi alla printf, ed opera sullo stream del file aperto con la funzione fopen.

La sintassi della funzione è la seguente:

```c
int fprintf(FILE *fp, char *format, [args])
```

In pratica, è analoga alla printf, se non per due differenze:

- la prima è che accetta come primo argomento un puntatore a file;
- la seconda è che restituisce un valore di ritorno, ovvero un intero.

Il valore di ritorno della fprintf è il numero di caratteri scritti nello stream in caso di successo o un EOF in caso di errore.

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

### scanf

La funzione scanf ci permette di acquisire una sequenza di caratteri (lettere o cifre) dalla tastiera e memorizzarla in una variabile opportuna.

E' la funzione duale della printf.

La sua sintassi è la seguente:

```c
scanf(char * format, [args])
```

dove:

- format rappresenta uno o più specificatori di formato
- args rappresenta uno o più riferimenti alle variabili da popolare.

Ad esempio:

```c
scanf("%d%, &x)
```

farà sì che il valore passato da tastiera sia salvato nella variabile di tipo intero x, mentre:

```c
scanf("%d %f", &x, &y)
```

leggerà un intero ed un decimale andandoli a mettere nelle variabili x ed y rispettivamente.

!!!note "Nota"
	In realtà, l'uso di `scanf` è sconsigliato. Per maggiori informazioni, [leggete qui](https://stackoverflow.com/questions/3744776/simple-c-scanf-does-not-work).

### fscanf

La funzione fscanf serve a leggere un file in modo formattato, chiaramente dopo l'apertura con fopen. E', come la fprintf, l'equivalente sugli stream della scanf. La differenza in questo caso è anche qui valutabile andando ad esaminare il prootipo della funzione:

```c
int fscanf(FILE *fp, char *format, [args])
```

Notiamo infatti che viene restituito un intero, che rappresenta il numero di caratteri letti, e che come primo argomento viene passato il puntatore al file di riferimento.

### feof

La funzione feof infine serve a sapere se ci troviamo alla fine di un file. Questa è definita come segue:

```c
int feof(FILE *fp)
```

e restituisce 0 se non è stata raggiunta laf ine del file, o true altrimenti. Possiamo farlo per leggere nel file fino a che non abbiamo raggiunto la fine dello stesso.

Un esempio è il seguente:

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
