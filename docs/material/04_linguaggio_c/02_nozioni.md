## Parole riservate

In ogni linguaggio di programmazione esiste una serie di **parole riservate**, o **keyword**, che indicano delle specifiche funzionalità dello stesso, e che pertanto non possono essere in alcun modo utilizzate dall'utente. Normalmente, queste parole chiave sono quelle relative a fattori come il *tipo* di una variabile, oppure ancora dei particolari *attributi* assegnabili ad una struttura dati o ad una funzione.

Ad esempio, proviamo ad esempio a creare la seguente variabile in C:

```c
int int = 10;
```

Provando a compilare, Visual Studio ci darà i seguenti messaggi di errore:

```bash
error C2632: 'int' non può essere seguito da 'int'
error C2513: 'int': nessuna variabile dichiarata prima di '='
```

Per una lista di keyword usate nei vari linguaggi, controllare l'appendice D.

## Modularità, prototipi e file header

### Funzioni e procedure

In C++, così come nel C, la diferenza tra *funzioni* e *procedure* è solo teorica.

Le procedure, in programmazione puramente procedrale, sono blocchi che espletano una determinata operazione senza produrre un valore di ritorno. Le funzioni, invece, mutuano il concetto matematico di relazione, ed associano ad un elemento del proprio dominio (variabili e parametri) un elemento di un codominio (valore di ritorno).

Ecco quindi come il `void` assume un significato diverso: una procedura è un tipo particolare di funzione che non ha codominio, e quindi presenta un valore di ritorno `void`.
