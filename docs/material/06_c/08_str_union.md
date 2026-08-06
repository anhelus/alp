# 6.9 Struct e Union

Fino ad ora abbiamo lavorato con i tipi di dato primitivi del C: interi, caratteri, numeri in virgola mobile. Sebbene siano fondamentali, sono spesso insufficienti per modellare le entità del mondo reale in modo efficace. Fortunatamente, il C ci fornisce degli strumenti potenti per definire i nostri tipi di dato personalizzati.

## Creare Alias con `typedef`

La parola chiave `typedef` ci permette di creare un **alias**, ovvero un nuovo nome, per un tipo di dato esistente. La sua utilità principale è quella di migliorare la leggibilità e la manutenibilità del codice, specialmente con tipi complessi.

La sua sintassi è: `typedef tipo_esistente nuovo_nome;`

Ad esempio, invece di scrivere `int*` ogni volta che ci serve un puntatore a un intero, potremmo definire un alias:
```c
typedef int* PuntatoreAIntero;

int a = 10;
PuntatoreAIntero p = &a; // 'p' è di tipo int*
```

## Aggregare Dati Eterogenei con `struct`

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

### Il pattern `typedef struct`

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

### Puntatori a `struct` e l'Operatore Freccia (`->`)

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

## Interpretazioni Multiple con `union`

!!! info "Memoria condivisa nelle `union`"
    A differenza di una `struct`, dove ogni membro occupa una propria area di memoria, **tutti i membri di una `union` condividono la stessa identica area di memoria**. La dimensione totale della `union` è pari alla dimensione del suo membro più grande. Questo significa che una `union` può contenere il valore di **un solo membro alla volta**, ma permette di interpretare la stessa sequenza di bit in modi diversi.

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

## Esercizi Svolti

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


