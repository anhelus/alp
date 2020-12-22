# Alcune definizioni

## Namespace

Quando abbiamo parlato delle variabili e delle funzioni in C, abbiamo sottolineato come non fosse possibile associare ad una variabile una determianta parola riservata. Inoltre, dato che il C++ permette (ed anzi favorisce) la definizione di nuovi tipi, potremmo trovarci nella situazione in cui si creano delle ambiguità, magari perché si sfruttano librerie di terzi che contengono alcuni tipi i cui nomi sono analoghi a quelli da noi definiti.

Per ovviare a queste limitazioni, il C++ introduce il concetto di *namespace*, inteso come "domini" di nomi tra loro indipendenti ed in grado di coesistere, permettendo di conseguenza la definizione ed utilizzo di tipi con lo stesso nome (ma appartenenti a namespace differenti).

Immaginiamo ad esempio di voler usare definire un metodo che restituisca le coordinate di un punto, e che queste debbano essere restituite in termini cartesiani e polari. Le strade percorribili potrebbero essere due.

La prima prevede l'utilizzo di due funzioni, chiamate ad esempio `restituisci_coordinate_cartesiane` e `restituisci_coordinate_polari`:

```cpp
double* restituisci_coordinate_cartesiane(double x, double y) {
	double coordinate[2] = {x, y};
	return coordinate;
}

double* restituisci_coordiante_polari(double r, double theta) {
	double coordinate[2] = {r, theta};
	return coordinate;
}
```

Questa soluzione ha uno svantaggio nel lungo periodo: man mano che aggiungiamo delle funzioni che operano su un sistema cartesiano o polare, infatti, il codice diverrà sempre più prolisso, con la conseguenza di essere sempre più "prono" ad eventuali errori.

La seconda soluzione sta quindi nell'utilizzo dei namespace:

```cpp
namespace cartesiano {
	double* restituisci_coordinate(double x, double y) {
		// ...
	}
}

namespace polare {
	double* restituisci_coordinate(double r, double theta) {
		// ...
	}
}
```

Abbiamo quindi definito due "domini", all'interno di ciascuno dei quali viene definita una funzione restituisci coordinate che, però, non sarà ambigua, perché univoca all'interno del suo namespace. Il vantaggio è chiaro quando ad esempio andiamo a definire altre funzioni, come ad esempio `trova_coeff_retta` e `trova_coeff_circonferenza`:

```cpp
namespace cartesiano {
	double* restituisci_coordinate(double x, double y) {
		// ...
	}

	double* trova_coeff_retta() {
		// ...
	}

	double* trova_coeff_circonferenza() {
		// ...
	}

}

namespace polare {
	double* restituisci_coordinate(double r, double theta) {
		// ...
	}

	double* trova_coeff_retta() {
		// ...
	}

	double* trova_coeff_circonferenza() {
		// ...
	}
}
```

Se avessimo optato per la soluzione precedente, avremmo dovuto scrivere sempre sei funzioni, ma postponendo (o anteponendo) un indicatore del tipo di coordinate, il che avrebbe peggiorato la leggibilità del nostro codice (ed aumentato la possibilità di fare errori).

### Utilizzare un namespace

Abbiamo due possibilità per utilizzare un namespace. La prima è quella di utilizzare la clausola `using namespace`:

```cpp
// ...
using namespace cartesiano;
```

La seconda è quella di anteporre il namespace direttamente al membro che utilizzeremo:

```cpp
// ...
cartesiano::restituisci_coordinate(2.0, 3.0);
```

In generale, il consiglio è, quando possibile, quello di scegliere la prima soluzione. Infatti, se nel nostro programma dovessimo utilizzare (ad esempio) soltanto le coordinate cartesiane, mediante la clausola `using namespace` ridurremmo di molto la prolissità del nostro codice. Ovviamente, ci sono delle situazioni nelle quali non ci si può limitare ad usare la suddetta clausola, per cui in quei casi è bene ricorrere anche alla seconda soluzione.

!!!tip "Il namespace `std`"
	Il namespace maggiormente usato in C++ è chiamato `std` (che, ovviamente, è una crasi di standard). Come buona prassi, specie nei programmi che fanno largo uso delle librerie standard, sarebbe bene importarlo in modo da ottenere un codice meno "prolisso".

## I/O in C++ (da riga di comando)

Quando abbiamo parlato del C, abbiamo visto che vi sono alcune funzioni, incluse nella libreria `stdio`, dedicate espressamente all'interazione con l'utente tramite il concetto di *stream*.

Il C++, nonostante possa agevolmente usare le funzioni `printf()` o `scanf()`, offre un'interfaccia evoluta verso gli stream mediante la libreria `iostream`.

### Output su riga di comando

L'output su riga di comando è ottenuto usando delle istanze di una classe base, chiamata `ostream`, e definita all'interno del namespace `std`. In particolare, esistono tre tipi di canali di output:

