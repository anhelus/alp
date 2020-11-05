## Introduzione al problema

I due algoritmi di ordinamento che abbiamo visto finora, ovvero il selection sort e l'insertion sort, hanno dei tempi di esecuzione nel caso peggiore di $O(n^2)$. Quando la dimensione dell'array in ingresso è abbastanza grande, questi algoritmi possono metterci parecchio ad essere eseguiti. Il nostro obiettivo è quello di ridurre questo tempo: a questo scopo, cerchiamo altri algoritmi.

### Paradigma divide-et-impera

I due algoritmi che cerchiamo, chiamati merge e quick sort, sono basati su un approccio ricorsivo chiamato *divide-et-impera*. Questo approccio si occupa di dividere un problema in diversi sotto problemi che risultano essere simili al problema originario. UNa volta divisi, l'approccio risolve ciascuno dei singoli problemi, e quindi combina le soluzioni per risolvere il problema originario.

Ovviamente, dato che viene usato un approccio ricorsivo, ogni sottoproblema deve essere più piccolo di quello originario, e ci deve essere un caso base per ciascuno di essi. Possiamo schematizzare l'algoritmo divide et impera come avente tre diverse parti:

1. **Divide**: la prima parte suddivide il problema in diversi sotto problemi che rappresentano delle istanze più piccole del problema stesso.
2. **Impera**: i sotto problemi sono risoilti in maniera riciorsiva. Se sono abbastanza piccoli, risolvere il sottoproblema come caso base.
3. **Combinare** le soluzioni ai sottoproblemi in quella al problema originario.

Si possono visualizzare questi passi in questo modo, con l'algoritmo che crea due sottoproblemi:

![divide_1](../assets/images/05_algoritmi/04_merge_sort/divide_impera_1.png)

Se abbiamo più di due step ricorsivi:

![divide_2](../assets/images/05_algoritmi/04_merge_sort/divide_impera_2.png)

## Descrizione dell'algoritmo

TODO: da qui
https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/overview-of-merge-sort

## Pseudocodice

## Diagramma di flusso

## Analisi computazionale