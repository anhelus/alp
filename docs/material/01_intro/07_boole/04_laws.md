# 1.7.4 - Leggi dell'algebra booleana

Nella [scorsa lezione](03_ops_properties.md) abbiamo esplicitato le più importanti proprietà delle operazioni fondamentali dell'algebra booleana. Vediamo quindi quali sono alcune tra le leggi fondamentali che governano questa disciplina.

##### Legge dell'idempotenza

Immaginiamo il seguente predicato:

<p style="text-align:center; font-style=italic">
la palla è tonda OR vero
</p>

Il predicato è una somma logica tra il valore *vero* ed una proposizione semplice. Come è facile intuire, il predicato composto sarà *sempre* vero, grazie alla presenza del valore *vero*. Se invece il predicato composto fosse nella forma:

<p style="text-align:center; font-style=italic">
la palla è tonda OR falso
</p>

allora sarà vero se e solo se la palla è tonda. Proviamo adesso a scrivere il seguente predicato composto:

<p style="text-align:center; font-style=italic">
la palla è tonda OR la palla è tonda
</p>

In questo caso, il risultato sarà vero se la palla è tonda (e, quindi, il predicato $p$ è vero), e falso altrimenti (e, quindi, se $p$ è falso). Formalmente, avremo che:

$$
\begin{cases}
p + 1 = 1 \\
p + 0 = p \\
p + p = p
\end{cases}
$$

Appare quindi evidente come lo $0$ logico, ovvero il *falso*, sia l'*elemento neutro* della somma logica, ovvero l'elemento che, se applicato in somma logica ad un predicato $p$, ne mantiene inalterata la veridicità.

Cosa accade se consideriamo il prodotto logico al posto della somma? Nel primo caso, avremo:

<p style="text-align:center; font-style=italic">
la palla è tonda AND vero
</p>

La precedente proposizione è strettamente dipendente dal valore di $p$: infatti, se $p$ è vero, anche il predicato lo sarà. Il seguente predicato invece:

<p style="text-align:center; font-style=italic">
la palla è tonda AND falso
</p>

sarà sempre falso, in quanto risulterà essere il prodotto di un predicato logico $p$ per uno zero logico. Infine:

<p style="text-align:center; font-style=italic">
la palla è tonda AND la palla è tonda
</p>

sarà vero se la palla è tonda, e falso altrimenti. Volendo scrivere formalmente queste relazioni, avremo che:

$$
\begin{cases}
p \times 1 = p \\
p \times 0 = 0 \\
p \times p = p
\end{cases}
$$

In questo caso, quindi, sarà il *vero*, ovvero l'$1$ logico, l'elemento neutro.

Queste condizioni ci permettono di derivare le *leggi dell'idempotenza*, definibili come:

$$
\begin{cases}
p + p = p \\
p \times p = p
\end{cases}
$$

##### Legge dell'assorbimento

Partiamo dalla seguente espressione.

<p style="text-align:center; font-style=italic">
la palla è tonda OR la palla è tonda AND la palla è verde
</p>

Analizziamola partendo dal prodotto logico.

* Se la palla *è tonda e verde*, il prodotto sarà vero. In questo caso, quindi, la somma logica sarà sicuramente vera, ed il risultato sarà vero.
* Se la palla *è tonda ma non verde*, il prodotto sarà falso. Tuttavia, la somma logica sarà comunque vera, per cui il risultato complessivo sarà sempre vero.
* Se la palla *è verde ma non tonda*, il prodotto sarà falso, e la somma logica sarà anch'essa falsa, per cui il risultato complessivo sarà falso.

Da qui deriva la formulazione della *legge dell'assorbimento*, che dice che, dati due predicati $p_1$ e $p_2$:

$$
p_1 + p_1 \times p_2 = p_1
$$

Possiamo verificare il tutto usando delle opportune tabelle della verità, ponendo $p_{AND} = p_1 \times p_2$ e $p_{c} = p_1 + p_{AND}$.

| $p_1$ | $p_2$ | $p_{AND}$ | $p_{c}$ |
| - | - | - | - |
| 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 1 |
| 0 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 |

##### Leggi di De Morgan

Le leggi di De Morgan mettono in relazione le funzioni base dell'algebra booleana, ovvero le funzioni $OR$, $AND$ e $NOT$, dimostrandone l'intrinseca ridondanza. In altre parole, ogni operazione logica può essere espressa in funzione delle altre. Ciò può essere sfruttato per trasformare una funzione booleana complessa, rendendola più facilmente realizzabile dal punto di vista circuitale.

Per comprendere le leggi di De Morgan, possiamo partire dal solito esempio.

<p style="text-align:center; font-style=italic">
NOT (la palla è tonda OR la palla è verde)
</p>

