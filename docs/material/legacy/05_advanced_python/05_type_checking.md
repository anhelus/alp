# Type checking

!!!note
    Cosa è il type checking? Perché ne abbiamo bisogno? Qual è la differentra tra type checking statico ed a runtime?

Python è un linguaggio *fortemente tipizzato* e che sfrutta la *programmazione dinamica*. In particolare, è *tipizzato in maniera dinamica*: in pratica, i tipi sono inferiti dinamicamente, per cui possiamo imostare i valori di una vairbabile direttamente senza definirne il tipo come nei linguaggi di programmazione tipizzati staticamente come Java.

What is type checking? Why do we need it? What's the difference between static and runtime type checking?

## Linguaggi di programmazione statici vs linguaggi di programmazione dinamici

I termini *forte* e *dinamico* indicano che i tipi sono inferiti a runtime, ma non possono essere tra loro mescolati. Ad esempio, `a = 1 + '0'` ci mostrerà un errore. D'altro canto, JavaScript è debolmente tipizzato e dinamico, per cui i tipi sono inferiti a runtime e pososno essere mescolati. Ad esempio, `a = 1 + '0'` ci darà 10 come risultato.

La tipizzazione dinamica ci porta una maggiore flessibilità, ma non è sempre desiderabile, per cui ci sono stati diversi sforzi per portare l'inferenza statica nei linguaggi dinamici.

In questo articolo vedremo a cosa sono i *type hints* e come possono aituarci. Vedremo anche come possiamo usare il sistema di tipizzazione di Python per il type checking statico con mypy e come effettuar eil type checking a runtime con pydantic, marshmallow e typeguard.

