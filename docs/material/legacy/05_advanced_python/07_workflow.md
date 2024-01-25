# Workflow

In questo articolo, metteremo assieme tutto quello che abbiamo visto negli articoli precedenti creando un singolo progetto dall'inizio alla fine. Al termine dell'articolo:

* creeremo una pipeline di CI/CD mediante GitHub Actions
* configureremo il coverage reporting mediante CodeCov
* pubblicheremo il package su PyPi ed la documentazione su Read the Docs
* aggiorneremo PyPI e Read the Docs mediante delle GitHub Actions

## Setup del progetto

Creiamo un generatore di citazioni casuali che restituisca una citazione a caso da un certo insieme.

## Inizializzazione del progetto

Per prima cosa, creiamo una nuova cartella per il nostro progetto:

```sh
$ mkdir random-quote-generator
$ cd random-quote-generator
```

Inizializziamo il progetto usando Pipenv. Ricordiamoci di assegnare un nome univoco in modo tale da evitare collisioni con altri package su PyPI.

Creiamo quindi una nuova repository su GitHub, ed inizializziamo una repository git all'interno del nostro progetto.

```sh
$ git init
$ git add pyproject.toml
$ git commit -m "first commit"
$ git branch -M main
$ git remote add origin git@github.com:<your-github-username>/random-quote-generator.git
$ git fetch
$ git branch --set-upstream-to=origin/main main
$ git pull origin main --rebase
$ git push -u origin main
```

Una volta completato il setup base, continuiamo aggiungendo le seguenti dipendenze:

* pytest
* pytest-cov
* Black
* isort
* Flake8
* Bandit
* Safety

Install:

```sh
$ poetry add --dev pytest pytest-cov black isort flake8 bandit safety
```

Aggiungiamo i nuovi file pipenv.lock assieme al pipfile a git:

```sh
$ git add Pipfile Pipfile.lock
```

## Build del progetto

Creiamo adesso una nuova cartella chiamata "random_quote_generator". All'interno della cartella. aggiungiamo un file `__init__.py`, in modo che venga trattata come un package, assieme ad un file chiamato `quotes.py`.

```
random-quote-generator
├── poetry.lock
├── pyproject.toml
└── random_quote_generator
    ├── __init__.py
    └── quotes.py
```

All'interno di `quotes.py` aggiungiamo:

```py
quotes = [
    {
        "quote": "A long descriptive name is better than a short "
        "enigmatic name. A long descriptive name is better "
        "than a long descriptive comment.",
        "author": "Robert C. Martin",
    },
    {
        "quote": "You should name a variable using the same "
        "care with which you name a first-born child.",
        "author": "Robert C. Martin",
    },
    {
        "quote": "Any fool can write code that a computer "
        "can understand. Good programmers write code"
        " that humans can understand.",
        "author": "Martin Fowler",
    },
]
```

Ovviamente non c'è niente di speciale qui. Soltanto una lista di dizionari, uno per ogni citazione. Quindi, creiamo una nuova cartella nella radice di progetto chiamata `tests` ed aggiungiamo i file seguenti:

```
tests
├── __init__.py
└── test_get_quote.py
```

Modifichiamo il file `test_get_quote.py` come segue:

```py
from random_quote_generator import get_quote
from random_quote_generator.quotes import quotes


def test_get_quote():
    """
    GIVEN
    WHEN get_quote is called
    THEN random quote from quotes is returned
    """

    quote = get_quote()

    assert quote in quotes
```

Eseguiamo i test:

```sh
$ pipenv run python -m pytest tests
```

Questi dovrebbero fallire:

```sh
E   ImportError: cannot import name 'get_quote' from 'random_quote_generator'
```

A questo punto, aggiungiamo un nuovo file chiamato `get_quote.py`:

```py
import random

from random_quote_generator.quotes import quotes


def get_quote() -> dict:
    """
    Get random quote

    Get randomly selected quote from database our programming quotes

    :return: selected quote
    :rtype: dict
    """

    return quotes[random.randint(0, len(quotes) - 1)]
```

