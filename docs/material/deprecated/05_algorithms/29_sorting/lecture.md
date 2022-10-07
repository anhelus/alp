# 14 - Algoritmi di ordinamento

Uno dei problemi più "classici" nello studio degli algoritmi è quello di ordinare una lista di elementi affini (ovvero dello stesso tipo). Questo problema, soltanto apparentemnete banale, ha in realtà numerosi riscontri pratici, in quanto capita molto spesso di dover ordinare una lista secondo un certo criterio (ad esempio, un elenco di nomi in ordine alfabetico, oppure i prezzi di diversi beni in ordine ascendente). Per far questo, nel tempo sono stati definiti diversi algoritmi detti di *ordinamento* o, in inglese, *sorting algorithms*. Vediamone alcuni tra i più conosciuti.

## 14.1 - Selection sort

Il primo algoritmo che vedremo è chiamato *selection sort*. Questo è un algoritmo di tipo *iterativo*, che analizza quindi un elemento della lista alla volta alla ricerca dell'elemento minore; per comprendere appieno il funzionamento dell'algoritmo, è opportuno utilizzare un esempio concreto.

### 14.1.1 - Esempio e formalizzazione

Immaginiamo quindi di voler ordinare un mazzo di dieci carte dalla più piccola alla più grande. Per farlo, seguiamo questi passi:

1. disponiamo tutte le carte presenti nel mazzo in un'unica fila;
2. cerchiamo la carta più piccola, e posizioniamola all'estrema sinistra del mazzo;
3. dividiamo la fila in due parti: nella parte più a sinistra inseriamo le carte già ordinate, mentre in quella destra quelle da ordinare;
4. prendiamo dalla fila di destra la carta più piccola, posizionandola a destra dell'ultimo elemento della fila di sinistra;
5. reiteriamo il passo 4 fino a che non vi sono più carte nella fila di destra.

Volendo, è possibile formalizzare i passi precedenti come segue. Dato un vettore $x$ fatto da $n$ numeri interi:

1. Associare ad $i$ il primo indice dell'array, ovvero $i = 0$, ed a $j$ l'ultimo, ovvero $j = n-1$.
2. Associare alla variabile $m$ il valore di $x(0)$, supponendo che $m$ sia il valore più piccolo attualmente presente all'interno dell'array.
3. Confrontare $m$ con tutti gli elementi $x(k), k \in (0, n-1]$. Se $x(k) < m$ per qualche $k$, allora $m = x(k)$.
4. Aumentare il valore di $i$ di un'unità.
5. Reiterare le istruzioni 3-4 fino a che $i = x(n-1)$.

### 14.1.2 - Esempio pratico

Immaginiamo di avere un array di numeri interi, i cui elementi assumono valore `[12, 4, 8, 7, 2]`. Seguiamo i passi evidenziati in precedenza per l'algoritmo.

* *Step 1*: imponiamo $i = 0, j = 4$.
* *Step 2*: imponiamo $m = x(0) = 12$.
* *Step 3*: dal confronto, emerge che $x(1) = 4 < m \Rightarrow m = x(1)$. Continuando però ad incrementare $i$, notiamo che $x(4) = 2 < m \Rightarrow m = x(4)$.
* *Step 4*: poniamo $i = i + 1 = 2$.
* *Step 5*: reiteriamo le istruzioni 3-4 fino a che $i = 4$, ottenendo l'array finale.

In altre parole:

```linenums="1"
START

CICLO 0
x = [12, 4, 8, 7, 2];
i = 0; j = 4; min = x(0) = 12;

CICLO 1
x = [2, 12, 4, 8, 7];
i = 1; j = 4; min = x(1) = 12;

CICLO 2
x = [2, 4, 12, 8, 7];
i = 2; j = 4; min = x(2) = 12;

CICLO 3
x = [2, 4, 7, 12, 8];
i = 3; j = 4; min = x(3) = 12;

CICLO 4
x = [2, 4, 7, 8, 12];
i = 4; j = 4; min = x(4) = 12;

STOP
```

### 14.1.3 - Analisi della complessità computazionale dell'algoritmo

