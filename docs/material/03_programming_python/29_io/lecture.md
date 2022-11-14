# 16 - Lettura e scrittura di file in Python

Python offre numerose funzioni (già integrate nel *core* del linguaggio) per la gestione dei file. Queste sono a loro volta divise in vari moduli, quali (ad esempio) [`os`](https://docs.python.org/3/library/os.html), [`shutil`](https://docs.python.org/3/library/shutil.html) e [`pathlib`](https://docs.python.org/3/library/pathlib.html).

In questa lezione, vedremo alcune tra le principali funzioni usate per effettuare le più comuni operazioni sui file Python.

## 16.1 File di testo vs. file binari

Prima di passare a vedere le principali funzioni usate da Python per la gestione dei file, dobbiamo parlare dei due diversi *tipi* di file esistenti, ovvero file *binari* e file di *testo*.

La maggior parte dei file che usiamo durante il normale utilizzo del computer sono, infatti, file di tipo *binario*. Nonostante quello che si possa pensare, infatti, anche un documento di Word (o di un programma equivalente) è, in realtà, un file binario, pur avendo soltanto del testo al suo interno. Altri esempi di file binario sono dati dalle immagini, dai database, o anche dai fogli Excel. Ciò è principalmente legato al fatto che file di questo tipo sono, in realtà, codificati in un formato che rende necessario un software specifico per la loro apertura.

Un *file di testo*, invece, non ha una codifica specifica, e può essere aperto da un normale editor di testo (per intenderci, anche Blocco Note). Tuttavia, occorre notare che:

* i file di testo devono essere *leggibili* da un essere umano;
* i dati contenuti in un file di testo devono essere organizzati in righe distinte.

In tal senso, al termine di ogni riga dei file di testo vi è un carattere di terminazione che, in Python, è la sequenza di escape `\n` (mentre in altri linguaggi, come ad esempio il C, è data dal punto e virgola).

## 16.2 - Python e gli strumenti per l'input/output (I/O)

Innazitutto è necessario premettere che Python integra di default gli strumenti per leggere (*input*) e scrivere (*output*) su file (o su altri supporti). Ciò differisce da altri linguaggi, come ad esempio il C++, nel quale è necessario includere una libreria facente parte del core del linguaggio (`#include <fstream>`).

Vediamo adesso come aprire un file in Python.

### 16.2.1 - Apertura di un file in Python

Per aprire un file in Python occorre usare la funzione `open()`, il cui utilizzo base è il seguente:

```py
riferimento_file = open(nome_file, modalità)
```

La funzione `open()` restituisce un *riferimento*, o *puntatore*, al file a partire da due parametri:

* `nome_file`, ovvero il nome del file con il quale vogliamo interagire, *comprensivo dell'estensione*;
* `modalità`, che indica il modo in cui interagiremo con il file.

In particolare, se il file con cui vogliamo interagire è nella stessa cartella del nostro script Python, potremo limitarci ad utilizzarne il nome completo di estensione (ad esempio, `dati.txt`). In caso contrario, invece, dovremo specificarne il percorso relativo al nostro script, o il percorso assoluto (ad esempio, `C:/documenti/dati.txt`).

!!!tip "Slash e backslash"
    Quando si utilizzano i percorsi assoluti, è importante fare attenzione al corretto uso di slash e backslash. Il consiglio è quello di utilizzare le slash o, in alternativa, il doppio backslash. Tuttavia, potrebbe essere saggio utilizzare strumenti più *pythonic*, come le librerie os e pathlib, che approfondiremo altrove.

La modalità indica invece quello che vogliamo fare con il nostro file; le diverse opzioni sono riassunte nella tabella successiva.

| Modalità | Abbreviazione | Descrizione | Piazzamento del puntatore al file |
| -------- | ------------- | ----------- | --------------------------------- |
| *Write* | `w` | Questa modalità è usata quando dobbiamo modificare il file da zero. Risulta importante sottolineare come, in questa modalità, un eventuale file già esistente viene cancellato | Il puntatore al file è piazzato all'inizio del file. |
| *Read* | `r` | Questa modalità è usata quando il file va esclusivamente letto e non modificato in alcun modo. | Il puntatore al file è piazzato all'inizio del file. |
| *Append* | `a` | Questa modalità è usata quando occorre aggiungere ulteriori informazioni al termine del file. | Il puntatore al file è piazzato al termine del file. |
| *Read/Write* | `r+` | Questa modalità è usata quando occorre sia modificare completamente sia leggere il file. | Il puntatore al file è piazzato all'inizio del file. |
| *Append/Read* | `a+` | Questa modalità è usata quando occorre sia aggiungere ulteriori informazioni al termine del file sia permetterne la lettura. | Il puntatore al file è piazzato alla fine del file. |
| *Exclusive Creation* | `x` | Questa modalità è usata esclusivamente per creare un *nuovo* file; ciò significa che, se esiste già un file con lo stesso nome, la funzione lancerà un'eccezione. | N.D. |

Le modalità precedentemente elencate funzionano con i file di testo; per usarle sui file binari, basterà aggiungere una `b` al modificatore, ovvero:

| Modalità | Shortcut (testo) | Shortcut (binario) |
| -------- | ---------------- | ------------------ |
| *Write* | `w` | `wb` |
| *Read* | `r` | `rb` |
| *Append* | `a` | `ab` |
| *Read/Write* | `r+` | `rb+` |
| *Append/Read* | `a+` | `ab+` |
| *Exclusive Creation* | `x` | `xb` |

#### 16.2.1.1 - Un esempio

Vediamo un esempio di come è possibile aprire un file in modalità *write*. Supponiamo di avere un file chiamato `dati.txt`, e che questo sia nella stessa cartella del nostro script:

```py
file_dati = open('dati.txt', 'w')
```

Avremo quindi creato un oggetto chiamato `file_dati` che potremo conseguentemente utilizzare per manipolare, in modalità di scrittura, il nostro file `dati.txt`.

!!!note "Modalità utilizzate"
    Le modalità di cui ci serviremo nei casi pratici saranno spesso quelle di lettura e scrittura.

## 16.3 - Chiusura di un file

Quando si utilizza un file in lettura o scrittura si crea un *flusso* (in inglese *stream*) che va da o verso il nostro file. In altre parole, lo script crea un "canale di comunicazione" che tiene aperto il file, non rendendolo disponibile ad altre applicazioni fino a che questo non viene liberato.

Va da sé che chiudere questo stream sia estremamente importante per due motivi, ovvero liberare risorse ed assicurarsi che eventuali modifiche provvisorie siano finalizzate. Per farlo, Python ci mette a disposizione la funzione `close()` da chiamare sul riferimento al file. Ad esempio:

```py
file_dati.close()
```

Dopo aver chiuso il file, non potremo più accedervi (a meno che, ovviamente, non lo riapriamo successivamente). Per verificarlo, proviamo ad eseguire le seguenti istruzioni da un terminale Python:

```py
>>> file_dati = open("dati.txt", "w")
>>> file_dati.close()
>>> file_dati.read()

Traceback (most recent call last):
  File "<input>", line 1, in <module>
    file_dati.read()
ValueError: I/O operation on closed file.
```

## 16.4 - La parola chiave with

Python offre una sintassi *consigliata* per l'interazione con i file mediante l'uso della parola chiave `with`. Grazie a questa sintassi, il file verrà automaticamente chiuso dopo che l'esecuzioni delle istruzioni presenti nel blocco di codice annidato all'interno del `with`. Ad esempio, l'istruzione precedente si trasforma nel seguente modo:

```py
with open("dati.txt", "w") as file_dati:
    # Abbiamo un puntatore chiamato file_dati.
    # Eseguiamo alcune operazioni sul file:
    file_dati.read()

# Siamo usciti dall'ambito del with.
# Il file è adesso chiuso.
```

!!!note "Nota"
    Nel prosieguo, utilizzeremo esclusivamente la sintassi che usa la parola chiave `with`.

## 16.5 - Interagire con un file

Una volta aperto un file, potremo usare i metodi integrati in Python per interagire con il file. Vediamone brevemente come fare.

### 16.5.1 - Lettura dei dati

Per leggere i contenuti di un file, dobbiamo usare il metodo `read(size)`. Se non specifichiamo il parametro `size` (in italiano *dimensione*), il metodo leggerà l'intero contenuto del file, stampandolo a schermo sotto forma di stringa (se è un file di testo) o come byte (se è un file binario).

!!!warning "Le dimensioni contano"
    Di solito, la funzione `read()` viene tranquillamente utilizzata lasciando il parametro di default. TUttavia, se il file che stiamo leggendo ha dimensioni maggiori rispetto alla memoria disponibile, non potremo accedervi in una sola volta, e dovremo usare il parametro `size` per "spezzarlo" in parti gestibili.

Vediamo un esempio di utilizzo del parametro `size`. Supponiamo che il nostro file `dati.txt` contenga il seguente testo:

```txt
Dati sulla riga 1
Dati sulla riga 2
Dati sulla riga 3
```

Proviamo quindi a scrivere questo codice:

```py linenums="1"
with open("dati.txt", "r") as dati:
    print("Nome del file: ", dati.name)
    line = dati.read()
    print(line)
```

L'output sarà:

```sh
Nome del file: dati.txt
Dati sulla riga 1
Dati sulla riga 2
Dati sulla riga 3
```

Proviamo adesso a modificare la terza riga come segue:

```py
line = dati.read(6)
```

L'output cambierà di conseguenza nel seguente:

```sh
Nome del file: dati.txt
Dati s
```

Appare evidente come l'operazione di lettura legga i dati nel file soltanto fino alla posizione 6, che è il valore che abbiamo passato alla precedente chiamata a `read()`.

!!!note "Nota"
    Nel caso provassimo ad effettuare nuovamente l'operazione di lettura sullo stesso file, continueremo a leggere i dati da dove ci eravamo precedentemente interrotti; in tal modo, possiamo elaborare un file dalle grandi dimensioni in pezzi dalle dimensioni ridotte.

### 16.5.2 Leggere i file di testo riga per riga

Abbiamo visto come l'istruzione `read()` ci permette di leggere un file nella sua interezza. Tuttavia, possiamo decidere di leggere un file riga per riga mediante l'istruzione `readline(size)`.

!!!note "Il parametro `size`"
    Il parametro `size` funzioni esattamente come per la funzione `read`.

Facciamo un esempio:

```py
with open("dati.txt", "r") as dati:
    print("Nome del file: ", dati.name)
    line = dati.readline()
    print(line)
```

L'uscita in questo caso sarà:

```sh
Nome del file: dati.txt
Dati sulla riga 1
```

Ovviamente, possiamo chiamare ripetutamente il metodo `readline()` allo scopo di leggere ulteriori righe dal file; in alternativa, possiamo usare `readlines()`, che restituisce una lista di tutte le righe contenute nel file.

Ad esempio:

```py
print(dati.readlines())
```

restituirà il seguente output:

```py
['Dati sulla riga 1', 'Dati sulla riga 2', 'Dati sulla riga 3']
```

!!!warning "`readline()` su file binari"
    Dato che i file binari non hanno al loro interno il concetto di "riga di codice", i metodi `readline()` e `readlines()` non funzioneranno su questo tipo di file.

Un modo alternativo di mostrare il contenuto di un file riga dopo riga è quello di usare un ciclo:

```py
with open("dati.txt", "r") as dati:
    for line in dati:
        print(line)
```

Queste istruzioni avranno l'output che segue:

```sh
Dati sulla riga 1
Dati sulla riga 2
Dati sulla riga 3
```

!!!tip "Efficienza nella lettura"
    L'approccio che prevede la lettura riga dopo riga del file mediante `readline()` è, in realtà, più efficiente di quello che si limita a leggere il file nella sua interezza mediante `read()`. Infatti, non dovremo leggere l'intero file e tenerlo in memoria, ma potremo leggere ed elaborare ogni riga in maniera individuale, il che è ovviamente vantaggioso in termini di memoria, specie nel caso di file di grandi dimensioni.

### 16.5.3 - Scrivere su file

Appare chiaro come i file non servano a molto se non è possibile scrivervi dei dati. Per farlo, dovremo aprire il file in scrittura, mediante (ad esempio) la modalità `w`.

!!!tip "Suggerimento"
    Spesso è opportuno utilizzare la modalità *append* per non eliminare se non si vogliono sovrascrivere i contenuti di un file già esistente.

Una volta aperto il file, sarà necessario usare la funzione `write(data)`, dove `data` sono i dati che saranno scritti sul file. Ad esempio, possiamo aggiungere una nuova riga al nostro file di dati come segue:

```py
dati.write("Dati sulla riga 4\n")
```

!!!tip "Suggerimento"
    Ricordiamo che la sequenza `\n` indica una nuova riga; in tal modo, le scritture successive avverranno a partire dalla riga successiva.

Se volessimo scrivere delle variabili non rappresentative di una stringa, come, ad esempio, una serie di numeri, dovremmo effettuarne il cast. Ad esempio, volendo scrivere una lista di tre numeri:

```py
values = [1, 2, 3]

with open("dati.txt", "a+") as dati:
    for value in values:
        str_value = str(value)
        dati.write(f'{str_value}\n')
```

### 16.5.4 Ricerca nei file

In precedenza abbiamo visto come quando scriviamo in modalità *read* il riferimento al file punta all'inizio dello stesso. Se volessimo leggere una sezione intermedia del file, dovremmo "scorrerlo" fino ad individuare la parte di interesse.

In alternativa, dovremo spostare il puntatore dall'inizio del file: il modo più semplice di farlo è usare il metodo `seek(offset, from_what)`. In particolare, il parametro `offset` indica il numero di caratteri da considerare a partire dal parametro `from_what`, che può assumere tre possibili valori:

* `0`: indica l'inizio del file;
* `1`: indica il puntatore alla posizione attuale;
* `2`: indica la fine del file.

!!!note "Differenza tra file di testo e binari"
    Sottolineamo che quando lavoriamo con dei file di testo possiamo usare soltanto i valori `0` e `2`.

Di conseguenza, usare `dati.seek(5, 0)` farà in modo da posizionare il puntatore al quarto carattere (ricordiamo che il conteggio in Python parte da 0). Di conseguenza, potremmo avere un output di questo tipo:

```sh
sulla riga 1
Dati sulla riga 2
Dati sulla riga 3
```

Se volessimo controllare l'attuale posizione del puntatore, possiamo usare il metodo `tell()`. Questo metodo può essere usato anche per capire quanto è lungo il file attuale:

```py
with open("dati.txt", "a") as dati:
    print(dati.tell())
```

Il valore restituito dovrebbe essere 55, il che rappresenta la dimensione del file.

## 16.6 Inserire nuovi elementi in file esistenti

Ci potrebbero essere delle occasioni dove è necessario *modificare internamente* un file esistente, senza necessariamente aggiungervi dei dati. Per farlo, non possiamo usare semplicemente le modalità *append* o *write*: infatti, la prima inserirà nuovi dati al termine del file, mentre la seconda *sovrascriverà l'intero file*.

Dovremo quindi usare dei metodi alternativi. Quello più semplice prevede di creare una lista di righe a partire dalla lettura del file, usando poi il metodo `insert(i, x)` su questa per inserire i nuovi dati nella lista stessa. Una volta terminata la modifica della lista, potremo effettuarne il `join()` e scriverla sul nostro file.

!!!note "La funzione `insert`"
    Ricordiamo che la funzione `insert(i, x)` prevede che `i` sia un intero che indica l'indice di lista nel quale inserire `x`.

Ad esempio, volendo inserire una nuova riga nel nostro file tra la 1 e la 2, dovremo usare il codice che segue:

```py
# Leggiamo i contenuti del file e salviamoli in una lista
with open("dati.txt", "r") as dati:
    righe_dati = dati.readlines()

righe_dati.insert(1, "Questo va tra le righe 1 e 2\n")

# Sovrascriviamo il vecchio file con i nuovi contenuti
with open("dati.txt", "w") as dati:
    nuovi_dati = "".join(righe_dati)
    dati.write(nuovi_dati)
```

Andando a leggere il file, il risultato finale sarà il seguente:

```sh
Dati sulla riga 1
Questo va tra le righe 1 e 2
Dati sulla riga 2
Dati sulla riga 3
```

## 16.7 - Conclusioni

In questa lezione, abbiamo visto una serie di tecniche e modi per leggere, creare e modificare file esistenti in Python. Per approfondire la conoscenza di metodi e concetti, il consiglio è, al solito, quello di rivolgersi alla [documentazione ufficiale](https://docs.python.org/3/library/io.html).
