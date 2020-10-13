## Formulare un problema

Possiamo iniziare la nostra dissertazione partendo dalla definizione del concetto di _problema_.

Il De Mauro lo definisce come un:

> _quesito da risolvere mediante la determinazione di uno o più enti, partendo da elementi noti e condizioni fissate in precedenza_

Questa definizione ci dà tutti gli elementi necessari a *formulare* un problema. Analizziamoli nel dettaglio insieme.

### Il problema come *compito*

Un problema è, per prima cosa, un _quesito_, o un _compito_, che _necessita di una risoluzione_. Esempi concreti possono essere quindi:

- _"Come montare il mobile che abbiamo appena acquistato dall'IKEA?"_
- _"Come calcolare l'area di un triangolo rettangolo?"_
- _"Come dimostrare l'ipotesi di Riemann?"_

Tra questi esempi, ovviamente, ce ne sono almeno due che probabilmente non sono di facile soluzione.

### Il *risolutore*

Per risolvere un problema è necessario ricorrere ad uno o più _enti_, propriamente intesi come _esecutori_ o _risolutori_ del problema. Tornando agli esempi precedenti, il risolutore del primo problema è, ovviamente, chi monta il mobile, quello per il secondo problema è invece lo studente (o la calcolatrice), mentre nel terzo caso abbiamo il matematico teorico che risolve (o confuta) l'ipotesi di Riemann.

### Gli *elementi noti* e le _condizioni fissate_

Il problema può essere risolto soltanto partendo da _elementi noti_. Questo significa, intuitivamente, avere la conoscenza di una serie di _condizioni iniziali_ dalle quali partire per risolvere il problema.

Al solito, riprendiamo i nostri esempi.

Per montare il nostro mobile dell'IKEA, avremo bisogno di conoscere una serie di condizioni iniziali, come ad esempio:

* dove collocare il mobile;
* quali e quanti pezzi ci sono nella confezione;
* di che attrezzi necessitiamo.

A questi, possiamo aggiungere alcune _condizioni_ che vogliamo rispettare, come ad esempio il voler completare la costruzione del mobile in un paio d'ore al massimo, o il provare a non rompere nulla.

Analogamente, per calcolare l'area di un triangolo rettangolo, dovremo conoscerne base ed altezza, e rispettare i vincoli imposti dalla geometria di base.

La determinazione degli elementi noti e delle condizioni fissate per la dimostrazione dell'ipotesi di Riemann è lasciata come banale esercizio al lettore.

## Risolvere un problema

Abbiamo visto che per formulare un problema dobbiamo determinare il quesito da risolvere, capire chi (o cosa) lo risolverà, ed infine esplorare le condizioni iniziali e gli eventuali vincoli.

Ciò ci permette però di 

Abbiamo quin



Abbiamo quindi visto che la formulazione di un problema 

Per risolvere un problema, 



Problem solving
Il problem solving prevede il passaggio dalla formulazione del problema all’individuazione di un metodo risolutivo.

La formulazione di un problema è imprescindibile: dobbiamo sempre e comunque sapere da che punto dobbiamo partire.

Immaginiamo, ad esempio di voler capire come organizzare la nostra libreria. Per prima cosa, occorre formulare il problema, ovvero capire “cosa” fare.

Una possibile formulazione del problema è la seguente:

Dati n libri, disposti in modo casuale, organizzarli in ordine alfabetico in modo che non ve ne siano più di dieci per ciascuno scaffale.

Nella precedente formulazione, alquanto informale, notiamo alcuni aspetti: in primis, stabiliamo quella che è una vera e propria condizione iniziale, legata al fatto che i nostri libri sono disposti in maniera casuale. Successivamente, individuiamo un obiettivo, ovvero quello di organizzare i libri in ordine alfabetico. In questo caso specifico, inotlre, abbiamo anche a che fare con un vincolo, legato al fatto che non ci devono essere più di dieci libri su ciascuno scaffale.

Formulare un problema significa individuarlo da un punto di vista più o meno formale.
FARE ESEMPI

Dopo che il problema è stato formulato, si deve costruire un metodo di soluzione del problema. In pratica, occorre individuare gli step necessari alla sua risoluzione.

Una volta individuati, occorre eseguire la soluzione. Questa può essere “delegata” ad un esecutore: questi deve essere in grado di comprendere la descrizione della soluzione, ed eseguire contestualmente le operazioni richieste.

La costruione del metodo risolutivo è legata:

alle operazioni semplici disponibili
alle modalità secondo cui queste operazioni possono essere composte per realizzare operazioni più complesse
sequeza (una dopo l’altra)
parallelo (contemporaneamente, o comunque in un’opportuna finrestra temporale)

Dati
Descrizione (anche parziale) di una situazione iniziale e di un obiettivo

I dati possono essere descritti in un linguaggio naturale, che permetta di descrivere situazioni (oggetti) e differenze tra diverse situazioni.

Insieme di operatori applicabili a situazioni per trasformarle in nuove situazioni
espressi in un linguaggio che fa riferimento al processo
ogni sequenza di operatore è a sua volta un operatore composto

La soluzione è un operatore (composto) nel linguaggio di proceso che trasformaa loggetto che descrive la situazione iniziale in quello che descrive la situazione desiderata.

Per algoritmo si intende la serie di prescrizioni o istruzioni che specifica l’insieme delle azioni da compiere per poter risolvere un problema.

Un esempio di algoritmo sono, per esempio, le istruzioni per il montaggio dei mobili IKEA.

Proviamo a caratterizzare un semplice problema matematico, ovvero il calcolo del Massimo Comun Divisore.

Problema

Formulazione: Dati due numeri interi n ed m, individuare il Massimo Comun Divisore.

Dati
Sia n il maggiore tra i due, ed m il minore.

Algoritmo risolutivo
Dividendo n per m, si ottiene un quoziente q ed un rest r.
Ripetiamo l’operazione preceente con m ed r al posto rispettivamente di n ed m.

Quando si ottiene r = 0, l’algoritmo si arresta, ed il resto ottenuto all’interazione precedente è il MCD ricercato.

ESEMPIO DI CALCOLO

Proprietà degli algoritmi

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
