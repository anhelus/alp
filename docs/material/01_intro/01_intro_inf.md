# 1.1 - Introduzione all'informatica

## Una definizione di Informatica

Non c'è modo migliore che partire con una definizione per introdurre l'informatica. Per farlo, partiamo da una (breve) analisi del termine.

*Informatica* è, infatti, una crasi delle parole *infor(mazione)* ed *(auto)matica*, e ciò suggerisce che la disciplina tratti, in maniera generica, di *automatizzazione dell'informazione*. Ciò, tradotto in "linguaggio corrente", implica la *gestione automatizzata* di informazioni.

Ed è proprio questo il focus dell'informatica: gestire in maniera automatica una serie (più o meno rilevante) di informazioni

Questo, infatti, è la traduzione italiana del francese _informatique_, crasi delle parole _informa(tion)_ ed _(automa)tique_. Intuitivamente, possiamo dedurre che la disciplina tratti quindi di "informazioni automatiche" o, per meglio dire, _automatizzazione delle informazioni_.

E, se ci pensiamo, è proprio di quello che si occupa l'informatica, ovvero di gestire in maniera automatica una serie più o meno rilevante di informazioni, correlate ad un qualsiasi aspetto della nostra vita, siano esse le nostre foto su Facebook, il nostro libretto universitario oppure i dati dei nostri conti corrente bancari: tutte queste informazioni vengono elaborate in maniera (più o meno) automatica.

Proviamo ad arricchire questa prima, un po' generica, definizione. Per farlo, sfruttiamo un'altra denominazione straniera, ovvero quella inglese, lingua nella quale l'informatica è chiamata _computer science_. Quello che notiamo di questa definizione è il termine _science_, che ci suggerisce come l'informatica, in realtà, sia basata su solide fondamenta scientifiche: per capirci, infatti, i "padri fondatori" della materia erano prevalentemente dei matematici, uno fra tutti il celebre Alan Turing.

L'ultimo fattore da tenere in conto è che l'informatica rappresenta uno vero e proprio _pilastro_ della società moderna. Tutto ciò che utilizziamo al giorno d'oggi, dallo smartphone che stiamo usando per leggere questo documento, al computer mediante il quale è stato scritto, fino ad arrivare alle nostre auto, o anche ai termostati nelle nostre caldaie, sono basati su tutte le evoluzioni informatiche (ed elettroniche) succedutesi a partire dal Secondo Dopoguerra.

Ecco, quindi, che possiamo dare una definizione più completa di informatica, presa direttamente dal dizionario Oxford Languages:

!!!quote "L'informatica"
    L'informatica è la scienza che si occupa dell'_ordinamento_, del _trattamento_ e della _trasmissione_ delle _informazioni_ per mezzo dell'_elaborazione elettronica_, la quale rende possibile gestire e organizzare le ingenti masse di dati prodotte dal moderno sviluppo sociale, scientifico e tecnologico.

Ora, non è tanto importante memorizzare questa definizione, quanto piuttosto comprenderne la portata: l'informatica è ovunque, e conoscerla ci dà l'accesso alle porte di quello che è il mondo odierno.

## Informatica ed informazione

Esiste un'altra definizione di informatica, questa volta legata al concetto di *informazione*, quest'ultima a sua volta definita come insieme di *dati* ed *intepretazione* degli stessi.

In particolare, l'informatica può essere definita come *studio teorico, analisi, progettazione, realizzazione ed applicazione degli algoritmi che descrivono e trasformano l'informazione*. 

!!!tip "L'informatica ai tempi dei mobilifici svedesi"
    Immaginiamo di doverci recare presso una nota catena di mobilifici svedesi per acquistare un tavolino. Questo sarà composto da una serie di componenti, come viti, bulloni, o pannelli, che andranno a costituire i *dati* a nostra disposizione. Contestualmente, avremo a disposizione un manuale da utilizzare per realizzare il mobile, che rappresenta l'*interpretazione* da dare agli stessi. Concettualmente, l'informatica studia l'algoritmo, definito sul manuale (interpretazione), che, a partire dalle componenti (dati) permette di ottenere il risultato desiderato.

I più attenti avranno sicuramente notato come manchi ancora qualcosa alle definizioni ed ai concetti che abbiamo introdotto finora. Infatti, l'informatica è così presente nelle nostre vite perché permette di svolgere in maniera semplice e *trasparente* compiti complessi. Ad esempio, il sistema di controllo della stabilità della nostra auto si abilita in maniera automatica, e ci impedisce di fare staccate degne del Valentino Rossi del 2004 grazie ad un sistema informatico. Stesso vale per il sistema che ci permette di acquistare l'ultimo gadget alla moda dal nostro sito di e-commerce preferito: con la semplice pressione di un tasto svolgeremo "automaticamente" una serie di operazioni che, un tempo, avrebbero previsto il recarsi fisicamente in negozio, scegliere il prodotto, consegnare i contanti al commesso, e ritornare a casa col bottino.

