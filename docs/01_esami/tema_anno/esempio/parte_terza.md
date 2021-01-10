# Esempio prova d'esame - Programma in C++

## Struttura del codice

Il programma è strutturato come segue:

```
|---File di intestazione
|------ioutils.h
|------parsing.h
|------sorting.h
|---File di origine
|------ioutils.cpp
|------parsing.cpp
|------sorting.cpp
|------source.cpp
|---File di risorse
|------array.txt
```

## Descrizione sintetica dei file

### File di intestazione (header)

Segue una breve descrizione dei singoli file di intestazione.

| File        | Descrizione                                           | Link al codice                                                                                                              |
| ----------- | ----------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------- |
| `ioutils.h` | Contiene delle utility di supporto all'I/O.           | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Tema%20di%20esempio/Linguaggio%20C%2B%2B/ioutils.h) |
| `parsing.h` | Contiene delle utility di supporto al parsing.        | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Tema%20di%20esempio/Linguaggio%20C%2B%2B/parsing.h) |
| `sorting.h` | Contiene delle utility di supporto al selection sort. | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Tema%20di%20esempio/Linguaggio%20C%2B%2B/sorting.h) |

### File di origine (sorgenti)

Segue una breve descrizione dei singoli file di origine.

| File          | Descrizione                                                              | Link al codice                                                                                                                |
| ------------- | ------------------------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------------------- |
| `ioutils.cpp` | Contiene l'implementazione delle funzioni descritte nell'header omonimo. | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Tema%20di%20esempio/Linguaggio%20C%2B%2B/ioutils.cpp) |
| `parsing.cpp` | Contiene l'implementazione delle funzioni descritte nell'header omonimo. | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Tema%20di%20esempio/Linguaggio%20C%2B%2B/parsing.cpp) |
| `sorting.cpp` | Contiene l'implementazione delle funzioni descritte nell'header omonimo. | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Tema%20di%20esempio/Linguaggio%20C%2B%2B/sorting.cpp) |
| `source.cpp`  | Contiene il programma principale.                                        | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Tema%20di%20esempio/Linguaggio%20C%2B%2B/source.cpp)  |

### File di risorse

Segue una breve descrizione dei singoli file di risorce.

| File        | Descrizione                                    |
| ----------- | ---------------------------------------------- |
| `array.txt` | Contiene un esempio per l'input di un vettore. |

## Descrizione sintetica dei file

### `ioutils`

In questo file è definito il namespace `ioutils`, contenente le seguenti funzioni e classi.

#### Funzioni

| Nome funzione   | Lista parametri (tipo - nome) | Output (tipo) | Descrizione                                                              |
| --------------- | ----------------------------- | ------------- | ------------------------------------------------------------------------ |
| `is_file_input` | N.D.                          | `bool`        | Se vero, legge da file; in caso contrario, legge da riga di comando.     |
| `read_file`     | `string file_name`            | `string`      | Legge il contenuto di `file_name`, restituendolo sotto forma di stringa. |
| `print_array`   | `vector<int> vect`            | `void`        | Utility per mostrare a schermo il contenuto di un vettore numerico.      |

!!!note "Uso di funzioni standalone"
	Usare delle funzioni _standalone_, ovvero a sè stanti, è perfettamente lecito. In questo caso, queste funzioni non sono strettamente correlate ad una classe, e non risultano essere tra loro complementari, per cui sono state dichiarate come facenti parte "globalmente" del namespace `ioutils`.

Le precedenti funzioni non sono state raggruppate all'interno di una classe a causa del

#### Classi

| Nome classe   | Descrizione                                                                   |
| ------------- | ----------------------------------------------------------------------------- |
| `SaveManager` | Classe delegata alla gestione del salvataggio su file di un vettore ordinato. |

##### `SaveManager`

###### Variabili membro

