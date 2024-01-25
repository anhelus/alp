La maggior parte dei linguaggi OOP come Java, C++, C# hanno il concetto di un costruttore, un metodo speciale che crei ed inizializzi l'oggetto quando viene creato. Python è un po' differente: ha un costruttore ed un inizializzatore. La funzione costruttore è raramente usata a meno che non stia facendo qualcosa di esotico. Di conseguenza, iniziamo la nostra discussione con il metodo di inizializzazione.

La funzione costruttore in Python è chiamata __new__ ed __init__ è la funzione di inizializzazione.

Andardo a riprendere la documentazione Python, __new__ è usato qunado abbiamo bisogno di controllare la creazione di una nuova istanza mentre __init__ è usato quando abbaimo bisogno dell'inizializzazione di una nuova istanza.

__new__ è il primo step della creazione dell'istanza. E' chiamata per prima ed è responsabile per restituire una nuova istanza della nosttra classe.

In contrasto, __init__ non restituisce niente: è responsabile soltanto per inizializzare l'istanza dopo che è stata creata. In generale, non dovremo sovrascrivere il metodo __new__, a meno che non stiamo andando ad usare una subclass per un tipo immutabile come str, int, Unicode o tuple.

## Costruttori di class in Python ed il processo di Istanziamento

Come molti altri linguaggi di programmazione, Python supporta la OOP. Al centro delle capacità object-oriented di Python, troveremo la keyword class, che ci permette di definire le classi custom che possono avere degli attributi per memorizzare i dati ed i metodi per fornire dei comportamenti.

Una volta avuta una classe con cui lavorare, a questo punto possiamo iniziare a creare nuove istanze o ogetti della classe, che è un modo efficiente per riutilizzare le funzionalità nel nostro codice.

Creare ed inizializzare gli oggetti di una data classe sono uno step fondamentale nella OOP. Questo passo è spesso riferito come costruzione o istanziamento degli oggetti. I tool responsabile per creare questo processo di istanziamento è spesso conosciuto come costruttore di classe.

## Conoscere i costruttori di classe di Python

In Python, per costruire un oggetto di una data classe, dobbiamo soltanto chiamare la classe con degli argomenti appropriati, così come chiameremmo una qualsiasi funzione:

```py
class SomeClass:
    pass

SomeClass()
#FAR VEDRE LA CALSSE
```

In questo esempio, definiamo SomeClass usando la parola chiave class. QUesta classe è al momento vuota perché non ha attributi o metodi. Invece, il corpo della classe contiene soltanto un'istruzione pass come istruzione "placeholder" che non fa niente.

Quindi creiamo una nuova istanza di SomeClass chiamando la clase con una coppia di paretnesi. In questo esempio, non dobbiamo passare alcun argomento nella chiamata perché la nostra classe non prende ancora alcun argomento.

In Python, quando chiamiamo una classe come fatto nell'esempio prcecente, stiamo chiamando il costruttore di classe, che crea, inizializza e restituisce un nuovo oggetto lanciando il processo interno di istanziamento di Python.

Un ultimo punto da notare è che chiamare una classe non è lo stesso di chiamare un'*istanza* di una classe. Questi sono due topic differenti e completamente incorrelati. Per rendere chiamabile l'istanza di una classe, dobbiamo implementare un metodo speciale __call(), che non ha niente a che fare con il processo di istanziamento di Python.

## Comprendere il processo di istanziamento di Python

Lanciamo il processo di istanziamento di PYthon quando chiamiamo una classe Python per creare una nuova istanza. Questo processo viene eseguito in due step separati, che possiamo descrivere come segue:

* creazione di una nuova istanza della classe target
* inizializzazione della nuova istanza con uno stato iniziale appropriato

Per eseguire il primo step, le classi Python hanno un metodo speciale chiamato __new__(), che è responsabile per la creazione e la restituzione di un nuovo oggetto vuoto. A questo punto un nuovo metodo speciale, __init__(), prende l'oggetto risultante, assieme agli argomenti del costruttore di classe.

Il metodo __init__ prende il nuovo oggetto come suo primo argometno, `self`. Quindi imposta ogni attributo dell'istanza richiesto ad uno stato valido usando gli argomenti che gli ha passato il costruttore di classe.

In breve, il processo di istanziamento di Python inizia con una chiamata al costruttore di classe, che lancia il creatore dell'istanza, __new__(), facendogli creare un nuovo oggetot vuoto. Il processo continua con l'inizializzatore dell'istanza, __inti__(), che prende gli argometni del crostruttore per inizializzare l'oggetto appena creato.

