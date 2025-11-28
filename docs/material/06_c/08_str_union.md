Ottimo, siamo all'ultimo set. Queste slide affrontano i tipi di dati definiti dall'utente, un passo fondamentale per passare dalla programmazione procedurale a quella basata su strutture dati complesse. La progressione da `typedef` a `struct` e infine a `union` è molto logica.

Come per i set precedenti, ci sono un paio di **imprecisioni critiche** che è fondamentale correggere per evitare che gli studenti imparino pattern di codice errati o concetti fuorvianti.

---

### **Valutazione Generale**

*   **Punti di Forza:**
    *   **Struttura Didattica:** La lezione è costruita in modo eccellente. Introdurre `typedef` come concetto generale e poi mostrare la sua vera potenza in combinazione con `struct` è il modo giusto di procedere.
    *   **Esempi Chiari:** Gli esempi dello `studente` e della `lettura_sensore` sono semplici, pertinenti e facili da capire.
    *   **Copertura Completa:** Le slide coprono tutti gli aspetti fondamentali: definizione, istanziazione, accesso ai membri (con `.` e `->`) e l'uso di `typedef`.

*   **Aree di Miglioramento (Critiche):**
    *   **Errore nel Codice:** C'è un esempio di codice che non è C valido e non compilerà, relativo all'assegnazione di stringhe.
    *   **Spiegazione Concettuale Incompleta:** La spiegazione del funzionamento interno di una `union` è troppo superficiale e omette il concetto chiave che la differenzia da una `struct` (la memoria condivisa).

---

### **Correzioni Critiche e Suggerimenti**

#### **Slide 3: Usare le struct in C (2)**

*   **Suggerimento (Prevenire un Errore Comune):** L'esempio di inizializzazione designata è ottimo e moderno. Tuttavia, uno studente potrebbe vedere `.nome = "Caio"` e pensare di poter usare l'operatore `=` per assegnare stringhe anche dopo l'inizializzazione (es. `tizio.nome = "Pluto";`).
*   **Aggiunta Consigliata:** Potresti aggiungere una piccola nota per prevenire questa confusione: "**Nota:** l'assegnazione di una stringa con `=` funziona solo in fase di inizializzazione. Per modificare un nome o cognome in un secondo momento, è necessario usare funzioni apposite come `strcpy` dalla libreria `<string.h>`."

#### **Slide 5: Usare le struct in C (4)**

*   **Errore Fattuale Grave:** L'esempio di codice in questa slide è **errato** e non compilerà.
    ```c
    char nome_estratto[32] = tp->nome; // ERRORE!
    ```
    In C, **non è possibile inizializzare o assegnare un array copiandone un altro** con l'operatore `=`. `tp->nome` è un array (`char[32]`), e non può essere usato per inizializzare `nome_estratto` in questo modo.
*   **Correzione Necessaria:** La maniera corretta per copiare il contenuto di una stringa (o di un array di char) in un altro è usare la funzione `strcpy` (o la sua variante più sicura `strncpy`).
*   **Esempio di Codice Corretto:**
    ```c
    // È necessario includere <string.h>
    #include <string.h>

    char nome_estratto[32];
    strcpy(nome_estratto, tp->nome); // Copia la stringa da tp->nome a nome_estratto
    ```
    Questa è una correzione fondamentale perché tocca la gestione di uno dei tipi di dato più comuni all'interno delle `struct`: le stringhe.

#### **Slide 6: Usare le union in C**

*   **Spiegazione Concettuale Incompleta e Critica:** La slide dice correttamente che la sintassi è analoga e che le `union` si usano per "diverse rappresentazioni possibili". Tuttavia, omette la spiegazione del **"come" e del "perché"** questo sia possibile, che è il concetto chiave.
*   **Concetto Mancante: La Memoria Condivisa.** A differenza di una `struct`, dove ogni membro ha la sua area di memoria dedicata, **tutti i membri di una `union` condividono la stessa identica area di memoria**. La dimensione della `union` è determinata dalla dimensione del suo membro più grande. Questo significa che puoi scrivere in un membro (es. `lettura_intera`) e leggere da un altro (`lettura_reale`), di fatto reinterpretando la stessa sequenza di bit in un modo diverso.
*   **Testo Suggerito da Aggiungere:** "A differenza di una `struct`, tutti i membri di una `union` **condividono la stessa area di memoria**. La dimensione della `union` è pari a quella del suo membro più grande. Questo permette di memorizzare un solo valore alla volta, ma di interpretarlo in modi diversi a seconda del membro a cui si accede."

