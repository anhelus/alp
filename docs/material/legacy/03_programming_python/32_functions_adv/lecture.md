# 34 - Concetti avanzati sulle funzioni Python

Quando abbiamo introdotto i [decorators](../32_decorators/lecture.md), abbiamo accennato al fatto che Python tratti le funzioni come degli oggetti. Possiamo assegnarle a delle variabili, memorizzarle in strutture dati, passarle come argomenti ad altre funzioni, ed anche restituirle come valori da altre funzioni.

Afferrare questi concetti ci permetterà di comprendere feature avanzate in Python come le lambda ed i decorator in modo molto più semplice, oltre che aiutarci a capire le tecniche di programmazione funzionale.

In questa lezione vedremo alcuni esempi che ci aiuteranno a sviluppare questa conoscenza. Tuttavia, la comprensione di questi concetti potrebbe risultare leggermente più complessa di qunato potreste attendervi. Non preoccupatevi.

Attraverso questo tutorial, utilizzeremo una funzione chiamata `grida` a scopi dimostrativi, che sarà caratterizzata da un output tutto in maiuscolo del tipo:

```py
def yell(text):
    return text.upper() + '!'

>>> yell('hello')
'HELLO!'
```

## Le funzioni sono oggetti

Tutti i dati in un programma Python sono rappresentati da oggetti o relazioni tra oggetti. Cose come stringhe, liste, moduli e funzioni sono oggetti. Non vi è nulla di particolarmente speciale nelle funzioni Python.

Dato che la funzione urla è un oggetto in Python, possiamo assegnarla ad un'altra variabile, proprio come ogni altro oggetto:

```py
>>> abbaia = urla
```

Questa riga non chiama la funzione. Prende l'oggetto funzione riferito ad urla e crea un secondo nome che vi punta, `abbaia`. Possiamo adesso anche eseguire la stessa funzione chiamando abbaia:

```py
>>> abbaia('bau')
'BAU!'
```

Gli oggetti funzione ed i loro nomi sono due cose separate. Possiamo cancellare il nomer della funzione originale, ovvero `urla`; dato che un altro nome (`abbaia`) punta ancora alla funzione sottostante, possiamo sempre chiamarla:

```py
>>> del yell

>>> yell('hello?')
NameError: "name 'yell' is not defined"

>>> bark('hey')
'HEY!'
```

D'altronde, Python collega un identificatore sotto forma di stringa ad ogni funzione nel momento in cui viene creata a socpo di debugging. POssiamo accedere a questo identificatore interno con l'attributo `__name__`:

```
>>> bark.__name__
'yell'
```

Il fatto che il `__name__` della funzione sia sempre `urla` non andrà ad impattare sul come possiamo accedervi dal nostro codice. Questo identificaotre è semplicemente un aiuto per il debugging. Una variabile che punta ad una funzione e la funzione stessa sono concetti separati.

!!!note "Nota"
    A partire da Python 3.3, vi è anche `__qualname__`, che asserve ad uno scopo simile e fornisce una stringa per disambiguare i nomi di funzioni e classi.

## Le funzioni possono essere memorizzate ins trutture dati

Dato che le funzioni sono degli oggetti, possiamo memorizzarle in strutture dati, proprio come possiamo fare con altri oggeti. Ad esempio, possiamo aggiungere le funzioni ad una lista:

```py
>>> funcs = [bark, str.lower, str.capitalize]
>>> funcs
[<function yell at 0x10ff96510>,
 <method 'lower' of 'str' objects>,
 <method 'capitalize' of 'str' objects>]
```

Accedere agli oggetti funzione memorizzati all'interno della lista funziona come funzionerebbe in ogni altro tipo di oggetto:

```py
>>> for f in funcs:
...     print(f, f('hey there'))
<function yell at 0x10ff96510> 'HEY THERE!'
<method 'lower' of 'str' objects> 'hey there'
<method 'capitalize' of 'str' objects> 'Hey there'
```