Per esploare il processo di istanziamento di Python internamente, possiamoc consdierare il seguente esempio di una classe Punto che implementa una versione custom di entrambi i metodi.

```py linenums="1"
class Punto:
    def __new__(cls, *args, **kwargs):
        print("1. Creazione di una nuova istanza di Punto.")
        return super().__new__(cls)

    def __init__(self, x, y):
        print("2. Inizializzazione di una nuova istanza di Punto.")
        self.x = x
        self.y = y

    def __repr__(self) -> str:
        return f"{type(self).__name__}(x={self.x}, y={self.y})"
```

Questo codice:

* alla riga 3, definisce la classe Punto usando la parola chiave `class` seguita dal nome della classe.
* alla riga 4, definisce il metodo __new__(), che prende la classe come primo argomento. Notiamo che il primo argomento è `cls`. Il metodo prende inoltre `*args` e `**kwargs`, che permettono di passare un numero indefinito di argomenti di inizializzazione all'istanza sottostante.
* alla riga 5, scriviamo un messaggio quando __new__() esegue lo step di creazione
* alla rgia 6, creiamo una nuova istanza di Punto chiamando il metodo __new__() della classe padre con cls come argomento. In questo esempio, la class padre è `object`, e la chiamata a super() vi dà accesso. Quindi, l'istanza viene restituita. Questa istanza sarà il primo argometno ad __init__.
* alla riga 8 definisce __init__(), che si occupa dello step di inizializzazione. Questo metodo prende un primo argomento (self), che ha un riferimento all'instanza atutale. Il metodo prende anche due ulteriori argomenti, x ed y. QUesti argomenti hanno i valori iniziali per gli attributi dell'istanza x ed y. Dobbiamo passare dei valori adatti per questi argomenti nella chiamata a Punto(), come vedremo a breve.
* la riga 9 scrive un messaggio quando __init__() esegue lo step di inizializzazione dell'oggetto
* le righe 10 ed 11 inizializzano x ed y, rispettivamente. Per farlo, usano gli argomenti di input forniti (x ed y)
* le righe 13 e 14 implementano il metodo speciale __repr__, che fornisce una rappresentazione aduegata sotto forma di stringa degli oggetti di classe Point.

Possiamo adesso scoprire come funziona il processo di istanziamento nella pratica. Salviamo il nostro codice in un file chiamato putno.py e lanciamo il nostro itnerprete Python in una finestra a riga di comando. Quindi eseguiamo il seguente codice:

```py
from point import Point

point = Point(21, 42)

1. Create a new instance of Point.
2. Initialize the new instance of Point.
```

Chiamare il costruttore di classe Point() crea, inizializza e restituisce una nuova istanza della classe. Questa istanza è quindi assegnata alla variabile point.

In questo esempio, la chiamata al costruttore ci permette anche di conoscere gli step che Python esegue internamente per costruire l'istanza. In primis, Python chiama `__new__()`, e quindi `__init__()`, il che risulta in una nuova e completamente inizializzata istanza di `Punto`, come possiamo vedere al termine dell'esempio.

Possiamo anche provare ad eseguire entrambi gli step manualmente:


```py
from point import Point

point = Point.__new__(Point)
1. Create a new instance of Point.

>>> # The point object is not initialized
>>> point.x
Traceback (most recent call last):
    ...
AttributeError: 'Point' object has no attribute 'x'
>>> point.y
Traceback (most recent call last):
    ...
AttributeError: 'Point' object has no attribute 'y'

>>> point.__init__(21, 42)
2. Initialize the new instance of Point.

>>> # Now point is properly initialized
>>> point
Point(x=21, y=42)
```

In questo esempio, per prima cosa chiamiamo `__new__()` sulla classe Punto, passando la classe stessa come primoa rgomento al meotod. Questa chiamata viene solo eseguita come primo step del processo di istanziamento, creando un nuovo oggetto vuoto. Notiamo che creare un'istanza in questo modo bypassa la chiamata ad `__init__()`.

!!!note "Nota"
    L'esempio precedente deve essere inteso come un esempio dimostrativo di come funziona il processo di istanziamento itnernamente. Non è un qualcosa che vogliamo tipicamente fare nel codice reale.

Una volta che abbiamo il nuovo oggetto, possiamo inizializzarlo chiamando `__init__()` con un insieme appropriato di argomenti. Dopo questa chiamata, il nostro oggetto Punto è inizializzato, con tutti i suoi attributi impostati.

Un sottile, ma importante, dettaglio da notare su `__new__()` è che può anche restituire un'istanza di una classe differente dalla classe che implementa il metodo stesso. Quando questo accade, Python non chiama `__init__()` nella classe attuale, perché non c'è modo di sapere in maniera non ambigua come inizializzare un oggetto di una classe differente.

