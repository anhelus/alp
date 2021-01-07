# Chiarimenti tracce

Di seguito, i chiarimenti richiesti su alcune delle tracce **prima della loro assegnazione**.

## Traccia 34

Il programma richiede in output tutte le coppie di indici $(i, j)$ di un vettore $n$ tali per cui i risulta essere minore di $j$, mentre $n[i]$ è maggiore di $2 * n[j]$. Ad esempio, consideriamo un vettore del tipo:

$$
n = [10 2 1 1]
$$

Consideriamo la coppia di indici $(0, 2)$, ovvero gli indici che puntano al primo e terzo elemento del vettore. In questo caso, $i$ è sicuramente inferiore a $j$. Inoltre, $n[i]$, ovvero l'elemento di $n$ che corrisponde all'indice $0$, e quindi $10$, è maggiore del doppio di $n[j]$, ovvero l'elemento di $n$ che corrisponde all'indice 2, e quindi 1.
Il controllo va effettuato su tutte le possibili coppie $(i,j)$, ovviamente non considerando quelle coppie per le quali $i$ è uguale a $j$.

## Traccia 47

L’espressione mostrata nella traccia è riassumibile come segue:

1. Dato un valore $d$, calcolare il massimo tra gli elementi $a_j$ che vanno nell’intervallo che varia tra $i$ ed $i + d$
2. Questo va reiterato per tutti gli i che vanno da 0 ad $n – d$
3. Del risultato della 2, calcolare il minimo

Il focus principale non è sul calcolo del minimo (quelli in uscita dalla 3 saranno infatti dei minimi “relativi”), ma sull’approccio (evidentemente iterativo) da utilizzare.
