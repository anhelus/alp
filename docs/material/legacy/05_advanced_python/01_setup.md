# Setup dell'ambiente Python

!!!note
    Questo articolo fa parte della serie di Tutorial intitolata *Setup dell'ambiente Python*.

Fare il setup della propria macchina per permettere l'esecuzione di Python non è banale: infatti, quando usato per scopi che vanno al di là del semplice *Hello, World!*, è spesso necessario capire come gestire *contestualmente* diversi ambienti, molto spesso uno per ogni singolo progetto Python. Inoltre, alcuni ambienti potrebbero essere recentissimi, mentre altri potrebbero fare riferimento a codice scritto cinque o dieci anni fa.

Per nostra fortuna, esiste una grande varietà di strumenti in grado di semplificarci la vita: in particolare, in questo articolo vedremo quelli che sono gli strumenti disponibili per rendere la gestione delle dipendenze e dell'ambiente di lavoro più semplici. In particolare, in questo articolo vedremo quali sono gli strumenti disponibili per la gestione delle dipendenze e del nostro ambiente di lavoro, in modo da risolvere tre problemi:

1. installazione e modifica di versioni *differenti* di Python sulla stessa macchina;
2. gestione delle dipendenze e degli ambienti virtuali;
3. riproducibilità degli ambienti virtuali.

## Installazione di Python

L'approccio "classico", usato dalla maggior parte di noi, è quello di installare Python a partire dai file binari ufficiali, o magari usando il package manager del nostro sistema. Tuttavia, questi approcci prevedono che si utilizzi *sempre* la medesima versione di Python, il che non è sempre vero.

Un'ovvia soluzione può essere quella di avere diverse versioni di Python installate sulla propria macchina. Tuttavia, questa procedura non è semplice, e può comportare diverse complicazioni, aggirabili usando un tool come [pyenv](https://github.com/pyenv/pyenv), strumento che ci permette di mantenere una versione "di sistema" di Python, adattando però le altre agli specifici requisiti di ogni progetto.

