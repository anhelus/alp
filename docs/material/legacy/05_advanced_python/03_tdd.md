Il test di codice production-grade è duro. Alle volte può prendere tutto il tempo necessario allo sviluppo delle feature. Inoltre, anche se abbiamo una copertura del 100% e tutti i test riesono, potremmo essere sempre non confidenti rispetto al fatto che la nuova feature funzionerà bene in produzione.

In questo articoo vedremocome sviluppare un'app usando il Test-Driven Development (TDD). Vedremo come e cosa testare. Useremo pytest per il testing, pydantic per validare i dati e ridurre il numero di test richiesti, e Flask per fornire un'interfaccia ai client con una API RESTful. Alla fine, avremo un pattern solido che possiamo usare per progetti Python generici, in modo da avere una certa confidenza sul fatto che i test passati indicano un software funzionante.

## Obiettivi

In questo articolo, vedremo come:

* Spiegare come dovremo eseguire i test sul nostro software
* Configurare pytest ed impostare una struttura di progetto per i test 
* Definire dei modelli database con pydantic
* USare le fixture di pytest per gestire lo stato del test e valutare dei side effect
* Verificare le risposte JSON rispetto alle definizioni sullo Schema JSON
* Organizzare le operazioni sul database mediante comandi (che cambiano lo stao ed hanno effetti collaterali) e query (read-only, senza effetti collateriali)
* Scrivere unit test, integration test ed end-to-end test mediante pytest
* Spiegare perché sia importante foalizzare gli sforzi di test sul comportamento del test piuttosto che sui dettagli implementativi

## Come testare il nostro software?

Gli sviluppatori software tendono ad essere molto soggettivi sul testing. A causa di questo, hanno opinioni divergenti su quanto è importante il test, ed idee divergenti su come farlo. Detto questo, vediamo tre linee guida su cui sperabilmente la maggior parte degli sviluppatori concorderà e che ci aiutano a scrivere test ottimali:

* i test devono indicare il comportamento atteso dell'unità sotto test. Quindi, è preferibile mantenerli brevi e dritti al punto. La struttura GIVEN, WHEN, THEN può aiutarci a farlo:

GIVEN - quali sono le condizioni iniziali per il test?
WHEN - cosa deve essere testato?
THEN - quale è la risposta attesa?

Per cui dovremmo preparare il nostro ambiente per il testing, eseguire il comportamento e, alla fine, controllare che gli output rispettino le attese.

Ogni parte di comportamento deve essere testata una ed una sola volta. Testare lo stesso comportamento non significa che il nostro software funzionerà meglio. I test devono essere anche manutenuti. Se facciamo un piccolo cambio alla nostra code base e si rompono venti test, come sappiamo quale funzionalità è rotta? Quando invece è soltanto un singolo test a rompersi, è molto più semplice individuare il bug.

Ogni test deve essere indipendente dagli altri. Altrimenti, avremo difficoltà a mentenere ed eseguire la suite di test.

Questo articolo è soggettivo anche. Non prendiamo tutto come il sacro graal o un proiettile d'argento.

## Setup base

Detto questo, è giunto il momento di sporcarci le mani. Vediamo, in pratica, cosa significa questo nel mondo reale. Il test più semplice che possiamo eseguire mediante pytest è il seguente:

```py
def another_sum(a, b):
    return a + b

def test_another_sum():
    assert another_sum(3, 2) == 5
```

Questo è l'esempio che probabilmente tutti noi abbiamo visto almeno una volta. Per prima cosa, non scriveremo mai dei test all'interno della nostra codebase, per cui suddividiamo questo in due file e package.

Creiamo una nuova cartella per questo progetto e spostiamoci al suo interno:

```sh
$ mkdir testing_project
$ cd testing_project
```

A questo punto, creiamo ed attiviamo un ambiente virtuale.

Installiamo quindi pytest:

```sh
(venv)$ pip install pytest
```

Dopo aver fatto questo, creiamo una nuova cartella chiamata `sum`. Aggiungiamo un file `__init__.py` nella cartella per trasformarla in un package, assieme ad un file `another_sum.py`:

```py
def another_sum(a, b):
    return a + b
```

Aggiungiamo un'altra cartella **tests** ed aggiungiamo i seguenti file e cartelle:

```
└── tests
    ├── __init__.py
    └── test_sum
        ├── __init__.py
        └── test_another_sum.py
```

Dovremmo avere quindi una struttura di questo tipo:

```
├── sum
│   ├── __init__.py
│   └── another_sum.py
└── tests
    ├── __init__.py
    └── test_sum
        ├── __init__.py
        └── test_another_sum.py
```

Nel file `test_another_sum.py` aggiungiamo:

```py
from sum.another_sum import another_sum


def test_another_sum():
    assert another_sum(3, 2) == 5
```

A questo punto, aggiungiamo un file `conftest.py` vuoto, che viene usato per memorizzare le fixture di pytest, assieme alla cartella **tests**.

Infine, aggiungiamo un file `pytest.ini` (ovvero, un file di configurazione pytest)

La struttura finale del progetto è come segue:

```
├── sum
│   ├── __init__.py
│   └── another_sum.py
└── tests
    ├── __init__.py
    ├── conftest.py
    ├── pytest.ini
    └── test_sum
        ├── __init__.py
        └── test_another_sum.py
```

