# 6.11 I Tipi Enumerativi (`enum`)

Oltre a `struct` e `union`, il C offre un terzo tipo definito dall'utente: l'**enumerazione** (`enum`). Un'enumerazione ci permette di definire un insieme di costanti intere con nome, rendendo il codice più leggibile e meno soggetto a errori.

## Definire un'enumerazione

La sintassi è simile a quella di `struct` e `union`:

```c
enum giorno { LUN, MAR, MER, GIO, VEN, SAB, DOM };
```

Per default, ai simboli vengono assegnati valori interi consecutivi a partire da `0`: `LUN` vale `0`, `MAR` vale `1`, e così via.

Possiamo dichiarare una variabile di tipo `enum giorno`:

```c
enum giorno oggi = MER;
```

## Valori personalizzati

Possiamo specificare esplicitamente i valori associati ai simboli:

```c
enum stato { OK = 0, ERRORE_FILE = 1, ERRORE_MEMORIA = 2, ERRORE_SCONOSCIUTO = 255 };
```

Se omettiamo un valore, il compilatore prosegue dal precedente incrementando di uno:

```c
enum note { DO = 1, RE, MI, FA, SOL, LA, SI };
// DO=1, RE=2, MI=3, FA=4, SOL=5, LA=6, SI=7
```

## Il pattern `typedef enum`

Come per le `struct`, si usa spesso `typedef` per evitare di scrivere `enum` ogni volta:

```c
typedef enum { PRIMAVERA, ESTATE, AUTUNNO, INVERNO } Stagione;

Stagione s = ESTATE;
```

## Usare gli `enum` nello `switch`

Gli `enum` sono particolarmente utili con il costrutto `switch`, perché i nomi simbolici rendono il codice auto-documentante:

```c
typedef enum { ADDIZIONE, SOTTRAZIONE, MOLTIPLICAZIONE, DIVISIONE } Operazione;

void applica(Operazione op, int a, int b) {
    switch (op) {
        case ADDIZIONE:
            printf("%d\n", a + b);
            break;
        case SOTTRAZIONE:
            printf("%d\n", a - b);
            break;
        case MOLTIPLICAZIONE:
            printf("%d\n", a * b);
            break;
        case DIVISIONE:
            if (b != 0) printf("%d\n", a / b);
            break;
    }
}
```

!!! tip "Gli `enum` non sono type-safe in C"
    In C, un `enum` è di fatto un intero: possiamo assegnare un valore intero arbitrario a una variabile `enum` senza che il compilatore emetta warning. Per un controllo più stretto, linguaggi come C++ offrono `enum class`, ma in C questa flessibilità va gestita con disciplina.

## Esempio: giorni della settimana

```c
#include <stdio.h>

typedef enum { LUN = 1, MAR, MER, GIO, VEN, SAB, DOM } Giorno;

const char* nome_giorno(Giorno g) {
    switch (g) {
        case LUN: return "Lunedi";
        case MAR: return "Martedi";
        case MER: return "Mercoledi";
        case GIO: return "Giovedi";
        case VEN: return "Venerdi";
        case SAB: return "Sabato";
        case DOM: return "Domenica";
        default: return "Sconosciuto";
    }
}

int main() {
    for (Giorno g = LUN; g <= DOM; g++) {
        printf("%d -> %s\n", g, nome_giorno(g));
    }
    return 0;
}
```


