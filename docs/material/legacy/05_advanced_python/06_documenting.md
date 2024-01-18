# Documentazione

Perché dobbiamo documentare il nostro codice Python? Che cosa dovrebbe includere la documentazione? Come scriviamo e generiamo la comunicazione?

La documentazione è una parte importante dello sviluppo software. Senza propria documentazione, può essere molto difficile o impossibile per stakeholder interni ed esterni che usano e/o mantengono il nostro codice. Rende anche molto più complesso avere altri sviluppatori. Facendo un passo in avanti, senza una cultura di documentare ed apprendere in generale, spesso faremo gli stessi errori molte volte. Sfortunatamente, diversi sviluppatori trattano la documentazione successivamente - qualcosa da non prendere troppo in considerazione.

Questo articola affronta il perché dovremmo documentare il nostro codice Python, e come farlo.

## Cosa è la documentazione?

La documentazione è una risorsa standalone che aiuta gli altri ad usare il nostro API, package, libreria o framework senza dover leggere ilcodice sorgente. I commenti, d'altra parte, sono per gli sviluppatori che leggono il nostro codice sorgente. La documentaione è qualcosa ch dovremmo sempre tenere presente, ma lo stesso non può essere detto per i commenti. Infatti, questi sono buoni da avere, ma non sono strettamente richiesti. La documentazione dovrebbe dire ad altri quando e come usare qualcosa, mentre i commenti dovrebbero rispondere a domande del tipo:

* perché è stato fatto in questo modo?
* perché questa parte di codice è qui?

La questione "cosa" dovrebbe essere teoricamente risposta dal codice:

* cosa è questo?
* che fa questo metodo?

Riassumendo:

| Tipo | Risposta | Attore |
| ---- | -------- | ------ |
| Documentazione | QUando e Come | Utenti |
| Commenti al codice | Perchè | Sviluppatori |
| Codice | Cosa | Sviluppatori |

## Docstring

Come specificato dalla PEP-257, una stringa di documentazione Python (o docstring) è una stringa speciale che avviene come prima istruzione in un modulo, funzione, classe, o definizione di metodo, per formare l'attributo __doc__ del dato oggetto. Ci permette di integrare la documentazione direttamente nel nostro codice sorgente.

Immaginiamo per esempio di avere un modulo chiamato `temperature.py` con una singola funzione che calcola la temperatura media giornaliera. Usando i docstring, possiamo documentarla come segue:

```py
"""
The temperature module: Manipulate your temperature easily

Easily calculate daily average temperature
"""

from typing import List


class HighTemperature:
    """Class representing very high temperatures"""

    def __init__(self, value: float):
        """
        :param value: value of temperature
        """

        self.value = value


def daily_average(temperatures: List[float]) -> float:
    """
    Get average daily temperature

    Calculate average temperature from multiple measurements

    :param temperatures: list of temperatures
    :return: average temperature
    """

    return sum(temperatures)/len(temperatures)
```

Possiamo vedere le docstring specificate per la funzione `daily_average` accedendo al suo attributo `__doc__`:

```py
>>> from temperature import daily_average
>>>
>>> print(daily_average.__doc__)

    Get average daily temperature

    :param temperatures: list of temperatures
    :return: average temperature
```

Possiamo anche vedere la docstring a livello dell'intero modulo usando la funzione di help integrata:

```py
>>> import temperature
>>>
>>> help(temperature)
```

E' il caso di notare che possiamo usare la funzione help con keywords integrate (`int`, `float`, `def`, e così via), classi, funzioni, e moduli.

## Singola vs. multi-line

Le docstring possono essere a singola linea o a più linee. In ogni modo, la prima linea è sempre trattata come sommario. La riga di sommario può essere usata dai tool di indicizzazione automatica per cui è importante che entri in un'unica rioga. Quando si usa la docstring a riga singola, tutto dovrebbe essere sulla stessa riga: virgolette di apertura, sommario, e virgolette di chiusura. Ad esempio:

```py
class HighTemperature:
    """Class representing very high temperatures"""

    # code starts here
```

Quando si usa una docstring multilinea, la struttura è la seguente: virgolette di apertura, riga vuota, descrizione più elabroata, e virgolette di chiusura.

```py
def daily_average(temperatures: List[float]) -> float:
    """
    Get average daily temperature

    Calculate average temperature from multiple measurements

    :param temperatures: list of temperatures
    :return: average temperature
    """

    return sum(temperatures) / len(temperatures)
```