L'algoritmo di selection sort cicla su tutti gli $n$ indici di un array. Per comprendere quante operazioni sono necessarie a completare l'ordinamento, dovremo contare il numero di comparazioni necessarie ad individuare l'elemento "minore" attualmente presente all'interno dell'array.

In particolare, alla prima iterazione (con $i = 0$), avremo la necessità di effettuare $n$ operazioni di comparazione, una per ogni elemento dell'array; alla seconda, con $i = 1$, dovremo fare $n - 1$ confronti, alla terza $n - 2$, e così via. Ciò implica che avremo bisogno di un numero di operazioni pari a:

$$
C_T = n + (n - 1) + \ldots + 2 + 1 = \frac{n^2}{2} + \frac{n}{2}
$$

La complessità di caso peggiore tiene conto del limite asintotico del valore precedente, ed è chiaramente pari ad un $O(n^2)$.

## 14.2 - Insertion sort

Il secondo algoritmo che vedremo è l'*insertion sort*. Per introdurlo, partiamo dal

un altro modo è l’insertion sort. Immaginiamo che stimao giocando un gioco di carte. Stiamo tenendo delle carte in mano, e tutte queste carte sono ordinate. Il dealer ci dà esattamente una nuova carta. Si deve metterla nel posto corretto in modo che la carta cheabbiamo in mano siano ancora ordinate. Nel selection sort, ogni elemento che aggiungiamo all’array ordinato non può essere più piccolo degli elementi già presenti nell’arry ordinato. Ma nel nostro esempio, la nuova carta può essere più piccola delle carte che abbiamo già in mano, per cui dobbiamo andare giù nella linea, comparando le nuove card con ognuna delle carte in mano, fino a che non troviamo un posto epr inserirla. Inseriamo la nuova carta nel punto giusto, e nuovamente la nostra mano ha delle card completamente ordinate. Quindi il dealer ci da un’altra carta, e si ripete la stesa procedura. Quindi un’altra carta, e via dicendo, fino a che il dealer non ci dà più alcuna carta.

Questa è l’idea dietro linsertion sort. Iterare nelle posizsioni dell’array, a partire dall’indice 1. COn ogni nuova posizione è come la nuova carta che civieen data dal dealer, e dobbiamo inserirla nel psto corretto nel subarray ordinato a sinistra di quella posizione.

Immaginiamo che il subarray dall’indice 0 all’indice 5 sia già ordinato, e vogliamo inserire l’ekemeto attuamlmente all’indice 6 in questo subarray già ordinato, in modo che il subarray dall’indice 0 all’indice 6 sia ordinato.

2 3 7 8 10 13 5  PER ARRIVARE A 2 3 5 7 9 10 13

Per inserire l’eeento in posizione 6 nel subarray alla sua sinsitra, compariamo ripetutatmente questo con gli elementi alla sua sinistra, andando da destra verso sinistra. Chiamaiamo quindi lìelemento in posizione 6 chiave. ogni volta che capiamo che la chiave è inferiroe di un elemento alla sua sinistra, lo spostiamo verso destra, dal momento che sappiamo che la chiave dovrà andare alla sinistra di quell’elemento. Dovremo fare altre due cose per far funzionare questa idea: dovremo avere un’operazione slide (che sposta un elemento di una posizione a destra), e dovremo salvare il valore della chiave in un puno separato. Nel nostro esempio, :

1.- inseriamo l’elemento all’indice 6 in ua variabile chiamata key
compariamo key con l’elemento alla posizione 5. sappiamo che key è inferiore all’elemento in posizione 5, quindi faccioamo lo slide di questo alla posizione 6.

Notiamo che l’operazione di slide si limita a copiare l’eemento una posizione a destra. Quindi, compariamo key con l’elemento in posizione 4. troviamo che key è inferiore, e reiteriamo la procedura.

Quando l’elementoè inferiore di key, non effettuiamo l’operazione di slide. Invece, lasciamo la variabile key in quella posizione, immediatamente all’elemento a destra. Il risultato è ‘ordinamento di tutto l’array.

