# 17 - Operatori in C

Un operatore agisce su coppia di dati (binario) o su un dato singolo (unario)
Un’espressione è una sequenza di operatori regolata dai principi di precedenza ed associatività
La precedenza vale solo in caso di più operatori, e va da sinistra verso destra
È comunque assicurata nel caso si usino delle parentesi tonde

a op_1 b op_2 c
a op_1 (b op_2 c)

L’associatività indica l’ordine in cui sono valutati gli operandi (i dati)
Si va quasi sempre da sinistra (l-value) verso destra (r-value)

# operatore di assegnazione

L’operatore di assegnazione ci permette di assegnare un valore ad una variabile
Viene usato in fase di inizializzazione
a = 10;
c = ‘A’;
Non serve per valutare il valore di una variabile, ma solo per assegnarne uno nuovo!
Ergo, un’espressione del tipo if (a = 10) non funzionerà!

# Operatori matematici

Sono gli operatori fondamentali coinvolti nelle operazioni di tipo aritmetico
Esercizio 1: scriviamo un programma che calcoli il quadrato di un numero
Esercizio 2: scriviamo un programma che determini se un numero è pari
Suggerimento: usare == per valutare il valore di una variabile
Suggerimento: usare l’header stdbool.h per i valori booleani

Esercizio 1: scriviamo un programma che calcoli il quadrato di un numero

// quadrato
#include <stdio.h>

int quadrato(int n) {
    return n * n;
}

int main() {
    int a = 3;
    printf("Il quadrato di %d è %d\n", a, quadrato(a));
}

// pari
#include <stdbool.h>
#include <stdio.h>

bool numero_pari(int n) {
    if (n % 2 == 0) {
        return true;
    }
    return false;
}

int main() {
    int pari = 4;
    int dispari = 5;
    printf("Il valore di %d è pari? %d\n", pari,        numero_pari(pari));
    printf("Il valore di %d è pari? %d\n", dispari,        numero_pari(dispari));
}

## Cenni di logica booleana

Governa le interazioni tra i valori booleani (true e false)
Ricordare che true == 1, e false == 0
Sono operatori binari
Alcune regole:
L’AND restituisce true se i due operandi sono true
L’OR restituisce true se almeno un operando è true
Lo XOR (exclusive OR) restituisce true se solo un operando è true

TODO: TABELLA LOGICA BOOLEANA

# operatori binari

Operano a livello di bit
Possono:
Effettuare uno shift (scorrimento) verso sinistra o destra
Effettuare operazioni binarie bit a bit
Supponiamo di avere una variabile di tipo byte
𝐚=4=2^2=(00000010)_2
Applicando gli operatori di scorrimento:
a>>1⇒a=(00000001)_2=2^1=a/2^1 
a<<1⇒a=(00000100)_2=2^3=a⋅2^1


Supponiamo ora di avere due char
Vediamo cosa succede applicando gli operatori binari logici


TODO: tabella operatori binari

| Operatore | Descrizione |
| --------- | ----------- |
| >>        | Right shift |
| <<        | Left shift  |
| &         | AND bit a bit |
| `|` | OR bit a bit |
| ^ | XOR bit a bit |

Ad esempio:

| Operatore | a | b | risultato |
| & | 10001011 | 01011010 | 00001010 |
| `|` | 10001011 | 01011010 | 11011011 |
| ^ | 10001011 | 01011010 | 11010001 |

# operatori relazionali

Confrontano due operandi di tipo primitivo
Restituiscono un valore booleano (true o false)
Esercizio 3: scriviamo un programma che confronta due intervalli di valori del tipo [𝑎,𝑏] e [𝑐,𝑑], con 𝑎,𝑏,𝑐 e 𝑑 numeri interi. Il programma deve stampare a schermo il maggiore tra gli estremi inferiori 𝑎 e 𝑐, il minore tra gli estremi superiori 𝑏 e 𝑑 e stabilire se il numero di elementi nei due intervalli è lo stesso.

TODO: tabella operatori relazionali

Esercizio 3: scriviamo un programma che confronta due intervalli di valori del tipo [𝑎,𝑏] e [𝑐,𝑑], con 𝑎,𝑏,𝑐 e 𝑑 numeri interi. Il programma deve stampare a schermo il maggiore tra gli estremi inferiori 𝑎 e 𝑐, il minore tra gli estremi superiori 𝑏 e 𝑑 e stabilire se il numero di elementi nei due intervalli è lo stesso.

void compara_intervalli(int a, int b, int c, int d) {
    int max_estremo_inferiore = a;
    int min_estremo_superiore = b;
    if (c > a) {
        max_estremo_inferiore = c;
    }
    if (d < b) {
        min_estremo_superiore = d;
    }
    printf("Il maggiore tra gli elementi e' %d\n",        max_estremo_inferiore);
    printf("Il minore tra gli elementi e' %d\n",        min_estremo_superiore);
    if ((b - a) != (d - c)) {
        printf("Gli intervalli non hanno lo stesso numero
            di elementi\n");
    } else {
        printf("Gli intervalli hanno lo stesso numero di
            elementi\n");
    }
}


# operatori logici

Agiscono su operandi booleani e restituiscono un valore logico
L’AND e l’OR sono operatori binari, il NOT è unario
Da non confondere con gli operatori binari
Esercizio 4: dati gli intervalli visti nell’esercizio 3, scrivere un programma che indichi se i due intervalli hanno lo stesso numero di elementi e gli estremi degli stessi coincidono, oppure se solo una di queste condizioni è verificata. Usare solo operatori logici.

TODO: tabella operatori logici

# conversione di tipo

La conversione di tipo può essere implicita ed esplicita
La conversione implicita avviene:
con gli operatori matematici, semplificando i tipi più complessi (ad esempio, un float viene convertito in int, un int in char, e così via);
con gli operatori di assegnazione, nei quali l’operando di sinistra assume il tipo dell’operando di destra;
eventuali errori di saturazione (overflow) non vengono segnalati!
La conversione esplicita avviene mediante l’operatore di casting
Questo indica il nuovo tipo tra parentesi, davanti al nome della variabile da trasformare

Alcuni esempi di conversione implicita:
	int a = 3.2 + 4.2; 		// il risultato sarà convertito da float ad int	int b = "c" 		// il risultato sarà convertito da char ad int	short c = 9999999 		// il valore di c sarà comunque 32767!
Alcuni esempi di conversione esplicita:
	int a = 3;	int b = 4;	float c;	c = (float) b/a;
In generale, evitare le conversioni di tipo implicite…
…e ricorrere a quelle esplicite solo quando necessario!


