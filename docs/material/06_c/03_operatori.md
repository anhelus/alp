# 6.4 Operatori ed Espressioni

Gli operatori sono i simboli che ci permettono di eseguire calcoli, confronti e manipolazioni sui dati. Combinati con variabili e valori, formano le espressioni.

## Regole Fondamentali: Precedenza e Associatività

Quando un'espressione contiene più operatori, il C segue due regole per determinare l'ordine di valutazione:

1. **Precedenza**: Stabilisce una gerarchia di importanza tra operatori diversi. Ad esempio, gli operatori di moltiplicazione (`*`) e divisione (`/`) hanno una precedenza maggiore rispetto a quelli di addizione (`+`) e sottrazione (`-`). In `a + b * c`, la moltiplicazione verrà eseguita per prima.
2. **Associatività**: Stabilisce l'ordine di raggruppamento per operatori con la **stessa** precedenza. La maggior parte degli operatori in C ha un'associatività da sinistra a destra. In `a - b + c`, prima viene eseguita `a - b` e poi il risultato viene sommato a `c`.

L'uso delle parentesi `()` permette di forzare un ordine di valutazione specifico, sovrascrivendo le regole di precedenza e associatività.

## Tipi di Operatori

!!! warning "Attenzione a `=` e `==`"
    Un errore comune è scrivere `if (a = 10)`: questa espressione assegna `10` ad `a` e risulta sempre vera, creando un bug difficile da scovare. La forma corretta per un confronto è `if (a == 10)`.

* **Operatore di Assegnazione (`=`)**: Assegna il valore dell'espressione a destra alla variabile a sinistra.
* **Operatori Aritmetici**: `+`, `-`, `*`, `/`. L'operatore modulo `%` restituisce il resto della divisione intera.
* **Operatori Relazionali e di Uguaglianza**: `==` (uguale), `!=` (diverso), `>`, `<`, `>=`, `<=`. Restituiscono `1` (vero) o `0` (falso).
* **Operatori Logici Booleani**: Agiscono su valori booleani (o valori che possono essere interpretati come tali). Sono `&&` (AND logico), `||` (OR logico) e `!` (NOT logico). Sono "pigri" (*short-circuiting*): in `A && B`, se `A` è falso, `B` non viene nemmeno valutato.
* **Operatori Bitwise (o Binari)**: Operano direttamente sulla rappresentazione binaria dei numeri interi. Sono `&` (AND), `|` (OR), `^` (XOR), `~` (NOT), `<<` (shift a sinistra) e `>>` (shift a destra). Sono strumenti potenti ma di basso livello, usati in contesti specifici.

## Conversioni di Tipo (Casting)

A volte è necessario convertire un valore da un tipo di dato a un altro.

*   **Conversione Implicita**: Avviene automaticamente quando il compilatore ritiene sicuro farlo, ad esempio assegnando un `int` a un `double`. Può però portare a perdite di dati se non si è attenti (es. assegnando un `double` a un `int`, la parte decimale viene troncata).
*   **Conversione Esplicita (Casting)**: È forzata dal programmatore tramite l'operatore di cast `(tipo)`. È essenziale in operazioni come la divisione tra interi quando si desidera un risultato con la virgola:

    ```c
    int a = 5;
    int b = 2;
    float risultato = (float)a / b; // Risultato: 2.5
    ```