Oltre a descrivere quello che una certa funzione, classe o metodo fa, possiamo anche specificare:

* argomenti di funzione
* valori di ritorno di funzione
* attributi di classe
* errori lanciati
* limitazioni
* esempin di codice

## Formati

I quattro tipi di formato più comune sono:

* Google
* reStructuredText
* NumPy
* Epytext

Il consiglio è quello di scegliere quello che più si adatta a noi ed essere consistenti lungo l'arco dell'intero progetto.

Usando le docstring possiamo esprimere i nostri intenti in maniera esplicita in linguaggio parlato per aiutare gli altri (e i noi stgessi del futuro) a capire al meglio quando, dove e come usare una determinata parte del codice.

## Linting

Possiamoe ffettuare il lint delle nostre docstring proprio come faremmo per il codice. I linters si assicurano che le nostre docstring siano ben formattate e che rispettino l'implementazione vera e propria, il che aiuta nella stesura dell anostra documentazione.

Darglint è un linter per la documentazione abbastanza popolare.

```py
$ pip install darglint
```

Proviamo ad effettuare il lint del modulo `temperature.py`.

```py
def daily_average(temperatures: List[float]) -> float:
    """
    Get average daily temperature

    Calculate average temperature from multiple measurements

    :param temperatures: list of temperatures
    :return: average temperature
    """

    return sum(temperatures) / len(temperatures)
```

Per fare il lint:

```sh
$ darglint --docstring-style sphinx temperature.py
```

Cosa accade se cambiamo il nome del parametro da `temperatures` a `temperatures_list`?

```sh
$ darglint --docstring-style sphinx temperature.py

temperature.py:daily_average:27: DAR102: + temperatures
temperature.py:daily_average:27: DAR101: - temperatures_list
```

### Esempi di codice

Possiamo anche aggiungere degli esempi di codice alle docstring, mostrando usi di esempiop della funzione, metodo o classe. Ad esempio:

```py
def daily_average(temperatures: List[float], new_param=None) -> float:
    """
    Get average daily temperature

    Calculate average temperature from multiple measurements

    >>> daily_average([10.0, 12.0, 14.0])
    12.0

    :param temperatures: list of temperatures
    :return: Average temperature
    """

    return sum(temperatures)/len(temperatures)
```

Gli esempi di codice possono anche essere eseguiti da pytest come ogni altro test mediante `doctest`. Assieme al linting, questo ci aiuta ad assicurarci che la nostra documentazione sia sempre sincronizzata al codice.

Per cui, con l'esempio precedente, pytest controllerà che `daily_average([10.0, 12.0, 14.0])` sia uguale a `12.0`. Per eseguire questo campione di codice come test abbiamo bisogno di eseguire pytest con l'opzione `doctest-modules`:

```sh
$ python -m pytest --doctest-modules temperature.py

==================================================== test session starts =====================================================
platform darwin -- Python 3.9.0, pytest-6.1.2, py-1.9.0, pluggy-0.13.1
rootdir: /Users/michael/repos/testdriven/python_developer_2020/docs
collected 1 item

temperature.py .                                                                                                       [100%]

===================================================== 1 passed in 0.01s ======================================================
What happens if you change the code example to:

>>> daily_average([10.0, 12.0, 14.0])
13.0
$ python -m pytest --doctest-modules temperature.py

==================================================== test session starts =====================================================
platform darwin -- Python 3.9.0, pytest-6.1.2, py-1.9.0, pluggy-0.13.1
rootdir: /Users/michael/repos/testdriven/python_developer_2020/docs
collected 1 item

temperature.py F                                                                                                       [100%]

========================================================== FAILURES ==========================================================
____________________________________________ [doctest] temperature.daily_average _____________________________________________
020
021     Get average daily temperature
022
023     Calculate average temperature from multiple measurements
024
025     >>> daily_average([10.0, 12.0, 14.0])
Expected:
    13.0
Got:
    12.0

/Users/michael/repos/testdriven/python_developer_2020/docs/temperature.py:25: DocTestFailure
================================================== short test summary info ===================================================
FAILED temperature.py::temperature.daily_average
===================================================== 1 failed in 0.02s =====================================================
```

## Sphinx

Aggiungere le docstring al nostro codice è ottimo, ma dobbiamo comunque mostrarle in qualche modo ai nostri utenti.

Qui è dove tool come Sphinx, Epydoc e MKDocs entrano in gioco, che converftiranno le docstring del nostro progetto in HTML e CSS.