| Nome e tipo variabile | Modificatore di accesso | Descrizione                                                           |
| --------------------- | ----------------------- | --------------------------------------------------------------------- |
| `string fileName`     | `private`               | Nome del file di output.                                              |
| `vector<int> vect`    | `private`               | Vettore da stampare sul file di output.                               |
| `string delimiter`    | `private`               | Separatore tra due elementi contingui del vettore. Di default, è `,`. |
| `string opener`       | `private`               | Carattere che contrassegna l'inizio del vettore. Di default, è `[`.   |
| `string closer`       | `private`               | Carattere che contrassegna il termine del vettore. Di default, è `]`. |

###### Funzioni membro

| Nome funzione  | Lista parametri (tipo - nome)                                                                                       | Output (tipo)      | Modificatore di accesso | Descrizione                 |
| -------------- | ------------------------------------------------------------------------------------------------------------------- | ------------------ | ----------------------- | --------------------------- |
| `SaveManager`  | `string fileName`, <br/> `vector<int> vect`, <br/> `string delimiter`, <br/> `string opener`, <br/> `string closer` | N.D.               | `public`                | Costruttore parametrizzato. |
| `setFileName`  | `string fileName`                                                                                                   | `void`             | `public`                | Setter per `fileName`.      |
| `getFileName`  | N.D.                                                                                                                | `string`           | `public`                | Getter per `fileName`.      |
| `setVect`      | `vector<int> vect`                                                                                                  | `void`             | `public`                | Setter per `vect`.          |
| `getVect`      | N.D.                                                                                                                | `vector<int> vect` | `public`                | Getter per `vect`.          |
| `setDelimiter` | `string delimiter`                                                                                                  | `void`             | `public`                | Setter per `delimiter`.     |
| `getDelimiter` | N.D.                                                                                                                | `string`           | `public`                | Getter per `delimiter`.     |
| `setOpener`    | `string opener`                                                                                                     | `void`             | `public`                | Setter per `opener`.        |
| `getOpener`    | N.D.                                                                                                                | `string`           | `public`                | Getter per `opener`.        |
| `setCloser`    | `string closer`                                                                                                     | `void`             | `public`                | Setter per `closer`.        |
| `getCloser`    | N.D.                                                                                                                | `string`           | `public`                | Getter per `closer`.        |
| `saveToFile`   | N.D.                                                                                                                | `void`             | `public`                | Salva il vettore su file.   |

### `parsing`

In questo file è definito il namespace `parsing`, contenente le seguenti funzioni e classi.

#### Classi

| Nome classe | Descrizione                                                 |
| ----------- | ----------------------------------------------------------- |
| `Parser`    | Classe delegata al parsing dell'input inserito dall'utente. |

##### `SaveManager`

###### Variabili membro

| Nome e tipo variabile | Modificatore di accesso | Descrizione                                              |
| --------------------- | ----------------------- | -------------------------------------------------------- |
| `string input`        | `private`               | Stringa rappresentativa dell'input inserito dall'utente. |

###### Funzioni membro

| Nome funzione     | Lista parametri (tipo - nome) | Output (tipo) | Modificatore di accesso | Descrizione                                                                                                   |
| ----------------- | ----------------------------- | ------------- | ----------------------- | ------------------------------------------------------------------------------------------------------------- |
| `Parser`          | N.D.                          | N.D.          | `public`                | Costruttore di default.                                                                                       |
| `Parser`          | `string input`                | N.D.          | `public`                | Costruttore parametrizzato.                                                                                   |
| `setInput`        | `string input`                | `void`        | `public`                | Setter per `input`.                                                                                           |
| `getInput`        | N.D.                          | `string`      | `public`                | Getter per `input`.                                                                                           |
| `strip`           | `char to_strip`               | `void`        | `public`                | Rimuove il carattere `to_strip` dalla stringa input. Effettua le operazioni _in place_.                       |
| `strip_multiple`  | `vector<char> to_strip`       | `void`        | `public`                | Rimuove tutti i caratteri specificati nel vettore di caratteri `to_strip`. Effettua le operazioni _in place_. |
| `parse_int_array` | `string delimiter`            | `vector<int>` | `public`                | Converte la stringa di input in un vettore di interi. Il delimitatore che viene considerato di default è `,`. |