### **Riepilogo delle Correzioni Urgenti**

1.  **Slide 5:** Sostituire l'esempio di assegnazione dell'array `char nome_estratto[32] = tp->nome;` con la versione corretta che usa `strcpy(nome_estratto, tp->nome);`.
2.  **Slide 6:** Aggiungere la spiegazione fondamentale che i membri di una `union` **condividono la stessa memoria**, specificando che la sua dimensione è quella del membro più grande.

Con queste correzioni, il tuo set di slide sarà tecnicamente ineccepibile e fornirà agli studenti una comprensione molto più profonda e corretta di come funzionano queste importanti strutture dati.

---

## Versione Narrativa e Esercizi Svolti

Ecco una versione narrativa delle slide, ideale per un testo più discorsivo, seguita da un'implementazione degli esercizi.

### Creare Tipi di Dati Personalizzati in C: `typedef`, `struct` e `union`

Fino ad ora abbiamo lavorato con i tipi di dato primitivi del C: interi, caratteri, numeri in virgola mobile. Sebbene siano fondamentali, sono spesso insufficienti per modellare le entità del mondo reale in modo efficace. Fortunatamente, il C ci fornisce degli strumenti potenti per definire i nostri tipi di dato personalizzati.

#### 1. Creare Alias con `typedef`

La parola chiave `typedef` ci permette di creare un **alias**, ovvero un nuovo nome, per un tipo di dato esistente. La sua utilità principale è quella di migliorare la leggibilità e la manutenibilità del codice, specialmente con tipi complessi.

La sua sintassi è: `typedef tipo_esistente nuovo_nome;`

Ad esempio, invece di scrivere `int*` ogni volta che ci serve un puntatore a un intero, potremmo definire un alias:
```c
typedef int* PuntatoreAIntero;

int a = 10;
PuntatoreAIntero p = &a; // 'p' è di tipo int*
```

#### 2. Aggregare Dati Eterogenei con `struct`

La vera potenza emerge quando vogliamo raggruppare dati di tipo diverso in un'unica entità logica. Per questo scopo, il C ci offre la `struct`. Una `struct` è un "contenitore" che ci permette di definire un nuovo tipo composto da un insieme di variabili (chiamate **membri** o **campi**).

