# 3.2.1 - Ricerca lineare

Vediamo in ultimo gli algoritmi di ricerca.

## Introduzione al problema

Supponiamo di voler trovare un determinato elemento all'interno di una lista di valori, come ad esempio il numero di un nostro contatto all'interno della nostra rubrica (ovviamente, supponiamo di *non* voler utilizzare la funzionalità di ricerca integrata nella rubrica stessa).

Supponiamo di voler trovare il nostro gruppo tra quello dei partecipanti al tema d'anno. Ovviamente, l'idea sarebbe quella di scrivere un programma che faccia la ricerca del nostro gruppo in maniera automatica.

Una prima idea potrebbe essere quindi quella di esaminare ogni gruppo, partendo dal primo, mediante un approccio chiamato *ricerca lineare* (*linear search*). Ciò significa che il nostro programma dovrebbe esaminare una quarantina di gruppi per trovare quello di cui ha bisogno; non molti, giusto?

Beh, immaginiamo adesso di voler trovare Betelgeuse nel catalogo stellare [*Tycho-2*](https://www.cosmos.esa.int/web/hipparcos/tycho-2), che contiene non quaranta studenti, ma più di due milioni e mezzo di stelle. L'impresa non sembra più tanto semplice.

Per questi casi è utile un altro approccio, che vedremo nella prossima lezione: la [ricerca binaria](../02_binary/lecture.md).

## Pseudocodice

```linenums="1"
function linearSearch(array, target):
    for i = 1 to length(array):
        if array[i] == target:
            return i
        endif
    endfor
    return -1  // non trovato
```

## Complessità computazionale

La ricerca lineare potrebbe dover consultare fino a $n$ elementi nel caso peggiore, per cui la sua complessità temporale è $O(n)$. La complessità spaziale è $O(1)$, poiché usa solo poche variabili di appoggio indipendentemente dalla dimensione dell'input.

