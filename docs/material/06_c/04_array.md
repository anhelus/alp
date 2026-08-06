# 6.5 Array e Stringhe

Fino ad ora abbiamo visto variabili che contengono un singolo valore. Gli array ci permettono di gestire collezioni di dati dello stesso tipo.

## Gli Array

Un array è una struttura dati che memorizza una sequenza di elementi dello stesso tipo in un blocco di memoria contiguo.

*   **Definizione**: `tipo nome_array[dimensione];`
*   **Accesso**: Gli elementi sono accessibili tramite un **indice** a base zero. Il primo elemento ha indice `0`, il secondo `1`, e l'ultimo `dimensione - 1`.
*   **Inizializzazione**: Può avvenire contestualmente alla dichiarazione:
    ```c
    int voti[5] = {28, 30, 25, 27, 29};
    // È anche possibile omettere la dimensione, che verrà dedotta
    int altro_array[] = {1, 2, 3}; // La sua dimensione sarà 3
    ```
    **Importante**: Dopo la dichiarazione, non è più possibile usare la notazione `{...}` per assegnare un nuovo set di valori all'intero array. Il nome di un array non può essere usato come destinazione di un'assegnazione.

## L'Operatore `sizeof` con gli Array

!!! warning "Attenzione: `sizeof` non restituisce il numero di elementi"
    `sizeof(mio_array)` **non** restituisce il numero di elementi, ma la **dimensione totale in byte** occupata dall'array (numero di elementi × dimensione in byte di un singolo elemento).

Per calcolare dinamicamente il numero di elementi in un array, si usa la seguente formula idiomatica:
```c
size_t num_elementi = sizeof(mio_array) / sizeof(mio_array[0]);
```

## Array Multidimensionali

È possibile creare "array di array" per rappresentare strutture come matrici o tabelle. Si dichiarano specificando più dimensioni:
```c
// Una matrice 3x3 di numeri interi
int matrice[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
// Per accedere all'elemento in seconda riga, terza colonna:
int elemento = matrice[1][2]; // Corrisponde al valore 6
```

## Le Stringhe in C

In C, le stringhe non sono un tipo di dato primitivo. Sono, per convenzione, **array di caratteri (`char`) terminati da un carattere speciale, il carattere nullo (`\0`)**. Questo terminatore è fondamentale perché permette alle funzioni di sapere dove finisce la stringa.

*   **Inizializzazione**:
    ```c
    // Modo esplicito (richiede il terminatore manuale)
    char stringa1[5] = {'C', 'i', 'a', 'o', '\0'};

    // Modo semplice (il terminatore \0 viene aggiunto automaticamente)
    char stringa2[5] = "Ciao"; 
    ```
*   **Manipolazione**: Poiché le stringhe sono array, non è possibile copiarle con il semplice operatore di assegnazione (`=`). Per queste operazioni, è necessario usare le funzioni apposite fornite dalla libreria standard `<string.h>`, come `strcpy()`.

*   **Conversione**: Le librerie standard offrono funzioni per convertire stringhe in numeri e viceversa:
    *   **Da Stringa a Numero** (definite in `<stdlib.h>`):
        *   `atoi("123")` -> converte in `int` (123)
        *   `atof("12.3")` -> converte in `double` (12.3)
    *   **Da Numero a Stringa** (definita in `<stdio.h>`):
        *   `sprintf(buffer, "Valore: %d", 42);` -> questa funzione non restituisce la stringa, ma la **popola** nel buffer di caratteri fornito come primo argomento. Restituisce un `int` che indica il numero di caratteri scritti.

