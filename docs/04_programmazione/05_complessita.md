## Analisi degli algoritmi

L'analisi delle performance di un algoritmo può essere effettuata in due diverse fasi, ovvero *prima* (*analisi a priori*) e *dopo* (*analisi a posteriori*) l'implementazione.

### Analisi a priori

L'*analisi a priori* è un'analisi di tipo prettamente *teorico* dell'efficienza dell'algoritmo. Questa viene misurata assumendo che tutti i fattori contestuali, quali (ad esempio) la velocità del processore utilizzato, o la quantità di memoria disponibile (RAM, cache e registri), siano costanti e non abbiano alcun effetto tangibile sull'algoritmo stesso.

!!! note "Nota"
	Ovviamente, sta al lettore comprendere il *contesto* legato alle premesse dell'analisi a priori. Ciò significa che è fortemente sconsigliato provare ad eseguire un algoritmo che ha difficoltà a girare su una GeForce 3090 su un Raspberry Pi 2, indipendentemente dalle considerazioni derivanti dall'analisi a priori.

### Analisi a posteriori

L'*analisi a posteriori* è un'analisi di tipo prettamente *empirico* dell'efficienza dell'algoritmo. Ciò significa che l'algoritmo viene valutato *dopo* essere stato eseguito su una macchina target, mediante indicazioni di tipo numerico come il tempo necessario all'esecuzione e la memoria occupata.

!!! note "Importanza del contesto"
	Nel caso dell'analisi a posteriori, il contesto risulta essere estremamente importante. Infatti, i risultati dipendono anche da fattori come il linguaggio di programmazione utilizzato, l'hardware sottostante, la presenza contestuale di altri processi software in esecuzione, e, non ultimo, le abilità del programmatore, che rappresentano spesso il vero e proprio collo di bottiglia.

!!! note "Statistica ed analisi"
	E' inoltre importante sottolineare come sia necessario effettuare *più* misurazioni in un'analisi a posteriori, proprio per minimizzare l'impatto del contesto sulle performance rilevate. Ciò comporta creare una rudimentale statistica dei valori ottenuti.

Ad ogni modo, che si parli di analisi a priori od a posteriori, questa procedura è necessaria per valutare la *complessità* dell'algoritmo.

## Complessità degli algoritmi

Supponiamo che un algoritmo $X$ abbia un insieme di dati in ingresso di cardinalità $N$. La *complessità* dell'algoritmo è strettamente correlata a due fattori, ovvero il *tempo* richiesto per l'esecuzione dell'algoritmo e lo *spazio* occupato da questo in memoria.

In particolare, la *complessità temporale* è determinata contando il numero di operazioni effettuate. Per esempio, negli algoritmi di ordinamento, il fattore temporale è direttamente proporzionale al numero di confronti tra gli elementi che saranno ordinati.

La *complessità spaziale* è invece determinata valutando lo spazio massimo richiesto dall'algoritmo in termini di memoria occupata.

Iniziamo parlando proprio di quest'ultima.

### Complessità spaziale

La complessità spaziale di un algoritmo indica il quantitativo di spazio che l'algoritmo occupa in memoria dall'inizio alla fine della sua esecuzione. Questo è pari alla somma di due componenti:

* una parte fissa, pari allo spazio richiesto per la memorizzazione di dati "fissi", come funzioni e costanti, che non variano a seconda del problema;
* una parte variabile, data dallo spazio richiesto per la memorizzazione (appunto) delle variabili, la cui dimensione è dipendente dal problema stesso.

Ciò significa che è possibile esprimere la complessità spaziale $S(X)$ di un algoritmo $X$ come:

$$
S(X) = S_F + S_V(C)
$$

con $S_F$ parte fissa ed $S_V$ parte variabile e dipendente dalle caratteristiche $C$ dell'algoritmo $X$.

!!! note "Nota"
	Le caratteristiche $C$ non coincidono con il numero di variabili in input per l'algoritmo $N$.

#### Un esempio

Consideriamo il seguente algoritmo (in pseudocodice):

