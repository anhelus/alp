# Cosa è la code quality?

Cosa intendiamo per *code quality*? Come facciamo a misurarla? Come miglioriamo la code quality ed il nostro codice Python?

In generale, la code quality si riferisce a quanto è funzionale e manutenibile il nostro codice. Il codice viene considerato di alta qualità quando:

* segue il suo scopo;
* il suo comportamento può essere testato;
* segue uno stile consistente;
* è comprensibile;
* non contiene vulnerabilità di sicurezza;
* è ben documentato;
* è semplice da manutenere.

DAl momento che abbiamo già affrontato i primi due punti negli articoli precedenti, il focus di questo articolo è sui punti successivi. In particolare, vedremo come migliorare la qualità del nostro codice Python mediante l'uso di linter, code formatter e scanner per le vulnerabilità di sicurezza.

## Linter

I *linter* evidenziano gli errori di programmazione, stile, i bug, ed i costrutti "sospetti" mediante l'analisi del codice sorgente. I tool di linting sono semplici da impostare, forniscono dei buoni valori di defautl, e migliorano l'esperienza complessiva di sviluppo rimuovendo le frizioni tra gli sviluppatori che hanno diverse opinioni sullo stile.

Anche se il linting è una pratica comune, è ancora FROWNED da molti sviluppatori, dal momento che questi tendono ad essere molto spesso molto soggettivi.

Vediamo un rapido esempio.

```py title="Prima versione"
numbers = []

while True:
    answer = input('Enter a number: ')
    if answer != 'quit':
        numbers.append(answer)
    else:
        break

print('Numbers: %s' % numbers)
```

```py title="Versione due"
numbers = []

while (answer := input("Enter a number: ")) != "quit":
    numbers.append(answer)

print(f"Numbers: {numbers}")
```

```py title="Versione tre"
numbers = []

while True:
    answer = input("Enter a number: ")
    if answer == "quit":
        break
    numbers.append(answer)

print(f"Numbers: {numbers}")
```

Quale tra le precedenti è migliore?

In termini di funzionalità, fanno praticamente la stessa cosa. Qual è quella che preferiamo con i nostri collaboratori?

Come sviluppatore, molto probabilmente lavirimo in team. E, in un team, è molto importante che tutti gli sviluppatori seguano gli stessi standard di codice. Altrimenti, risulta essere molto più complesso leggere il codice di qualcun altro. Il focus delle code reviews dovrebbe essere sui problemi ad alto livello, piuttosto che sui problemi sintattici di formattazione.

Ad esempio, se decidiamo di terminare ogni frase con un punto esclamativo, sarebbe molto difficile per un lettore inferire il tono. Se andiamo avanti e ignoraiamo gli standard comuni come le lettere maiuscole e le regole per lo spacing, le frasi saranno molto difficili da leggere. Sarà necessario molto più "cervello" per leggerle. Perderemmo lettori e collaboratori. Lo stesso vale per il codice. USiamo le linee guida per rendere più semplice ai nostri compagni sviluppatori (inclusi noi stessi) per trasferire gli intenti e collaborare ocn noi.

Siamo fortunati come sviluppatori Python ad avere la guida PEP-8 a nostra disposizione, che fornisce un insieme di convenzioni, linee guida e best practices per rendere il nostro codice più semplice da leggere e manutenere. Si focalizza sulle convenzioni dei nomi, commenti ai codici, e problemi al layout, come indentazioni e spazi. d esempio:

* una singola istruzione deve essere lunga al massimo 79 caratteri
* usare lo spazio al posto dei tab
* usare nomi di funzioni in minuscolo

Per quello che riguarda i tool di linting, anche se ve ne sono molti in giro, per la maggior parte cercano gli errori nella logica del codice, o forzano gli standard di codice:

* code logic: questi controllano gli errori di programmazione, forzano gli standard, cercano i *code smells*, e controllano la complessità del codice. Pyflakes e McCabe sono i tool più popolari per il linting della code logic.
* code style: questi controllano semplicemente gli standard del codcie sulla base del PEP-8. Un esempio di tool di questo tipo è pycodestyle.