In definitiva, tenere i test assieme all'interno di un singolo package ci permette di:

* riutilizzare la configurazione di pytest in tutti i test
* riutilizzare le fixture in tutti i test
* semplificare l'esecuzione dei test

Possiamo eseguire tutti i test con questo comando:

```sh
(venv)$ python -m pytest tests
```

Dovremmo quindi vedere i risultati dei test, che in questo caso valgono:

```sh
============================== test session starts ==============================
platform darwin -- Python 3.10.1, pytest-7.0.1, pluggy-1.0.0
rootdir: /testing_project/tests, configfile: pytest.ini
collected 1 item

tests/test_sum.py/test_another_sum.py .                                 [100%]

=============================== 1 passed in 0.01s ===============================
```

## Un'applicazione reale

Ora che abbiamo l'idea base di come impostare e strutturare i nostri test, costruiamo un semplice blog. Lo costruiremo usando il TDD per vedere il test in azione. Useremo Flask come framework web e, per focalizzarci sul testing, SQLite come database.

La nostra app avrà i seguenti requisiti:

* potremo creare degli aritcoli
* leggere articoli
* restituire una lista di articoli

Per prima cosa, creiamo un nuovo progetto:

```sh
$ mkdir blog_app
$ cd blog_app
```

A questo punto, creiamo ed attiviamo un nuovo ambiente virtuale. Installiamo al suo interno pytest e pydantic, una liberia per il parsing e la validazione dei dati:

```sh
(venv)$ pip install pytest && pip install "pydantic[email]"
```

Notiamo che stiamo installando "pydantic[email]", che ci permette di installare pydantic con un validatore delle email, che useremo per validare gli indirizzi email inseriti.

A questo punto, creiamo i seguenti file e cartelle:

```
blog_app
    ├── blog
    │   ├── __init__.py
    │   ├── app.py
    │   └── models.py
    └── tests
        ├── __init__.py
        ├── conftest.py
        └── pytest.ini
```

Aggiungiamo il seguente codice al file `models.py` per definire il modello per un nuovo Articolo mediante pydantic:

```py
import os
import sqlite3
import uuid
from typing import List

from pydantic import BaseModel, EmailStr, Field


class NotFound(Exception):
    pass


class Article(BaseModel):
    id: str = Field(default_factory=lambda: str(uuid.uuid4()))
    author: EmailStr
    title: str
    content: str

    @classmethod
    def get_by_id(cls, article_id: str):
        con = sqlite3.connect(os.getenv("DATABASE_NAME", "database.db"))
        con.row_factory = sqlite3.Row

        cur = con.cursor()
        cur.execute("SELECT * FROM articles WHERE id=?", (article_id,))

        record = cur.fetchone()

        if record is None:
            raise NotFound

        article = cls(**record)  # Row can be unpacked as dict
        con.close()

        return article

    @classmethod
    def get_by_title(cls, title: str):
        con = sqlite3.connect(os.getenv("DATABASE_NAME", "database.db"))
        con.row_factory = sqlite3.Row

        cur = con.cursor()
        cur.execute("SELECT * FROM articles WHERE title = ?", (title,))

        record = cur.fetchone()

        if record is None:
            raise NotFound

        article = cls(**record)  # Row can be unpacked as dict
        con.close()

        return article

    @classmethod
    def list(cls) -> List["Article"]:
        con = sqlite3.connect(os.getenv("DATABASE_NAME", "database.db"))
        con.row_factory = sqlite3.Row

        cur = con.cursor()
        cur.execute("SELECT * FROM articles")

        records = cur.fetchall()
        articles = [cls(**record) for record in records]
        con.close()

        return articles

    def save(self) -> "Article":
        with sqlite3.connect(os.getenv("DATABASE_NAME", "database.db")) as con:
            cur = con.cursor()
            cur.execute(
                "INSERT INTO articles (id,author,title,content) VALUES(?, ?, ?, ?)",
                (self.id, self.author, self.title, self.content)
            )
            con.commit()

        return self

    @classmethod
    def create_table(cls, database_name="database.db"):
        conn = sqlite3.connect(database_name)

        conn.execute(
            "CREATE TABLE IF NOT EXISTS articles (id TEXT, author TEXT, title TEXT, content TEXT)"
        )
        conn.close()
```

Questo è un modello di tipo Active Record, che fornisce metodi per memorizzare, estrarre un singolo articolo, e creare la lista di tutti gli articoli.

Potremmo chiederci perché non abbiamo scritto dei test per coprire il modello. Lo capiremo a breve.

## Creazione di un nuovo articolo

Adesso, vediamo la business logic del nostro modello. Scriveremo alcuni comandi di aiuto e delle query per separare la nostra logica dal modello e delle API. Dal momento che stiamo usando pydantic, possiamo facilmente validare i dati sulla base del modello stesso.

Creiamo quindi un package **test_article** nella cartella **test**. Aggiungiamo quindi un file chiamato **test_commands.py**.

```
blog_app
    ├── blog
    │   ├── __init__.py
    │   ├── app.py
    │   └── models.py
    └── tests
        ├── __init__.py
        ├── conftest.py
        ├── pytest.ini
        └── test_article
            ├── __init__.py
            └── test_commands.py
```

