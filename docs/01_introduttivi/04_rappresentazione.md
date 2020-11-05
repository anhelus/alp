## Rappresentare il mondo in forma binaria

Le informazioni contenute all'interno di un calcolatore, siano esse dati o istruzioni, sono rappresentate in forma *binaria* come sequenze finite di simboli `0` ed `1`. Questa notazione permette di definire una delle nozioni fondamentali su cui è basata l'informatica, ovvero quella di *bit*, contrazione di *binary digit* (cifra binaria):

!!! quote "Bit"
	*Il bit è l'unità di informazione fondamentale interpretabile da un calcolatore, e può assumere valori `0` (falso) o `1` (vero).*

![byte](../assets/images/04_rappresentazione/byte.png){: align=center }

Conseguentemente, è possibile definire un'altra nozione fondamentale, ovvero quella di *byte*, associata ad una sequenza (arbitraria) di otto bit. E' facile verificare che un byte può assumere uno tra $2^8$ possibili valori.

Definiamo infine una *parola*, o *word*, una sequenza di $N$ byte, con $N$ dipendente dal contesto specifico (ad esempio, il tipo di processore in uso).

## I dati numerici

### Rappresentazione di numeri interi

#### Finitezza

I calcolatori sono dispositivi *reali*, ed in grado quindi di elaborare esclusivamente informazioni *finite*; più nello specifico, laddove il mondo reale è *analogico*, e quindi *continuo*, il mondo "comprensibile" dai calcolatori è *digitale*, e quindi è una versione *discretizzata* del mondo reale.

Ciò comporta che, parlando di numeri interi rappresentabili in un calcolatore, si sta in realtà parlando di un'approssimazione finita dell'insieme dei numeri naturali $\mathbb{N}$: l'estensione di questa rappresentazione dipende dall'architettura del calcolatore. Ad esempio, la maggior parte dei calcolatori odierni accetta come limite massimo il valore di $2^64$, pari $18.446.744.073.709.551.616$ (abbastanza per rappresentare il numero massimo di amici che potete avere su Facebook, plausibilmente).

#### Da decimale a binario

Siamo abituati a pensare (ed usare) i numeri interi usando una notazione di tipo *decimale* e *posizionale*. Ciò significa che:

* utilizziamo i simboli compresi tra $0$ e $9$ per rappresentare ogni numero intero;
* sfruttiamo la posizione in cui compare ciascun simbolo per interpretare il valore finale del numero.

Per fare un esempio, i numeri $12$ e $21$ sono rappresentati usando gli stessi simboli decimali, ovvero $1$ e $2$; tuttavia, la loro disposizione è differente, per cui non hanno lo stesso significato.

##### Un esempio

In generale, sia $N$ un generico numero intero composto da $n$ simboli. Usando la notazione decimale e posizionale è possibile esprimerlo come segue:

$$
N = a_n a_{n-1} a_{n-2} ... a_2 a_1 a_0
$$

Esprimendo $N$ in base $b$:

$$
N_b = a_n * b^n + a_{n-1} * b^{n-1} + ... + a_1 * b + a_0
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

Notiamo che la prima cifra che otteniamo è indicata con il termine *LSB*, acronimo che sta per *Least Significant Bit*; questo è il bit meno significativo, ovvero quello "meno rilevante" rispetto al valore finale, ed è posizionato più a destra nella rappresentazione. Di converso, il primo valore è chiamato *MSB*, acronimo che sta per *Most Significant Bit* (e che è ovviamente il bit più significativo).

#### Segno

E' importante ricordare che i numeri interi possono essere dotati di segno; questo è, ovviamente, un fattore di cui va tenuto conto nella rappresentazione del numero stesso, ed è legato al fatto che il calcolatore può contenere solo un quantitativo finito di infomrazione.

Immaginiamo infatti che il computer utilizzi una word di $W$ bit per memorizzare gli interi; ciò significa che sarà possibile memorizzare *al più* $2^W$ valori. Nel caso si considerino tutti i valori positivi (includendo nel conteggio "per convenzione" anche lo $0$), il calcolatore potrà rappresentare tutti i numeri che vanno da $0$ a $2^W-1$.

Questa situazione, però, cambia nel caso si voglia considerare il segno del numero. Infatti, supponendo di suddividere l'intervallo considerato in valori negativi e valori positivi, il calcolatore sarà in grado di rappresentare sempre $2^W$ valori, ma metà di questi saranno negativi, mentre l'altra metà sarà composta da valori positivi. Ciò ha come diretta conseguenza il fatto che il range dei numeri rappresentati varia da $-2^{W-1}$ a $2^{W-1}-1$.

Per fare un esempio pratico, supponendo un valore di $W = 8$, avremo che:

* se consideriamo solo gli interi positivi, potremo rappresentare tutti i numeri interi compresi tra $0$ e $255 = 2^8-1$;
* se consideriamo anche i valori negativi, potremo rappresentare tutti i numeri interi compresi tra $-128 = -2^{W-1}$ e $127 = -2^{W-1}-1$.

### Rappresentazione di numeri reali

Così come per l'insieme dei numeri naturali, anche quello dei numeri reali $\mathbb{R}$ può essere rappresentato all'interno di un calcolatore esclusivamente mediante un'approssimazione finita. Per trovare quest'approssimazione, occorre considerare che ogni numero reale è composto da una parte *intera* $r$ ed una parte *frazionaria* $f$.

#### Rappresentazione a virgola fissa

Supponiamo di avere a disposizione parole composte da $W$ bit. Nella rappresentazione a virgola fissa (o *fixed point*) di un numero $N$, usiamo un numero fisso di bit (ovvero $W_r$) per la parte intera di $N$, ed i rimanenti bit ($W_f$) per la rappresentazione della parte frazionaria. Ovviamente, questa rappresentazione ha lo svantaggio di essere poco flessibile, e le viene spesso preferita quella a *virgola mobile*.

#### Rappresentazione a virgola mobile

La modalità di rappresentazione di un numero reale maggiormente diffusa è quella a *virgola mobile* (*floating point*), che si basa sui concetti di *mantissa*, ovvero la *parte frazionaria* di un numero, e *caratteristica*, o *esponente*.

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

Anche i caratteri (ovvero quelli che troviamo normalmente sulle nostre tastiere) possono essere rappresentati in binario. Più in generale, il concetto di "carattere" è assimilabile a quello di *simbolo*, in quanto i calcolatori sono in grado di comprendere simboli che indicano, tra le altre cose, le cifre decimali, la punteggiatura, ed una vasta serie di caratteri speciali (ad esempio, l'underscore, la "chiocciola", e via dicendo).

L'enorme varietà di caratteri ha portato alla necessità di uniformarne la rappresentazione, creando una corrispondenza biunivoca tra ogni carattere ed un numero intero. Tale corrispondenza è stabilita da *standard* ben precisi, tra i quali vale la pena di ricordare lo standard ASCII e quello UNICODE. Quest'ultimo è particolarmente potente (ed esteso), in quanto permette di codificare la maggior parte dei caratteri conosciuti, compresi quelli di alcune lingue ormai considerate morte (come ad esempio il greco antico).

!!! note "Curiosità"
	Complessivamente, lo standard UNICODE è in grado di rappresentare più di diecimila caratteri. Essendo però codificato a sedici bit, vi è spazio ancora per un bel po' di lingue morte.