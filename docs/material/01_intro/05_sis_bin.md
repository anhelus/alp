# 1.5 - Sistema binario

Nella [precedente lezione](04_num_sis.md) abbiamo introdotto il concetto di sistema di numerazione, parlando in maniera approfondita di sistema addizionale e sistema posizionale, facendo quindi l'esempio di numeri romani ed arabi, rispettivamente.

!!!warning "Numeri arabi"
    Prima di "aiutarli a casa loro", ricordiamoci sempre che l'intera scienza moderna si basa su una simbologia che non abbiamo inventato noi europei.

##### Perché binario?

Adesso, posto che abbiamo messo un punto sul fatto che, per far gestire informazione al nostro calcolatore, dovremo utilizzare un sistema numerico, ci interessa trovare quello che, in qualche modo, sia il più vicino possibile al funzionamento fisico dell'elaboratore. Di conseguenza, dobbiamo proprio ppartire da quest'ultimo: *cosa è, quindi, un elaboratore?*

Detto nella maniera più semplice possibile, un elaboratore è un insieme di circuiti elettrici che, organizzati in maniera opportuna, fanno scorrere della corrente in maniera tale da trasformare un input in un output. Semplice, giusto? Beh, non proprio: questi "circuiti" sono di dimensione nanometrica, e ve ne sono miliardi per ogni singolo processore. Tuttavia, il funzionamento è sempre lo stesso: ognuno di questi circuiti viene governato da degli interruttori, chiamati *transistor*, che possono essere *aperti* (e, quindi, senza passaggio di corrente al loro interno) o *chiusi* (e che quindi permettono il passaggio di corrente). Dato che il funzionamento del processore è legato a due differenti situazioni (aperto e chiuso), avremo bisogno di un sistema di numerazione in grado di modellare proprio questi due stati, ovvero il *sistema binario*.

## Caratteristiche del sistema binario

Il sistema di numerazione binario è basato sulla base $2$, ovvero quella più piccola possibile. Essendo la base pari a $2$, saranno permesse soltanto due cifre, ovvero $0$ ed $1$.

!!!tip "Sistema binario e bit"
    Se ricordate, abbiamo in precedenza introdotto il concetto di *bit*, affermando fosse una crasi di *binary* e *digit*, ovvero *cifra binaria*. Ecco spiegato il motivo.

Il sistema binario presenta quindi il vantaggio fondamentale di permettere di stabilire, in maniera relativamente semplice, una *corrispondenza biunivoca* con i possibili stati di funzionamento dei circuiti elettrici ed elettronici. Ciò viene tuttavia al costo di una maggiore complessità, dato che è necessario utilizzare un numero di cifre più elevato per rappresentare lo stesso numero. Ad esempio, per rappresentare un numero a $2$ cifre decimali, ovvero tutti quelli compresi tra $10$ e $99$, sono necessarie da $3$ a $7$ cifre binarie, ovvero quelle che servono a rappresentare i numeri compresi tra $8$ (che è pari a $2^3$) fino a $128$ (che è pari a $2^7$).

## Conversioni di base

L'esempio legato alla diversa complessità della rappresentazione di un dato numero in sistemi differenti ci permette di introdurre il concetto di *conversione di base*. I numeri, infatti, sono concetti astratti, rappresentabili in modo equivalente in qualsiasi base di numerazione, a seconda di quanti simboli possono essere tra loro combinati; la conversione di base è l'operazione matematica con cui si passa da una base di numerazione adll'altra.

### Conversione da decimale a base $B$

##### Numeri interi

In generale, la conversione di un numero intero $N$ da decimale (ovvero base $10$) ad una certa base $B$ avviene dividendo ripetutamente $N$ per $B$, fino ad ottenere un quoziente $0$, e recuperando i resti in ordine inverso alla loro determinazione. Complicato, giusto? Non proprio.

Facciamo un esempio con base $2$: dovremo dividere ripetutamente il numero $N$ per $2$, fermandoci soltanto quando otteniamo un quoziente nullo. A quel punto, prenderemo (in ordine inverso) i resti delle divisioni effettuate, con le quali formeremo il numero convertito. Quindi, se $N=10$:

| Valore diviso | Base | Quoziente | Resto |
| ------------- | ---- | --------- | ----- |
| $10$          | $2$  | $5$       | $0$   |
| $5$           | $2$  | $2$       | $1$   |
| $2$           | $2$  | $1$       | $0$   |
| $1$           | $2$  | $0$       | $1$   |

In base alla tabella precedente, ed alla regola che abbiamo definito, il risultato della conversione è dato da $1010$.

##### Numeri frazionari

Gli stessi principi si applicano ai numeri frazionari. In questi casi, è necessario moltiplicare ripetutamente la parte frazionaria per la base $B$, e considerare il risultato $P$ di questo prodotto. In particolare, $P$ avrà una parte intera (che chiameremo *P.I.*) ed una parte frazionaria (che chiameremo *P.F.*); ai nostri scopi, continueremo a moltiplicare fino a che non otterremo una P.F. pari a $0$, e considereremo come risultato della conversione le parti intere prese nell'ordine di moltiplicazione. Ad esempio:

| Valore moltiplicato | Base | Prodotto | P.I. | P.F. |
| ----------------- | ---- | -------- | ---- | ---- |
| $0.25$            | $2$  | $0.5$    | $0$  | $5$  |
| $0.5$             | $2$  | $1$      | $1$  | $0$  | 

In questo caso, la rappresentazione in binario di $0.25$ sarà quindi $01$. Di conseguenza, se volessimo rappresentare in binario $10.25$, dovremmo scrivere $1010.01$.

Esiste, per i numeri frazionari, anche la possibilità di trovarsi davanti a rappresentazioni in cui la conversione *non converge*, ovvero continua all'infinito. Ad esempio:

| Valore moltiplicato | Base | Prodotto | P.I. | P.F. |
| ----------------- | ---- | -------- | ---- | ---- |
| $0.6$             | $2$  | $1.2$    | $1$  | $2$  |
| $0.2$             | $2$  | $0.4$    | $0$  | $4$  |
| $0.4$             | $2$  | $0.8$    | $0$  | $8$  |
| $0.8$             | $2$  | $1.6$    | $0$  | $4$  |
| $0.6$             | $2$  | $1.2$    | $1$  | $2$  |

Notiamo due cose:

1. quando il prodotto ha una parte intera superiore ad $1$, questa andrà riportata a zero nella moltiplicazione successiva;
2. potremmo continuare ad effettuare un numero indefinito di moltiplicazioni, e non convergeremmo *mai*.

In quest'ultimo caso, quindi, dovremo imporre un'ulteriore condizione, ovvero quella relativa al *numero massimo di bit da utilizzare*, giunti al quale termineremo l'operazione di conversione, approssimando il risultato ottenuto. Nel nostro caso, volendo usare una rappresentazione a $9$ bit, $10.6$ sarà dato da $1010.10001$.

## Bit, byte e word

Abbiamo già visto una rappresentazione *informale* di bit, come componente "fondamentale" dell'informazione. In maniera più formale, possiamo adesso darne una definizione.

!!!quote "Il Bit"
    Il **bit** è l'unità di informazione fondamentale interpretabile da un calcolatore, e può assumere valori $0$ (interpretabile come *falso*, o *circuito aperto*) o $1$ (interpretabile come *vero*, o *circuito chiuso*).

Dalla definizione di bit segue quella (altrettanto importante) di *byte*, comunemente associata ad una sequenza di valori binari arbitrari ma con lunghezza pari ad otto bit.

!!!tip "I valori del byte"
    Quanti sono i valori che è possibile rappresentare mediante un byte? Per rispondere alla domanda, riprendiamo le nozioni viste quando abbiamo parlato di informazione. In particolare, sappiamo che una sequenza di $K$ bit può rappresentare al più $2^K$ combinazioni di bit; quindi, se $K=8$, allora potremo rappresentare al più $2^8=256$ valori.

Possiamo infine definire come *word* (parola) una sequenza di $N$ byte, con $N$ dipendente da fattori contestuali, come il tipo di processore utilizzato. Ad esempio, i processori dei nostri PC sono in grado di gestire parole ad otto byte, ovvero $64$ bit. Ciò influenza il numero di valori che può essere gestito dal processore: vedremo questo argomento maggiormente nel dettaglio nella [prossima lezione](06_data_types.md).