!!!note "Compatibilità con Windows"
    Come indicato nella [documentazione ufficiale](https://github.com/pyenv/pyenv#windows), pyenv non è ufficialmente supportato da Windows. In tal senso, il suggerimento è quello di usare il fork [pyenv-win](https://github.com/pyenv-win/pyenv-win).

Una volta installato pyenv seguendo le istruzioni riportate sulla repository ufficiale, potremo usarlo per installare una specifica versione di Python come segue:

```sh
$ pyenv install 3.8.5
$ pyenv install 3.10.2

$ pyenv versions
* system
3.8.5
3.10.2
```

Potremo anche impostare la versione di sistema di Python usando l'istruzione `global`:

```sh
$ pyenv global 3.8.5

$ pyenv versions
system
* 3.8.5
3.10.2

$ python -v
Python 3.10.2
```

In modo analogo, possiamo selezionare uno specifico interprete per la cartella nella quale ci troviamo mediante l'istruzione `local`:

```sh
$ pyenv local 3.10.2

$ pyenv versions
  system
  3.8.5
* 3.10.2

$ python -V
Python 3.10.2
```

## Gestione delle dipendenze

Vediamo adesso alcuni strumenti per la gestione delle dipendenze, così come degli ambienti virtuali.

!!!tip "Cosa è un ambiente virtuale?"
    Per *ambiente virtuale* si intende una sorta di "spazio riservato" che permette di evitare conflitti tra progetti che usano differenti versioni dello stesso package: in pratica, potremo installare diverse versioni della stessa libreria all'interno di diversi ambienti virtuali.

### venv e pip

[venv](https://docs.python.org/3/library/venv.html) e [pip](https://pypi.org/project/pip/) sono due tra gli strumenti più popolari per la gestione, rispettivamente, degli ambienti virtuali e dei package installati. Risultano molto semplici da usare, e sono già integrati nella maggior parte delle distribuzioni Python.

#### Creazione, attivazione e disattivazione di un nuovo ambiente virtuale

Per creare un nuovo ambiente virtuale, creiamo una nuova cartella, spostiamoci nella stessa, ed usiamo venv:

```sh linenums="1"
$ mkdir nuova_cartella
$ cd nuova_cartella
$ python -m venv nuovo_venv
```

In particolare, l'istruzione alla riga `3` ci permetterà di creare un ambiente virtuale chiamato `nuovo_venv`. Dopo la creazione dello stesso, dovremo attivarlo mediante lo script `activate`, che viene creato in automatico da venv:

```sh
$ source nuovo_venv/bin/activate
(nuovo_venv)$
```

!!!note "Come funziona un ambiente virtuale?"
    Ci si potrebbe chiedere come funzioni, nella pratica, l'ambiente virtuale. In poche parole, la libreria venv crea una copia dell'interprete Python, che andrà ad inserire in una cartella sul nostro computer assieme a tutte le dipendenze che vorremo installare. Infatti, se provassimo ad eseguire l'istruzione `which python` dall'interno dell'ambiente virtuale vedremo il percorso dell'interprete Python interno all'ambiente virtuale.
    > ```sh
      (nuovo_venv)$ which python

      /Users/username/folder/...
      ```

Per disattivare un ambiente virtuale, eseguiamo l'istruzione `deactivate` dall'interno dell'ambiente.

```sh
(nuovo_venv)$ deactivate
```

#### Aggiunta di una nuova dipendenza con pip

Possiamo aggiungere nuovi package al nostro progetto mediante l'istruzione `install` di pip:

```sh
(nuovo_venv)$ python -m pip install nome_package
```

In questo modo, pip si occuperà di verificare che il package chiamato `nome_package` sia reperibile su [PyPI](https://pypi.org/), rendendolo contestualmente disponibile all'interprete Python all'interno del nostro ambiente virtuale.

#### Riproducibilità dell'ambiente virtuale

Per garantire la *riproducibilità* dell'ambiente virtuale, da parte sia nostra sia di colleghi, è necessario definire la lista di package richiesti per il funzionamento del progetto, tipicamente usando un file chiamato `requirements.txt`. Questo file può essere creato manualmente, oppure generato mediante l'istruzione `pip freeze`:

```sh
(nuovo_venv)$ python -m pip freeze > requirements.txt

(nuovo_venv)$ cat requirements.txt

brotlipy==0.7.0
certifi==2021.10.8
cffi @ file:///opt/conda/conda-bld/cffi_1642701102775/work
charset-normalizer @ file:///tmp/build/80754af9/charset-normalizer_1630003229654/work
colorama @ file:///tmp/build/80754af9/colorama_1607707115595/work
conda==4.12.0
conda-content-trust @ file:///tmp/build/80754af9/conda-content-trust_1617045594566/work
conda-package-handling @ file:///tmp/build/80754af9/conda-package-handling_1649105784853/work
cryptography @ file:///tmp/build/80754af9/cryptography_1639414572950/work
idna @ file:///tmp/build/80754af9/idna_1637925883363/work
pycosat==0.6.3
pycparser @ file:///tmp/build/80754af9/pycparser_1636541352034/work
pyOpenSSL @ file:///opt/conda/conda-bld/pyopenssl_1643788558760/work
PySocks @ file:///tmp/build/80754af9/pysocks_1605305812635/work
requests @ file:///opt/conda/conda-bld/requests_1641824580448/work
ruamel-yaml-conda @ file:///tmp/build/80754af9/ruamel_yaml_1616016711199/work
six @ file:///tmp/build/80754af9/six_1644875935023/work
tqdm @ file:///opt/conda/conda-bld/tqdm_1647339053476/work
urllib3 @ file:///opt/conda/conda-bld/urllib3_1643638302206/work
```

### Oltre venv e pip

Ammettiamolo: venv e pip sono strumenti abbastanza semplici da usare. Tuttavia, esistono altri tool, sicuramente più moderni, avanzati e flessibili, che permettono di ovviare ad alcuni limiti legati a venv e pip.

In primis, venv e pip non hanno informazioni sulla versione di Python con la quale stiamo lavorando: infatti, potremmo stare lavorando con la versione 3.1.0, ed inviare il nostro progetto ad un collega che usa la 3.10.0, generando probabili incompatibilità e conflitti non sempre facili da risolvere.

Inoltre, la gestione delle dipendenze e degli ambienti virtuali è fatta a mano: dovremo creare e gestire il file `requirements.txt` in prima persona, e separare manualmente le librerie che useremo durante lo sviluppo da quelle che useremo in produzione.

In tal senso, [Poetry](https://python-poetry.org/) e [Pipenv](https://pipenv.pypa.io/) sono degli strumenti che combinano le funzionalità offerte da venv e pip, rendendo facile separare gli ambienti di sviluppo e produzione, così come permettendo delle build *deterministiche* mediante dei file di lock che specificano, oltre alle versioni di tutte le dipendenze, anche la versione di Python utilizzata.

TODO: DA QUI

### Poetry

Poetry è probabilmente il tool di gestione delle dipendenze più ricco di feature di Python. Arriva con una CLI potente usata per creare e gestire i progetti Python. Una volta installata, per creare un nuovo progetto eseguiamo:

```sh
$ poetry new sample-project
$ cd sample-project
```

Eseguire questi comandi creerà i seguenti file e cartelle:

```
sample-project
|--- README.rst
|--- pyproject.toml
|--- sample_project
|    |--- __init__.py
|--- tests
     |--- __init__.py
     |--- test_sample_project.py
```

Le dipendenze sono gestite all'interno del file `pyproject.toml`:

```
TODO
```

!!!tip
    Per sapere di più sul file `pyproject.tom`, il nuovo file di configurazione Python che tratta "ogni progetto come un package", diamo uno sguardo a questo articolo.

Per aggiungere una nuova dipendenza, eseguiamo:

```sh
$ poetry add [--dev] <package name>
```

!!!tip
    Il flag `--dev` indica che la dipendenza deve essere usata soltanto in modalità di sviluppo. Le dipendenze di sviluppo non sono installate di default.

Ad esempio:

```sh
$ poetry add flask
```

Questo comando scarica ed installa Flask da PyPI all'interno dell'ambiente virtuale gestito da Poetry, lo aggiunge assieme a tutte le sue sotto-dipendenze al file poetry.lock, e lo aggiunge automaticamnete (come dipendenza top-level) a pyproject.toml.

```
[tool.poetry.dependencies]
python = "^3.10"
Flask = "^2.0.3"
```

Prendiamo nota delle [limitazioni alla versione](https://python-poetry.org/docs/basic-usage#version-constraints): "^2.0.3".

Per eseguire un comando all'interno dell'ambiente virtuale, usiamo prima poetry run. Per esempi, per eseguire dei test con pytest:

```sh
$ poetry run python -m pytest
```

`poetry run <command>` eseguirà dei comandi all'interno dell'ambiente virutale. Tuttavia, non sarà attivato l'ambiente virtuale. Per farlo, dobbiamo eseguire il comando `poetry shell`. PEr disattivarlo, possiamo semplicemente eseguire il comando `exit`. Di conseguenza, possiamo attivare il nostro ambiente virutale prima di lavorare al progetto e deattivarlo una volta che abbiamo terminato oppure usare `poetry run <command>` senza attivare l'ambiente virutale.

Poetry funziona anche bene con pyenv. IN tal senso, conviene dare un'occhiata alla [specifica sezione](https://python-poetry.org/docs/managing-environments/) sulla documentazione ufficiale.

### Pipenv

pipenv prova a risolvere glis tessi problemi di Poetry.

1. gestire le dipendenze e gli ambienti virtuali
2. riprodurre gli ambienti

Una volta installato, creiamo un nuovo progetto con Pipenv:

```sh
$ mkdir sample-project
$ cd sample-project
$ pipenv --python 3.8.5
```

Questo crea un nuovo ambiente virtuale ed aggiunge un *Pipfile* al progetto:

```
[[source]]
name = "pypi"
url = "https://pypi.org/simple"
verify_ssl = true

[dev-packages]

[packages]

[requires]
python_version = "3.10"
```

!!!tip
    Un Pipfile funzina praticamente come il pyproject.toml di Poetry.

Possiamo installare una nuova dipendenza in questo modo:

```sh
$ pipenv install [--dev] <package name>
```

!!!note
    Il flag `--dev` indica che la dipendenza deve essere usata soltanto in fase di sviluppo. Le dipendenze di sviluppo non sono installate di default.

Ad esempio:

```sh
$ pipenv install flask
```

Così come con Poetry, Pipenv scarica ed installa Flask all'interno dell'ambiente virutale, fissa tutte le sotto-dipendenze nel file Pipfile.lock, ed aggiunge una dipendenza ad alto livello al Pipfile.

Per eseguire uno script all'interno dell'ambiente virutale gestito da Pipenv, dobbiamo eseguirlo con il comando `pipenv run`. A desempio, per eseguire dei test mediante `pytest`, eseguiamo:

```sh
$ pipenv run python -m pytest
```

Come con Poetry, `pipenv run <command>` eseguirà dei comandi all'interno dell'ambiente virtuale. Per attivare l'ambiente virutale di Pipenv dobbiamo eseguire `pipenv shell`. Per disattivarlo, possiamo scrivere `exit`.

Anche Pipenv lavora bene con pyenv. Ad esempio, quando vogliamo creare un ambiente virtuale da una versione di Python che non abbiamo installata, ci chiederà se vogliamo prima instarla usando pyenv:

```sh
$ pipenv --python 3.7.5

Warning: TODO
```

### Suggerimenti

Cosa usare?

Il suggerimento per i principianti è iniziare con venv e pip. Sono i più facili da utilizzare. Una volta presa un po' di confidenza, potremo capire cosa hanno e cosa gli manca.

Per quello che riguarda Poetry e Pipenv, sono tool molto simili, e risolvono lo stesso problema, per cui tutto si riduce alla fine alle preferenze personali.

Alcune note:

1. Pubblicare su PyPI è molto più semplice usando Poetry, per cui se stiamo creando un package Python conviene usare questo tool.
2. Entrambi i progetti sono abbastanza lenti quando si tratta di risolvere le dipendenze, per cui se stiamo usando Docker potremmo volerli evitare.
3. Da una prospettiva open source, Poetry è più veloce, ed è più responsive ai feedback degli utenti.

!!!tip
    Nonostante tutto, però, io preferisco Pipenv.

## Tool aggiuntivi

Oltre a questi tool, è opportuno dare uno sguardo ai seguenti tool per installare e switchare tra diverse versioni di Python sulla stessa machcina, gestire dipendenze ed ambienti virtuali, e riprodurre tali ambienti.

1. Docker è una piattaforma per costruire, fare il deploy e gestire appliczioni containerizzati. E' perfetta per creare degli ambienti facilmente riproducibili.
2. Conda, che è molto popoalre nelle community di data science e machine learning, può aiutarci a gestire le dipendenze e gli ambienti virtuali, così come riprodurre gli ambienti.
3. quando dobbiamo semplicemente switchare tra ambienti virtuali e gestirli, possiamo usare virtualenvwrapper e pyenv-virtualenv.
4. pip-tools semplifica la gestione delle dipendenze e la riproducibilità dell'ambiente. Viene spesso usato assieme a venv.

|       | Versioning | Gestione delle dipendenze | Ambienti virtuali | Riproducibilità dell'ambiente |
| ----- | ---------- | ------------------------- | ----------------- | ----------------------------- |
| pyenv | :check:    | :x:                       | :x:               | :x:                           |
| venv + pip | :x:    | :check:                       | :check:               | :x:                           |
| venv + pip-tools | :x:    | :check:                       | :check:               | :check:                           |
| Poetry | :x:    | :check:                       | :check:               | :check:                           |
| Pipenv | :x:    | :check:                       | :check:               | :check:                           |
| Docker | :x:    | :x:                       | :x:               | :check:                           |
| Conda | :check:    | :check:                       | :check:               | :x:                           |

## Gestione di un progetto

Vediamo come gestire un progetto Flask usando pyenv e Poetry. Per prima cosa, creiamo una nuova cartella chiamata flask_exmaple e spostiamoci al suo interno:

```sh
$ mkdir flask_example
$ cd flask_example
```

A quel punto, impostiamo la versione di Python per il progetto con pyenv:

```sh
$ pyenv local 3.8.5
```

Quindi inizializziamo un nuovo progetto Python con Poetry:

```sh
$ poetry init

Package name [flask_example]:
Version [0.1.0]:
Description []:
Author [Your name <your@email.com>, n to skip]:
License []:
Compatible Python versions [^3.10]:

Would you like to define your main dependencies interactively? (yes/no) [yes] no
Would you like to define your development dependencies interactively? (yes/no) [yes] no
Do you confirm generation? (yes/no) [yes]
```

Aggiungiamo Flask:

```sh
$ poetry add flask
```

Infine, aggiungiamo pytest come dipendenza di sviluppo:

```sh
poetry add --dev pytest
```

Ora che abbiamo impostato un ambiente base, possiamo scrivere un test per un singolo endpoint. Aggiungiamo un file chiamato *test_app.py*.

```py
import pytest

from app import app

@pytest.fixture
def client():
    app.config['TESTING'] = True

    with app.test_client() as client:
        yield client


def test_health_check(client):
    response = client.get('/health-check/')

    assert response.status_code == 200
```

Dopo questo, aggiungiamo una semplice app Flask ad un nuovo file chiamato `app.py`:

```py
from flask import Flask

app = Flask(__name__)

@app.route('/health-check/')
def health_check():
    return'OK'

if __name__ == '__main__':
    app.run()
```

Ora eseguiamo i test:

```sh
$ poetry run python -m pytest
```

Possiamo quindi eseguire il server di sviluppo come segue:

```sh
$ poetry run python -m flask run
```

!!!tip
    Il comando `poetry run` esegue un comando all'interno dell'ambiente virtuale di Poetry.

## Conclusioni

Abbiamo visto i tool più popolari epr risolvere i seguenti problemi rispetto alle dipendenze ed alla gestione del workspace:

1. installare e switchare tra diverse versioni di POython sulla stemssam macchina
2. gestire le dipendenze e gli ambienti virtuali
3. riprodurre gli ambienti

Non è importante quale tool specifico usiamo nel nostro flusso di lavoro, e più quello che riusciamo a fare per risolvere questi problemi. Scegliamo ed usiamo i tool che rendono facile per noi sviluppare in Python.
