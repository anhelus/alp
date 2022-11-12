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




TODO DA QUI


However, object.__new__() still accepts and passes over extra arguments to .__init__() if your class doesn’t override .__new__(), as in the following variation of SomeClass:

>>> class SomeClass:
...     def __init__(self, value):
...         self.value = value
...

>>> some_obj = SomeClass(42)
>>> some_obj
<__main__.SomeClass object at 0x7f67db8d0ac0>
>>> some_obj.value
42
In this implementation of SomeClass, you don’t override .__new__(). The object creation is then delegated to object.__new__(), which now accepts value and passes it over to SomeClass.__init__() to finalize the instantiation. Now you can create new and fully initialized instances of SomeClass, just like some_obj in the example.

Cool! Now that you know the basics of writing your own implementations of .__new__(), you’re ready to dive into a few practical examples that feature some of the most common use cases of this method in Python programming.


Remove ads
Subclassing Immutable Built-in Types
To kick things off, you’ll start with a use case of .__new__() that consists of subclassing an immutable built-in type. As an example, say you need to write a Distance class as a subclass of Python’s float type. Your class will have an additional attribute to store the unit that’s used to measure the distance.

Here’s a first approach to this problem, using the .__init__() method:

>>> class Distance(float):
...     def __init__(self, value, unit):
...         super().__init__(value)
...         self.unit = unit
...

>>> in_miles = Distance(42.0, "Miles")
Traceback (most recent call last):
    ...
TypeError: float expected at most 1 argument, got 2
When you subclass an immutable built-in data type, you get an error. Part of the problem is that the value is set during creation, and it’s too late to change it during initialization. Additionally, float.__new__() is called under the hood, and it doesn’t deal with extra arguments in the same way as object.__new__(). This is what raises the error in your example.

To work around this issue, you can initialize the object at creation time with .__new__() instead of overriding .__init__(). Here’s how you can do this in practice:

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
In this example, .__new__() runs the three steps that you learned in the previous section. First, the method creates a new instance of the current class, cls, by calling super().__new__(). This time, the call rolls back to float.__new__(), which creates a new instance and initializes it using value as an argument. Then the method customizes the new instance by adding a .unit attribute to it. Finally, the new instance gets returned.

Note: The Distance class in the example above doesn’t provide a proper unit conversion mechanism. This means that something like Distance(10, "km") + Distance(20, "miles") won’t attempt at converting units before adding the values. If you’re interested in converting units, then check out the Pint project on PyPI.

That’s it! Now your Distance class works as expected, allowing you to use an instance attribute for storing the unit in which you’re measuring the distance. Unlike the floating-point value stored in a given instance of Distance, the .unit attribute is mutable, so you can change its value any time you like. Finally, note how a call to the dir() function reveals that your class inherits features and methods from float.

Returning Instances of a Different Class
Returning an object of a different class is a requirement that can raise the need for a custom implementation of .__new__(). However, you should be careful because in this case, Python skips the initialization step entirely. So, you’ll have the responsibility of taking the newly created object into a valid state before using it in your code.

Check out the following example, in which the Pet class uses .__new__() to return instances of randomly selected classes:

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
In this example, Pet provides a .__new__() method that creates a new instance by randomly selecting a class from a list of existing classes.

Here’s how you can use this Pet class as a factory of pet objects:

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
Every time you instantiate Pet, you get a random object from a different class. This result is possible because there’s no restriction on the object that .__new__() can return. Using .__new__() in such a way transforms a class into a flexible and powerful factory of objects, not limited to instances of itself.

Finally, note how the .__init__() method of Pet never runs. That’s because Pet.__new__() always returns objects of a different class rather than of Pet itself.

Allowing Only a Single Instance in Your Classes
Sometimes you need to implement a class that allows the creation of a single instance only. This type of class is commonly known as a singleton class. In this situation, the .__new__() method comes in handy because it can help you restrict the number of instances that a given class can have.

Note: Most experienced Python developers would argue that you don’t need to implement the singleton design pattern in Python unless you already have a working class and need to add the pattern’s functionality on top of it.

The rest of the time, you can use a module-level constant to get the same singleton functionality without having to write a relatively complex class.

