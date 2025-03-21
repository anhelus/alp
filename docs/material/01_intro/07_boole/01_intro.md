# 1.7.1 - Algebra booleana

[Abbiamo già detto](../01_intro_inf.md) che gli elaboratori si basano sui *circuiti elettronici digitali* che, ad *alto livello*, possono essere visti come un insieme più o meno complesso di *interruttori*, proprio come quelli che possiamo trovare in un normalissimo impianto elettrico.

Per capirci meglio, pensiamo agli interruttori presenti nelle nostre case: questi sono caratterizzati esclusivamente da due stati di funzionamento, ovvero *aperto* e *chiuso*. Nello stato di funzionamento *aperto*, il circuito viene "interrotto", rendendo impossibile il passaggio della corrente; ciò, di conseguenza, impedisce che le lampadine nella stanza si accendano. Nello stato di funzionamento *chiuso*, invece, la corrente scorre normalmente nel circuito, illuminando le lampadine presenti nella stanza.

!!!tip "Interruttori e resistenza"
    I più esperti noteranno che il circuito aperto ha *resistenza infinita*, il che significa che la corrente che scorre è nulla. Invece, il circuito chiuso ha *resistenza nulla*, il che significa che la corrente che scorre è massima (non infinita).

Sfruttando il funzionamento base dei circuiti, è possibile modellare delle situazioni più o meno complesse. Facciamo un semplice esempio nel mondo reale: immaginiamo due stanze adiancenti, ciascuna dotata di una porta dalla quale è possibile dedurre se la luce sia o meno accesa all'interno della singola stanza. Ponendoci come osservatori esterni, potremo trovarci in una tra le seguenti casistiche:

* *caso 1*: entrambe le luci sono accese, per cui è plausibile che ci siano due persone, una in ciascuna stanza;
* *caso 2*: entrambe le luci sono spente, per cui è plausibile che non ci sia nessuno;
* *caso 3*: una luce è accesa, per cui è plausibile che ci sia una persona nella stanza illuminata.

Se ponessimo quindi la domanda *c'è qualcuno in casa*, potremmo rispondere in maniera *affermativa* nel caso 1 (c'è una persona nella prima stanza, ed una persona nella seconda) e nel caso 3 (c'è una persona nella prima stanza o nella seconda stanza), ed in maniera *negativa* nel caso 2. Immaginiamo di estendere questo scenario ad una casa a più stanze: è facile comprendere come, combinando delle semplici informazioni di tipo binario, si riesca a modellare uno scenario arbitrariamente complesso.

!!!note "Interpretazione del risultato ottenuto"
    Notiamo come l'osservazione dello stato di accensione delle luci non ci permetta di definire con certezza *quante* persone ci sono in casa, ma soltanto che *c'è qualcuno in casa*. In altri termini, non possiamo dare una risposta *quantitativa*, ma soltanto una *binaria*.

A questo punto è lecito farsi una domanda: esiste un modo *formale* per determinare se è presente una persona in casa a partire dalle precedenti considerazioni partendo da una serie di regole ben definite? Prevedibilmente, la risposta a questa domanda è affermativa, ed è definita grazie alle regole introdotte dall'*algebra di Boole*.

Formalmente, l'algebra di Boole venne introdotta nel XIX secolo da Boole allo scopo di *scomporre* ed *analizzare* in maniera algebrica problemi di [logica proposizionale](https://it.wikipedia.org/wiki/Logica_proposizionale).

Questo tipo di logica si basa sulla presenza delle cosiddette *proposizioni logiche*, ovvero degli "enunciati" che possono assumere valore *vero* o *falso*. Per fare un esempio "banale", proviamo ad osservare la seguente figura.

![ball_box](./images/ball_box.png)

Guardando l'immagine precedente, è facile dire che la proposizione *la palla è dentro la scatola* assume valore vero, così come lo assumono proposizioni del tipo *la palla è verde* e *la scatola è blu*. Ciò non vale per altre proposizioni, come ad esempio *la scatola è dentro la palla* oppure *la scatola è rossa*.

Da notare come ognuna di queste proposizioni sia *atomica*, o *semplice*, nel senso che viene espresso esclusivamente un predicato: ad esempio, il rapporto intercorrente tra palla e scatola, oppure ancora il colore di uno dei due oggetti. Un quadro completo della situazione richiederebbe l'uso di predicati *composti* da più proposizioni atomiche: ad esempio, *la palla è dentro la scatola* E *la palla è verde* E *la scatola è blu*.

L'algebra Booleana si occupa di formulare un insieme di regole per definire se i predicati composti siano veri o falsi a partire dai singoli predicati che li compongono. Per farlo, si avvale di una serie di operazioni fondamentali, che approfondiremo nella [prossima lezione](02_ops.md).
