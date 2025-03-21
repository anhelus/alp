# 1.7.3 - Proprietà delle operazioni fondamentali

## Operazioni con $n$ predicati

Nella [lezione precedente](02_ops.md) abbiamo introdotto le operazioni fondamentali dell'algebra booleana. In particolare, abbiamo visto come le operazioni di somma e prodotto logici siano di tipo *binario*, ovvero definite per una coppia di predicati, mentre la negazione sia *unaria*.

Nonostante questo, è possibile estendere le considerazioni fatte per una logica a due variabili ad una ad $n$ variabili. Prendiamo, ad esempio, il seguente predicato composto:

<p style="text-align:center; font-style:italic">
la palla è tonda AND la palla è verde AND la palla è nella scatola
</p>

Questo predicato altro non è se un prodotto logico tra tre predicati semplici e, proprio come nel caso più semplice, sarà vero *se e solo se tutti i predicati sono veri*.

Si può ragionare allo stesso modo per la somma logica. Immaginiamo di avere il predicato composto:

<p style="text-align:center; font-style:italic">
la palla è tonda OR la palla è verde OR la palla è nella scatola
</p>

In questo caso, il predicato composto sarà *sempre* vero, a meno che *tutti* i singoli predicati non siano falsi.

A questo punto è possibile generalizzare la somma ed il prodotto logico come segue. Indicando con $+$ l'operazione di somma logica, e con $\times$ quella di prodotto logico, varranno le seguenti regole.

???+ quote "Somma logica di $n$ variabili indipendenti"

    Date $n$ variabili binarie indipendenti, la loro somma logica è:

    $$
    x_1 + x_2 + \ldots + x_n = \begin{cases}
    1, & \exists x_i = 1, & i \in 1, \ldots, n \\
    0, & \not \exists x_i = 1, & i \in 1, \ldots, n
    \end{cases}
    $$

    In altre parole, il risultato della somma logica di $n$ variabili è pari ad $1$ se almeno una delle $n$ variabili è anch'essa pari ad $1$.

???+ quote "Prodotto logico di $n$ variabili indipendenti"

    Date $n$ variabili binarie indipendenti, il loro prodotto logico è:

    $$
    x_1 \times x_2 \times \ldots \times x_n = \begin{cases}
    0, & \exists x_i = 0, & i \in 1, \ldots, n \\
    1, & x_1 = x_2 = \ldots = x_n
    \end{cases}
    $$

## Proprietà delle operazioni logiche fondamentali

Alle tre operazioni logiche fondamentali sono associate alcune proprietà fondamentali, che richiamano le equivalenti proprietà aritmetiche. In particolare, alle operazioni di $AND$ ed $OR$ sono associate tre diverse proprietà che, come vedremo, sono concettualmente analoghe a quelle definite nell'aritmetica classica.

##### Proprietà commutativa

La prima è la proprietà *commutativa*, per la quale il risultato di somma e prodotto logico rimangono invariati cambiando l'ordine dei singoli predicati. Quindi:

<p style="text-align:center; font-style:italic">
la palla è tonda AND la palla è verde
</p>

equivale a:

<p style="text-align:center; font-style:italic">
la palla è verde AND la palla è tonda
</p>

così come:

<p style="text-align:center; font-style:italic">
la palla è tonda OR la palla è verde
</p>

equivale a:

<p style="text-align:center; font-style:italic">
la palla è verde OR la palla è tonda
</p>

Formalmente, dati due predicati $p_1, p_2$:

$$
\begin{align}
OR \Leftrightarrow p_1 + p_2 = p_2 + p_1 \\
AND \Leftrightarrow p_1 \times p_2 = p_2 \times p_1
\end{align}
$$

