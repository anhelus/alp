# 16 - Lettura e scrittura di file in Python

Python offre numerose funzioni (già integrate nel *core* del linguaggio) per la gestione dei file. Queste sono a loro volta divise in vari moduli, quali (ad esempio) [`os`](https://docs.python.org/3/library/os.html), [`shutil`](https://docs.python.org/3/library/shutil.html) e [`pathlib`](https://docs.python.org/3/library/pathlib.html).

In questa lezione, vedremo alcune tra le principali funzioni usate per effettuare le più comuni operazioni sui file Python.

## 16.1 File di testo vs. file binari

Prima di passare a vedere le principali funzioni usate da Python per la gestione dei file, dobbiamo parlare dei due diversi *tipi* di file esistenti, ovvero file *binari* e file di *testo*.

La maggior parte dei file che usiamo durante il normale utilizzo del computer sono, infatti, file di tipo *binario*. Nonostante quello che si possa pensare, infatti, anche un documento di Word (o di un programma equivalente) è, in realtà, un file binario, pur avendo soltanto del testo al suo interno. Altri esempi di file binario sono dati dalle immagini, dai database, o anche dai fogli Excel. Ciò è principalmente legato al fatto che file di questo tipo sono, in realtà, codificati in un formato che rende necessario un software specifico per la loro apertura.

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