Possiamo anche chiamare un oggetto fuznine memorizzato nella lista senza assegnarli prima una variabile. Possiamo fare il lookup ed immediatamente chiamare la funzione in una singola espressione:

```py
>>> funcs[0]('heyho')
'HEYHO!'
```

## Le funzioni possono essere passate ad altre funzioni

Dato che le funzioni sono oggetti possiamo passarle come argomenti ad altre funzioni. Ad esempio, una funzione greet che formatta una stirnga di benvenuto usando l'oggetto funzione passatogli e quindi stampandolo:

```py
def greet(func):
    greeting = func('Hi, I am a Python program')
    print(greeting)
```

Possiamo influenzare il benvenuto risultante passandolo in diverse funzioni. Ecco cosa acccade sed passiamo la funzione yell a greet:

```py
>>> greet(yell)
'HI, I AM A PYTHON PROGRAM!'
```

OVviamente possioamo anche definire una nuova funzione per generare un diverso tipo di benvenutto. Ad esempio, la seocnda funzione "sussurra" lavorerà meglio se vogliamo un programma Pythondiscreto:

```py
def whisper(text):
    return text.lower() + '...'

>>> greet(whisper)
'hi, i am a python program...'
```

La capacità di passare oggetti funzione come argomenti ad altre funzioni è potenbte. Ci perm,ette di astrarci e passare il comportamento dei nostri programmi. In questo esempio, la funzione greet rimane la stessa ma possiamo influenzare l'output passando diversi comportmaenti di benvenuto.

Le funzioni che possono accettare altre funzioni come argomenti sono anche chiamate *funzioni di ordine superiore*. Sonmo una necessità per lo stile di programmazione funzionale.

IOl classico esempio di funzioni di ordine superiore in Python è la funzione integrata `map`. Prende una funzione ed un iteratore, e chiama la funzione su ogni elemento dell'iteratore, restituiendo il risultato man mano che questo scorre.

Ecco come potremmo formattare una sequenza di benvenuto in una volta mappando la funzione yell:

```py
>>> list(map(yell, ['hello', 'hey', 'hi']))
['HELLO!', 'HEY!', 'HI!']
```

La funzione `map` ha attraversato l'intera lista applicando la funzione `yell` ad ogni elemnto.

### LE funzioni possono essere annidate

Python permette alle funzioni di essere definite all'interno di altre funzioni. Queste sono spesso chiuamate funzioni annidate o inner function. Ecco un esempio:

```py
def speak(text):
    def whisper(t):
        return t.lower() + '...'
    return whisper(text)

>>> speak('Hello, World')
'hello, world...'
```

Cosa sta succedendo? Ogni volta che chiamiamo `speak` definisce una nuova funzione itnerna `whisper` e la chiama. La funzione `whisper` non esiste all'estenro di `speak`:

```py
>>> whisper('Yo')
NameError: "name 'whisper' is not defined"

>>> speak.whisper
AttributeError: "'function' object has no attribute 'whisper'"
```

Ma cosa succede se vogliamo accedere a questa funzione annidata dall'esterno? Le funzioni sono oggetti - per cui possiamo restituire la funzione interna al chiuamante della funzione padre. Ad esempio, ecco una funzione che definsice due funzioni annidate. A seconda dell'argomento passato alla funzione top-level, viene selezionato e restituito una delle funzioni itnerne al chiamante:

```py
def get_speak_func(volume):
    def whisper(text):
        return text.lower() + '...'
    def yell(text):
        return text.upper() + '!'
    if volume > 0.5:
        return yell
    else:
        return whisper
```

Notiamo come `get_speak_func` non chiama uno delle sue funzioni interne - semplicemente seleziona la funzione appropriata sulla base dell'argomento `volume` e restituisce l'oggetto function:

