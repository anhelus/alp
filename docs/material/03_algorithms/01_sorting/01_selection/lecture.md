# 3.1.1 Selection sort

Uno dei problemi più "classici" nello studio degli algoritmi è quello di ordinare una lista di elementi affini (ovvero dello stesso tipo). Questo problema, soltanto apparentemnete banale, ha in realtà numerosi riscontri pratici, in quanto capita molto spesso di dover ordinare una lista secondo un certo criterio (ad esempio, un elenco di nomi in ordine alfabetico, oppure i prezzi di diversi beni in ordine ascendente). Per far questo, nel tempo sono stati definiti diversi algoritmi detti di *ordinamento* o, in inglese, *sorting algorithms*.

Il primo algoritmo che vedremo è chiamato *selection sort*. Questo è un algoritmo di tipo *iterativo*, che analizza quindi un elemento della lista alla volta alla ricerca dell'elemento minore; per comprendere appieno il funzionamento dell'algoritmo, è opportuno utilizzare un esempio concreto.

### Esempio e formalizzazione

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

### Esempio pratico

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

### Analisi della complessità computazionale dell'algoritmo

L'algoritmo di selection sort cicla su tutti gli $n$ indici di un array. Per comprendere quante operazioni sono necessarie a completare l'ordinamento, dovremo contare il numero di comparazioni necessarie ad individuare l'elemento "minore" attualmente presente all'interno dell'array.

In particolare, alla prima iterazione (con $i = 0$), avremo la necessità di effettuare $n$ operazioni di comparazione, una per ogni elemento dell'array; alla seconda, con $i = 1$, dovremo fare $n - 1$ confronti, alla terza $n - 2$, e così via. Ciò implica che avremo bisogno di un numero di operazioni pari a:

$$
C_T = n + (n - 1) + \ldots + 2 + 1 = \frac{n^2}{2} + \frac{n}{2}
$$

La complessità di caso peggiore tiene conto del limite asintotico del valore precedente, ed è chiaramente pari ad un $O(n^2)$.