Sphinx è di gran lunga il tool più popolare. Viene usatop per generare la documentazione per un gran numero di progetti open-source come Python e Flask. E' anche uno dei tool di documentazione supportati da Read the Docs, che è usato da migliaia di progetti open-source, come Requests, Flask8, e pytest, per nominarne alcuni.

Vediamolo in azione. Iniziamo seguendo la guida ufficiale per scaricare ed installare Sphinx.

```sh
$ sphinx-quickstart --version

sphinx-quickstart 3.3.1
```

Creiamo la cartello per un nuovo progetto:

```sh
$ mkdir sphinx_example
$ cd sphinx_example
```

A questo pèunto, aggiungiamo nuvo file chiamato `temperature.py`:

```py
"""
The temperature module: Manipulate your temperature easily

Easily calculate daily average temperature
"""

from typing import List


class HighTemperature:
    """Class representing very high temperatures"""

    def __init__(self, value: float):
        """
        :param value: value of temperature
        """

        self.value = value


def daily_average(temperatures: List[float]) -> float:
    """
    Get average daily temperature

    :param temperatures: list of temperatures
    :return: average temperature
    """

    return sum(temperatures)/len(temperatures)
```

Per effettuare lo scaffolding dei file e delel cartelle per Sphinx per creare la documentazione per `temperature.py`, all'interno della radice di progetto, eseguiamo:

```sh
$ sphinx-quickstart docs
```

Ci verranno fatte alcune domande:

```sh
> Separate source and build directories (y/n) [n]: n
> Project name: Temperature
> Author name(s): Your Name
> Project release []: 1.0.0
> Project language [en]: en
```

Una volta fatto, la cartella *docs* conterrà i seguenti file e cartelle:

```
docs
├── Makefile
├── _build
├── _static
├── _templates
├── conf.py
├── index.rst
└── make.bat
```

Quindi, aggiungiamo la configurazione di progetto. Apriamo `docs/conf.py` e rimpiazziamo queste righe:

```py
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))
```

con queste:

```py
import os
import sys
sys.path.insert(0, os.path.abspath('..'))
```

Adesso, autodoc, che è usato per creare la documentazione dalle docstring, cercherà i moduli nella cartella padre di *docs*.

Aggiungiamo le seguenti estensioni alla lista di estensioni:

```
extensions = [
    'sphinx.ext.autodoc',
]
```

Apriamo `docs/index.rst` e modifichiamolo come segue:

```
Welcome to Temperature documentation!
=====================================

.. automodule:: temperature
    :members:



Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
```

I contenuti di `index.rst` sono scritti in reStructuredText, che è un fomrato di file per dati testuali simile a Markdown, ma molto più potente perché progettato per scrivere la documentaizone tecnica.

Note:

* i titoli sono creati sottolineando (ed opzionalmente OVERLINING) il titolo con un carattere `=`, almeno lunga come il testo

La direttiva automodule è usata per raccogliere le docstring dai moduli Python. Di conseguenza, `automodule:: temperature` dice a Sphinx di raccogliere le docstring dal modulo `temperature.py`.

Le direttive genindex, modindex e search sono usate per generare un indice generico, un indice di moduli documentati, ed una pagina di ricerca, rispettivamente.

Dalla cartella "docs", costruiamo la documentazione:

```sh
$ make html
```

Apriamo `docs/_build/html/index.html` nel nostro browser. Dovremmo vedere:

### Sphinx docs

Ora possiamo servire i docs noi stessi, usando un tool come Netlify, o mediante un servizio esterno come Read the Docs.

## Documentazione delle API

QUando parliamo della documentazione non dobbiamo dimenticarci della documentazione delle nostre API. Abbiamo degli endpoint con i loro URL, parametri, status code, corpi delle richieste e delle risposte. Anche una semplice API può avere un numero di parametri che sono difficili da ricordare.

Le specifiche OpenAPI (prima chiamate Swagger) forniscono un formato standard per descrivere, produrre, consumare e visualizzare le API RESTful. Questa specifica è usata per generarre la documentazione con Swagger UI o ReDoc. Può essere anche importata in tool come Postman. Possiamo generare diversi stub e client SDK così come dei tool come Swagger Codegen e OpenAPI Generator.

Per una lista completa di editor, linter, parser, generotri di codice, documetnazione, testing e tool di validazione schema/dati per OpenAPI, vediamo i tool di OpenAPI.

Le specifiche stesse devono essere scritte in YAML o JSON. Ad esempio:

