## Struttura del codice

Il programma è strutturato come segue:

```
|---File di intestazione
|------ioutils.h
|------parsing.h
|------sorting.h
|---File di origine
|------ioutils.c
|------parsing.c
|------sorting.c
|------source.c
|---File di risorse
|------array.txt
```

## Descrizione sintetica dei file

### File di intestazione (header)

Segue una breve descrizione dei singoli file di intestazione.

| File        | Descrizione                                           | Link al codice                                                                                                        |
| ----------- | ----------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------- |
| `ioutils.h` | Contiene delle utility di supporto all'I/O.           | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Tema%20di%20esempio/Linguaggio%20C/ioutils.h) |
| `parsing.h` | Contiene delle utility di supporto al parsing.        | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Tema%20di%20esempio/Linguaggio%20C/parsing.h) |
| `sorting.h` | Contiene delle utility di supporto al selection sort. | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Tema%20di%20esempio/Linguaggio%20C/sorting.h) |

### File di origine (sorgenti)

Segue una breve descrizione dei singoli file di origine.

| File        | Descrizione                                                              | Link al codice                                                                                                        |
| ----------- | ------------------------------------------------------------------------ | --------------------------------------------------------------------------------------------------------------------- |
| `ioutils.c` | Contiene l'implementazione delle funzioni descritte nell'header omonimo. | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Tema%20di%20esempio/Linguaggio%20C/ioutils.c) |
| `parsing.c` | Contiene l'implementazione delle funzioni descritte nell'header omonimo. | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Tema%20di%20esempio/Linguaggio%20C/parsing.c) |
| `sorting.c` | Contiene l'implementazione delle funzioni descritte nell'header omonimo. | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Tema%20di%20esempio/Linguaggio%20C/sorting.c) |
| `source.c`  | Contiene il programma principale.                                        | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Tema%20di%20esempio/Linguaggio%20C/source.c)  |

### File di risorse

Segue una breve descrizione dei singoli file di risorce.

| File        | Descrizione                                    |
| ----------- | ---------------------------------------------- |
| `array.txt` | Contiene un esempio per l'input di un vettore. |

## Descrizione delle funzioni implementate

### `ioutils`

| Funzione        | Argomenti                 | Output            | Descrizione                                                                                                                                                                          |
| --------------- | ------------------------- | ----------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| `read_file`     | `char* string`            | N.D.              | Legge un file (chiesto in input all'interno della funzione) e va a popolare di conseguenza la stringa (`string`) passata come argomento. Contiene funzioni di verifica degli errori. |
| `print_array`   | `int array[], int length` | N.D.              | Permette di formattare a schermo un determinato array di interi.                                                                                                                     |
| `text_or_shell` | N.D.                      | `char input_mode` | Chiede all'utente di inserire un carattere tra `f` ed `r` per determinare se leggere da file o da riga di comando.                                                                   |
| `save_to_file`  | `int array[], int length` | `void`            | Salva un array di interi di lunghezza length nel file di testo richiesto all'utente. Se il file di testo non esiste, viene creato; se esiste, viene sovrascritto.                    |

### `parsing`

| Funzione              | Argomenti                                            | Output        | Descrizione                                                                                                                               |
| --------------------- | ---------------------------------------------------- | ------------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| `strstrp`             | `char* str_in, char* str_out, char strp, int length` | N.D.          | Legge la stringa `str_in` di lunghezza `length`, rimuove tutte le occorrenze del carattere `strp` e la salva nella stringa `str_out`.     |
| `string_to_int_array` | `char* string, int* buffer`                          | `int numbers` | Converte la stringa di interi `string`, con interi separati da una virgola, nell'array `buffer`. Restituisce il numero di interi trovati. |

### `sorting`

| Funzione         | Argomenti                                                   | Output | Descrizione                                                                                           |
| ---------------- | ----------------------------------------------------------- | ------ | ----------------------------------------------------------------------------------------------------- |
| `swap`           | `int array[], int swap_l_idx, int swap_r_idx, int swap_val` | N.D.   | Sostituisce l'elemento all'indice swap_l_idx con l'elemento swap_r_idx nell'array di interi `vector`. |
| `selection_sort` | `int vector[], int length`                                  | N.D.   | Implementa l'algoritmo di selection sort sul vettore di interi `vector`.                              |

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
