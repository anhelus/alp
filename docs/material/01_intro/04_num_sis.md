# 1.4 - Sistemi di numerazione

Nella [precedente lezione](03_dig_an.md) abbiamo visto la differenza tra codifica analogica e digitale, ma non abbiamo parlato di un aspetto fondamentale, ovvero del sistema da utilizzare, nei fatti, per rappresentare le nostre informazioni.

Per introdurre questo aspetto, dovremo dare un'ulteriore definizione di informazione, stavolta in relazione al concetto di *messaggio* definito all'interno di un *linguaggio*. 

##### Messaggi, linguaggi ed informazione

Formalmente, il messaggio è una delle possibili combinazioni dei simboli appartenenti ad un certo linguaggio: per esempio, tutte le frasi che trovate in queste dispense sono dei messaggi, appartenenti (si spera!) ad un insieme di regole sintattiche e semantiche definite come "linguaggio italiano". L'informazione può quindi essere definita come la *misura dell'ampiezza della classe* alla quale appaprtiene un dato messaggio.

La definizione è un po' criptica, quindi cerchiamo di spiegarla tramite un esempio. Consideriamo un messaggio del tipo *XXXX*, con *X* uno dei simboli dell'alfabeto anglosassone, ovvero quello composto da $26$ caratteri. Possibili messaggi di questo tipo sono quindi *CIAO*, *OKAY*, *CARA*, *VELA*, e via discorrendo. Ciò implica che il numero di *possibili combinazioni* sarà dato dal numero di possibili caratteri ($26$) elevato per il numero di caratteri contenuti nel messaggio ($4$). L'informazione sarà *esattamente questo valore*, ovvero $26^4$.

!!!tip "Significato delle possibili combinazioni"
    Ovviamente, non tutte le combinazioni possibili avranno un senso compiuto.

##### Misurare l'informazione

L'informazione viene comunemente misurata in *bit*. Questa parola è in realtà una crasi delle parole *binary* e *digit*; di conseguenza, ci torneremo quando parleremo della codifica binaria.

Per adesso, ci basti sapere che il numero di informazione associato ad ogni messaggio è dato, per convenzione, dal logaritmo in base $2$ dell'ampiezza della classe dei messaggi. In altre parole, per il caso precedente:

$$
Informazione = \log_{2} 26^4
$$

Facciamo un esempio. Sia dato un messaggio di tipo *XXYYY*, con *X* simbolo dell'alfabeto anglosassone, ed *Y* simbolo numerico. In questo caso, l'informazione totale sarà data da:

$$
Informazione = 26 \cdot 26 \cdot 10 \cdot 10 \cdot 10 = 26^2 \cdot 10^3
$$

La misura in bit di questa informazione sarà quindi:

$$
Informazione_{bit} = \log_2 (26^2 \cdot 10^3)
$$

## Codificare numeri

Dopo aver definito il concetto di informazione in relazione a quello di messaggio, ed aver visto come calcolarne il contributo in bit, possiamo introdurre i sistemi di numerazione che, come suggerisce la parola stessa, altro non sono se non degli *schemi* per la *codifica di numeri*. Semplice.

Per asservire a questo scopo, un sistema di numerazione deve avere alcune caratteristiche e proprietà, ovvero essere definito da:

* *cifre*, per rappresentare i numeri;
* *regole*, da applicare per costruire e combinare numeri.

Sulla base di queste definizioni, è possibile definire due categorie di sistemi di numerazione.

##### Sistemi addizionali

Nei sistemi addizionali, ogni simbolo ha un valore fisso, indipendentemente dalla posizione che occupa.

Un esempio classico di sistema di numerazione addizionale è quello *romano*. In particolare, in questo sistema a sette simboli (che ricordiamo essere $I=5,V=5,X=10,L=50,C=100,M=1000$), il valore di ciascun simbolo viene sempre sommato a quello alla sua destra, a patto che quest'ultimo sia minore o uguale. Ad esempio:

$$
XV = 10 + 5
$$

o ancora:

$$
XVII = 10 + 5 + 1 + 1
$$

Ovviamente, non abbiamo considerato l'eventualità in cui il simbolo alla destra sia *maggiore*. In questo caso, avverrà una sottrazione (o, equivalentemente, un'addizione, ma considerando il simbolo a sinistra cambiato di segno). Ad esempio:


$$
XC = -10 + 100
$$

Combinando i due concetti:

$$
XCV = -10 + 100 + 5
$$

##### Sistemi posizionali

Nei sistemi *posizionali*, invece, il valore di ogni cifra dipende dalla sua posizione all'interno del numero. In pratica, ad ogni posizione è associato un certo "peso", che aumenta partendo da destra ed andando verso sinistra. Ogni numero, inoltre, è associato ad una base $b$, la quale verrà utilizzata per stabilire il "peso" da utilizzare nella valutazione complessiva della cifra.

Facciamo un esempio considerando il classico sistema decimale. Possiamo esprimere il numero $123$ come:

$$
123 = 1 \cdot 100 + 2 \cdot 10 + 3 \cdot 1
$$

ovvero:

$$
123 = 1 \cdot 10^2 + 2 \cdot 10^1 + 3 \cdot 10^0
$$

Ancora:

$$
52 = 5 \cdot 10 + 2 \cdot 1 = 5 \cdot 10^1 + 2 \cdot 10^0
$$

In questo caso, dato che stiamo parlando del sistema di numerazione *decimale*, la base $b$ sarà pari a $10$.

In linea generale, la formulazione di un numero posizionale $N$ ad $m$ cifre espresso in base $b$ è data dalla seguente:

$$
N = c_{m-1} \cdot b^{m-1} + c_{m-2} \cdot b^{m-2} + \ldots + c_1 \cdot b^1 + c_0 \cdot b^0
$$

dove $c_{m-1}, c_{m-2}, \ldots, c_0$ sono i coefficienti associati a ciascuna delle cifre presenti nel numero.

Il sistema di numerazione correntemente usato, come i lettori più attenti avranno avuto modo di intuire, è un sistema di numerazione posizionale in base decimale. Nella [prossima lezione](05_sis_bin.md) vedremo come il sistema più usato in informatica sia quello *binario*.
