# 2.6 La complessità computazionale degli algoritmi

Il concetto di *complessità computazionale* di un algoritmo è direttamente correlato al numero di operazioni che occorre svolgere per portarlo a termine, oppure ancora alla quantità di memoria occupata nel sistema durante l'esecuzione dello stesso.

In particolare, avremo due tipi di complessità:

* la *complessità temporale* può essere determinata a partire dal numero di operazioni effettuate dall'algoritmo;
* la *complessità spaziale* è legata allo spazio massimo richiesto dall'algoritmo in fase di esecuzione nella memoria del calcolatore.

Torneremo più avanti su questi aspetti; per adesso, limitiamoci a fare un breve esempio a titolo meramente illustrativo.

## Un primo, rapido, esempio

Facciamo un rapido esempio introduttivo (nel prosieguo, formalizzeremo al meglio i concetti espressi).

Immaginiamo di dover calcolare la distanza euclidea tra due numeri, così come abbiamo visto nella lezione precedente; per comodità, riportiamo di seguito lo stesso pseudo-codice:

``` linenums="1"
distanza_x = (x_a - x_b)^2;
distanza_y = (y_a - y_b)^2;
distanza = (distanza_x + distanza_y)^(1/2);
```

La complessità computazionale va valutata a partire dalle operazioni *atomiche*. Nel caso precedente, notiamo subito che alcune operazioni sono raggruppate, per cui è il caso di "esplodere" l'algoritmo per quanto possibile.

``` linenums="1"
differenza_x = x_a - x_b
distanza_x = (differenza_x)^2;
differenza_y = y_a - y_b
distanza_y = (differenza_y)^2;
distanza_quad = distanza_x + distanza_y
distanza = (distanza_quad)^(1/2);
```

!!!note "Nota"
	Per semplicità, non teniamo conto dei singoli passaggi che un calcolatore potrebbe impiegare nell'effettuare un'elevazione a potenza, ma consideriamo la stessa un'operazione unitaria.

Avremo quindi un totale di $N=6$ operazioni; supponendo che ognuna di queste richieda esattamente un ciclo del nostro processore, e che questo effettui un ciclo al secondo, la complessità computazionale temporale sarà proprio pari a 6.

Per quello che riguarda la complessità computazionale spaziale, invece, dovremo contare il numero $K$ di variabili create (e, di conseguenza, memorizzate) durante l'esecuzione dell'algoritmo, oltre che il numero $b$ di bit con cui ciascuna variabile è rappresentata (per semplicità, riterremo costante questo valore). In particolare, notiamo che vengono create 6 variabili, a cui sono da aggiungere gli input `x_a` ed `x_b`; supponendo che $b$ sia pari ad 8 bit, avremo:

$$
K = 6 + 2 = 8, b = 8 \Rightarrow \\
\Rightarrow C_s = K \cdot b = 8 \cdot 8 = 64
$$

La complessità computazionale spaziale sarà quindi pari a 64 bit.

Importantissimo comunque sottolineare come questo esempio sia puramente *introduttivo*. Nel seguito, forniremo una definizione formale di complessità spaziale e temporale; per adesso, concentriamoci brevemente su due tipi di analisi che è possibile effettuare, ovvero quelle *a priori* ed *a posteriori*.

## Tipi di analisi computazionale

### Analisi a priori

L'*analisi a priori* è un'analisi di tipo prettamente *teorico* dell'efficienza dell'algoritmo. Questa viene misurata assumendo che tutti i fattori contestuali, quali (ad esempio) la velocità del processore utilizzato e la quantità di memoria disponibile siano costanti e non abbiano alcun effetto tangibile sull'algoritmo stesso.

### Analisi a posteriori

L'*analisi a posteriori* è un'analisi di tipo prettamente *empirico* dell'efficienza dell'algoritmo. Ciò significa che l'algoritmo viene valutato *dopo* essere stato eseguito su una macchina target, mediante indicazioni di tipo numerico come il tempo necessario all'esecuzione e la memoria occupata.

!!! note "Importanza del contesto"
	Nel caso dell'analisi a posteriori, il contesto risulta essere estremamente importante. Infatti, i risultati dipendono anche da fattori come il linguaggio di programmazione utilizzato, l'hardware sottostante, la presenza contestuale di altri processi software in esecuzione, e, non ultimo, le abilità del programmatore.
	E' inoltre importante sottolineare come sia necessario effettuare *più* misurazioni in un'analisi a posteriori, proprio per minimizzare l'impatto del contesto sulle performance rilevate. Ciò comporta creare una rudimentale statistica dei valori ottenuti.

Vediamo adesso come è possibile formalizzare i due diversi tipi di analisi computazionale per la complessità spaziale e per quella temporale.

## Complessità spaziale e temporale

### Complessità spaziale

La complessità spaziale di un algoritmo indica il quantitativo di spazio che l'algoritmo occupa in memoria durante la sua esecuzione. Formalmente, questo è pari alla somma di due componenti:

* una parte *fissa*, pari allo spazio richiesto per la memorizzazione di dati che non variano (in pratica, funzioni e costanti, che saranno trattati nel seguito);
* una parte *variabile*, data dallo spazio richiesto per la memorizzazione delle variabili.

Ciò significa che è possibile esprimere la complessità spaziale $C_s(X)$ di un algoritmo $X$ come:

$$
C_s(X) = C_{S_F}(C) + C_{S_V}(C)
$$

