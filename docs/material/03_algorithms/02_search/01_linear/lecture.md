# 15 - Algoritmi di ricerca

Vediamo in ultimo gli algoritmi di ricerca.

## 15.1 - Ricerca binaria

## Introduzione al problema

Supponiamo di voler trovare un determinato elemento all'interno di una lista di valori, come ad esempio il numero di un nostro contatto all'interno della nostra rubrica (ovviamente, supponiamo di *non* voler utilizzare la funzionalità di ricerca integrata nella rubrica stessa).

Supponiamo di voler trovare il nostro gruppo tra quello dei partecipanti al tema d'anno. Ovviamente, l'idea sarebbe quella di scrivere un programma che faccia la ricerca del nostro gruppo in maniera automatica.

Una prima idea potrebbe essere quindi quella di esaminare ogni gruppo, partendo dal primo, mediante un approccio chiamato *ricerca lineare* (*linear search*). Ciò significa che il nostro programma dovrebbe esaminare una quarantina di gruppi per trovare quello di cui ha bisogno; non molti, giusto?

Beh, immaginiamo adesso di voler trovare Betelgeuse nel catalogo stellare [*Tycho-2*](https://www.cosmos.esa.int/web/hipparcos/tycho-2), che contiene non quaranta studenti, ma più di due milioni e mezzo di stelle. L'impresa non sembra più tanto semplice.

Non disperiamo, però. Esiste un approccio che ci permette di ridurre in maniera drastica il numero di operazioni da eseguire, ovvero la *ricerca dicotomica* o, più comunemente, la *binary search*. 

!!! note "Definizione del problema"
	Abbiamo dimenticato una parte fondamentale nella descrizione dell'algoritmo, ovvero definire più o meno formalmente quale problema risolve. In breve, la *ricerca dicotomica serve a trovare un oggetto in una lista ordinata*.

## Descrizione dell'algoritmo

L'idea alla base della binary search è *tenere traccia di un intervallo di ipotesi ragionevoli*. Facciamo un rapido esempio per capire al meglio di cosa si tratta.

Immaginiamo che noi, Alice, chiediamo al nostro collega, Bob, di pensare ad un numero compreso tra *uno* e *cento*. Il nostro obiettivo è quello di indovinare il numero in meno di otto mosse: facendolo, costringeremo Bob a pagare il caffè (anche al Docente). Le regole dicono che, ad ogni mossa, diremo a Bob un numero, e lui ci dirà soltanto se quello che ha pensato è *inferiore* o *superiore*.

Bob già gongola, pensando al caffè che gusterà a nostre spese: in realtà, però, non sa che noi abbiamo seguito l'insegnamento del Docente, e quindi siamo pronti a fargli sparire il sorriso dalle labbra.

La nostra strategia è semplice: scartare, ad ogni mossa, il maggior numero possibile di *ipotesi false*, ovvero di numeri che *non* coincidono con quello pensato da Bob. Per farlo, partiamo con una mossa standard: diciamo a Bob che, a nostro avviso, il numero cui ha pensato è 50. Bob, ovviamente, sogghigna: non è quello, e si limita a dirci che è *superiore*. Quello che lui non afferra al volo è che ha appena ridotto di metà il nostro spazio delle ipotesi, che da cento possibilità è passato a cinquanta.

La seconda mossa è altrettanto semplice: infatti, gli proponiamo la metà del nuovo intervallo, ovvero 75. Bob continua a godersela, dicendoci che è *inferiore*. Ma noi abbiamo ulteriormente delimitato il nostro range di possibilità.

Il gioco prosegue come segue.

```
ROUND 3
--------------------------------
ALICE -> 62 --- BOB -> INFERIORE
--------------------------------
ROUND 4
--------------------------------
ALICE -> 56 --- BOB -> SUPERIORE
--------------------------------
ROUND 5
--------------------------------
ALICE -> 59 --- BOB -> SUPERIORE
--------------------------------
ROUND 6 (BOB IMPALLIDISCE)
--------------------------------
ALICE -> 61 --- BOB -> INFERIORE
--------------------------------
ROUND 7 (BOB TREMANTE...)
--------------------------------
ALICE -> 60 --- BOB -> PAGARE
```

In sole sette mosse, abbiamo trovato il valore immaginato da Bob e, mentre sorseggiamo il meritato caffè, ringraziamo il Docente di Informatica per averci illuminato.

## Fase di progettazione.

Potremmo voler implementare questo algoritmo in un linguaggio di programmazione, di modo da serializzare la vittoria di caffè con gli altri nostri amici Charlie, Dave, etc.

Per farlo, è necessario per prima cosa scrivere l'algoritmo in *pseudocodice*, e poi definirne il flow chart.

TODO: da qui

Per questo gioco, posso usare poche variabili. Possiamo usare la variabile *min* per indicare l'ipotesi minima più ragionevole, e la variabile *max* per l'ipotesi massima ragionevole.

Ecco un'implementazione step-by-step:

1. sia min = 1 e max = n
2. troviamo il valore medio tra min e max, arrotondato ad un intero
3. se abbiamo trovato il numero, fermiamoci. altrimenti
4. se l'ipotesi era troppo bassa, impostiamo min a n/2 + 1
5. se l'ipotesi era troppo altra, impostiamo max a n/2 - 1
6. torniamo al passo 2

## TODO: flow chart 

## Complessità computazionale

Sappiamo che la ricerca lineare di un array di $n$ elementi potrebbe dover consultare fino ad $n$ ipotesi.

Vediamo come capire qual è il numero massimo di ipotesi che invece porta avanti la ricerca dicotomica.

L'idea chiave è che quando la ricerca dicotomica fa un'ipotesi incorretta, la porzione dell'array che contiene le ipotesi ragionevoli è ridotta di metà. Se la porzione ragiovenole ha 32 elemnti, un'ipotesi non corretta la riduce di 16. Quindi, la ricerca dicotomica dimezza la diemnsione della porzioe ragionevole ad ogni ipotesi non corretta.

Quindi, se iniziamo con un array lungo 8, la prima ipotesi non corretta riduce la dimensione delk problema a 4, quindi a 2, e quindi a 1. Una volta che la poszione ragionevole contiene solo unn elemento, non c'è bvisogno di ulteriori ipotesi; infatti, in questo caso, l'ipotesi può essere corretta o incorretta, e comunque abbiamo finito. POer cui con un array di otto elmenti sono necessari al più quattro valutazioni.

Cosa accade con 16? Beh, è semplice verificare che serve un passaggio in più, e quindi sono necessarie cinque valutazioni.

Questo ci porta ad un pattern. Ogni volta che raddoppiamo la dimensione dell'array, abbiamo bisogno di soltanto una nuova ipotesi. Supponendo di avere $m$ ipotesi per un array di lunghezza $n$. Quindi, se la lunghezza dell'array raddoppia a $2 * n", il numero di ipotesi diventa $m + 1$.

Possiamo quinid esprimere il numero di ipotesi, nel caso peggiore, come "il numero di volte che dobbiamo ripetutatmente dimezzare, aprtendo da $n$, fino ad arrivare ad 1, più 1". Questo significa che dobbiamo usare un log_2 (n). Questo significa che, se n come nel nostro caso è circa 64, avremo che il numero di ricerche è pari a 6. Per i 2.600.000 stelle, il numero di ipotesi è pari a 22.

!!! note "Nota"
	I numeri che abbiamo indicato non sono potenze di 2. in questo caso, valuteremo la potenza di deu immediatamente inferiroe, e vi aggiungeremo 1. Ecco perché per gli studenti abbiamo 7, mentre per le stelle abbiamo 22.

Il vantaggio di una complessità logaritmica è che cresce molto lentamente, essendo l'inverso della funzione esponenziale, che invece cresce molto rapidamente.

## 15.2 - Ricerca in ampiezza

## Descrizione dell'algoritmo

La **ricerca in ampiezza**, o, in inglese, **breath-first search** (**BFS**), è un algoritmo di ricerca che lavora su grafi e, per estensione, alberi.

Le sue applicazioni sono svariate: può ad esempio, trovare i collegamenti tra due nodi ad una distanza pari a $k$, oppure individuare i nodi adiacenti all'interno di una rete, o, ancora, trovare il cammino minimo tra due nodi.

Per far questo, la BFS opera "attraversando" tutti i nodi presenti ad una data distanza dal nodo sorgente. Una volta esplorati questi nodi, la distanza viene incrementata, ed i nodi a distanza immediatamente maggiore sono esplorati. In tal senso, esistono diverse possibili implementazioni della BFS; quella che esploreremo prevede l'utilizzo di una _coda_.

Per semplicità, comunque, partiremo vedendo l'applicazione della BFS sugli alberi.

### BFS sugli alberi

Visualizzare l'applicazione della BFS su un albero è molto semplice. Supponiamo di dover considerare il seguente albero.


La BFS opera considerando due parametri:

1. il nodo attualmente ispezionato;
2. i _figli_ di questo nodo, ovvero quelli adiacenti al nodo attualmente attraversato.

In particolare, alla prima iterazione il nodo attualmente ispezionato è proprio i

1. il nodo _radice_, ovvero quello da cui parte la ricerca;
2. la _distanza_ dal nodo radice, ovvero il numero di archi che separano un dato nodo dal nodo radice;
3. il _predecessore_ del nodo

Il primo nodo che dovremo considerare è quello relativo al nodo radice, ovvero il nodo $1$.

Il primo valore che andremo a considerare è proprio quello relativo al nodo radice, ovvero il nodo $1$.

Il primo valore è la _distanza_, che ci dà il numeor minimo di archi in un qualsiasi percorso presente dal vertice sorgente al vertice $v$.

Il seocndo è il vertice _predecessore_ di $v$ lunco il percorso più breve dal vertice sorgente. Il predecessore del sorgente, ovviamente, non c'è.

Se non vi è alcun path dal vertice sorgente al vertice $v$, la distnaza di $v$ è infinita ed il suo predecessore non esiste.

TODO: esempio vertice isolato

Nella BFS, impostiamo inizialmente la distanza ed il predecessore di ogni vertice al valore null. Iniziamo a cercare dal nodo sorgente, e vi assegniamo una distanza pari a 0. Quindi, visitiamo tutti i vicini del nodo sorgente, e vi assegnamo una distanza di 1, impostando il predecessore come sorgente. Quindi, visitiamo tutti i vicini dei vertici la cui distanza è 1 e che nono sono stati viistati prima, e diamo a ciascuno di quesi vertici una distanza di 2, ed impostiamo il loro predecessore come l vertice a partire dal quale abbiamo fatto la visita. Procediamo iterativamente con questa procedura fino a che tutti i veritci raggiungibili dal nodo radice non sono stati visitati, sempre visitando tutti i vertici a distanza $k$ dalla sorgente prima di visitare un qualsiasi vertice a distanza di $k + 1$.

TODO: ESEMPIO SU ALBERO

Una volta completato l'esempio, possono sorgere un paio di domande. la prima è come determianre se un vertice è già stato visitato. Questo è in realtà semplice: la distanza di un vertice è nulla prima che è stata visitata, nel qual momento assume un valore numerico. Quindi, quando siesaminano i vicini di un vertice, visitiamo solo quelli la cui distanza è auttlamente a null.

L'altra domanda è come tener traccia di quali vertici sono già stati visitati ma che devono essere ancora analizzati. Si usa in questo caso una coda.

In particoalre, quando visitiamo un vertice, lo mettiamo in una coda. All'inizio, mettiamo nella coda il vertice sorgente perché è sempre il primo che visiteremo. Per decidere quale vertice vgisitare in seguito, scegliamo il vertice che è stato maggiormente in coda, e lo rimuoviamo dalla coda - in altre parole, usiamo il vertice che viene restituito dall'operazione di dequeue().

TODO: esempio su albero

Notiamo che, in ogni momento, la coda o contiene tutti i vertici alla stessa distanza, o contiene i vertici con distanza $k$ seguiti dai vertici con distanza $k + 1$. In questo modo, ci assicuriamo di visitare tutti i vertici a distanza $k$ prima di visitare un qualsiasi vertice a distanza $k + 1$.

## Analisi della BFS

Quanto impiega la BFS per un grafo con un insieme di vertici $V$ ed un insieme di archi $E$? La risposta è un tempo pari a $O(V + E)$.

Vediamo il perché. Ipotizziamo che $|E| \geq |V|$, che è il caso per la maggior parte dei grafi, specialmente quelli per i quali eseguiamo la BFS. Quindi:

$$
|V| + |E| \leq |E| + |E| = 2 \times |E|
$$

Dato che ignoriamo i fattori costanti nella notazione asintotica, vediamo che quando $|E| \geq |V|$, allora $O(V + E)$ è in pratica $O(E)$. Se, però, abbiamo $|E| < |V|$, allora:

$$
|V| + |E| \leq |V| + |V| = 2 \times |V|
$$

per cui $O(V + E)$ significa in realtà $O(V)$. Possiamo mettere i casi insieme dicendo che $O(V + E)$ significa $O(max(V, E))$.

In generale, se abbiamo dei parametri $x$ ed $y$, $O(x + y)$ significa in realtà $O(max(x, y))$.

Perché la BFS quindi viene eseguita in $O(V+E)$? E' necessario $O(V)$ per inizializzare la distanza ed i predecessori per ciascun vertice. Ognif vertice è visitato almeno una volta, perchè soltanto la prima volta che viene raggiunto la sua distanza è pari a `null`, per cui ogni vertice è messo nella coda almeno una volta. Dal momento in cui esaminiamo gli archi indicednti s un vertice solo quando lo usiamo come putno di partenza, ogni edge è esaminato almeno due volte, una per ognuno dei veritci su cui incide. Di conseguenza, la BFS spende $O(V+E)$ tempo visitando i vertici.