Consideriamo il seguente esempio, nel quale il metodo __new__() della classe B restituisce un'istanza della classe A:

```py
# ab_classes.py

class A:
    def __init__(self, a_value):
        print("Initialize the new instance of A.")
        self.a_value = a_value

class B:
    def __new__(cls, *args, **kwargs):
        return A(42)

    def __init__(self, b_value):
        print("Initialize the new instance of B.")
        self.b_value = b_value
```

Siccome `B.__new__()` restituisce un'istanza di una clase differente, Python non esegue B.__init__(). Per confermare questo comportamento, salviamo il codice in un file chiamato classi_ab.py e quindi eseguiamo il codice seguente in una sessione Python interattiva.

```python
>>> from ab_classes import B

>>> b = B(21)
Initialize the new instance of A.

>>> b.b_value
Traceback (most recent call last):
    ...
AttributeError: 'A' object has no attribute 'b_value'

>>> isinstance(b, B)
False
>>> isinstance(b, A)
True

>>> b.a_value
42
```

La chiamata al costruttore della classe `B()` esegue `B.__new__()`, che restituisce un'istanza di A invece di B. Per questo motivo, `B.__ini__()` non viene mai eseguito. Notiamo che b non ha un attributo b_value. In contrasto, b ha un attributo a_value, con valore 42.

Ora che conosciamo gli step che Python percorre internamente per creare istanze di una data classe, possiamo scendere più nel dettaglio nelle altre caratteristiche di __init__(), __new__() e gli step che eseguono.

### INizializazzione degli oggetti con __init__()

In Python, il metodo __init__() è probabilmente il metodo speciale più comemente sovrascritto nelle nostre classi custom. Più o meno tutte le nostre classi avranno bisogno di un'implementazione custom di __init__(). Sovrascrivere questo metodo ci permette di inizializzare propriamente i nostri oggetti.

LO scopo di questo step di inizializzazione è lasciare i nostri nuovi oggetti in uno stato valido, in modo che li si possa iniziare ad usare immediatamente nel nostro codice. In questa sezione, vedremo le basi di scrivere i nostri metodi __init__(), e come ci possono aiutare a customizzare le nostre classi.

### Fornire degli inizializzatori custom degli oggetti

L'implementazione più basilare di __init__() che possiamo scrivere si occuperà soltanto di assegnare gli argomenti in input ai corrispondenti attributi dell'istanza. Ad esempio, diciamo che stiamo scrivendo una classe Rettangolo che richiede gli attributi width ed height. In questo caso, possiamo fare qualcosa come questa:

```py
>>> class Rectangle:
...     def __init__(self, width, height):
...         self.width = width
...         self.height = height
...

>>> rectangle = Rectangle(21, 42)
>>> rectangle.width
21
>>> rectangle.height
42
```

Come abbiamo visto prima, __init__() esegue il secondo step dell'istanziamento dell'oggetto in Python. Il suo primo argomento, `self`, contiene la nuova istanza che risulta dalla chiamata a `__new__()`. Il resto degli argomenti ad `__init__()` sono normalmente usati per inizializzare gli attributi dell'istanza. Nell'esempio precedente, abbiamo inizializzato le proprietà width ed height del rettangolo usando gli argomenti width ed height passati ad __inti__().

E' importante notare che, senza contare il self, gli argomenti all'__init__() sono gli stessi che passiamo nella chiamata al costruttore di classe. Di conseguenza, possiamo dire che la firma __init__() definisce la firma del costruttore di classe.

Inoltre, teniamo a mente che __inti__() non deve esplciritamente restituire un qualcosa di diverso da None, o otterremo un'eccezione di tipo TypeError.

```py
>>> class Rectangle:
...     def __init__(self, width, height):
...         self.width = width
...         self.height = height
...         return 42
...

>>> rectangle = Rectangle(21, 42)
Traceback (most recent call last):
    ...
TypeError: __init__() should return None, not 'int'
```

In questo esempio, il metodo __init__() prova a restituire un numero intero, che finisce per lanciare un'eccezione `TypeError` a runtime.

Il messaggio di errore nell'esempio precedente ci dice che il metodo __init__() deve restituire None. Ad ogni modo, non dobbiamo aggiungere un return None esplciitamente, perché i metodi e le funzioni senza un'istruzione return esplicita semplicemente restituiscono None, in Python.

Con l'implementazione precedente di __init__(), ci assicuriamo che width ed height vengano inizializzati ad uno stato valido quando chiamiamo il Costruttore di lcasse con argomenti adeguati. In questo modo, i nostri rettangoli saranno pronti all'uso dopo che finisce il processo di costruzione.

