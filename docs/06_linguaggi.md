# Linguaggio

Insieme di sequenze di simboli chiamati parole appartenenti ad un lessico definito giustapposti secondo un'opportuna grammatica (o sintassi)

Per descriverlo è necessario un meta-linguaggio

In informatica un linguaggio è più precisamente definito come l'insieme di stringhe ottenute applicando le regole della relativa grammatica. Di conseguenza, una grammatica è formalismo per definire un linguaggio mediante l'imposizione di un metodo per la costruzione delle stringhe.

Le stringhe ottenute possono essere anlizzate da un punto di vista:

- sintattico (siverifica la correttezza della forma linguistica in cui è codificato)
- semantico (si individua il significato associato alla forma linguistica)
- pragmatico (si studiano gli usi e le utilità dei costrutti linguistici)

# Comunicazione diretta:

Requisiti per i due interlocutori:

l'estensore del messaggio (al momento della formulaizone) e il ricevitore (allar icezione) devono assegnare al messaggio uguale significato, ciascuno nel  proprio contesto

# Programma

E' un messaggio di comunicazione fra l'uomo e la macchinma.

rappresenta un insiem di frasi costruite secondo regole molto rigide: elimina le ambiguità nell'interpretazione dei comandi da parte della macchina.

Le istruzioni obbediscono a rigorose regole grammaticale.

# Comunicazione indiretta

E' il caso della comunicazione tra il programmatore ed il computer.

Il ricevitore non conosce il linguaggio usato per la stesura del messaggio.

L'estensore ed il ricevitore hanno un diverso grado di conoscenza del linguaggio.

Tra i due mancano adeugate convenzioni per un'interpretazione unica del messaggio

Occorre un *traduttore*

# Il Linguaggio Naturale

è usato per la comunucazione verbale tra esseri umani

Vi sono delle fonti di ambiguitpè, legati all'evoluzione (termini arcaici o neologismi), polisemia (parole con significati diversi a seconda del contesto), intrinseca (una vecchia porta la sbarra)

E' inadatto alla comunicazione con la macchina : l'umano deve quindi adattarsi ad un linguaggio consono.

# linguaggi di programmazione

- a basso livello: più vicini alla struttura reale della macchina ed al suo linguaggio
- ad alto livello: più vicini al linguaggio dei rpoblemi
- più facilid a comprendere per l'uomo
- portabili, utilizzabili, senza modifiche, su diversi tipi di macchine

# Ad alto livello

- procedurali:

descrivono i passi necessari per ottenere i risultati desiderati (si concentrano sul come)

basati sui concetti di variabile ed assegnamento

Es. C, C++, Python

- non procedurali

Esprimono le proprieotà dei risultati che si vogliono ottenere, ovvero il cosa

es. volendo ottenre la radice quadrata di y, ci interessa quel valore di x t.c. x*x = y

ad esempio, abbiamo Lisp e Prolog

# Sintassi

Pochi, semplici, rigide regole che indicano quali sono le istruzioni formali permesse

Il programma va accuratamente controllato dal punto di vista formale per garantire la correttezza sintattica. La codifica è solitamente ambigua o non interpretabile; il controllo è delegato al traduttore.

# Semantica

Riguarda il contenuto informativo ed il significato di una frase.

Esistono metodi per trattare formalmente la semantica dei linguaggi di progammazione, al fine di capire il comportamento dei programmi.

La semantica operazionale specifica come i costrutti del linguaggio sono eseguiti su una macchina astratta.

La semantica denotazionale definisce come denotare il significato dei (costruitti del) linguaggio

La semantica assiomatica determian il signficato dei (costrutti del) linguaggio usando regole di correttezza all'interno di una data logica

# esempio

Io ho andato -> errore sintattico

La penna sta mangiando -> corretta sintatticamente, ma errata sematnicametne

Tutti i bimbi sono buoni  e Tutti i buoni sono bimbi

CORRETTE -> SEMANTICA DIVERSA NONONSTANTE ABBIANO GLI STESSI ELEMENTI