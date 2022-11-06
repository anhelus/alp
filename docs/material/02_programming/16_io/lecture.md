# 16 - Lettura e scrittura di file in Python

Python ha diversi modelli e funzioni integrati per la gesitone dei file. Queste funzioni sono divise in diversi moduli, come os, os.-path, shutil e pathlib., tra gli altri. In questa lezione, vedremo molte delle funzioni pèrincipali di cui abbiamo bisogno per effettuare le operazioni più comuni sui file di Python.

## 16.1 - Il pattern "with open (...) as (...)"

Leggere e scrivere i dati sui file usando Python è semplice. Per farlo, dobbiamo epr prima cosa aprire i file in modalità appropriata. Ecco un esempio di come usare il pattern `with open (...) as ...` per aprire un file di testo e leggere i suoi contenuti:

```py
with open('data.txt', 'r') as f:
    data = f.read()
```

`open()` prende il nome di un file ed una modalità di apertura dello stesso come primo e secondo parametro, rispettivmaente. In particolare, `r` apre i file in modalità di sola lettura. Per scrivere i dati su file, dobbiamo passare come argomento un `w`:

```py
with open('data.txt', 'w') as f:
    f.write('dati da scrivere nel file')
```

Nell'esempio precedente, `open()` apre i file in lettura o scrittura e restituisce un *handle*, ovvero un riferimento, al file, che fornisce dei metodi  che psosono essere usati per scrivere o leggere i dati su file.

## 16.2 FIle di testo vs. file binari

Ci sono due tipi differenti di file che Python può gestire: i file *binari* ed i file di *testo*. Conoscere la differenza tra i due è importante per come sono gestiti.

La maggior parte dei file che possiamo usare durante l'uso normale del computer sono dei file binari, non testo. Anche il file di Microsoftw Word è in realtà un file binario, anche se ha soltanto del testo al suo interno. Altri esempi di file binari includono:

* immagini;
* database;
* fogli Excel;

e via dicendo.

Questo è legato al fatto che questi file hanno dei requisiti speciali di gestione, e richiedono uno specifico software per essere aperti. Ad esempio, abbiamo bisogno di Excel per aprire un foiglio Excel, o di Word per aprire un documento Word.

Un *file di testo*, invece, non ha una codifica specifica, e può essere aperto da un editor di testo standard senza alcuna gestione specifica. Tuttavia, ogni file di testo deve aderire ad alcune regole specificeh:

* i file di testo devono essere leggibili "as is". Spesso contengono delle codifiche speciali, specialmente in HTML, ma saremo comuqnue in grado di leggere quello che dicono.
* I dati in un file di testo sono organizzati in righe. Nella maggior parte dei casi, ogni riga è un elemento distinto, sia che sia una riga di istruzione o un comando.

Inoltre, i file di testo hanno dei caratteri non visti al termine di orgni riga che permettono all'editor di testo di sapere dove c'è una nuova riga. Quando siinteragisce con questi file mediante la programmazione, possiamo sfruttare questi caratteri. In Python ed in molti altri linguaggi, è definto mediante la sequenza di escape "\n".

## Dove trovare i tool per l'I/O in Python

Quando si lavora in Python, non dobbiamo preoccuparci di importare una libreria esterna per lavorare con i file, in qunato sono integrati nella parte fondamentale del linguaggio. In altri linguaggi come il C++, per lavorare con i file dobbiamo abilitare i tool di I/O includendo l'header corretto, per esempio #include <fstream>, o in Java dobbiamo importare l'iustruzioen import java.io.*.

Invece, Python ha un insieme integrato di funzioni che gestiscono tuttoi quello di cui abbiamo bisogno per leggere e scrivere sui file. Vediamole di seguito.

## Apertura di un file in Python

La prima funzione che dobbiamo conoscere è `open()`. Presente sia in Python 2 sia in Python 3, questo comando restituisce un opggetto di tipo file come specificato dai parmaetri passati. L'utilizzo base di open() è il seguente: 

