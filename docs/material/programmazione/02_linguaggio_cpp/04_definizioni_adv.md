# Alcune definizioni (avanzate!)

## La parola riservata `this`

Uno dei concetti più importanti del C++ è legato alla keyword `this`, la quale definisce uno speciale puntatore che contiene l'indirizzo della specifica istanza della classe cui è associato. Questo viene inizializzato in maniera automatica, e passato come parametro implicito ad ogni funzione (ad eccezione dei metodi statici, come vedremo in seguito).

!!!note "Nota"
	Va da sè che il tipo associato al puntatore `this` è quello di un puntatore alla classe stessa. Nel nostro esempio, `this` sarà associato alla classe `PersonaBase*`.

Il puntatore `this` gioca un ruolo fondamentale nella definizione di alcuni metodi, come ad esempio gli operatori di assegnazione, e più in generale ogni volta che ci si vuole riferire ad una specifica istanza di un oggetto. In tal senso, un uso "classico" di `this` è nei metodi setter:

```cpp
// persona.cpp
void setNome(string nome) {
	this->nome = nome;
}

void setCognome(string cognome) {
	this->cognome = cognome;
}

void setEta(int eta) {
	this->eta = eta;
}
```

Questa particolare modalità di utilizzo di `this` serve a referenziare un membro di classe il cui nome è oscurato da quello dell'argomento omonimo.

!!!note "L'uso di this"
	E' comunque utile sottolineare che l'uso di `this` rimane perlopiù opzionale, ancorché consigliato.

## Overloading degli operatori

Il C++ tratta gli operatori come delle vere e proprie *funzioni*, il cui nome assume la forma `operatorX`, dove `X` contraddistingue uno tra gli operatori (ad esempio quelli aritmetici) che abbiamo discusso in precedenza parlando del C. In quanto funzioni, inoltre, sono caratterizzati da tipo restituito e parametri accettati. La conseguenza più rilevante per i nostri scopi è che *è possibile effettuarne l'overloading*.

Tuttavia, l'uso di questa pratica, seppur necessario, non è banale. Infatti, l'overloading degli operatori implica la necessità di considerare la seguente sintassi:

```cpp
a.operatorX(b);
```

al posto della classica:

```cpp
a X b;
```

con tutto ciò che implica in termini di commutatività e simmetria dell'operatore.

In tal senso, è necessario distinguere tra due tipi di operatori, ovvero quelli per i quali l'overload può avvenire all'interno della classe, e quelli per i quali l'overload deve avvenire all'esterno della stessa.

### Operatori in overloading come membri di classe

Come detto in precedenza, l'overload di un operatore come membro della classe fa sì che il compilatore interpreti l'operazione come segue:

```cpp
// L'operatore binario X_bin passa da...
a X_bin b;
// ...ad...
a.operatorX_bin(b);
// L'operatore unario X_un passa da... 
X_un a;
// ...ad...
a.operatorX_un();
```

Immaginiamo quindi di avere una classe vettore, con attributi modulo ed angolo relativo rispetto all'asse delle ascisse, e voler implementare l'operatore somma (il `+`) tra due oggetti di questa classe. Iniziamo quindi dichiarando un header ed il relativo sorgente.

```cpp
// geometria.h
#ifndef GEOMETRIA_H
#define GEOMETRIA_H
namespace Geometria {
	class Vettore;
}

class Geometria::Vettore {
private:
	double modulo;
	double angolo;
public:
	Vettore();
	Vettore(double modulo, double angolo);
	void setModulo(double modulo);
	void setAngolo(double angolo);
	double getModulo();
	double getAngolo();
	Vettore operator+(const Vettore& op);
};
#endif // !GEOMETRIA_H
```

```cpp
// geometria.cpp
#include "geometria.h";
#include <cmath>

using namespace Geometria;

Vettore::Vettore() {
	setModulo(0);
	setAngolo(0);
}

Vettore::Vettore(double modulo, double angolo) {
	setModulo(modulo);
	setAngolo(angolo);
}

double Vettore::getModulo() {
	return this->modulo;
}

double Vettore::getAngolo() {
	return this->angolo;
}

void Vettore::setModulo(double modulo) {
	this->modulo = modulo;
}

void Vettore::setAngolo(double angolo) {
	this->angolo = angolo;
}

Vettore Vettore::operator+(const Vettore& op) {
	double res_angolo = abs(this->angolo - op.angolo);
	double norma = (this->modulo * this->modulo) + (op.modulo * op.modulo) - (2 * this->modulo * op.modulo * cos(this->angolo));
	return Vettore(sqrt(norma), (this->angolo + op.angolo)/2);
}
```

Proviamo ad invocare l'operatore somma usando la sintassi infissa:

```cpp
// main.cpp
Vettore v1(10.0, 60.0);
Vettore v2(5.0, 30.0);
Vettore v3 = v1 + v2;
```

Notiamo due cose:

1. l'uso di una variabile reference per indicare l'operando `op`;
2. il fatto che, nonostante si stia usando la notazione infissa, l'operazione chiamata dal compilatore è *comunque* `v1.operator+(v2)`.

Quest'ultimo aspetto ha, in particolare, importanti implicazioni, che vediamo di seguito.

### Operatori in overloading come funzioni esterne alla classe

Immaginiamo di voler semplicemente aggiungere un valore al modulo del vettore e, per qualche motivo, non voler usare la funzione `setModulo()`. L'opzione potrebbe essere quella di creare un altro operatore in overload:

```cpp
// geometria.h
Vettore operator+(double modulo);
// geometria.cpp
Vettore operator+(double modulo) {
	return Vettore(this->modulo + modulo, this->angolo);
}
```

Provando a verificare la commutatività dell'operatore precedente, noteremo un errore a runtime:

```cpp
Vettore v1(10.0, 60.0);
Vettore v2 = v1 + 5; 				// Ok
Vettore v3 = 5 + v1; 				// Errore
```

Per capire da dove deriva l'errore, dobbiamo ricordarci che gli operatori in overload come membri della classe sono considerati come funzioni chiamate su un'istanza della classe tipo `a.operatorX(b)`. Nel primo caso, quindi, andrà tutto bene, perché il compilatore starà chiamando una funzione del tipo `v1.operator+(5)`, mentre nel secondo caso starà chiamando una funzione del tipo `5.operator+(v1)`, che ovviamente non è definita!

E' quindi necessario dichiarare queste funzioni *esternamente* alla classe, in maniera tale che il loro funzionamento sia interpretato in questa maniera:

```cpp
// L'operatore binario X_bin passa da...
a X_bin b;
// ...ad...
operatorX_bin(a, b);
// L'operatore unario X_un passa da... 
X_un a;
// ...ad...
operatorX_un(a);
```

Per farlo, possiamo usare due diversi approcci.

#### Overload multipli

Il primo, e più semplice, è utilizzare due overload, uno per ogni possibile commutazione degli operatori. Il codice diventerebbe quindi:

```cpp
// geometria.h
Vettore operator+(Vettore& right, double left);
Vettore operator+(double right, Vettore& left);
// geometria.cpp
Vettore Geometria::operator+(Vettore& right, double left)
{
	return Vettore(right.getModulo() + left, right.getAngolo());
}
Vettore Geometria::operator+(double right, Vettore& left)
{
	return Vettore(left.getModulo() + right, left.getAngolo());
}
```

Il problema principale è che stiamo duplicando gli overload per ogni operatore, con tutto quello che ne consegue. Un modo più "elegante" di procedere è usare un apposito costruttore, che accetti soltanto il valore del modulo:

```cpp
// geometria.h
Vettore::Vettore(double modulo);
Vettore operator+(Vettore& right, Vettore& left);
// geometria.cpp
Vettore::Vettore(double modulo) {
	setModulo(modulo);
	setAngolo(0);
}
Vettore operator+(Vettore& right, Vettore& left) {
	return Vettore(right.getModulo() + left.getModulo());
}
```

!!!note "Nota"
	Una ulteriore "rifinitura" potrebbe essere quella di modificare l'argomento `angolo` del costruttore di `Vettore` in maniera tale che esso, di default, sia pari a 0.

### Overloading degli operatori di inserimento ed estrazione da flusso

Possiamo anche ridefinire gli operatori di inserimento ed estrazione da uno stream (rispettivamente `<<` e `>>`), in maniera tale da ottenere una modalità di visualizzazione ed acquisizione dati predefinita per gli oggetti della nostra classe. Ad esempio:

```cpp
// geometria.h
ostream& operator<<(ostream& output, Vettore& v);
istream& operator>>(istream& input, Vettore& v);

// geometria.cpp
ostream& Geometria::operator<<(ostream& output, Vettore& vettore)
{
	cout << "Modulo: " << vettore.getModulo() << " Angolo: " << vettore.getAngolo();
	return output;
}
istream& Geometria::operator>>(istream& input, Vettore& vettore)
{
	double modulo;
	double angolo;
	input >> modulo >> angolo;
	vettore.setModulo(modulo);
	vettore.setAngolo(angolo);
	return input;
}
```

Provando ad invocarli, otterremo:

```shell
# rappresentazione
Modulo: 15 Angolo: 60
# acquisizione
Inserire modulo ed angolo per il nuovo vettore:
# atteso input utente
```

## Allocazione dinamica delle risorse

Abbiamo visto come il sistema operativo si occupa di assegnare una determinata area di memoria ad ogni variabile e funzione. Senza scomodare i concetti relativi alle architetture di von Neumann ed Harvard, però, possiamo dire che le aree di memoria più importanti per i nostri scopi sono due: lo *stack* e lo *heap*.

Lo *stack* è organizzato come una pila, i cui elementi sono accessibili con politica LIFO; normalmente, le variabili sono memorizzate nello stack per l'intera durata del loro ambito di visibilità. Quindi, in un programma come il seguente, avremo un comportamento del tipo:

```cpp
int main()
{
	int a = 0; 				// stack: {a}
	{
		int b = a++; 		// stack: {b} {a}
	} 						// stack: {a}
	return 0;
}
```

Questo tipo di variabili è detto *automatica*: l'allocazione e la deallocazione della memoria è quindi gestita automaticamente dal compilatore.

Lo stack risulta essere molto efficiente; tuttavia, dispone di uno spazio limitato, per cui spesso si ricorre allo heap, per gestire il quale è necessario usare i puntatori, in modo da allocare o deallocare le corrispondenti aree di memoria. Per cui la sintassi generica che viene utilizzata prevede l'uso delle parole chiave `new` e `delete`. Ad esempio:

```cpp
int main()
{
	int * puntatore;		// Dichiaro un puntatore
	puntatore = new int;	// Alloco memoria nello heap il puntatore con l'operatore new
	delete p;				// Dealloco la memoria riservata al puntatore mediante l'operatore delete
	return 0;
}
```
