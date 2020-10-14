## Formulare un problema

Possiamo iniziare la nostra dissertazione partendo dalla definizione del concetto di _problema_.

Il De Mauro lo definisce come un:

> _quesito da risolvere mediante la determinazione di uno o più enti, partendo da elementi noti e condizioni fissate in precedenza_

Questa definizione ci dà tutti gli elementi necessari a _formulare_ un problema. Analizziamoli nel dettaglio insieme.

### Il problema come _compito_

Un problema è, per prima cosa, un _quesito_, o un _compito_, che _necessita di una risoluzione_. Esempi concreti possono essere quindi:

- _"Come montare il mobile che abbiamo appena acquistato dall'IKEA?"_
- _"Come calcolare l'area di un triangolo rettangolo?"_
- _"Come dimostrare l'ipotesi di Riemann?"_

Tra questi esempi, ovviamente, ce ne sono almeno due che probabilmente non sono di facile soluzione.

### Il _risolutore_

Per risolvere un problema è necessario ricorrere ad uno o più _enti_, propriamente intesi come _esecutori_ o _risolutori_ del problema. Tornando agli esempi precedenti, il risolutore del primo problema è, ovviamente, chi monta il mobile, quello per il secondo problema è invece lo studente (o la calcolatrice), mentre nel terzo caso abbiamo il matematico teorico che risolve (o confuta) l'ipotesi di Riemann.

### Gli _elementi noti_ e le _condizioni fissate_

Il problema può essere risolto soltanto partendo da _elementi noti_. Questo significa, intuitivamente, avere la conoscenza di una serie di _condizioni iniziali_ dalle quali partire per risolvere il problema.

Al solito, riprendiamo i nostri esempi.

Per montare il nostro mobile dell'IKEA, avremo bisogno di conoscere una serie di condizioni iniziali, come ad esempio:

- dove collocare il mobile;
- quali e quanti pezzi ci sono nella confezione;
- di che attrezzi necessitiamo.

A questi, possiamo aggiungere alcune _condizioni_ che vogliamo rispettare, come ad esempio il voler completare la costruzione del mobile in un paio d'ore al massimo, o il provare a non rompere nulla.

Analogamente, per calcolare l'area di un triangolo rettangolo, dovremo conoscerne base ed altezza, e rispettare i vincoli imposti dalla geometria di base.

La determinazione degli elementi noti e delle condizioni fissate per la dimostrazione dell'ipotesi di Riemann è lasciata come banale esercizio al lettore.

## Risolvere un problema

Come abbiamo visto, formulare un problema implica determinare il quesito da risolvere (il "cosa?"), l'esecutore della risoluzione (il "chi?") e lo stato di partenza (in maniera non proprio ortodossa, il "da dove?").

Risolvere il problema, però, significa andare oltre alla sua formulazione, allo scopo di individuare un apposito _metodo di risoluzione_. Dal punto di vista formale, possiamo esprimere questo passaggio come la ricerca di una funzione che colleghi lo spazio dei problemi allo spazio delle soluzioni; in parole povere, queste prevedono l'individuazione di tutti gli step necessari alla risoluzione del problema.

INSERIRE FIGURA

La possibilità di costruire il metodo di risoluzione è legata a diverse parti fondamentali, ed in particolare:

- le operazioni atomiche disponibili;
- il modo in cui queste operazioni possono essere "composte" per realizzare delle operazioni più complesse, ovvero sequenza (un'operazione eseguita dopo l'altra) e parallelo (due o più operazioni eseguite contemporaneamente, o comunque in un'opportuna finestra temporale).

Insieme di operatori applicabili a situazioni per trasformarle in nuove situazioni
espressi in un linguaggio che fa riferimento al processo
ogni sequenza di operatore è a sua volta un operatore composto

## Di cosa ha bisogno un problema per la sua risoluzione?

### Dati

Per prima cosa, abbiamo bisogno dei _dati_ del problema. I dati rappresentano la descrizione, anche parziale, della _situazione iniziale_ e dell'_obiettivo_. Normalmente, i dati possono essere descritti in un linguaggio naturale, che permette di descrivere situazioni (oggetti) e differenze tra diverse situazioni.

### Soluzione

La soluzione è un operatore (composto) nel linguaggio di processo che trasforma l'oggetto che descrive la situazione iniziale in quello che descrive la situazione desiderata. Per algoritmo si intende la serie di prescrizioni o istruzioni che specifica l’insieme delle azioni da compiere per poter risolvere un problema.

## Un esempio

Facciamo un esempio. Proviamo a formulare e risolvere un semplice problema matematico, ovvero il calcolo del Massimo Comun Divisore.

### Formulazione del problema

> Dati due numeri interi _n_ ed _m_, individuare il _Massimo Comun Divisore_ (_MCD_).

### Dati

Sia _n_ il maggiore tra i due numeri, ed _m_ il minore.

### Algoritmo risolutivo

1. Dividere _n_ per _m_. Il risultato di questa operazione è rappresentato da un quoziente _q_ ed un resto _r_.
2. Reiterare l'operazione precedente ponendo _n = m_ ed _m = r_.
3. Se _r = 0_, l'algoritmo si arresta; il valore di _r_ ottenuto all'iterazione precedente è il MCD ricercato.

### Esempio numerico

DA FARE

## Caratteristiche degli algoritmi risolutivi

Le caratteristiche degli algoritmi risolutive sono principalmente quattro.

### Finitezza

Gli algoritmi devono essere _finiti_, sia dal punto di vista _spaziale_, sia dal punto di vista _temporale_. Ciò significa che un algoritmo deve essere esprimibile in uno

Gli algoritmi sono:
Finitezza
spaziale: espressi in uno spazio finito
temporale: esecuzione in un tempo finito

Il MCD non sarebbe un algoritmo se non fosse finito spazialmente (ovvero se, per assurdo, l’algoritmo non riuscisse mai a “terminare”, occupando sempre più memoria sul calcolatore ed impiegandoci sempre più tempo).

Generalità
Gli algoritmi sono generali, ovvero rappresentano una soluzione ad un’intera classe di problemi. Più banalmente, l’algoritmo per il calcolo del MCD può essere applicato indipendentemente dal valore di n ed m.

Completezza
Tutte le istanze del problema (ovvero tutti i problemi che richiedono il calcolo del MCD) devono essere risolubili dall’algoritmo.

Non ambiguo
Le istruzioni dell’algoritmo non possono essere interpretabili in maniera ambigua. Quelle dell’IKEA possono essere non chiare, ma non sono mai ambigue.

Eseguibilità
L’esecutore deve essere potenzialmente in grado di eseguire ogni istruzione.

Un algoritmo si dice deterministico quando al momento dell’esecuzione di ogni istruzione è nota l’istruzione successiva. Un effetto di questo è che due diverse esecuzioni dello stesso algoritmo determiniisticocon gli stessi dati producono gli stessi efeftti.

Ciò non vale per gli algoritmi non deterministici, che sono affetti da fenomeni di tipo stocastico.

Gli algoritmi possono dare delle risposte di tipo binario (SI o NO). Non è necessario che siano elaborati dei dati numerici.

ESEMPIO: STRINGA PALINDROMA

“osso”

posizione 1 == posizione 4? OK
posizione i+1 == posizione f-1

OPPURE

Se sono uguali primo ed ultimo, cancellare primo ed ultimo e ripetere fino a che ci sono al massimo un carattere.

Input ed output
Gli algoritmi per poter godere della proprietà di generalità devvno ressere in grado di riolsvere una classe di problemi
algoritmo calcola ipoteusa di un triangolo rettangolo INDIPENDENTEMNETE DAI VALORI DEI CATETI; unica condizione è che questi siano noti

La generalizzazione è ottenuta mediante la procedura detta di parametrizzazione dei valori su cui opera l’algoritmo.

Istanza del problema -> per risolverla si sostituiscono ai parametri le istanze dei valori.

I dati forniti in ingresso sono gli input; i risultati forniti dall’esecuzione dell’algoritmo sono gli output.

NON E’ STRETTAMENTE NECESSARIO CHE UN ALGORITMO ABBIA UN OUTPUT. Ad esempio, se mettiamo che un algoritmo deve dare la differenza esclusivamente se m è maggiore di n, in caso contrario abbiamo comunuque due input, ma se n > m allora non abbiamo un output. DOMANDA: COME FARE SI’ CHE QUESTO ALGORITMO ABBIA UN OUTPUT?

Variabili
Oltre ai dati di I/O, gli algoritmi utilizzano dei dati di supporto per svolgere le proprie attività, detti variabili
