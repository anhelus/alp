# 10 - Strutture dati

Nella [lezione precedente](../09_functions/lecture.md) abbiamo ad un certo punto parlato di "insieme" dei voti relativi ai nostri esami, senza però ben specificare come rappresentarlo con i concetti a nostra disposizione. Se ci pensiamo, infatti, non abbiamo (apparentemente) strumenti per rappresentare degli insiemi: non possiamo certamente utilizzare un singolo dato numerico, così come neanche un dato booleano o un carattere.

Per risolvere questo problema (e, in realtà, mille altri) dobbiamo utilizzare una serie di concetti che vanno sotto il nome collettivo di *strutture dati*, ovvero dei costrutti progettati per organizzare e gestire un insieme di valori nella maniera più efficiente possibile.

Esistono diversi tipi di struttura dati, ognuno dei quali adatto ad un determinato scopo. Vediamo quelli più diffusi.

## 10.1 - Array

La maniera più rapida di rappresentare i nostri voti è quella di immaginarli come un vettore di numeri interi; per far questo esiste una struttura dati apposita chiamata *array*.

Un array contiene quindi una sequenza di elementi, tipicamente dello stesso tipo (anche se, come vedremo, ciò dipende dal linguaggio di programmazione), ed organizzati seguendo un ordine specifico, "esplorabile" mediante il concetto di *indice*.

La presenza dell'indice permette di definire la modalità di accesso ai dati dell'array, indicata come *accesso diretto*. Nella pratica, possiamo estrarre qualsiasi elemento nell'array mediante l'indice stesso, in maniera diretta, senza dover "scorrere" l'intero vettore; questo fa sì che l'accesso abbia sempre una complessità $O(1)$, dato che è richiesta un'unica operazione.

!!!note "Nota"
	A far da contraltare all'efficienza in termini di accesso vi è una certa laboriosità legata all'inserimento o rimozione di un elemento dall'array.

Tipicamente, un array viene rappresentato come una serie di singole variabili racchiuse tra due parentesi quadre. Ad esempio:

```py
array = [8, 5, 12, 7, 4]
```

In particolare, il precedente array è composto da elementi di tipo intero, ed ha una lunghezza pari a cinque elementi. Da notare che nella maggior parte dei linguaggi di programmazione l'indice del primo elemento *non* è pari ad uno, ma a zero. La figura successiva esplicita adeguatamente questo concetto.

TODO: inserire figura array

## 10.2 - Liste

Una *lista*, conosciuta anche con il nome di *linked list*, è una struttura dati simile all'array, ma che consta di una differenza fondamentale. Nella lista, infatti, ogni elemento contiene un riferimento esplicito a quello successivo. Questo concetto è esplicitato nella seguente figura:

TODO: inserire figura lista

In particolare, osserviamo che:

- il primo elemento nella lista, il cui valore è `5`, ha un riferimento all'elemento successivo `R2`;
- il secondo elemento nella lista ha valore `3`, e conserva un riferimento all'elemento successivo `R2`;
- ciò prosegue sino all'elemento `7`, che conserva un riferimento all'ultimo elemento TODO: `R`.

Il fatto che ogni elemento della lista contenga un riferimento al successivo ha due conseguenze:

1. la prima consiste nel fatto che la lista è una struttura dati ad *accesso sequenziale*, il che significa che occorrerà "scorrere" tutti gli elementi della stessa fino ad arrivare a quello desiderato;
2. la seconda sta nel fatto che risulta essere molto più semplice aggiungere o rimuovere un elemento da una lista che da un array: infatti, basterà semplicemente modificare i riferimenti dagli elementi contigui a quello che si sta aggiungendo o rimuovendo.

## 10.3 - Struct

Una *struct* contiene un insieme di valori tipicamente chiamati *membri* o *campi*, il cui numero, sequenza e tipo sono tipicamente prefissati. Le struct trovano ampia applicazione in linguaggi come il C, ed hanno una sintassi di questo tipo:

```c
struct nome_struct {
	tipo_campo_uno id_campo_uno;
	tipo_campo_due id_campo_due;
};
```

Questa sintassi ci permette di definire quindi un tipo di struct chiamato `nome_struct` ed avente, in questo caso, due campi, ovvero un primo campo di tipo `tipo_campo_uno` ed identificatore `id_campo_uno`, ed un secondo campo di tipo `tipo_campo_due` ed identificatore `id_campo_due`.

## 10.4 - Union

Una *union* è un tipo di struttura dati che permette di specificare il tipo del valore che può essere memorizzato al suo interno tra un certo numero di tipi primitivi. Nonostante sia sintatticamente affine alla struct, ne differisce quindi dal punto di vista funzionale: non è una "struttura", ma piuttosto un "ventaglio di possibili tipi" da cui selezionare. La sintassi di una union è simile alla seguente:

```c
union nome_union {
	tipo_union_uno id_union_tipo_uno;
	tipo_union_due id_union_tipo_due;
};
```

In questo caso, la union di nome `nome_union` potrà assumere uno tra due possibili valori, ovvero `id_union_tipo_uno` di tipo `tipo_union_uno` o `id_union_tipo_due` di tipo `id_union_tipo_due`.

!!!note "Nota"
	Per adesso, non facciamo un esempio "concreto" di union; lo vedremo più avanti, quando ritorneremo su queste due strutture dati in C.

## 10.5 - Pile e code

Abbiamo visto in precedenza due tipi di accesso ai dati, ovvero quello *casuale*, proprio degli array, e quello *sequenziale*, proprio dell eliste. Esiste un altro tipo di accesso ai dati, chiamato *accesso limitato*, usato da specifiche strutture dati come *pile* e *code*. Vediamo brevemente entrambi questi tipi di struttura dati.

### 10.5.1 - Pile

Una *pila* (in inglese, *stack*) è una struttura dati che contiene al suo interno variabili inserite e/o rimosse seguendo il principio *Last-In, First-Out* (*LIFO*). In altre parole, ciò significa che l'ultimo elemento che accede ad una pila è anche il primo ad uscirne.

Una pila ha a disposizione quindi due diverse operazioni, ovvero quella di `push`, mediante la quale un oggetto viene inserito in cima allo stack, e quella di `pop`, che permette di estrarre l'oggetto dalla cima dello stesso.

Il funzionamento della pila è schematizzato all'interno della seguente figura.

TODO: figura funzionamento pila

!!!note "Nota"
	Il motivo alla base dell'aggettivo "limitato" è da ricercarsi proprio nel fatto che sia il push sia il pop possono essere effettuati soltanto sugli elementi in cima alla pila.

### 10.5.2 - Code

Una *coda* (in inglese, *queue*) è una struttura dati concettualmente simile alla pila, ma che segue il principio (*First-In, First-Out*) (*FIFO*); in questo caso, il primo ad uscire dalla coda sarà il primo ad esservi entrato.