## Flake8

Flake8 è un wrapper di Pyflakes, pycodestyle e McCabe. Può essere installato come qualsiasi altro package PyPI:

```sh
$ pip install flake8
```

Diciamo che abbiamo il seguente codice slavato in un file chiamato `my_module.py`:

```py
from requests import *

def get_error_message(error_type):
    if error_type == 404:
        return 'red'
    elif error_type == 403:
        return 'orange'
    elif error_type == 401:
        return 'yellow'
    else:
        return 'blue'


def main():
    res = get('https://api.github.com/events')
    STATUS = res.status_code
    if res.ok:
        print(f'{STATUS}')
    else:
        print(get_error_message(STATUS))




if __name__ == '__main__':
    main()
```

Per effettuare il linting di questo file, possiamo semplicemente eseguire il comando:

```sh
$ python -m flake8 my_module.py
```

Questo dovrebbe produrre il seguente output:

```sh
my_module.py:1:1: F403 'from requests import *' used; unable to detect undefined names
my_module.py:3:1: E302 expected 2 blank lines, found 1
my_module.py:15:11: F405 'get' may be undefined, or defined from star imports: requests
my_module.py:25:1: E303 too many blank lines (4)
```

Potremmo anche vedere un errore `my_module.py:26:11: W292 no newline at end of file` a seconda della configurazione della nostra IDE.

Per ogni violazione viene stampata a schermo una riga che contiene i seguenti dati:

* percorso del file (relativo alla cartella da dove è stato eseguito Flake8)
* numero di riga
* numero di colonna
* identificativo della regola violata
* descrizione della regola violata

Le violazioni segnalate che iniziano con la F sono degli errori da Pyflakes, mentre quelle che iniziano con la E sono da pycodestyle.

Dopo aver corretto le violazioni, dovremmo avere:

```py
from requests import get


def get_error_message(error_type):
    if error_type == 404:
        return 'red'
    elif error_type == 403:
        return 'orange'
    elif error_type == 401:
        return 'yellow'
    else:
        return 'blue'


def main():
    res = get('https://api.github.com/events')
    STATUS = res.status_code
    if res.ok:
        print(f'{STATUS}')
    else:
        print(get_error_message(STATUS))


if __name__ == '__main__':
    main()
```

Oltre a PyFlakes e pycodestile, possiamo usare Flake8 per controllare la CYCLOMATIC COMPLEXITY. Ad esempio, la funzione `get_error_message` ha una complessità pari a quattro, dal momento che ci sono quattro possibili branch (o percoris del codice):

```py
def get_error_message(error_type):
    if error_type == 404:
        return 'red'
    elif error_type == 403:
        return 'orange'
    elif error_type == 401:
        return 'yellow'
    else:
        return 'blue'
```

Per forzare, ad esempio, una complessità massima di 3, eseguiamo la seguente istruzione:

```sh
$ python -m flake8 --max-complexity 3 my_module.py
```

Flake8 dovrebbe segnalare un errore del tipo:

```sh
my_module.py:4:1: C901 'get_error_message' is too complex (4)
```

Possiamo quindi effettuare un refactoring del tipo:

```py
def get_error_message(error_type):
    colors = {
        404: 'red',
        403: 'orange',
        401: 'yellow',
    }
    return colors[error_type] if error_type in colors else 'blue'
```

Flake8 dovrebbe adesso dare esito positivo:

```sh
$ python -m flake8 --max-complexity 3 my_module.py
```

Possiamo aggiungere ulteriori controlli a Flake8 mediante il suo sistema di plugin. Ad esempio, per forzare le naming convention di PEP-8, isntalliamo pep8-naming:

```sh
$ pip install pep8-naming
```

Eseguendo:

```sh
$ python -m flake8 my_module.py
```

Dovremmo vedere:

```sh
my_module.py:15:6: N806 variable 'STATUS' in function should be lowercase
```

Per correggere:

```py
def main():
    res = get('https://api.github.com/events')
    status = res.status_code
    if res.ok:
        print(f'{status}')
    else:
        print(get_error_message(status))
```

