# 7.2 Git e Controllo di Versione

## Cos'è Git?

**Git** è un sistema di controllo di versione distribuito, creato da Linus Torvalds nel 2005 per gestire il codice sorgente del kernel Linux. Tiene traccia delle modifiche ai file nel tempo, permettendo di collaborare, tornare a versioni precedenti e gestire lo sviluppo in parallelo.

## Concetti fondamentali

### Repository

Un **repository** (repo) è una directory che contiene il progetto e tutta la sua storia di modifiche. Si crea con `git init` o si clona da remoto con `git clone`.

### Commit

Un **commit** è uno snapshot del progetto in un dato momento. Ogni commit ha:

* un **hash** univoco (es: `a1b2c3d4...`);
* un **messaggio** che descrive le modifiche;
* un **autore** e una **data**;
* uno o più **genitori** (commit precedenti).

```
commit a1b2c3d4e5f6...
Author: Mario Rossi <mario@example.com>
Date:   Mon Jul 28 13:00:00 2026

    Aggiunta funzione di login
```

### Area di staging

Git distingue tre aree:

* **Working directory**: i file sul disco, come li modifichiamo.
* **Staging area (index)**: le modifiche pronte per il prossimo commit.
* **Repository**: la storia dei commit.

```
Working → git add → Staging → git commit → Repository
```

## Operazioni principali

### git init

Crea un nuovo repository nella directory corrente:

```bash
git init
git config user.name "Mario Rossi"
git config user.email "mario@example.com"
```

### git clone

Copia un repository remoto in locale:

```bash
git clone https://github.com/utente/progetto.git
```

### git status

Mostra lo stato dei file (modificati, staged, non tracciati):

```bash
git status
```

### git add

Aggiunge file alla staging area:

```bash
git add file.txt        # file specifico
git add .               # tutti i file
git add -p              # interattivo (pezzo per pezzo)
```

### git commit

Crea un commit con le modifiche in staging:

```bash
git commit -m "Messaggio descrittivo"
git commit -am "Salta git add per file già tracciati"
```

### git log

Mostra la cronologia dei commit:

```bash
git log                 # lista completa
git log --oneline       # formato compatto
git log --graph         # con grafico dei branch
```

### git diff

Mostra le differenze tra versioni:

```bash
git diff                # working vs staging
git diff --staged       # staging vs ultimo commit
git diff HEAD~1         # confronto con un commit precedente
```

## Branch e merging

Un **branch** è un ramo di sviluppo indipendente. Il branch predefinito si chiama `main` (o `master`).

```bash
git branch feature-x        # crea un nuovo branch
git checkout feature-x      # passa al branch (o git switch)
git checkout -b feature-x   # crea e passa al branch (scorciatoia)
git merge feature-x         # unisce feature-x nel branch corrente
git branch -d feature-x     # elimina il branch (dopo il merge)
```

```
main:   A---B---C---D
            \     /
feature-x    E---F
```

### Conflitti di merge

Se lo stesso file è stato modificato in modo diverso su due branch, Git segnala un **conflitto**:

```text
<<<<<<< HEAD
versione sul branch corrente
=======
versione sul branch da mergiare
>>>>>>> feature-x
```

Il programmatore deve risolvere il conflitto manualmente, poi fare `git add` e `git commit`.

## Lavorare con repository remoti

```bash
git remote add origin https://github.com/utente/progetto.git
git push origin main        # carica i commit su remoto
git pull origin main        # scarica e integra i commit remoti
git fetch origin            # scarica senza integrare
```

## File .gitignore

Il file `.gitignore` elenca i file/directory che Git deve ignorare:

```gitignore
*.o
*.exe
build/
__pycache__/
.vscode/
.env
```

## Buone pratiche

* Commit piccoli e atomici: ogni commit fa una cosa sola.
* Messaggi chiari: spiega *cosa* e *perché*, non *come*.
* Non committare file generati (binari, compilati, dipendenze).
* Usare branch per funzionalità isolate.
* Fare `git pull` prima di `git push` per evitare conflitti.
* Non forzare la push (`git push --force`) su branch condivisi.