In __init__(), possiamo eseguire una qualsiasi trasformazione degli argomenti di input per inizializzare propriamente gli attributi dell'istanza. Ad esempio, se i nostri utenti useranno direttamente un rettangolo, allora potremmo voler validare i valori forniti di width ed height ed assicurarci che siano corretti prima di inizializzare gli attributi corrispondenti:

```py
>>> class Rectangle:
...     def __init__(self, width, height):
...         if not (isinstance(width, (int, float)) and width > 0):
...             raise ValueError(f"positive width expected, got {width}")
...         self.width = width
...         if not (isinstance(height, (int, float)) and height > 0):
...             raise ValueError(f"positive height expected, got {height}")
...         self.height = height
...

>>> rectangle = Rectangle(-21, 42)
Traceback (most recent call last):
    ...
ValueError: positive width expected, got -21
```

In questa implementazione aggiornata di __init__(), ci assicuriamo che gli argomenti di input width ed height siano numeri positivi prima di inizializzare gli attributi width ed height corrispondenti. Se una validazione tra le due fallisce, abbiamo un ValueError.

!!!note "Nota"
    Una tecnica maggiormente Pythonica prevede dii gestire la validazione degli attributi mediante delle property.

Ora diciamo ches tiamo usando l'ereditarietà per fcreare una gerarchia di classi custom e riutilizzare delle funzionalità nel nostro codice. Se la nostra sottoclasse fornisce un metodo __init__(), allora questo metodo deve esplicitamente chiamare l'__init__() della classe base con argomenti appropriati per assicurare la corretta inizializzazione delle istanze. Per farlo, dobbiamo suare la funzione built-in super() come nel seguente esempio.

```py
>>> class Person:
...     def __init__(self, name, birth_date):
...         self.name = name
...         self.birth_date = birth_date
...

>>> class Employee(Person):
...     def __init__(self, name, birth_date, position):
...         super().__init__(name, birth_date)
...         self.position = position
...

>>> john = Employee("John Doe", "2001-02-07", "Python Developer")

>>> john.name
'John Doe'
>>> john.birth_date
'2001-02-07'
>>> john.position
'Python Developer'
```

La prima riga nel metodo __init__() di Impiegato chiama super().__init__() con argomenti nome e data di compleanno. Questa chiamata assicura l'inizializzazione degli attributi name e birth_date nella classe madre, Persona. Questa tecnica ci permette di estendere la classe base con nuovi attributi e funzioanlità.

PEr terminare questa sezione, dovremo sapere che l'implementazione base di __init__() viene dalla classe object. Questa implementazione viene chiamata in automatico quando non forniamo un metodo __init__() esplicito nelle nostre classi.

### Costruire degli inizializzatori flessibili

Possiamo rendere gli step di inizializzazione dei nostri oggetti flessibili e versatili modificando il metodo __init__(). A tal scopo, una delle tecniche più popolari è quella di usare degli argomenti opzionali. Questa tecnica ci permette di scrivere delle classi nelle quali il costruttore accetta diversi insiemi di argomenti di input al momento dell'istanziamento. Quali arogmenti utilizzare ad un dato istante di tempo dipende dai nostri specifici obiettivi e contesto.

Come rapido esempio, vediamo la seguente classe Greeter:

```py
# greet.py

class Greeter:
    def __init__(self, name, formal=False):
        self.name = name
        self.formal = formal

    def greet(self):
        if self.formal:
            print(f"Good morning, {self.name}!")
        else:
            print(f"Hello, {self.name}!")
```

IN questo esempio, __init__() prende un argomento regolare chiamato `name`. Accetta anche un argomento opzionale chiamato `formal`, che di default assume il valore `False`. Dato che `formal` ha un valore di default, possiamo costruire degli oggetti affidandoci a questo valore o fornirne uno noi.

Il comportamento finale della classe dipenderà dal valore di formal. Se questo argomento è False, allora avremo un greeting informale qunado chiameremo il metodo greet(). Altrimenti, avremo un benvenuto più formale.

Per provare Greeter, salviamo il codice in un file greet.py. Quindi, apriamo una sessione interattiva nella nostra cartella di lavoro, eseguendo questo codice:

```py
>>> from greet import Greeter

>>> informal_greeter = Greeter("Pythonista")
>>> informal_greeter.greet()
Hello, Pythonista!

>>> formal_greeter = Greeter("Pythonista", formal=True)
>>> formal_greeter.greet()
Good morning, Pythonista!
```