Le operazioni definite sulla coda sono concettualmente simili a quelle definite sulla pila, e vengono chiamate `enqueue` (per mettere in coda un nuovo elemento) e `dequeue` (per togliere dalla coda l'elemento presente da più tempo).

Il funzionamento della coda è schematizzato all'interno della seguente figura.

TODO: figura funzionamento coda

#### TODO: questo va in avanzato Pila come array

Per implementare una pila sotto forma di array, abbiamo bisogno dei seguenti elementi:

1. un array di lunghezza superiore ad uno (`stack`);
2. una variabile che caratterizza l'elemento in cima all'array (`top`);
3. una variabile che si riferisce alla lunghezza dell'array (`capacity`).

Lo `stack` è pieno quando `top` è pari a `capacity - 1`; invece, è vuoto quando `top` è pari a `-1`. Questi principi sono riassunti nella figura successiva:

E' importante notare che possiamo avere due tipi di implementazione: una in cui la dimensione dell'array è fissa, ed una in cui la dimensione dell'array varia in maniera dinamica. Nella prima, ovviamente, quando il `top` è pari a `capacity` si genera un errore; ciò non avviene nel secondo caso.

L'operazione di `push` prevede quindi che sia inserito un nuovo elemento all'indice `top` dell'array; di converso, l'operazione di `pop` prevede che tale elemento sia rimosso. In etrambi i casi, è importante aggiornare il valore di `top`.

```
push(array, top, capacity, element)
STEP 1 -> top = top + 1;
STEP 2 -> if (top >= capacity)
		      return ERROR;
STEP 3 -> array[top] = element;
```

```
pop(array, top)
STEP 1 -> element = array[top];
STEP 2 -> top = top - 1;
STEP 3 -> return element;
```



#### TODO: questo va in avanzatoEsempio di implementazione come array

Nel caso volessimo implementare una coda come array, dovremmo definire almeno i metodi `enqueue` e `dequeue`.

In particolare, la procedura di `enqueue` prevede che sia posto come primo membro dell'array proprio l'elemento che si vuole aggiungere. Per farlo, potremmo ad esempio salvare l'array in una variabile temporanea, e concatenarlo all'elemento che entra in coda.

```
enqueue(array, element)
STEP 1 -> temp_array = array;
STEP 2 -> new_array = concatenate(element, temp_array);
STEP 3 -> return new_array;
```

La procedura di `dequeue` di converso comporta la semplice rimozione dell'ultimo elemento nell'array.

```
dequeue(array)
STEP 1 -> element = array[length(array) - 1]
STEP 2 -> new_array = remove_last(array)
STEP 3 -> return new_array, element
```

## Grafi

Ecco un modo per rappresentare una rete sociale:

![social_network](../../assets/images/04_programmazione/06_strutture_dati/social_network.png)

Le linee presenti tra i nomi di due persone indicano che queste si conoscono tra loro. Ovviamente, la conoscenza è _bidirezionale_: dato che Alice conosce Bob, anche Bob conosce Alice.

Questo modo di schematizzare una rete sociale è conosciuto come _grafo_.

### Vertici ed archi

Ciascun nodo è noto come _vertice_, mentre ogni linea è un _arco_ che connette due vertici.

L'insieme dei vertici è dato da $V$, mentre quello degli archi è dato da $E$. Il grafo è quindi rappresentabile come una coppia $G=(V,E)$.

Anche i nodi possono essere rappresentati a coppie: in particolare, due nodi $u$ e $v$ connessi da un arco sono una coppia $(u, v)$.

### Grafo non diretto

Abbiamo detto che le relazioni rappresentate nella nostra rete sociale sono bidirezionali: ciò significa che non è possibile individuare una "direzione" specifica nella relazione. Siamo quindi in presenza di un _grafo non diretto_.

In un grafo non diretto, un arco $(u, v)$ equivale all'arco $(v, u)$. Ciascun arco incide su entrambi i vertici, ed i vertici connessi da un arco sono _adiacenti_ o _vicini_. Definiamo inoltre il numero di archi che incide su un vertice come _grado_ dello stesso.

### Cammini e cicli

Immaginiamo che Bob voglia conoscere Eric. non vi è un arco che li collega; però, Bob potrebbe chiedere ad Alice di presentargli David, che a sua volta potrebbe presentargli Eric. Esiste quindi un **percorso**, o **cammino**, composto da tre archi tra Bob ed Eric, e rappresenta il modo più diretto per i due per incontrarsi. Chiamiamo un percorso del genere (ovvero il percorso con un numero minimo di archi) **cammino minimo**, o **shortest path**.

Un cammino che ha come punto di partenza e di arrivo lo stesso vertice è chiamato **ciclo**. Ad esempio, quello che va da Alice, passa per David, Eric e Charlie, e torna ad Alice, è appunto un ciclo.

### Grafo pesato

Alle volte, gli archi sono **pesati**, ovvero correlati da valori numerici. Ad esempio, potremmo rappresentare la distanza tra diverse città come segue:

![cities](../../assets/images/04_programmazione/06_strutture_dati/cities_map.png)

Il termine generale per ognuno dei numeri che mettiamo su un lato è **peso**, ed un grafo i cui archi hanno dei pesi è un **grafo pesato**. In questo caso, volendo trovare il percorso minimo tra due posizioni, dovremo tenere contro del valore dei pesi. Ad esempio, per Andare da Bari a Napoli, occorrerà, nel nostro caso, passare da Roma e Milano (piuttosto che da Torino).

!!! note "Nota"
Il Docente si scusa per questa interpretazione poco realistica. Non seguite questa mappa, e risparmierete molte ore.

### Grafo diretto

Cosa accade se inseriamo informazioni inerenti i sensi di marcia all'interno del grafo precedente? Otteniamo un **grafo diretto**.

![cities_directed](../../assets/images/04_programmazione/06_strutture_dati/cities_map_directed.png)

Le direzioni degli archi mostrano quali percorsi possono essere affrontati, e quali no. In questo caso, ad esempio, non potremo uscire da Bari, in quanto non ci saranno archi uscenti. Roma invece perde il suo status, in quanto si dimostra che _non tutte le strade portano a Roma_.

Possiamo fare altre due osservazioni su questo grafo:

- il grafo non ha alcun ciclo, per cui siamo in presenza di un **grafo aciclico diretto**;
- il grafo conserva i pesi, per cui siamo comunque in presenza di un grafo pesato.

Per quello che riguarda infine il grado di ogni arco, abbiamo due termini da tenere in considerazione:

- il **grado esterno**, o **out-degree**, è il numero di archi in uscita da un vertice;
- il **grado interno**, o **in-degree**, è il numero di archi in ingresso in un vertice.

## Alberi

Un **albero** è una struttura dati, particolarmente usata in ambito informatico, che simula una struttura gerarchica, con un valore radice ed una serie di figli, rappresentata sotto forma di grafo **non orientato**, **connesso** ed **aciclico**.

In particolare, il fatto che l'albero sia connesso indica che esiste _almeno un cammino che connette tutti gli archi_.

![tree](../../assets/images/04_programmazione/06_strutture_dati/tree.png)

Un particolare tipo di albero è poi l'**albero binario**, nel quale ciascun nodo ha (al più) due figli.

Un nodo terminale (ovvero uno in basso nella gerarchia) è chiamato **foglia**.