Aggiungiamo i seguenti test a **test_commands.py**:

```py
import pytest

from blog.models import Article
from blog.commands import CreateArticleCommand, AlreadyExists


def test_create_article():
    """
    GIVEN CreateArticleCommand with valid author, title, and content properties
    WHEN the execute method is called
    THEN a new Article must exist in the database with the same attributes
    """
    cmd = CreateArticleCommand(
        author="john@doe.com",
        title="New Article",
        content="Super awesome article"
    )

    article = cmd.execute()

    db_article = Article.get_by_id(article.id)

    assert db_article.id == article.id
    assert db_article.author == article.author
    assert db_article.title == article.title
    assert db_article.content == article.content


def test_create_article_already_exists():
    """
    GIVEN CreateArticleCommand with a title of some article in database
    WHEN the execute method is called
    THEN the AlreadyExists exception must be raised
    """

    Article(
        author="jane@doe.com",
        title="New Article",
        content="Super extra awesome article"
    ).save()

    cmd = CreateArticleCommand(
        author="john@doe.com",
        title="New Article",
        content="Super awesome article"
    )

    with pytest.raises(AlreadyExists):
        cmd.execute()
```

Questi test coprono i seguenti casi d'uso:

* gli articoli devono essere creati a partire da dati validi
* i titoli degli articoli devono essere unici

Eseguiamo i test dalla nostra cartella di progetto per vedere come falliscono:

```sh
(venv)$ python -m pytest tests
```

Adesso possiamo implementare i nostri comandi. Aggiungiamo un file commands.py alla cartella **blog**:

```py
from pydantic import BaseModel, EmailStr

from blog.models import Article, NotFound


class AlreadyExists(Exception):
    pass


class CreateArticleCommand(BaseModel):
    author: EmailStr
    title: str
    content: str

    def execute(self) -> Article:
        try:
            Article.get_by_title(self.title)
            raise AlreadyExists
        except NotFound:
            pass

        article = Article(
            author=self.author,
            title=self.title,
            content=self.content
        ).save()

        return article
```

## Test delle fixture

Possiamo usare le fixture di pytest per pulire il database dopo ogni test e crearne uno nuovo prima di ogni test. Le fixture sono delle funzioni decorate con un decorator di tipo `@pytest.fixture`. Di solito, sono collocate all'interno di `conftest.py`, ma possono essere anche aggiunte ai file di test veri e propri. Queste funzioni sono eseguite di default prima di ogni test.

Un'opzione è quella di usare i valori restituiti all'interno dei nostri test. Ad esempio:

```py
import random
import pytest


@pytest.fixture
def random_name():
    names = ["John", "Jane", "Marry"]
    return random.choice(names)


def test_fixture_usage(random_name):
    assert random_name
So, to use the value returned from the fixture inside the test you just need to add the name of the fixture function as a parameter to the test function.

Another option is to perform a side effect, like creating a database or mocking a module.

You can also run part of a fixture before and part after a test using yield instead of return. For example:

@pytest.fixture
def some_fixture():
    # do something before your test
    yield # test runs here
    # do something after your test
```

Adesso, aggiungiamo la seguente fixture a `conftest.py`, che crea un nuovo database prima di ogni test e lo rimuove immediatamente dopo:

```py
import os
import tempfile

import pytest

from blog.models import Article


@pytest.fixture(autouse=True)
def database():
    _, file_name = tempfile.mkstemp()
    os.environ["DATABASE_NAME"] = file_name
    Article.create_table(database_name=file_name)
    yield
    os.unlink(file_name)
```

Il flag `autouse` è impostato a `True` in modo che sia automaticamente usato di default prima (e dopo) ogni test nella suite di test. Dal momento che stiamo usando un database per tutti i test ha senso usare questo flag. In questo modo non dobbiamo aggiungere in maniera esplicita il nome della fixture ad ognit est come parametro.

Se non dobbiamo avere accesso al database per un test possiamo disabilitare autouse con un test marker. Possiamo vedere un esempio di questo qui.,

Eseguiamo nuovamente i test:

```sh
(venv)$ python -m pytest tests
```

Stavolta, dovrebbero passare.

Come possiamo vedere, i nostri test testano soltanto il comando CreateArticleCommand. Non testiamo il modello Article vero e proprio, in quatno non risulta essere responsabile per la logica di business. Sappiamo che il comando funziona come atteso. Quindi, non c'è la necessità di scrivere ulteriori test.

## lista di tutti gli articoli

Il requisito succesivo è quello di elencare la lista di tutti gli articoli. Useremo una query invece di un comando, per cui aggiungiamo un nuovo file chiamato test_queries.py alla cartella test_article:

```py
from blog.models import Article
from blog.queries import ListArticlesQuery


def test_list_articles():
    """
    GIVEN 2 articles stored in the database
    WHEN the execute method is called
    THEN it should return 2 articles
    """
    Article(
        author="jane@doe.com",
        title="New Article",
        content="Super extra awesome article"
    ).save()
    Article(
        author="jane@doe.com",
        title="Another Article",
        content="Super awesome article"
    ).save()

    query = ListArticlesQuery()

    assert len(query.execute()) == 2
```