Nel primo esempio, creiamo un oggetto chiamato informal_greeter passando un valore all'argomento name ed affidandoci al valore di default di formal. Otteniamo un messaggio di benvenuto informale sul nostro schermo quando chiamiamo greet() su questo oggetto.

Nel secondo esempio, usiamo un nome ed un argomento formale per istanziare Greeter. Siccome formal è True, il risultato di chiamare greet() è un messaggio di benvenuto formale.

Anche se questo è un esempio "toy", mostra come i valori degli argomenti di default sono una feature potente in Python che possiamo usare per scrivere degli inizializzatori flessibili per le nostre classi. Questi inizializzatori ci permettono di istanziare le nostre classi usando diversi insiemi di argomenti a seconda delle nostre necessità.

Adesso che conosciamo le basi di __init__() e dello step di inizializzazione dell'oggetto, è il momento di cambiare marcia ed iniziare a vedere __new__() e lo step di creazione dell'oggetto.

### Creazione dell'oggetto con __new__()

Quando scriviamo delle classi Python, tipicamente non dobbiamo fornire la nostra implementazione del metodo speciale __new__(). La maggior parte delle volte, l'implementazione base dalla classe built-in object è sufficiente a creare un oggetto vuoto per la nostra classe attuale.

Tuttavia, ci sono alcuni casi d'uso interessanti per questo metodo. Ad esempio, possiamo usare __new__() per creare delle sottoclassi di tipi immutabili, come int, float, tuple e str. Nella seguente sezioni, vedremo come scrivere implementazioni custom di __new__() nelle nostre classi. Per farlo, codificheremo alcuni campioni che ci daranno un'idea di quando potremmo dover sovrascrivere questo metodo.

### Fornire dei creatori di oggetti custom

Tipicamente, scriveremo un'implementazione personalizzata di __new__() soltanto qunado dobbiamo controllare la crezione di una nuova istanza a basso livello. Adesso, se abbiamo bisogno di un'implementazione personalizzata di questo metodo, dobbiamo seguire alcuni step:

* creazione di una nuova istanza chiamando `super().__new__()` con gli argomenti adeguati
* personalizzazione della nuova istanza in accordo ai nostri obiettivi specifici
* restituzione della nuova istanza per continuare il processo di istanziamento

Con questi tre step circoncisi, siamo in grado di personalizzare lo step di creazione dell'istanza nel processo di istanziamento Python. Ecco un esempio di come possiamo tradurre questi step in codice Python.

```py
class SomeClass:
    def __new__(cls, *args, **kwargs):
        instance = super().__new__(cls)
        # Customize your instance here...
        return instance
```

Questo esempio fornisce una specie di implementazione template di __new__(). Come sempre, __new__() prende la classe attuale come argomento tipicamente indicato come `cls`. Notiamo che stiamo usando *args e **kwargs per rendere il metodo più flessibile e manutenibile accettando un numero qualisasi di argomenti.

Notiamo che stiamo usando *args e **kwargs per rendere il metodo più flessibile e manutenibile accettando un numero arbitrario di argomenti. Dovremmo sempre definire __new__() con *args e **kwargs, a meno che non si abbiano buone ragioni per seguire un pattern differente.

Alla prima riga di __new__(), chiamiamo il metodo __new__() della classe padre per creare una nuova istanza ed allocarvi memoria. Per accedere al metodo __new__() della classe padre, usiamo la funzione super(). Questa catena di chiamate va fino al metodo __new__() di object, che è l'implementazione base di __new__() per tutte le classi Python.

!!!note "Nota"
    La classe object integrata è la classe base di default per tutte le classi Python.

Il passo successivo è personalizzare l'istanza appena creata. Possiamo fare tutto quello di cui abbiamo bisogno per personalizzare l'istanza. Infine, nel terzo step, dobbiamo restituire la nuova istanza per continuare il processo di istanziamento con lo step di inizializzazione.

E' importante notare che il metodo __new__() da solo accetta soltanto un arogmento singolo, ovvero la classe da istanziare. SE chiamiamo il metodo __new__() con più argomenti, avremo un TypeError:

```py
>>> class SomeClass:
...     def __new__(cls, *args, **kwargs):
...         return super().__new__(cls, *args, **kwargs)
...     def __init__(self, value):
...         self.value = value
...

>>> SomeClass(42)
Traceback (most recent call last):
    ...
TypeError: object.__new__() takes exactly one argument (the type to instantiate)
```

In questo esempio, abbiamo mandato *args e **kwargs come argomenti aggiuntivi nella chiamata a super().__new__(). Il sottostante metodo object.__new__() accetta soltanto la classe come argomento, per cui abbiamo un TypeError quando istanziamo la classe.

