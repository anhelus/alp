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