* `std::cout`: questo è il canale di output predefinito, usato alla stregua della funzione `printf()`; a differenza di quest'ultima, però, offre funzionalità più sofisticate, ed è in grado di riconoscere in maniera automatica il tipo della variabile passata, convertendolo sullo stream in uscita. E' importante sottolineare come il `cout` utilizzi un buffer di uscita: ciò significa che, specialmente nelle applicazioni ad elevata intensita, ci sarà una latenza tra l'immisione di un messaggio sul `cout` e la sua effettiva visualizzazione;
* `std::cerr`: questo è un canale usato per trasmettere dei messaggi di errore. Vista la sua particolare funzione (e considerato che un messaggio di errore coincide di solito con il termine del programma), non è provvisto di buffer come il `cout`;
* `std::clog`: questo è un canale accessorio, dedicato al *logging*, e mediante il quale possiamo tenere traccia del comportamento "interno" del programma, verificandone le condizioni nel caso ci siano dei bug.

La sintassi standard dei diversi operatori è la seguente:

```cpp
#include <iostream>

using namespace std;

int main() {
	cout << "Questo è un messaggio in output" << endl;
	cerr << "Questo è un messaggio di errore" << endl;
	clog << "Questo è un messaggio di log" << endl;
}
```

L'operatore `<<` è detto di *inserimento*, e restituisce in realtà un riferimento allo stream. Ciò implica che è possibile concatenare più operazioni di output:

```cpp
cout << "Concateno il numero: " << 2 << endl;
```

Nell'istruzione precedente, notiamo l'uso di `endl` che, come suggerisce il nome, è una crasi di *end line*, ed ha un comportamento equivalente all'escape sequence `\n`.

### Input da riga di comando

Anche per quello che riguarda la lettura degli input da riga di comando, C++ utilizza l'istanza `cin` della classe `istream`; in questo caso, viene usato l'operatore di *estrazione* `>>` per leggere i dati dal canale di input.

```cpp
int a;
cin >> a;
```

!!!note "Gestione dei diversi tipi base"
	Avremo notato che sia `ostream` sia `istream` gestiscono in automatico diversi tipi di dati, come ad esempio le stringhe. Questo avviene mediante una tecnica chiamata overloading, che approfondiremo nel seguito.

#### Inserimento di più input

Anche il canale `cin` gestisce i dati in input mediante un buffer, e riconosce lo spazio come input per separare i diversi elementi; questo permette quindi di concatenare più estrazioni consecutivamente.

Ad esempio:

```cpp
int a;
string s;
cin >> a >> s;
```

#### Verifica dei valori inseriti

Un modo per verificare la correttezza dei tipi dei valori inseriti è quello di usare il metodo `good()`, che restituisce false nel caso questi non siano stati ben interpretati.

Tornando al nostro esempio:

```cpp
int a;
string s;
cin >> a >> s;
// Verifico la correttezza degli input
if (cin.good()) {
	cout << "Ok!";
}
else {
	cerr << "Errore!"
}
```

#### Inserire stringhe composte da più parole

L'uso dello spazio come separatore di diversi input può essere problematico nel caso si voglia inserire una stringa composta da più parole (come il nostro caro vecchio `Hello, World!`, di cui verrebbe catturato soltanto l'`Hello,`). La classe `istream` prevede quindi anche il metodo `getline()`, incluso nella libreria `string`, che abilita la lettura di tutti i dati inseriti nello stream fino alla pressione del tasto Enter.

```cpp
#include <string>

string composed;
getline(cin, composed);
if (cin.good()) {
	cout << "Hai inserito " << composed;
}
else {
	cerr << "Errore!";
}
```

## Variabili reference

La funzione delle *variabili reference* è quella di occupare la *stessa area di memoria* di una variabile già esistente. In tal senso, vengono anche chiamate *alias*.

Le variabili reference sono principalmente usate come notazione sostitutiva a quella dei puntatori: infatti, invece di accedere ad una variabile puntata da un puntatore mediante l'operazione di dereferenziazione, si può direttamente usare una variabile reference per avere un risultato analogo. In altre parole:

```cpp
int a = 2;
int* pa = &a;
int& ref_a = a;

cout << "Accesso al valore di a mediante dereferenziazione: " << *pa << endl;
cout << "Accesso al valore di a mediante variabile reference: " << ref_a << endl;
```

Notiamo che la dichiarazione della variabile reference è preceduta dal simbolo `&`.

### Perché usare le variabili reference?

Può essere quindi utile preferire l'uso delle variabili reference ai puntatori per due motivi:

1. migliore leggibilità del codice, legata ad una sintassi meno "prolissa";
2. se una variabile reference non viene inizializzata, si ha un errore in fase di compilazione (lo stesso non avviene con i puntatori).

### Tipo delle variabili reference

Abbiamo visto che esiste una differenza tra il tipo associato ad un puntatore e quello della variabile cui punta. Ad esempio, un puntatore a `float` è di tipo `float*`, mentre la variabile puntata rimane di tipo `float`.