Eseguiamo i test:

```sh
(venv)$ python -m pytest tests
```

I test dovrebbero adesso fallire.

Aggiungiamo un file `queries.py` alla cartella *blog*:

```
blog_app
    ├── blog
    │   ├── __init__.py
    │   ├── app.py
    │   ├── commands.py
    │   ├── models.py
    │   └── queries.py
    └── tests
        ├── __init__.py
        ├── conftest.py
        ├── pytest.ini
        └── test_article
            ├── __init__.py
            ├── test_commands.py
            └── test_queries.py
```

Adesso possiamo implementare la nostra query:

```py
from typing import List

from pydantic import BaseModel

from blog.models import Article


class ListArticlesQuery(BaseModel):

    def execute(self) -> List[Article]:
        articles = Article.list()

        return articles
```

Anche se non abbiamo dei parametri, per consistenza, abbiamo ereditato da `BaseModel`.

Eseguiamo nuovamente i test:

```sh
(venv)$ python -m pytest tests
```

Adesso dovrebbero passare.

## Get Article by ID

Ottenere un articolo dal suo ID può essere fatto in modo simile all'elenco di tutti gli aritcopli. Aggiungiamo un nuovo test per GetArticleByIDQuery a test_queries.py:

```py
from blog.models import Article
from blog.queries import ListArticlesQuery, GetArticleByIDQuery


def test_list_articles():
    """
    GIVEN 2 articles stored in the database
    WHEN the execute method is called
    THEN it should return 2 articles
    """
    Article(
        author="jane@doe.com",
        title="New Article",
        content="Super extra awesome article"
    ).save()
    Article(
        author="jane@doe.com",
        title="Another Article",
        content="Super awesome article"
    ).save()

    query = ListArticlesQuery()

    assert len(query.execute()) == 2


def test_get_article_by_id():
    """
    GIVEN ID of article stored in the database
    WHEN the execute method is called on GetArticleByIDQuery with an ID
    THEN it should return the article with the same ID
    """
    article = Article(
        author="jane@doe.com",
        title="New Article",
        content="Super extra awesome article"
    ).save()

    query = GetArticleByIDQuery(
        id=article.id
    )

    assert query.execute().id == article.id
```

Eseguiamo i test per assicurarci che falliscano:

```sh
(venv)$ python -m pytest tests
```

Adesso, aggiungiamo GetArticleByIDQuery a queries.py:

```py
from typing import List

from pydantic import BaseModel

from blog.models import Article


class ListArticlesQuery(BaseModel):

    def execute(self) -> List[Article]:
        articles = Article.list()

        return articles


class GetArticleByIDQuery(BaseModel):
    id: str

    def execute(self) -> Article:
        article = Article.get_by_id(self.id)

        return article
```

I test dovrebbero adesso passare:

```sh
(venv)$ python -m pytest tests
```

Bene. Abbiamo rispettato tutti i requisiti su menzionati:

* gli articoli possono essere creati
* gli articoli possono essere estratti
* gli articoli possono essere elencati

E tutto viene coperto da test. Dal momento che stiamo usando pydantic per la validazione dei dati a runtime, non abbiamo bisogno di molti test per coprire la logica di business in quanto non dobbiamo scrivere dei test per validare i dati. Se author non è una email valida, pydantic lancerà un errore. Tutto quello che era necessario era impostare l'attributo author al tipo EmailStr. Non dobbiamo testarlo perché è già stato testato dai mantainer di pydantic.

Con questo, siamo pronti ad esporre questa funzionalità al mondo mediante una API RESTful Flask.

## Esporre l'API con Flask

Introdurremo tre endpoint che coprono questo requisito.

* /create-article/ - creiamo un nuovo articolo
* /article-list/ - recuperiamo tutti gli articoli
* /article/<article_id>/ - estraiamo un singolo articolo

Per prima cosa, creiamo una cartella chiamata *schemas* in *test_article*, ed aggiungiamo due schemi JSON alla stessa, Article.json ed ArticleList.json.

```json "Article.json"
{
  "$schema": "http://json-schema.org/draft-07/schema#",
  "title": "Article",
  "type": "object",
  "properties": {
    "id": {
      "type": "string"
    },
    "author": {
      "type": "string"
    },
    "title": {
      "type": "string"
    },
    "content": {
      "type": "string"
    }
  },
  "required": ["id", "author", "title", "content"]
}
```
```json "ArticleList.json"
{
  "$schema": "http://json-schema.org/draft-07/schema#",
  "title": "ArticleList",
  "type": "array",
  "items": {"$ref":  "file:Article.json"}
}
```

Gli schemi JSON usati per definire le risposte dagli endpoint API. Prima di continuare, installiamo la libreria jsonschema, che sarà usata per validare i payload JSON, e Flask:

```sh
(venv)$ pip install jsonschema Flask
```

A questo punto, scriamo dei test di integrazione per la nostra API. Aggiungiamo un nuovo file chiamato test_app.py a test_article:

```py
import json
import pathlib

import pytest
from jsonschema import validate, RefResolver

from blog.app import app
from blog.models import Article


@pytest.fixture
def client():
    app.config["TESTING"] = True

    with app.test_client() as client:
        yield client


def validate_payload(payload, schema_name):
    """
    Validate payload with selected schema
    """
    schemas_dir = str(
        f"{pathlib.Path(__file__).parent.absolute()}/schemas"
    )
    schema = json.loads(pathlib.Path(f"{schemas_dir}/{schema_name}").read_text())
    validate(
        payload,
        schema,
        resolver=RefResolver(
            "file://" + str(pathlib.Path(f"{schemas_dir}/{schema_name}").absolute()),
            schema  # it's used to resolve the file inside schemas correctly
        )
    )


def test_create_article(client):
    """
    GIVEN request data for new article
    WHEN endpoint /create-article/ is called
    THEN it should return Article in json format that matches the schema
    """
    data = {
        'author': "john@doe.com",
        "title": "New Article",
        "content": "Some extra awesome content"
    }
    response = client.post(
        "/create-article/",
        data=json.dumps(
            data
        ),
        content_type="application/json",
    )

    validate_payload(response.json, "Article.json")


def test_get_article(client):
    """
    GIVEN ID of article stored in the database
    WHEN endpoint /article/<id-of-article>/ is called
    THEN it should return Article in json format that matches the schema
    """
    article = Article(
        author="jane@doe.com",
        title="New Article",
        content="Super extra awesome article"
    ).save()
    response = client.get(
        f"/article/{article.id}/",
        content_type="application/json",
    )

    validate_payload(response.json, "Article.json")


def test_list_articles(client):
    """
    GIVEN articles stored in the database
    WHEN endpoint /article-list/ is called
    THEN it should return list of Article in json format that matches the schema
    """
    Article(
        author="jane@doe.com",
        title="New Article",
        content="Super extra awesome article"
    ).save()
    response = client.get(
        "/article-list/",
        content_type="application/json",
    )

    validate_payload(response.json, "ArticleList.json")
```

Che cosa sta succedendo qui?

Per prima cosa, definiamo il client di test Flask come una fixture, in modo che possa essere usato nei test. A questo punto, aggiungiamo una funzione per la validazione dei payload. In tal senso, usiamo due parametri:

* payload - la risposta JSON dall'API
* schema_name: il nome del file dello schema all'interno della cartella "schemas"

Infine, ci sono tre test, uno per ogni endpoint. All'interno di ciascun test vi è una chiamata all'API e la validazione del payload restituito.

Eseguiamo i test per assicurarci che falliscano a questo punto:

```sh
(venv)$ python -m pytest tests
```

Adesso possiamo scrivere le API.

Aggiorniamo `app.py` come segue:

```py
from flask import Flask, jsonify, request

from blog.commands import CreateArticleCommand
from blog.queries import GetArticleByIDQuery, ListArticlesQuery

app = Flask(__name__)


@app.route("/create-article/", methods=["POST"])
def create_article():
    cmd = CreateArticleCommand(
        **request.json
    )
    return jsonify(cmd.execute().dict())


@app.route("/article/<article_id>/", methods=["GET"])
def get_article(article_id):
    query = GetArticleByIDQuery(
        id=article_id
    )
    return jsonify(query.execute().dict())


@app.route("/article-list/", methods=["GET"])
def list_articles():
    query = ListArticlesQuery()
    records = [record.dict() for record in query.execute()]
    return jsonify(records)


if __name__ == "__main__":
    app.run()
```

I nostri route handler sono abbastanza semplici dato che tutta la logica è coperta da comandi e query. Le azioni disponibili con side effects, come mutazioni, sono rappresentate dai comandi (ad esempio, creare un nuovo articol). D'altro canto, le azioni che non hanno un side effect, quelle che stanno semplicemente leggendo lo stato corrente, sono coperte dalle query.

I pattern delle query ed i comandi usati in questo articolo sono uina versioen semplificata del pattern CQRS. In pratica, stiamo combinando CQRS e CRUD.

Il metodo `.dict()` di prima viene fornito dal BaseModel di pydantic, da cui tutti i nostri modelli ereditano.

Il test dovrebbe avere successo:

```sh
(venv)$ python -m pytest tests
```

Abbiamo coperto gli scenari "corretti". Nel mondo reale ci dovremo aspettare che i client non sempre useranno le API come dovrebbero. Ad esempio, quando la richiesta per creare un articolo è fatta senz aun titolo, sarà lanciato un errore dal comando CreateArticleCommand, che risulterà in un errore interno del server ed uno status HTTP 500. Questo è qualcosa che vogliamo evitare. Quindi, dobbiamo gestire questi errori in modo da notificare l'utente della richiesta sbagliata in maniera "soft".

Scriviamo dei test per coprire questi casi. Aggiungiamo il seguente a `test_app.py`:

```py
@pytest.mark.parametrize(
    "data",
    [
        {
            "author": "John Doe",
            "title": "New Article",
            "content": "Some extra awesome content"
        },
        {
            "author": "John Doe",
            "title": "New Article",
        },
        {
            "author": "John Doe",
            "title": None,
            "content": "Some extra awesome content"
        }
    ]
)
def test_create_article_bad_request(client, data):
    """
    GIVEN request data with invalid values or missing attributes
    WHEN endpoint /create-article/ is called
    THEN it should return status 400
    """
    response = client.post(
        "/create-article/",
        data=json.dumps(
            data
        ),
        content_type="application/json",
    )

    assert response.status_code == 400
    assert response.json is not None
```

