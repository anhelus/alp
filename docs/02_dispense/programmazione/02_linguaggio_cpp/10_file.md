# La gestione dei file in C++

La gestione dei file in C++ (e, ovviamente, dei relativi stream di I/O) ricalca in parte il modello usato per il C, con delle classi specifiche per l'interazione con il file system, ovvero `ofstream` (usata per le operazioni di sola scrittura), `ifstream` (usata per le operazioni di sola lettura), ed `fstream` (usata per entrambi i tipi di operazioni). Proprio come nel C vi è un'analogia tra, ad esempio, `printf` ed `fprintf`, nel C++ troviamo numerose analogie tra le classi prima citate e le classi `ostream` ed `istream`, che ricordiamo essere delegate alla gestione dell'I/O da riga di comando.

!!!note "Nota"
	Queste "analogie" sono rese possibili dal fatto che in realtà `ofstream` ed `ifstream` sono classi derivate da `ostream` ed `istream`, mentre `fstream` deriva da `iostream`, a sua volta classe derivata da `istream` ed `ostream`.

Vediamo brevemente un paio di esempi.

## Esempio 1: Copia di file riga per riga

Un caso comune è quello che riguarda la copia di un file di testo riga per riga. Immaginiamo quindi di avere un file di testo in input (al solito, chiamiamolo **input.txt**), e volerlo copiare (quindi, leggere riga per riga, e scrivere il contenuto su un altro file). Chiameremo il file di output **output.txt**. Per la prima parte, useremo la classe `ifstream`, mentre per la seconda parte la classe `ostream`.

### Header e namespace

Per prima cosa, ricordiamoci di includere gli header necessari, e di specificare l'utilizzo del namespace `std`:

```cpp linenums="1"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
```

### Step 1: Apertura del file in input

Fatto questo, dovremo istanziare un oggetto di classe `ifstream`. Utilizziamo la sintassi seguente:

```cpp hl_lines="4" linenums="1"
// Header

int main() {
	ifstream input("input.txt")
	// ...
}
```

L'istruzione è alquanto semplice da interpretare: stiamo infatti creando una variabile `input` associata ad un oggetto di classe `ifstream` che si occupa di leggere il contenuto del file **input.txt**.

### Step 2: Verifica dell'esistenza del file

I più attenti avranno notato che, a differenza del C, dove si usava una verifica del valore restituito dalla `fopen` per appurare che il file esistesse, qui non abbiamo effettuato alcun controllo. In realtà, questo non avrebbe molto senso: stiamo comunque creando una variabile di classe `ifstream`, e ciò non dipende dal valore passato (sotto forma peraltro di stringa) al costruttore. Come fare, quindi?

Una soluzione è quella di verificare la possibilità di aprire il file mediante la funzione `is_open()`. Questa funzione infatti ci indica se il file è stato correttamente aperto e, ovviamente, qualora questo non sia avvenuto, potremo tranquillamente desumere che il file non esiste, o che vi è stato un qualche altro tipo di problema. Modifichiamo quindi il nostro codice come segue:

```cpp hl_lines="5-9" linenums="1"
// Header

int main() {
	ifstream input("input.txt")
	if (intput.is_open()) {
		cout << "Il file esiste!";
	} else {
		cout << "Il file non esiste!";
	}
	// ...
}
```

!!!note "Nota"
	Effettueremo un controllo analogo anche sui file in apertura.

### Step 3: Apertura del file in output

Possiamo quindi passare ad aprire il file su cui andremo a copiare i contenuti del file di input. Per farlo, creeremo una variabile di classe `ofstream`, che chiameremo `output`, e che creerà (se non esiste) il file **output.txt**. Verificheremo anche che il file sia stato effettivamente creato richiamando il metodo `is_open()`:

```cpp hl_lines="7-8" linenums="1"
// Header

int main() {
	// ...
	if (input.is_open()) {
		// ...
		ofstream output("output.txt");
		if (output.is_open()) {
			// ...
		}
	}
	// ...
}
```

!!!note "Nota"
	Di default, `ofstream` apre i file in modalità *truncate*, il che significa che il contenuto esistente del file sarà sovrascritto. E' tuttavia possibile specificare, come nel C, la modalità di apertura del file, tra quelle definite nella [libreria standard C++](https://en.cppreference.com/w/cpp/io/ios_base/openmode).

### Step 4: Copia del file riga per riga

Modifichiamo l'istruzione precedentemente alla riga 8 (ovvero, l'istruzione condizionale annidata) in questo modo:

```cpp hl_lines="5-14" linenums="1"
// Header

int main() {
	// ...
	if (output.is_open()) {
		string line;
		int row = 1;
		while (getline(input, line) && output.good()) {
			output << line << endl;
			cout << "Linea " << row << " copiata" << endl;
			row++;
		}
		output.close();
	}
	// ...
}
```

