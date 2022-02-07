# Classi e funzioni

## Funzioni membro

Finora abbiamo parlato diverse volte del concetto di *funzione membro*: esempi sono costruttori, distruttori ed operatori, tutti dotati di una sintassi ben definita a causa delle peculiarità del loro compito. Tuttavia, le funzioni membro non hanno necessariamente delle caratteristiche particolari: in realtà, qualsiasi funzione può essere definita come funzione membro.

Ciò non significa però che non vi siano differenze tra le funzioni generiche (quelle dichiarate all'esterno di una classe) e le funzioni membro: queste sussistono infatti soprattutto nell'*ambito* e *visibilità*, oltre che di capacità di accedere ai membri della classe (ricordiamo che ad ogni funzione membro viene implicitamente passato il puntatore `this`). In particolare:

* una funzione membro non può essere invocata se non su un'istanza della classe di appartenenza;
* grazie al puntatore `this`, la funzione membro ha accesso non solo ai parametri di input ed alle variabili dichiarate localmente, ma anche a tutti gli attributi e le funzioni della classe di appartenenza.

E' inoltre importante una corretta gestione dei modificatori di accesso delle funzioni membro, soprattutto in sede di *refactoring* del codice. Infatti, le funzioni dichiarate con il modificatore `public` sono molto spesso invocate al di fuori della classe su specifiche istanze della stessa; in tal senso, bisogna tener presente che, modificando il nome della funzione membro, si influenzerà il comportamento di *tutto il codice chiamante*.

Immaginiamo ad esempio di usare in questo modo la nostra classe `Vettore`:

```cpp
// main.cpp
int main() {
	Vettore v1 = new Vettore(10.0, 45.0);
	Vettore v2 = new Vettore(5.0, 45.0);
	if(v1.getAngolo() == v2.getAngolo()) {
		// I due vettori sono paralleli, la somma dei moduli è più semplice
		double sommaModuli = v1.getModulo() + v2.getModulo(); 
	}
}
```

Immaginiamo quindi di decidere, per un motivo qualsiasi, di modificare le firme dei getter in questo modo:

```cpp
// vettore.h
class Vettore {
	// ...
	public:
		double angolo();		// Precedentemente getAngolo()
		double modulo();		// Precedentemente getModulo()
}
```

Cosa accadrebbe al codice chiamante (ovvero al `main.cpp`)? Beh, chiaramente avremmo un errore in fase di compilazione!

Adesso, come al solito, stiamo considerando casi abbastanza "ristretti"; qualora però dovessimo sviluppare delle *grosse* librerie, magari utilizzate da diversi sviluppatori (anche esterni), allora una qualsiasi modifica, anche di scarsa rilevanza come questa, potrebbe causare errori e problemi, con la conseguenza di richiedere tempo (e denaro) per la loro risoluzione. Ovviamente, ci sono casi in cui queste situazioni diventano inevitabili; tuttavia, è sempre bene essere consapevoli di quelle che sono le proprie responsabilità nell'effettuare modifiche, ed attenersi quanto più possibile alle *best practices* (che, in soldoni, ci chiedono di aderire il più possibile al principio dell'incapsulamento)!

## Funzioni `inline`

Una possibile forma di ottimizzazione del codice prevede l'applicazione alle funzioni della parola chiave `inline`, rappresentativa di una direttiva al compilatore che, se eseguita, permette di sostituire nel codice compilato la chiamata a funzione con il corpo della stessa. Se da un lato questo può migliorare le prestazioni, dall'altro ovviamente influenza le dimensioni dell'eseguibile finale, per cui va usata con un certo giudizio; inoltre, l'effettivo impatto sulle prestazioni dipende anche dal compilatore, che potrebbe anche ignorare (totalmente o in parte) la direttiva, o applicarla a metodi che non l'abbiano esplicitamente definita.

La sintassi per la definizione di una generica funzione inline è la seguente:

```cpp
inline int somma(int a, int b)
{
	return a + b;
}

int main()
{
	somma(2, 3);
	return 0;
}
```

E' ovviamente possibile definire un metodo inline direttamente in una classe. Per farlo, possiamo specificarlo nell'header; ad esempio:

```cpp
// geometria.h
class Vettore {
	// ...
	public:
		inline double getModulo() {
			return this->modulo;
		}
}
```

Un altro modo è specificarlo nel file sorgente, ad esempio:

```cpp
// geometria.h
class Vettore {
	// ...
	public:
		double getModulo();
}

// geometria.cpp
// Dovremo ridefinirlo in ogni sorgente in cui lo utilizziamo!
inline double Vettore::getModulo() {
	return this->modulo;
}
```

