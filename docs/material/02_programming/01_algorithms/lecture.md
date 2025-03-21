# 2.1 Introduzione agli algoritmi

In questa sezione discuteremo uno degli strumenti fondamentali dell'informatica, ma non solo: gli *algoritmi*.

## Problemi e soluzioni

Tutti avremo notato come la realtà che ci circonda sia piena di problemi. Ad esempio:

* *come mi preparerò da mangiare per stasera?*
* *riuscirò ad avere una misera pensione?*
* *come monto il mobile Ikea?*
* *come supero l'esame di Informatica?*

Questi problemi (soprattutto l'ultimo) sono risolvibili utilizzando un semplice approccio che, di base, consiste nell'individuare una *soluzione*. Ad esempio:

* *per mangiare, dovrò prendere gli ingredienti, mescolarli secondo una ricetta e, una volta completata la preparazione, godermeli.*
* *per avere una misera pensione, devo lavorare per i prossimi (tanti) anni, versare i contributi, crearmi un fondo pensione integrativo, ed incrociare le dita (soprattutto).*
* *per montare il mobile Ikea, devo seguire le singole, comprensibilissime, istruzioni presenti sul manuale di montaggio.*
* *per superare l'esame, devo studiare l'intero programma e preparare gli opportuni esercizi.*

!!!tip "Nota"
	Per l'ultima soluzione, si consiglia anche l'uso di strumenti scaramantici e votivi di vario tipo.

##### Formulazione di un problema

A questo punto è lecita una domanda: cosa significa *formulare un problema*? E' presto detto: il problema è un *quesito da risolvere mediante la determinazione di uno o più enti, partendo da elementi noti e condizioni fissate in precedenza*. Ok, cerchiamo di scomporre questa formulazione.

1. Il problema è un *quesito*, ovvero una domanda che richiede una risposta, alle volte aperta (*cosa mangio? dove andiamo?*), altre chiusa (*come monto il mobile?*).
2. Per trovare una soluzione al quesito posto dal problema, avremo bisogno di almeno un *ente risolutore*, inteso come entità, fisica o logica, che si occuperà di implementare tutti gli step atti a risolvere il problema. Ad esempio, nel caso del mobile Ikea, l'ente risolutore saremo noi, o chi ci aiuterà a montarlo.
3. L'ente deve poter quindi partire da *elementi noti* e *condizioni fissate* e, quindi, avere una visione dello stato iniziale del mondo. Ad esempio, dovrà conoscere il senso della vite (orario).

Alcuni esempi di quesito, ente e stato iniziale sono riportati nella seguente tabella.

| Quesito | Ente risolutore | Stato iniziale del mondo |
| ------- | --------------- | ------------------------ |
| *Come montare il mobile che abbiamo appena acquistato dall'IKEA?* | Montatore | Collocazione desiderata del mobile, numero e tipo di pezzi, attrezzi necessari... |
| *Come calcolare l'ipotenusa di un triangolo rettangolo?* | Studente | Base, altezza, teorema di Pitagora |
| *Come dimostare l'ipotesi di Riemann?* | Studente | Banali regole basilari di aritmetica |

##### Risoluzione di un problema


DA QUI

## 2.2 - Risolvere un problema

La formulazione di un problema implica quindi la determinazione del _cosa_ (il quesito da risolvere), del _chi_ (l'esecutore materiale della risoluzione) e del _da dove_ (lo stato di partenza e le condizioni fissate). In particolare, diamo a questi ultimi il nome di _dati_: i dati caratterizzano, anche parzialmente, lo stato iniziale del mondo, e possono essere forniti in un linguaggio naturale che permetta di descrivere delle _situazioni_, o _stati_, e le differenze tra di essi.

### 2.2.1 Problemi e soluzioni

Il lettore più attento noterà che manca ancora un elemento fondamentale, ovvero il _come_. Questo è definito individuando un apposito _metodo di risoluzione_ o, più semplicemente, una _soluzione_ al problema.

Dal punto di vista formale, l'individuazione del metodo di risoluzione può essere espressa come una _relazione univoca_ che associa ad ogni elemento dello spazio dei problemi (o meglio, delle _classi di problemi_, come sarà più chiaro in seguito) $\mathbb{P}$ uno o più elementi dello spazio delle soluzioni $\mathbb{S}$.

Informalmente, possiamo dire che _per ogni problema_ (se risolvibile) _esiste almeno una soluzione_.

### 2.2.2 - Costruire la soluzione

Il compito del risolutore è quindi quello di "costruire", o "individuare", la soluzione. La possibilità di farlo è legata ad alcune condizioni fondamentali, ovvero:

- le operazioni _atomiche_ disponibili;
- il modo in cui le operazioni di cui sopra possono essere combinate per realizzare operazioni più complesse.

#### 2.2.2.1 Operazioni atomiche

Per operazione "atomica" intendiamo un'operazione che non è possibile _semplificare_ (ovvero suddividere) in alcun modo. Esempi di operazione atomica possono essere:

- sommare due numeri;
- fare un passo in avanti;
- finalizzare una transazione sul proprio conto corrente bancario.

Esempi di operazioni _non_ atomiche sono invece:

- risolvere un'equazione di secondo grado;
- correre per dieci metri;
- effettuare un versamento ed un prelievo sul proprio conto corrente bancario.

!!!note "Nota sulla somma"
	Il lettore più zelante potrebbe pensare che una somma è suddivisibile usando l'inverso della proprietà associativa. Ciò porterebbe però a scomporre una somma in due somme, che potrebbero essere scomposte in tre somme, e via dicendo. Questa operazione risulta essere controproducente, oltre che contraria al senso comune; si invita quindi il lettore zelante ad adeguarsi al senso comune ed evitare una

!!!note "Nota sul conto corrente bancario"
	La singola transazione sul proprio corrente bancario è in realtà scomponibile, dal punto di vista informatico, in un gran numero di operazioni atomiche: il correntista, infatti, effettua l'autenticazione, completa un form, finalizza la transazione e la esegue. Dato che tutte queste operazioni devono però essere necessariamente _completate_ in un ordine ben definito, i sistemi bancari le vedono come un'unica operazione, che è possibile annullare qualora sopravvenga un problema qualsiasi (problemi di autenticazione, rete non disponibile, mancanza di energia elettrica su uno dei sistemi, etc.).

#### 2.2.2.2 Combinare operazioni atomiche

Le operazioni atomiche possono essere combinate in due modi:

- effettuandole in _sequenza_ (come nel caso del versamento e del prelievo sul proprio conto corrente bancario);
- effettuandole in _parallelo_.

Nel secondo caso, più operazioni vengono eseguite contemporaneamente. Ciò comporta però la necessità di due problemi principali, ovvero:

- _mantenere indipendenti le singole operazioni_;
- _coordinare più esecutori_, o _suddividere il tempo di un esecutore in modo che "simuli" il parallelismo_.

Il primo problema è di importanza cruciale. Immaginate di voler montare assieme a vostro cugino due mobili IKEA allo stesso tempo, ma di avere a disposizione un unico cacciavite: cosa succede se usate il cacciavite e questo contestualmente serve al cugino? O, ancora peggio se, avendo a disposizione un cacciavite a punte intercambiabili, ne modificate la punta da stella a brucola senza avvertire il povero cugino?

Il secondo è meno evidente, ma altrettanto degno di attenzione. Infatti, voi e vostro cugino dovrete necessariamente coordinarvi per non urtarvi, usare gli stessi attrezzi, e via dicendo. L'alternativa sarebbe fare a meno del cugino, e simulare il parallelismo montando i due mobili da voi contemporaneamente; in questo caso, però, il tempo che impieghereste è sicuramente maggiore, ed avreste la necessità di ottimizzare le operazioni da fare cercando di minimizzare lo sforzo necessario a terminare i lavori.

#### 2.2.2.3 Determinare l'insieme di operatori

Individuare le operazioni atomiche e trovare dei modi per combinarle permette quindi di definire un _insieme di operatori_ che possono essere applicati ad un problema per modificarne lo stato (idealmente, da "aperto" a "risolto", considerando eventualmente gli step intermedi). Per essere comprensibili dal risolutore, questi operatori dovranno essere espressi in un _linguaggio_ che faccia riferimento _esplicito_ al contesto del problema.

#### 2.2.2.4 Da _soluzione_ ad _algoritmo_

La soluzione sarà quindi definita come un operatore composto nel linguaggio di processo, il cui compito è trasformare lo stato iniziale del mondo (ovvero problema aperto) in quello che definisce la situazione desiderata (ovvero problema risolto).

L'algoritmo è la serie di istruzioni che specifica l'insieme delel azioni che è necessario compiere per risolvere il problema.

## 2.3 - Un esempio

Proviamo a formulare e risolvere un semplice problema matematico, ovvero il calcolo dell'ipotenusa di un triangolo rettangolo.

### 2.3.1 - Formulazione del problema

_Dati due numeri interi $c_1$ e $c_2$, rappresentanti le lunghezze dei due cateti di un triangolo rettangolo $T$, calcolarne l'ipotenusa $i$._

### 2.3.2 - Dati

Sia $c_1$ la lunghezza del primo cateto, e $c_2$ quella del secondo.

### 2.3.3 - Algoritmo risolutivo (in operazioni atomiche, o quasi)

1. Calcolare il quadrato di $c_1$.
2. Calcolare il quadrato di $c_2$.
3. Sommare i quadrati calcolati ai punti **1** e **2**.
4. Calcolare la radice quadrata della somma ottenuta al punto **3**.

### 2.3.4 Svolgimento numerico

#### Dati

$$
\begin{eqnarray}
c_1 &= 3 \\
c_2 &= 4 \\
\end{eqnarray}
$$

#### Passi dell'algoritmo

$$
\begin{eqnarray}
\text{Step 1} & \rightarrow & {c_1}^2 = 9 = v_1 \\
\text{Step 2} & \rightarrow & {c_2}^2 = 16 = v_2 \\
\text{Step 3} & \rightarrow & v_1 + v_2 = 25 = v_3 \\
\text{Step 4} & \rightarrow & \sqrt{v_3} = 5 = v_4
\end{eqnarray}
$$

Il risultato è $v_4 = 5$.

## 2.4 - Caratteristiche degli algoritmi risolutivi

Un algoritmo è contraddistinto da cinque caratteristiche principali.

1. _finitezza_: gli algoritmi sono _finiti_, sia dal punto di vista _spaziale_, sia da quello _temporale_;
2. _generalità_: gli algoritmi sono _generici_, ovvero rappresentano una soluzione ad un'intera classe di problemi;
3. _completezza_: gli algoritmi sono _completi_, e quindi possono risolvere tutte le istanze del problema;
4. _non ambiguità_: gli algoritmi _non sono ambigui_, e ciò comporta che tutte le istruzioni sono univoche e ben interpretabili;
5. _eseguibilità_: gli algoritmi sono _eseguibili_, nel senso che l'esecutore deve (potenzialmente) essere in grado di eseguire ogni singolo passo dell'algoritmo.

Tornando al nostro esempio, il metodo di individuazione dell'ipotenusa rispetta le condizioni perchè:

1. può essere risolto in un numero di passi finito, che non occupa uno spazio (ad esempio su carta o nella memoria di un computer) infinito;
2. può risolvere ogni problema di determinazione dell'ipotenusa, anche cambiando i valori dei cateti (a patto ovviamente che si tratti sempre di un triangolo rettangolo, e che quindi si sia nell'ambito della stessa classe dei problemi);
3. le istruzioni sono chiare e non equivocabili;
4. le istruzioni possono essere eseguite da chiunque sia in grado di calcolare un quadrato ed una radice quadrata.

### 2.4.1 Determinismo

Un algoritmo si dice _deterministico_ quando al momento dell'esecuzione di ogni istruzione è nota l'istruzione successiva. Ciò comporta che eseguire due volte un algoritmo deterministico sugli stessi dati produce gli stessi effetti. L'algoritmo di esempio è a tutti gli effetti un algoritmo deterministico.

Gli algoritmi non deterministici sono invece affetti da fenomeni di tipo casuale, o stocastico; sono in genere algoritmi avanzati, usati perlopiù in applicazioni di statistica e machine learning, che non tratteremo durante questo corso.

### 2.4.2 Input, Output e Variabili

Generalmente, i dati in ingresso ad un algoritmo sono anche chiamati _input_ dell'algoritmo, mentre la "risposta" che restituisce l'algoritmo stesso è chiamata _output_.

E' importante sottolineare come gli algoritmi possano accettare sia input sia output _anche non numerici_.

Un esempio è dato dall'algoritmo per determinare se una stringa è palindroma: questo accetta come dati una serie di caratteri, e dà una risposta di tipo binario (VERO o FALSO).

Oltre ad input ed output, gli algoritmi spesso utilizzano dei dati di _supporto_, chiamati _variabili_. Ne tratteremo molto più estesamente durante il prosieguo del corso.
