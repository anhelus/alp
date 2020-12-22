# Container

I *container* sono uno tra i costrutti più utilizzati nel C++. Non ne esiste un unico esempio; piuttosto, sono una serie di strutture dati che si prestano alla gestione di insiemi, o *collezioni*, di dati, offrendo funzionalità semplificate per *inserimento*, *estrazione* e *cancellazione*.

Esistono container per praticamente ogni struttura dati che abbiamo visto finora, partendo dagli array, passando per le liste, fino ad arrivare a strutture più complesse come le hashmap.

!!!note "Nota"
	I container sono un esempio di **template** C++. Questo si traduce nel fatto che possono essere usati per memorizzare elementi di tipo arbitrario, a patto che questo tipo esista e sia specificato a priori.

## Tipi un container

I container più utilizzati sono contenuti nella [Standard Template Library](https://en.wikipedia.org/wiki/Standard_Template_Library), e ne esistono tre tipi, a seconda del caso d'uso cui si riferiscono.

### Sequence container

Questo tipo di container agisce su delle sequenze di dati, ordinandoli, inserendoli ed estraendoli in base agli indirizzi di memoria degli elementi contenuti nel container. E' importante sottolineare che questo tipo di container assicura un accesso *sequenziale* ai dati contenuti.

I sequence container della STL sono:

* `array`, riconducibile al classico concetto di array visto finora, ovvero di vettore (non ridimensionabile);
* `vector`, che possiamo immaginare una versione "migliorata" dell'array, implementante tecniche di accesso casuale e ridimensionabile a seguito dell'aggiunta di elementi;
* `deque`, implementa una coda doppia;
* `list`, che implementa una **doubly linked list**, ovvero una linked list che incorpora un riferimento sia all'elemento precedente sia a quello successivo;
* `forward_list`, che implementa una linked list standard.

### Associative container

I container associativi permettono di implementare delle strutture dati chiamate **array associativi**, conosciuti anche come **dizionari**.

Come suggerisce il nome stesso, un dizionario è una struttura dati estremamente utile per accedere al **valore** dei dati conoscendone la **chiave**. Pensiamo, ad esempio, ad un classico dizionario: per risalire al significato di una qualsiasi parola (il valore ricercato), basterà conoscere la parola stessa (la chiave). Questo tipo di struttura è molto utilizzato soprattutto in linguaggi come Python e JavaScript, nei quali è direttamente associato alla definizione di oggetto.

La STL offre quattro tipi di associative container:

* `set` viene usato nei casi in cui è necessario memorizzare soltanto un valore, ovvero la chiave;
* `map` viene usato nei casi in cui è necessario memorizzare una coppia di valori, ovvero la classica coppia chiave/valore;
* `multiset` è una variante di `set` usata qualora ci siano delle chiavi ripetute;
* `multimap` è una variante di `map` usata qualora ci siano coppie chiave-valore ripetute.

E' importante notare che i container associativi seguono il concetto di **strict weak ordering**, che dice che:

1. $\forall(a, b)$, se $\ a \leq b$ allora $\ b \leq a$ non è valida, e viceversa;
2. se $a \leq b$ e $b \leq a$, allora $a \sim b$;
3. se $a \leq b$, e $b \leq c$, allora $a \leq c$;
4. se $a \sim b$, e $b \sim c$, allora $a \sim c$;
5. se $a \leq b$, e $a \not\sim b$, allora $a$ *precede* $b$, ovvero $a < b$.

!!!note "Nota clarificatrice"
	In buona sostanza, i container associativi sono ordinati.

### Unordered associative container

I container associativi non ordinati hanno delle applicazioni molto simili a quelle dei container associativi, ma non ordinano gli elementi memorizzati. Ve ne sono quattro tipi, del tutto equivalenti alle loro controparti ordinate, ovvero `hash_set`, `hash_map`, `hash_multimap` ed `hash_multiset`.

!!!note "Container associativi ordinati vs. non ordinati"
	Apparentemente, sembrerebbe che non ci sia un motivo valido per preferire un container non ordinato, diciamo una `hash_map`, al suo equivalente ordinato. Dobbiamo però considerare il motivo per cui una `hash_map` non memorizza i dati in maniera ordinata: questo, infatti, avviene a causa del fatto che ne memorizza una rappresentazione *compressa*, chiamata **hash**. La scelta tra i due tipi dipende dalle performance richieste: una `hash_map` offre vantaggi in termini di performance, ma la `map` ha delle caratteristiche utili in caso di necessità di iterazione ordinata degli elementi, come ad esempio in certi algoritmi su grafi.

## Un esempio

Vediamo un semplice esempio di definizione di un container di tipo `vector` su elementi interi.

```cpp
// main.cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vettore = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "Itero usando la un valore massimo predefinito." << endl;
	for (int i=0; i<10; i++)
	{
		cout << vettore[i] << endl;
	}
	
	cout << "Itero usando la funzione size." << endl;
	
	for (int i=0; i<v.size(); i++)
	{
		cout << persone[i].getNome() << persone[i].getCognome() << endl;
	}
	
	return 0;
}
```

## Iteratori

Un *iteratore* è un'entità preposta alla scansione degli elementi di un container. Ovviamente, il vantaggio dell'utilizzo di un iterator sta nel fatto che il programmatore non è più vincolato alla conoscenza dettagliata delle caratteristiche dello specifico container (uno tra tutti, la dimensione), ma può piuttosto *generalizzare* i metodi definiti.

Vediamo come si usano. Immaginiamo di partire da un normale array, acceduto con un classico ciclo `for`:

```cpp
int[10] vettore = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
for (int i = 0; i < 10; i++)
{
	cout << vettore[i] << endl;
}
```

Abbiamo visto che usare un container come `vector` permette di astrarci dalla dimensione fissa dell'array:

```cpp
vector<int> vettore = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
for (int i = 0; i < vettore.size(); i++)
{
	cout << vettore[i] << endl;
}
```

Un iterator si usa in modo molto simile: infatti, viene definito sul container di interesse, associato ad un elemento da cui inizia ad iterare, e prosegue fino al verificarsi di una condizione di arresto. Ad esempio:

```cpp
vector<int> vettore = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
for (vector<int>::iterator it = vettore.begin(); it != vettore.end(); it)
{
	cout << *it << endl;
}
```

Notiamo come l'iterator `it` venga inizializzato sulla prima posizione del container `vettore` grazie al metodo `begin()`, mentre la condizione di terminazione si verifica quando l'iteratore si trova alla fine del container (metodo `end()`); **non facciamo in alcun modo riferimento al numero di elementi contenuti nel container**. Quest'ultima considerazione è critica soprattutto quando abbiamo a che fare con container associativi, in quanto è *estremamente* più comodo usare un iteratore per accedere sequenzialmente agli elementi contenuti. Notiamo infine come l'iteratore in realtà punti all'area di memoria del singolo elemento, e supporti l'operazione di incremento (`it++`); ovviamente, tale incremento fa sì che si passi all'elemento successivo del container.

!!!note "La potenza delle interfacce"
	La STL è dotata di un'interfaccia quanto più omogenea, per cui è possibile usare questi stessi metodi sulla maggior parte dei container disponibili. Ad esempio, potremo replicare questo codice "as is" passando da `vector` a `list` (passare a container associativi richiede qualche ulteriore modifica).

!!!note "La potenza delle interfacce - parte 2"
	Se invece volessimo adattare il codice che sfrutta un approccio più "classico", senza iteratori per capirci, all'accesso ai membri di una lista, dovremmo innanzitutto considerare due criticità: in primis, le liste non supportano l'operatore `[]` per l'accesso diretto, e poi il metodo `size()` risulta essere più oneroso rispetto all'omonimo sul `vector`, in quanto nel primo caso occorre fare una scansione sequenziale preliminare dell'intera lista, mentre nel secondo basta conoscere la dimensione in memoria ed il tipo del vettore.