Il nome dell’insertion sort deriva dal fatto che questo inserisce ripetutamente un elemento nel subarray a sinistra dell’elemento che sta valutando. Di conseguenza, nel caso generale, si parte considerando sempre il primo elemento del subarray (o meglio un subarray di un elemento), che non può non essere ordinato (è ordinato rispetto a se stesso).
La prima chiave sarà quindi l’elemento con indice 1. 

10   7   3  13
7 10   3 13

A questo punto, il subarray ordinato va da 0 ad 1, quindi il nuovo key è indice 2. compariamo questo con quelli a sinistra ed abbiamo:

7 10 3 13
7 3 10 13
3 7 10 13

Ci sono un paio di situazioni limite. Il primo è quando l’elemento chiave è inferiore a tutti gli elementi nel subarray ordinato; il secondo è qunado invece è superiore. Nel primo, ogni elemento del subarray deve effettuare uno slide, nel secondo non ci sono slide da effettuare.


pseudocdice

chiamo insert per inserire l’elemento cheinizia all’indice 1 nell’array ordinato all’indice 0.
chiamo insert per insierire l’elemento che inizia all’indice 2 nell’array ordinato in un indice che va da 0 ad 1.
…
Chiamo insert per insserire l’elemento che inizia all’indice n-1 nell’array ordinato nell’indice che va da 0 ad n - 2.

analisi
come nel caso del selection sort, l’insertion sort fa un loop sugli indici dell’array. chiama semplicemente insert sugli elementi di indice che vanno da 1 ad n-1. Ogni chiamata ad insert richiede un certo periodo di tempo.

Prendiamo una situazione nella quale chiamoiamo insrt ed il valore che viene inserito nel subarray è inferiore ad ogni elemento nel sybarray. Quindi, ogni elemento nel subarray dovrà effettuare lo slide di una posizione a sinistra. Per cui, in generale, se stiamo inserendo un nuovo elemento in un subarray con k elementi, tutti i k elementi dovranno effettuare uno slide di una posizione. Pitutosto che contare esattamente quante linee di codice dobbiamo usare, diciamo che questo numero è c. Quindi, potremmo aver bisogno di c * k linee per inserire un valore in un subarray di k elementi.


Supponiamo che ad ogni chiamata ad insert, il valore che venga inserito sia inferirore ad ogni elmento nel subarray alla sua sinsitra. Quando chiamiamo insert la prima vlta, con k = 1. La seconda volta, k = 2. La terza volta, k = 3. E via, fino all’ultima volta, quando k = n -1. Quinid, il tempo totale speso ad inserire qualcosa nel sub array è

c * (1 + 2 + .. + n-1).

Anche in questo caso abbiamo una serie aritmetica. Tornando alla notazione, O(n^2).

Molto probabilmente, però, l’insertion sort potrebbe avere meno tempo necessario (ad esempio, questo accadrebbe nel caso avessimo un array già ordinato). Però non è detto, quindi è necessario sempre e comunque considerare un tempo pari a O(n^2). Potremmo però considerare il caso migliroe, che avrebbe un O(n) (in questo caso l’array è già quasi ordinato).

## 14.3 - Quick sort

## Descrizione dell'algoritmo

Così come il merge sort, il quick sort utilizza l'approccio *divide-and-conquer*, ed è ovviamente un algoritmo di tipo ricorsivo. Tuttavia, laddove nel merge sort lo step *divide* è praticamente ininfluente, ed è il *combine* ad essere quello più rilevante per il riordinamento, nel quick sort i ruoli si invertono.

Ecco quindi come si articolano i tre diversi step del *divide-and-conquer* nel quick sort.

##### Divide e procedura di partitioning

Nel passo *divide*, scegliamo un elemento dell'array `array[l,r]` chiamato *elemento pivot*. A questo punto, gli elementi presenti nell'array saranno disposti in modo che:

* tutti gli elementi minori o uguali del pivot siano alla sua *sinistra*;
* tutti gli elementi strettamente maggiori del pivot siano alla sua *destra*.

Questa procedura è chiamata *partitioning* (partizionamento).

!!! note "Nota"
	Non ci interessa l'ordine relativo degli elementi a sinistra o a destra del pivot.