file = open(nome_file, modo)

In questo caso, `nome_file` è ovviamente il nome del file con il quale vogliamo interagire, con l'estensione inclusa. Questo significa che se abbiamo un file di testo chiamato `dati.txt`, il nome del file da inserire sarà proprio `dati.txt`, e non solo `dati`.

Possiamo anche specificare il percorso esatto del file, come C:\Lavoro\dati.txt (se, ad esempio, stiamo usando Windows).

E' opportuno ricordare che una singola backslash è una stringa che indica a Python l'inizio di un literal. Quindi, qui abbiamo un problema, perché questi due significati avranno un conflitto.

Per fortuna, abbiamo diversi modi di risolvere questo problema. Il primo è quello di usare due backslash, in questo modo:

```py
'C:\\Lavoro\\dati.txt'
```

L'altro è usare gli slash normali:

```py
'C:/Lavoro/dati.txt'
```

Per quello che riguarda il modo, questo dice a Python cosa vogliamo fare con il nostro file. Ci sono diversi modi che possiamo specificare quando ci occupiamo di file di testo.

| Modo | Descrizione |
| ---- | ----------- |
| 'w' | Write: questo modo è usato qunaodo il file deve essere modificato, e diverse informazioni cambiate o aggiutne. Teniamo a mente che questo cancella il file esistente per crearne uno nuov. Il puntatore al file è piazzato all'inizio del file. |
| 'r' | Read: questo modo va usato quanod le infomraizoni nel file devono soltanto essere lette, e non modificate in alcun modo. Il puntatore al file è piazzato all'inizio del file. |
| 'a' | Append: questo modo aggiunge delle ulteriori informazioni al terminee del file in maniera automatica. Il putnatore al file è piazzato al termine del file. |
| 'r+' | Read/Write: questa modalità viene usata quando faremo dei cambi al file, e leggeremo le informazioni dallo stesso. Il puntatore al file è piazzato all'inizio del file |
| 'a+' | Append/Read: un ifle è aperto per permettere l'aggiunta di dati alla fine del file e permetterne anche la lettura. Il putnatore al file è piazzato alla fine del file. |
| x | Exclusive Creation: questo modo è usato esclusivamente per creare un file. Se un file con lo stesso nome esiste, la chiamata a funzione fallirà.

Quando stiamo usando file bianri, useremo gli stessi specificatori, ma aggiungeremo una 'b' al termine del file. Quindi:

| Modalità | Shortcut (testo) | Shortcut (binario) |
| -------- | ---------------- | ------------------ |
| Write | 'w' | 'wb' |
| Read | 'r' | 'rb' |
| Append | 'a' | 'ab' |
| Read/Write | r+ | rb+ |
| Append/Read | a+ | ab+ |
| Exclusive Creation | x | xb |

Veidmao un esempio di compe aprire un file ed impostare la modalità di accesso 

Quando si usa la funzikone open(), tipicamente si assegna il suo risultato ad una varibile. Dato un nome chiamato dati.txt, il codice per aprire il file in modalità di lettura e scrittura è il seguente:

data_file = open('dati.txt', 'r+')

Questo crea un oggetto chiamato file_dati che possiamo manipolare mediante opportunio metodi. Abbiamo usato la modalità di accesso r+ in questo esempio che dice a Python che vogliamo aprire il file per la lettura e la scrittura. Questo ci dà molta flesisbilità, ma spesso potremmo voler restirngere il nostro programma alla semplice lettura o scritutra, e questo è quando le altre modalità vengono in aiuto.

## Chiusura di un file in Python

Sapere come chiudere un file è importante quando siamo il lettura e scrittura.

In questo modo, liberiamo le risorse di sistema che il nostro programma sta usando a scopo di I/O. Qunado scriviamo un programma che ha vincoli di spazio o memoria, questo ci permette di gestire le nostre risorse in maniera efficace.

