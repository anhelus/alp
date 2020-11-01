## Analisi degli algoritmi

L'analisi dell'efficienza di un algoritmo può essere effettuata in due fasi differenti, prima dell'implementazione e dopo dell'implementazione

### Analisi a priori

Questa è definita come l'analisi teorica di un algoritmo. L'efficienza di un algoritmo è misurata asusmendo che tutti gli altri fattori, come ad esempio la velocità del processore, sono costanti e non hanno alcun effetto sull'implementazione.

### Analisi a posteriori

Questa è definita come l'analisi empirica di un algoritmo. L'algoritmo scelto viene implementato usando un linguaggio di programmazione. Successivamente, l'algoritmo scelto è eseguito sulla macchina target. In questa analisi, le statistiche come il tempo e lo spazio necessario sono collezionale.

L'analisi degli algoritmi tiene conto dell'esecuzione o del tempo delle varie operazioni coinvolt. Il tempo di esecuzione di un'operazione può essere definito come il numero di istruzioni computerizzate eseguite per ogni operazione.

## Complessità degli algoritmi

Supponiamo che X sia trattato come l'algoritmo e che $N$ sia la dimensione dei dati in ingresso Il tempo e lo spazio richiesto dall'algortimo X sono i due fattori principali che determinano l'efficienza dell'algoritmo.

### Fattore temporale

Il tempo è calcolato o misurato contando il numero di oeprazioni (come le comparazioni negli algoritmi di sorting).

### Fattore spaziale

Lo spazio è calcolato o misurato contando il massimo spazio richiesto in memoria dall'algoritmo.

La complessità di un algoritmo $O(n)$ fornisce il tempo di esecuzione o lo spazio necessario dall'algoritmo considerando $N$ come dimensione dei dati di ingresso.

## Complessità spaziale

La complessità spaziale di un algoritmo rappresenta il quantitativo di spazio di memoria necessario all'algoritmo nel suo life cycle.

Lo spazio necesario da un algoritmo è uguale alla somma delle seguenti due componenti.

Una parte fissa che è lo spazio richiesto per memorizzare crti dati e variabili (es. semplici variabili e costanti, dimensioni del programma, etc.) che non sono dipendenti dalla dimensione del problema.

Una parte variabile è lo spazio richiesto dalle variabili, la cui dimensione è totalmente dipendete dalla dimensione del problema. Ad esempio, allocazione dinamica della memoria.

La complessità spazilae $S(p)$ di un qualsiasi algoritmo $p$ è data da:

$$
S(p) = A + S(I)
$$

dove $A$ è la parte fissa ed $S(I)$ è la parte variabile dell'algoritmo, che dipende dalle caratteristiche $I$ dello stesso.

Vediamo un esempio

### Algoritmo

```
SUM(P, Q)
Step 1 ->  START
Step 2 -> R = P + Q
Step 3 -> STOP
```

Qui abbiamo tre variabili, ovvero `R`, `p` e `q`. Di conseguenza, $S(p) = 0 + 3$.

!!! note
	Ovviamente, lo spazio effettivo dipende dal data type. Ad esempio, se consideriamo un intero abbiamo che il precedente valore va moltiplicato per 32 bit.

## T^Complessità nel tempo

La complessità nel tempo di un algoritmo è la rappresentazione della quantità di tempo richiesto dall'algoritmo per essere completamente eseguito. I requisiti nel tempo possono essere definiti come una funzionenumerica $t(N)$, dove $t(N)$ può essere misurata come il numero di step, supponendo che ogni step richieda tempo costante.

Ad esempi, nel caso dell'addizione di due interi ad n bit, sono necessari N step. di conseguenza, il tempo totale è t(N) = c*n, dove c è il tempo necessario all'aggiunta di due bit. Osservamo quinid che t(N) cresce linearmente con l'aumento di N.

### Esempi

```c

for(i = 0; i < n; i++) {
	cout<<i;
	i++;
}
```

La complessità computazionale di questo ciclo for è pari ad $O(n/2)$. Questo è legato al fatto che ad ogni ciclo il valore di i è incrementato due volte.

```c
for (i = n; i >0; i++) {
	for (j = 0; j < n; j++) {
		cout<<i;
	}
}
```

Qui si vede che ad ogni iterazione del ciclo "esterno", seguiranno *n* iterazioni del ciclo interno, per cui la complessità nel tempo è pari ad $O(n^2)$.

```c
while (i) {
	cout<<i;
	i = i/2;
}
```

Ad ogni iterazione, il valore di i sarà diviso per 2. Di conseguenza, la complessità è pari ad $O(log(n))$.