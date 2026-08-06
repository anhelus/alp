# 6.18 Esercizi Guidati

## 1. Lettura di codice: cosa stampa?

### 1.1

```c
#include <stdio.h>

int main() {
    int x = 10;
    int y = 3;
    int z = x / y;
    printf("%d %d %d\n", x, y, z);
    return 0;
}
```

???risposta "Risposta"
    Stampa `10 3 3`. La divisione tra interi tronca la parte decimale (10 / 3 = 3, non 3.33).

    **Concetti**: divisione intera, printf.

### 1.2

```c
#include <stdio.h>

int main() {
    int a = 5;
    int b = ++a;
    int c = a++;
    printf("%d %d %d\n", a, b, c);
    return 0;
}
```

???risposta "Risposta"
    Stampa `7 6 6`. `++a` pre-incremento: a diventa 6, b = 6. `a++` post-incremento: c = 6 (valore prima dell'incremento), poi a diventa 7.

    **Concetti**: pre/post-incremento, operatori.

### 1.3

```c
#include <stdio.h>

int main() {
    int v[] = {10, 20, 30, 40, 50};
    int *p = v + 2;
    printf("%d %d %d\n", *p, p[-1], *(v + 4));
    return 0;
}
```

???risposta "Risposta"
    Stampa `30 20 50`. `p` punta a v[2] (30). `p[-1]` equivale a *(p - 1) = v[1] (20). `*(v + 4)` = v[4] (50).

    **Concetti**: aritmetica dei puntatori, relazione array/puntatore, indici negativi.

### 1.4

```c
#include <stdio.h>
#include <string.h>

int main() {
    char s1[] = "Ciao";
    char s2[] = "Ciao";
    if (s1 == s2)
        printf("uguali\n");
    else
        printf("diversi\n");
    if (strcmp(s1, s2) == 0)
        printf("uguali\n");
    else
        printf("diversi\n");
    return 0;
}
```

???risposta "Risposta"
    Stampa `diversi` (primo if) e `uguali` (secondo if). `s1 == s2` confronta gli **indirizzi** dei due array, non i contenuti. `strcmp()` confronta il contenuto delle stringhe carattere per carattere.

    **Concetti**: array vs puntatori, stringhe, confronto tra stringhe.

---

## 2. Trovare l'errore

### 2.1

```c
#include <stdio.h>

int main() {
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", n);
    printf("Hai inserito: %d\n", n);
    return 0;
}
```

???risposta "Risposta"
    Manca `&` in `scanf("%d", n)`. Deve essere `scanf("%d", &n)`. `scanf` scrive il valore letto all'indirizzo della variabile, quindi serve il puntatore.

    **Concetti**: scanf, passaggio per indirizzo.

### 2.2

```c
#include <stdio.h>

void raddoppia(int x) {
    x = x * 2;
}

int main() {
    int n = 5;
    raddoppia(n);
    printf("%d\n", n);
    return 0;
}
```

???risposta "Risposta"
    Stampa `5`, non 10. In C il passaggio è **per valore**: la funzione modifica una copia di `n`. Per modificare n bisogna passare un puntatore:

    ```c
    void raddoppia(int *x) {
        *x = *x * 2;
    }
    raddoppia(&n);
    ```

    **Concetti**: passaggio per valore, puntatori.

### 2.3

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = malloc(10 * sizeof(int));
    for (int i = 0; i <= 10; i++)
        p[i] = i;
    for (int i = 0; i < 10; i++)
        printf("%d ", p[i]);
    free(p);
    return 0;
}
```

???risposta "Risposta"
    **Buffer overflow**: il ciclo scrive da `p[0]` a `p[10]` (11 elementi), ma lo spazio allocato è per 10 interi. `p[10]` scrive oltre i limiti dell'area allocata. Il loop di stampa è invece corretto (da 0 a 9). Correzione:

    ```c
    for (int i = 0; i < 10; i++)
        p[i] = i;
    ```

    **Concetti**: allocazione dinamica, buffer overflow, off-by-one.

---

## 3. Completare il codice

### 3.1

Scrivere il corpo della funzione che conta le occorrenze di un carattere in una stringa:

```c
int conta_carattere(const char *s, char c) {
    // scrivere qui
}
```

???risposta "Risposta"
    ```c
    int conta_carattere(const char *s, char c) {
        int count = 0;
        while (*s) {
            if (*s == c)
                count++;
            s++;
        }
        return count;
    }
    ```

    **Concetti**: stringhe in C, puntatori, cicli.

### 3.2

Completare la funzione che inverte un array in-place:

```c
void inverti(int *v, int n) {
    // scrivere qui
}
```

???risposta "Risposta"
    ```c
    void inverti(int *v, int n) {
        for (int i = 0; i < n / 2; i++) {
            int temp = v[i];
            v[i] = v[n - 1 - i];
            v[n - 1 - i] = temp;
        }
    }
    ```

    **Concetti**: array, scambio di valori, loop.

### 3.3

Completare la funzione che alloca e copia una stringa (versione manuale di `strdup`):

```c
char *copia_stringa(const char *s) {
    // scrivere qui
}
```

???risposta "Risposta"
    ```c
    char *copia_stringa(const char *s) {
        int len = 0;
        while (s[len])
            len++;
        char *copia = malloc((len + 1) * sizeof(char));
        if (copia == NULL)
            return NULL;
        for (int i = 0; i <= len; i++)
            copia[i] = s[i];
        return copia;
    }
    ```

    **Concetti**: allocazione dinamica, stringhe, controllo errori malloc, `\0` terminatore.

---

## 4. Scrivere un programma

Scrivere un programma C per ciascuno dei seguenti problemi.

### 4.1 Calcolatrice base

Un programma che legge due numeri interi e un carattere (`+`, `-`, `*`, `/`) e stampa il risultato dell'operazione. Gestire la divisione per zero.

???risposta "Risposta"
    ```c
    #include <stdio.h>

    int main() {
        int a, b;
        char op;

        printf("Inserisci due numeri: ");
        scanf("%d %d", &a, &b);
        printf("Inserisci l'operazione (+, -, *, /): ");
        scanf(" %c", &op);

        switch (op) {
            case '+':
                printf("%d + %d = %d\n", a, b, a + b);
                break;
            case '-':
                printf("%d - %d = %d\n", a, b, a - b);
                break;
            case '*':
                printf("%d * %d = %d\n", a, b, a * b);
                break;
            case '/':
                if (b == 0)
                    printf("Errore: divisione per zero\n");
                else
                    printf("%d / %d = %d\n", a, b, a / b);
                break;
            default:
                printf("Operazione non valida\n");
        }
        return 0;
    }
    ```

    **Concetti**: switch, input/output, divisione per zero.

### 4.2 Palindromo

Un programma che verifica se una stringa è palindroma (es: "anna", "racecar"). Ignorare maiuscole/minuscole e spazi.

???risposta "Risposta"
    ```c
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>

    int main() {
        char s[256];
        printf("Inserisci una stringa: ");
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = '\0';

        int i = 0, j = strlen(s) - 1;
        int palindromo = 1;

        while (i < j) {
            while (i < j && s[i] == ' ') i++;
            while (i < j && s[j] == ' ') j--;
            if (tolower(s[i]) != tolower(s[j])) {
                palindromo = 0;
                break;
            }
            i++;
            j--;
        }

        printf("\"%s\" %s palindroma\n", s,
               palindromo ? "e'" : "non e'");
        return 0;
    }
    ```

    **Concetti**: stringhe, caratteri, tolower, fgets, puntatori a due estremità.

### 4.3 Invertire un file

Un programma che legge un file di testo e scrive un nuovo file con le righe in ordine inverso (l'ultima riga diventa la prima).

???risposta "Risposta"
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int main() {
        char nome[256];
        printf("Nome file: ");
        scanf("%255s", nome);

        FILE *f = fopen(nome, "r");
        if (f == NULL) {
            printf("Errore apertura file\n");
            return 1;
        }

        char **righe = NULL;
        int n = 0, cap = 0;
        char buf[1024];

        while (fgets(buf, sizeof(buf), f)) {
            if (n >= cap) {
                cap = cap ? cap * 2 : 16;
                righe = realloc(righe, cap * sizeof(char *));
            }
            righe[n] = malloc(strlen(buf) + 1);
            strcpy(righe[n], buf);
            n++;
        }
        fclose(f);

        for (int i = n - 1; i >= 0; i--)
            printf("%s", righe[i]);

        for (int i = 0; i < n; i++)
            free(righe[i]);
        free(righe);
        return 0;
    }
    ```

    **Concetti**: file I/O, allocazione dinamica, realloc, gestione memoria.