Nella pratica, vedremo come conviene scegliere come pivot sempre l'elemento più a destra nell'array, ovvero `array[r]`.

Ad esempio, con il nostro array `[8, 4, 5, 12, 7]`, il pivot ad essere scelto alla prima iterazione sarà proprio il `7`. Dopo il partizionamento, l'array sarà riscritto come `[4, 5, 7, 8, 12]`, ed indicheremo con `q` il nuovo indice del pivot (in questo caso, `q = 2`).

!!! note "Nota"
	Il fatto che siamo riusciti a riordinare l'array in una sola mossa è puramente fortuito.

##### Conquer

Nel passo *conquer* ordiniamo in maniera ricorsiva gli array `array[l, q-1]` (ovvero tutti gli elementi minori o uguali al pivot) ed `array[q+1, r]` (ovvero tutti gli elementi maggiori del pivot).

##### Combine

Come accennato in precedenza, il passo *combine* non fa effettivamente niente, dato che tutti gli elementi a sinistra del pivot saranno ordinati, e lo stesso varrà per gli elementi a destra dello stesso.

### Partitioning

Abbiamo visto che il "lavoro" vero e proprio dell'algoritmo di quick sort avviene durante lo step *divide*; ricordiamo inoltre che è opportuno scegliere come pivot l'elemento più a destra nell'array sotto analisi.

Dopo aver scelto il pivot, dividiamo il nostro array come segue. 

Per prima cosa, usiamo due indici, chiamati $q$ e $j$, per dividere l'array in quattro gruppi. La variabile `q` sarà quella che contiene il riferimento all'indice nel quale inseriremo il pivot; la variabile `j` invece sarà usata come contatore. In particolare, avremo:

* un gruppo $L$, in cui saranno inseriti tutti gli elementi di `array[l, q-1]` (ovvero quelli minori o uguali al pivot);
* un gruppo $G$, in cui saranno inseriti tutti gli elementi di `array[q+1, j-1]` (ovvero quelli maggiori del pivot);
* un gruppo $U$, in cui saranno inseriti tutti gli elementi di `array[j, r-1]` (ovvero quelli la cui relazione con il pivot non è conosciuta perché non ancora comparati).

Il pivot è contraddistinto con `array[r]`.

All'inizio, sia `q` sia `j` sono uguali ad `l`. Ad ogni step, si compara `array[j]`, ovvero l'elemento più a sinistra del gruppo $U$, con il pivot. Se `array[j]` è maggiore del pivot, ci limitiamo ad incrementare il valore di `j`; se invece `array[j]` è inferiore al pivot, allora lo sostituiamo con `array[q]`, aumentando contestualmente `j` e `q`.

Una volta arrivati al pivot, il gruppo $U$ risulta essere vuoto. A quel punto, sostituiamo il pivot con l'elemento più a sinistra del gruppo $G$, ovvero sostituendo `array[r]` con `array[q]`. Questo cambio mette il pivot *sempre* tra i gruppi $L$ e $G$.

<!-- ## Pseudocodice

```
quickSort(array, l, r)
STEP 1: if (r > l)
STEP 2: 	q = partition(array, l, r)		// Step divide: divide l'array e restituisce il pivot
STEP 3:		quickSort(array, l, q-1)		// Step conquer (a): chiama quickSort sull'array di sinistra
STEP 4: 	quickSort(array, q+1, r)		// Step conquer (b): chiama quickSort sull'array di destra
```

```
// Swaps two items in an array, changing the original array
var swap = function(array, firstIndex, secondIndex) {
    var temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
};

var partition = function(array, p, r) {
    var q = p;
    for (var j = p; j <= r - 1; j++) {
        if (array[j] <= array[r]) {
            swap(array, j, q);
            q++;
        }
    }
    swap(array, q, r);
    return q;
    // Compare array[j] with array[r], for j = p, p+1,...r-1
    // maintaining that:
    //  array[p..q-1] are values known to be <= to array[r]
    //  array[q..j-1] are values known to be > array[r]
    //  array[j..r-1] haven't been compared with array[r]
    // If array[j] > array[r], just increment j.
    // If array[j] <= array[r], swap array[j] with array[q],
    //   increment q, and increment j. 
    // Once all elements in array[p..r-1]
    //  have been compared with array[r],
    //  swap array[r] with array[q], and return q.
};

var array = [9, 7, 5, 11, 12, 2, 14, 3, 10, 4, 6];
var q = partition(array, 0, array.length-1);
println("Array after partitioning: " + array);
Program.assertEqual(q, 4);
Program.assertEqual(array, [5, 2, 3, 4, 6, 7, 14, 9, 10, 11, 12]);

``` -->

