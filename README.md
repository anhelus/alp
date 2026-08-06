# Corso di Informatica

Materiale didattico per il corso di Informatica.

## Installazione e Configurazione di VS Code per lo sviluppo in C

### Il ruolo di Visual Studio Code

*Visual Studio Code* (VS Code) è un *Integrated Development Environment* (IDE) che, per una precisa scelta di design, mantiene una struttura "leggera", non includendo nativamente componenti legati alla compilazione ed al debugging in molteplici linguaggi di programmazione. In altri termini, VS Code è una sorta di "blocco note evoluto", fungendo primariamente da editor di codice "potenziato", ed affidandosi interamente ad estensioni e strumenti esterni per lo sviluppo ed il test del codice.

Questo implica che l'installazione di VS Code sulla nostra macchina sia soltanto il primo passo: lo sviluppo in linguaggio C richiede l'installazione della *toolchain*, composta da un *compilatore* e da un *debugger* sul sistema operativo. La corretta configurazione avviene quando VS Code viene istruito su come invocare questi strumenti esterni e, per farlo, occorre manipolare un file di configurazione.

### Installazione di Visual Studio Code e dell'estensione C/C++

Iniziamo scaricando l'editor all'indirizzo https://code.visualstudio.com/. Dopo averlo installato, dovremo ottenere l'estensione che fornisce il supporto al linguaggio C/C++, chiamata **Estensione C/C++ di Microsoft**. Per farlo:

* accedere alla finestra *Estensioni*, selezionando l'icona dalla barra di Attività, oppure usando la scorciatoia da tastiera `Ctrl+Shift+X`;
* cercare il termine `C++` e selezionare l'estensione opportuna.

![Estensioni](docs/material/new/appendix/images/img_01.png)

![Estensione C/C++](docs/material/new/appendix/images/img_02.png)

Le funzionalità primarie fornite dall'estensione includono:

* **IntelliSense**: funzionalità che permette di completare il codice in maniera intelligente, dando informazioni interattive al programmatore, e verificando in rosso gli errori in tempo reale;
* **Supporto al debugger**: funzionalità che abilita l'interfaccia di debug di VS Code, che comunica con il debugger esterno configurato nel sistema.

!!!note ""
    L'estensione C/C++ **non installa il compilatore o il debugger**. Il suo funzionamento dipende dalla capacità di VS Code di localizzare ed eseguire la toolchain già installata nel sistema.

### Installazione della Toolchain

La configurazione della toolchain è un processo dipendente dal sistema operativo. Questa guida si focalizzerà **esclusivamente su Windows**.

La toolchain raccomandata per lo sviluppo è MinGW-w64, installabile mediante MSYS2. Per installarla:

1. **Installazione di MSYS2**: dall'indirizzo https://www.msys2.org/, scarichiamo ed eseguiamo l'installer di MSYS2. Utilizziamo le opzioni di default e lasciamo selezionata la casella *Run MSYS2 now* al termine dell'installazione, in modo da aprire la finestra del terminale MSYS2.
2. **Installazione dei pacchetti GCC/GDB**: all'interno del terminale, eseguiamo il seguente comando per installare la toolchain C/C++ completa:

```sh
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
```

![MSYS2](docs/material/new/appendix/images/img_03.png)

### Configurazione delle variabili d'ambiente

Il punto critico è la configurazione delle variabili d'ambiente, ed in particolare del `PATH`, che permette a VS Code di "ritrovare" la toolchain.

1. **Identifichiamo il percorso di installazione della toolchain**. Con le configurazioni predefinite, il percorso da aggiungere sarà `C:\msys64\ucrt64\bin`.
2. **Modifichiamo la variabile PATH**. Apriamo la barra di ricerca di Windows, cerchiamo "Modifica variabili d'ambiente per il tuo account" e, nella sezione "Variabili utente", selezioniamo e modifichiamo la variabile `PATH`, aggiungendo il percorso identificato al punto 1.

![Variabili d'ambiente](docs/material/new/appendix/images/img_04.png)

3. Dopo aver modificato il `PATH`, riavviamo ogni terminale aperto, incluso quello di VS Code.
4. Testiamo la presenza dei binari in PowerShell:

```sh
gcc --version
g++ --version
gdb --version
```

Se non abbiamo errori, la configurazione è avvenuta con successo.

### Configurazione del workspace

Una volta installata la toolchain esterna, bisogna configurare VS Code affinché la utilizzi. La configurazione specifica per un progetto viene salvata in una cartella nascosta `.vscode` all'interno della cartella dello stesso, contenente almeno un file JSON fondamentale: `tasks.json`.

Non dovremo creare questo file a mano: invece, avviamo VS Code, creiamo un nuovo progetto all'interno di una cartella (che potremo chiamare `helloworld`), e quindi creiamo un nuovo file sorgente (`helloworld.c`). Inseriamo il seguente codice:

```c
#include <stdio.h>

int main() {
    printf("Hello, World");
    return 0;
}
```

![Progetto](docs/material/new/appendix/images/img_05.png)

A questo punto, selezioniamo il pulsante di Debug (la piccola freccia in alto a destra). Scegliamo la prima opzione e premiamo **Invio**.

![Selezione compilatore](docs/material/new/appendix/images/img_06.png)

VS Code creerà in automatico la cartella `.vscode` con il file `tasks.json`. Se tutto è andato per il verso giusto, vedremo nel terminale:

![Risultato](docs/material/new/appendix/images/img_07.png)

Se viene lanciato qualche errore, dovremo fare un passo indietro e ripetere gli step precedenti. A questo punto, VS Code è configurato per lo sviluppo in C!