```yaml
---
openapi: 3.0.2
info:
  title: Swagger Petstore - OpenAPI 3.0
  description: |-
    This is a sample Open API
  version: 1.0.0
servers:
- url: "/api/v3"
paths:
  "/pet":
    post:
      summary: Add a new pet to the store
      description: Add a new pet to the store
      operationId: addPet
      requestBody:
        description: Create a new pet in the store
        content:
          application/json:
            schema:
              "$ref": "#/components/schemas/Pet"
        required: true
      responses:
        '200':
          description: Successful operation
          content:
            application/json:
              schema:
                "$ref": "#/components/schemas/Pet"
        '405':
          description: Invalid input
components:
  schemas:
    Pet:
      required:
      - name
      - photoUrls
      type: object
      properties:
        id:
          type: integer
          format: int64
          example: 10
        name:
          type: string
          example: doggie
        photoUrls:
          type: array
          items:
            type: string
        status:
          type: string
          description: pet status in the store
          enum:
          - available
          - pending
          - sold
  requestBodies:
    Pet:
      description: Pet object that needs to be added to the store
      content:
        application/json:
          schema:
            "$ref": "#/components/schemas/Pet"
```

Scrivere uno schema di questo tipo a mano è duro e soggetto ad errori. Fortunatamente, ci sono diversi tool che ci aiutano ad automatizzare queto processo:

* Django: drf-yasg
* Flask - Flask-RESTX, Connexion, Flask-Rebar
* FastAPI - OpenAPI integrato

## Test come documentazione

Finora, abbiamo parlato della documentrazione per gli utenti (documentazione del progetto) e sviluppatori (commenti del codice). Un altro tipo di documentazione per gli sviluppatori viene dai test stessi.

Come sviluppatore che lavora su un progetto dobbiamo sapere più di come usare un metodo. Dobbiamo sapere se funziona come atteso e come usarlo per ulteriori sviluppi. Anche se aggiungere degli esempi di codice alla docstring ci aiuta, questi non sono intesi per nient'altro che esempi. Dobbiamo aggiungere dei test per coprire più che il percorso atteso di una funzione.

I test documentano tre cose:

* quello che è l'output atteso di un dato input
* come i percorsi delle eccezioni sono gestiti
* come usare una data funzione, metodo o classe

Dato che stiamo scrivendo dei test, assicuriamoci di usare della nomenclatura propria e specificare chiaramente quello che stiamo testando. Qeusto ci rende molto più semplice effettaure la review della test suite per trovare una certa funzione o metodo da usare.

Inoltre, quando scriviamo un test, in pratica definiamo quello che dovrebbe andare nella docstring. La struttura GIVEN, WHEN, THEN può essere facilmente convertita nella docstring di una funzione.

Ad esempio:

* DATA una lista di misure di temperatura -> :param temperatures: list of temperatures
* QUANDO 'media_giornaliera' viene chiamata -> >>> daily_average([10.0, 12.0, 14.0])
* ALLORA la temperatura media viene restituita -> Get average temperature, :return: Average temperature

```py
def daily_average(temperatures: List[float]) -> float:
    """
    Get average temperature

    Calculate average temperature from multiple measurements

    >>> daily_average([10.0, 12.0, 14.0])
    12.0

    :param temperatures: list of temperatures
    :return: Average temperature
    """

    return sum(temperatures)/len(temperatures)
```

Quindi, possiamo trattare il TDD come una sorta di approccio "documentation-driven" allo sviluppo creando la nostra docstring sotto forma di codice:

* Scriviamo un test
* Ci assicuriamo che il test fallisca
* Scriviamo il codice
* Ci assicuriamo che il test passo
* effettuiamo il refacotring ed aggiuingiamo la docstring

## Documentare una API REST Flask

Finora, abbiamo semplicemente coperto la teoria, per cui andiamo su un esempio reale. Creeremo una API RESTful con Flask per la misurazione della temperatura. Ogni misura avrà i seguenti attributi: timestamp, temperatura, note. Flask-RESTX verrà usato per auto-generare una specifica OpenAPI.

Per prima cosa, creiamo una nuova cartella:

```sh
$ mkdir flask_temperature
$ cd flask_temperature
```

A questo punto, inizializziamo il progetto usando Poetry:

```sh
$ poetry init
Package name [flask_temperature]:
Version [0.1.0]:
Description []:
Author [Your name <your@email.com>, n to skip]:
License []:
Compatible Python versions [^3.7]:  >3.7

Would you like to define your main dependencies interactively? (yes/no) [yes] no
Would you like to define your development dependencies interactively? (yes/no) [yes] no
Do you confirm generation? (yes/no) [yes]
```