!!!note "Sulle variabili membro di `Parser`"
	Noterete che abbiamo scelto come variabili membro di parser soltanto la stringa `input`. Una scelta valida potrebbe essere inserire anche il vettore di output come variabile membro, anche se ci sarebbe probabilmente un maggiore _coupling_ (accoppiamento) tra classi, in quanto il `Sorter` (vedere seguito) dipenderebbe da una variabile membro del `Parser`. Ovviamente, il coupling va evitato (quando possibile).

### `sorting`

In questo file è definito il namespace `sorting`, contenente le seguenti funzioni e classi.

#### Classi

| Nome classe | Descrizione                                  |
| ----------- | -------------------------------------------- |
| `Sorter`    | Classe delegata all'ordinamento del vettore. |

##### `SaveManager`

###### Variabili membro

| Nome e tipo variabile      | Modificatore di accesso | Descrizione                        |
| -------------------------- | ----------------------- | ---------------------------------- |
| `vector<int> to_sort`      | `private`               | Vettore da ordinare.               |
| `vector<int>::iterator it` | `private`               | Iteratore sul vettore da ordinare. |

###### Funzioni membro

| Nome funzione   | Lista parametri (tipo - nome)  | Output (tipo) | Modificatore di accesso | Descrizione                                                                 |
| --------------- | ------------------------------ | ------------- | ----------------------- | --------------------------------------------------------------------------- |
| `Sorter`        | N.D.                           | N.D.          | `public`                | Costruttore di default.                                                     |
| `Sorter`        | `vector<int> to_sort`          | N.D.          | `public`                | Costruttore parametrizzato.                                                 |
| `setVector`     | `vector<int> vect`             | `void`        | `public`                | Setter per `to_sort`.                                                       |
| `getVector`     | N.D.                           | `vector<int>` | `public`                | Getter per `to_sort`.                                                       |
| `swap`          | `int l_idx`, <br/> `int r_idx` | `void`        | `public`                | Effettua la funzione di `swap`. Chiamato internamente da `selectionSort()`. |
| `selectionSort` | N.D.                           | `void`        | `public`                | Applica l'algoritmo di `selectionSort` sul vettore `to_sort`.               |

!!!note "Il metodo `swap`"
	In questo caso, sarebbe perfettamente lecito assegnare al metodo `swap` il modificatore di accesso `private`, in quanto esclusivamente acceduto internamente dal `selectionSort()`.

## Funzionamento del programma

1. Recarsi nella cartella dove è posizionato l'eseguibile fornito usando PowerShell o la Command Prompt.

        cd folder_selection_sort

2. Lanciare il programma.

        SelectionSort.exe

3. Il programma richiederà di scegliere tra la selezione di un file (mediante il carattere `f`) o quella della riga di comando (mediante il carattere `r`).

    a. Se viene selezionato il file, occorre inserire un nome valido. Il file dovrà essere inserito all'interno della cartella del programma, ed avere estensione `.txt`. All'interno del file dovrà già essere stato inserito un array.
    b. Se viene selezionata la riga di comando, occorre inserire un array.

    I formati validi sono del tipo `[el_1, el_2, ..., el_n]` oppure `{el_1, el_2, ..., el_n}`.

4. Il programma provvederà a stampare a schermo il risultato dell'algoritmo di ordinamento.

### Esempio di funzionamento

```shell
$ cd folder_selection_sort
$ SelectionSort.exe
% Enter 'f' to use a text file, or 'r' to use shell. 			-> r
$ Please enter array values:									-> [10, 4, 3, 2]
$ Sorted vector:
$ 2       3       4       10
```

```shell
$ cd folder_selection_sort
$ SelectionSort.exe
% Enter 'f' to use a text file, or 'r' to use shell. 			-> f
$ Please enter file name: 	 									-> array.txt
$ Sorted vector:
$ 1       2       3       3       4       7       8       12      51      66
```

### File di input

Ecco un esempio di file di input.

```shell
[10, 4, 3, 2]
```

Il file andrà posizionato nella stessa cartella dell'eseguibile.
