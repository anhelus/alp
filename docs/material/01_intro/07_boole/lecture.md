# 4 - Algebra booleana

[Abbiamo già detto](../01_intro_inf.md) che gli elaboratori si basano sui *circuiti elettronici digitali* che, ad *alto livello*, possono essere visti come un insieme più o meno complesso di *interruttori*, proprio come quelli che possiamo trovare in un normalissimo impianto elettrico.

Per capirci meglio, pensiamo agli interruttori presenti nelle nostre case: questi sono caratterizzati esclusivamente da due stati di funzionamento, ovvero *aperto* e *chiuso*. Nello stato di funzionamento *aperto*, il circuito viene "interrotto", rendendo impossibile il passaggio della corrente; ciò, di conseguenza, impedisce che le lampadine nella stanza si accendano. Nello stato di funzionamento *chiuso*, invece, la corrente scorre normalmente nel circuito, illuminando le lampadine presenti nella stanza.

!!!tip "Interruttori e resistenza"
    I più esperti noteranno che il circuito aperto ha *resistenza infinita*, il che significa che la corrente che scorre è nulla. Invece, il circuito chiuso ha *resistenza nulla*, il che significa che la corrente che scorre è massima (non infinita).

Sfruttando il funzionamento base dei circuiti, è possibile modellare delle situazioni più o meno complesse. Facciamo un semplice esempio nel mondo reale: immaginiamo due stanze adiancenti, ciascuna dotata di una porta dalla quale è possibile dedurre se la luce sia o meno accesa all'interno della singola stanza. Ponendoci come osservatori esterni, potremo trovarci in una tra le seguenti casistiche:

* *caso 1*: entrambe le luci sono accese, per cui è plausibile che ci siano due persone, una in ciascuna stanza;
* *caso 2*: entrambe le luci sono spente, per cui è plausibile che non ci sia nessuno;
* *caso 3*: una luce è accesa, per cui è plausibile che ci sia una persona nella stanza illuminata.

Se ponessimo quindi la domanda *c'è qualcuno in casa*, potremmo rispondere in maniera *affermativa* nel caso 1 (c'è una persona nella prima stanza, ed una persona nella seconda) e nel caso 3 (c'è una persona nella prima stanza o nella seconda stanza), ed in maniera *negativa* nel caso 2. Immaginiamo di estendere questo scenario ad una casa a più stanze: è facile comprendere come, combinando delle semplici informazioni di tipo binario, si riesca a modellare uno scenario arbitrariamente complesso.

!!!note "Interpretazione del risultato ottenuto"
    Notiamo come l'osservazione dello stato di accensione delle luci non ci permetta di definire con certezza *quante* persone ci sono in casa, ma soltanto che *c'è qualcuno in casa*. In altri termini, non possiamo dare una risposta *quantitativa*, ma soltanto una *binaria*.

A questo punto è lecito farsi una domanda: esiste un modo *formale* per determinare se è presente una persona in casa a partire dalle precedenti considerazioni partendo da una serie di regole ben definite? Prevedibilmente, la risposta a questa domanda è affermativa, ed è definita grazie alle regole introdotte dall'*algebra di Boole*.



## 4.2 - L'algebra di Boole

L'algebra di Boole venne introdotta nel XIX secolo da Boole per analizzare algebricamente problemi di calcolo proposizionale, al fine di studiare le leggi del pensiero.

L'algebra di Boole è fondata su un insieme di teoremi e regole che goveranon le operazioni logiche e che ne consentono una rappresentazione matematica.

Sull'algebra di Boole si basa l'elettronica digitale ed il suo sviluppo.

L'algebra di Boole contempla due costanti 0 e 1, rispettivamente falso e vero. I due stati sono mutualmente esclusivi: ciò significa che si escludono a vicenda.

In pratica, possono descrivere lo stato di apertura (0) o chiusura di un generico contatto, o di un circuito a più contatti.

Sui valori booleani si definiscono diverse operazioni, tra cui le più importanti sono AND, OR, NOT e XOR.

Le operazioni AND ed OR sono di tipo binario, assieme alla XOR, mentre l'operazione NOT è unaria.

Nella valutazione delle espressioni booleane esiste una relazione di precedenza tra gli oepratori NOT, AND e OR, nell'ordine in cui sono stati elencati.

Gli operatori dell'algebra booleana possono essere rappresentati in vari modi.

Spesso sono descritti semplicemente come AND, OR e NOT. Nella descrizione dei circuiti appaiono sotto forma di porte logiche. In matematica si usa + per OR e x per AND, mentre si rappresenta il NOT con una barra posta sopra l'espressione che viene negata.

### 4.2.1 - L'operazione di AND

L'operazione di $AND$ è definita anche come *prodotto logico*. In particolare, il valore del prodotto logico è pari al simbolo $1$ se e solo se il valore di entrambi gli operandi coinvolti è pari ad $1$.

| A | B | $\times$ |
| - | - | -------- |
| $0$ | $0$ | $0$ |
| $0$ | $1$ | $0$ |
| $1$ | $0$ | $0$ |
| $1$ | $1$ | $1$ |

![and_port](./images/and_port.png)

### 4.2.2 - L'operazione di OR

L'operazione $OR$ è anche definita come *somma logica*.

In particolare, il valore della somma logica è il simbolo $1$ se e solo se almeno uno dei due operandi ha valore $1$.

| A | B | $+$ |
| - | - | -------- |
| $0$ | $0$ | $0$ |
| $0$ | $1$ | $1$ |
| $1$ | $0$ | $1$ |
| $1$ | $1$ | $1$ |

![or_port](./images/or_port.png)

### 4.2.3 - L'operazione NOT

L'operazione $NOT$ è definita come *negazione logica*.

In particolare, l'operatore inverte il valore della costante su cui opera.

| A | $\hat{A}$ |
| - | - |
| $0$ | $0$ |
| $0$ | $1$ |
| $1$ | $0$ |
| $1$ | $1$ |
