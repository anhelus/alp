# 02 - Test del codice Python

Il test automatico del codice è sempre stato un topic centrale nello sviluppo del software, ed ha raggiunto una sempre maggior centralità con l'arrivo di paradigmi come la *CI/CD*. In tal senso, il linguaggio Python consta di numerosi strumenti che possono aiutarci a scrivere ed eseguire test di tutti i tipi; in questo articolo, ne vedremo alcuni tra i più conosciuti ed utilizzati.

## 02.1 - pytest

Di suo, la libreria standard Python integra un framework di unit test chiamato [`unittest`](https://docs.python.org/3/library/unittest.html); tuttavia, lo standard *de facto* è la libreria [`pytest`](https://pytest.org/), che ha cinque punti di forza:

1. **minor quantità di codice boilerplate**, rendendo quindi le librerie meno "verbose" e, complessivamente, più leggibili;
2. **supporto all'istruzione `assert`**, che risulta essere molto più leggibile e facile da utilizzare se comparata a metodi come `assertEquals`, `assertTrue` o `assertContains` contenuti in `unittest`;
3. **aggiornamento costante**, dal momento che è una libreria open source a sé stante, mentre `unittest` è parte integrante di Python;
4. **semplificazione del setup e del teardown** dei casi di test con il sistema di *fixture*;
5. **uso di un approccio orientato alla programmazione funzionale**.

`pytest` ci permette inoltre di avere uno stile di testing *coerente* tra i nostri diversi progetti Python. Immaginiamo, ad esempio, di avere due web app nel nostro stack, una creata mediante Django, e l'altra mediante Flask. Senza `pytest`, probabilmente, dovremo utilizzare il framework interno di Djano per l'unit testing per la prima, ed un'estensione Flask apposita, come Flask-Testing, per la seconda: di conseguenza, le due test suite avranno stili differenti. Usando `pytest`, invece, entrambe le test suite avranno uno stile *consistente*, rendendo semplice il saltare dall'una all'altra.

`pytest` offre anche un ecosistema di plugin molto esteso ed interamente mantenuto dalla community. Ad esempio, esiste il plugin [`pytest-django`](https://pytest-django.readthedocs.io/), che fornisce strumenti specificamente pensati per il test di web app Django, oppure anche [`pytest-cov`](https://pytest-cov.readthedocs.io/), utile ad integrare il supporto al code coverage.

## mocking

I test automatizzati devono essere veloci, isolati, indipendenti, deterministici e ripetiovili. Quindi, se dobbiamo testare del codice che fa una chiamata HTTP esterna ad una API di terze parti, dobbiamo effettuare il mocking della richiesta. QPErché? se non lo facciamo, i test specifici saranno:

1. lenti perché stanno facendo delle richieste HTTP nella rete
2. dipendono dal servizio di terze parti e dalla velocità della rete stessa
3. non sono deterministici dal momento che il test puòd are un risultato differnete basato sula risposta dalla API

!!!tip
    E' una buona idea anche effettuare il mocking di altre operazioni lunghe, come query al database e task asinmcrone, dal momento che i test automatizzati sono generalmente eseguiti frequente,ente, su ogni commit pushata al source control.

Il mocking è la pratica di rimpiazzare oggetti reali con oggetti simulati che mimano il loro comportamento a runtime. Per cui, invece da mandare una vera richiesta HTTP sula rete, ci limitiamo a restituire le risposte attes equando il metodo simulato viene chiamato.

Ad esempio:

```py
import requests

def get_my_ip():
    response = requests.get(
        'http://ipinfo.io/json'
    )
    return response.json()['ip']


def test_get_my_ip(monkeypatch):
    my_ip = '123.123.123.123'

    class MockResponse:

        def __init__(self, json_body):
            self.json_body = json_body

        def json(self):
            return self.json_body

    monkeypatch.setattr(
        requests,
        'get',
        lambda *args, **kwargs: MockResponse({'ip': my_ip})
    )

    assert get_my_ip() == my_ip
```

Cosa sta succedendo?

Usiamo la fixture [monkeypatch](https://docs.pytest.org/en/stable/monkeypatch.html) per rimpiazare tutte le chiamate al metodo `get` dal modulo `requests` con il callback lambda che restituisce sempre un'istanza di `MockedResponse`.

!!!note
    Usiamo un oggetto perché `requests` restituisce un oggetto Response.

Possiamo semplificare il test con il metodo create_autospec dal modulo unittest.mock. Questo metodo crea un oggetto mockato con le stesse proprietà e metodi dell'oggetto passato come parametro:

```py
from unittest import mock

import requests
from requests import Response


def get_my_ip():
    response = requests.get(
        'http://ipinfo.io/json'
    )
    return response.json()['ip']


def test_get_my_ip(monkeypatch):
    my_ip = '123.123.123.123'
    response = mock.create_autospec(Response)
    response.json.return_value = {'ip': my_ip}

    monkeypatch.setattr(
        requests,
        'get',
        lambda *args, **kwargs: response
    )

    assert get_my_ip() == my_ip
```

Anche se pytest raccomanda l'approccio monkeypatch per il mocking, l'estensieone pytest-mock e la libreria unittest.mock dalla libreria standard sono approcci ottimi entrmabi.

### code coveratge

un altro aspetto importante del test è il code coverage. è una metrica che ci indica che il rapproto tra il numero di linee eseguiti duranti il test esegue ed il numero totale di righe nella nostra codebase. Possiamo usare il plugin pyutest-cov per questo, che integra Coverage.py con pytest.

Una volta installata, per eseguire i test con il report del coverage aggiungiamo l'opzione --cov:

```sh
$ python -m pytest --cov=.
```

Produrrà un output del genere:

```sh
================================== test session starts ==================================
platform linux -- Python 3.7.9, pytest-5.4.3, py-1.9.0, pluggy-0.13.1
rootdir: /home/johndoe/sample-project
plugins: cov-2.10.1
collected 6 items

tests/test_sample_project.py ....                                             [ 66%]
tests/test_sample_project_mock.py .                                           [ 83%]
tests/test_sample_project_mock_1.py .                                         [100%]

----------- coverage: platform linux, python 3.7.9-final-0 -----------
Name                                  Stmts   Miss  Cover
---------------------------------------------------------
sample_project/__init__.py                1      1     0%
tests/__init__.py                         0      0   100%
tests/test_sample_project.py              5      0   100%
tests/test_sample_project_mock.py        13      0   100%
tests/test_sample_project_mock_1.py      12      0   100%
---------------------------------------------------------
TOTAL                                    31      1    97%


==================================  6 passed in 0.13s ==================================
```

Per ogni file nel percorso del progetto otteniamo:

* Stmts: numero di righe di codice
* Miss: numero di righe che non sono state eseguitre dai test
* cover: percentuale di copertura per il file

Alla fine, vi è una linea con i totali per l'intero progetto.

Teniamo a mente che anche se è bene ottenere una percentuale di copertura alta, questo non significa che i nostri test siano buoni, e che testino tutti percorsi che possono essere seguiti dal codice. Per esempio, i test con assert sum(3, 2) == 5 può avere un'alta percentuale di copertura, ma il codice non è testato, dal momento che i percorsi delle eccezioni non sono coperte.

## mutation testging

Il mutation testing ci aiuta ad assicurarci che i nostri test coprano effettivamente l'intero comportamento del nostro codice. Messo in un altro modo, analizziamo l'efficacia o robustezza della nostra test suite. Durante il mutation testing, un tool itera attraverso ogni riga del nostro codice sorgente, facendom dei piccoli cambi (chiamati mutazioni) che potrebbero rompere il nostro codice. Dopo ogni mutazione, il tool esegue gli unit test e verifica se il nostro test fallisce o meno. Se i nostri test passano, allora il codice non è riuscito a passare il mutation test.

Ad esempio, imamginiamo di avere il seguente codice:

```py
if x > y:
    z = 50
else:
    z = 100
```

Il mutation tool può cambiare l'operatore da > a >=:

```py
if x>= y:
    z = 50
else:
    z = 100
```

mutmut è una libreria di mutation testing per Python. Vediamola in azione.

Immaginiamo di avere la seguente classe Prestiti:

```py
# loan.py

from dataclasses import dataclass
from enum import Enum


class LoanStatus(str, Enum):
    PENDING = "PENDING"
    ACCEPTED = "ACCEPTED"
    REJECTED = "REJECTED"


@dataclass
class Loan:
    amount: float
    status: LoanStatus = LoanStatus.PENDING

    def reject(self):
        self.status = LoanStatus.REJECTED

    def rejected(self):
        return self.status == LoanStatus.REJECTED
```

Ora diciamo che vogliamo automaticamente respingere le richieste di mutuo che sono superiori a 250k:

```py
# reject_loan.py

def reject_loan(loan):
    if loan.amount > 250.000:
        loan.reject()
    
    return loan
```

Scriviamo quindi il seguente test:

```py
from loan import loan
from reject_loan import reject_loan

def test_reject_loan():
    loan = loan(amount=100_000)

    assert not reject_loan(loan).rejected() 
```

Quando eseguiamo il mutation testing con mutmut, vedremo che avremo due mutazioni che sopravvivono:

```sh
$ mutmut run --paths-to-mutate reject_loan.py --tests-dir=.

- Mutation testing starting -

These are the steps:
1. A full test suite run will be made to make sure we
   can run the tests successfully and we know how long
   it takes (to detect infinite loops for example)
2. Mutants will be generated and checked

Results are stored in .mutmut-cache.
Print found mutants with `mutmut results`.

Legend for output:
🎉 Killed mutants.   The goal is for everything to end up in this bucket.
⏰ Timeout.          Test suite took 10 times as long as the baseline so were killed.
🤔 Suspicious.       Tests took a long time, but not long enough to be fatal.
🙁 Survived.         This means your tests needs to be expanded.
🔇 Skipped.          Skipped.

1. Running tests without mutations
⠏ Running...Done

2. Checking mutants
⠸ 2/2  🎉 0  ⏰ 0  🤔 0  🙁 2  🔇 0
```

Possiamo vedere le mutazioni che sopravvivono in base al loro ID:

```sh
$ mutmut show 1

--- reject_loan.py
+++ reject_loan.py
@@ -1,7 +1,7 @@
 # reject_loan.py

 def reject_loan(loan):
-    if loan.amount > 250_000:
+    if loan.amount >= 250_000:
         loan.reject()

     return loan
```

$ mutmut show 2

--- reject_loan.py
+++ reject_loan.py
@@ -1,7 +1,7 @@
 # reject_loan.py

 def reject_loan(loan):
-    if loan.amount > 250_000:
+    if loan.amount > 250001:
         loan.reject()

     return loan
    

Miglioriamo il nostro testO:

from loan import Loan
from reject_loan import reject_loan


def test_reject_loan():
    loan = Loan(amount=100_000)
    assert not reject_loan(loan).rejected()

    loan = Loan(amount=250_001)
    assert reject_loan(loan).rejected()

    loan = Loan(amount=250_000)
    assert not reject_loan(loan).rejected()


Se facciamo di nuovo il nsotro mutation test, vedremo che nessuna mutazione è sopravvissuta:

$ mutmut run --paths-to-mutate reject_loan.py --tests-dir=.

- Mutation testing starting -

These are the steps:
1. A full test suite run will be made to make sure we
   can run the tests successfully and we know how long
   it takes (to detect infinite loops for example)
2. Mutants will be generated and checked

Results are stored in .mutmut-cache.
Print found mutants with `mutmut results`.

Legend for output:
🎉 Killed mutants.   The goal is for everything to end up in this bucket.
⏰ Timeout.          Test suite took 10 times as long as the baseline so were killed.
🤔 Suspicious.       Tests took a long time, but not long enough to be fatal.
🙁 Survived.         This means your tests needs to be expanded.
🔇 Skipped.          Skipped.

1. Running tests without mutations
⠏ Running...Done

2. Checking mutants
⠙ 2/2  🎉 2  ⏰ 0  🤔 0  🙁 0  🔇 0


Adesso i nostri test sono molto più robusti. Un qualsiasi cambio non intenzionale all'intenro di `reject_loan.py` produrrà un test che fallisce.

!!!tip
    I tool di mutation testing per Python non sono maturi come quelli per altri linguaggi.POer esempoi, mtuatn è un mutation testing maturo per Ruby.

Così come per ogni altro approccio, il mutationt esting ha un tradeoff. Mentre miglirloa la abilità della nostra test suite di catturare dei bug, ha il costo di velocità dal momento che dobbiamo eseguire l'intera test suitee centinaia di volte. Ci forza inotlre a testare davvero tutto. QUesto ci aiuta a scoprire dei path di eccezioni, ma avremo molti test case minori da mantenere.

## TODO: DA HYPOTHESIS

[Hypotheisi](https://hypothesis.readthedocs.io/en/latest/) è una libreria per effettuare il property-based testing in Python. In pratica, pitutosto che scrivere differenti test case per ogni argomento da testare, il property-based testing genera un ampio range di dati di test casuali che sono dipendenti dalle precedenti run. Questo ci aiuta ad aumentare la robustezza della della nostra test suite e diminuire la ridondanza dei test. In breve, il codice di test sarà più pulito, più DRY, e più efficiente, mentre comunque copre un ampio range di dati di test.

Per esempio, diciamo di dover scrivere dei test per la seguente funzione:

```py
def increment(num: int) -> int:
    return num + 1
```

Possiamo scrivere i seguenti test:

```py
import pytest

@pytest.mark.parametrize(
    'number, result',
    [
        (-2, -1),
        (0, 1),
        (3, 4),
        (101234, 101235)
    ]
)

def test_increment(number, result):
    assert increment(number) == result
```

Non vi è niente di sbagliato in questo approccio. Il codice è testato e la copertura è alta (100%, per essere satti). Detto questo, quanto bene è stato testato il codice rispetto al range dei possibili input? Vi sono molti interi che possono essere testati, ma solo quattro di loro sono usati nel test. In alcune situazioni questo è abbastanza. In altre situazioni quattro casi non sono abbastanza, ad esempio, nel codice machine learning (che non è detrerministico). COsa diciamo per dei numeri molto piccoli o grandi? o se la nostra funzione prende una lista di interi piuttosto che un singolo intero. E se la lista è vuota o contiene un elemnto, centtinaia di elementi, o migliaia di elemneti? In alcune situaizoni non possiamo semplicemente fornire (o anche pensare) tutti i possibili casi. E' qui che il test propertty-based viene in gioco.

!!!note
    Gli algoritmi di machine learning sono un use case ottimo per il property-based testing dal momento in cui è dificile produrre (e mantenere)) i campioni di test per insiemi di dati complessi.

I frmaework come hypothesis fornisce le ricette (chiamate [Strategies](https://hypothesis.readthedocs.io/en/latest/data.html?#core-strategies)) per generare dati di test casuali. Hypothesis memorizza anche i risultati delle precedenti run di test e le use per creare nuovi casi.

!!!note
    Le strategie sono algoritmi che generano dati pseudo-casuali basate sulla forma dei dati input. E' pseudo-causuale perché i dati generati sono basati sui dati dai test precedenti.

Lo stesso test che usa il property-based testing mediante Hypothesis appare come segue:

```py
from hypothesis import given
import hypothesis.strategies as st

@given(st.integers())
def test_add_one(num):
    assert increment(num) == num - 1
```

`st.integers()` è una strategia Hypothesis che genbera deglki interti casuali per il test mentre il decorator `@given` è usato per parametrizzare la funzione di test. Per cui quando la funzione di test è chiamato, gli interi generati, dalla strategiua, saranno passati nei test.

```sh
$ python -m pytest test_hypothesis.py --hypothesis-show-statistics

================================== test session starts ===================================
platform darwin -- Python 3.8.5, pytest-6.1.1, py-1.9.0, pluggy-0.13.1
rootdir: /home/johndoe/sample-project
plugins: hypothesis-5.37.3
collected 1 item

test_hypothesis.py .                                                               [100%]
================================= Hypothesis Statistics ==================================

test_hypothesis.py::test_add_one:

  - during generate phase (0.06 seconds):
    - Typical runtimes: < 1ms, ~ 50% in data generation
    - 100 passing examples, 0 failing examples, 0 invalid examples

  - Stopped because settings.max_examples=100


=================================== 1 passed in 0.08s ====================================
```

## type checking

I test sono codice, e devono esere trrattati di conseguenza. Come il codice di business, dobbiamo mantenerli e fare il refactoring. Possiamo dover affrontare i bug di volta in volta. A causa di questo, è una buona pratica mantenere i test corti, semplici, e dritti al punto. Dovremmo anche occuparci di non effettuare troppi test sul codice.

I type checker a runtime, o dinamici, come [Typeguard](https://typeguard.readthedocs.io/) e [pydantic](https://pydantic-docs.helpmanual.io/), possono aituare a minimizzare il numero di test. Vediamo ad un esempio di questo con pydantic.

Per esempio, diciamo di avere un `User` che ha un singolo attributo, un indirizzo email:

```py
class User:

    def __init__(self, email: str):
        self.email = email


user = User(email='john@doe.com')
```

Vogliamo assicuraci che la mail fornita sia un indirizzo effettivamente valido. PEr cui, per validarlo, dovremo aggiungere da qualche parte del codice helper. Assieme alla scrittura di test, dovremo anche spendere del tempo per scrivere le espressioni regolari per questo. pydantic può aiutarci. Possiamo usarlo per derinife ril nostro modello User:

```py
from pydantic import BaseModel, EmailStr


class User(BaseModel):
    email: EmailStr


user = User(email='john@doe.com')
```

Ora, l'argomento email sarà validato da pydantic prima che ogni istanza di User sia creata. Quando non è una mail valida (ad esempio, User(email='something')) un ValidationError sarà lanciato. Qeusto elimina la necessità dis crivere il nostro validatore. Non dobbiamo neanche testarlo perché i mantainer di pydantic lo fanno per noi.

Possiamo ridure il numero di test per ogni dato fornito dall'utente. E, invece, dobbiamo semplciemente testare che un ValidationError sia gestito correttamente.

Vediamo un rapido esempio in un'app Flask:

```py
import uuid

from flask import Flask, jsonify
from pydantic import ValidationError, BaseModel, EmailStr, Field


app = Flask(__name__)


@app.errorhandler(ValidationError)
def handle_validation_exception(error):
    response = jsonify(error.errors())
    response.status_code = 400
    return response


class Blog(BaseModel):
    id: str = Field(default_factory=lambda: str(uuid.uuid4()))
    author: EmailStr
    title: str
    content: str
```

Il test diventa:

```py
import json


def test_create_blog_bad_request(client):
    """
    GIVEN request data with invalid values or missing attributes
    WHEN endpoint /create-blog/ is called
    THEN it should return status 400 and JSON body
    """
    response = client.post(
        '/create-blog/',
        data=json.dumps(
            {
            'author': 'John Doe',
            'title': None,
            'content': 'Some extra awesome content'
        }
        ),
        content_type='application/json',
    )

    assert response.status_code == 400
    assert response.json is not None
```

## Conclusioni

Il test può essere alle volte un compito scooraggiante. Ci sono sempre delle volte in cui lo sarà, ma abbiamo visto delle tecniche e deglis trumenti che possiamo usare per rendere ilt est più semplice. Focalizziamo gli sforzi di testing sul diminuire i test inutili. I nostri test dovrebbero anche essere veloci, isolati, indipendenti, deterministici e ripetibili. Alla fine, avere confidenza nella nostra suite di test ci aiuterà ad efettuare il deploy in produzione più spesso e dormire sogni tranquilli.
