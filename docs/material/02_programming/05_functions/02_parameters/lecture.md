# 2.5.2 Parametri Formali e Attuali

Quando definiamo una funzione, dobbiamo stabilire quali dati riceve in ingresso e come li utilizza. I concetti di **parametro formale** e **parametro attuale** ci permettono di distinguere tra la definizione astratta della funzione e la sua chiamata concreta.

## Parametri Formali

I **parametri formali** sono le variabili definite nell'intestazione della funzione. Fungono da "segnaposto": specificano *cosa* la funzione si aspetta di ricevere, senza indicare *quale* valore concreto.

```
function calcolaAreaRettangolo(base, altezza)
    return base * altezza
endfunction
```

Qui `base` e `altezza` sono parametri formali. La funzione dichiara di aver bisogno di due valori per funzionare, chiamandoli internamente `base` e `altezza`.

## Parametri Attuali

I **parametri attuali** sono i valori *effettivi* che passiamo alla funzione quando la chiamiamo:

```
larghezza = 5
lunghezza = 3
area = calcolaAreaRettangolo(larghezza, lunghezza)
```

In questo caso, `larghezza` (con valore 5) e `lunghezza` (con valore 3) sono i parametri attuali. All'atto della chiamata:

* il valore di `larghezza` (5) viene copiato nel parametro formale `base`;
* il valore di `lunghezza` (3) viene copiato nel parametro formale `altezza`.

## Corrispondenza

L'ordine dei parametri attuali deve corrispondere all'ordine dei parametri formali:

```
function dividi(dividendo, divisore)
    return dividendo / divisore
endfunction

dividi(10, 2)    // corretto: 10 / 2 = 5
dividi(2, 10)    // SBAGLIATO: 2 / 10 = 0.2 (logica diversa!)
```

I nomi, invece, **non devono per forza coincidere**: l'importante è la posizione.

## Passaggio per valore vs riferimento

Nella maggior parte dei linguaggi (C, Java, Python), il passaggio avviene **per valore**: la funzione riceve una copia del parametro attuale. Modificare il parametro formale all'interno della funzione **non** modifica la variabile originale:

```
function raddoppia(x)
    x = x * 2     // modifica solo la copia
    return x
endfunction

n = 5
risultato = raddoppia(n)
// n vale ancora 5, risultato vale 10
```

In alcuni linguaggi (o tramite puntatori, come in C), è possibile il passaggio **per riferimento**, dove la funzione opera direttamente sulla variabile originale.

## Tabella riassuntiva

| Caratteristica | Parametri Formali | Parametri Attuali |
|----------------|-------------------|-------------------|
| Dove si trovano | Nella definizione della funzione | Nella chiamata alla funzione |
| Cosa sono | Segnaposto per i valori attesi | I valori effettivi passati |
| Scopo | Definire come la funzione userà i dati | Fornire i dati specifici su cui lavorare |
| Esempio | `function f(x, y)` | `f(valore1, valore2)` |

!!! tip "Analogia con una ricetta"
    La **funzione** è la ricetta. I **parametri formali** sono gli ingredienti elencati nella ricetta ("farina", "uova"). I **parametri attuali** sono gli ingredienti veri che mettete nella ciotola (200 g di farina, 3 uova). La ricetta dice cosa fare con gli ingredienti, indipendentemente dalle quantità specifiche.

