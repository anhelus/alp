# Insertion sort

```
function sortedArray = insertionSort(array)
    n = length(array); % Lunghezza dell'array
    for i = 2:n
        key = array(i); % Elemento da inserire nella posizione corretta
        j = i - 1;
        % Sposta gli elementi maggiori di 'key' verso destra
        while j > 0 && array(j) > key
            array(j + 1) = array(j);
            j = j - 1;
        end
        % Inserisce il valore 'key' nella posizione corretta
        array(j + 1) = key;
    end
    sortedArray = array; % Restituisce l'array ordinato
end
```



Spiegazione del funzionamento:
Suddivisione dell'array:

L'algoritmo considera due parti dell'array: una parte ordinata (inizialmente il primo elemento) e una parte non ordinata (gli altri elementi).
Iterazione:

Si parte dal secondo elemento e si confronta con gli elementi della parte ordinata.
Se il valore è più piccolo, gli elementi maggiori vengono spostati a destra.
Inserimento:

L'elemento corrente viene posizionato nella sua posizione corretta nella parte ordinata.
Ripetizione:

Si ripete il processo per tutti gli elementi dell'array.
Complessità:
Tempo:
Caso migliore (array già ordinato): 
O
(
n
)
O(n).
Caso peggiore (array in ordine inverso): 
O
(
n
2
)
O(n 
2
 ).
Spazio:
In-place, quindi 
O
(
1
)
O(1) memoria aggiuntiva.
Se hai bisogno di una spiegazione più dettagliata o ulteriori modifiche, fammi sapere! 😊

Che cos’è Insertion Sort?
Insertion Sort è un algoritmo di ordinamento semplice ed efficiente per piccoli array. Funziona come farebbe una persona quando ordina manualmente delle carte da gioco: seleziona una carta (elemento), la confronta con quelle già ordinate e la inserisce nella posizione corretta.

Passaggi dell'algoritmo
Considerare il primo elemento come già ordinato:

L'algoritmo inizia con l'assunto che il primo elemento dell'array sia ordinato.
La parte rimanente è considerata non ordinata.
Iterare sugli elementi non ordinati:

Per ogni elemento nella parte non ordinata (dal secondo elemento in poi), determina la sua posizione corretta nella parte ordinata.
Inserimento nella posizione corretta:

Scorri gli elementi ordinati all'indietro per trovare dove inserire l'elemento corrente.
Sposta gli elementi maggiori verso destra per fare spazio all'elemento.
Inserisci l'elemento nella posizione trovata.
Ripetere per ogni elemento:

Il processo si ripete per ogni elemento fino a che tutta la lista è ordinata.
Esempio passo-passo
Consideriamo l'array: [64, 34, 25, 12].

Iterazione 1 (i=2):
Elemento da inserire (key): 34.
Parte ordinata: [64].
Confronta 34 con 64:
Sposta 64 a destra → [64, 64, 25, 12].
Inserisci 34 al posto corretto → [34, 64, 25, 12].
Iterazione 2 (i=3):
Elemento da inserire (key): 25.
Parte ordinata: [34, 64].
Confronta 25 con 64:
Sposta 64 a destra → [34, 64, 64, 12].
Confronta 25 con 34:
Sposta 34 a destra → [34, 34, 64, 12].
Inserisci 25 al posto corretto → [25, 34, 64, 12].
Iterazione 3 (i=4):
Elemento da inserire (key): 12.
Parte ordinata: [25, 34, 64].
Confronta 12 con 64:
Sposta 64 a destra → [25, 34, 64, 64].
Confronta 12 con 34:
Sposta 34 a destra → [25, 34, 34, 64].
Confronta 12 con 25:
Sposta 25 a destra → [25, 25, 34, 64].
Inserisci 12 al posto corretto → [12, 25, 34, 64].
Proprietà dell'algoritmo
Stabile: Mantiene l'ordine relativo degli elementi uguali.
In-place: Non richiede memoria aggiuntiva significativa.
Prestazioni:
O
(
n
2
)
O(n 
2
 ) nel caso peggiore (array in ordine inverso).
O
(
n
)
O(n) nel caso migliore (array già ordinato).
Applicazioni:
Ottimo per piccoli array o quando l'array è quasi ordinato.
Se hai altri dubbi o vuoi un esempio più complesso, fammi sapere! 😊