```py
>>> get_speak_func(0.3)
<function get_speak_func.<locals>.whisper at 0x10ae18>

>>> get_speak_func(0.7)
<function get_speak_func.<locals>.yell at 0x1008c8>
```

Naturalmente psosiamo chiamare la funzionem restituita, sia direttamente o assegnandola ad un nome di una variabile:

```py
>>> speak_func = get_speak_func(0.7)
>>> speak_func('Hello')
'HELLO!'
```

Questo singifca che non solo le funzioni accettano i comportamento attraverso gli argomenti, ma che possono anche restituire dei comportamenti.

## Le funzioni possono catturare lo stato locale

Abbiamo appena visto come le funzioni possono contenere delle funzioni annidate ed è possibile restiruire quest'ultime dalla funzione padre.

Non solo le funzioni possono restiure altre funzioni, queste funzioni annidate possono anche catturare e portare parte dello stato della funzione padre con loro.

Riscriviamo leggermente l'esempio `get_speak_func` precedente. La nuova versione prende un argomento `volume`e `text` per rendere la funzione resittuira immediatamente chiamabile:

```py
def get_speak_func(text, volume):
    def whisper():
        return text.lower() + '...'
    def yell():
        return text.upper() + '!'
    if volume > 0.5:
        return yell
    else:
        return whisper

>>> get_speak_func('Hello, World', 0.7)()
'HELLO, WORLD!'
```

Vediamo per bene le funzioni annidate `whisper`e `yell`. Notiamo che non hanno più un parametro `text`, ma accedono al parametro definito nella funzione padre. Infatti, sembrano poter cattruare e ricordare il valore di questll'argomento. Le funzioni che fanno questo sono chiamate *closure lessicali*, o *closure*. Una closure ricorda i valori dell'ambito lessicale nel quale è inserita anche quando il flusso di programma non è più in quell'ambito. In termini pratici, questo signifca non solo che le funzioni restituiscono dei comportamenti, ma possono anche pre-configurarli. Ecco un altro esempio per illustrare questa idea:

```py
def make_adder(n):
    def add(x):
        return x + n
    return add

>>> plus_3 = make_adder(3)
>>> plus_5 = make_adder(5)

>>> plus_3(4)
7
>>> plus_5(4)
9
```

In questo esempio `make_adder` serve come una factory epr creare e configurare delle funzioni `somma`. Notiamo come le funzion `somma` possanoo ssempre accedere all'argomento `n` della funzione `make_adder` (che è nell'ambito che le racchidue).

### Gli oggetti si possono comportare come funzioni

Gli oggetti non sono necessariamente funzioni. Ma possono essere resi chiamabili, il che ci permette di trattarli come funzioni in molti casi.

SE un oggetto è chiamabile, significa che possiamo suare parentesi tonde e passargli degli argomenti di chiamata a funzione. Ad esempio:

```py
class Adder:
    def __init__(self, n):
         self.n = n
    def __call__(self, x):
        return self.n + x

>>> plus_3 = Adder(3)
>>> plus_3(4)
7
```

Dietro il cofano, chjiamare un'istanza di un oggetto come una fuinzione prova ad eseguire il metodo `__call__` dell'0oggetto. Ovviament4e, non tutti gli oggetti saranno chiamabili. Ecco perché vi è una funzione built-in `callable` che controlla se un oggetto è callable o no:

```py
>>> callable(plus_3)
True
>>> callable(yell)
True
>>> callable(False)
False
```

## Note finali

Tutto in Python è un oggetto, incluse le funzioni. Possiamo assegnarle a variabili, memorizzarle in strutture dati, e passarle o restituirle da e verso altre funzioni. Questo ci permette di astrarre il comportamento nei nostri programmi.

Le funzioni possono essere annidate, e possono catturare e portare parte dello stato delle funzioni padre con loro. Le funzioni che fanno questo sono chiamate clousres.

Gli oggetti possono essere resi chiamabili, il che ci permette di trattarli spesso come funzioni.
