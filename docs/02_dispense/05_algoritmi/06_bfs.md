## Descrizione dell'algoritmo

La **ricerca in ampiezza**, o, in inglese, **breath-first search** (**BFS**), è un algoritmo di ricerca che lavora su grafi e, per estensione, alberi.

Le sue applicazioni sono svariate: può ad esempio, trovare i collegamenti tra due nodi ad una distanza pari a $k$, oppure individuare i nodi adiacenti all'interno di una rete, o, ancora, trovare il cammino minimo tra due nodi.

Per far questo, la BFS opera "attraversando" tutti i nodi presenti ad una data distanza dal nodo sorgente. Una volta esplorati questi nodi, la distanza viene incrementata, ed i nodi a distanza immediatamente maggiore sono esplorati. In tal senso, esistono diverse possibili implementazioni della BFS; quella che esploreremo prevede l'utilizzo di una _coda_.

Per semplicità, comunque, partiremo vedendo l'applicazione della BFS sugli alberi.

### BFS sugli alberi

Visualizzare l'applicazione della BFS su un albero è molto semplice. Supponiamo di dover considerare il seguente albero.

![starting_tree](../../assets/images/05_algoritmi/06_bfs/starting_tree.png# images)

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
