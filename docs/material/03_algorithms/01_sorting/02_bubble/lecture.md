# 3.1.2 Bubble sort

## Idea di base

L'algoritmo di *ordinamento a bolle* (*bubble sort*) ordina un array confrontando e scambiando gli elementi adiacenti di un vettore. In particolare, l'algoritmo sposta, in maniera rigorosamente iterativa, i valori più alti verso la fine dell'array, mentre i valori più piccoli vengono spostati verso l'inizio. Questo processo (che ricorda un po' delle "bolle" che "risalgono" in un bicchiere di champagne) viene ripetuto fino a che l'array non è completamente ordinato.

L'algoritmo si articola in due step reiterati per un certo numero di volte.

1. `compare`: nel primo step, compariamo (coppia a coppia) tutti gli elementi adiacenti all'interno dell'array.
2. `swap`: se dallo step precedente risulta che l'ordinamento è sbagliato, invertiamo la coppia di elementi nell'array.

## Esempio pratico

```
START

INIZIALIZZAZIONE
x = [12, 4, 8, 7, 2]
i = 1; j = 4;

ITERAZIONE 1
CONFRONTO:      V(j) < V(j-1) <==> 2 < 7 ==> TRUE
SOSTITUZIONE:   [12, 4, 8, 2, 7]
AGGIORNAMENTO:  j ==> 3

ITERAZIONE 2
CONFRONTO:      V(j) < V(j-1) <==> 2 < 8 ==> TRUE
SOSTITUZIONE:   [12, 4, 2, 8, 7]
AGGIORNAMENTO:  j ==> 2

ITERAZIONE 3
CONFRONTO:      V(j) < V(j-1) <==> 2 < 4 ==> TRUE
SOSTITUZIONE:   [12, 2, 4, 8, 7]
AGGIORNAMENTO:  j ==> 1

ITERAZIONE 4
CONFRONTO:      V(j) < V(j-1) <==> 2 < 12 ==> TRUE
SOSTITUZIONE:   [2, 12, 4, 8, 7]
AGGIORNAMENTO:  i ==> 2, j ==> 4

ITERAZIONE 5
CONFRONTO:      V(j) < V(j-1) <==> 7 < 8 ==> TRUE
SOSTITUZIONE:   [2, 12, 4, 7, 8]
AGGIORNAMENTO:  j ==> 3

ITERAZIONE 6
CONFRONTO:      V(j) < V(j-1) <==> 7 < 8 ==> FALSE
SOSTITUZIONE:   [2, 12, 4, 7, 8]
AGGIORNAMENTO:  j ==> 2

ITERAZIONE 7
CONFRONTO:      V(j) < V(j-1) <==> 4 < 12 ==> TRUE
SOSTITUZIONE:   [2, 4, 12, 7, 8]
AGGIORNAMENTO:  j ==> 1

ITERAZIONE 8
CONFRONTO:      V(j) < V(j-1) <==> 8 < 7 ==> FALSE
SOSTITUZIONE:   [2, 4, 12, 7, 8]
AGGIORNAMENTO:  i ==> 3, j ==> 4

ITERAZIONE 9
CONFRONTO:      V(j) < V(j-1) <==> 7 < 12 ==> FALSE
SOSTITUZIONE:   [2, 4, 7, 12, 8]
AGGIORNAMENTO:  j ==> 2
```

## Pseudocodice

## Complessità numerica

## Codice

```matlab
function sortedArray = bubbleSort(array)
    n = length(array); % Lunghezza dell'array
    for i = 1:n-1
        for j = 1:n-i
            if array(j) > array(j+1)
                % Scambia gli elementi
                temp = array(j);
                array(j) = array(j+1);
                array(j+1) = temp;
            end
        end
    end
    sortedArray = array; % Restituisce l'array ordinato
end

% Esempio di array
array = [64, 34, 25, 12, 22, 11, 90];

% Ordinamento con Bubble Sort
sortedArray = bubbleSort(array);

% Visualizza il risultato
disp('Array ordinato:');
disp(sortedArray);
```