## Analisi computazionale

### Analisi del partitioning

Il partitioning di un array ad `n` elementi si effettua in $O(n)$. Questo è legato al fatto che ogni elemento `array[j]` viene comparato una volta sola con il pivot; a seguito della comparazione, può avvenire uno swap, `q` può essere incrementato o meno, e `j` è sempre incrementato.

### Analisi di caso peggiore

Partiamo dall'analisi di caso peggiore. Supponiamo infatti che le dimensioni delle partizioni non siano bilanciate, e che il pivot scelto sia l'elemento più piccolo o grande dell'array. Di conseguenza, una delle partizioni non avrà alcun elemento, mentre l'altra ne avrà $n-1$ (ovvero tutti tranne il pivot). Di conseguenza, dovremo valutare ricorsivamente un array ad $n-i$ elementi, con $1 \leq i \leq n$.

Notiamo quindi che, in questo caso, avremo una serie del tipo $n + (n - 1) + \ldots + 2 + 1$, che abbiamo visto essere in un $O(n^2)$.

### Analisi di caso migliore

Nel caso migliore, le partizioni sono ben bilanciate. Ad esempio, potremmo trovarci nel caso in cui l'array analizzato ha un numero dispari di elementi, ed il pivot si trova esattamente al centro dopo il primo partitioning, per cui ogni partizione ha $(n-1)/2$ elementi. Oppure ancora, avendo un numero pari di elementi, avremo che la partizione di sinistra avrà $n/2$ elementi, mentre quella di destra $(n - 2)/2$. In questi casi, l'albero è facilmente riconducibile a quello del merge sort, per cui la complessità è in $O(n \cdot log_2n)$.

## 14.4 - Merge sort

## Il paradigma Divide-et-Impera (Divide-and-Conquer)

Prima di introdurre questo algoritmo ed il successivo, è opportuno parlare dell'approccio su cui sono basati, chiamato **divide-et-impera** o, in inglese, **divide-and-conquer**. Useremo la notazione inglese perché fa più "stile", ovviamente.

Il paradigma divide-and-conquer è puramente ricorsivo: infatti, divide un problema in diversi sotto-problemi, che risultano essere riconducibili al caso originario, pur rimanendo meno complessi. Una volta ricondottisi ai singoli casi base, l'approccio risolve ciascuno dei singoli problemi, combinando le soluzioni per risolvere il problema originario.

E' quindi possibile schematizzare il paradigma in tre parti:

1. **divide**: suddividiamo il problema in diversi sotto problemi, che rappresentano delle istanze più piccole del problema originario.
2. **conquer**: risolviamo ogni sotto-problema, se riconducibile ad un caso base.
3. **combine**: combiniamo le soluzioni ai sottoproblemi, arrivando a quella del problema originario.

Schematizzando:

