# 2. Il mondo in forma binaria

## 2.1 Le informazioni nel mondo reale

Nel mondo reale, le informazioni fluiscono dalla sorgente al destinatario sotto forma di onde _analogiche_. Per capirci, pensiamo ad una conversazione tra due persone: entrambe produrranno, mediante il loro apparato fonatorio, delle onde sonore, _continue_ sia nel tempo che nelle ampiezze, che arriveranno all'orecchio dell'altro interlocutore, il quale le passerà al cervello che, a sua volta, le interpreterà.

Di particolare importanza è il concetto di _continuità_ della forma d'onda utilizzata. Partiamo dall'analisi matematica: sappiamo che le funzioni continue sono definite nel dominio $\mathbb{R}$ dei numeri reali, per cui assumono, a meno dei punti di discontinuità, un numero _infinito_ di valori. Questo vale anche per le forme d'onda analogiche, che abbiamo detto essere continue: ogni onda sonora emessa nella conversazione di cui sopra potrà assumere un numero "infinito" di valori all'interno degli intervalli temporali e di ampiezza nei quali è emessa.

!!!note "Nota"
Ovviamente, non teniamo conto di effetti quantistici: stiamo parlando di fenomeni _macroscopici_.

## 2.2 La gestione dell'informazione

Chiarito il concetto di grandezza "analogica", pensiamo adesso a come uno strumento potrebbe in qualche modo caratterizzarla. In particolare, ragioniamo in termini di _capacità_ dello strumento, ovvero:

> \*Quanti stati deve essere in grado di rappresentare contemporaneamente un sistema per caratterizzare completamente una forma d'onda analogica?"

Beh, la risposta a questa domanda è semplice: _infiniti_. Ovviamente, una realizzazione pratica di questa macchina non esiste, né può essere realizzata con le tecnologie attuali.

Occorre quindi ridurre il numero di stati che devono essere rappresentati contemporaneamente. Per farlo, dobbiamo passare dal dominio analogico a quello _digitale_.

## 2.3 La rappresentazione digitale dell'informazione

Il dominio digitale è semplice da caratterizzare: infatti, l'informazione può assumere soltanto due possibili valori, ovvero $0$ ed $1$ (chiamati alle volte anche _basso_ ed _alto_, o anche _spento_ ed _acceso_).

Appare chiaro come una rappresentazione digitale, o anche _binaria_, sia molto più facile da gestire per un calcolatore rispetto ad una rappresentazione analogica. Ed è per questo che è importante definire la nozione fondamentale su cui è basata l'intera informatica, ovvero _bit_, crasi di _binary digit_ (traducibile dall'inglese come _cifra binaria_):

!!! quote "Bit"
_Il bit è l'unità di informazione fondamentale interpretabile da un calcolatore, e può assumere valori `0` (falso) o `1` (vero)._

![byte](../../assets/images/04_rappresentazione/byte.png){: align=center }

Conseguentemente, è possibile definire un'altra nozione fondamentale, ovvero quella di _byte_, associata ad una sequenza (arbitraria) di otto bit. E' facile verificare che un byte può assumere uno tra $2^8$ possibili valori.

Definiamo infine una _parola_, o _word_, una sequenza di $N$ byte, con $N$ dipendente dal contesto specifico (ad esempio, il tipo di processore in uso).

## I dati numerici

### Rappresentazione di numeri interi

#### Finitezza

I calcolatori sono dispositivi _reali_, ed in grado quindi di elaborare esclusivamente informazioni _finite_; più nello specifico, laddove il mondo reale è _analogico_, e quindi _continuo_, il mondo "comprensibile" dai calcolatori è _digitale_, e quindi è una versione _discretizzata_ del mondo reale.

Ciò comporta che, parlando di numeri interi rappresentabili in un calcolatore, si sta in realtà parlando di un'approssimazione finita dell'insieme dei numeri naturali $\mathbb{N}$: l'estensione di questa rappresentazione dipende dall'architettura del calcolatore. Ad esempio, la maggior parte dei calcolatori odierni accetta come limite massimo il valore di $2^64$, pari $18.446.744.073.709.551.616$ (abbastanza per rappresentare il numero massimo di amici che potete avere su Facebook, plausibilmente).

#### Da decimale a binario

Siamo abituati a pensare (ed usare) i numeri interi usando una notazione di tipo _decimale_ e _posizionale_. Ciò significa che:

- utilizziamo i simboli compresi tra $0$ e $9$ per rappresentare ogni numero intero;
- sfruttiamo la posizione in cui compare ciascun simbolo per interpretare il valore finale del numero.

Per fare un esempio, i numeri $12$ e $21$ sono rappresentati usando gli stessi simboli decimali, ovvero $1$ e $2$; tuttavia, la loro disposizione è differente, per cui non hanno lo stesso significato.

##### Un esempio

In generale, sia $N$ un generico numero intero composto da $n$ simboli. Usando la notazione decimale e posizionale è possibile esprimerlo come segue:

$$
N = a_n a_{n-1} a_{n-2} ... a_2 a_1 a_0
$$

Esprimendo $N$ in base $b$:

$$
N_b = a_n *b^n + a_{n-1}* b^{n-1} + ... + a_1 * b + a_0
$$

Per fare un semplice esempio:

$$
N = 485_{10} = (4 * 10^2 + 8 * 10 + 5)_{10}
$$

###### Conversione

Supponiamo di voler rappresentare $N = 485$ in forma binaria (ovvero in base $2$). Dovremo procedere dividendo $N$ per la nostra base $b = 2$, valutare il resto $r$, che sarà di volta in volta il valore meno significativo del nostro numero in forma binaria, e reiterare l'operazione usando il quoziente $q$.