Aggiungiamo quindi Flask e Flask-RESTX:

```sh
$ poetry add flask flask-restx
```

Creiamo adesso la nostra API documentata. Aggiungiamo un file per l'app Flask chiamato `app.py`:

```py
import uuid

from flask import Flask, request
from flask_restx import Api, Resource

app = Flask(__name__)
api = Api(app)

measurements = []


@api.route('/measurements')
class Measurement(Resource):
    def get(self):
        return measurements

    def post(self):
        measurement = {
            'id': str(uuid.uuid4()),
            'timestamp': request.json['timestamp'],
            'temperature': request.json['temperature'],
            'notes': request.json.get('notes'),
        }
        measurements.append(measurement)

        return measurement


if __name__ == '__main__':
    app.run()
```

Flask-RESTX usa delle view class-based per organizzare le risorse, route e metodi HTTP. Nell'esempio precedente, la classe Measurement supporta i metodi HTTP GET e POST. Altri metori restiuiranno un errore `MethodNotAllowed`. Flask-RESTX genererà anche lo schema OpenAPI quando l'app viene eseguita.

```sh
$ python app.py
```

Possiamo vedere lo schema all'indirizzo http://localhost:5000/swagger.json. Saremo anche in grado di vedere l'API navigabile a http://localhost:5000.

## SwaggerUI

Al momento, lo schema contiene soltnato degli endpoint. POssiamo definire i corpi delle richieste e delle risposte per dire ai nostri utenti quello che è atteso da loro, così come quello che sarà restituito. Aggiorniamo `app.py`:

```py
import uuid

from flask import Flask, request
from flask_restx import Api, Resource, fields

app = Flask(__name__)
api = Api(app)

measurements = []

add_measurement_request_body = api.model(
    'AddMeasurementRequestBody', {
        'timestamp': fields.Integer(
            description='Timestamp of measurement',
            required=True,
            example=1606509272
        ),
        'temperature': fields.Float(
            description='Measured temperature',
            required=True, example=22.3),
        'notes': fields.String(
            description='Additional notes',
            required=False, example='Strange day'),
    }
)

measurement_model = api.model(
    'Measurement', {
        'id': fields.String(
            description='Unique ID',
            required=False,
            example='354e405c-136f-4e03-b5ce-5f92e3ed3ff8'
        ),
        'timestamp': fields.Integer(
            description='Timestamp of measurement',
            required=True,
            example=1606509272
        ),
        'temperature': fields.Float(
            description='Measured temperature',
            required=True,
            example=22.3
        ),
        'notes': fields.String(
            description='Additional notes',
            required=True,
            example='Strange day'
        ),
    }
)


@api.route('/measurements')
class Measurement(Resource):
    @api.doc(model=[measurement_model])
    def get(self):
        return measurements

    @api.doc(model=[measurement_model], body=add_measurement_request_body)
    def post(self):
        measurement = {
            'id': str(uuid.uuid4()),
            'timestamp': request.json['timestamp'],
            'temperature': request.json['temperature'],
            'notes': request.json.get('notes'),
        }
        measurements.append(measurement)

        return measurement


if __name__ == '__main__':
    app.run()
```

Per definire dei modelli per i corpi delle nostre richieste e risposte abbiamo usato `api.model`. Abbiamo definito i nomi ed i campi appropriati. Per ciascun campo, abbiamo definito il tipo, descrizione, esempio, e se è richiesto.

### Swagger UI models

Per aggiungere i modelli agli endpoint, abbiamo usato il decorator @api.doc. Il parametro body definisce il corpo della richiesta, m,entre il modello definisce il corpo della risposta.

### Swagger UI models

Ora dovremmo avere l'idea base di come docuemntare la nostra API RESTful Flask con Flask-RestX. Abbiamo soltanto scalfito la superficie. Controlliamo la documentaizone Swagger per dettagli su come definire le info di autenticazione, i parametri degli URL, gli status code e molto altro.

## Conclusion

Molti di noi possono migliorare nello scrivere documentazione. Fortunatamente, ci sono molti tool disponibili per semplificare il processo di scrittura. Quando scriviamo i package e le librerie, usiamo Sphinx per organizzare ed aituarci a generar ela nostra documentazione a partire da delle docstring. Quando lavoriamo su un'API RESTful, usiamo un tool che genera uno schema OpenAPI, dal momento che lo schema può essere usato da molti altri strumenti, ovverto tutto dai data validator ai code generator.