In pratica, stiamo scegliendo una citazione generando un intero casuale mediante `random.randint` tra 0 e l'ultimo indice.

Esportiamo la funzione in `random_quote_generator/__init__.py`:

```py
"""
Random Quote Generator
======================

Get random quote from our database of programming wisdom
"""
from .get_quote import get_quote

__all__ = ["get_quote"]
```

La funzione viene importata ed elencata all'interno dell'attributo `__all__`, che è una lista di oggetti pubblici per il modulo. In altre parole, quando qualcuno usa `from random_quote_generator import *`, soltanto i nomi elencati in `__all__` saranno importati.

Il test dovrebbe adesso avere successo:

```sh
$ pipenv run python -m pytest tests
```

Creiamo un file `.gitignore` alla radice del nostro progetto, ed aggiungiamo le cartelle `random_quote_generator` e `test` a git assieme al file `.gitignore`:

```sh
$ git add random_quote_generator/ tests/ .gitignore
```

Abbiamo finito. Il package è pronto per essere inviato su PyPI.

### Documentare il progetto

Il nostro package funziona, ma i nostri utenti dovranno controllarne il codice sorgente per vedere come usarlo. Abbiamo già incluso le docstring, per cui possiamo facilmente creare la documentazione del progetto "standalone" mediante Sphinx.

Con Sphinx installato, eseguiamo la seguente istruzione per fare lo scaffold dei file e delle cartelle per Sphinx dalla radice di progetto:

```sh
$ sphinx-quickstart docs
```

Ci verranno fatte alcune domande:

```sh
> Separate source and build directories (y/n) [n]: n
> Project name: Random Quote Generator
> Author name(s): Your Name
> Project release []: 0.1.0
> Project language [en]: en
```

A questo punto, aggiorniamo la configurazione del progetto. Apriamo `docs/conf.py` e rimpiazziamo questa parte:

```py
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))
```

con questa:

```py
import os
import sys
sys.path.insert(0, os.path.abspath('..'))
```

Adesso, autodoc, che è usato per prendere la documentazione dalle docstring, cercherà i moduli nella cartella padre di "docs".

Aggiungiamo la seguente estensione alla lista delle estensioni:

```
extensions = [
    'sphinx.ext.autodoc',
]
```

Aggiorniamo `docs/index.rst` come segue:

```rst
.. Random Quote Generator documentation master file, created by
   sphinx-quickstart on Mon Dec 21 22:27:23 2020.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to Random Quote Generator's documentation!
==================================================

.. automodule:: random_quote_generator
    :members:

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
```

Questo file dovrebbe essere escluso da Flake8, che aggiungeremo a breve. Per cui creiamo un file `.flake8` nella cartella radice del progetto:

```
[flake8]
exclude =
    docs/conf.py,
```

Aggiungiamo la cartella `docs` e `.flake8` a git:

```sh
$ git add docs/ .flake8
```

## GitHub Actions

Adesso è il momento di collegare una pipeline di CI con GitHub Actions. Aggiungiamo i seguenti file e cartelle alla radice di progetto.

```sh
.github
└── workflows
    └── branch.yaml
```

All'interno di branch.yaml, aggiungiamo:

```yaml
name: Push
on: [push]

jobs:
  test:
    strategy:
      fail-fast: false
      matrix:
        python-version: ['3.10']
        poetry-version: ['1.1.13']
        os: [ubuntu-latest]
    runs-on: ${{ matrix.os }}
    steps:
      - uses: actions/checkout@v3
      - uses: actions/setup-python@v3
        with:
          python-version: ${{ matrix.python-version }}
      - name: Run image
        uses: abatilo/actions-poetry@v2.1.4
        with:
          poetry-version: ${{ matrix.poetry-version }}
      - name: Install dependencies
        run: poetry install
      - name: Run tests
        run: poetry run pytest --cov=./ --cov-report=xml
      - name: Upload coverage to Codecov
        uses: codecov/codecov-action@v2
  code-quality:
    strategy:
      fail-fast: false
      matrix:
        python-version: ['3.10']
        poetry-version: ['1.1.13']
        os: [ubuntu-latest]
    runs-on: ${{ matrix.os }}
    steps:
      - uses: actions/checkout@v3
      - uses: actions/setup-python@v3
        with:
          python-version: ${{ matrix.python-version }}
      - name: Run image
        uses: abatilo/actions-poetry@v2.1.4
        with:
          poetry-version: ${{ matrix.poetry-version }}
      - name: Install dependencies
        run: poetry install
      - name: Run black
        run: poetry run black . --check
      - name: Run isort
        run: poetry run isort . --check-only --profile black
      - name: Run flake8
        run: poetry run flake8 .
      - name: Run bandit
        run: poetry run bandit .
      - name: Run saftey
        run: poetry run safety check
```