Otteniamo quindi:

$$
\begin{eqnarray}
485/2 &\Rightarrow q = 242 & r = 1 & \Rightarrow LSB\\
242/2 &\Rightarrow q = 121 & r = 0 \\
121/2 &\Rightarrow q = 60 & r = 1 \\
60/2 &\Rightarrow q = 30 & r = 0 \\
30/2 &\Rightarrow q = 15 & r = 0 \\
15/2 &\Rightarrow q = 7 & r = 1 \\
7/2 &\Rightarrow q = 3 & r = 1 \\
3/2 &\Rightarrow q = 1 & r = 1 \\
1/2 &\Rightarrow q = 0 & r = 1 & \Rightarrow MSB
\end{eqnarray}
$$

Il valore di $N$ in forma binaria è quindi dato da:

$$
N_{2} = (111100101)_2
$$

Notiamo che la prima cifra che otteniamo è indicata con il termine _LSB_, acronimo che sta per _Least Significant Bit_; questo è il bit meno significativo, ovvero quello "meno rilevante" rispetto al valore finale, ed è posizionato più a destra nella rappresentazione. Di converso, il primo valore è chiamato _MSB_, acronimo che sta per _Most Significant Bit_ (e che è ovviamente il bit più significativo).

#### Segno

E' importante ricordare che i numeri interi possono essere dotati di segno; questo è, ovviamente, un fattore di cui va tenuto conto nella rappresentazione del numero stesso, ed è legato al fatto che il calcolatore può contenere solo un quantitativo finito di infomrazione.

Immaginiamo infatti che il computer utilizzi una word di $W$ bit per memorizzare gli interi; ciò significa che sarà possibile memorizzare _al più_ $2^W$ valori. Nel caso si considerino tutti i valori positivi (includendo nel conteggio "per convenzione" anche lo $0$), il calcolatore potrà rappresentare tutti i numeri che vanno da $0$ a $2^W-1$.

Questa situazione, però, cambia nel caso si voglia considerare il segno del numero. Infatti, supponendo di suddividere l'intervallo considerato in valori negativi e valori positivi, il calcolatore sarà in grado di rappresentare sempre $2^W$ valori, ma metà di questi saranno negativi, mentre l'altra metà sarà composta da valori positivi. Ciò ha come diretta conseguenza il fatto che il range dei numeri rappresentati varia da $-2^{W-1}$ a $2^{W-1}-1$.

Per fare un esempio pratico, supponendo un valore di $W = 8$, avremo che:

- se consideriamo solo gli interi positivi, potremo rappresentare tutti i numeri interi compresi tra $0$ e $255 = 2^8-1$;
- se consideriamo anche i valori negativi, potremo rappresentare tutti i numeri interi compresi tra $-128 = -2^{W-1}$ e $127 = -2^{W-1}-1$.

### Rappresentazione di numeri reali

Così come per l'insieme dei numeri naturali, anche quello dei numeri reali $\mathbb{R}$ può essere rappresentato all'interno di un calcolatore esclusivamente mediante un'approssimazione finita. Per trovare quest'approssimazione, occorre considerare che ogni numero reale è composto da una parte _intera_ $r$ ed una parte _frazionaria_ $f$.

#### Rappresentazione a virgola fissa

Supponiamo di avere a disposizione parole composte da $W$ bit. Nella rappresentazione a virgola fissa (o _fixed point_) di un numero $N$, usiamo un numero fisso di bit (ovvero $W_r$) per la parte intera di $N$, ed i rimanenti bit ($W_f$) per la rappresentazione della parte frazionaria. Ovviamente, questa rappresentazione ha lo svantaggio di essere poco flessibile, e le viene spesso preferita quella a _virgola mobile_.

#### Rappresentazione a virgola mobile

La modalità di rappresentazione di un numero reale maggiormente diffusa è quella a _virgola mobile_ (_floating point_), che si basa sui concetti di _mantissa_, ovvero la _parte frazionaria_ di un numero, e _caratteristica_, o _esponente_.

In particolare, la mantissa di un numero reale $n$ è pari al valore del numero diminuito della sua parte intera $n_i$:

$$
M = n - n_i
$$

Ad esempio, la mantissa di $5.2$ è pari a $0.2$. E' facile verificare che la mantissa $M$ è sempre compresa tra $-1$ ed $1$.

Ne consegue che un numero $a$ è rappresentabile in una data base $b$ mediante la seguente relazione:

$$
a = M * b^e
$$

### Rappresentazione di caratteri

Anche i caratteri (ovvero quelli che troviamo normalmente sulle nostre tastiere) possono essere rappresentati in binario. Più in generale, il concetto di "carattere" è assimilabile a quello di _simbolo_, in quanto i calcolatori sono in grado di comprendere simboli che indicano, tra le altre cose, le cifre decimali, la punteggiatura, ed una vasta serie di caratteri speciali (ad esempio, l'underscore, la "chiocciola", e via dicendo).

L'enorme varietà di caratteri ha portato alla necessità di uniformarne la rappresentazione, creando una corrispondenza biunivoca tra ogni carattere ed un numero intero. Tale corrispondenza è stabilita da _standard_ ben precisi, tra i quali vale la pena di ricordare lo standard ASCII e quello UNICODE. Quest'ultimo è particolarmente potente (ed esteso), in quanto permette di codificare la maggior parte dei caratteri conosciuti, compresi quelli di alcune lingue ormai considerate morte (come ad esempio il greco antico).

!!! note "Curiosità"
Complessivamente, lo standard UNICODE è in grado di rappresentare più di diecimila caratteri. Essendo però codificato a sedici bit, vi è spazio ancora per un bel po' di lingue morte.