Ad ogni modo, __new__() accetta e passa argomenti extra ad __init__() se la nostra classe non sovrasrive __new__(), come nella seguente variazione di SomeClass:


```py
>>> class SomeClass:
...     def __init__(self, value):
...         self.value = value
...

>>> some_obj = SomeClass(42)
>>> some_obj
<__main__.SomeClass object at 0x7f67db8d0ac0>
>>> some_obj.value
42
```

In questa implementazione di SomeClass, non sovrascriviamo __new__(). La creazione dell'oggetto è quindi delegata ad object.__new__(), che adessoa ccetta dei valori e li pasa a SomeClass.__init__() per finalizzare l'istanziamento. Adesso creiamo delle nuove, e completamente inizializzate, istanze di SomeClass, proprio come some_obj nell'esempio.

Adesso che sappiamo come scrivere la nostra implementazione di __new__(), siamo in grado di valutare alcuni esempi pratici che mostrano alcuni dei casi d'uso più comuni di questo metodo nella programmazione Python.

### SUbclassing dei tipi built-in immutabili

Per iniziare, vedriamo un caso d'uso di __new__() che consiste nel creare una sottoclasse di un tipo immutabile built-in. Ad esempio, diciamo di dover scrivere una classe Distanza come sottoclasse del tipo float di Python. La nostra classe avrà un ulteriore attributo per memorizzare l'unità usata per misurare la distanza.

Ecco un primo approccio a questo problema usando il metodo __init__():

```py
>>> class Distance(float):
...     def __init__(self, value, unit):
...         super().__init__(value)
...         self.unit = unit
...

>>> in_miles = Distance(42.0, "Miles")
Traceback (most recent call last):
    ...
TypeError: float expected at most 1 argument, got 2
```

Quando si fa una sottoclasse di un tipo immutabile built-in, abbiamo un errore. Parte del problema è che il valore è impostato durante la creazione, ed è troppo tardi per cambiarlo durante l'inizializzazione. Inoltre, float.__new__() viene chiamato "sotto al cofano", e non si occupa di argomenti extra allo stesso modo di object.__new__(). Questo è ciò che lancia l'errore nel nostro esempio precedente.

Per evitare questo problema, possiamo inizializzare l'oggetto al momento della creazione con __new__() invece di sovrascrivere __init__(). Ecco come possiamo farlo in pratica:

```py
>>> class Distance(float):
...     def __new__(cls, value, unit):
...         instance = super().__new__(cls, value)
...         instance.unit = unit
...         return instance
...

>>> in_miles = Distance(42.0, "Miles")
>>> in_miles
42.0
>>> in_miles.unit
'Miles'
>>> in_miles + 42.0
84.0

>>> dir(in_miles)
['__abs__', '__add__', ..., 'real', 'unit']
```

In questo esempio, __new__() esegue i tre step che abbiamo visto nella sezione precedente. Per priam cosa, il metodo crea una nuova istanza della classe attuale, cls, chiamando super().__new__(). Questa volta, la chiamata va indietro a float.__new__(), che cera una nuova istanza inizializzando il suo valore come argomento. QUindi, il metodo customizza la nuova istanza aggiungendovi un attributo .unit. Infine, la nuova istanza viene restituita.

!!!note "Nota"
    La classe `Distance` nell'esempio precedente non fornisce un meccanismo di conversione di unità appropriato. Questo significa che qualcosa come `Distance(10, "km") + Distance(20, "miles")` non proverà a convertire le unità prima di aggiungere i valori.

Ecco fatto! Ora la classe Distance funziona come atteso, permettendoci di usare un attributo dell'istanza per memorizzare l'unità nella quale stiamo misurando la distanza. A differenza dei valori a virgola mobile memorizzati in una data istanza di `Distance`, l'attributo `.unit` è mutabile, per cui possiamo cambiare il suo valore qunado vogliamo. Infine, notiamo come una chiamata alla funzione `dir()` riveli che la nostra classe eredita feature e metodi da `float`.

## Restituire istanze di una classe differente

Restituire un oggetto di una classe differente è un requisito che può richiedere un'implementazione custom di __new__(). Tuttavia, dovremmo porre attenzione perché in questo caso Python salta interamente lo step di inizializzazione. Avremo quindi la responsabilità di prendere l'oggetto appena creto in uno stato valido prima di usarlo nel nostro codice.

Vediamo il seguente esempio, nel quale la classe Pet usa __new__() per restituire istanze di classe scelte casualmente.