### 4.4 Rubrica telefonica

Un programma che gestisce una rubrica di contatti (nome, telefono) con funzioni per aggiungere, cercare e stampare. Usare array di struct e allocazione dinamica.

???risposta "Risposta"
    ```c
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    typedef struct {
        char nome[64];
        char telefono[16];
    } Contatto;

    typedef struct {
        Contatto *contatti;
        int n;
        int capacita;
    } Rubrica;

    void aggiungi(Rubrica *r, const char *nome, const char *tel) {
        if (r->n >= r->capacita) {
            r->capacita = r->capacita ? r->capacita * 2 : 8;
            r->contatti = realloc(r->contatti,
                                  r->capacita * sizeof(Contatto));
        }
        strcpy(r->contatti[r->n].nome, nome);
        strcpy(r->contatti[r->n].telefono, tel);
        r->n++;
    }

    void cerca(const Rubrica *r, const char *nome) {
        for (int i = 0; i < r->n; i++) {
            if (strcmp(r->contatti[i].nome, nome) == 0) {
                printf("%s: %s\n", r->contatti[i].nome,
                       r->contatti[i].telefono);
                return;
            }
        }
        printf("Contatto non trovato\n");
    }

    void stampa_tutti(const Rubrica *r) {
        for (int i = 0; i < r->n; i++)
            printf("%d. %s — %s\n", i + 1,
                   r->contatti[i].nome,
                   r->contatti[i].telefono);
    }

    int main() {
        Rubrica r = {NULL, 0, 0};
        aggiungi(&r, "Mario", "333-123456");
        aggiungi(&r, "Anna", "340-654321");
        aggiungi(&r, "Luigi", "347-111222");
        stampa_tutti(&r);
        cerca(&r, "Anna");
        free(r.contatti);
        return 0;
    }
    ```

    **Concetti**: struct, typedef, array dinamici, realloc, funzioni.