L'espressione precedente valuta la veridicità della negazione della somma logica tra i predicati *la palla è tonda* e *la palla è verde*. In pratica, il predicato tra parentesi $p_{OR}$ sarà vero soltanto se la palla è tonda o verde. Tuttavia, dato che il predicato composto *nega* $p_{OR}$, per cui il risultato complessivo sarà vero soltanto se $p_{OR}$ è falso (e quindi se la palla non è tonda e non è verde). Questo ci porta ad un'altra possibile formulazione del predicato:

<p style="text-align:center; font-style=italic">
NOT la palla è tonda AND NOT la palla è verde
</p>

In questo caso, effettuiamo il prodotto logico tra due negazioni, ottenendo un valore vero se e solo se entrambi i predicati negati sono originariamente falsi.

Analogamente possiamo verificare che un predicato nella forma:

<p style="text-align:center; font-style=italic">
NOT (la palla è tonda AND la palla è verde)
</p>

sarà vero soltanto se la palla non è tonda o non è verde, per cui la forma equivalente è:

<p style="text-align:center; font-style=italic">
NOT la palla è tonda OR NOT la palla è verde
</p>

Queste equivalenze possono essere scritte formalmente come segue:

$$
\begin{align}
\overline{(x_1 + x_2)} = \overline{x_1} \times \overline{x_2} \\
\overline{(x_1 \times x_2)} = \overline{x_1} + \overline{x_2}
\end{align}
$$

Le equazioni 1 e 2 rappresentano le due leggi di De Morgan.

!!!note "Tabelle della verità"
    Verifichiamo le leggi di De Morgan sfruttando le tabelle della verità. Per la prima legge potremo scrivere:

    | $x_1$ | $x_2$ | $x_1 + x_2$ | $\overline{x_1 + x_2}$ |
    | - | - | - | - |
    | 0 | 0 | 0 | 1 |
    | 0 | 1 | 1 | 0 |
    | 1 | 0 | 1 | 0 |
    | 1 | 1 | 1 | 0 |

    che equivale a:

    | $\overline{x_1}$ | $\overline{x_2}$ | $\overline{x_1} \times \overline{x_2}$ |
    | - | - | - |
    | 1 | 1 | 1 |
    | 1 | 0 | 0 |
    | 0 | 1 | 0 |
    | 0 | 0 | 0 |

    Per la seconda:

    | $x_1$ | $x_2$ | $x_1 \times x_2$ | $\overline{x_1 \times x_2}$ |
    | - | - | - | - |
    | 0 | 0 | 0 | 1 |
    | 0 | 1 | 0 | 1 |
    | 1 | 0 | 0 | 1 |
    | 1 | 1 | 1 | 0 |

    che equivale a:

    | $\overline{x_1}$ | $\overline{x_2}$ | $\overline{x_1} + \overline{x_2}$ |
    | - | - | - |
    | 1 | 1 | 1 |
    | 1 | 0 | 1 |
    | 0 | 1 | 1 |
    | 0 | 0 | 0 |

##### Tabelle della verità per le funzioni composte

Le tabelle della verità possono essere utilizzate anche per definire funzioni composte e non riconducibili a combinazioni "standard" delle tre funzioni logiche fondamentali. Immaginiamo ad esempio di avere i tre seguenti predicati:

<p style="text-align:center; font-style=italic">
la palla è tonda
</p>

<p style="text-align:center; font-style=italic">
la palla è verde
</p>

<p style="text-align:center; font-style=italic">
la palla è nella scatola
</p>

Vogliamo ottenere una funzione logica $F$ che sia vera quando solo e soltanto due dei predicati precedenti (che, per comodità, chiameremo $p_1, p_2, p_3$) sono veri. Per caratterizzare $F$, allora, potremo scrivere la tabella delle verità come:

| $p_1$ | $p_2$ | $p_3$ | $F$ |
| - | - | - | - |
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 |
| 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 0 |

Determinare come si combinano i singoli predicati mediante le operazioni fondamentali può essere particolarmente complesso. Possiamo quindi effettuare una sorta di *reverse engineering* della tabella delle verità, scoprendo quindi che:

* $F$ è vero quando $p_2$ e $p_3$ sono veri, e $p_1$ è falso;
* $F$ è vero quando $p_1$ e $p_3$ sono veri, e $p_2$ è falso;
* $F$ è vero quando $p_1$ e $p_2$ sono veri, e $p_3$ è falso.

Ne consegue che:

$$
F = \overline{p_1} p_2 p_3 + p_1 \overline{p_2} p_3 + p_1 p_2 \overline{p_3}
$$

In altre parole, la nostra funzione composta sarà vera se una delle tre condizioni composte è verificata:

* la palla è verde e nella scatola, ma non tonda;
* la palla è tonda e nella scatola, ma non verde;
* la palla è tonda e verde, ma non nella scatola.

Questa tecnica può essere quindi usata per creare funzioni composte di complessità arbitraria.

## Conclusioni

Nel corso di questa parte, abbiamo visto quali sono i concetti base dell'informatica, parlando della trattazione numerica binaria e delle relazioni legate all'algebra booleana. Nella prossima parte, prenderemo dimestichezza con le basi della programmazione.