Questa configurazione:

* viene eseguita ad ogni push su ogni singolo branch (on: [push])
* esegue l'ultima versione di Ubuntu (ubuntu-latest)
* usa Python 3.10 (python-version: [3.10], python-version: ${{ matrix.python-version }})
* usa Poetry versione 1.1.13 (poetry-version: [1.1.13], poetry-version: ${{ matrix.poetry-version }})

Vengono definiti due job: test e code-quality. Come suggerisce il nome, i test sono eseguiti nel job test, mentre i controlli sulla qualità del codice sono eseguiti nel job code-quality.

Ora ad ogni push nella repository GitHub, i job test e code quality saranno eseguiti.

Aggiungiamo .github a git:

```sh
$ git add .github/
```

Eseguiamo tutti i controlli per la qualità del codice:

```sh
$ pipenv run black .
$ pipenv run isort . --profile black
$ pipenv run flake8 .
$ pipenv run bandit .
$ pipenv run safety check
```

Assicuriamoci di aggiungere ogni file che può essere cambiato a git. Quindi, effettuiamo la commit ed il push delle nostre modifiche a GitHub.

```sh
$ git add docs/ random_quote_generator/ tests/
$ git commit -m 'Package ready'
$ git push -u origin main
```

Dovremmo vedere il nostro workflow eseguito sul tab "Actions" nella nostra repository GitHub. Assicuriamoci che passi prima di proseguire.

## CodeCov

A questo punto potremo configurare CodeCov per tracciare la code coverage. Navighiamo su http://codecov.io/, e logghiamo con il nostro account GitHub per trovare la nostra repository.

Seguiamo la guida Quick Start per impostare ed eseguire CodeCov.

Eseguiamo nuovamente il workflow definito dalle GitHub Actions. Una volta termianto, dovremmo essere in grado di vedre il coverage report su CodeCov.

Adesso, ogni volta che viene eseguito il nostro workflow, un coverage report sarà generato e caricato su CodeCov. Possiamo analizzare le modifiche nelle percentuali di coverage per branch, commit e pull request, focalizzandoci sugli aumenti e decrementi nel coverage nel tempo.

## Read the docs

Useremo Read the Docs per ospitare la nostra documentazione. Navighiamo su https://readthedocs.org, e logghiamoci usando il nostro account GitHub.

Adesso, clicchiamo su "Import a Project". Dopo averlo fatto, aggiorniamo i nostri progetti, ed aggiungiamo quello che abbiamo appena pushato su GitHub. Apriamo il progetto e navighiamo nella sezione "Admin". Quindi, su "Advanced Settings", impostiamo il branch di default su main. Non dimentichiamo di salvare le nostre modifiche.

Avremo bisogno di alcuni minuti per costruire la documentazione. Una volta fatto, dovremmo essere in grado di vedere la documentazione del progetto ad un link simile a https://your-project-slug-on-readthedocs.readthedocs.io.

Di default, la documentazione sarà ricostruita ad ogni push sul branch main. Con questo, l'unica cosa rimasta da fare è pubblicare il package su PyPI.

## PyPI

Iniziamo aggiungendo la seguente sezione a pyproject.toml in modo che il modulo "random_quote_generator" sia incluso nella distribuzione su PyPI:

```
packages = [
    { include = "random_quote_generator" },
]
```

Il nostro file diventerà quindi:

```
[tool.poetry]
name = "random-quote-generator-93618"
packages = [
    { include = "random_quote_generator" },
]
version = "0.1.0"
description = ""
authors = ["Amir Tadrisi <notreal@gmail.com>"]

[tool.poetry.dependencies]
python = "^3.10"

[tool.poetry.dev-dependencies]
pytest = "^7.1.2"
pytest-cov = "^3.0.0"
black = "^22.3.0"
isort = "^5.10.1"
flake8 = "^4.0.1"
bandit = "^1.7.4"
safety = "^1.10.3"

[build-system]
requires = ["poetry-core>=1.0.0"]
build-backend = "poetry.core.masonry.api"
Add a new file called release.yaml to ".github/workflows":

name: Release
on:
  release:
    types:
      - created

jobs:
  publish:
    strategy:
      fail-fast: false
      matrix:
        python-version: ['3.10']
        poetry-version: ['1.1.13']
        os: [ubuntu-latest]
    runs-on: ${{ matrix.os }}
    steps:
      - uses: actions/checkout@v3
      - uses: actions/setup-python@v3
        with:
          python-version: ${{ matrix.python-version }}
      - name: Run image
        uses: abatilo/actions-poetry@v2.1.4
        with:
          poetry-version: ${{ matrix.poetry-version }}
      - name: Publish
        env:
          PYPI_TOKEN: ${{ secrets.PYPI_TOKEN }}
        run: |
          poetry config pypi-token.pypi $PYPI_TOKEN
          poetry publish --build
```

Quindi, quando si crea una nuova release, il package sarà pubblicato su PyPI.

Quindi dovremo creare un token PyPI. Creiamo un account su PyPI, se non ne abbiamo già uno. Quindi, una volta loggati, clicchiamo su "Account settings" per aggiungere un nuovo API token. Copiamo il token. Dovremo adesso aggiungerlo ai *secrets* della nostra repository GitHub. Per farlo, clicchiamo sul tab "Settings", e quindi "Secrets" e poi "Actions". Usiamo PYPI_TOKEN per il nome al secret ed il valore del token come valore.

Adesso siamo pronti per creare la nostra prima release.

Aggiungiamo il file `release.yaml` a git così come il file `pyproject.toml` aggiornato, effettuiamone la commit, e pushiamo:

```sh
$ git add .github/workflows/release.yaml pyproject.toml
$ git commit -m 'Ready for first release'
$ git push -u origin main
```

Per creare una nuova release, navighiamo su https://github.com/<username>/<project-name>/releases/. Clicchiamo su "Create a new release". Indichiamo 0.1.0 come tag, ed Initial Release per il titolo.

Questo lancerà un nuovo workflow sulle GitHub Actions. Una volta completato, dovremmo essere in grado div ered il nostro package su PyPI.

A questo punto dovremmo essere in grado di installare il nostro package da PyPI.

## Conclusioni

Impostiamo una semplice pipeline di CI/CD per un package Python pubblicato su PyPI. Il codice su ogni branch viene controllato con i test e la code quality. Possiamo controllare la code coverage all'interno di CodeCov. Alla release, nuove versioni vengono deployate su PyPI, ed i documenti sono aggionrati. Quesot può semplificare di molto la nostra vita.

Le pipeline automatizzate come questa ci assicurano che il nostro worfklow rimanga lo stesso giorno dopo giorno. Tuttavia, dovremo sempre essere attenti alla cultura di lavoro del nostro team. Eseguiamo i test sul push, ma devono essere presenti. Infatti, automatizzare i test non darà alcun esito se non ci sono test. L'automatizzazione non farà alcuna differenza anche alla dimensione dei nostri cambi. Cerchiamo di mantenerli piccoli, facendo spesso dei merge sul main. I piccoli cambi assieme al TDD ed una pipeline di CI/CD possono fare un'enorme differenza alla qualità del software che stiamo producendo. Non dimentichiamo che si inizia e finisce sempre con la team culture.