Ciò ci riconduce al concetto di *automazione*: l'informatica, infatti, utilizza quasi sempre sistemi *automatizzati* di gestione dell'informazione.

Ovviamente, esistono sorgenti di informazioni diverse: ad esempio, l'informazione può provenire da Internet, oppure da un hard disk attaccato al nostro computer, o anche in un video visto su YouTube. Contestualmente, le tipologie di informazione sono eterogenee: le informazioni provenienti da Internet sono di tipo testuale, mentre i video sono chiaramente multimediali. La natura eterogenea delle informazioni richiede quindi una rappresentazione *uniforme*. Vediamo come questo sia reso possibile dal concetto di *linguaggio*.

## Linguaggi

Ora, per comprendere e veicolare l'informazione dobbiamo tenere in conto alcuni fattori. Il primo, e forse il più intuitivo, è che l'informazione deve essere in qualche modo "scritta" o "letta" su un *supporto fisico*. La seconda, invece, è che per veicolare con efficacia l'informazione è necessario adottare un insieme di regole condivise che ne permettano l'interpretazione; questo insieme di regole è comunemente chiamato *linguaggio*.

!!!tip "L'informatica ai tempi dei mobilifici svedesi"
    Nel mobilificio di cui sopra il supporto fisico scelto per veicolare l'informazione è (come prevedibile) il manuale, sia esso cartaceo o in formato PDF. Il linguaggio usato per veicolare l'informazione è invece di tipo grafico, anche se ai più può apparire poco comprensibile.

Un linguaggio è costituito da due commponenti:

* un *alfabeto*, che altro non è se non un insiemme di simboli;
* una *grammatica*, definita nel senso di insieme di regole sintattiche e semantiche che permettono di strutturare ed interpretare i simboli dell'alfabeto.

Esempio classico di alfabeto è quello latino, che utilizziamo comunemente per scrivere in occidente; tale alfabeto, se strutturato secondo regole sintattiche e semantiche proprie di una grammatica, permette di veicolare informazione scritta in un certo linguaggio. Ad esempio, il testo che state leggendo questo testo è, sperabilmente, italiano.

!!!tip "Quanti simboli in un alfabeto?"
    Affinché abbia un senso commpiuto, un alfabeto deve avere almeno due simboli distinti. Usare un unico simbolo sarebbe quantomeno *irrealistico*.

La scelta di un linguaggio segue essenzialmente due criteri, esplicitati di seguito.

1. *Universalità*: questo criterio implica che i sistemi che elaborano l'informazione adottino un linguaggio universalmente condiviso, di modo tale che due dispositivi differenti siano in grado di comunicare tra loro. Immaginiamo ad esempio che bel problema sarebbe non poter comunicare con la nostra dolce metà se questa avesse uno smartphone basato su un sistema operativo diverso da quello del nostro!
2. *Semplicità*: questo criterio è legato alla natura *reale*, e non astratta, dei dispositivi coinvolti nell'elaborazione automatica dell'informazione. I nostri computer e smartphone, infatti, altro non sono se non un "ammasso" di circuiti elettronici, i quali operano essenzialmente come *interruttori*. Sì, esattamente come quello che vi permette di accendere o spegnere la luce nella vostra stanza, soltanto *molto più in piccolo*: infatti, ciascuno di questi interruttori, chiamati *transistor*, occupa soltanto un paio di nanometri. La nostra esperienza ci dice che gli interruttori sono estremamente semplici da operare: infatti, possono essere soltanto *aperti*, non facendo quindi scorrere la corrente (e facendo sì che la lampadina sia spenta), o *chiusi*, facendo scorrere la corrente al loro interno, ed accendendo la lampadina. In altri termini, gli interruttori hanno soltanto due possibili *stati*.

Ovviamente, esiste un linguaggio che soddisfa entrambi i requisiti precedentemente menzionati. Questo linguaggio deve adottare un sistema di simboli quanto più semplice possibile, ed essere adatto ad effettuare operazioni di tipo numerico; un linguaggio che soddisfa tutti questi requisiti è quello *binario*, nel quale sono contenuti esclusivamente i simboli $0$ ed $1$.

Prima di approfondire i concetti alla base dell'utilizzo del codice binario, tuttavia, è importante discutere di come si [rappresentano i dati in un elaboratore](02_data_repr.md).
