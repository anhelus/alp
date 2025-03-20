# Parametri formali ed attuali

Certamente, cercherò di spiegare i parametri formali e attuali in modo chiaro e adatto a studenti del primo anno, usando un esempio in MATLAB.

**Concetti chiave: Funzioni e Parametri**

Prima di parlare di parametri formali e attuali, è importante capire cosa sono le funzioni e perché usiamo i parametri.

*   **Funzione:** Immagina una funzione come una piccola "macchina" che prende degli "ingredienti" (dati), li elabora e produce un "risultato".  Le funzioni ci permettono di organizzare il codice, renderlo più leggibile e riutilizzabile. Invece di riscrivere lo stesso blocco di codice più volte, lo mettiamo in una funzione e la chiamiamo quando serve.
*   **Parametri:**  I parametri sono come gli "ingredienti" che passiamo alla "macchina-funzione".  Servono per far sapere alla funzione quali dati deve usare per svolgere il suo compito.

**Parametri Formali (o Argomenti Formali)**

*   **Definizione:** I parametri formali sono le variabili che vengono *definite* all'interno della definizione della funzione.  Sono dei "segnaposto" che indicano cosa la funzione si aspetta di ricevere quando viene chiamata.  Immaginali come i nomi degli ingredienti scritti sulla ricetta (es. "farina", "uova", "zucchero").
*   **Scopo:** Servono a definire come la funzione userà i dati che riceverà.  All'interno del corpo della funzione, usiamo i nomi dei parametri formali per riferirci ai valori che verranno passati.
*   **Esempio (MATLAB):**

    ```matlab
    function area = calcolaAreaRettangolo(base, altezza)
        % Questa funzione calcola l'area di un rettangolo.
        % base e altezza sono i parametri formali.

        area = base * altezza;
    end
    ```

    In questo esempio, `base` e `altezza` sono i parametri formali della funzione `calcolaAreaRettangolo`.  La funzione si aspetta di ricevere due valori numerici, che internamente chiamerà `base` e `altezza`, e li userà per calcolare l'area.

**Parametri Attuali (o Argomenti Attuali)**

*   **Definizione:** I parametri attuali sono i valori *effettivi* che vengono passati alla funzione quando la si chiama (cioè quando la si "usa"). Sono gli ingredienti *veri* che mettiamo nella "macchina-funzione".
*   **Scopo:** Forniscono alla funzione i dati specifici su cui deve lavorare.
*   **Esempio (MATLAB):**

    ```matlab
    lunghezza = 5;
    larghezza = 3;

    areaRettangolo = calcolaAreaRettangolo(lunghezza, larghezza);
    % lunghezza e larghezza sono i parametri attuali.

    disp(['L''area del rettangolo è: ', num2str(areaRettangolo)]);
    ```

    In questo esempio, `lunghezza` (con valore 5) e `larghezza` (con valore 3) sono i parametri attuali.  Quando chiamiamo `calcolaAreaRettangolo(lunghezza, larghezza)`, il valore di `lunghezza` (5) viene passato al parametro formale `base`, e il valore di `larghezza` (3) viene passato al parametro formale `altezza`.  La funzione esegue i calcoli usando questi valori specifici.

**Riassumendo in una Tabella:**

| Caratteristica      | Parametri Formali                                      | Parametri Attuali                                            |
| -------------------- | ------------------------------------------------------ | ------------------------------------------------------------ |
| Dove si trovano     | Nella definizione della funzione                         | Nella chiamata alla funzione                                 |
| Cosa sono            | Segnaposto per i valori che la funzione riceverà       | I valori effettivi che vengono passati alla funzione         |
| Scopo                | Definire come la funzione userà i dati                 | Fornire alla funzione i dati specifici su cui lavorare        |
| Esempio (MATLAB)    | `function miaFunzione(parametro1, parametro2)`       | `miaFunzione(valore1, valore2)`                             |

**Analogia con una Ricetta:**

*   **Ricetta:** La funzione
*   **Ingredienti elencati nella ricetta (es. "farina", "uova"):** Parametri Formali
*   **Ingredienti che usi effettivamente per cucinare (es. 200g di farina, 3 uova):** Parametri Attuali

**Punti importanti da ricordare:**

*   **Corrispondenza:** L'ordine dei parametri attuali deve corrispondere all'ordine dei parametri formali nella definizione della funzione.  Se la funzione si aspetta `(base, altezza)`, devi passare i valori in quell'ordine: `calcolaArea(5, 3)` è corretto, `calcolaArea(3, 5)` darebbe un risultato diverso (e potenzialmente inatteso).
*   **Nomi diversi:** I nomi dei parametri attuali e formali *non* devono necessariamente essere gli stessi.  Nell'esempio, abbiamo usato `lunghezza` e `larghezza` come parametri attuali e `base` e `altezza` come parametri formali.  L'importante è che i *valori* vengano passati correttamente.
*   **Tipi di dati:**  Idealmente, i tipi di dati dei parametri attuali dovrebbero essere compatibili con i tipi di dati che la funzione si aspetta (anche se MATLAB è meno rigido di altri linguaggi in questo).  Se la funzione si aspetta un numero, dovresti passare un numero, non una stringa di testo.

Spero che questa spiegazione e l'esempio in MATLAB ti siano utili! Se hai altre domande, non esitare a chiedere.
