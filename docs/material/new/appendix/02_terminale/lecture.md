# 7.3 Terminale e Riga di Comando

## Cos'è un terminale?

Un **terminale** (o console, shell) è un'interfaccia testuale per interagire con il sistema operativo. A differenza della GUI (interfaccia grafica), i comandi vengono digitati come testo e il sistema risponde con testo.

## Shell

La **shell** è il programma che interpreta i comandi. Le principali:

* **Bash** (Bourne Again Shell): la più comune su Linux/macOS.
* **PowerShell**: la shell moderna di Windows.
* **CMD**: il vecchio prompt dei comandi di Windows.
* **Zsh**: shell moderna con autocompletamento avanzato (predefinita su macOS dall'high Sierra).

## Cosa useremo

Per questo corso useremo **Bash** (o Zsh) su Linux/macOS, e **PowerShell** su Windows. I concetti sono simili, la sintassi cambia leggermente.

## Navigazione tra directory

| Comando | Descrizione |
|---------|-------------|
| `pwd` | Mostra la directory corrente |
| `ls` | Elenca i file |
| `ls -l` | Elenco dettagliato |
| `ls -a` | Mostra file nascosti |
| `cd directory` | Entra in una directory |
| `cd ..` | Directory padre |
| `cd ~` | Home directory |
| `cd /` | Directory radice (su Windows: `cd C:\`) |
| `mkdir nome` | Crea una directory |
| `rmdir nome` | Rimuove una directory vuota |

## Gestione file

| Comando | Descrizione |
|---------|-------------|
| `touch file` | Crea file vuoto o aggiorna timestamp |
| `cp src dst` | Copia file |
| `mv src dst` | Sposta/rinomina file |
| `rm file` | Elimina file |
| `rm -r dir` | Elimina directory ricorsivamente |
| `cat file` | Mostra contenuto file |
| `less file` | Visualizza file con paginazione |
| `head -n 10 file` | Prime 10 righe |
| `tail -n 10 file` | Ultime 10 righe |
| `nano file` | Editor testuale semplice |

## Wildcard (pattern matching)

Utili per operare su gruppi di file:

```bash
*.txt         # tutti i file .txt
file?.doc     # file1.doc, file2.doc, fileA.doc...
[abc]*        # file che iniziano con a, b o c
file[0-9].txt # file0.txt ... file9.txt
```

## Redirezione e pipe

### Redirezione dell'output

```bash
comando > file          # scrive output in file (sovrascrive)
comando >> file         # appende output a file
comando 2> errori.log   # redirige errori (stderr)
comando > /dev/null     # scarta l'output
```

### Pipe (`|`)

Il pipe collega l'output di un comando all'input del successivo:

```bash
ls -l | grep .c         # mostra solo file .c
cat file.txt | wc -l    # conta le righe
ps aux | grep firefox   # cerca processi firefox
```

## Comandi utili

| Comando | Descrizione |
|---------|-------------|
| `echo "testo"` | Stampa testo |
| `whoami` | Nome utente corrente |
| `date` | Data e ora |
| `ps` | Elenca processi |
| `top` / `htop` | Monitoraggio processi in tempo reale |
| `grep pattern file` | Cerca pattern in file |
| `find . -name "*.txt"` | Cerca file per nome |
| `chmod +x file` | Rende un file eseguibile |
| `sudo comando` | Esegue comando come amministratore |
| `man comando` | Manuale del comando |
| `--help` | Aiuto rapido |

## Variabili d'ambiente

```bash
echo $HOME        # directory home
echo $PATH        # directory dei comandi eseguibili
export VAR=valore # imposta una variabile
echo $VAR         # stampa la variabile
```

## Alias

Creare scorciatoie per comandi frequenti:

```bash
alias ll='ls -la'
alias gs='git status'
alias ..='cd ..'
```

## Script Bash

Uno script Bash è un file di testo con comandi eseguibili:

```bash
#!/bin/bash
# primo script
echo "Ciao, mondo!"
echo "Oggi è $(date)"
```

Esecuzione:

```bash
chmod +x script.sh
./script.sh
```

## VS Code Terminal integrato

VS Code include un terminale integrato (`` Ctrl+` ``). Puoi averne più istanze (caddy), usare split view, e scegliere tra Bash, PowerShell o altri.

!!! tip "Imparare il terminale"
    Il terminale è uno strumento potentissimo. All'inizio può sembrare ostico, ma con la pratica diventa più veloce di qualsiasi interfaccia grafica per molte operazioni (batch processing, grep, pipe, scripting).


