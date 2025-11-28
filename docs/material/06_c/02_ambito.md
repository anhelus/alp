

## 2. Visibilità e Ciclo di Vita delle Variabili

Una volta compreso dove "vive" fisicamente il codice, dobbiamo capire dove "vivono" logicamente i dati. Questo ci porta ai concetti di ambito e tempo di vita di una variabile.

### 2.1 Ambito di Visibilità (Scope)

L'ambito definisce la regione di un programma in cui un identificatore (come il nome di una variabile) è visibile e può essere utilizzato.

*   **Ambito Locale**: Una variabile dichiarata all'interno di un blocco di codice (delimitato da parentesi graffe `{}`) ha un ambito locale. È visibile e accessibile **solo** all'interno di quel blocco e di eventuali blocchi annidati. Ad esempio, una variabile definita in una funzione non può essere vista o usata da un'altra funzione.

*   **Ambito Globale**: Una variabile dichiarata al di fuori di qualsiasi funzione ha un ambito globale. È visibile e accessibile da **qualsiasi punto** del programma (in tutti i file sorgente, se opportunamente dichiarata). Sebbene utili in alcuni scenari, le variabili globali sono spesso considerate una cattiva pratica perché rendono il codice più difficile da comprendere e possono generare effetti collaterali inaspettati.

### 2.2 Il Tempo di Vita (Lifetime)

Mentre l'ambito è un concetto "spaziale" (dove una variabile è visibile), il tempo di vita è un concetto "temporale" (per quanto tempo una variabile esiste in memoria).

*   **Variabili Automatiche**: Per impostazione predefinita, le variabili locali sono **automatiche**. Vengono create in memoria quando il programma entra nel loro ambito e vengono distrutte non appena l'esecuzione esce da quell'ambito. Questo significa che ad ogni chiamata di una funzione, le sue variabili locali vengono create da capo, perdendo il valore che avevano nella chiamata precedente.

    ```c
    int incrementa() {
        int contatore = 0; // Questa variabile è automatica
        contatore++;
        return contatore;
    }
    // Ogni chiamata a incrementa() restituirà sempre 1.
    ```

*   **Variabili Statiche**: Se si desidera che una variabile locale **mantenga il suo valore tra le chiamate di una funzione**, è possibile dichiararla con la keyword `static`. Una variabile statica locale viene inizializzata solo una volta (la prima volta che la funzione viene chiamata) e il suo tempo di vita si estende per l'intera durata del programma.

    ```c
    int incrementa_statico() {
        static int contatore = 0; // Questa variabile è statica
        contatore++;
        return contatore;
    }
    // Chiamate successive a incrementa_statico() restituiranno 1, 2, 3, ...
    ```