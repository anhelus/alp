https://www.tutorialspoint.com/automata_theory/turing_machine_introduction.htm

## Introduzione

Una *macchina di Turing* è un'astrazione matematica che consiste di un nastro a lunghezza infinita diviso in celle sul quale è dato un certo input. Consiste di una testina che legge il nastro di ingresso. Un registro memorizza lo stato della macchina di Turing. Dopo aver letto un simbolo in input, ed averlo rimpiazzato con un altro simbolo, cambia il suo stato interno, e si sposta di una cella a destra o sinistra. Se la macchina di Turing raggiunge lo stato finale, la stringa in input viene accettata; alternativamente, viene rigettata.

Una macchina di turing può essere descritta formalmente come una tupla $(Q, X, \Sigma, \delta, q_0, B, F)$ dove:

* $Q$ è un insieme finito di stati
* $X$ è l'alfabeto del nastro
* $\Sigma$ è l'alfabeto in input
* $\delta$ è una funzione di transizione
* q_0 è lo stato iniziale
* B è il simbolo vuoto
* F è l'insieme finale degli stati

In particolare, la funzione $\delta$ è definita come segue:

$$
\delta: Q \times X \leftarrow Q \times X \
$$

## Esempio

Consideriamo una machcina di Turing $M$ del tipo:

$$
M = (Q, X, \Sigma, \delta, q_0, B, F)
$$

con: 

* $Q={q_0, q_1, q_2, q_f}$
* $X={a,b}$
* $\Sigma={1}$
* q_0=${q_0}$
* F = ${q_f}$

$\delta$ è data da:

| | |

## Complesistà spazio/temporale

Per una macchina di turing la complessità temporale si riferisce alla misura del numero di volte che il nastro si muove quando la macchina è inizializzata per alcuni siboli di input, e la complessità spaziale è il numero di celle del nastro scritte.

La complessità temporale è:

$$T(n) = O(n log n)$$

mentre quella spaziale:

$$S(n) = O(n)$$

## Linguaggi accettati

Una TM accetta un linguaggio se entra in uno stato finale per una qualunque stringa di ingresso $w$.

Una TM decide un linguaggio se lo accetta ed entra in uno stato di reject per un qualsiasi input che non è nel linugaggio. Un linguaggio è ricorsivo se dcidibile da una macchina di Truing.

Ci possono essere casi nei quali una TM non si ferma. Questa TM acceetta il linguaggio, ma non lo giudica decidibile.

## Progettare una macchina di Turing

Le linee guida per la progettazione di una macchina di Turing sono le seguenti.

### Esempio 1

Progettare una TM per riconoscere tutte le stringhe che hanno un numero di a dispari.

Soluzione

La macchina di Turing può essere costruita come segue.

* sia q_1 lo stato iniziale.
* se M è in q_1, sulla scansione di a, entra nello stato di q_2 e scive B (blank)
* se M è in q_2, sulla scansioen di a, entra nello stato q_1 e scrive B
* dalle mosse precedenti, possiamo vedere che M enra lo stato q_1 se effettua la scansione di un numero pari di a, e entra lo stato q_2 se scandeisc eun numero dispari di a. Quindi q_2 è l'unico stato accettato.

Di conseguenza:

$$
T = {{q_1, q_2}, {1}, {1, B}, \delta, q_1, B, {q_2}}
$$

con $\delta$ dato da:

| Simbolo | stato q_1 | stato q_2 |
| ------- | --------- | --------- |
| a | BRq_2 | BRq_1 |
