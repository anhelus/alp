# Le classi (parte due)

## Copiare un oggetto

Copiare un oggetto di un tipo non primitivo non è un'operazione così semplice come copiarne uno di tipo primitivo. Di solito, infatti, per copiare un valore basta usare l'operatore di assegnamento; le classi, invece, necessitano della definizione di un apposito **costruttore di copia**, il quale condivide buona parte delle caratteristiche di un costruttore ordinario, a meno di due caratteristiche:

1. il primo dei parametri (obbligatorio) è una reference ad un'istanza della classe;
2. la presenza di eventuali parametri aggiuntivi è opzionale.

Vediamo un esempio di costruttore di copia per le classi PersonaBase e Vettore:

```cpp
// persona.h
PersonaBase(const Persona& other);
// persona.cpp
Persona::PersonaBase(const PersonaBase& other)
{
	setNome(other.)
	nome = other.getNome();
	cognome = other.getCognome();
	eta = other.getEta();
}
// vettore.h
Vettore(const Vettore& altro);
// vettore.cpp
Vettore::Vettore(const Vettore& altro)
{
	setModulo(altro.modulo);
	setAngolo(altro.angolo);
}
```

E' importante sottolineare la presenza della parola chiave `const`. I motivi possono essere molteplici; i più semplici hanno a che fare con il fatto che non ha molto senso modificare l'oggetto copiato, o anche che vogliamo essere in grado di copiare oggetti dichiarati come costanti; per i più complessi, invece, possiamo rifarci ad un interessante articolo di [Herb Sutter](https://herbsutter.com/2008/01/01/gotw-88-a-candidate-for-the-most-important-const/).

### Shallow copy e deep copy

E' importante sottolineare come i due costruttori di copia che abbiamo specificato non siano differenti da quelli generati in maniera automatica dal compilatore; infatti, l'idea generale è quella di effettuare una copia *membro a membro*, usando una tecnica chiamata *shallow copy* (copia superficiale).

La shallow copy non può però essere usata nel caso la classe contenga attributi come puntatori o reference. Infatti, in questo caso, creeremmo un legame tra le due istanze, in quanto una modifica all'attributo puntato dalla variabile copiata si ripercuterebbe sullo stesso attributo della variabile risultato della copia, e viceversa. Di conseguenza, in questi casi si utilizza una tecnica chiamata *deep copy*. Nel caso fosse presente il solito puntatore alla nostra età:

```cpp
class Vettore {
	// ...
	private:
		double *puntatoreModulo;
}

Vettore(const Vettore& altro)
{
	// shallow copy
	modulo = altro.modulo;
	angolo = altro.angolo;
	// deep copy
	puntatoreModulo = new double;
	if (altro.puntatoreModulo != nullptr) {
		*puntatoreModulo = *(altro.puntatoreModulo);
	}
}
```

La deep copy prevede quindi due step:

1. nel primo step, viene allocata memoria per l'attributo da copiare;
2. nel secondo step, viene copiato nella memoria allocata il valore puntato dall'oggetto da copiare.

### Operatore di assegnazione di copia

La copia di un oggetto deve tener conto, oltre che del costruttore, anche dell'operatore di assegnazione, ovvero `=`, che entra in gioco ogni volta che ad un oggetto viene assegnato un valore successivamente alla sua inizializzazione, come in questo caso:

```cpp
PersonaBase piero("piero", "scamarcio", 18);
PersonaBase tizio("una", "persona", 22);
tizio = piero;

Vettore v1(10.0, 45.0);
Vettore v2(15.0, 60.0);
v2 = v1;
```

Per definirlo, possiamo sfruttare il concetto di overload di operatore. Ad esempio:

```cpp
// persona.h
PersonaBase& operator=(const PersonaBase& other);
// persona.cpp
PersonaBase& operator=(const PersonaBase& other) {
	nome = other.getNome();
	cognome = other.getCognome();
	eta = other.getEta();
	return *this;
}

// geometria.h
Vettore& operator=(const Vettore& altro);
// geometria.cpp
Vettore& operator=(const Vettore& altro) {
	modulo = altro.modulo;
	angolo = altro.angolo;
	return *this;
}
```

Notiamo la presenza di numerose analogie con il costruttore di copia, tra cui firma, sintassi e generazione automatica da parte del compilatore. L'unica differenza tangibile sta nel fatto che l'operatore di assegnazione restituisce il valore puntato dal puntatore `this`, ovvero l'istanza che abbiamo appena definito.

## Allocazione dinamica di nuovi oggetti

In precedenza abbiamo visto come utilizzare costruttori e distruttori per inizializzare nuove istanze di una classe. Questo tipo di inizializzazione è però statica; è possibile definire un'allocazione dinamica degli oggetti utilizzando appositamente i puntatori e le keyword `new` e `delete`. Ad esempio:

```cpp
// main.cpp
PersonaBase *pb = new PersonaBase("Piero", "Scamarcio", 21);
delete pb;

Vettore *v = new Vettore(10.0, 45.0);
//...
delete v;
```

Notiamo come l'inizializzazione dinamica della variabile preveda che alla keyword `new` segua uno dei costruttori in overload, assieme ad una lista di argomenti contenuti tra parentesi tonde.

Per accedere ai membri ed alle funzioni dell'oggetto istanziato dinamicamente, dovremo usare l'operatore freccia `->`, come avevamo già visto quando abbiamo parlato delle `struct`

Quindi:

```cpp
pb->setNome("Pietro");
```
