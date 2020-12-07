## Introduzione al problema

Abbiamo visto 

INSERTION SORT
Ci sono molti modi diversi di effettuare il sort. 

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