con $C_{S_F}$ parte fissa e $C_{S_V}$ parte variabile; entrambe possono essere influenzate dalle caratteristiche $C$ come linguaggio di programmazione ed hardware sottostante.

#### Un esempio più strutturato - Parte 1

Consideriamo il seguente algoritmo (in pseudocodice):

``` linenums="1"
leggi p, q
r = p + q + 1
scrivi r
```

Partiamo dall'analisi a priori. Vediamo subito come questo algoritmo consti di tre variabili, ovvero `p` e `q` (variabili di input) ed `r` (variabile di output). Abbiamo inoltre una costante (il valore `1`). La complessità spaziale (analizzata a priori) sarà quindi pari a:

$$
C_S(X) = C_{S_F} + C_{S_V} = 1 + 3
$$

Notiamo che abbiamo omesso le caratteristiche $C$, in quanto, come già detto, non ne teniamo conto nell'analisi a priori. Ne consegue che l'algoritmo occuperà quattro unità di memoria.

Per quello che riguarda l'analisi a posteriori, immaginiamo che il tipo di dato associato a ciascuna variabile sia un intero ad 8 bit. La complessità analizzata a posteriori sarà:

$$
b = 8 bit \Rightarrow \\
\Rightarrow C_S(X) = C_{S_F}(C) + C_{S_V}(C) = (1 + 3) \cdot 8 = 32 bit
$$

### Complessità temporale

Abbiamo già visto come la complessità temporale di un algoritmo risulti essere associata alla quantità di tempo richiesto ad una completa esecuzione dello stesso. Anche questa complessità può essere espressa da una funzione numerica del tipo:

$$
C_T = \sum_{i=1}^n t_i(C)
$$

con $t_i$ tempo necessario all'esecuzione di uno step atomico dell'algoritmo, e $C$ dipendendente anche stavolta dalle caratteristiche hardware del nostro dispositivo.

#### Un esempio più strutturato - Parte 2

Torniamo all'algoritmo precedente, ed effettuiamone una valutazione a priori.

Abbiamo elencato tre step, anche se, nei fatti, ci saranno soltanto due addizioni della cui esecuzione dovremo tenere conto. Di conseguenza, la complessità temporale analizzata a priori sarà pari a $C_T = 2$.

Per quello che riguarda l'analisi a posteriori, invece, sarà necessario anche stavolta fissare una condizione al contorno, ovvero la velocità con cui il nostro processore riesce ad eseguire una singola istruzione. Supponendo che questa sia pari ad un microsecondo, l'analisi a posteriori ci porterà a stabilire che la complessità computazionale sarà pari a 2 microsecondi.

## Complessità di caso peggiore

Nelle applicazioni reali, è abbastanza difficile che si riesca a calcolare *esattamente* la complessità computazionale di un programma, in quanto il numero di ramificazioni e le variabili da tenere in considerazione sono tali da rendere un approccio deterministico realisticamente non percorribile. Di conseguenza, si ricorre ad approcci che ci permettano di avere un'idea *veritiera* della complessità dell'algoritmo, stimata assumendo la *casistica peggiore*, ovvero calcolando la quantità massima di tempo e memoria che, nel peggiore dei casi, il nostro algoritmo richiederà per essere eseguito.

Per far questo, si utilizza la cosiddetta *O-big notation*, che in matematica ci permette di descrivere il limite asintotico superiore di una funzione rispetto ad un'altra. In parole povere, un algoritmo che ha (ad esempio) una complessità temporale $C_T(n) = \mathbb{O}(n^2)$ richiederà un tempo di esecuzione pari *al massimo* ad $n^2$, mentre un algoritmo con una complessità $C_S(n) = O(n * log(n))$ occuperà al massimo $n*log(n)$ unità di memoria.

!!!note "Nota"
	Nella notazione precedente, `n` indica una variabile che può influenzare il numero di operazioni eseguite dall'algoritmo. Il perché occorra specificarla sarà più chiaro grazie ai prossimi esempi.

### Alcuni esempi

#### Ciclo for (semplice)

Supponiamo di dover calcolare la complessità di questo semplice ciclo `for`:

``` linenums="1"
n = 10;
for i da 1 a n:
	scrivi i;
	incrementa i;
endfor
```

Notiamo innanzitutto che il valore del contatore `i` varia da 1 ad $n=10$. Ciò significa che, *al più*, saranno eseguite $n-1$ operazioni. Ciò implica che la complessità computazionale (nel tempo) sarà nell'ordine di $O(n)$.

Per quello che riguarda quella nello spazio, supponendo che ad ogni iterazione le variabili create all'interno del corpo del ciclo (righe 3-4) siano anche cancellate, l'algoritmo avrà una complessità spaziale di caso peggiore pari a 2; in questi casi, ovvero quando la complessità di caso peggiore è costante, si dice che $C_S = O(1)$

#### Cicli for annidati

Vediamo cosa accade nel caso si considerino due cicli `for` l'uno annidato all'interno dell'altro.

```linenums="1"
n = 10;
for i da 1 a n:
	for j da 1 a n:
		scrivi i;
		scrivi j;
	endfor
endfor
```

Per ogni iterazione del ciclo esterno (quello che usa come contatore la variabile `i`) avremo *n* iterazioni del ciclo interno (quello che usa come contatore la variabile `j`). La complessità temporale di caso peggiore sarà quindi $O(n^2)$; per quello che riguarda invece la complessità spaziale, invece, assumendo un meccanismo analogo al precedente, avremo sempre $O(1)$.V
