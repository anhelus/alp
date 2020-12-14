## This

Il linguaggio C++ include la parola riservata this, il cui uso è confinato all'ambuto della definizione dei metodi di una classe.

In quest'ottica, this indica un puntatore speciale che contiene l'indirizzo dell'istanza della classe che ha invocato il meotodo.

L'inizializzatore avviene in automatico da parte del compilatore, e viene passato come parametro implicito ad ogni funzione membro (ad eccezione, come vedremo, dei metodi statici).

Il tipo del puntatore this è quello di puntatore alla classe. Ad esempio, il tipo del puntatore this nel contesto della classe `PersonaBase` è `PersonaBase*`.

Vedremo che ha un ruolo fondamentale nella definizione di alcuni meotdi speciali, come gli operatori di assegnamento, in quanto viene usato esplicitamente per la restituzione del valore di ritorno.

Viene inoltre usato in maniera implicita ogni qual volta si faccia riferimento ad un dato membro di una classe all'interno di un metodo non statico. Ad esempio, potremmo modificare il codice dei nostri setter come segue:

```cpp
void setNome(string nome) {
	this->nome = nome;
}
```

In questo modo possiamo usare this per referenziare un membro di classe il cui nome è oscurato da quello di un argomento omoniomo.

Quando il puntatore this è usato come parametro implciito di metodi const, ad esso viene applicato il qualificatore const, garantendo che nell'ambto di questo metodo tutti i membri della classe siano non modificabili.

L'uso di this è opzionale e demandato al compilatgore.

This è un membro di classe a tutti gli effetti, e può essere soggetto ad ereditarietà.

## Overloading degli operatori

A livello implementativo, gli operatori sono funzioni a tutti gli effetti, il cui nome assume la forma operator@, dove con @intendiamo uno qualsiasi tra gli operatori che abbimo discusso in precedenza anche parlando del C. Inoltre, come funzioni, sono caratterizzati dal tipo del valore restituito, numero di argomenti ed ordine.

Il linguaggio C++ permette di "ridefinire" gli operatori, in modo che siano applicabili anche ai tipi definiti dall'utente,.

Questo proceso, detto overloading degli operatori, implica la capacità da parte del compilatore di tradurre una o più istruzioni dalla notazione infissas (DESCRIVERE) alla sintassi di invocazione delle funzioni.

L'overloading di operatori necessita quindi di pratiche di buona programmazione per mantenere fattori quali simmetria e commutatività degli operatori.

Il problema principale consiste nella definizione dell'ambito di visibilitaà per gli operatori sovraccaricati. Alcuni infatti possono essere sovraccaricati solo come mebri di classe, perché per la loro implementazione è richiesto lk'uso di this, m altri solo come funzioni esternel alla classe, altri ancora indifferentemnete; tuttavia, anche in quest'ultimo caso, la scelta può avre ripercussioni inattesse.

### Overloading degli oeperatori come membri di classe

L'overloading di un operatore come mebro di classe traduce la sua invocazione come segue:

```cpp
// Operatori binari (es. OP)
a OP b;
// diventa...
a.operatorOP(b);
// Unari:
OPa;
a.operatorOP();
```

Notiamo quindi che a OP b e b OP a hanno in questo caso una semantica differente *non solo èper le operazioni non commutative, ma anche per quelle commutative!*

Immaginiamo, ad esempio, di avere una classe `Quadrato`, e di voler implementare l'operatore `+` tra due oggetti di tipo quadrato in modo che il risultato dell'operazione restituisca la somma delle aree.

TODO: FARE ESEMPIO, ALTRI TIPI DI OVERLOADING
