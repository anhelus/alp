# Le Classi

Il concetto di *classe* permette di espandere in maniera potenzialmente *infinita* l'insieme dei tipi a disposizione dello sviluppatore, dando la possibilità di *comporre nuovi oggetti*. Ogni oggetto avrà al suo interno *attributi* (che a loro volta possono essere altri oggetti) e *metodi* da invocare su questi oggetti; a loro volta, attributi e metodi saranno dotati di un *livello di accesso*, che limiterà l'accesso agli stessi da parte del mondo "esterno" (ovvero, altre classi e programmi). In tal senso, le classi sfruttano una tecnica chiamata *incapsulamento*, definendo una *interfaccia* verso il mondo esterno per manipolare i dati della classe mascherando le dinamiche di funzionamento interno. Questa tecnica è anche chiamata *information hiding*.

La sintassi per la definizione di una classe è la seguente:

```cpp
class NomeClasse
{
	public:
		// attributi o metodi accessibili all'esterno della classe
	private:
		// attributi o metodi accessibili solo dall'interno della classe 
	protected:
		// attributi o metodi accessibili solo dalle classi "figlie
}
```

Le tre sezioni di cui sopra servono a definire il livello di accesso (e, quindi, la *visibilità*) di ciascun membro o attributo. Di default, membri ed attributi sono considerati privati.

## Definire ed implementare una classe

Il concetto di information hiding si ripercuote sul modo di definire una classe. Normalmente, infatti, viene usato un file header per definire l'interfaccia della classe, ed un normale file con estensione `.cpp` per implementare effettivamente i metodi contenuti. Vediamo quindi un esempio pratico.

### Definizione della classe

Creiamo un header chiamato `persona.h` con il seguente codice:

```cpp
// File persona.h
#ifndef PERSONA_H
#define PERSONA_H
#include <string>

using namespace std;

namespace Persona
{
	class PersonaBase;
}

class Persona::PersonaBase
{
private:
	string nome;
	string cognome;
	int eta;
public:
	string getNome();
	string getCognome();
	int getEta();
	void setNome(string nuovoNome);
	void setCognome(string nuovoCognome);
	void setEta(int nuovaEta);
};

#endif // !PERSONA_H
```

Notiamo subito tre cose:

* sfruttiamo il concetto di *include guards*, ovvero delle direttive da specificare al preprocessore per impedire che l'header sia incluso più di una volta durante la compilazione;
* allo scopo di evitare collisioni, definiamo un namespace che contiene le definizioni delle classi che useremo (in questo caso, lo chiameremo `Persona`);
* includiamo l'header `<string>` ed usiamo il namespace `std` onde includere il tipo `string` ed evitare un'eccessiva ripetitività del codice.

La classe `PersonaBase` (il motivo della scelta di questo nome sarà chiaro più avanti) conterrà tre attributi, due di tipo string (ovvero `nome` e `cognome`), ed uno di tipo intero (ovvero `eta`). Notiamo come gli attributi siano dichiarati come privati, ed a ciascuno di essi sia associato un metodo pubblico per garantirne l'accesso rispettivamente in lettura (i metodi che iniziano con il suffisso `get`, detti anche *getter* o, in una tradizione "passabile", *accessori*) ed in scrittura (i metodi che iniziano con il suffisso `set`, detti anche *setter* o *modificatori*).

Notiamo infine che l'intera definizione di classe è seguita dal simbolo `;` a causa di ragioni di retrocompatibilità con le `struct` mutuate dal linguaggio C.

### Implementazione della classe

Creiamo ora un sorgente `persona.cpp` contenente il seguente codice:

```cpp
// File persona.cpp
#include "persona.h"
#include <iostream>

using namespace std;
using namespace Persona;

string PersonaBase::getNome() {
	return nome;
}

string PersonaBase::getCognome() {
	return cognome;
}

int PersonaBase::getEta() {
	return eta;
}

void PersonaBase::setNome(string nuovoNome) {
	if (nuovoNome.length() > 2) {
		nome = nuovoNome;
	}
}

void PersonaBase::setCognome(string nuovoCognome) {
	if (nuovoCognome.length() > 2) {
		cognome = nuovoCognome;
	}
}

void PersonaBase::setEta(int nuovaEta) {
	if (nuovaEta >= 0) {
		eta = nuovaEta;
	}
}

```

Notiamo innanzitutto l'inclusione dell'header `persona.h`, che va ovviamente incluso assieme a tutti gli altri necessari. Inoltre, usiamo il namespace `std` ed il namespace `Persona` per accedere in maniera non eccessivamente prolissa ai metodi di `PersonaBase`.

!!!note "Nota"
	Avremmo potuto usare la clausola `using Persona::PersonaBase` per ridurre ulteriormente il codice utilizzato. Tuttavia, dato che in seguito aggiungeremo altre classi al nostro namespace, è meglio usare la clausola `using` nel modo descritto in precedenza.

Il motivo per cui gli attributi sono dichiarati privati ed i metodi `getter` e `setter` pubblici è spiegato dall'implementazione. Notiamo infatti che i diversi metodi modificatori compiono delle verifiche sugli argomenti passati in ingresso; se accedessimo direttamente agli attributi, dovremmo implementare il codice necessario a questi controlli ogni volta. Inoltre, mantenere un'interfaccia comune permette di modificare l'implementazione dei propri metodi senza dover per questo alterare il programma chiamante.

### Esempio di utilizzo

Proviamo ad utilizzare la nostra classe per creare una nuova istanza di `PersonaBase` all'interno del metodo `main()`:

```cpp
#include "persona.h"
#include <iostream>

using namespace Persona;
using namespace std;

int main() {
	PersonaBase truce;
	truce.setNome("Truce");
	truce.setCognome("Baldazzi");
	truce.setEta(18);

	cout << "Nome: " << truce.getNome() << "\tCognome: " << truce.getCognome() << "\tEta': " << truce.getEta() << endl;

	return 0;
}
```

!!!tip "Classi e struct"
	Nel C++, le struct sono considerate equivalenti alle classi, dato che vengono tradotte in fase di compilazione in classi con soli membri `public`. L'unico motivo per utilizzarle risiede nella retrocompatibilità con codice scritto in linguaggio C.

## Utilizzare le istanze di una classe

### Costruttori

Nell'esempio precedente, abbiamo visto come *dichiarare* un nuovo oggetto, ma non come *inizializzarlo* ed *utilizzarlo*. Per farlo, ci sono due operazioni preliminari da svolgere:

1. allocare la memoria per attributi e metodi dell'oggetto;
2. inizializzare ogni attributo.

Queste operazioni sono svolte da una particolare funzione chiamata *costruttore*, il cui prototipo presenta due caratteristiche uniche:

1. il nome del costruttore *coincide con quello della classe*;
2. un costruttore *non* ha alcun tipo o valore di ritorno.

Per il resto, il costruttore è una normalissima funzione, che può accettare più argomenti, anche opzionali. In particolare, un costruttore che non accetta argomenti (o che accetta soltanto argomenti opzionali) è detto *costruttore di default*.

Normalmente, il compilatore genera in automatico un costruttore di default, dato che in grado di dedurre autonomamente la quantità di spazio da riservare per un oggetto a compile time, definendo contestualmente un valore di default per ogni membro. Questa operazione ha tuttavia dei limiti, ed è comunque preferibile definire manualmente un costruttore di default, specialmente nei casi "limite" in cui si ha a che fare con attributi sotto forma di puntatori.

Modifichiamo quindi la nostra classe andando ad inserire due costruttori, uno di default ed uno che accetta tre parametri.

