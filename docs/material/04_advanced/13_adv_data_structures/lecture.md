# 13 - Ancora sulle strutture dati

## 13.1 - Pila come array

### 13.1.1 - Variabili da utilizzare

Proviamo adesso ad implementare una pila utilizzando un array. Per farlo, avremo bisogno di tre elementi:

1. un array, che chiameremo `stack`;
2. una variabile che indica l'elemento in cima allo `stack`, che chiameremo `top`;
3. una variabile che indica la lunghezza dello `stack`, che chiameremo `capacity`.

Da qui consegue che:

* lo `stack` è pieno quando `top` è pari a `capacity`;
* lo `stack` è vuoto quando `top` è pari a `0`.

Questi principi sono riassunti nella figura successiva:

TODO: figura da dispense

### 13.1.2 - Operazioni di `push` e `pop`

Ricordiamo che lo stack segue una strategia LIFO, per cui una `push` prevede che sia inserito un nuovo elemento nella parte superiore dell'array (ovvero, all'indice `top`). Quindi:

```linenums="1"
push(stack, top, capacity, element):

STEP 1 -> top = top + 1;
STEP 2 -> if (top >= capacity)
		      return ERROR;
STEP 3 -> stack[top] = element;
```

Ciò implica che:

* allo `STEP 1` viene aumentato il valore attuale di `top`;
* allo `STEP 2` viene verificato che `top` non sia superiore a `capacity`, e che quindi la pila non sia già piena;
* allo `STEP 3` l'elemento `element` viene inserito al posto `top` dello `stack`.

L'operazione di `pop` invece prevede che l'elemento al vertice dello stack sia rimosso:

```linenums="1"
pop(stack, top)

STEP 1 -> if (top <= 0):
			  return ERROR;
STEP 2 -> element = stack[top];
STEP 3 -> top = top - 1;
STEP 4 -> return element;
```

Ciò implica che:

* allo `STEP 1` si verifica che lo `stack` non sia vuoto;
* allo `STEP 2` viene assegnato ad `element` il valore presente al `top` dello `stack`;
* allo `STEP 3` il valore di `top` viene ridotto di uno;
* allo `STEP 4` viene restituito il valore estratto dallo `stack`.

## 13.2 - Coda come array

### 13.2.1 - Variabili da utilizzare

Anche in questo caso dovremo usare tre diversi elementi:

1. un array, che chiameremo `queue`;
2. una variabile che indica l'elemento da più tempo in coda, chiamata `first`;
3. una variabile che indica la lunghezza della `queue`, che chiameremo `capacity`.

### 13.2.2 - Operazioni di enqueue e dequeue

Ricordiamo che la strategia seguita da una coda è di tipo FIFO, per cui dovremo definire i metodi `enqueue` e `dequeue`.

In particolare, il metodo `enqueue` prevede che al primo posto nell'array sia inserito l'elemento che si vuole aggiungere.

```
enqueue(array, element)

STEP 1 -> if (index[first] equals capacity):
			  return ERROR;
STEP 2 -> for current_element in queue:
			  queue[current_element + 1] = queue[current_element];
			  reset queue[0]
STEP 3 -> queue[0] = element;
```

In pratica:

* allo `STEP 1`, controlliamo che la `queue` non sia già satura. Per far ciò, verifichiamo che l'indice di `first` non sia uguale a `capacity`;
* allo `STEP 2`, muoviamo tutti gli elementi presenti nella coda, incrementando l'indice di ciascuno, e "liberando" l'ultimo elemento della coda;
* allo `STEP 3`, aggiungiamo `element` alla coda in posizione `last`.

La procedura di `dequeue`, di converso, comporta la semplice rimozione dell'ultimo elemento nell'array.

```
dequeue(array)

STEP 1 -> element = queue[first]
STEP 2 -> remove queue[first]
STEP 3 -> queue[first] = queue[first - 1]
```

## 13.3 - Grafi

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