---

## 5. Cosa fa questa funzione?

### 5.1

```c
int mistero(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
```

???risposta "Risposta"
    Calcola l'**MCD** (massimo comun divisore) usando l'algoritmo di Euclide. Esempio: `mistero(12, 8)` → 4.

### 5.2

```c
#include <stdio.h>

void mistero(const char *s) {
    if (*s == '\0')
        return;
    mistero(s + 1);
    putchar(*s);
}
```

???risposta "Risposta"
    Stampa la stringa **al contrario** usando la ricorsione. La chiamata ricorsiva arriva fino al terminatore, poi risalendo stampa i caratteri in ordine inverso.

    **Concetti**: ricorsione, stack delle chiamate.

### 5.3

```c
unsigned int mistero(unsigned int n) {
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
```

???risposta "Risposta"
    Conta il numero di bit a **1** (popcount) nella rappresentazione binaria di `n`. Per ogni iterazione controlla il bit meno significativo (`n & 1`) e poi scalza a destra (`n >>= 1`).

    **Concetti**: operatori bitwise (&, >>), rappresentazione binaria.

---

## 6. Sfida: mini progetto

### 6.1 Simulatore di pila (stack)

Scrivere un programma che implementa una pila di interi con le funzioni:

* `void push(Stack *s, int valore)`
* `int pop(Stack *s)`
* `int peek(const Stack *s)`
* `int is_empty(const Stack *s)`

La pila deve essere dinamicamente ridimensionabile. Usare il programma per invertire una sequenza di numeri inseriti dall'utente (terminata da 0).