```cpp
// File persona.h
#ifndef PERSONA_H
#define PERSONA_H
#include <string>

using namespace std;

namespace Persona
{
	class PersonaBase;
}

class Persona::PersonaBase
{
private:
	string nome;
	string cognome;
	int eta;
public:
	PersonaBase();
	PersonaBase(string nuovoNome, string nuovoCognome, int nuovaEta);
	string getNome();
	string getCognome();
	int getEta();
	void setNome(string nuovoNome);
	void setCognome(string nuovoCognome);
	void setEta(int nuovaEta);
};

#endif // !PERSONA_H

// File persona.cpp
#include "persona.h"
#include <iostream>

using namespace std;
using namespace Persona;

PersonaBase::PersonaBase() {
	setNome("Non definito");
	setCognome("Non definito");
	setEta(0);
}

PersonaBase::PersonaBase(string nuovoNome, string nuovoCognome, int nuovaEta) {
	setNome(nuovoNome);
	setCognome(nuovoCognome);
	setEta(nuovaEta);
}

string PersonaBase::getNome() {
	return nome;
}

string PersonaBase::getCognome() {
	return cognome;
}

int PersonaBase::getEta() {
	return eta;
}

void PersonaBase::setNome(string nuovoNome) {
	if (nuovoNome.length() > 2) {
		nome = nuovoNome;
	}
}

void PersonaBase::setCognome(string nuovoCognome) {
	if (nuovoCognome.length() > 2) {
		cognome = nuovoCognome;
	}
}

void PersonaBase::setEta(int nuovaEta) {
	if (nuovaEta >= 0) {
		eta = nuovaEta;
	}
}
```

!!!note "Nota"
	E' interessante sottolineare come all'interno del costruttore parametrizzato si usino i setter per modificare i valori degli attributi. Questa operazione è consigliata per gli stessi motivi sottolineati in precedenza relativamente all'accesso degli attributi da variabili e metodi esterni alla classe.

### Distruttori

Una volta terminato l'utilizzo di un oggetto, è necessario rilasciare le risorse da questo utilizzate in memoria. Per far questo, si utilizza un opportuno metodo chiamato *distruttore*, che viene automaticamente invocato su ogni variabile una volta raggiunto il termine del suo ambito di visibilità (oppure mediante l'invocazione della parola chiave `delete`).

La firma di un distruttore ha anch'essa alcune particolarità: infatti, il nome coincide sì con quello della classe invocante, ma è preceduto dal carattere `~` (la tilde, ottenibile mediante il codice ASCII 0126). Come il costruttore, inoltre, il distruttore non ha alcun tipo o valore di ritorno, ed a differenza del costruttore non accetta alcun parametro in ingresso. Per il resto, il distruttore è una funzione come le altre, il cui unico compito però rimane quello di *rimuovere dalla memoria un oggetto e tutte le sue dipendenze*.

Molto spesso non è necessario definire in maniera esplicita il distruttore, in quanto questo viene generato automaticamente. Tuttavia, qualora l'oggetto utilizzato includa delle reference (variabili alias o puntatori) o faccia uso di risorse esterne (ad esempio file), potrebbe essere necessario definirlo per svolgere le operazioni adegaute a "concludere" adeguatamente le operazioni.

Nel nostro caso, ad esempio, non è necessario specificare un distruttore. Immaginiamo però di associare alla nostra classe un riferimento ad un puntatore; dovremo quindi definire un adeguato distruttore:

```cpp
// persona.h
// ...
class Persona::PersonaBase
{
	private:
		// ...
		int* puntatoreEta;
		// ..
	public:
		// ...
		~PersonaBase();
		// ...
}
```

Il distruttore dovrà poi essere implementato all'interno del file `persona.cpp`:

```cpp
// persona.cpp
PersonaBase::PersonaBase()
{
	// ...
	puntatoreEta = &eta;
	// ...
}
PersonaBase::~PersonaBase()
{
	delete puntatoreEta;
}
```

E' importante sottolineare il ruolo fondamentale giocato dal distruttore in queste situazioni. Trascurandolo, infatti, avremmo un *memory leak* (come in questo caso), oppure potremmo rendere inaccessibile uno stream (come ad esempio un file binario di logging).