Tuttavia, quando si definisce una funzione inline, è necessario che il corpo della stessa sia presente in ogni **unità di compilazione**. Questo implica la necessità di includere la definizione del metodo inline o direttamente nell'header, oppure in ognuno dei file sorgenti in cui la funzione viene invocata. Scegliendo il secondo metodo, quindi, il nostro `main` assumerà una forma del tipo:

```cpp
#include <iostream>
#include "geometria.h"

using namespace std;

// Rimuovendo questa definizione, avremo un errore di compilazione
inline double Vettore::getModulo() {
	return this->modulo;
}

int main()
{
	Vettore v1 = new Vettore(10.0, 45.0);
	cout << v1.getModulo() << endl;
	return 0;
}
```

!!!note "Nota"
	E' chiaro come entrambe le opzioni non siano esattamente "ottimali". Nel primo caso, infatti, stiamo violando uno dei principi della OOP, ovvero quello di incapsulamento, in quanto esponiamo all'interno di un interfaccia i dettagli dell'implementazione. Nel secondo, invece, dovremo ripetere il sorgente della funzione inline in ogni sorgente che la usa, con tutto ciò che ne consegue in termini di possibili errori e prolissità del codice. Di conseguenza, l'uso di questa particolare tecnica di ottimizzazione deve rimanere confinato al campo del "soltanto se indispensabile".

## Funzioni `const`

Abbiamo visto gli effetti della parola chiave `const` quando applicata ad una variabile. Applicandola però alla firma di una funzione membro, avrà l'effetto di inibire la modifica del membro stesso (ovviamente all'interno della funzione). In tal senso, l'esempio classico che è possibile fare è sui getter, che di solito vengono "decorati" con la keyword `const` per garantire che non vi siano effetti collaterali. Nel nostro caso:

```cpp
// geometria.h
class Geometria::Vettore
{
	//...
	private:
		double modulo;
		double angolo;
	public:
		double getModulo() const;
		double getAngolo() const;
		// ...
}

// geometria.cpp
double Vettore::getModulo() const {
	return this->modulo;
}

double Vettore::getAngolo() const {
	return this->angolo;
}
```

## Funzioni `static`

Le funzioni contrassegnate con la keyword `static` possono essere invocate *senza* la necessità di istanziare un oggetto della classe di appartenenza. Come conseguenza, si dice che i metodi statici sono *relativi alla classe*, e non alle singole istanze della stessa; ciò comporta quindi che all'interno dei metodi statici ci si possa riferire *esclusivamente* agli attributi statici della classe.

Supponiamo, ad esempio, di voler inserire un riferimento allo spazio cartesiano nel quale sono contenuti i nostri vettori; dato che questo risulta essere comune, potremo usare un attributo ed una funzione statici per ottenerli:

```cpp
// geometria.h
class Punto {
	// ...
}

class Vettore {
	private:
		static Punto origine;
	public:
		static Punto getOrigine();
}

// geometria.cpp
Punto Vettore::getOrigine()
{
	return origine;
}


// main.cpp
#include <iostream>
#include "geometria.h"

using namespace std;

int main()
{
	cout << Vettore::getOrigine() << endl;
	return 0;
}

```

Alcune note:

* le funzioni membro static di una classe sono accessibili mediante l'uso dell'operatore di scope;
* il qualificatore static appare nella dichiarazione della funzione membro, ma **non** nella sua definizione;
* i metodi statici non possono essere contestualmente `const`.

## La parola chiave `friend`

Chiudiamo questa carrellata introducendo il modificatore `friend`, che può essere assegnato a funzioni o classi che, pur non facendo parte dell'ambito della classe presso la quale vengono dichiarati, possono accedere ai membri della stessa indipendentemente dal qualificatore di accesso.

Immaginiamo ad esempio di definire una classe `SpazioVettoriale`, che per motivi implementativi deve poter accedere ai singoli vettori che compongono la sua base. Potremo quindi definirla come classe `friend` del singolo vettore:

```cpp
// geometria.h
class Vettore {
	private:
		// ...
		friend class SpazioVettoriale;
}
```

In questo modo, la classe `SpazioVettoriale` potrà accedere ai membri `private` dei vettori.

!!!note "Nota"
	Questo esempio apperentemente va in contrasto con le regole di incapsulamento dettate dalla OOP. Tuttavia, ed in situazioni complesse, l'utilizzo di una funzione o classe `friend` può risolvere numerosi grattacapi imposti da un'interpretazione troppo "rigida" dei dettami imposti dalla programmazione orientata agli oggetti.
