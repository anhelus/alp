## Descrizione dell'algoritmo

L'algoritmo di *heap sort* è una tecnica basata principalmente sulla struttura dati binary heap. E' simile al selection sort, dove per prima cosa troviamo l'elemento massimo e lo piazziamo ad uno dei due estremi del vettore. Ripetiamo la stessa procedura per tutti gli altri elementi.

### Definizione di binary heap

Per *binary heap* si intende un albero binario completo dove gli oggetti sono memorizzati in modo che un valore in un nodo padre sia pi+ grande (o più piccolo) dei valori in due dei nodi figli. Il primo è chiamato *max heap*, mentre il secondo è chiamato *min heap*. L'heap può essere rappresentato usando un albero binario o un array.

Dal momento che un binary heap è un albero binario completo, può essere rappresentato facilente come un array, e questo tipo di rappresentazione risulta essere efficiente in termini spazilai. Se il nodo padre è memorizzato all'indice I, il figlio di inistra può essere calcolato come 2*I + 1 ed il figlio di destra come 2* I + 2.

## Heap Sort

1. creare un max heap dai dati di inpuyt
2. a queto punto, l'oggetto più grande è memorizzato alla radice dell'heap. rimpiazzarlo con l'ultimo oggetot dell'heap seguito riducendo la dimensione dell'heap di 1. Infine, 

Heap Sort Algorithm for sorting in increasing order:
1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of the tree.
3. Repeat step 2 while size of heap is greater than 1.

How to build the heap?
Heapify procedure can be applied to a node only if its children nodes are heapified. So the heapification must be performed in the bottom-up order.

Lets understand with the help of an example:

https://www.geeksforgeeks.org/heap-sort/