!!!tip
    Diamo un'occhiata ad Awesome Flake8 Extension per una lista delle estensioni più popolari per Flake8.

!!!tip
    Un altro tool popolare per il linting è Pylama che, come Flake8, mette insieme diversi linter.

## Code formatters

Mentre i linter si limitano a valutare problemi nel codice, i code formatter effettuano delle modifiche al codice sulla base di un insieme di standard.

!!!note
    Mantenere un codice ben formattato che segue una precisa guida per il suo stile lo rende più semplice da leggere, il che rende più semplice individuare bug ed aggiungere nuovi sviluppatori. Riduce inoltre i conflitti che possono emergere in fase di merge.

Di nuovo, dato che questo è un compito stupido sul quale gli sviluppatori hanno spesso pareri soggettivi (tab vs spazi, singole vs doppie virgolette), usare un tool di code formatting per riformattare automaticamente il codice è meglio.

### isort

isort viene usato per separare automaticamente gli import nei seguenti gruppi:

* standard library
* librerie di terze parti
* locali

I diversi gruppi sono quindi ordinati in ordine alfabetico. Ad esempio:

```py
# standard library
import datetime
import os

# third-party
import requests
from flask import Flask
from flask.cli import AppGroup

# local
from your_module import some_method
```

Per installare il tool:

```sh
$ pip install isort
```

Volendo, è disponibile anche come plugin per Flake8, ed è chiamato `flake8-isort`.

Per eseguirlo su tutti i file nella cartella attuale e nelle sottocartelle:

```sh
$ python -m isort .
```

Invece, per eseguirlo su un singolo file:

```sh
$ python -m isort my_module.py
```

Prima avevamo:

```py
import os
import datetime
from your_module import some_method
from flask.cli import AppGroup
import requests
from flask import Flask
```

Dopo otteniamo:

```py
import datetime
import os

import requests
from flask import Flask
from flask.cli import AppGroup

from your_module import some_method
```

Per controllare se i nostri import sono ordinati in maniera corretta, possiamo usare il flag --check-only:

```sh
$ python -m isort my_module.py --check-only

ERROR: my_module.py Imports are incorrectly sorted and/or formatted.
```

Per vedere i cambi che saranno applicati (senza applicarli) usiamo il flag --diff:

```sh
$ python -m isort my_module.py --diff

--- my_module.py:before      2022-02-28 22:04:45.977272
+++ my_module.py:after       2022-02-28 22:04:48.254686
@@ -1,6 +1,7 @@
+import datetime
 import os
-import datetime
+
+import requests
+from flask import Flask
+from flask.cli import AppGroup
 from your_module import some_method
-from flask.cli import AppGroup
-import requests
-from flask import Flask
```

Dobbiamo usare l'opzione `--profile black` quando si usa isort con Black per evitare delle collisioni di code style:

```sh
$ python -m isort --profile black .
```

## Black

Black è un formatter che viene usato per riformattare il codice sulla base delle style guide di Black, che è molto simile a PEP-8.

```sh
$ pip install black
```

!!!tip
    Possiamo anche usare un plugin per Flake8, ovvero flake8-black.

Al solito, per riformattare i file in maniera ricorsiva all'interno della cartella attuale:

```sh
$ python -m black .
```

Al solito, può essere eseguito su un singolo file:

```
$ python -m black my_module.py
```

Prima abbiamo:

```py
import pytest

@pytest.fixture(scope="module")
def authenticated_client(app):
    client = app.test_client()
    client.post("/login", data=dict(email="dummy@email.ai", password="notreal"), follow_redirects=True)
    return client
```

Dopo:

```py
import pytest


@pytest.fixture(scope="module")
def authenticated_client(app):
    client = app.test_client()
    client.post(
        "/login",
        data=dict(email="dummy@email.ai", password="notreal"),
        follow_redirects=True,
    )
    return client
```

Se vogliamo semplicemente vedere se il nostro codice segue gli standard dello stile Black, possiamo usare il flag `--check`:

```sh
$ python -m black my_module.py --check

would reformat my_module.py
Oh no! 💥 💔 💥
1 file would be reformatted.
```

Il flag --diff invece ci mostra la differenza tra il codice attuale e quello che sarà quello riformattato:

```sh
$ python -m black my_module.py --diff

--- my_module.py        2022-02-28 22:04:45.977272 +0000
+++ my_module.py        2022-02-28 22:05:15.124565 +0000
@@ -1,7 +1,12 @@
 import pytest
+

 @pytest.fixture(scope="module")
 def authenticated_client(app):
     client = app.test_client()
-    client.post("/login", data=dict(email="dummy@email.ai", password="notreal"), follow_redirects=True)
-    return client
\ No newline at end of file
+    client.post(
+        "/login",
+        data=dict(email="dummy@email.ai", password="notreal"),
+        follow_redirects=True,
+    )
+    return client
would reformat my_module.py

All done! ✨ 🍰 ✨
1 file would be reformatted.
```

YAPF e autopep8 sono dei formatter simili a Black che meritano uno sguardo.

## Security Vulnerability Scanners

Le vulnerabilità di sicurezza sono probabilmente l'aspetto più importante della code quality, ma spesso sono ignorate. Il nostro codice è sicuro solo come la sua parte meno sicura. Per fortuna, c'è un gran numero di strumenti che ci aiutano ad individuare possibili vulnerabilità nel nostro codice. Vediamone un paio.

### Bandit

Bandit è uno strumento progettato per trovare dei problemi di sicurezza comuni nel codice Python, come stringhe con password in chiaro, codice untrusted che effettua la deserializzazione, usare pass in blocchi except, ed altro.

```sh
$ pip install bandit
```

Anche in questo caso abbiamo un plugin per Flake8, ovvero `flake8-bandit`. Eseguiamolo come segue:

```sh
$ bandit my_module.py
```
Dato questo codice:

```py
evaluate = 'print("Hi!")'
eval(evaluate)


evaluate = 'open("secret_file.txt").read()'
eval(evaluate)
```

Dovremmo vedere i seguenti avvisi:

```sh
>> Issue: [B307:blacklist] Use of possibly insecure function - consider using safer
    ast.literal_eval.
   Severity: Medium   Confidence: High
   Location: my_module.py:2
   More Info:
    https://bandit.readthedocs.io/en/latest/blacklists/blacklist_calls.html#b307-eval
1   evaluate = 'print("Hi!")'
2   eval(evaluate)
3

--------------------------------------------------
>> Issue: [B307:blacklist] Use of possibly insecure function - consider using safer
    ast.literal_eval.
   Severity: Medium   Confidence: High
   Location: my_module.py:6
   More Info:
    https://bandit.readthedocs.io/en/latest/blacklists/blacklist_calls.html#b307-eval
5   evaluate = 'open("secret_file.txt").read()'
6   eval(evaluate)

--------------------------------------------------
```

### Safety

Safety è un altro tool che è utile per mantenere il nostro codice libero da problemi di sicurezza. Viene usato per controllare le dipendenze installate per vulnerabilità di sicurezza conosciute rispetto a Safety DB, che è un database di vulnerability di sicurezza conosciute nei package Python.

```sh
$ pip install safety
```

Con l'ambiente virtuale attivato, possiamo eseguirlo come segue:

```sh
$ safety check
```

Ecco un esempio di output con Flask v0.12.2:

```sh
+==============================================================================+
|                                                                              |
|                               /$$$$$$            /$$                         |
|                              /$$__  $$          | $$                         |
|           /$$$$$$$  /$$$$$$ | $$  \__//$$$$$$  /$$$$$$   /$$   /$$           |
|          /$$_____/ |____  $$| $$$$   /$$__  $$|_  $$_/  | $$  | $$           |
|         |  $$$$$$   /$$$$$$$| $$_/  | $$$$$$$$  | $$    | $$  | $$           |
|          \____  $$ /$$__  $$| $$    | $$_____/  | $$ /$$| $$  | $$           |
|          /$$$$$$$/|  $$$$$$$| $$    |  $$$$$$$  |  $$$$/|  $$$$$$$           |
|         |_______/  \_______/|__/     \_______/   \___/   \____  $$           |
|                                                          /$$  | $$           |
|                                                         |  $$$$$$/           |
|  by pyup.io                                              \______/            |
|                                                                              |
+==============================================================================+
| REPORT                                                                       |
| checked 37 packages, using default DB                                        |
+============================+===========+==========================+==========+
| package                    | installed | affected                 | ID       |
+============================+===========+==========================+==========+
| flask                      | 0.12.2    | <0.12.3                  | 36388    |
| flask                      | 0.12.2    | <1.0                     | 38654    |
+==============================================================================+
```