Abbiamo usato l'opzione parametrize di pytest, che semplifica il passaggio di più input ad un singolo test.

I test dovrebbero fallire a questo punto perché non abbiamo ancora gestito il `ValidationError`:

```sh
(venv)$ python -m pytest tests
```

Aggiungiamo un error handler all'app Flask all'interno di `app.py`:

```py
from pydantic import ValidationError

# Other code ...

app = Flask(__name__)


@app.errorhandler(ValidationError)
def handle_validation_exception(error):
    response = jsonify(error.errors())
    response.status_code = 400
    return response

# Other code ...
```

Il `ValidationError` ha un metodo per la gestione degli errori che restituisce una lista di tutti gli errori per ogni campo che è mancante o passa un valore che non ha passato la validazione. Possiamo semplicemente restituire qeusto nel corpo ed impostare lo status della rsiposta a 400.ù

Ora che l'errore è propriamente gestito, tutti i test dovrebbero passare:

```sh
(venv)$ python -m pytest tests
```

## Code Coverage

Adesso, con l'applicazione testata, è il momento di controlare la copertura del codice. Installiamo un plugin di pytest per far questo chiamato `pytest-cov`:

```sh
(venv)$ pip install pytest-cov
```

Dopo che il plugin è installato, possiamo controllare il code coverage della nostra applicazione blog come segue:

```sh
(venv)$ python -m pytest tests --cov=blog
```

Dovremmo vedere qualcosa di simile:

```sh
---------- coverage: platform darwin, python 3.10.1-final-0 ----------
Name               Stmts   Miss  Cover
--------------------------------------
blog/__init__.py       0      0   100%
blog/app.py           25      1    96%
blog/commands.py      16      0   100%
blog/models.py        57      1    98%
blog/queries.py       12      0   100%
--------------------------------------
TOTAL                110      2    98%
```

Il 98% è un buon risultato, ma dobbiamo sempre ricordarci che un'alta percentuale di copertura èp buyona, ma la qualità dei nostri test è molto più importante. Se soltanto il 70% o meno del codice è coiperto, dovremmo pensare a come aumentare la percentuale di copertura; in generale, però, non ha senso scrivere test che vadano dal 98 al 100$ (di nuovo, i test devono essere mantenuti proprio come la nostra logica di business).

## Test end-to-end

Abbiamo un'API funzionante a questo punto che è completamente testata. Possiamo adesso guardare a come scrivere dei test end-to-end (e2e). Dal momento che abbiamo una semplice API, possiamos crivere un singolo test e2e per coprire il seguente scenario:

* creare un nuovo articolo
* redigere la lista degli articoli
* ottenere il primo articolo della lsita

Per prima cosa, installiamo la libreria requests:

```sh
(venv)$ pip install requests
```

A  questo punto, aggiungiamo un nuovo test a `test_app.py`:

```py 
import requests
# other code ...

@pytest.mark.e2e
def test_create_list_get(client):
    requests.post(
        "http://localhost:5000/create-article/",
        json={
            "author": "john@doe.com",
            "title": "New Article",
            "content": "Some extra awesome content"
        }
    )
    response = requests.get(
        "http://localhost:5000/article-list/",
    )

    articles = response.json()

    response = requests.get(
        f"http://localhost:5000/article/{articles[0]['id']}/",
    )

    assert response.status_code == 200
```

Ci sono due cose che dobbiamo fare prima di eseguire questo test. Per prima cosa, registriamo un marker chiamato e2e con pytest aggiungendo il seguente codice a `pytest.ini`:

```ini
[pytest]
markers =
    e2e: marks tests as e2e (deselect with '-m "not e2e"')
```

I marker pytest sono usati per escludere dei test dall'esecuzione, o per includere i test selezionati indipendentemente dalla loro posizione.

Per eseguire soltanto i test e2e, eseguiamo:

```sh
(venv)$ python -m pytest tests -m 'e2e'
```

Per eseguire tutti i test ad eccezione degli e2e:

```sh
(venv)$ python -m pytest tests -m 'not e2e'
```

I test e2e sono più costosi da eseguire e richiedono che l'app sia configurata ed in esecuzione, per cui probabilmente non vorremo eseguirli sempre.

Dal momento che i nostri test e2e vanno a riguardare un server live, dovremo lanciare l'app. Navighiamo nel progetto in un nuovo terminale, attiviamo l'am,biente virtuale, ed esegfuiamo l'app:

```sh
(venv)$ FLASK_APP=blog/app.py python -m flask run
```

Adesso possiamo eseguire il nostro test e2e:

```sh
(venv)$ python -m pytest tests -m 'e2e'
```

Dovremmo vedere un errore 500. Perché? Non è passato l'unit test? Sì. Il problema è che non abbiamo creato la tabella del database. Abbiamo suato delle fixture per questo nei nostri test che lo fanno per noi. Creiamo quindi una tabella ed un datrabase.

Aggiungiamo un file `inti_db.py` nella cartella *blog*:

```py
if __name__ == "__main__":
    from blog.models import Article
    Article.create_table()
```