!!!note "Tool per il type checking"
    Esistono numerosi strumenti che usano i type hints per il type checking statico ed a runtime. Per una lista completa, consultiamo [Awesome Python Typing](https://github.com/typeddjango/awesome-python-typing).

## Type Hints

Il concetto di type hints è stato aggiungo a Python nella versione 3.5. Questi hanno permesso aglis viluppatori di annotare i tipi *attesi* per le variabili, i parametri di funzione, ed i valori restituiti da una funzione all'interno del codice Python. Questi tipi non vengono forzati dall'interprete Python; tuttavia, offrono un certo numero di benefici. Per prima cosa, con i type hints, possiamo esprimere al meglio l'intento di ciò che è nel nostro codice, e di come utilizzarlo. Una migliore comprensione comporta meno bug.

Ad esempio, diciamo di avere la seguente funzione epr calcolare la temperatura media in un giorno:

```py
def daily_average(temperatures):
    return sum(temperatures) / len(temperatures)
```

Finché forniamo una lista di temperature, la funzione lavora come previsto e restituisce il risultato atteso:

```py
average_temperature = daily_average([22.8, 19.6, 25.9])
print(average_temperature)  # => 22.76666666666667
```

Cosa accade se chiamiamo la funzione con un dizionario dove le chiavi sono i timestamp delle misure ed i valori sono le temperature?

```py
average_temperature = daily_average({1599125906: 22.8, 1599125706: 19.6, 1599126006: 25.9})
print(average_temperature)  # => 1599125872.6666667
```

In pratica, questa funzione restituisce la somma delle chiavi diviso il numero dichiavi, il che è chiaramente sbagliato. Dal momento che la chiamata a funzione non ha lanciato un errore, questo potrebbe non essere individuato, specialmente se l'utente finale fornisce le temperature.

Per evitare questa confusione, possiamo aggiungere i type hints marcando l'argomento ed il valore di ritorno:

```py
from typing import List


def daily_average(temperatures: List[float]) -> float:
    return sum(temperatures) / len(temperatures)
```

Adesso la definizione della funzione ci dice che:

* le temperature dovrebbero essere una lista di float: `temperatures: List[float]`
* la funzione dovrebbe restituire un float: `-> float`

Verifichiamolo:

```py
print(daily_average.__annotations__)
# {'temperatures': typing.List[float], 'return': <class 'float'>}
```

I type hints permettono di usare dei tool di type checking statico. Le IDE li usano, mettendo in guardia l'utente quando l'uso di una certa funzione o metdono non è quello atteso sulla base dei type hint e fornendo un'ottima funzione di autocompletamento.

Di conmseguenza, i type hint sono nei fatti soltanto dei *suggerimenti*. Non sono vincolanti come le definizioni di tipo nei linguaggi tipizzati staticamente, in altre parole. Detto questo, anche se sono abbastanza flessibili, ci aiutano a migliorare la qualità del codice esprimendo più chiaramente le nostre intenzioni. Oltre questo possiamo usare una serie di strumenti che ci aiutano a trarne beneficio.

## Type annotation vs type hints

Le type annotation sono soltanto una sintassi per annotare gli input, output e variabili di una funzione:

```py
def sum_xy(x: 'an integer', y: 'another integer') -> int:
    return x + y

print(sum_xy.__annotations__)
# {'x': 'an integer', 'y': 'another integer', 'return': <class 'int'}
```

I type hints sono costruiti "sopra" le annotation, per renderle più utili. Gli hint e le annotation sono spesso usati in maniera intercambiabile, ma in realtà sono differenti.

## Il modulo `typing`

Potremmo chiederci perché possiamo usare il float built-in per definire il tipo di ritorno di una funzione, ma la List invece viene importata direttamente dal modulo `typing`:

```py
from typing import List

def daily_average(temperatures: List[float]) -> float:
    return sum(temperatures) / len(temperatures)
```

Prima di Python 3.9, l'interprete Python non supportava l'uso di built-in come argomenti per il type hinting. Ad ese mpio, era possibile usare una list come type hint come segue:

```py
def daily_average(temperatures: list) -> float:
    return sum(temperatures) / len(temperatures)
```

Ma non era possibile definire il tipo atteso degli elementi di una lista (`List[float]`) senza il modulo `typing`. Lo stesso può essere detto per i dizionari e le altre sequenze e tipi complessi:

```py
from typing import Tuple, Dict

def generate_map(points: Tuple[float, float]) -> Dict[str, int]:
    return map(points)
```

Oltre questo, il modulo `typing` ci permette di defninire nuovi tipi, alias per tipi esistenti, usare il tipo `Any` e molte altre cose.

Ad esempio, potremmo voler permettere più tipi. In questo caso, possiamo suare una `Union`:

```py
from typing import Union

def sum_ab(a: Union[int, float], b: Union[int, float]) -> Union[int, float]:
    return a + b
```

A partire da Python 3.9, possiamo usare i built-ins come segue:

```py
def sort_names(names: list[str]) -> list[str]:
    return sorted(names)
```

## Static Type Checking con mypy

[mypy](#) è un tool per il type checking a compile time. Possiamo installarlo come ogni altro package Python:

```sh
$ pip install mypy
```

Per controllare il nostro modulo Python possiamo eseguirlo come segue:

```sh
$ python -m mypy my_module.py
```

Diamo di nuovo uno sguardo all'esempio `daily_average`:

```py
def daily_average(temperatures):
    return sum(temperatures) / len(temperatures)

average_temperature = daily_average(
    {1599125906: 22.8, 1599125706: 19.6, 1599126006: 25.9}
)
```

Quando effettuiamo il type checking con mypy su questo codice, non ci sono errori, dal momento che la funzione non usa dei type hints:

```sh
Success: no issues found in 1 source file
```

Aggiungiamo i type hint:

```py
from typing import List


def daily_average(temperatures: List[float]) -> float:
    return sum(temperatures) / len(temperatures)


average_temperature = daily_average(
    {1599125906: 22.8, 1599125706: 19.6, 1599126006: 25.9}
)
```

Eseguiamo di nuovo `mypy`:

```sh
$ python -m mypy my_module.py
```

Dovremmo vedere un output di questo tipo:

```sh
my_module.py:9: error: Argument 1 to "daily_average" has incompatible
type "Dict[int, float]"; expected "List[float]"

Found 1 error in 1 file (checked 1 source file)
```

mypy ha riconosciuto che la funzione era chiamata in maniera non corretta. Aveva riportato il nome del file, il numero di linea, e la descrizione dell'errore. Usare i type hint assieme a mypy può aiutare a ridurre il numero di errori risultanti dall'uso sbagliato di funzioni, metodi, e classi. Questo risulta in loop di feedback più rapidi. Non abbiamo bisogno di eseguire tutti i nostri test o effettuare il deploy dell'intera applicazione. Siamo notificati di questi errori immediatamente.

E' anche una buona idea aggiungere mypy alla nostra CI pipeline, così come effetutare il type checking prima che sia fatto il merge o il deploy del nostro codice, come abbiamo detto nell'[articolo sulla qualità del codice Python](04_code_quality.md).

Anche se rappresenta un grosos miglioramento in termini di qualità del codice, il type chekcing statico non forza i tipi a runtime. Questo è il motivo per cui abbiamop anche dei type checker a runtime, che vedremo a brevev.

mypy contiene anche typeshed, che contiene delle annotazioni di tipo esterne per la libreria standard Python e per i tipi integrati in Python, così come package di terze parti.

mypy controlla i programmi Python senza alcun overhead a runtime. Anche se controlla i tipi, il duck typing è sempre valido. Quindi, non può essere usato per compilare le estensioni CPython.

## Type Checking a runtime

### pydantic

I type checker statici non ci aiutano con i dati da sorgenti esterne come gli utenti della nostra applciazione. Qui è dove i runtime type checker entrano in gioco. Un tool per far questo è [pydantic](#), che viene usato per validare i dati. Lancia un errore di validazione quando i dati forniti non combaciano con un tipo definito con un type hint.

pydantic usa il type casting per convertire i dati di input per forzarlo a conformarsi al tipo atteso.

```sh
$ pip install pydantic
```

E' abbastanza semplice da usare. Per esempio, definiamo una classe `Song` con alcuni attributi:

```py
from datetime import date
from typing import List

from pydantic import BaseModel


class Song(BaseModel):
    id: int
    name: str
    release: date
    genres: List[str]
```

Ora, quando inizializziamo una nuova `Song` con dati validi, tutto funziona come atteso:

```py
song = Song(
    id=101,
    name='Bohemian Rhapsody',
    release='1975-10-31',
    genres=[
        'Hard Rock',
        'Progressive Rock'
    ]
)
print(song)
# id=101 name='Bohemian Rhapsody' release=datetime.date(1975, 10, 31)
# genres=['Hard Rock', 'Progressive Rock']
```

Tuttavia, quando proviamoa d inizializzare una nuova Song con una data non valida viene lanciato un `ValidationError`:

```py
song = Song(
    id=101,
    name='Bohemian Rhapsody',
    release='1975-31-31',
    genres=[
        'Hard Rock',
        'Progressive Rock'
    ]
)
print(song)
# pydantic.error_wrappers.ValidationError: 1 validation error for Song
# release
#   invalid date format (type=value_error.date)
```

Con pydantic, possiamo assicurarci che soltanto i dati che combaciano con i tipi che abbiamo definito siano usati nella nostram applicazione. Questo comporta non solo meno bug, ma dovremo anche scrivere meno test. Usando strumenti come `pydantic` non dobbiamo scrivere test per i casi dove l'utente manda dei dati completamente errati. Tutto ciò viene gestito da pydantic: infatti, viene lanciato un `ValidationError`. Ad esempio, FastAPI valida le richieste e le risposte HTTP mediante `pydantic`:

```py
from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()


class Item(BaseModel):
    name: str
    price: float


@app.post("/items/", response_model=Item)
async def create_item(item: Item):
    return item
```

L'handler `create_item` si attende un payload con un nome (`string`) ed un prezzo (`float`). La risposta dovrebbe essere simile. Adesso, se c'è un problema con il payload fornito, viene subito lanciato un errore. Lanciarlo in ritardo rende più difficile effettuare il debug e determianre da dove è venuto il dato di tipo errato. Inoltre, dal momento che è gestito da pydantic, possiamo tenere i nostri handler più puliti.

Assieme allo sfruttare i type hiunts per la validazione dei dati possiamo anche aggiungere dei validator custom per assicurare la correttezza dei dati oltre al loro tipo. Aggiungere una validazione custom per un attirbuto è abbastanza semplice. Per esempio, per prevenire i duplicati di genere nella classe `Song`, possiamo aggiugnere una validazione come segue:

```py
from datetime import date
from typing import List

from pydantic import BaseModel, validator


class Song(BaseModel):
    id: int
    name: str
    release: date
    genres: List[str]

    @validator('genres')
    def no_duplicates_in_genre(cls, v):
        if len(set(v)) != len(v):
            raise ValueError(
                'No duplicates allowed in genre.'
            )
        return v


song = Song(
    id=101,
    name='Bohemian Rhapsody',
    release='1975-10-31',
    genres=[
        'Hard Rock',
        'Progressive Rock',
        'Progressive Rock',
    ]
)
print(song)
# pydantic.error_wrappers.ValidationError: 1 validation error for Song
# genre
#   No duplicates allowed in genre. (type=value_error)
```

Per cui il metodo di validazione, `no_duplicates_in_genre`, deve essere decorato con un validator, che prende il nome dell'attributo come argomento. Il metodo di validazione deve essere un meotod di classe dal momento che la validazione avviene prima che l'istanza sia creata. Per i dati che falliscono la validazione dovrebbe lanciare un ValueError standard.

Possiamo anche usare i metodi di validazioen per alterare un valore prima che avvenga la validazione. Per farlo, aggiungiamo `pre=True` ed `always=True` al decorator validator:

```py
@validator('genres', pre=True, always=True)
```

Per esempio potremmo convertire i generi in minuscolo come segue:

```py
from datetime import date
from typing import List

from pydantic import BaseModel, validator


class Song(BaseModel):
    id: int
    name: str
    release: date
    genres: List[str]

    @validator('genres', pre=True, always=True)
    def to_lower_case(cls, v):
        return [genre.lower() for genre in v]

    @validator('genres')
    def no_duplicates_in_genre(cls, v):
        if len(set(v)) != len(v):
            raise ValueError(
                'No duplicates allowed in genre.'
            )
        return v


song = Song(
    id=101,
    name='Bohemian Rhapsody',
    release='1975-10-31',
    genres=[
        'Hard Rock',
        'PrOgReSsIvE ROCK',
        'Progressive Rock',
    ]
)
print(song)
# pydantic.error_wrappers.ValidationError: 1 validation error for Song
# genre
#   No duplicates allowed in genre. (type=value_error)
```

In particolare, `to_lower_case` converte ogni elemento nella lista dei genere in minuscolo. Siccome `pre` è impostato a `True`, questo metodo è chiamato prima che pydantic validi i tipi. Tutti i generi sono convertiti in minuscolo e quindi validati con `no_duplicates_in_genre`.

pydantic ci offre anche dei tipi più stretti, come PositiveInt ed EmailStr, pre rendere le validazioni migliori. In tal senso, possiamo dare un'occhiata alla sezione [Field Types](#) della documentazione.

## Marshmallow

Un altro tool degno di nota è [marshmallow](#), che ci aiuta a validare dati complessi e caricare o effettuare il dump di dati dao verso tipi Python nativi. Al solito, marshmallow si installa come ogni altro package Python:

```sh
$ pip install marshmallow
```

Come per pydantic, possiamo aggiungere la validazione di tipo ad una classe:

```py
from marshmallow import Schema, fields, post_load


class Song:
    def __init__(
            self,
            id,
            name,
            release,
            genres
    ):
        self.id = id
        self.name = name
        self.release = release
        self.genres = genres

    def __repr__(self):
        return (
            f'<Song(id={self.id}, name={self.name}), '
            f'release={self.release.isoformat()}, genres={self.genres}>'
        )


class SongSchema(Schema):
    id = fields.Int()
    name = fields.Str()
    release = fields.Date()
    genres = fields.List(fields.String())

    @post_load
    def make_song(self, data, **kwargs):
        return Song(**data)


external_data = {
    'id': 101,
    'name': 'Bohemian Rhapsody',
    'release': '1975-10-31',
    'genres': ['Hard Rock', 'Progressive Rock']
}

song = SongSchema().load(external_data)
print(song)
# <Song(id=101, name=Bohemian Rhapsody), release=1975-10-31, genres=['Hard Rock', 'Progressive Rock']>
```

A differenza di pydantic, marshmallow non usa il type casting, per cui dobbiamo definire lo schemae la classe *separatamente*. Ad esempio, la data di uscita in `external_data` deve essere una stringa ISO. Non funziona con un oggetto di tipo `datetime`.

Per abilitare la deserializzazione dei dati in un oggetto di tipo `Song`, dobbiamo aggiungere un metodo decorato con il decorator `@post_load` allo schema:

```py
class SongSchema(Schema):
    id = fields.Int()
    name = fields.Str()
    release = fields.Date()
    genres = fields.List(fields.String(), validate=no_duplicates)

    @post_load
    def make_song(self, data, **kwargs):
        return Song(**data)
```

Lo schema valida i dati e se tutti i campi sono validi crea un'istanza della classe chiamando `make_song` con i dati validati.

Come pydantic, possiamo aggiungere delle validazioni custom per ogni attributo a partire dallo schema. Ad esempio, possiamo prevenire dei duplicati:

```py
import datetime

from marshmallow import Schema, fields, post_load, ValidationError


class Song:
    def __init__(
            self,
            id,
            name,
            release,
            genres
    ):
        self.id = id
        self.name = name
        self.release = release
        self.genres = genres

    def __repr__(self):
        return (
            f'<Song(id={self.id}, name={self.name}), '
            f'release={self.release.isoformat()}, genres={self.genres}>'
        )


def no_duplicates(genres):
    if isinstance(genres, list):
        genres = [
            genre.lower()
            for genre in genres
            if isinstance(genre, str)
        ]

        if len(set(genres)) != len(genres):
            raise ValidationError(
                'No duplicates allowed in genres.'
            )


class SongSchema(Schema):
    id = fields.Int()
    name = fields.Str()
    release = fields.Date()
    genres = fields.List(fields.String(), validate=no_duplicates)

    @post_load
    def make_song(self, data, **kwargs):
        return Song(**data)


external_data = {
    'id': 101,
    'name': 'Bohemian Rhapsody',
    'release': '1975-10-31',
    'genres': ['Hard Rock', 'Progressive Rock', 'ProgressivE Rock']
}

song = SongSchema().load(external_data)
print(song)
# marshmallow.exceptions.ValidationError:
# {'genres': ['No duplicates allowed in genres.']}
```

Come possiamo vedere, possiamo sia usare pydantic sia marshmallow per assicurarci che i dati abbiano il tipo corretto man mano che la nostra applciazione viene eseguita. Il consiglio è quello di scegliere quello che più si adatta al nostro stile.

## Typeguard

Mentre pydantic e marshmallow si focalizzano sulla validazione e serializzazione dei dati, typeguard si focalizza sul controllo dei tipi man mano che le funzioni vengono chiamate. Mentre mypy efefttua soltanto il type checking statico, typeguard forza i tipi mentre il nostro prgramma è in esecuzione.

```sh
$ pip install typeguard
```

Vediamo lo stesso esempio di prima (quello della classe Song). Questa volta definiamo il suo metodo `__init__` con gli argomenti hinted:

```py
from datetime import date
from typing import List

from typeguard import typechecked


@typechecked
class Song:

    def __init__(
            self,
            id: int,
            name: str,
            release: date,
            genres: List[str]

    ) -> None:
        self.id = id
        self.name = name
        self.release = release
        self.genres = genres


song = Song(
    id=101,
    name='Bohemian Rhapsody',
    release=date(1975, 10, 31),
    genres={
        'Hard Rock',
        'Progressive Rock',
    }
)
print(song)
# TypeError: type of argument "genres" must be a list; got set instead
```

Il decorator `typechecked` può essere usato sia per classi, sia per funzioni, quando vogliamo forzare il type checking a runtime. Eseguire questo codice lancerà un `TypeError`, dal momento che i generi sono un set invece di una lista. Possiamo usare in modo simile un decorator per le funzioni:

```py
from typeguard import typechecked

@typechecked
def sum_ab(a: int, b: int) -> int:
    return a + b
```

Viene anche fornito un plugin per pytest. Per controllare i tipi per il package `my_package` mentre eseguiamo i test possiamo eseguire questo comando:

```sh
$ python -m pytest --typeguard-packages=my_package
```

Quando eseguiamo il comando con pytest non dobbiamo usare il decorator `@typechecked`. Di conseguenza, possiamo o decorare le nostre funzioni e classi per forzare i tipi a runtime oppure semplicemente durante l'esecuzione dei test. Ad ogni modo, typeguard può essere una rete di salvezza per la nostra applicazione, in modo da assicurarci che venga eseguita come ci si aspetta.

## Flask con pydantic

Mettiamo insieme i diversi pezzi in un'applicazione web. Come detto prima, FastAPI usa pydantic di default. Anche se Flask non ha il supporto integrato di default per ppydantic, possiamo usare dei buinding per aggiungerlo alle nostre API. Creiamo quindi un nuovo progetto Flask per vederlo in azione.

Per prima cosa, creiamo una nuova cartella:

```sh
$ mkdir flask_example
$ cd flask_example
```

Quindi, inizializziamo il nostro progetto con Pipenv:

```sh
$ pipenv install flask Flask-Pydantic
$ pipenv isntall -d pytest
```

Creiamo un file per i nostri test e chiamiamolo `test_app.py`:

```py
import json

import pytest

from app import app


@pytest.fixture
def client():
    app.config["TESTING"] = True

    with app.test_client() as client:
        yield client


def test_create_todo(client):
    response = client.post(
        "/todos/",
        data=json.dumps(
            {
                'title': 'Wash the dishes',
                'done': False,
                'deadline': '2020-12-12'
            }
        ),
        content_type='application/json'
    )

    assert response.status_code == 201


def test_create_todo_bad_request(client):
    response = client.post(
        "/todos/",
        data=json.dumps(
            {
                'title': 'Wash the dishes',
                'done': False,
                'deadline': 'WHENEVER'
            }
        ),
        content_type='application/json'
    )

    assert response.status_code == 400
```

Qui abbiamo due test per creare nuovi todo. Uno controlla che  lo stato di `201` sia restituito quando tutto va bene. Un altro controlla che lo status `400` sia restituito quando i dati forniti non sono quelli attesi. 

Quindi, aggiungiamo un file per l'app Flask chiamato `app.py`:

```py
import datetime

from flask import Flask, request
from flask_pydantic import validate
from pydantic import BaseModel

app = Flask(__name__)


class CreateTodo(BaseModel):
    title: str
    done: bool
    deadline: datetime.date


class Todo(BaseModel):
    title: str
    done: bool
    deadline: datetime.date
    created_at: datetime.datetime


@app.route("/todos/", methods=['POST'])
@validate(body=CreateTodo)
def todos():
    todo = Todo(
        title=request.body_params.title,
        done=request.body_params.done,
        deadline=request.body_params.deadline,
        created_at=datetime.datetime.now()
    )

    return todo, 201


if __name__ == "__main__":
    app.run()
```

Abbiamo definito un endpoint per creare i todo assieme ad uno schema di richieste chiamato `CreateTodo` ed uno di risposte chiamato `Todo`. Ora, quando i dati sono mandati all'API che non rispetta lo schema della richiest,a uno status di `400` con errori di validazione nel corpo viene restituito. Possiamo eseguire i test per controllare che l'API si stia comportando come descritto:

```sh
$ pipenv run pytest
```

## Eseguire i type checker

Ora che conosciamo gli strumenti, la domanda è: quando usarli?

In maneira simile ai tool di controllo di qualità del codice, tipicamente eseguiamo i type checker:

* quando stiamo programmando (all'interno quindi della nostra IDE);
* al momento della commit (mediante gli hook pre-commit);
* quando il codice viene mandato su una repository (mediante una pipeline di CI);
* durante l'esecuzione del nostro programma (a runtime).

### All'interno della nostra IDE

E' bene controallare problemi che possano avere un impatto negativo sulla qualità del codice spesso. QUindi, è raccomadnato effettuare il check statico del codice durante lo sviluppo. Molte delle IDE più popolari hanno dei type checkers simili a mypy (o mypy stesso) già integrati. Per quelle che non li hanno, vi è probabilmente un plugin disponibile. Questi plugin ci avvertono in tempo reale su eventuali violazioni di tipo e potenziali errori di programmazione.

### Pre-commit Hooks

Dal momento che inevitabilmente ci perderemo qualche warning mentre stiamo programmando, è una buona pratica controllare problemi sui tipi al momento della commit mediante dei pre-commit hooks. In questo modo possiamoe vitare di effettaure la commit di codice che non passerà i type check all'interno della nostra pipeline di CI.

Il framework pre-commit è quello raccomandato per la gestione dei git hooks:

```sh
$ pip install pre-commit
```

Una volta installato, aggiungiamo un file di cofnigurazione pre-commit chiamato `.pre-commit-config.yaml` al nostro progetto. Per eseguire mypy, aggiungiamo la seguente configurazione:

```yaml
repos:
  - repo: https://github.com/pre-commit/mirrors-mypy
    rev: 'v0.790'
    hooks:
      - id: mypy
```

Infine, per impostare gli script di git hook:

```sh
(venv)$ pre-commit install
```

Adesso, ogni volta che eseguiamo `git commit` mypy verrà eseguito prima della commit vera e propria. E se vi sono dei problemi la commit verrà annullata.

### CI Pipeline
Ha senso eseguire il type check statico all'interno della nostra pipeline CI per prevenire che problemi sui tipi siano portati nella code base. Questo è probabilmente il momento più importante per eseguire mypy o altre tecniche di type checking statico.

Potremmo avere dei problemi quando eseguiamo i type check statici con mypy, specialmente quando usiamo librerie di terze parti senza dei type hints. Probabilmente questa è la ragione principale per la quale molti evitano di effettuare dei controlli con mypy all'interno della pipeline di CI.

### A runtime

Per il tipe checking dinamico abbiamo bisogno di un programma effettivamente in esecuzione. Come detto prima, usare dei type checker di questo tipo richiede meno test, produce meno bug, e ci aiuta ad inidividuarli prima. Possiamo usarli per la validazione dei dati (con pydantic e marshmallow) e pèer forzare i tipi durante l'esecuzione dle porogramma (con typeguard).

## Conclusioni

Il type checking potrebbe sembrare non necessario quando si ha una ridotta code base, ma man mano che aumenta di dimensioni, più importante diventa. E' uno strato utleriore che ci protegge da bug facilmente prevenibili. I type hints, anche se non sono forzati dall'interprete, ci aiutano ad esprimere al meglio lo scopo di una variabile, funzione, o classe. La maggior parte delle IDE moderne fornisce dei plugin per avvisare gli sviluppatori di problemi sui tipi sulla base dei type hiunts. Per forzarli, possiamo includere  mypy nel nostro workflow per controllare in maniera statica se l'uso dei metodi combacia con i loro type hints. Anche se l'analisi statica può migliorare il nsotro codice, dobbiamo tener conto che il nostro software sta comunicando con il mondo esterno. Di consegeunza, è preferibile aggiungere dei type checker dinamici a runtime come pydantic o marshmallow. Questi ci aiuteranno a validare l'input dell'utente e lancaire gli errori il prima possibile. Più rapidamente troviamo un errore, più facile è correggerlo.