Ora che conosciamo i tool, la prossima domanda è: quando usarli?

Tipicamente, dovremmo usarli:

* mentre si fa il coding (all'interno della nostra IDE)
* a momento della commit
* quando il codice viene controllato nel source control mediante una pipeline di CI
* all'interno della nostra IDE

E' meglio controllare dei problemi che possono avere un impatto negativo sulla qualità il prima possibile. Quindi, è fortemente raccomandato effettuare il linting e la formattazione del codice durante lo sviluppo. Molti degli IDE più popolari hanno dei linter e dei formatter integrati. Saremo in grado di trovare un plugin per il nostro editor per la maggior parte dei tool sopra menzionati. Alcuni plugin ci avvertono in tempo reale sulle violaizoni del code style e degli errori di programmazione.

## pre-commit hooks

Dal momento che, inevitabilmente, ci perderemo un warning alle volte mentre scriviamo il nostro codice, è una buona pratica controllare i problemi di qualità mentre facciamo la commit con dei pre-commit git hooks. Possiamo per prima cosa formattare il codice prima di effettuarne il linting. IN questo modo possiamo evitare di fear il commit di codice che non passerà i controlli di qualità nella nostra pipeline di CI.

Il framework di pre-commit è raccomandato per gestire i git hooks.

```sh
$ pip install pre-commit
```

Una volta installato, aggiungiamo un file di configurazione pre-commit chiamato `.pre-commit-config.yaml` al nostro progetto. Per eseguire ad esempio Flake8, aggiungiamo la seguente configurazione:


```yaml
repos:
-   repo: https://gitlab.com/PyCQA/flake8
    rev: 4.0.1
    hooks:
    -   id: flake8
```

Infine, impostiamo gli script git hook:

```sh
(venv)$ pre-commit install
```

Ora, ogni volta che effettuiamo una commit Flake8 sarà eseguito prima della commit attuale. E se vi sono dei problemi, la commit sarà abbandonata.

### CI Pipeline

Anche se potremmo usare dei tool per la code qualità nel nostro editor e negli hook pre-commit, non possiamo sempre contare sul fatto che i nostri collaboratori facciano lo stesso. Di cosneguenza, dovremmo eseguire dei controlli per la code quality all'interno della nostra pipeline di CI. A questo punto, dovremmo eseguire dei linter e dei security vulnerability detector, assicurandoci che il codice segua un certo stile. Possiamo eseguire questi controlli in parallelo ai nostri test.

### Un esempio reale

Creiamo un semplice progetto di esempio per vedere come tutto questo funziona.

PEr prima cosa, creiamo una nuova cartella:

```sh
$ mkdir flask_example
$ cd flask_example
```

Adesso inizializziamo il nostro progetto con pipenv:

```sh
$ pipenv --three
```

A questo punto, installiamo Flask, pytest, Flake8, Black, isort, Bandit, e Safety:

```sh
$ pipenv install flask
$ pipenv install --dev pytest flake8 black isort safety bandit
```

Creiamo un file che contenga i test chiamato `test_app.py`:

```py
from app import app
import pytest


@pytest.fixture
def client():
    app.config['TESTING'] = True

    with app.test_client() as client:
        yield client


def test_home(client):
    response = client.get('/')

    assert response.status_code == 200
```

Aggiungiamo adesso un file per l'app Flask chiamato `app.py`:

```py
from flask import Flask

app = Flask(__name__)


@app.route('/')
def home():
    return 'OK'


if __name__ == '__main__':
    app.run()
```

Adesso siamo pronti ad aggiungere la configurazione pre-commit.

Per prima cosa, inizializziamo una nuova repository git:

```sh
$ git init
```

A questo punto, installiamo la pre-commit, ed impostiamo gli script di git hook:

```sh
$ pipenv install --dev pre-commit
$ pipenv run pre-commit install
```

Creiamo un file di configurazione chiamato `.pre-commit-config.yaml`:

```yaml
repos:
-   repo: https://gitlab.com/PyCQA/flake8
    rev: 4.0.1
    hooks:
    -   id: flake8
```

Prima di fare la commit, eseguiamo `isort` e Black:

```sh
$ pipenv run isort . --profile black
$ pipenv run black .
```

Effettuiamo la commit per lanciare l'hook pre-commit:

```sh
$ git add .
$ git commit -m 'Initial commit'
```

Infine, configuriamo una CI pipeline mediante GitHub Actions. Per farlo, creiamo la seguente struttura di file e cartelle:

```
.github
└── workflows
    └── main.yaml
```

Nel file `.github/workflows/main.yaml` inseriamo il seguente codice:

```yaml
name: CI
on: [push]

jobs:
  test:
    strategy:
      fail-fast: false
      matrix:
        python-version: [3.10.2]
        poetry-version: [1.1.13]
        os: [ubuntu-latest]
    runs-on: ${{ matrix.os }}
    steps:
      - uses: actions/checkout@v3
      - uses: actions/setup-python@v2
        with:
          python-version: ${{ matrix.python-version }}
      - name: Run image
        uses: abatilo/actions-poetry@v2.0.0
        with:
          poetry-version: ${{ matrix.poetry-version }}
      - name: Install dependencies
        run: poetry install
      - name: Run tests
        run: poetry run pytest
  code-quality:
    strategy:
      fail-fast: false
      matrix:
        python-version: [3.10.2]
        poetry-version: [1.1.13]
        os: [ubuntu-latest]
    runs-on: ${{ matrix.os }}
    steps:
      - uses: actions/checkout@v3
      - uses: actions/setup-python@v2
        with:
          python-version: ${{ matrix.python-version }}
      - name: Run image
        uses: abatilo/actions-poetry@v2.0.0
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

* viene eseguita ad ogni push (`on: [push]`)
* viene eseguita sull'ultima versione di Ubuntu (`ubuntu-latest`)
* usa Python 3.10.2 (`python-version: [3.10.2], python-version: ${{ matrix.python-version }}`)
* usa Pipenv nella versione X.X.X (`poetry-version: [1.1.13], poetry-version: ${{ matrix.poetry-version }}`)

Vengono definiti due job: il test e la verifica della qualità del codice. Come suggerisce il nome, i test sono eseguiti nel job `test`, mentre i controlli per la code quality sono eseguiti nel job `code-quality`.

Aggiungiamo la configurazione CI a git ed effettuiamo la commit:

```sh
$ git add .github/workflows/main.yaml
$ git commit -m 'Add CI config'
```

Creiamo infine una nuova repository su GitHub, ed effettuiamo il push del nostro progetto al remote appena creato. Ad esempio:

```sh
$ git remote add origin git@github.com:jangia/flask_example.git
$ git branch -M main
$ git push -u origin main
```

Dovremmo vedere il nostro workflow eseguito sul tab Actions sulla nostra repository GitHub.

## Conclusioni

Quello della qualità del codice è uno dei topic più soggettivi nello sviluppo software. Lo stile del codice, in particolare, è un topic sensibile tra gli sviluppatori, dato che spendiamo molto del tempo di sviluppo leggendo codice. E' molto più semplice leggere e comprendere quando il codice ha uno stile ocnsistente che aderisce agli standard PEP-8. Dal momento che questo è un procedimento noioso, dovrebbe essere gestito da un computer mediante dei code formatter come Black ed isort. In modo simile, Flake8, Bandit e Safety ci aiutano ad assicurare che il codice sia sicuro e privo di errori.
