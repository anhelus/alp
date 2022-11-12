# E17 - Operatori nel linguaggio C

## Esercizio E17.1

Scriviamo un programma che calcoli il quadrato di un numero.

### Soluzione S17.1

```c
#include <stdio.h>

int quadrato(int n) {
    return n * n;           // Analogamente potremmo scrivere n ^ 2
}

int main() {
    int l = 3;
    int q = quadrato(l);
    printf("Il quadrato di %d è %d\n", l, q);
    return 0;
}
```

## Esercizio E17.2

Scriviamo un programma che determini se un numero è pari. In tal senso, utilizzare l'operatore di confronto `==` per confrontare due variabili.

### Soluzione S17.2

Ecco una possibile soluzione:

```c
#include <stdio.h>

int numero_pari(int n) {
    if (n % 2 == 0) {
        return 1;
    }
    return 0;
}

void scrivi_pari_o_dispari(int numero, int pari_dispari) {
    if (pari_dispari == 0) {
        printf("Il valore %d è dispari", numero);
    } else if (pari_dispari == 1) {
        printf("Il valore %d è pari", numero);
    } else {
        printf("C'è stato un errore. Riprovare.");
    }
}

int main() {
    int a = 4;
    int b = 5;

    scrivi_pari_o_dispari(a, numero_pari(a));
    scrivi_pari_o_dispari(b, numero_pari(b));

    return 0;
}
```

Alcune note:

* nella funzione `numero_pari` valutiamo un numero come pari se e solo se il resto della divisione dello stesso per due è pari a 0;
* nella funzione `scrivi_pari_o_dispari` prendiamo il valore in uscita dalla funzione `numero_pari` e lo usiamo per scrivere a schermo se siamo la condizione di parità è rispettata.

## Esercizio E17.3

Scriviamo un programma che confronti due intervalli di valori $[a, b]$ e $[c, d]$, con $a$, $b$, $c$ e $d$ numeri interi. Il programma deve stampare a schermo il maggiore tra gli estremi inferiori $a$ e $c$, il minore tra gli estremi superiori $b$ e $d$, e stabilire se il numero di elementi presenti nei due intervalli è lo stesso.

### Soluzione S17.3

Ecco una possibile soluzione:

```c
#include <stdio.h>

void compara_estremi_inferiori(int a, int c) {
    if (a < c) {
        printf("L'estremo inferiore di valore minore è %d\n", a);
    } else if (a > c) {
        printf("L'estremo inferiore di valore minore è %d\n", c);
    } else {
        printf("I due estremi inferiori hanno lo stesso valore\n");
    }
}

void compara_estremi_superiori(int b, int d) {
    if (b < d) {
        printf("L'estremo superiore di valore maggiore è %d\n", d);
    } else if (b > d) {
        printf("L'estremo superiore di valore maggiore è %d\n", b);
    } else {
        printf("I due estremi superiori hanno lo stesso valore\n");
    }
}

void compara_intervalli(int a, int b, int c, int d) {
    int els_ac = c - a;
    int els_bd = d - b;
    if (els_ac > els_bd) {
        printf("L'intervallo [%d, %d] ha più elementi dell'intervallo [%d, %d]", a, c, b, d);
    } else if (els_ac < els_bd) {
        printf("L'intervallo [%d, %d] ha più elementi dell'intervallo [%d, %d]", b, d, a, c);
    } else {
        printf("I due intervalli hanno lo stesso numero di elementi");
    }
}

int main() {
    int a = 5;
    int b = 7;
    int c = 10;
    int d = 14;

    compara_estremi_inferiori(a, c);
    compara_estremi_superiori(b, d);
    compara_intervalli(a, b, c, d);
    return 0;
}
```

## Esercizio E17.4

Dati gli intervalli visti nell’esercizio 17.3, scrivere un programma che indichi se questi hanno lo stesso numero di elementi e gli estremi coincidono, oppure se solo una di queste condizioni è verificata. Usare solo operatori logici.

### Soluzione S17.4

Possiamo integrare le seguenti istruzioni nella funzione `compara_intervalli`.

```c
void compara_intervalli(int a, int b, int c, int d) {
    int els_ac = c - a;
    int els_bd = d - b;
    if (els_ac > els_bd) {
        printf("L'intervallo [%d, %d] ha più elementi dell'intervallo [%d, %d]", a, c, b, d);
    } else if (els_ac < els_bd) {
        printf("L'intervallo [%d, %d] ha più elementi dell'intervallo [%d, %d]", b, d, a, c);
    } else {
        printf("I due intervalli hanno lo stesso numero di elementi");
    }

    if ((a == c) && (b == d) && (els_ac == els_bd)) {
        printf("Gli intervalli coincidono, ed i due estremi hanno lo stesso numero di elementi");
    } else if ((a == c) && (b == d) || (els_ac == els_bd)) {
        printf("Gli intervalli coincidono, o i due estremi hanno lo stesso numero di elementi");
    }
}
```

!!!note "Nota"
    Ovviamente, se gli estremi coincidono allora i due insiemi hanno necessariamente lo stesso numero di elementi. Tuttavia, a scopo di esempio, ignoriamo questo (ovvio) fenomeno.