Here’s an example of coding a Singleton class with a .__new__() method that allows the creation of only one instance at a time. To do this, .__new__() checks the existence of previous instances cached on a class attribute:

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
The Singleton class in this example has a class attribute called ._instance that defaults to None and works as a cache. The .__new__() method checks if no previous instance exists by testing the condition cls._instance is None.

Note: In the example above, Singleton doesn’t provide an implementation of .__init__(). If you ever need a class like this with a .__init__() method, then keep in mind that this method will run every time you call the Singleton() constructor. This behavior can cause weird initialization effects and bugs.

If this condition is true, then the if code block creates a new instance of Singleton and stores it to cls._instance. Finally, the method returns the new or the existing instance to the caller.

Then you instantiate Singleton twice to try to construct two different objects, first and second. If you compare the identity of these objects with the is operator, then you’ll note that both objects are the same object. The names first and second just hold references to the same Singleton object.


Remove ads
Partially Emulating collections.namedtuple
As a final example of how to take advantage of .__new__() in your code, you can push your Python skills and write a factory function that partially emulates collections.namedtuple(). The namedtuple() function allows you to create subclasses of tuple with the additional feature of having named fields for accessing the items in the tuple.

The code below implements a named_tuple_factory() function that partially emulates this functionality by overriding the .__new__() method of a nested class called NamedTuple:

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
Here’s how this factory function works line by line:

Line 3 imports itemgetter() from the operators module. This function allows you to retrieve items using their index in the containing sequence.

Line 5 defines named_tuple_factory(). This function takes a first argument called type_name, which will hold the name of the tuple subclass that you want to create. The *fields argument allows you to pass an undefined number of field names as strings.

Line 6 defines a local variable to hold the number of named fields provided by the user.

Line 8 defines a nested class called NamedTuple, which inherits from the built-in tuple class.

Line 9 provides a .__slots__ class attribute. This attribute defines a tuple for holding instance attributes. This tuple saves memory by acting as a substitute for the instance’s dictionary, .__dict__, which would otherwise play a similar role.

Line 11 implements .__new__() with cls as its first argument. This implementation also takes the *args argument to accept an undefined number of field values.

Lines 12 to 16 define a conditional statement that checks if the number of items to store in the final tuple differs from the number of named fields. If that’s the case, then the conditional raises a TypeError with an error message.

Line 17 sets the .__name__ attribute of the current class to the value provided by type_name.

Lines 18 and 19 define a for loop that turns every named field into a property that uses itemgetter() to return the item at the target index. The loop uses the built-in setattr() function to perform this action. Note that the built-in enumerate() function provides the appropriate index value.

Line 20 returns a new instance of the current class by calling super().__new__() as usual.

Lines 22 and 23 define a .__repr__() method for your tuple subclass.

Line 25 returns the newly created NamedTuple class.

To try your named_tuple_factory() out, fire up an interactive session in the directory containing the named_tuple.py file and run the following code:

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
In this code snippet, you create a new Point class by calling named_tuple_factory(). The first argument in this call represents the name that the resulting class object will use. The second and third arguments are the named fields available in the resulting class.

Then you create a Point object by calling the class constructor with appropriate values for the .x and .y fields. To access the value of each named field, you can use the dot notation. You can also use indices to retrieve the values because your class is a tuple subclass.

Because tuples are immutable data types in Python, you can’t assign new values to the point’s coordinates in place. If you try to do that, then you get an AttributeError.

Finally, calling dir() with your point instance as an argument reveals that your object inherits all the attributes and methods that regular tuples have in Python.

Conclusion
Now you know how Python class constructors allow you to instantiate classes, so you can create concrete and ready-to-use objects in your code. In Python, class constructors internally trigger the instantiation or construction process, which goes through instance creation and instance initialization. These steps are driven by the .__new__() and .__init__() special methods.

By learning about Python’s class constructors, the instantiation process, and the .__new__() and .__init__() methods, you can now manage how your custom classes construct new instances.

In this tutorial, you learned:

How Python’s instantiation process works internally
How your own .__init__() methods help you customize object initialization
How overriding the .__new__() method allows for custom object creation
Now you’re ready to take advantage of this knowledge to fine-tune your class constructors and take full control over instance creation and initialization in your object-oriented programming adventure with Python.