In primis, notiamo l'utilizzo della funzione `getline()`, che accetta in ingresso la variabile `input` ed una stringa, che chiameremo `line`, e che rappresenta un contenitore per il contenuto della riga specifica. Di norma, la `getline()` restituisce un riferimento allo stream passato come argomento (ovvero `input`); tuttavia, nel nostro caso, lo useremo come valore booleano per valutare l'effettiva esistenza dello stream. Inoltre, usiamo il metodo `good()` sullo stream relativo all'oggetto `output`, in modo da verificarne lo stato.

L'unico fattore di nota all'interno del ciclo `while` è legato al fatto che utilizziamo lo stream relativo all'oggetto `output` esattamente allo stesso modo in cui usiamo lo stream relativo all'output su riga di comando. Nello specifico, dopo aver copiato l'i-ma riga del file **input.txt** in **output.txt**, manderemo su riga di comando un messaggio di conferma dell'avvenuta copia della riga. Notiamo infine il metodo `close()`, che serve per chiudere un file (e rilasciare le relative risorse occupate).

!!!note "Nota"
	Il metodo `close()` va chiamato **su ogni variabile associata ad uno stream su file**. Ergo, anche sul file che sta venendo letto!

### Codice completo

Il codice completo per la copia del file è mostrato di seguito.

```cpp linenums="1"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream input("inpput.txt");
	if (input.is_open()) {
		cout << "File letto correttamente." << endl;
		ofstream output("output.txt");
		if (output.is_open()) {
			string line;
			int row = 1;
			while (getline(input, line) && output.good()) {
				output << line << endl;
				cout << "Linea " << row << " copiata" << endl;
				row++;
			}
			output.close();
		}
		input.close();
	}
	else {
		cout << "Errore nella lettura del file.";
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
```

## Esempio 2: Copia carattere per carattere

Un altro esempio è quello che vede la copia di un file carattere per carattere. Notiamo che gli step 1 - 3 di questo esempio sono analoghi a quelli dell'esempio precedente, a meno del mancato utilizzo dell'header `string`, questa volta non necessario.

Di conseguenza, rivediamo esclusivamente lo step 4.

### Step 4: Copia del file carattere per carattere

La parte interessata dalle modifiche è quella evidenziata nel listato successivo.

```cpp linenums="1" hl_lines="10-21"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream input("input.txt");
	if (input.is_open()) {
		ofstream output("output.txt");
		if (output.is_open()) {
			char c = NULL;
			while (input.get(c) && output.good()) {
				if (output.put(c)) {
					cout << "Carattere " << c << " copiato" << endl;
				}
				else {
					cout << "Impossibile copiare il carattere " << c << endl;
					exit(EXIT_FAILURE);
				}
			}
			output.close();
		}
		else {
			cout << "Errore di I/O sul file di output." << endl;
			exit(EXIT_FAILURE);
		}
		input.close();
	}
	else {
		cout << "Errore di I/O sul file di input." << endl;
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

```

Notiamo innanzitutto la funzione `get()` che, in maniera simile alla `getline()`, scandisce il file associato alla variabile `input`, questa volta carattere per carattere. Notiamo una differenza: laddove la `getline()` prende due parametri in ingresso, la `get()` viene chiamata direttamente sulla variabile associata al file di input, ed accetta come parametro esclusivamente il riferimento al carattere attualmente scandito.

Dopo la `get()`, troviamo una chiamata alla funzione "duale", ovvero la `put()`, che (prevedibilmente) si occupa di scrivere il carattere passato in ingresso sul file di output.

## Bonus: combinare i due esempi

Di seguito il codice per un possibile approccio alla combinazione dei due esempi precedenti.

```cpp linenums="1"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Funzione per la copia carattere per carattere. Ricordare il passaggio per reference!
void char_copy(ifstream& input, ofstream& output) {
	char c = NULL;
	while (input.get(c) && output.good()) {
		if (output.put(c)) {
			cout << "Carattere " << c << " copiato" << endl;
		}
		else {
			cout << "Impossibile copiare il carattere " << c << endl;
			exit(EXIT_FAILURE);
		}
	}
}

// Funzione per la copia riga per riga. Ricordare il passaggio per reference!
void row_copy(ifstream& input, ofstream& output) {
	string line;
	int row = 1;
	while (getline(input, line) && output.good()) {
		output << line << endl;
		cout << "Linea " << row << " copiata" << endl;
		row++;
	}
}

int main() {
	cout << "Inserire 0 per lettura riga a riga, ed 1 per lettura carattere per carattere." << endl;
	bool char_or_row = false;
	cin >> char_or_row;
	ifstream input("input.txt");
	if (input.is_open()) {
		ofstream output("output.txt");
		if (output.is_open()) {
			if (char_or_row) {
				char_copy(input, output);
			}
			else {
				row_copy(input, output);
			}
		}
		else {
			cout << "Errore di I/O sul file di output." << endl;
			exit(EXIT_FAILURE);
		}
		input.close();
	}
	else {
		cout << "Errore di I/O sul file di input." << endl;
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
```
