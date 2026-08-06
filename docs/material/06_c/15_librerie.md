# 6.15 La Libreria Standard del C

La libreria standard del C fornisce un insieme di funzioni pronte all'uso per operazioni comuni. Ne esploriamo le più utili, organizzate per header.

## `<string.h>`: manipolazione di stringhe

Le stringhe in C sono array di `char` terminati da `\0`. La libreria `<string.h>` offre funzioni per manipolarle in modo sicuro.

### Lunghezza e copia

```c
#include <string.h>

char src[] = "Hello";
char dst[10];

size_t len = strlen(src);          // lunghezza (5, senza il \0)
strcpy(dst, src);                   // copia: dst contiene "Hello"
strncpy(dst, src, sizeof(dst) - 1); // copia sicura con limite
dst[sizeof(dst) - 1] = '\0';        // assicura terminazione
```

!!! warning "`strcpy` non è sicura"
    `strcpy(dest, src)` copia fino al `\0` senza controllare la dimensione del buffer di destinazione. Se `src` è più lunga di `dest`, si ha un **buffer overflow**. Preferire `strncpy` o funzioni più moderne come `strlcpy` (dove disponibile).

### Confronto e ricerca

```c
char s1[] = "mela";
char s2[] = "melone";

int cmp = strcmp(s1, s2);  // < 0 perché "mela" < "melone"
// strcmp confronta lessicograficamente, restituendo:
//   0 se uguali
//   < 0 se la prima stringa precede la seconda
//   > 0 se la prima segue la seconda

char* trovato = strstr(s1, "el");   // cerca "el" in s1, restituisce puntatore
char* virgola = strchr(s1, 'e');    // cerca 'e' in s1, restituisce puntatore
```

### Concatenazione

```c
char percorso[100] = "/home/user/";
strcat(percorso, "documenti.txt");  // attenzione: stesso rischio di overflow
strncat(percorso, "documenti.txt", sizeof(percorso) - strlen(percorso) - 1);
```

### Tokenizzazione

```c
char testo[] = "mela,pera,banana";
char* token = strtok(testo, ",");
while (token != NULL) {
    printf("%s\n", token); // stampa mela, pera, banana
    token = strtok(NULL, ",");
}
```

!!! note "`strtok` modifica la stringa originale"
    `strtok` sostituisce i separatori con `\0` e mantiene uno stato interno statico, quindi non è thread-safe e non può essere usata su stringhe costanti. Per applicazioni concorrenti, usare `strtok_r`.

## `<ctype.h>`: classificazione e conversione di caratteri

```c
#include <ctype.h>

char c = 'a';

isalpha(c)   // 1 (vero): è una lettera?
isdigit(c)   // 0 (falso): è una cifra?
isalnum(c)   // 1: è alfanumerico?
isspace(c)   // 0: è spazio/tab/newline?
islower(c)   // 1: è minuscola?
isupper(c)   // 0: è maiuscola?

char maiuscola = toupper(c); // 'A'
char minuscola = tolower('B'); // 'b'
```

Esempio: contare le parole in una stringa

```c
#include <ctype.h>

size_t conta_parole(const char* str) {
    size_t conteggio = 0;
    int in_parola = 0;

    while (*str) {
        if (isspace(*str)) {
            in_parola = 0;
        } else if (!in_parola) {
            in_parola = 1;
            conteggio++;
        }
        str++;
    }
    return conteggio;
}
```

## `<math.h>`: funzioni matematiche

```c
#include <math.h>

double x = 4.0;
double y = 2.5;

sqrt(x)    // radice quadrata (2.0)
pow(x, 3) // elevamento a potenza (64.0)
exp(1.0)  // e^1 (2.718...)
log(x)    // logaritmo naturale (1.386...)
log10(x)  // logaritmo base 10 (0.602...)

ceil(y)   // arrotonda per eccesso (3.0)
floor(y)  // arrotonda per difetto (2.0)
round(y)  // arrotonda all'intero più vicino (3.0)
fabs(-5)  // valore assoluto (5.0)

sin(0.0)  // seno (0.0)
cos(0.0)  // coseno (1.0)
tan(0.0)  // tangente (0.0)
```

!!! tip "Compilare con `-lm`"
    Su molti sistemi (Linux, MinGW), le funzioni matematiche richiedono il linking esplicito della libreria matematica: `gcc programma.c -lm -o programma`.

## `<time.h>`: data e ora

### Misurare il tempo

```c
#include <time.h>

clock_t inizio = clock();
// ... codice da misurare ...
clock_t fine = clock();

double secondi = (double)(fine - inizio) / CLOCKS_PER_SEC;
printf("Tempo: %.3f s\n", secondi);
```

### Ottenere data e ora correnti

```c
#include <time.h>
#include <stdio.h>

time_t ora = time(NULL);                    // timestamp UNIX
printf("%ld\n", (long)ora);                // secondi dal 01/01/1970

char buffer[100];
struct tm* info = localtime(&ora);          // converte in data/ora locale
strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", info);
printf("%s\n", buffer);                     // es. "09/07/2026 14:30:15"
```

### Misurare con precisione (C11)

```c
#include <time.h>

struct timespec inizio, fine;
clock_gettime(CLOCK_MONOTONIC, &inizio);
// ... codice ...
clock_gettime(CLOCK_MONOTONIC, &fine);

double sec = (fine.tv_sec - inizio.tv_sec)
           + (fine.tv_nsec - inizio.tv_nsec) / 1e9;
```

## Esempio: validatore di input

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int leggi_intero() {
    char buffer[50];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // rimuove newline

    for (size_t i = 0; i < strlen(buffer); i++) {
        if (!isdigit(buffer[i]) && buffer[i] != '-') {
            return 0; // input non valido
        }
    }
    return atoi(buffer);
}

int main() {
    printf("Inserisci un numero: ");
    int n = leggi_intero();
    printf("Hai inserito: %d\n", n);
    return 0;
}
```

