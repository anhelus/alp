# Appendice E - Tema d'esempio

In questa appendice descriviamo un esempio di tema d'anno.

In particolare, l'argomento trattato da questo esempio è:

> *Implementazione di un metodo di ordinamento vettoriale basato sull'algoritmo selection sort*.

## Parti da evidenziare

1. **Struttura del programma**. Evidenziare la struttura del programma, descrivendo cartelle e file utilizzati. Ad esempio: *nella cartella `algs` sono contenuti i moduli appartenenti al package omonimo, il cui compito è quello di contenere il codice usato per gli algoritmi*, oppure *lo script `run.py` rappresenta il punto di accesso principale al programma, e contiene il metodo omonimo, che effettua l'ordinamento di un vettore in ingresso ricavato a partire dall'input ricevuto mediante il modulo `argparse` invocando i metodi definiti nel packae `algs`*.
2. **Eventuali algoritmi utilizzati**. In questo caso, vanno elencati e spiegati brevemente gli eventuali algoritmi utilizzati. Ad esempio: *il programma implementa l'algoritmo di ordinamento su vettori chiamato selection sort, il quale ordina in maniera iterativa un vettore suddividendolo in due sottoinsiemi, che saranno comparati ad ogni iterazione ed eventualmente modificati scambiando l'ultimo valore dell'array a sinistra con il primo dell'array a destra fino al termine dell'algoritmo*.

Il codice va inoltre *commentato*, spiegando nel dettaglio il funzionamento di ciascun metodo o classe.

## Codice

Il codice è organizzato secondo questa struttura:

```
|src                    # Package principale
|---__init__.py
    |algs               # Package dedicato agli algoritmi
    |---__init__.py
        sorting.py      # Modulo per le classi per l'ordinamento
|run.py                 # Script principale
```

Di seguito il link ai due file di rilievo (gli `__init__.py` sono file vuoti):

| File | Link |
| ---- | ---- |
| Script principale (run.py) | [:link:](./project/run.py) |
| Modulo per le classi per l'ordinamento (sorting.py) | [:link:](./project/src/algs/sorting.py) |