Eseguiamo il nuovo script e lanciamo di nuovo il server:

```sh
(venv)$ python blog/init_db.py
(venv)$ FLASK_APP=blog/app.py python -m flask run
```

Se abbiamo dei problemi nell'eseguire `init_db.py`, dovremmo voler impostare il pathg Python:

```sh
export PYTHONPATH=$PYTHONPATH:$PWD.
```

I test dovrebbero adesso passare.

```sh
(venv)$ python -m pytest tests -m 'e2e'
```

## Testing Pyramid

Abbiamo iniziato con gli unit test (per testare i comandi e le query) seguiti dagli integration test (per testare gli endpoint), ed abbiamo finito con i test e2e. In semplici applicazioni, come in questo esempio, possiamo finire con un unmero simile di unit ed integration test. In generale, maggiore è la complessità, più dovremmo vedere una forma simile ad una piramide in termini della relazione tra unit, integration e test e2e. Qui è da dove viene il termine "test pyramid".

La Test Pyramid è un framework che ci aiuta a creare del software di alta qualità.

### Test Pyramid

Usando il concetto di Test Pyramid come guida, vogliamo tipicamente che il 50% dei test nella nostra test suite sia unit test, il 30% integration test, ed il 20% e2e test.

| Tipo di test | Descrizione |
| ------------ | ----------- |
| Unit test | Testa una singola unità di codice |
| Integration test | Testa che più unità lavorino insieme |
| Test e2e | Testa l'intera applicazione in un ambiente simile a quello di produzione |

Più in alto andiamo nella piramide, più BRITTLE e meno predicibili sono i nostri test. Inoltre, i test e2e sono di gran lunga i più lenti da eseguire, per cui anche se possono assicurarci che la nsotra applicazione stia facendo quello per cui ci si aspetta che funzioni, non dovremmo averne così tanti come gli unit o integration test.

### Cosa è una Unit?

E' semplice capire cosa sono i test e2e e quelli di integration. Vi è molta più discussione a riguardo degli unit test dal momento che dobbiamo per prima cosa definire quello che è in effetti una "unit". La maggior parte dei tutotrial ci mostra che una unit è una singola funzione o metodo. Purtroppo, il codice nei casi reali non è quasi mai così semplice.

Tuttavia, prima di definire quello che è una unit, vediamo qual è il motivo per cui effettuare il test, e cosa dovrebbe essere testato.

### Perché testare?

Scriviamo dei test per:

* assicurarci che il nostro codice funzioni come atteso
* proteggiamo i software contro i problemi di regressione

Nonostante questo, quando i cicli di feedback sono troppo lunghi, gli sviluppatori tendono ad iniziare a pensare più sui tipi di test da scrivere dal momento che il tempo è un vincolo importante nello sviluppo software. Ecco perché vogliamo avere più unit test che altri tipi di test. Vogliamo trovare e fixare il difetto quanto prima possibile.

## Cosa testare?

Ora che sappiamo che cosa dobbiamo testare, dobbiamo vedere quello che stiamo testando.

Dovremmo testare il comportamento del nostro software. E, sì, questo si applica al TDD, non solo al BDD. Questo è il motivo per cui non dovremmo dover cambiare i nostri test ogni volta che vi è un cambio nella codebase.

Pensiamo di nuovo all'esempio dell'applicazione reale. Da una prospettiva di testing, non ci interessa dove gli articoli sono mermozizati. Potrebbe trattarsi di un file di testo, un database relazionale, un insieme di coppie chiave/valore - non importa. Di nuovo, l'app ha i seguenti requisiti:

* gli articoli possono essere creati
* gli articoli possono essere estratti
* gli articoli possono essere messi in lista

Fino a che questi requisiti non cambiano, un cambio nel mezzo di storage non romperà i nostri test. In modo simile, sappiamo che fino a che questi test passano, sappiamo che i software rispettano i requisiti preposti, per cui sta funzionando.

### Per cui cosa è un'unit?

Ogni funzione/metodo è tecnicamente un'unità, ma non dobbiamo comunque testare ognuno di loro. Invece, dobbiamo focalizzarci sul test delle funzioni e metodi che sono pubblicamente esposti da un modulo/package.

Nel nostro caso, questi erano i metodi execute. Non ci aspettiamo di chiamare il modello Article direttamente dall'API Flask, per cui non ci focalizziamo molto sul suo test. Per essere più precisi, nel nostro caso, le "unità" che devono essere testato sono i metodi execute dai comandi e dalle query. Se alcuni metodi non devono essere chiamati direttamente da altre parti del software o da un utilizzatore finale, siamo di fronte a dettagli implementativi, probabilmente. Di conseguenza, i nostri test sono resistenti al refacotring per i dettagli implementativi, che è una delle qualità dei buoni test.

Ad esempio, i nostri test passano se wrappiamo la logica per `get_by_id` e `get_by_title` in un metodo protetto chiamato _get_by_attribute:

```py
# other code ...

class Article(BaseModel):
    id: str = Field(default_factory=lambda: str(uuid.uuid4()))
    author: EmailStr
    title: str
    content: str

    @classmethod
    def get_by_id(cls, article_id: str):
        return cls._get_by_attribute("SELECT * FROM articles WHERE id=?", (article_id,))

    @classmethod
    def get_by_title(cls, title: str):
        return cls._get_by_attribute("SELECT * FROM articles WHERE title = ?", (title,))

    @classmethod
    def _get_by_attribute(cls, sql_query: str, sql_query_values: tuple):
        con = sqlite3.connect(os.getenv("DATABASE_NAME", "database.db"))
        con.row_factory = sqlite3.Row

        cur = con.cursor()
        cur.execute(sql_query, sql_query_values)

        record = cur.fetchone()

        if record is None:
            raise NotFound

        article = cls(**record)  # Row can be unpacked as dict
        con.close()

        return article

# other code ..
```

D'altro lato, se facciamo un breaking change all'interno di Article i test falliranno. E questo è esattamente quello che vogliamo. In questa situazione, possiamo sia invertire il breaking change, o adattarlo all'interno del nostro comando o query-

PErché c'è una cosa per la quale stiamo STRIVING FOR: i test che passano significa che il nostro software funziona.

## Quando usare i mocks?

Non abbiamo usato dei mocks nei nostri test, perché non ne abbiamo avuto bisogno. I metodi di mocking o le classi all'interno dei moduli o package producono dei test che non sono resistenti al refactoring perché sono accoppiati ai dettagli implementativi. Questi test si "rompono" spesso e sono costosi da manuentere. D'altro canto, ha senso effettuare il mock di risorse esterne quando la velicità è un problema (chiamata ad API eterne, invio di email, processi asincroni lunghi, etc.).

Per esempio, possiamo testare il modello Article separatamente, ed effettuarne il mock all'interno dei nostri test per CreateArticleCommand come segue:

```py
def test_create_article(monkeypatch):
    """
    GIVEN CreateArticleCommand with valid properties author, title and content
    WHEN the execute method is called
    THEN a new Article must exist in the database with same attributes
    """
    article = Article(
        author="john@doe.com",
        title="New Article",
        content="Super awesome article"
    )
    monkeypatch.setattr(
        Article,
        "save",
        lambda self: article
    )
    cmd = CreateArticleCommand(
        author="john@doe.com",
        title="New Article",
        content="Super awesome article"
    )

    db_article = cmd.execute()

    assert db_article.id == article.id
    assert db_article.author == article.author
    assert db_article.title == article.title
    assert db_article.content == article.content
```

Sì, questo è perfettamente ok da fare, ma adesso abbiamo più test da manutenere -- ovvero, tutti i test di prima più tutti i nuovi test per i metodi in Article. Oltre questo, l'unica cosa che è adesso testata da test_create_article è che un articlo restituito dal metodo save è lo stesso di quelli restituiti da exeute. Quando rompiamo qualcosa all'interno di Article questo test passerà comunque perché ne abbiamo fatto il mocking. E questo è qualcosa che vogliamo evitare: vogliamo testare il comportamento del software per assicurarci che funzionasse come atteso. In questo caso, il comportamento è rotto ma i nostri test non lo mostreranno.

## Pensieri finali

Non c'è un singolo modo giusto per testare il nostro software. Inoltre, è più facile testare la logica quando non è accoppiata con il nostro database. Possiamo in tal senso usare il pattern Active Record with command adn queries (CQRS) per aiutarci in tal senso.

E' opportuno focalizzarci sul valore di business del nostro codice.

Non testiamo i metodi giusto per dire che sono stati testati. Abbiamo bisogno di software funzionale, non meotdi testati. Il TDD è semplicemente un tool per dare software migliore più velocemente ed in maniera più affidabile. Lo stesso si può dire per la copertura del codice: proviamo a mantenerla alta, ma non dobbiamo necessariamente aggiungere test semplicemente per averla al 100%.

Un test ha valore soltanto quando ci protegge dalla regressione, ci permette il refacoring ,e ci offre un feedback rapido. Quindi, dovremmo fare in modo che i test assomiglino ad una forma piramidale (50% unit, 30% integraiton, 20% e2e). Questo anche se in applicazioni semplici può sembrare più una casa (40 unit, 40 integration, 20 e2e), il che va comunque bene.

Più rapidamente notiamo la regressione, più velocemente possiamo intercettarla e correggerla. Più velocemente la correggiamo, più breve è il ciclo di sviluppo. Per avere feedback più rapidi, possiamo usare i marker di pytest per escludere e2e ed altri test lenti durante lo sviluppo. Possiaom eseguirli meno frequentemente.

Usiamo i mock solo quanod necessario, come per le API di terze parit. Questi rendono il setup dei nostri test più complicati ed i test meno resistenti al refactoring. Inoltre, possono risultare in falsi positivi.

Di nuvoo, i test sono una vulnerabilitùà e non un asset: dovremmo coprire il comportamento del software, ma non crearne un numero eccessivo.

### Conclusione

C'è molto da digerire qui. Teniamo a mente che questi sono solo esempi usati per mostrare le idee. Possiamo usare le stesse idee con il Domain-driven design (DDD), il Behavior-Driven design (BDD), e molti altri approcci. Teniamo a mente che i test dovrebbero essere trattati come altro codice: sono una vulnerabilità, e non una risorsa. Scriviamo i test per proteggere i software dai bug, ma non permettiamo loro di bruciare il nostro tempo.
