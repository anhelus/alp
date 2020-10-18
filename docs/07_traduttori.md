# TRADUTORE

Programma che traduce in linguaggio
macchina programmi in un linguaggio di livello
superiore
– Analizza i messaggi (comandi) e verifica che siano
scritti scritti (codificati) (codificati) in un linguaggio linguaggio noto
• Correttezza sintattica
– Attribuisce alle sequenze di simb l o i l’opportuno
significato in modo da eseguire le giuste azioni
• Interpretazione unica di ogni istruzione
– Fa parte del software di sistema
• Livello intermedio della gerarchia software‐hardware

Nei p og a r r mmi ad a tol live oll ope a o r n su due
tipi di entità:
– Istruzioni
• Molto più potenti che nel linguaggio macchina
– Strutture di dati
(sequenze, insiemi, alberi, ecc.)
• Non direttamente disponibili al livello di linguaggio
macchina
• Devono essere rappresentate in termini di bit, indirizzi
e legami tra locazioni

Interpreti
• Compilatori
– Specifici per ogni linguaggio
– Forniti entrambi dai sistemi di sviluppo del
software per i linguaggi supportati

• Dopo l’analisi sintattica, la traduzione procede
passo passo con l’esecuzione
– Traduzione ed esecuzione istruzione per istruzione
• Ogni istruzione istruzione tradotta tradotta tante volte quante viene
eseguita


PROGRAMMA ->
				INTERPRETE -> RISULTATI
DATI -> 

COMPILAZIONE


Il programma originale (Sorgente) è analizzato
sintatticamente e tradotto in codice oggetto,
quindi eseguito
– Traduzione Traduzione completamente completamente effettuata effettuata prima che
cominci l’esecuzione
• Ogni istruzione istruzione è tradotta tradotta una sola volta


PROGRAMMA -> COMPILATORE -> CODICE OGGETTO ->
												MACCHIAN FISICA -> RISULTATi
DATI -------------------------------------->

| Interpreti | Compilatori |
| -| -|

INTERPRETI
programma sorgente residente in memoria, semplici, efficienti, tempo e spazio, interattivi, erorri comprensibili riferiti al sorgente

COMPILATORI
programma sorgente non residente in memoria, ottimizzabili, efficienti, tempo e spazio, interattivi, errori scoperti prima ma riferiti al codice oggetto

# Processo di compilazione

Analisi Lessicale (Scanning)
– Lettura Lettura in sequenza sequenza di tutti i caratteri caratteri che
costituiscono il programma (il programma è visto
come un unica ’ stringa stringa di caratteri) caratteri)
– Divisione della stringa in token (segni di
interpunzione interpunzione, nomi di dati, operatori operatori, parole
riservate, ...)
– Nessun cont ll ro o

Analisi Sintattica (Parsing)
– Definizione della struttura struttura sintattica sintattica del
programma usando le regole del linguaggio
– Un gruppo di token raggruppati raggruppati secondo secondo la
strutturazione ottenua deve corrispondere a una
frase sintatticamente sintatticamente corretta corretta secondo secondo il
linguaggio adottato
– Se la frase non è si t tti t ntatticamente corretta viene
segnalato un messaggio d’errore

Generazione del Codice
– Creazione Creazione di istruzioni istruzioni in linguaggio linguaggio macchina macchina per
ogni elemento sintattico del programma
• L insieme ’insieme finale di queste istruzioni istruzioni è il programma programma
oggetto

Le fasi sono tra loro interrelate
– I moduli di p g ro ramma responsabili dell’analisi
sintattica possono utilizzare
• I moduli dell analisi dell’analisi lessicale lessicale per ottenere ottenere un token
• I moduli di generazione del codice per produrre il
codice oggetto dell’istruzione analizzata
• Per capire come vengono effettuate le analisi
è necessaria necessaria la teoria dei linguaggi linguaggi
