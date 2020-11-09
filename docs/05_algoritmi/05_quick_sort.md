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