Ad esempio, per rappresentare uno studente, potremmo aver bisogno del suo nome, cognome e numero di matricola. Una `struct` è perfetta per questo:
```c
struct studente {
    char nome[32];
    char cognome[32];
    int matricola;
};
```
Per creare una variabile (un'**istanza**) di questo tipo, scriviamo `struct studente tizio;`.

Per accedere ai singoli membri di un'istanza, usiamo l'**operatore punto (`.`)**:
```c
struct studente caio = {
    .nome = "Caio",
    .cognome = "De Caius",
    .matricola = 123456
};

printf("Matricola di Caio: %d\n", caio.matricola);
```

##### Il pattern `typedef struct`

Per evitare di dover scrivere `struct studente` ogni volta, è prassi comune combinare `struct` e `typedef` in un unico blocco. Questo definisce la struttura e contemporaneamente crea un alias più conciso.

```c
typedef struct {
    char nome[32];
    char cognome[32];
    int matricola;
} Studente; // 'Studente' è ora un alias per l'intera definizione della struct

// Ora possiamo dichiarare le variabili in modo più pulito:
Studente tizio;
Studente caio;
```

##### Puntatori a `struct` e l'Operatore Freccia (`->`)

È molto comune lavorare con puntatori a `struct`, specialmente quando le si passa alle funzioni. Per accedere ai membri di una `struct` tramite un puntatore, si usa l'**operatore freccia (`->`)**. Questo operatore è una scorciatoia sintattica per l'espressione `(*puntatore).membro`.

```c
#include <string.h> // Per strcpy

Studente tizio = {"Tizio", "Tizi", 78910};
Studente* puntatore_a_tizio = &tizio;

char nome_estratto[32];
// Copiamo il nome usando l'operatore freccia
strcpy(nome_estratto, puntatore_a_tizio->nome);

printf("Nome estratto tramite puntatore: %s\n", nome_estratto);
printf("Matricola: %d\n", puntatore_a_tizio->matricola);
```

#### 3. Interpretazioni Multiple con `union`

Una `union` è sintatticamente simile a una `struct`, ma il suo comportamento interno è radicalmente diverso. A differenza di una `struct`, dove ogni membro occupa una propria area di memoria, **tutti i membri di una `union` condividono la stessa identica area di memoria**.

La dimensione totale della `union` è pari alla dimensione del suo membro più grande. Questo ha due implicazioni principali:
1.  Una `union` può contenere il valore di **un solo membro alla volta**.
2.  Permette di interpretare la stessa sequenza di bit in modi diversi, a seconda del membro che si utilizza per leggere i dati.

È utile quando una variabile può rappresentare diversi tipi di dati, ma mai contemporaneamente. Ad esempio, una lettura da un sensore potrebbe essere un valore intero (conteggio di impulsi) o un valore reale (temperatura).

```c
typedef union {
    long lettura_intera;
    double lettura_reale;
} LetturaSensore;

LetturaSensore lettura;

lettura.lettura_intera = 1500;
printf("Lettura come intero: %ld\n", lettura.lettura_intera);

// Ora scriviamo nello stesso spazio di memoria, ma come double
lettura.lettura_reale = 36.6;
printf("Lettura come reale: %f\n", lettura.lettura_reale);

// Se provassimo a leggere il membro 'lettura_intera' ora, otterremmo dati senza senso,
// perché i bit sono stati sovrascritti con la rappresentazione di un double.
```

---

### Esercizi Svolti

Ecco un programma completo che implementa i concetti di `struct` e `union`.

```c
#include <stdio.h>
#include <string.h>

// ESERCIZIO 1: Definire e utilizzare una struct Studente

// Definiamo il tipo 'Studente' usando il pattern typedef struct
typedef struct {
    char nome[50];
    char cognome[50];
    int matricola;
    float media_voti;
} Studente;

// Funzione che stampa i dati di uno studente.
// Accetta un puntatore costante a Studente per efficienza e sicurezza.
void stampa_studente(const Studente* s) {
    printf("--- Scheda Studente ---\n");
    printf("Nome:      %s\n", s->nome);
    printf("Cognome:   %s\n", s->cognome);
    printf("Matricola: %d\n", s->matricola);
    printf("Media:     %.2f\n", s->media_voti);
    printf("-----------------------\n\n");
}


// ESERCIZIO 2: Definire e utilizzare una union LetturaSensore

// Definiamo il tipo 'Dato'
typedef union {
    long valore_intero;
    double valore_reale;
    char stato_sensore; // Aggiungiamo un terzo tipo
} Dato;

// Per tenere traccia di quale tipo è attualmente memorizzato nella union,
// usiamo una struct che combina la union con un "tag" di tipo.
typedef enum { INTERO, REALE, STATO } TipoDato;

typedef struct {
    TipoDato tipo;
    Dato dato;
} LetturaSensore;

// Funzione che stampa una lettura, interpretandola correttamente
void stampa_lettura(const LetturaSensore* lettura) {
    printf("--- Lettura Sensore ---\n");
    switch (lettura->tipo) {
        case INTERO:
            printf("Tipo: Conteggio, Valore: %ld\n", lettura->dato.valore_intero);
            break;
        case REALE:
            printf("Tipo: Temperatura, Valore: %.2f C\n", lettura->dato.valore_reale);
            break;
        case STATO:
            printf("Tipo: Stato, Valore: '%c'\n", lettura->dato.stato_sensore);
            break;
    }
    printf("-----------------------\n\n");
}


int main() {
    printf("=== ESERCIZIO STRUCT ===\n");
    
    // Creiamo e inizializziamo un'istanza di Studente
    Studente studente1;
    strcpy(studente1.nome, "Mario");
    strcpy(studente1.cognome, "Rossi");
    studente1.matricola = 12345;
    studente1.media_voti = 28.5f;

    // Passiamo l'indirizzo della struct alla funzione di stampa
    stampa_studente(&studente1);

    printf("\n=== ESERCIZIO UNION ===\n");

    // Creiamo tre diverse letture
    LetturaSensore lettura1, lettura2, lettura3;

    // Prima lettura: un intero
    lettura1.tipo = INTERO;
    lettura1.dato.valore_intero = 500;
    stampa_lettura(&lettura1);

    // Seconda lettura: un reale
    lettura2.tipo = REALE;
    lettura2.dato.valore_reale = 25.7;
    stampa_lettura(&lettura2);

    // Terza lettura: uno stato (char)
    lettura3.tipo = STATO;
    lettura3.dato.stato_sensore = 'A'; // 'A' per Attivo
    stampa_lettura(&lettura3);

    return 0;
}
```