```
SUM_ONE(P, Q)
Step 1 -> START
Step 2 -> R = P + Q + 1
Step 3 -> STOP
```

##### Analisi a priori

Il numero di variabili in questo algoritmo è pari a 3, ovvero `P` e `Q` (input) ed `R` (output). Abbiamo inoltre una costante (il valore `1`). La complessità spaziale (analizzata a priori) sarà quindi pari a:

$$
S(X) = S_F + S_V(C) = 1 + 3
$$

Ne consegue che l'algoritmo occuperà quattro unità di memoria.

##### Analisi a posteriori

Supponiamo che l'effettiva implementazione dell'algoritmo sia in linguaggio C, e che il tipo di dato associato a ciascuna variabile sia un intero. La complessità spaziale (analizzata a posteriori) sarà pari a:

$$
m_{int} = 32 bit \Rightarrow S(X) = S_F + S_V(C) = 4 m_{int} = 128 bit
$$

### Complessità temporale

Abbiamo visto come la complessità temporale di un algoritmo sia associata alla quantità di tempo richiesto dallo stesso per una sua completa esecuzione. Anche questa complessità può essere espressa come una funzione numerica del tipo $T(I)$, con $I$ numero di step necessari al completamento dell'istruzione.

#### Un esempio

##### Analisi a priori

Torniamo al precedente algoritmo. In questo caso, abbiamo elencato tre step, anche se, nei fatti, ci sono solo due operazioni di cui tenere conto, ovvero due addizione. Quindi, la complessità temporale analizzata a priori sarà pari a $T(I) = 2$.

##### Analisi a posteriori

Anche in questo caso, per effettuare l'analisi a posteriori avremo bisogno di fissare alcune condizioni. Supponiamo, ad esempio, che il nostro processore impieghi un microsecondo per eseguire una somma. Di conseguenza, la complessità temporale analizzata a posteriori sarà pari a 2 microsecondi.

## Complessità di caso peggiore

L'esempio che abbiamo visto è, al solito, *estremamente* semplice. In realtà, è difficile che nella realtà sia necessario calcolare la complessità computazionale di situazioni così poco articolate; è più facile avere un'idea abbastanza *sommaria* della complessità spaziale e temporale di un algoritmo, che va quindi *stimata* assumendo il *caso peggiore*, ovvero calcolando il numero massimo di operazioni e/o spazio che, nel peggiore dei casi, il nostro algoritmo dovrebbe dover effettuare e/o occupare.

Per far questo, si utilizza la notazione *O-grande*, utilizzata spesso per descrivere il limite asintotico superiore di una funzione rispetto ad un'altra.

Detto in maniera meno formale: un algoritmo che ha (ad esempio) una complessità temporale $T(n) = O(n^2)$ avrà un costo, in termini di tempo, pari *al più* ad $n^2$; un algoritmo con una complessità $T(n) = O(n * log(n))$ "costerà" al massimo $n*log(n)$ operazioni, e così via.

## Alcuni esempi

### Semplice ciclo for

Supponiamo di dover calcolare la complessità di questo semplice ciclo `for`:

```c
int n = 10;
for(int i = 0; i < n; i++) {
	printf("%d", i);
	i++;
}
```

Notiamo innanzitutto che il valore del contatore `i` viene incrementato di due ad ogni iterazione. Ciò significa che, *al più*, saranno eseguite $n/2$ operazioni. Ciò implica che la complessità computazionale sia nell'ordine di $O(n/2)$.

### Cicli for annidati

Vediamo cosa accade nel caso si considerino due cicli `for` l'uno annidato all'interno dell'altro.

```c
int n = 10;
for (int i = 0; i < n 0; i++) {
	for (int j = 0; j < n; j++) {
		printf("%d", i);
	}
}
```

Per ogni iterazione del ciclo esterno (quello che usa come contatore la variabile `i`) avremo *n* iterazioni del ciclo interno (quello che usa come contatore la variabile `j`). La complessità di caso peggiore sarà quindi $O(n^2)$.
