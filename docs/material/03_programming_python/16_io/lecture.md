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

### 16.3 - Chiusura di un file

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

### 16.4 - La parola chiave with

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

### 16.5 - Interagire con il file

Una volta aperto un file, potremo usare i metodi integrati in Python per interagire con il file. Vediamone brevemente come fare.

#### 16.5.1 - Lettura dei dati

Per leggere i contenuti di un file, dobbiamo usare il metodo `read(dimensione)`. Se non specifichiamo il parametro `dimensione`, il metodo leggerà l'intero contenuto del file, stampandolo a schermo sotto forma di stringa (se è un file di testo) o come byte (se è un file binario).

TODO: DA QUI

Dobbiamo stare attenti quando usiamo la dimensione di default. Se il file che stiamo leggendo è più grande della memorai disponibile, non saremo in grado di accedere all'intero file in una sola volta. In un caso come questo, dobbiamo suare il parametro `size` per spezzarlo in parti gestibili dalla memoria.

Il parametro `size` dice al metodo `read` quanti byte deve restituire dal file al display. Supponiamo che il file data.txt abbia il seguente testo al suo interno:

```txt
This data is on line 1
This data is on line 2
This data is on line 3
```

Quindi se scriviamo il seguente programma in Python:

```py
with open("workData.txt", "r+") as work_data:
    print("This is the file name: ", work_data.name)
    line = work_data.read()
    print(line)
```

Avremo questo output:

```sh
This is the file name: workData.txt
This data is on line 1
This data is on line 2
This data is on line 3
```

D'altro canto, se modifichiamo la terza linea per dire:

```py
line = workData.read(6)
```

Avremo questo output:

```sh
This is the file name: workData.txt
This d
```

Come possiamo vedere, l'operazione di lettura legge solo i dati nel file fino alla posizione 6, che è quello che abbiamo passato alla chiamata `read()` precedente. In questo modo possiamo limitare quanti dati sono letti da un file in un unico punto.

Se leggiamo dallo stesso oggetto file nuovamente, continuerà a leggere i dati da dove ci siamo interrotti. In questo modo possiamo elaborare un grosso file in diversi "chunk" più piccoli.

## Leggere i file di testo riga per riga con readline()

Possiamo fare anche il parsing dei dati in un file leggendolo riga dopo riga. Qesto ci può pemrettere di scansionare un intero file riga per riga, avanzando solo quando vogliamo, o vedere una linea specifica.

Il metodo `oggetto_file.readline(size)` di defeault restituisce la prima riga del file. Ma cambiando il parametro `size`, possiamo ottenere una qualsiasi riga che vogliamo nel nostro file.

Ad esempio:

```py
with open("workData.txt", "r+") as work_data:
     print("This is the file name: ", work_data.name)
     line_data = work_data.readline()
     print(line_data)
```

Questo restituirà l'uscita come:

```sh
This is the file name:  workData.txt
This data is on line 1
```

Possiamo chiamare `readline()` ripetutamente per leggere ulteriori righe di test dal file.

Un metodo simile è `fileobject.readlines()` (al plurale), che restiusce una lista di tutte le righe nel file. Se facciamo una chiamata a questo:

```py
print(work_data.readlines())
```

Avremo il seguente output:

```py
['This data is on line 1', 'This data is on line 2', 'This data is on line 3']
```

Come possiamo vedere, questo legge l'intero file in memoria e lo suddivide in diverse righe. Questo funziona soltanto con i file di testo. Un file binario è soltanto un insieme di dati - non ha associato quindi il concetto di quello che rappresenta la singola riga.

## Elaborare un intero file di testo riga per riga

Il modo più semplice per elaborare un intero file di testo riga per riga in Python è usare un semplice ciclo:

```py
with open("workData.txt", "r+") as work_data:
    for line in work_data:
        print(line)
```

Queste istruzioni hanno il seguente output:

```sh
This data is on line 1
This data is on line 2
This data is on line 3
```

Questo approccio è in realtà più efficiente del precedente, perché leggeremo ed elaboreremo ogni riga individualmente. In questo modo, il programma non deve leggere l'intero file in memoria insieme. QUindi, usare `readline()` è un modo semplice ed efficiente per elaborare un grosso file di testo in parti più piccole.

## Scrivere su file con Python mediante write()

I file non servirebbero a molto se non possiamo scriverci dei dati. Vediamo quindi questo aspetto.

Ricordiamo che quando creiamo un nuovo oggetto di tipo file, Python crea il file se non ne esiste già uno. QUando si crea un file per la prima volta, dobbiamo usare i modi `a+` o `w+`.

Spesso è preferibile usare il modo `a+` perché i dati saranno di default aggiunti alla fine del file. USare `w+` cancellerà i dati esistenti nel file.