???tip "Tabelle della verità"
    Per dimostrare la proprietà commutativa, possiamo usare le tabelle della verità. Per l'operazione di $AND$:
    
    | $p_1$ | $p_2$ | $p_1 \times p_2$ | $p_2 \times p_1$ |
    | ----- | ----- | ---------------- | ---------------- |
    | 0 | 0 | 0 | 0 |
    | 0 | 1 | 0 | 0 |
    | 1 | 0 | 0 | 0 |
    | 1 | 1 | 1 | 1 |

    Per l'operazione di $OR$:
    
    | $p_1$ | $p_2$ | $p_1 + p_2$ | $p_2 + p_1$ |
    | ----- | ----- | ----------- | ----------- |
    | 0 | 0 | 0 | 0 |
    | 0 | 1 | 1 | 1 |
    | 1 | 0 | 1 | 1 |
    | 1 | 1 | 1 | 1 |

##### Proprietà associativa

La seconda proprietà notevole è quella *associativa*, per la quale è possibile associare un prodotto o una somma logica mediante relazioni di precedenza senza per questo variare il risultato atteso. In altri termini, immaginiamo di avere i seguenti predicati:

<p style="text-align:center; font-style:italic">
la palla è tonda AND la palla è verde AND la palla è nella scatola
</p>

Il valore di verità di questo predicato sarà equivalente a quello dei seguenti:

<p style="text-align:center; font-style:italic">
(la palla è tonda AND la palla è verde) AND la palla è nella scatola
</p>

In pratica, nel secondo predicato, verificheremo dapprima che la palla sia tonda e verde, e poi che sia nella scatola, laddove nel primo verificheremo le tre condizioni contemporaneamente. Stesse considerazioni valgono per le operazioni di somma logica. 

!!!warning "Causalità delle verifiche"
    Da notare come questa formulazione abbia come ipotesi "forte" il fatto che non vi sia alcuna relazione di causalità tra le proprietà associate. In pratica, si suppone che il fatto che si verifichi in primis che la palla sia tonda e verde *non abbia alcuna influenza o causalità* sul fatto che la palla sia nella scatola.

Formalmente, dati $3$ predicati del tipo $p_1,p_2,p_3$:

$$
\begin{align}
OR \Leftrightarrow p_1 + p_2 + p_3 = p_1 + (p_2 + p_3) \\
AND \Leftrightarrow p_1 \times p_2 \times p_3 = p_1 \times (p_2 \times p_3)
\end{align}
$$

???tip "Tabelle della verità"
    Usiamo le tabelle della verità per verificare la proprietà associativa. Indicando $p_{or}$ il predicato originario avremo per la $AND$:

    | $p_1$ | $p_2$ | $p_3$ | $p_2 \times p_3$ | $p_1 \times (p_2 \times p_3)$ | $p_{or}$ |
    | ----- | ----- | ----- | --- | --- | --- |
    | 0 | 0 | 0 | 0 | 0 | 0 |
    | 1 | 0 | 0 | 0 | 0 | 0 |
    | 0 | 1 | 0 | 0 | 0 | 0 |
    | 1 | 1 | 0 | 0 | 0 | 0 |
    | 0 | 0 | 1 | 0 | 0 | 0 |
    | 1 | 0 | 1 | 0 | 0 | 0 |
    | 0 | 1 | 1 | 0 | 0 | 0 |
    | 1 | 1 | 1 | 1 | 1 | 1 |

    Mentre per la $OR$:
    
    | $p_1$ | $p_2$ | $p_3$ | $p_2 + p_3$ | $p_1 + (p_2 + p_3)$ | $p_{or}$ |
    | ----- | ----- | ----- | --- | --- | --- |
    | 0 | 0 | 0 | 0 | 0 | 0 |
    | 1 | 0 | 0 | 0 | 1 | 1 |
    | 0 | 1 | 0 | 1 | 1 | 1 |
    | 1 | 1 | 0 | 1 | 1 | 1 |
    | 0 | 0 | 1 | 1 | 1 | 1 |
    | 1 | 0 | 1 | 1 | 1 | 1 |
    | 0 | 1 | 1 | 1 | 1 | 1 |
    | 1 | 1 | 1 | 1 | 1 | 1 |

##### Proprietà distributiva

L'ultima proprietà notevole è quella *distributiva* del prodotto rispetto alla somma. Anche questa proprietà richiama la corrispondente proprietà aritmetica, e può essere esplicitata come segue.

Vogliamo valutare che:

<p style="text-align:center; font-style:italic">
la palla è tonda AND la palla è verde OR la palla è tonda AND la palla è nella scatola
</p>

