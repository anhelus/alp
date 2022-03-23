# 3 - Il mondo in forma binaria

> *Le slides di questa lezione sono disponibili [qui](./slides/03%20-%20Rappresentazione%20binaria%20e%20decimale.pdf)*.

## 3.1 - Le informazioni nel mondo reale

Nel mondo reale, le informazioni fluiscono dalla sorgente al destinatario sotto forma di onde _analogiche_. Per capirci, pensiamo ad una conversazione tra due persone: entrambe produrranno, mediante il loro apparato fonatorio, delle onde sonore, _continue_ sia nel tempo che nelle ampiezze, che arriveranno all'orecchio dell'altro interlocutore, il quale le passerà al cervello che, a sua volta, le interpreterà.

Di particolare importanza è il concetto di _continuità_ della forma d'onda utilizzata. Partiamo dall'analisi matematica: sappiamo che le funzioni continue sono definite nel dominio $\mathbb{R}$ dei numeri reali, per cui assumono, a meno dei punti di discontinuità, un numero _infinito_ di valori. Questo vale anche per le forme d'onda analogiche, che abbiamo detto essere continue: ogni onda sonora emessa nella conversazione di cui sopra potrà assumere un numero "infinito" di valori all'interno degli intervalli temporali e di ampiezza nei quali è emessa.

!!!note "Nota"
    Ovviamente, non teniamo conto di effetti quantistici: stiamo parlando di fenomeni _macroscopici_.

## 3.2 - La gestione dell'informazione

Chiarito il concetto di grandezza "analogica", pensiamo adesso a come uno strumento potrebbe in qualche modo caratterizzarla. In particolare, ragioniamo in termini di _capacità_ dello strumento, ovvero:

> _Quanti stati deve essere in grado di rappresentare contemporaneamente un sistema per caratterizzare completamente una forma d'onda analogica?_

Beh, la risposta a questa domanda è semplice: _infiniti_. Ovviamente, una realizzazione pratica di questa macchina non esiste, né può essere realizzata con le tecnologie attuali.

Occorre quindi ridurre il numero di stati che devono essere rappresentati contemporaneamente. Per farlo, dobbiamo passare dal dominio analogico a quello _digitale_.

## 3.3 - La rappresentazione digitale dell'informazione

Il dominio digitale è semplice da caratterizzare: infatti, l'informazione può assumere soltanto due possibili valori, ovvero $0$ ed $1$ (chiamati alle volte anche _basso_ ed _alto_, o anche _spento_ ed _acceso_).

### 3.3.1 - Il bit

Appare chiaro come una rappresentazione digitale, detta anche _binaria_, sia molto più facile da gestire per un calcolatore rispetto ad una rappresentazione analogica. Ed è per questo che è importante definire la nozione fondamentale su cui è basata l'intera informatica, ovvero _bit_, crasi di _binary digit_ (traducibile dall'inglese come _cifra binaria_):

!!! quote "Bit"
    _Il bit è l'unità di informazione fondamentale interpretabile da un calcolatore, e può assumere valori `0` (falso) o `1` (vero)._

### 3.3.2 - Il byte

Dalla definizione di bit segue quella, altrettanto importante, di _byte_, associata ad una sequenza arbitraria di otto bit.

Quanti sono i possibili valori di un byte?

Per rispondere a questa domanda, ricordiamoci che ogni bit può assumere soltanto due valori; di conseguenza, due bit potranno assumere al massimo $2 \times 2$ valori, ovvero quattro, tre bit $2 \times 2 \times 2$ valori, ovvero otto, e così via.

E' semplice quindi constatare che una sequenza di $n$ bit assume al più $2^n$ valori, per cui otto bit potranno assumere al massimo $2^8$ valori. Ne consegue che, riportando il tutto in decimale, un byte potrà assumere al massimo 256 valori.

### 3.3.3 - La parola

Definiamo infine una _parola_, o _word_, una sequenza di $N$ byte, con $N$ dipendente dal contesto specifico (ad esempio, il tipo di processore in uso). Ad esempio, la maggior parte dei processori consumer odierni utilizza parole da otto byte, ovvero 64 bit, capaci quindi di rappresentare fino a $2^{64}$ valori.

## 3.4 - Da decimale a binario

Nel mondo reale, siamo abituati ad utilizzare i numeri seguendo una notazione di tipo _decimale_ e _posizionale_. Detto in altri termini:

- utilizziamo i simboli compresi tra $0$ e $9$ per rappresentare ogni numero intero;
- sfruttiamo la posizione in cui compare ciascun simbolo per interpretare il valore finale del numero.

Per fare un esempio, i numeri $12$ e $21$ sono rappresentati usando gli stessi simboli decimali, ovvero $1$ e $2$; tuttavia, la loro disposizione è differente, per cui non hanno lo stesso significato.

### 3.4.1 - Espressione formale di un numero in base decimale

Formalmente, se $N \in \mathbb{i}$ è un numero intero composto da $k$ simboli, è possibile esprimerlo come:

$$
N = a_k a_{k-1} a_{k-2} \ldots a_2 a_1 a_0
$$

dove $a_i$ è l'$i$-mo simbolo, con $i \in [1, \ldots, k]$.

Possiamo esprimere $N$ anche in base $10$:

$$
N = a_k * 10^k + a_{k-1} * 10^{k-1} + \ldots + a_1 * 10^1 + a_0 * 10^0
$$

Per fare un semplice esempio:

$$
N = 485 = 4 * 10^2 + 8 * 10 + 5
$$

### 3.4.2 - Da base decimale a base binaria

Ovviamente, l'espressione formale di un numero in base decimale è facilmente adattabile ad altre basi, per cui, in generale, vale che un numero $B$ a $l$ simboli è esprimibile in base $b$ mediante un'espressione del tipo:

$$
B_{b} = a_l * b^l + a_{l-1} * b^{l-1} + \ldots + a_1 * b^1 + a_0 * b^0
$$

Supponiamo adesso di voler convertire un numero $N$ dalla forma decimale a quella binaria. Per farlo, dovremo procedere dividendo $N$ per la base $2$, valutando il resto $r$, e reiterare l'operazione usando il quoziente $q$.

Facciamo un esempio usando $N = 485$.

$$
\begin{eqnarray}
\frac{485}{2} &\Rightarrow q = 242 & r = 1 & \Rightarrow LSB\\
\frac{242}{2} &\Rightarrow q = 121 & r = 0 \\
\frac{121}{2} &\Rightarrow q = 60 & r = 1 \\
\frac{60}{2} &\Rightarrow q = 30 & r = 0 \\
\frac{30}{2} &\Rightarrow q = 15 & r = 0 \\
\frac{15}{2} &\Rightarrow q = 7 & r = 1 \\
\frac{7}{2} &\Rightarrow q = 3 & r = 1 \\
\frac{3}{2} &\Rightarrow q = 1 & r = 1 \\
\frac{1}{2} &\Rightarrow q = 0 & r = 1 & \Rightarrow MSB
\end{eqnarray}
$$

Il valore di $N$ in forma binaria è quindi dato da:

$$
N_{2} = (111100101)_2
$$

Notiamo che la prima cifra che otteniamo è indicata con il termine _LSB_, acronimo che sta per _Least Significant Bit_; questo è il bit meno significativo, ovvero quello "meno rilevante" rispetto al valore finale, ed è posizionato più a destra nella rappresentazione. Di converso, il primo valore è chiamato _MSB_, acronimo che sta per _Most Significant Bit_ (e che è ovviamente il bit più significativo).
