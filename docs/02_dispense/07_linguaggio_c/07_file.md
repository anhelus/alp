## Il concetto di stream

Il linguaggio C (e, di conseguenza, anche il C++) adotta il concetto di _stream_ come base per favorire i meccanismi di input ed output rispettivamente da e verso l'utente.

## Cosa è un file?

Possiamo definire un file come un insieme di dati, i quali vengono organizzati e memorizzati sulla maniera ordinata.

Il C riconosce due categorie di file: i file _di testo_ ed i file _binari_.

I file di testo sono formati da una sequenza di caratteri organizzati in _linee_, ciascuna delle quali termina con il carattere `\n`; i file binari, invece, sono costituiti da una sequenza di byte.

### Accedere ad un file C

Per accedere ad un file in C, possiamo usare due diverse modalità. La prima è l'accesso _sequenziale_: in questo modo, possiamo accedere ad un elemento _scorrendo_ tutti quelli precedenti. La seconda è invece l'accesso _casuale_, o _diretto_, che permette di raggiungere un elemento direttamente.

Il linguaggio C crea un livello intermedio tra il programma e il file che prende il nome di **stream**, nel quale si memorizzano le informazioni da gestire. Dunque, il nostro programma non gestisce direttamente il file, quanto piuttosto lo _stream_, che ha il compito di filtrare le istruzioni.

### puntatore a FILE

per accedere ad un file occorre usare un puntatore a FILE, ovvero un indirizzo di memoria o locazione iniziale del file cui si vuole accedere. FILE è un tipo definito nell'header stdio.h.

La sintassi è:

```c
#include <stdio.h>

// ...

FILE *fp;
```

### fopen in C

la funzione **fopen** in C serve ad aprire un file in diverse modalità. La sintassi è la seguente:

FILE _fopen(char_ nomefile, char \*modo)

I modi sono diversi, ed in particolare:

| Modo | Funzione | Creazione file |
| -- | -- | |-- |
| r | Apre un file in lettura | No (file deve esistere) |
| r+ | Apre un file esistente in lettura/scrittura | No (file deve esistere) |
| w | Crea un nuovo file in scrittura; se il file esiste, viene cancellato il contenuto | Sì. Se il file esiste, viene cancellato il contenuto. |
| w+ | Crea un nuovo file in lettura/scrittura; se il file esiste, wiene cancellato il contentuo | Sì, se il file esiste viene cancellato il contenuto |
| a | Aggiunge alla fine del file. Se non esiste, crealo. | Sì |
| a+ | Aggiunge e legge a partire dalla fine del file. | Sì (se non esiste viene creato) |

E' inoltre possibile specificare il tipo di file usando, rispettivament,e le lettere b o t (binario o di testo). Di default, si usa il valore t.

Un esempio di uso è il seguente:

```c
FILE *fp;

if (fp=fopen("prova.txt", "w+t") == NULL) {
	printf("Errore nell'apertura del file desiderato.");
}
```

Notiamo come controlliamo che il file esiste. Una possibile causa di fallimento potrebbe essere usare la modalità r su un file che non esiste.

### fclose

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
