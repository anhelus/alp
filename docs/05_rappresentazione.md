# rappresentazione dei dati

Tutte le informazioni (dati e istruzioni) in un computer sono rappresentate in forma binaria (ovvero come sequenza finita di simboli '0' ed '1')

L'unità di informazione è il *bit*, contrazione di *binary digit*.

Un bit può assumere solo i valori 0 oppure 1.

Una sequenza di 8 bit costituisce un byte: un byte può assumere uno tra 2^8 valori.

Una *parola* (word) è composta da N byte, con N dipendente dallo specifico contesto


# dati numerici
Data la finitezza della macchina computer, tutte le informazioni che in essosi possono rappresentare sono necessariamente finite.

Qando ad esempio si parla di insieme dei numeri interi, si intende un'approsismazione finita di N.

Siamo abituati a pensare (e usare) i numeri interi in forma decimale e posizionale.

Decimale, perché espressi in base 10, facendo usso di dieci simboli (0, 1, 2,3, etc.)

posizionale perché la posizione in cui compare un simbolo è fondamentale per la sua interpretazione.

Ad esempio, il numero 12 ed il numero 21 sono rappresentati mediante gli stessi simboli 1 e 2, ma disposizioni in posizioni diverse.

Sia $N$ un generico numero intero ad $n$ simboli. In forma decimale e posizionale è possibile esprimerlo come:

$$
N = a_n a_{n-1} a_{n-2} ... a_2 a_1 a_0
$$

Esprimendo $N$ in base $b$:

$$
N_b = a_n * b^n + a_{n-1} * b^{n-1} + ... + a_1 * b + a_0
$$

Ad esempio:

$$
N = 485_{10} = (4 * 10^2 + 8 * 10 + 5)_{10}
$$

Volendo rappresentare N in base 2:

$$
N = 485
$$

Per prima cosa, dividiamo il numero decimale per 2.

$$
N / 2 = 485 / 2 = 242 * 2 + 1
$$

Il risultato della divisione ha resto 1; questo sarà il primo bit del nostro numero converito (chiamato anche Least Significant Bit, o LSB, o bit meno significativo).

Continuiamo a dividere:

$$
242 / 2 = 121 * 2 + 0
$$

Il secondo bit è pari a 0.

Reiterando la procedura:

$$
\begin{eqnarray}
121 / 2 &= 60 * 2 + 1 \\
60 / 2 &= 30 * 2 + 0 \\
30 / 2 &= 15 * 2 + 0 \\
15 / 2 &= 7 * 2 + 1 \\
7 / 2 &= 3 * 2 + 1 \\
3 / 2 &= 1 * 2 + 1 \\
1 / 2 &= 0 * 2 + 1
\end{eqnarray}
$$

La rappresentazione risulta quindi essere data da:

$$
N_10 = 485_{10} = (111100101)_2
$$

Contrariamente all'LSB, la prima cifra è chiamata Most Significant Bit (MSB).

# Rappresentazione di Interi

Possiamo considerare due casi:

- interi senza segno - unsigned integer: si intendono solo i positivi
- interi con segno - signed ingteger: siintendono i positivi ed i negativi

Immaginiamo che il computer possa utilizzare una word di N byte per rappresentare un intero (sia signed che unsigned) : N byte = N * 8 bit = Wbit

Avendo a disposizione W bit è possibile rappresentare i valori binari da 0 a 2^W-1

Nel caso si voglia rappresentare gli interi signed il bit più significativo viene utilizzato per indicare il segno

Convenzionalmente, 0 è per il + ed 1 èer il meno.

In tal caso, quindi, con W bit si possono rappresentare gli interi compresi tra (-2^W-1 - 1) e + (2 ^ W-1 - 1)

# Numeri rali

Nell'ambito di un computer, l'approssimazione di $\mathbb{R}$ espressa da "numeri reali" indica più precisamente un'approssimazione (finita) dei numeri razionali.

Concettulamente, un numero "reale" è rappresentato dalla giustapposizione di due numeri:

- se W bit sono disponibili, i primi W_r indicano la parte intera, i rimanenti W_f la parte frazionaria. Tale rappresentazione è detta a virgola fissa (fixed point).

La modalità di rappresentazione più diffusa è quella a virgola mobile (floating point), che utilizza due valori.

Il primo è la *mantissa*, interpretato come numero frazionario tra -1 ed 1, il secondo è la caratteristica, usato come esponente.

Si basa sulla notazione esponenziale, secondo cui 

$$
r = m * b^c
$$

# Rappresentazione di Caratteri

Anche i caratteri sono rappresentati mediante codici binari.

Più in generale si parla di "simboli" per specificare oltre agli usuali caratteri alfabetici, anche i simboli che idnicano:

- le cifre (decimali)
- la punteggiatura
- i simboli speciali (blank, carriage return, linefed, ...)

Per poter codificare univocamente i caratteri è necessaria una corrispondenza biunivoca tra questi e un opportuno sottoinieme degli interi:

 -standard ASCII
 - UNICODE

## UNICODE

Codifica di tutti i caratteri possibili - delle lingue attualmente vive - di alcune lingue morte

Più di 110 k caratteri.