Il meotod di default per scrivere nuovi dati in un file Python è mediante `oggetto_file.write(data)`. Per esempio, possiamo aggiungere una nuova riga al file `dati.txt` usando il seguente codice:

```py
work_data.write("This data is on line 4\n")
```

La sequenza `\n` indica una nuova riga, il che fa in modo che le scritture successive avvengano sulla riga successiva.

Se vogliamos scrivere qualcosa che non sia una stringa su un file di testo, come una serie di numeri, dovremo convertirli (ovvero, effettuarne il *cast*) in stringhe, usando l'opportuno codice di conversione.

Per esempio, se vogliamo aggiungere gli interi `1234`, `5678`, `9012` al file `dati`, faremo il seguente.

Per prima cosa, faremo il cast delle non-strighe a stringhe, quindi scriveremo quella stringa all'oggetto file:

```py
values = [1234, 5678, 9012]

with open("workData.txt", "a+") as work_data:
    for value in values:
        str_value = str(value)
        work_data.write(str_value)
        work_data.write("\n")
```

## Ricerca nei file: spostare il puntatore read/write

Ricordiamo che quando scriviamo usando la modalità `a+`, il puntatore al file va sempre alla fine del file stesso. Di conseguenza, prende il codice che abbiamo scritto prima, se usiamo il metodo `fileobject.write()`, non avremo niente in uscita. Questo è legato al fatto che il metodo sta guardando al puntatore per trovare del testo aggiuntivo.

Quello che dobbiamo fare allora è muovere il puntatore all'inizio del file. Il modo più semplice di farlo è usare il metodo `seek(offset, from_what)`. In questo meotod, inseriamo il puntatore in un punto specifico.

L'offset è il numero di caratteri dal parametro `from_what`. Il parametro `from_what` ha tre possibili valori:

* 0: indica l'inizio del file
* 1: indica il puntaore alla posizioen attuale
* 2: indica la fine del file

Quando stiamo lavorando con file di testo (quelli che sono stati aperti senza una `b` indicata nel modo), possiamo usare soltanto il valore `0`, o un `2`, che ci porta alla fine del file.

Quindi, usare `data.seek(3, 0)` sul nostro file `data.txt` ci farà piazzare il puntatore al quarto carattere (ricordiamo che il conteggio in Python parte da 0). Se usiamo il ciclo per il print, allora avremo un output come:

```sh
s data is on line 1
This data is on line 2
This data is on line 3
```

Se vogliamo controllare la poszione attuale del puntatore, possiamo usare il metodo `tell()`, che restituisce un valore decimale per dove il puntatore è nel file attuale. Se vogliamo capire quanto è lungo il file `data` attuale, possiamo usare il seguente codice:

```py
with open("workData.txt", "a+") as work_data:
    print(work_data.tell())
```

Questo ci darà un valore di ritorno di 69, che rappresenta la dimensione del file.

## Editare un file di testo esistente con Python

Ci saranno delle situazioni dove dobbiamo modifiacre un file esistente piuttosto che semplicemente aggiungervi dei dati. Per farlo, non possiamo semplicemente usare la modalità `w+`. Ricordiamo che la modalità `w` effettuerà una completa soprascrittura del file, per cui anche quando si usa `seek()` non saremo in grado di farlo. E `a+` inserirà sempre i dati alla fine del file.

Il modo più semplice per farlo prevede l'estrazione dell'intero file e la creazione di una lista o di un array con questo. Una volta creata la lista, possiamo usare il metodo `insert(i, x)` per inserire i nuovi dati. Una volta modificata la lista, possiamo effettuarne il join e scriveral sul nostro file.

Ricordiamo che `insert(i, x)` prevede che `i` sia un intero che indica il numero della cella. I dati di `x` sono quindi piazzati prima della cella nella lista idnicata da `i`.

Ad esempio, usando il file `data.txt`, diciamo che dobbiamo inserire la riga successiva, ovvero `Questo va tra la riga 1 e la riga 2`, tra la prima e la seconda riga. Il codice per farlo è:

```py
# Open the file as read-only
with open("workData.txt", "r") as work_data:
    work_data_contents = work_data.readlines()

work_data_contents.insert(1, "This goes between line 1 and 2\n")

# Re-open in write-only format to overwrite old file
with open("workData.txt", "w") as work_data:
    work_dataContents = "".join(work_data_contents)
    work_data.write(work_data_contents)
```

Una volta che eseguiamo questo codice, se scriviamo le seguenti istruzioni:

```py
with open("workData.txt", "r") as work_data:
    for line in work_data:
        print(line)
```

Avremo un output di:

```sh
This data is on line 1
This goes between line 1 and 2
This data is on line 2
This data is on line 3
```

Abbiamo quindi visto un metodo per modificare un file esistente in Python, inserendo una nuova riga di testo esattamente nel posto che volevamo.