???risposta "Risposta"
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    typedef struct {
        int *data;
        int n;
        int capacita;
    } Stack;

    void push(Stack *s, int valore) {
        if (s->n >= s->capacita) {
            s->capacita = s->capacita ? s->capacita * 2 : 8;
            s->data = realloc(s->data, s->capacita * sizeof(int));
        }
        s->data[s->n++] = valore;
    }

    int pop(Stack *s) {
        return s->data[--s->n];
    }

    int peek(const Stack *s) {
        return s->data[s->n - 1];
    }

    int is_empty(const Stack *s) {
        return s->n == 0;
    }

    int main() {
        Stack s = {NULL, 0, 0};
        int n;

        printf("Inserisci numeri (0 per terminare):\n");
        while (1) {
            scanf("%d", &n);
            if (n == 0) break;
            push(&s, n);
        }

        printf("Inverso: ");
        while (!is_empty(&s))
            printf("%d ", pop(&s));
        printf("\n");

        free(s.data);
        return 0;
    }
    ```

    **Concetti**: stack LIFO, allocazione dinamica, struct, realloc.

### 6.2 Moltiplicazione di matrici

Scrivere un programma che:

1. Legge due matrici di interi da file (formato: righe colonne poi i valori).
2. Verifica che siano moltiplicabili (colonne di A = righe di B).
3. Calcola e stampa la matrice prodotto.
4. Usa allocazione dinamica.

???risposta "Risposta"
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    typedef struct {
        int r, c;
        int **d;
    } Matrice;

    Matrice leggi_matrice(const char *nome_file) {
        Matrice m = {0, 0, NULL};
        FILE *f = fopen(nome_file, "r");
        if (f == NULL) return m;

        fscanf(f, "%d %d", &m.r, &m.c);
        m.d = malloc(m.r * sizeof(int *));
        for (int i = 0; i < m.r; i++) {
            m.d[i] = malloc(m.c * sizeof(int));
            for (int j = 0; j < m.c; j++)
                fscanf(f, "%d", &m.d[i][j]);
        }
        fclose(f);
        return m;
    }

    Matrice moltiplica(const Matrice *a, const Matrice *b) {
        Matrice r = {a->r, b->c, NULL};
        r.d = malloc(r.r * sizeof(int *));
        for (int i = 0; i < r.r; i++) {
            r.d[i] = calloc(r.c, sizeof(int));
            for (int k = 0; k < a->c; k++)
                for (int j = 0; j < r.c; j++)
                    r.d[i][j] += a->d[i][k] * b->d[k][j];
        }
        return r;
    }

    void stampa_matrice(const Matrice *m) {
        for (int i = 0; i < m->r; i++) {
            for (int j = 0; j < m->c; j++)
                printf("%4d ", m->d[i][j]);
            printf("\n");
        }
    }

    void libera_matrice(Matrice *m) {
        for (int i = 0; i < m->r; i++)
            free(m->d[i]);
        free(m->d);
    }

    int main(int argc, char *argv[]) {
        if (argc != 3) {
            printf("Uso: %s file1 file2\n", argv[0]);
            return 1;
        }
        Matrice a = leggi_matrice(argv[1]);
        Matrice b = leggi_matrice(argv[2]);
        if (a.c != b.r) {
            printf("Matrici non moltiplicabili\n");
            libera_matrice(&a);
            libera_matrice(&b);
            return 1;
        }
        Matrice r = moltiplica(&a, &b);
        stampa_matrice(&r);
        libera_matrice(&a);
        libera_matrice(&b);
        libera_matrice(&r);
        return 0;
    }
    ```

    **Concetti**: allocazione 2D, puntatori a puntatori, lettura file, matrici, prodotto righe×colonne.

---

## Guida alla soluzione

Se un esercizio non riesce subito, prova a:

1. **Tracciare manualmente** il codice su carta: scrivi lo stato delle variabili a ogni passo.
2. **Aggiungere `printf`** per vedere cosa succede dentro il programma.
3. **Usare un debugger** (es: GDB, o il debugger integrato in VS Code) per seguire l'esecuzione passo-passo.
4. **Semplificare** il problema: risolvi prima una versione più facile, poi aggiungi complessità.