![divide_conquer](../../assets/images/05_algoritmi/04_merge_sort/divide_conquer.png# images)

## Descrizione dell'algoritmo

Abbiamo già detto come il **merge sort** si basi su un approccio di tipo divide-and-conquer.

Di conseguenza, partendo dal nostro solito problema (ovvero, l'ordinamento di un array), dobbiamo definire il _sotto-problema da risolvere_. Banalmente, questo potrà essere proprio quello di ordinare ciascun sotto-array in cui viene scomposto il nostro array originario.

Utilizziamo in tal senso una notazione specifica per indicare il sotto-array che va dall'elemento di indice $l$ all'elemento di indice $r$, denotandolo con `array[l, r]`. Per fare un esempio, se il nostro array iniziale fosse:

```
array = [8, 5, 12, 7, 4];
```

allora:

```
l = 0;
r = 2;
array[l,r] = [8, 5, 12];
```

Il merge sort utilizza l'approccio divide-and-conquer come segue:

1. **divide**: trova il valore $q$ intermedio tra $l$ ed $r$. Se $q$ è dispari, lo approssimiamo all'intero inferiore;
2. **conquer**: ordina i due sotto-array creati dal passo _divide_. Ciò significa che si agirà su `array[l,q]` ed `array[q+1,r]`;
3. **combine**: unisci i due sotto-array in uno singolo `array[l, r]`.

Ovviamente, come tutti i problemi ricorsivi, avremo bisogno di un caso base. Ciò avviene quando gli array risultanti dal passo _conquer_ hanno meno di due elementi, ovvero quando $l \geq r$: questo è ovviamente legato al fatto che un array vuoto o con un solo elemento è già ordinato di suo.

### Un esempio

Vediamo un esempio di utilizzo del merge sort. In tal senso, usiamo il nostro solito array con valori `[8, 5, 12, 7, 4]`.

Al primo livello, l'array da considerare è quello completo, e quindi:

```
l = 0;
r = 4;
array[l,r] = [8, 5, 12, 7, 4]
```

1. **divide**: in questo passo, calcoliamo $q=2$;
2. **conquer**: in questo passo, notiamo che i due array non sono riconducibili ad un caso base, per cui ripetiamo il _divide_;

Avremo quindi il secondo livello. In questo passo, l'array `array[0,1]` avrà ancora due elementi, per cui sarà necessario suddividerlo ulteriormente; stesso vale per `array[2,4]`.

Arrivando in fondo, avremo la scomposizione di ogni array a livello di singolo elemento. Ciò comporta che si arriverà ad un certo punto ad una situazione in cui tutti gli array sotto esame saranno composti da un unico elemento, come mostrato in figura.

![divide_step](../../assets/images/05_algoritmi/04_merge_sort/divide_step.png# images)

A questo punto, ci si è ricondotti in ogni situazione al caso base. Potrà quindi avvenire lo step _conquer_, dove saranno ordinati i diversi sotto-array, ed infine lo step _combine_, che combinerà i risultati in uscita dal _conquer_. Questo processo è mostrato in figura.

![conquer_step](../../assets/images/05_algoritmi/04_merge_sort/conquer_step.png# images)

Notiamo come, dal punto di vista logico, i passaggi _divide_ e _conquer_ del merge sort siano in realtà abbastanza semplici. Il punto "complesso", quello dove avviene l'ordinamento vero è proprio, è il _combine_.

#### Merging

Il passo _combine_ è quello che ci permette di "unire" due sotto-array adiacenti, ovvero `array[l, q]` ed `array[q+1, r]`, in un singolo array ordinato.

Supponiamo che l'array iniziale `array[l, r]` abbia $n$ elementi. E' necessario esaminare ciascuno di essi, per cui, nel caso migliore, potremo sperare in un tempo per l'unione in un $O(n)$.

Detto questo chiamiamo, per comodità, `array[l,q]` con il nome di `left`, ed `array[q+1, r]` con il nome di `right`.

Vogliamo fare in modo che nell'elemento più a sinistra di `array`, ovvero `array[l]`, venga inserito l'elemento più minore presente sia in `left` sia in `right`. Ovviamente, dato che `left` e `right` si suppongono ordinati, il valore più piccolo può essere, all'inizio, o in `left[0]` o in `right[0]`.

Possiamo usare quindi tre variabili per indicizzare gli array:

- `i` indicizza il primo elemento di `left` non ancora copiato in `array`. Inizialmente, `i = 0`;
- `j` indicizza il primo elemento di `right` non ancora copiato in `array`. Inizialmente, `j = 0`;
- `k` indicizza la posizione successiva di `array` in cui copiare. Inizialmente, `k = l`.

In pratica, avremo un ciclo all'interno del quale verranno reiterate le seguenti istruzioni:

```c
if (left[i] > right[j]) {
	array[k] = right[j];
	j++;
} else {
	array[k] = left[i];
	i++;
}
k++;
```

Potrà ovviamente accadere che uno tra `left` e `right` si "svuoti" per primo; di conseguenza, dato che l'altro è comunque ordinato, potremo semplicemente limitarci a copiarlo integralmente negli elementi restanti di `array`, senza la necessità di effettuare alcuna ulteriore comparazione.

<!-- ## Pseudocodice

```
mergeSort(array[], l, r)
STEP 1:	if r > l
STEP 2: 	m = floor((l + r)/2)			// Trovo valor medio tra gli estremi
STEP 3:		mergeSort(array, l, m)			// Chiamo la funzione mergeSort sulla prima metà dell'array
STEP 4:		mergeSort(array, m+1, r)  		// Chiamo la funzione mergeSort sulla seconda metà dell'array
STEP 5:		merge(array, l, m, r)			// Combino le due metà trovate negli step 3 e 4
``` -->

## Analisi computazionale

### Passo combine

Verifichiamo che il costo legato allo step _combine_ sia in $O(n)$.

L'operazione di unione avviene in tre parti:

1. nella prima, creiamo i due array `left` e `right`;
2. fino a che ci sono degli elementi non copiati da `left` o `right` in `array`, compariamo il primo elemento non ancora copiato di `left` a quello non ancora copiato di `right`, e copiamo il minore in `array`;
3. una volta che abbiamo copiato tutti gli elementi da `left` (o `right`) in `array`, copiamo ogni elemento rimanente da `right` (o `left`) in `array`.

E' chiaro che, al massimo, dovremo effettuare `n` comparazioni ed `n` operazioni di copia. Ciò significa che, al più, avremo $2 \cdot n$ operazioni, per cui la complessità sarà in un $O(n)$.

### Analisi di caso peggiore

Per effettuare l'analisi della complessità globale dell'algoritmo, consideriamo i tempi di esecuzione di ciascuno degli step coinvolti. Assumiamo, al solito, di stare ordinando un array ad $n$ elementi.

- Nel passo _divide_, abbiamo bisogno di un tempo costante, ed indipendente dalla dimensione degli array coinvolti. Infatti, stiamo semplicemente calcolando il valore medio tra `l` ed `r`, per cui abbiamo bisogno di un'unica operazione.
- Nel passo _conquer_, ordiniamo ricorsivamente due sotto-array di approsimativamente $n/2$ elementi.
- Nel passo _combine_, uniamo $n$ elementi, ed abbiamo già verificato avere bisogno di un $O(n)$.

Considerando i passi _divide_ e _combine_ assieme, notiamo che il tempo necessario al _divide_ è trascurabile, per cui possiamo considerare solo quello per il _combine_. Resta da calcolare il tempo necessario al _conquer_.

Per mantenere le cose semplici, consideriamo $n$ pari e potenza di due (nel caso $n$ sia dispari, il calcolo della complessità non cambia molto). Notiamo poi che l'esecuzione del merge sort su un array ad $n$ elementi richiederà (approssimativamente) lo stesso tempo dell'esecuzione di due merge sort su array ad $n/2$ elementi, ciascuno dei quali richiede il doppio dell'esecuzione del merge sort su un array ad $n/4$ elementi, e così via.

Ricordando che il merge sort può essere visto come un albero binario, è evidente come ad ogni livello successivo dell'albero il numero di problemi _raddoppi_, mentre il tempo necessario alla risoluzione di un singolo problema si _dimezzi_. Questi due effetti si annullano reciprocamente, per cui potremo dire che, ad ogni livello, avremo bisogno al più di $n$ operazioni.

Il tempo totale necessario è quindi considerando un $O(n)$ per ogni livello dell'albero prodotto dal merge sort. Con $c$ livelli, avremo che il tempo totale necessario sarà al più $c \cdot n$.

Qual è quindi il valore di $c$? Dato che stiamo parlando di un albero binario, e che stiamo considerando un valore di $n$ pari e potenza di due, sappiamo che $c = log_2n$. Di conseguenza, il tempo necessario per il merge sort sarà dato da $n$ (ovvero il numero di operazioni da effettuare a ciascun livello) moltiplicato per $c$ (il numero di livelli), ovvero un $O(n \cdot log_n2)$.
