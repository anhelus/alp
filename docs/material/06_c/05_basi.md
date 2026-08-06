# 6.2 Basi del C: Strutture di Controllo

## Il Flusso di Controllo e la Programmazione Strutturata

La programmazione strutturata è un paradigma che mira a migliorare la chiarezza e la manutenibilità del codice evitando costrutti caotici (come il famigerato `goto`). Si basa sull'idea che ogni programma possa essere costruito combinando tre semplici strutture di controllo: la sequenza, la selezione e l'iterazione. Sono i mattoncini fondamentali con cui costruiamo la logica di qualsiasi algoritmo.

### Selezione: Prendere Decisioni nel Codice

La selezione permette a un programma di scegliere quali istruzioni eseguire in base a una o più condizioni.

#### Il Costrutto `if-else`

Il costrutto `if-else` è lo strumento principale per l'esecuzione condizionale. Valuta un'espressione booleana e, se è vera, esegue un blocco di codice; altrimenti, può eseguire un blocco di codice alternativo.

```c
int eta = 20;

if (eta >= 18) {
    printf("L'utente e' maggiorenne.\n");
} else {
    printf("L'utente e' minorenne.\n");
}
```
!!! tip "Regola d'oro"
    Usa sempre le parentesi graffe `{}` per delimitare i blocchi di codice, anche se contengono una sola riga. Questo previene molti errori comuni.

Per gestire più condizioni in sequenza, si usa la catena `if-else if-else`:
```c
int voto = 75;

if (voto >= 90) {
    printf("Eccellente\n");
} else if (voto >= 70) {
    printf("Buono\n");
} else if (voto >= 60) {
    printf("Sufficiente\n");
} else {
    printf("Insufficiente\n");
}
```

#### Il Costrutto `switch`

Quando dobbiamo scegliere tra molteplici valori discreti di una singola variabile intera (come `int` o `char`), il costrutto `switch` offre un'alternativa più pulita e leggibile a una lunga catena di `if-else if`.

```c
char scelta = 'B';

switch (scelta) {
    case 'A':
        printf("Hai scelto l'opzione A.\n");
        break; // Il break è FONDAMENTALE!
    case 'B':
        printf("Hai scelto l'opzione B.\n");
        break;
    case 'C':
        printf("Hai scelto l'opzione C.\n");
        break;
    default: // Eseguito se nessun case corrisponde
        printf("Scelta non valida.\n");
        break;
}
```

!!! warning "Il *fall-through* dello `switch`"
    La parola chiave `break` interrompe l'esecuzione. Se omessa, il programma eseguirà un "fall-through", continuando a eseguire il codice dei `case` successivi. Questo comportamento è utile in rari casi, ma è quasi sempre un bug se non intenzionale.

### Iterazione: Eseguire Codice Ripetutamente

L'iterazione, o ciclo, permette di ripetere un blocco di codice finché una certa condizione rimane vera.

#### Il Ciclo `for`

Il ciclo `for` è la scelta ideale quando il numero di ripetizioni è noto prima di iniziare il ciclo. La sua sintassi compatta unisce tre parti fondamentali:

1. **Inizializzazione**: eseguita una sola volta all'inizio.
2. **Condizione**: controllata *prima* di ogni iterazione.
3. **Incremento/Aggiornamento**: eseguito *dopo* ogni iterazione.

```c
// Stampa i numeri da 0 a 9
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

#### Il Ciclo `while`

Il ciclo `while` è perfetto quando la condizione di terminazione non dipende da un contatore, ma da un evento esterno. Il ciclo continua finché la condizione è vera.

```c
int numero = 0;
// Chiede un numero finché l'utente non inserisce un valore negativo
while (numero >= 0) {
    printf("Inserisci un numero (negativo per uscire): ");
    scanf("%d", &numero);
}
```

#### Il Ciclo `do-while`

Il ciclo `do-while` è una variante del `while` in cui la condizione viene verificata **alla fine** dell'iterazione. Questo garantisce che il corpo del ciclo venga eseguito **almeno una volta**, indipendentemente dalla condizione.

```c
char conferma;
do {
    printf("Vuoi continuare? (s/n): ");
    scanf(" %c", &conferma); // Spazio prima di %c per consumare eventuali newline
} while (conferma == 's');
```

Questi tre costrutti (sequenza, selezione, iterazione) sono gli unici strumenti necessari per costruire la logica di qualsiasi programma, non importa quanto complesso. Padroneggiarli è il primo, grande passo per diventare un programmatore C competente.


