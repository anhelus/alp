# Esempio di risoluzione degli esercizi svolti a casa

## Compito 1 - 

## Compito 2 - Applicazione dei concetti teorici

Si applichino i concetti teorici visti a lezione alla risoluzione del seguente problema.

Si supponga di avere l'insieme dei numeri che vanno da 1 a 10 (ovvero 1, 2, 3, ..., 9, 10). Si vuole creare un algoritmo che restituisca soltanto i numeri pari, ovvero divisibili per 2 senza resto. Per far questo:

* definire il problema nei termini indicati a lezione (obiettivo, ente risolutore, etc.);
* definire, in maniera descrittiva, un algoritmo che possa risolvere il problema;
* definire il diagramma di flusso associato all'algoritmo precedentemente descritto.

### Punto 2.1 - Definizione del problema nei termini indicati a lezione

| Elemento | Definizione |
| -------- | ----------- |
| Obiettivo | L'obiettivo del problema è quello di restituire i numeri pari compresi nell'intervallo che va tra 1 a 10. |
| Ente risolutore | In senso lato, chi implementa l'algoritmo; in senso stretto, il calcolatore. |
| Elementi noti | Insieme dei numeri da valutare, regola per la quale un numero è pari se il resto della divisione per due è zero. |

### Punto 2.2 - Definizione descrittiva di un algoritmo che possa risolvere il problema

1. Al primo punto, l'algoritmo considererà la lista `numeri` contenente i valori che vanno da 1 a 10. Opzionalmente, potrebbe anche leggerli da un supporto esterno.
2. Successivamente, sarà usato un ciclo FOR per contare dieci iterazioni, una per ogni elemento della lista `numeri`. Per il conteggio, sarà usata una variabile contatore chiamata `i` con valore iniziale pari a 0.
3. Ad ogni iterazione, l'algoritmo valuterà se l'`i`-mo elemento della lista `numeri` è divisibile per 2. Nel caso questo sia vero, lo stamperà a schermo; in caso contrario, non sarà effettuata alcuna operazione.
4. Si incrementa la variabile contatore di 1, e si torna al punto 2.
5. Quando la variabile contatore assumerà valore maggiore od uguale a 10, l'algoritmo terminerà la sua esecuzione.

### Punto 2.3 - Definire il diagramma di flusso del problema nei termini indicati a lezione

``` mermaid
flowchart TD
    A((Start)) --> B["numeri = [1, ..., 10]"];
    B --> C[i = 0];
    C --> D{i < 10?};
    D --> |Sì| E{"numeri[i] % 2 == 0?"};
    E --> |Sì| F[/"print(numeri[i])"/];
    F --> G[i = i+1];
    E --> |No| G;
    G --> D;
    D --> |No| H((End));
```


    
    
    
