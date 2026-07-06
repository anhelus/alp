# 3.1.3 Insertion sort

L'insertion sort è un algoritmo di ordinamento semplice ed efficiente per piccoli array. Funziona come farebbe una persona quando ordina manualmente delle carte da gioco: seleziona una carta (elemento), la confronta con quelle già ordinate e la inserisce nella posizione corretta.

## Funzionamento

L'algoritmo considera due parti dell'array: una parte ordinata (inizialmente il primo elemento) e una parte non ordinata (gli altri elementi). Si parte dal secondo elemento e lo si confronta con gli elementi della parte ordinata. Se il valore è più piccolo, gli elementi maggiori vengono spostati a destra. L'elemento corrente viene quindi posizionato nella sua posizione corretta nella parte ordinata. Il processo si ripete per tutti gli elementi dell'array.

### Esempio passo-passo

Consideriamo l'array: `[64, 34, 25, 12]`.

- **Iterazione 1 (i=2)**: Elemento da inserire (key): 34. Parte ordinata: `[64]`. Confronta 34 con 64: sposta 64 a destra → `[64, 64, 25, 12]`. Inserisci 34 → `[34, 64, 25, 12]`.
- **Iterazione 2 (i=3)**: Elemento da inserire (key): 25. Parte ordinata: `[34, 64]`. Confronta 25 con 64: sposta → `[34, 64, 64, 12]`. Confronta 25 con 34: sposta → `[34, 34, 64, 12]`. Inserisci 25 → `[25, 34, 64, 12]`.
- **Iterazione 3 (i=4)**: Elemento da inserire (key): 12. Parte ordinata: `[25, 34, 64]`. Confronta 12 con 64, 34 e 25, spostando tutti → `[25, 34, 64, 64]` → `[25, 34, 34, 64]` → `[25, 25, 34, 64]`. Inserisci 12 → `[12, 25, 34, 64]`.

## Pseudocodice

```linenums="1"
function insertionSort(array):
    n = length(array)
    for i = 2 to n:
        key = array[i]
        j = i - 1
        while j > 0 and array[j] > key:
            array[j + 1] = array[j]
            j = j - 1
        endwhile
        array[j + 1] = key
    endfor
    return array
```

## Complessità computazionale

| Caso | Complessità temporale | Complessità spaziale |
| ---- | --------------------- | -------------------- |
| Migliore (array già ordinato) | $O(n)$ | $O(1)$ |
| Peggiore (array in ordine inverso) | $O(n^2)$ | $O(1)$ |

## Proprietà

- **Stabile**: mantiene l'ordine relativo degli elementi uguali
- **In-place**: non richiede memoria aggiuntiva significativa
- Ottimo per array piccoli o quasi ordinati