```py
# pets.py

from random import choice

class Pet:
    def __new__(cls):
        other = choice([Dog, Cat, Python])
        instance = super().__new__(other)
        print(f"I'm a {type(instance).__name__}!")
        return instance

    def __init__(self):
        print("Never runs!")

class Dog:
    def communicate(self):
        print("woof! woof!")

class Cat:
    def communicate(self):
        print("meow! meow!")

class Python:
    def communicate(self):
        print("hiss! hiss!")
```

In questo esempio, `Pet` fornisce un metodo `__new__()` che crea una nuova istanza selezionando casualmente una classe da una lista di classi esistenti.

Ecco come possiamo usare questa clase Pet come una factory di oggetti pet:

```py
>>> from pets import Pet

>>> pet = Pet()
I'm a Dog!
>>> pet.communicate()
woof! woof!
>>> isinstance(pet, Pet)
False
>>> isinstance(pet, Dog)
True

>>> another_pet = Pet()
I'm a Python!
>>> another_pet.communicate()
hiss! hiss!
```

Ogni volta che istanziamo Pet, otteniamo u oggetto casuale da una diversa classe. Questo risultato è possibile perché non vi sono restrizioni sull'oggetto che `__new__()` può restituire. Usare `__new__()` in questo modo trasforma una classe in una factory flessibile e potente di oggetti, non limitate alle istanze di sé stessa.

Infine, notiamo come il metodo `__init__()` di Pet non viene mai eseguito. Questo è legato al fatto che `Pet.__new__()` restituisce sempre oggetti di una classe diversa da Pet stesso.

## PErmettere solo una singola istanza nelle nostre classi

Alle volte dobbiamo implementare una classe che ci permette la creazione di una singola istanza. QUesto tipo di classe è comunemente conosciuto come *singleton*. In questa situazione, il metodo `__new__()` ci viene in aiuto perché ci aiuta a restringere il numero di istanze che una data classe può avere.

!!!note "Nota"
    La maggior parte degli sviluppatori Python noterà che non dobbiamo implementare il design pattern singleton in Python a meno che non abbiamo già una classe funzionante a cui dobbiamo aggiungere le funzionalità del pattern. Il resto delle volte, possiamo usare una costante a livello di modulo per ottenre le stesse funzionalità singleton senza dover scrivere una classe relativamente complessa.

Ecco un esempio di come codificare una classe Singleton con un metodo __new__() che pemrmette la creazione di un'unica istanza alla volta. Per farlo, `__new__()` controlla l'esistenza di un'istanza precedentemente messa in cache di un attributo di classe:

```py
>>> class Singleton(object):
...     _instance = None
...     def __new__(cls, *args, **kwargs):
...         if cls._instance is None:
...             cls._instance = super().__new__(cls)
...         return cls._instance
...

>>> first = Singleton()
>>> second = Singleton()
>>> first is second
True
```

La classe Singleton in questo esempio ha un attributo di classe chiamato `_instance` di valore di default None che funziona come cache. Il metodo `__new__()` controlla che non esistano istanze precedenti testando il fatto che `cls._instance` sia None.

!!!note "Nota"
    Nell'esempio precedente, la classe `Singleton` non fornisce un'implementazione di `__init__()`. Se dovessimo aver bisogno di una classe con un metodo `__init__()`, teniamo a mente che questo metodo sarà eseguito ogni volta che chiamiamo il costruttore `Singleton()`. Questo comportamento può causare degli strani effetti di inizializzazione e bug.

Se questa condizione è vera, allora il blocco di codice if crea una nuova istanza di Singleton e la memorizza in `cls._instance`. Infine, il metodo restituisce la nuova o esistente istanza al chiamante.

Quindi istanziamo Singleton due volte per provare a copstruire due diversi gogetti, `first` e `second`. Se compariamo l'identità di questi oggetti con l'operatore `is`, allora noteremo che entrambi gli oggetti sono in realtà lo stesso. I nomi `first` e `second` sono solo due reference allo stesso oggetto `Singleton`.

## Emulazione parziale di collections.namedtuple

Come esempio finale di come sfruttare `__new__()` nel nostro codice, possiamo spingere le nostre abilità Python e scrivere una funzione factory che emula parzialmente `collections.namedtuple()`. La funzione `namedtuple()` ci permette di creare delle sottoclassi di tuple con la feature aggiuntiva di avere campi nominali per accedere agli oggetti nella tupla.

Il codice sottostante implementa una funzione `named_tuple_factory()` che emula parzialmente questa funzionalità sovrascrivendo il metodo `__new__()` di una classe annidata chiamata `NamedTuple`:

```py
# named_tuple.py

from operator import itemgetter

def named_tuple_factory(type_name, *fields):
    num_fields = len(fields)

    class NamedTuple(tuple):
        __slots__ = ()

        def __new__(cls, *args):
            if len(args) != num_fields:
                raise TypeError(
                    f"{type_name} expected exactly {num_fields} arguments,"
                    f" got {len(args)}"
                )
            cls.__name__ = type_name
            for index, field in enumerate(fields):
                setattr(cls, field, property(itemgetter(index)))
            return super().__new__(cls, args)

        def __repr__(self):
            return f"""{type_name}({", ".join(repr(arg) for arg in self)})"""

    return NamedTuple
```

Ecco come funziona questa factory riga per riga:

* alla riga 3 importiamo `itemgetter()` dal modulo `operator`. Questa funzione ci permette di restituire gli ingressi usando il loro indice nella sequenza che li contiene.
* alla riga 5 definiamo `named_tuple_factory()`. Questa funzione prende un primo argomento chiamato `type_name`, che conterrà il nome della sottoclasse delle tuplce che vogliamo creare. L'argomento *fileds ci permette di parssare un numero indefinito di nomi di campi come stringhe.
* la riga 6 definisce una variabile locale per contenere il numero di named fields forniti dall'utente.
* la riga 8 definisce una classe annidata chiamata `NamedTuple`, che discende dalla classe integrata `tuple`.
* la riga 9 fornisce un attributo di classe `__slots__`. Questo attributo definisce una tupla per contenere gli attributi dell'istanza. Questa tupla risparmia memoria agendo come una sostituta per il dizionario dell'istanza, `__dict__`, che altrimenti giocherebbe un ruolo simile.
* la riga 11 implementa `__new__()` con `cls` come primo argomento. Questa implementazione prende anche l'argomento `*args` per accettare un numero indefinito di valori per il campo.
* le righe dalla 12 alla 16 definiscono un'istruzione condizionale che controlla se il numero di oggetti da memorizzare nella tupla finale differisce dal numero di campi con un nome. Se questo è il caso, allora la condizione lancia un `TypeError` con un messaggio di errore.
* la riga 17 imposta l'attributo `__name__` della classe attuale al valore fornito da `type_name`.
* le righe 18 e 19 definsicon un ciclo for che cambia tutti i campi con un nome in una property che usa itemgetter() per restituire l'oggetto al dato indice. Il ciclo usa la funzione itnegrata `setattr()` per effettuare questa azione. Notiamo che la funzione integrata `enumerate()` fornisce il valore appropriato dell'indice.
* la riga 20 restituisce una nuova istanza della classe attuale chiamando `super().__new__()`.
* le righe 22 e 23 definiscono un metodo `__repr__()` per la nostra classe.
* la riga 25 restituisce la nuova classe `NamedTuple`.

Per provare la classe `named_tuple_factory()`, lanciamo una sessione interattiva nella cartella conenente il file named_tuple.py ed eseguiamo il seguente codice:

```sh
>>> from named_tuple import named_tuple_factory

>>> Point = named_tuple_factory("Point", "x", "y")

>>> point = Point(21, 42)
>>> point
Point(21, 42)
>>> point.x
21
>>> point.y
42
>>> point[0]
21
>>> point[1]
42

>>> point.x = 84
Traceback (most recent call last):
    ...
AttributeError: can't set attribute

>>> dir(point)
['__add__', '__class__', ..., 'count', 'index', 'x', 'y']
```

In questo snippet, abbiamo creato una nuova classe Point chiamando named_tuple_factory(). Il primo argomento in questa chiamata rappresenta il nome che l'oggetto della classe risultatne userà. Il secondo e terzo argomento sono i campi cn nome disponibili nella classe risultante.

Quindi creiamo un oggetto Point chiamando il costruttore di classe con valori appropriati epr i campi x ed y. Per accedere ai valori di ongi campo con nome, usiamo la dot notation. Possiamo anche usare gli indici per recuperare i valori dato che la nostra classe è una sottoclasse di tuple.

Dato che le tuple sono dei tipi di dati immutaibili, non possiamo assegnare nuovi valori alle coordinate del punto: se proviamo a farlo, avremo un AttributeError.

Infine, la chiamata a dir() con l'istanza del nostro punto come argomento rivela che l'oggetto eredtia tutti gli attributi e metodi che le tuple normali hanno in Python.

## conclusioni

Ora sappiamo come i costruttori di classe Python ci permettono di istanziare delle classi, per cui possiamo creare degli oggetti concreti e riutilizzabili nel nostro codice. In Python, i costruttori di classe lanciano internamente i processi di costruione, che prevedono la creazione ed inizializzazione dell'istanza. Questi passi sono condotti dai metodi __new__() ed __init__().