Inoltre, chiudere un file ci assicura che ogni dato "pendente" viene scritto nel sistema di memoria sottostante, ad esempio, il disco locale. Chiudendo esplicitamente il file ci assicuriamo che ogni dato bufferizzato in memorria venga rimosso e scritto sul file.

La funzione per chiudere un file in Pyuthon è semplicemente oggetto_file.close(). Usando l'oggetto data_file che abbiamo creato nell'esempio precedente, il comando per chiuderlo sarebbe:

```py
data_file.close()
```

Dopo che chiudiamo il file, non possiamo più accedervi a meno che non lo riapriamo successivamente. Provare a leggere o scrivere un file chiuso lancerà un'eccezione ValueError:

```py
>>> f = open("/tmp/myfile.txt", "w")
>>> f.close()
>>> f.read()
Traceback (most recent call last):
  File "<input>", line 1, in <module>
    f.read()
ValueError: I/O operation on closed file.
```

In Python, la best practice per aprire e chiudere i file usa la parola chiave `with`. Questa parola chiave chiude il file automaticamente dopo che si completa il blocco di codice annidato:

```py
with open("workData.txt", "r+") as workData:
    # File object is now open.
    # Do stuff with the file:
    workData.read()

# File object is now closed.
# Do other things...
```

Se non usiamo la parola chiave `with` o usiamo la funzione `fileobject.close()` allora Python chiuderà in automatico e distruggerà l'oggetto file attraverso il suo garbage collector integrato. Tuttavia, a seconda del nostro codice, la garbage collection può avvenire in ogni istante. 

Per cui è raccomandabile usare la parola chiave `with` per controllare quando il file sarà chiuso - in pratica dopo che il blocco di codice interno finisce la sua esecuzione.

## Lavorare ocn gli oggetti di tipo file

Una volta che abbiamo aperto con successo un file, possiamo usare i metodi built-in per occuparci il nuovo oggetto file. Possiamo leggere i dati da questo, o scrivervi nuovi dati. Ci sono anche altre operazioni come muovere il "puntatore read/write", che determinaon dove vengono letti i dati dal file e dove sono scritti. Vedremo questo più avanti nella lezione.

Adesso vedremo come leggere i dati da un file che abbiamo aperto.

## Lettura dei dati da un file in Python

Leggere i contenuti di un file avviene emdiante il metodo `oggetto_file.read(dimensione)`. Di defautl, questo metodo leggerà l'intero file e lo stamperà su console come una stringa (in modalità testo) o come un oggetto byte (in modalità binaria).

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



DA QUI


If you read from the same file object again, it will continue reading data where you left off. That way you can process a large file in several smaller “chunks.”

Reading Text Files Line-by-Line With readline()
You can also parse data in a file by reading it line by line. This can let you scan an entire file line by line, advancing only when you want to, or let you see a specific line.

The fileobject.readline(size) method defaults to returning the first line of the file. But by changing the integer size parameter, you can get any line in your file you need.

For example:

with open("workData.txt", "r+") as work_data:
     print("This is the file name: ", work_data.name)
     line_data = work_data.readline()
     print(line_data)
This would return the output of:

This is the file name:  workData.txt
This data is on line 1
You can call readline() repeatedly to read additional lines of text from the file.

A similar method is the fileobject.readlines() call (notice the plural), which returns a list of all lines in the file. If you did a call of:

print(work_data.readlines())
You would get the following output:

['This data is on line 1', 'This data is on line 2', 'This data is on line 3']
As you can see, this reads the whole file into memory and splits it up into several lines. This only works with text files however. A binary file is just a blob of data—it doesn’t really have a concept of what a single line is.

Processing an Entire Text File Line-By-Line
The easiest way to process an entire text file line-by-line in Python is by using a simple loop:

with open("workData.txt", "r+") as work_data:
    for line in work_data:
        print(line)
This has the following output:

This data is on line 1
This data is on line 2
This data is on line 3
This approach is very memory-efficient, because we’ll be reading and processing each line individually. This means our program never needs to read the whole file into memory at once. Thus, using readline() is a comfortable and efficient way to process a big text file in smaller chunks.

