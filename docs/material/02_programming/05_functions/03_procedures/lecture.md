# 2.5.3 Funzioni e Procedure

Nella programmazione strutturata, suddividiamo il codice in blocchi logici riutilizzabili. Questi blocchi si distinguono in due categorie principali: **funzioni** e **procedure**.

## L'idea chiave: output o no output?

La differenza fondamentale sta nel fatto che una funzione **restituisce un valore** (un output), mentre una procedura **esegue un'azione** senza restituire un risultato.

### Funzione

Una funzione è un blocco di codice che:

* riceve zero o più **parametri** in ingresso;
* elabora i dati;
* **restituisce un risultato** (un singolo valore).

Pensiamo a una calcolatrice: inseriamo due numeri, premiamo `+`, e la calcolatrice ci restituisce la somma.

```
function somma(a, b)
    return a + b
endfunction
```

### Procedura

Una procedura (o *subroutine*) è un blocco di codice che:

* riceve zero o più **parametri** in ingresso;
* **esegue una serie di azioni**;
* **non restituisce alcun valore**.

Pensiamo a un robot aspirapolvere: lo programmiamo per pulire, esegue l'azione, ma non ci restituisce un valore specifico.

```
procedure stampaSaluto(nome)
    write("Ciao, " + nome + "!")
    write("Benvenuto!")
endprocedure
```

## Esempi concreti

### Una funzione: calcolare l'area

```
function areaCerchio(raggio)
    return 3.14159 * raggio * raggio
endfunction
```

Uso: `risultato = areaCerchio(5)` assegna il valore calcolato a `risultato`.

### Una procedura: stampare un menu

```
procedure stampaMenu()
    write("1. Inserisci dato")
    write("2. Visualizza risultato")
    write("3. Esci")
endprocedure
```

Uso: `stampaMenu()` mostra il menu a schermo, senza restituire nulla.

## Effetti collaterali

Una **funzione pura** si limita a calcolare il risultato a partire dagli input, senza modificare lo stato esterno. Una **procedura**, invece, spesso ha **effetti collaterali**: stampa a schermo, scrive su file, modifica variabili globali.

Nella pratica, molti linguaggi (C incluso) non fanno una distinzione sintattica netta: in C, tutto è "funzione", ma una funzione con tipo di ritorno `void` si comporta di fatto come una procedura.

## Tabella riassuntiva

| Caratteristica | Funzione | Procedura |
|----------------|----------|-----------|
| Restituisce un valore? | Sì (con `return`) | No |
| Scopo principale | Calcolare e restituire un risultato | Eseguire un'azione |
| Effetti collaterali | Idealmente assenti | Spesso presenti |
| Esempio | `max = calcolaMassimo(a, b)` | `stampaMessaggio("Errore")` |
| In C | Con tipo di ritorno diverso da `void` | Con tipo di ritorno `void` |

!!! note "Nel resto del corso"
    D'ora in poi useremo il termine **funzione** in senso generico per indicare entrambi i tipi di sottoprogrammi, specificando quando necessario se si tratta di una funzione in senso stretto o di una procedura.