Questo non accade però con le variabili reference, per le quali la forma `tipo&` non è associata ad nuovo tipo di dato: infatti, il *tipo di una variabile reference è lo stesso usato dalla variabile ordinaria cui è associata*. Nel nostro esempio, quindi, sia `a` sia `ref_a` saranno variabili intere.

!!!note "Come imbrogliare il compilatore"
	Un modo per "imbrogliare" il compilatore C++ è quello di usare una variabile reference come alias di un puntatore a null, contraddistinto in C++ dalla parola chiave `nullptr` (e che sostituisce `NULL`).

## Concetti avanzati sulle funzioni

Il C++ introduce alcuni concetti avanzati relativamente alle funzioni.

### Parametri opzionali

Le funzioni normalmente utilizzano il concetto di argomento per dare la possibilità alla funzione chiamante (o al programmatore) di impostare tutti i parametri dell'algoritmo. Ad esempio, una funzione che calcola l'ordinata di una retta potrebbe accettare come parametri il coefficiente angolare, l'intercetta e l'ordinata.

Alle volte, però, è possibile stabilire "a priori" i valori che meglio si adattano al nostro algoritmo; il C++ introduce quindi la possibilità (ripresa da molti altri linguaggi) di applicare tali valori predefiniti, includendoli nella dichiarazione del prototipo della funzione con una sintassi del tipo:

```cpp
tipo_ritorno nome_funzione (tipo_argomento nome_argomento_opzionale=valore_default)
```

Vediamo, ad esempio, una funzione che permette di calcolare il voto medio degli esoneri, considerando un valore di default di quattro per il parametro `numero_esoneri`.

```cpp
#include <iostream>

int calcola_voto_esame(int* voto_esoneri, int numero_esoneri = 4) {
	int sum = 0;
	for (int i = 0; i < numero_esoneri; i++) {
		sum += voto_esoneri[i];
	}
	return int(round(sum / numero_esoneri));
}

int main()
{
	int voti_interi[4] = { 25, 24, 22, 28 };
	int voto_intero = calcola_voto_esame(voti_interi);
	cout << "Voto approssimato: " << voto_intero << endl;
}
```

Sarà ovviamente possibile variare il valore associato al parametro opzionale mantenendo "intatto" il funzionamento della funzione.

### Overloading

L'*overloading* delle funzioni permette di mantenere lo stesso nome per diverse funzioni, a patto che il compilatore sia in grado di comprendere quale tra queste stia venendo di volta in volta utilizzata specificando diversi parametri di input. Ritornando al nostro esempio precedente, immaginiamo di voler considerare dei valori reali mantenendo una "interfaccia comune". Sfruttando l'overloading:

```cpp
#include <iostream>
#include <math.h>

using namespace std;

int calcola_voto_esame(int* voto_esoneri, int numero_esoneri = 4) {
	int sum = 0;
	for (int i = 0; i < numero_esoneri; i++) {
		sum += voto_esoneri[i];
	}
	return int(round(sum / numero_esoneri));
}

double calcola_voto_esame(double* voto_esoneri, int numero_esoneri = 4) {
	double sum = 0;
	for (int i = 0; i < numero_esoneri; i++) {
		sum += voto_esoneri[i];
	}
	return (sum / numero_esoneri);
}

int main() {
	int voti_interi[4] = { 25, 24, 22, 28 };
	double voti_reali[4] = { 25.3, 24.1, 21.9, 28.1 };
	int voto_intero = calcola_voto_esame(voti_interi);
	double voto_reale = calcola_voto_esame(voti_reali);

	cout << "Voto approssimato: " << voto_intero << endl;
	cout << "Voto reale: " << voto_reale << endl;
}
```

E' importante sottolineare come il tipo restituito dalla funzione non influisca nella selezione della funzione in overload.

Usare l'overload può essere utile, e quando parleremo delle classi talvolta indispensabile, ma comporta anche dei rischi: è necessario infatti evitare ambiguità nei parametri forniti, o sfruttare i meccanismi di cast per assicurarsi di stare chiamando la giusta funzione in overload. Ecco infatti un caso particolare:

```cpp
void promosso_o_bocciato(bool esito) {
	if (esito) {
		cout << "Sei stato bocciato!" << endl;
	}
}

void promosso_o_bocciato(string esito) {
	cout << esito;
}

int main() {
	promosso_o_bocciato("Sei stato promosso!");
}
```

Chiamare la funzione con un argomento di tipo stringa, infatti, si traduce in una chiamata all'overloading con il tipo booleano in ingresso! Questo avviene principalmente perché il compilatore applica i meccanismi di inferenza di tipo previsti dallo standard C++, e fa sì che ci sia prima una conversione ad un puntatore a tipo `char`, il quale viene poi convertito in booleano! Il motivo di questa scelta è, ovviamente, per motivi di retrocompatibilità con il C, ma ci deve comunque essere di lezione per evitare di usare l'overloading in maniera eccessivamente "avventata".