Writing to a File With Python Using write()
Files wouldn’t be any good if you couldn’t write data to them. So let’s discuss that.

Remember that when you create a new file object, Python will create the file if one doesn’t already exist. When creating a file for the first time, you should either use the a+ or w+ modes.

Often it’s preferable to use the a+ mode because the data will default to be added to the end of the file. Using w+ will clear out any existing data in the file and give you a “blank slate” to start from.

The default method of writing to a file in Python is using fileobject.write(data). For example, you could add a new line to our “workData.txt” file by using the following code:

work_data.write("This data is on line 4\n")
The \n acts as the new line indicator, moving subsequent writes to the next line.

If you want to write something that isn’t a string to a text file, such as a series of numbers, you have to convert or “cast” them to strings, using conversion code.

For example, if you wanted to add the integers 1234, 5678, 9012 to the work_data file, you’d do the following. First, you cast your non-strings as a string, then you write that string to your file object:

values = [1234, 5678, 9012]

with open("workData.txt", "a+") as work_data:
    for value in values:
        str_value = str(value)
        work_data.write(str_value)
        work_data.write("\n")
File Seeks: Moving the Read/Write Pointer
Remember that when you write using the a+ mode, your file pointer is always going to be at the end of the file. So taking the above code where we’ve written the two numbers, if you use the fileobject.write() method, you’re not going to get anything in return. That’s because that method is looking after the pointer to find additional text.

What you need to do then, is move the pointer back to the beginning of the file. The easiest way to do this is to use the fileobject.seek(offset, from_what) method. In this method, you put the pointer at a specific spot.

The offset is the number of characters from the from_what parameter. The from_what parameter has three possible values:

0 – indicates the beginning of the file
1 – indicates the current pointer position
2 – indicates the end of the file
When you’re working with text files (those that have been opened without a b in the mode), you can only use the default 0, or a seek(0, 2), which will take you to the end of the file.

So by using work_data.seek(3, 0) on our “workData.txt” file, you will place the pointer at the 4th character (remember that Python starts counts at 0). If you use the line print loop, you would then get an output of:

s data is on line 1
This data is on line 2
This data is on line 3
If you want to check the current position of the pointer, you can use the fileobject.tell() method, which returns a decimal value for where the pointer is at in the current file. If we want to find how long our current work_data file is, we can use the following code:

with open("workData.txt", "a+") as work_data:
    print(work_data.tell())
This will give a return value of 69, which is the size of the file.

Editing an Existing Text File with Python
There will come a time when you need to edit an existing file rather than just append data to it. You can’t just use w+ mode to do it. Remember that mode w will completely overwrite the file, so even with using fileobject.seek(), you won’t be able to do it. And a+ will always insert any data at the end of the file.

The easiest way to do it involves pulling the entire file out and creating a list or array data type with it. Once the list is created, you can use the list.insert(i, x) method to insert your new data. Once the new list is created, you can then join it back together and write it back to your file.

Remember that for list.insert(i, x), i is an integer that indicates the cell number. The data of x then is placed before the cell in the list indicated by i.

For example, using our “workData.txt” file, let’s say we needed to insert the text line, “This goes between line 1 and 2” in between the first and second lines. The code to do it is:

# Open the file as read-only
with open("workData.txt", "r") as work_data:
    work_data_contents = work_data.readlines()

work_data_contents.insert(1, "This goes between line 1 and 2\n")

# Re-open in write-only format to overwrite old file
with open("workData.txt", "w") as work_data:
    work_dataContents = "".join(work_data_contents)
    work_data.write(work_data_contents)
Once this code runs, if you do the following:

with open("workData.txt", "r") as work_data:
    for line in work_data:
        print(line)
You’ll get an output of:

This data is on line 1
This goes between line 1 and 2
This data is on line 2
This data is on line 3
This demonstrated how to edit an existing text file in Python, inserting a new line of text at exactly the place you wanted.