In pratica, vorremo valutare se la palla sia tonda e verde (primo prodotto logico) oppure se sia tonda e nella scatola (secondo prodotto logico). La proprietà distributiva ci dice che il precedente predicato equivale a scrivere:

<p style="text-align:center; font-style:italic">
la palla è tonda AND (la palla è verde OR la palla è nella scatola)
</p>

Staremo quindi valutando se la palla è verde oppure nella scatola e, conseguentemente, se sia tonda. Formalmente, quindi, dati tre predicati $p_1, p_2, p_3$:

$$
p_1 \times p_2 + p_1 \times p_3 = p_1 \times (p_2 + p_3)
$$

???tip "Tabelle della verità"
    Anche in questo caso, le tabelle della verità ci permettono di confermare l'eguaglianza. Indicando $p_{or}$ il predicato originario, avremo:

    | $p_1$ | $p_2$ | $p_3$ | $p_1 \times p_2$ | $p_1 \times p_3$ | $p_{or}$ |
    | ----- | ----- | ----- | --- | --- | --- |
    | 0 | 0 | 0 | 0 | 0 | 0 |
    | 1 | 0 | 0 | 0 | 0 | 0 |
    | 0 | 1 | 0 | 0 | 0 | 0 |
    | 1 | 1 | 0 | 1 | 0 | 1 |
    | 0 | 0 | 1 | 0 | 0 | 0 |
    | 1 | 0 | 1 | 0 | 1 | 1 |
    | 0 | 1 | 1 | 0 | 0 | 0 |
    | 1 | 1 | 1 | 1 | 1 | 1 |

    Se adesso indichiamo con $p_{d}$ il predicato associato alla proprietà distributiva, avremo:

    | $p_1$ | $p_2$ | $p_3$ | $p_2 + p_3$ | $p_d$
    | ----- | ----- | ----- | --- | --- |
    | 0 | 0 | 0 | 0 | 0 |
    | 1 | 0 | 0 | 0 | 0 |
    | 0 | 1 | 0 | 1 | 0 |
    | 1 | 1 | 0 | 1 | 1 |
    | 0 | 0 | 1 | 1 | 0 |
    | 1 | 0 | 1 | 1 | 1 |
    | 0 | 1 | 1 | 1 | 0 |
    | 1 | 1 | 1 | 1 | 1 |

##### Identità dell'operatore $NOT$

Chiudiamo questa carrellata illustrando brevemente tre delle identità che valgono per l'operatore $NOT$.

Partiamo dalla seguente espressione:

<p style="text-align:center; font-style:italic">
la palla è tonda OR la palla non è tonda
</p>

In questo caso, vediamo come il precedente predicato composto sia *sempre* vero. Ciò è legato al fatto che i due predicati semplici si complementano andando, se considerati congiuntamente, a coprire la totalità dei possibili casi esperibili nel mondo reale. Volendo essere meno formali, quindi, potremmo dire che il precedente predicato esprime il concetto al fatto che la palla o è tonda, o non lo è.

Formalmente, quindi, potremo scriivere:

$$
p + \overline{p} = 1
$$

Consideriamo adesso la seguente espressione:

<p style="text-align:center; font-style:italic">
la palla è tonda AND la palla non è tonda
</p>

Estendendo il ragionamento precedente, questo predicato non potrà mai essere vero, perché implicherebbe che la palla sia contestualmente tonda e non tonda, il che, ovviamente, non avviene nella realtà. Formalmente:

$$
p + \overline{p} = 0
$$

Infine, consideriamo l'espressione:

<p style="text-align:center; font-style:italic">
NOT (NOT la palla è tonda)
</p>

In pratica, l'espressione all'interno delle parentesi *nega* il predicato, implicando che la palla non sia tonda. Tuttavia, il $NOT$ esterno *nega la negazione*, il che ovviamente ci riporta al caso iniziale. Formalmente:

$$
\overline{\overline{x}} = x
$$

Queste sono le basi per l'interpretazione dei principi dell'algebra booleana; nella [prossima lezione](04_laws.md) andremo ad approfondire alcune leggi notevoli.
