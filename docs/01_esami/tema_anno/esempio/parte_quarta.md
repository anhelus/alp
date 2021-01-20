# Esempio prova d'esame - Programma in Python

## Struttura del codice

Di seguito, la struttura su file system del codice sorgente.

```
|---algorithms
|------__init__.py
|------sorting.py
|---utils
|------__init__.py
|------ioutils.py
|------parsing.py
|---run.py
```

## Package

Segue una sintetica descrizione dei package presenti sull'applicazione.

| Package      | Descrizione                                            | Link                                                                                                                            |
| ------------ | ------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------- |
| `algorithms` | Contiene tutti gli algoritmi utilizzati dal programma. | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/tree/master/Tema%20di%20esempio/Linguaggio%20Python/app/algorithms) |
| `utils`      | Contiene le utility utilizzate dal programma.          | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/tree/master/Tema%20di%20esempio/Linguaggio%20Python/app/utils)      |
| `run.py` | Script di esecuzione del programma | [:link:](https://github.com/anhelus/informatica-dm-uniba-ex/blob/master/Tema%20di%20esempio/Linguaggio%20Python/app/run.py) |

## Moduli

Segue una sintetica descrizione dei moduli contenuti in ciascun package.

### `algorithms`

Segue una sintetica descrizione dei moduli contenuti all'interno del package `algorithms`.

#### `sorting.py`

Il modulo `sorting.py` contiene le seguenti classi.

| Classe          | Descrizione                                                                                                                                |
| --------------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
| `BaseSort`      | Classe base usata per definire gli algoritmi di sorting. Caratterizzata dal metodo astratto `sort`, da implementare nelle classi derivate. |
| `SelectionSort` | Classe derivata che definisce l'algoritmo di selection sort.                                                                               |

##### `BaseSort`

La classe `BaseSort` consta dei seguenti metodi ed attributi.

| Attributo | Descrizione                                                              | Tipo   | Modificatore |
| --------- | ------------------------------------------------------------------------ | ------ | ------------ |
| `ar`      | Lista di valori numerici da ordinare. Utilizza il decorator `@property`. | `List` | `private`    |

!!!note "Nota"
	Un'implementazione maggiormente rigorosa potrebbe prevedere l'uso di un array NumPy per rendere superfluo il metodo `check_numeric`, descritto di seguito.

| Metodo          | Descrizione                                                                                                                             | Tipo di metodo  | Parametri di ingresso | Tipo restituito |
| --------------- | --------------------------------------------------------------------------------------------------------------------------------------- | --------------- | --------------------- | --------------- |
| `check_numeric` | Controlla se il valore passato come parametro è di tipo intero o float (violando leggermente il principio del duck typing).             | Metodo statico  | `val: Any`            | `bool`          |
| `sort`          | Metodo astratto per l'ordinamento di `ar`, da implementare nelle classi derivate. Può opzionalmente effettuare l'ordinamento _inplace_. | Metodo astratto | `inplace: bool=True`  | `List`          |

##### `SelectionSort`

La classe `SelectionSort` deriva dalla classe `BaseSort`, ed oltre ad attributi e metodi derivanti da quest'ultima, consta dei seguenti metodi.

| Metodo          | Descrizione                                                                                                                                                                                 | Tipo di metodo  | Parametri di ingresso    | Tipo restituito |
| --------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------- | ------------------------ | --------------- |
| `_compare_sort` | Metodo ausiliario usato nell'implementazione per diminuire il riutilizzo di codice. Effettua lo swap e la riassegnazione dei due array (left e right) sfruttando la mutabilità delle liste. | Metodo statico  | `l_ar: List, r_ar: List` | `None`          |
| `sort`          | Implementa il selection sort.                                                                                                                                                               | Metodo astratto | `inplace: bool=True`     | `List`          |

!!!note "Nota"
	Non è stato definito un metodo swap perché consta di un'unica operazione.

### `utils`

#### `ioutils.py`

Il modulo `ioutils.py` contiene le seguenti classi e funzioni.

| Classe        | Descrizione                                                   |
| ------------- | ------------------------------------------------------------- |
| `FilePrinter` | Classe delegata alla scrittura dei risultati in un dato file. |

| Funzione        | Descrizione                                            | Parametri di ingresso | Tipo restituito |
| --------------- | ------------------------------------------------------ | --------------------- | --------------- |
| `is_file_input` | Determina le modalità di input desiderate dall'utente. | `im:str`              | `bool`          |
| `read_file`     | Legge un file, restituendo il suo valore come stringa. | `fn: str, fp: str`    | `str`           |

!!!note "Nota"
	Un approccio interessante sarebbe definire un `BasePrinter`, il quale definisse il modo di formattare la stringa, magari mediante un metodo `format`, ed implementasse un metodo per la stampa "astratto" che si adatta allo specifico stream di output. Lo stesso discorso potrebbe essere esteso ad una classe BaseReader, che potrebbe leggere da diversi tipi di stream di input.

##### `FilePrinter`

La classe `FilePrinter` consta dei seguenti metodi ed attributi.

| Attributo | Descrizione                                                                                           | Tipo  | Modificatore | Valore di default |
| --------- | ----------------------------------------------------------------------------------------------------- | ----- | ------------ | ----------------- |
| `fn`      | Stringa che rappresenta il nome del file di output. Utilizza il decorator `@property`.                | `str` | `private`    | N.D.              |
| `fp`      | Stringa che rappresenta il path assoluto del file di output. Utilizza il decorator `@property`.       | `str` | `private`    | `os.getcwd()`     |
| `dl`      | Stringa che rappresenta il delimitatore tra due elementi contigui. Utilizza il decorator `@property`. | `str` | `private`    | `,`               |
| `op`      | Stringa di apertura del vettore. Utilizza il decorator `@property`.                                   | `str` | `private`    | `[`               |
| `cl`      | Stringa di chiusura del vettore. Utilizza il decorator `@property`.                                   | `str` | `private`    | `]`               |

!!!note "Nota"
	Un'implementazione maggiormente rigorosa potrebbe prevedere l'uso di un array NumPy per rendere superfluo il metodo `check_numeric`, descritto di seguito.

| Metodo       | Descrizione                         | Tipo di metodo   | Parametri di ingresso | Tipo restituito |
| ------------ | ----------------------------------- | ---------------- | --------------------- | --------------- |
| `print_list` | Stampa su file una lista di interi. | Metodo di classe | `vals: List`          | N.D.            |

#### `parsing.py`

Il modulo `parsing.py` contiene le seguenti classi.

| Classe   | Descrizione                                                                      |
| -------- | -------------------------------------------------------------------------------- |
| `Parser` | Classe delegata alla conversione di una stringa in una lista di valori numerici. |

!!!note "Nota"
	Anche in questo caso, sarebbe interessante usare un approccio gerarchico, o diversi metodi.

##### `Parser`

La classe `Parser` consta dei seguenti metodi ed attributi.

| Attributo  | Descrizione                                                                                                      | Tipo   | Modificatore | Valore di default |
| ---------- | ---------------------------------------------------------------------------------------------------------------- | ------ | ------------ | ----------------- |
| `st`       | Stringa di input da convertire in lista numerica. Utilizza il decorator `@property`.                             | `str`  | `private`    | N.D.              |
| `dl`       | Delimitatore che suddivide gli elementi numerici contigui. Utilizza il decorator `@property`.                    | `str`  | `private`    | N.D.              |
| `rm`       | Lista dei caratteri da rimuovere. Utilizza il decorator `@property`.                                             | `List` | `private`    | `[]`              |
| `to_float` | Indica se gli elementi della lista devono essere convertiti in formato reale. Utilizza il decorator `@property`. | `bool` | `private`    | `False`           |

| Metodo        | Descrizione                                                     | Tipo di metodo   | Parametri di ingresso | Tipo restituito |
| ------------- | --------------------------------------------------------------- | ---------------- | --------------------- | --------------- |
| `check_valid` | Controlla se il valore passato può essere convertito in intero. | Metodo statico   | `val: Any`            | `bool`          |
| `parse`       | Effettua il parsing della stringa di input.                     | Metodo di classe | N.D.                  | `str`           |

!!!note "Nota"
	Il metodo `check_valid` ha ovvie limitazioni legate al fatto che controlla soltanto gli interi, per cui ci sarebbe una perdita di informazione passando dei float. Sarebbe quindi interessante prevedere anche questa eventualità.

## Funzionamento del programma

Ecco una breve guida per illustrare il funzionamento del programma.

1. Recarsi nella cartella dove è posizionato il file `run.py`.

        cd folder_selection_sort

2. Lanciare il programma.

        python run.py

3. Il programma richiederà di scegliere tra la selezione di un file (mediante il carattere `f`) o quella della riga di comando (mediante il carattere `r`).

    a. Se viene selezionato il file, occorre inserire un nome valido. Il file dovrà essere inserito all'interno della cartella del programma, ed avere estensione `.txt`. All'interno del file dovrà già essere stato inserito un array.
    b. Se viene selezionata la riga di comando, occorre inserire un array.

    I formati validi sono del tipo `[el_1, el_2, ..., el_n]` oppure `{el_1, el_2, ..., el_n}`.

4. Il programma provvederà a stampare a schermo il risultato dell'algoritmo di ordinamento.

!!!note "Nota"
	Si omette, per brevità, la parte relativa all'esempio di funzionamento ed al file da passare in input, in quanto sostanzialmente identica a quella proposta per la seconda e terza parte.
