# 2 - Rappresentazione dell'informazione

## 2.1 - Messaggi ed informazione

<!-- NOTA: manca il contesto per il quale sto introducendo questa informazione. -->

Nel linguaggio comune, il termine *informazione* è spesso usato come sinonimo di *messaggio*, il che in pratica è una *combinazione* di diversi simboli.

Formalmente, invece, l'informazione è una *metrica* che misura *l'ampiezza della classe dei messaggi alla quale appartiene un dato messaggio*.

Consideriamo, ad esempio, un messaggio composto da quattro caratteri, ciascuno dei quali può essere associato ad uno dei simboli dell'alfabeto standard anglosassone, il quale (ricordiamo) essere composto da 26 simboli. In questo caso, l'informazione sarà data dalla *cardinalità dell'insieme dei messaggi formati da quattro simboli appartenenti all'alfabeto anglosassone*.

Ciò significa che messaggi come *CIAO*, *OTTO*, *ANNA*, sono validi, e l'informazione è pari a $26^4$, ovvero tutti i possibili messaggi che è possibile creare.

## 2.2 Sistema di numerazione

Un sistema di numerazione è uno schema utilizzato per codificare dei numeri. Tale sistema è definito mediante *cifre* (che, concettualmente, possiamo consdierare come equivalenti ad un alfabeto), e *regole* da applicare per costruire i numeri. Ne esistono di due categorie: *addizionali* e *posizionali*.

### Sistemi addizionali

Nei sistemi *addizionali*, ogni simbolo ha un valore fisso indipendente dalla posizione che occupa.

##### Un esempio di sistema addizionale: l'alfabeto romano

Un esempio abbastanza conosciuto di sistema addizionale è l'*alfabeto romano*. In questo alfabeto, infatti, sono ammesse le seguenti cifre:

| Cifra | Valore odierno |
| ----- | -------------- |
| I | 1 |
| V | 5 |
| X | 10 |
| L | 50 |
| C | 100 |
| D | 500 |
| M | 1000 |

La regola per l'interpretazione è invece la seguente: *il valore di ciascun simbolo viene sommato se alla sua destra compare un simbolo di valore inferiore o uguale (o se è l'ultimo), altrimenti viene sottratto*.

Ad esempio:

$$
DCXXII \rightarrow 500 + 100 + 10 + 10 + 2 = 622 \\
CMV \rightarrow 1000 - 100 + 50 = 950
$$

### Sistemi posizionali

Nei sistemi posizionali il valore di ogni cifra dipende dalla sua posizione all'interno del numero. In particolare:

* ad ogni posizione è associato un certo peso;
* le posizioni si contano da destra verso sinistra, partendo da $0$;
* il valore della cifra viene moltiplicato per la base $b$ elevata alla posizione.

In sostanza, un numero $N$ ad $n$ cifre è rappresentato come:

$$
N = c_{n-1} \cdot b^{n-1} + c_{n-2} \cdot b^{n-2} + \cdots + c_{1} \cdot b^{1} + c_{0} \cdot b^{0}
$$

Nell'equazione precedente, $c$ rappresenta la cifra, mentre $n$ rappresenta il numero di cifre associato alla parte intera. Inoltre, $c_{n-1}$ è detta *cifra più significativa*, mentre $c_0$ è la *cifra meno significativa*.

Ad esempio, dato $N = 705$, e $b = 10$, allora:

\begin{align}
c_2 = 7, c_1 = 0, c_0 = 5 \Rightarrow \\
\Rightarrow 705 = 7 \cdot 10^2 + 0 \cdot 10^1 + 5 \cdot 10^0
\end{align}

Questa relazione ci permette di definire quindi la *forma polinomiale* di un numero, e può essere estesa alla parte frazionaria come:

$$
(.c_{-1} \cdots c_{-m}) = c_{-1} \cdot b^{-1} + \cdots + c_{-m} \cdot b^{-m}
$$

Combinando i due concetti, un numero reale può essere espresso come:

$$
(c_{n-1} \cdots c_0.c_{-1} \cdots c_{-m})_b = c_0 \cdot b^0 + \cdots + c_{n-1} \cdot b^{n-1} + \cdots + c_{-m} \cdot b^{-m}
$$

### Il sistema binario

Il *sistema binario* è caratterizzato dal valore di $b=2$, ed è il sistema di numerazione con la più piccola base possibile, in cui le due cifre ammesse sono esclusivamente $0$ ed $1$.

!!!tip
    Si potrebbe pensare di usare un ipotetico sistema unario il quale, tuttavia, sarebbe di poca utilità, in quanto definito soltanto da un simbolo.

Il vantaggio di un sistema di questo tipo appare evidente: infatti, la presenza di un numero limitato di simboli fondamentali, ovvero esclusivamente $0$ ed $1$, permette di stabilire una corrispondenza biunivoca con i soli due stati di funzionamento dei circuiti elettronici, ovvero *spento* e *acceso*. Lo svantaggio, tuttavia, risiede nel fatto che è necessario utilizzare un maggior numero di cifre per rappresentare un dato numero.

## 2.3 - Il concetto di bit

La quantità di informazione viene misurata in *bit*, crasi che proviene dall'inglese *binary digit*, ovvero cifra binaria. In altri termini, il bit rappresenta la *quantità minima di informazione* che è possibile trasmettere.

Ogni messaggio, di conseguenza, porta al suo interno un certo numero di bit, dato per convenzione dal logaritmo in base 2 della cardinalità della classe dei messaggi disponibili.

In altre parole, una sequenza ordinata di $n$ numeri binari può rappresentare uno fra $2^n$ cifre diverse; ciò è dato dal fatto che i possibili simboli sono $2$, mentre la lunghezza della sequenza è $n$. Di conseguenza, l'informazione associata a questa sequenza sarà pari proprio ad $n$ bit.

### Esempi

Consideriamo in primis un messaggio del tipo $XXYY$, dove $XX$ è un simbolo dell'alfabeto anglosassone, mentre $Y$ è una cifra in base $10$. Allora, il computo totale dell'informazione $I$ sarà dato da:

$$
I = (26)^2 \cdot (10)^2 = 676 \cdot 100
$$

Per ottenere il valore corrispondente dell'informazione misurato in bit, dovremo calcolarne il logaritmo in base $2$.

$$
I_{bit} = \log_{2}(67600)
$$