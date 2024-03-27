
Nella [lezione precedente](../01_informatics/lecture.md) abbiamo introdotto una prima definizione del concetto di informatica.

Esistono altre definizioni dell'informatica particolarmente legate al concetto di *informazione*, quest'ultima definita come insieme di *dati* ed *intepretazione* degli stessi.

!!!tip "L'informazione ai tempi dei mobilifici svedesi"
    Immaginiamo di doverci recare presso una nota catena di mobilifici svedesi per acquistare un tavolino con cui studiare il corso di Informatica per l'Ingegneria. Il nostro tavolino sarà composto da un insieme di dati, ovvero le singole parti come viti, bulloni, assi, etc., ed interpretazione, ovvero l'insieme di istruzioni, definite nel manuale, che dobbiamo utilizzare per realizzare il nostro mobile.

In particolare, l'informatica può essere definita come *studio teorico, analisi, progettazione, realizzazione ed applicazione degli algoritmi che descrivono e trasformano l'informazione*. 

!!!tip "L'informatica ai tempi dei mobilifici svedesi"
    Concettualmente, l'informatica studia l'algoritmo, definito sul manuale, con cui creare il nostro mobile. Di conseguenza, se questo ci risulta essere incomprensibile, possiamo tranquillamente dare la colpa ad un informatico.

##### Il supporto fisico

Abbiamo quindi definito l'informatica come la scienza che veicola la diffusione e la trasformazione dell'informazione. Ciò implica diverse necessità di cui tenere conto: la prima, e forse più intuitiva, è che l'informazione deve essere in qualche modo *veicolata* mediante un *supporto fisico*.

!!!tip "Mobilificio svedese ed informazione"
    Appare evidente come il supporto fisico scelto dal famoso mobilificio svedese sia il manuale cartaceo.

##### Il linguaggio e l'informazione

La seconda, importantissima necessità è quella di utilizzare un insieme di regole comuni che permetta la trasmissione ed interpretazione dell'informazione. Questo insieme di regole comuni è comunemente chiamato *linguaggio*.

!!!tip "Mobilificio svedese e linguaggio"
    Il manuale del mobilificio svedese ha un suo linguaggio, seppur poco comprensibile ai più.

Un linguaggio è costituito da un *alfabeto* e da un'insieme di *regole* sintattiche e semantiche.

L'alfabeto altro non è se non un insieme di simboli: un esempio sono i simboli con cui vengono redatte queste pagine, così come anche gli alfabeti cirillici o cinesi. Un altro esempio di alfabeto, magari meno intuitivo, è dato dai simboli necessari a rappresentare i numeri arabi.

Per quello che riguarda invece le regole sintattico/semantiche, queste permettono di combinare i simboli dell'alfabeto in costrutti anche complessi, ed interpretarli in maniera appropriata. Un esempio (teoricamente) banale sono le regole logiche e grammaticali della lingua italiana: ad esempio, è necessario coniugare correttamente i verbi (specie i congiuntivi), usare in maniera appropriata la punteggiatura, oppure ancora dotare ciascuna frase di soggetto, complemento oggetto, e verbo. Ma questi principi si applicano anche alla rappresentazione di espressioni algebriche mediante numeri arabi, nella quale i simboli delle operazioni hanno una determinata priorità, così come le parentesi utilizzate.

!!!tip "Alfabeti e linguaggi"
    Sottolineamo come, affinché abbia un senso compiuto, un alfabeto deve avere almeno due simboli distinti. Il manuale del mobilificio rientra in questa definizione.

## Sistemi automatici per la rappresentazione dell'informazione

I più attenti avranno sicuramente notato come l'informatica utilizzi spesso dei sistemi *automatici* per gestire l'informazione. Come intuibile, il computer, che nell'immaginario comune è sinonimo di informatica, serve proprio a questo.

Ovviamente, esistono sorgenti di informazioni diverse: ad esempio, l'informazione può provenire da Internet, oppure da un hard disk attaccato al nostro computer, o anche in un video visto su YouTube. Contestualmente, le tipologie di informazione sono eterogenee: le informazioni provenienti da Internet sono di tipo testuale, mentre i video sono chiaramente multimediali. La natura eterogenea delle informazioni richiede quindi una rappresentazione *uniforme*. 

!!!tip "Uniformità e video"
    Se le informazioni non fossero uniformi, non potremmo scambiarcele. Banalmente, il video girato mediante il nostro smartphone non potrebbe essere visualizzato dal dispositivo del nostro amico, e viceversa.

Per elaborare e scambiare l'informazione, quindi, viene quindi adottato un *linguaggio* comune. La scelta del linguaggio segue basilarmente due criteri: *universalità* e *semplicità*.

Intuitivamente, il primo criterio ci dice che i sistemi che elaborano l'informazione in maniera automatica devono adottare un linguaggio "universale", di modo tale che due dispositivi differenti siano in grado di comunicare tra loro appoggiandosi ad una base comune. Immaginate, ad esempio, se non fosse possibile inviare un messaggio al vostro amico soltanto perché i vostri smartphone sono di produttori differenti: comunicare sarebbe un bel problema.

Per quello che riguarda invece la *semplicità*, questa è necessaria a causa della natura *intrinseca* dei dispositivi che elaborano l'informazione. I nostri computer e smartphone, infatti, sono composti da una serie più o meno complessa di circuiti elettronici, i quali lavorano essenzialmente combinando (in maniera più o meno complessa) una serie di *interruttori* chiamati *transistor*. Pensate alle lampadine di casa: per accendere la lampadina dovremo *chiudere* un interruttore, in modo che passi della corrente attraverso il circuito elettrico che collega la lampadina alla centrale più vicina, mentre per spegnerla dovremo *aprire* questo interruttore. Bene, i circuiti elettrici alla base dei nostri computer si comportano come una serie estremamente complessa di lampadine: ciascuna parte può essere aperta o chiusa e, conseguentemente, veicolare una certa informazione piuttosto che un'altra. Abbiamo quindi due possibili *stati* per ciascun transistor, ovvero *aperto* e *chiuso*: di conseguenza, è necessario usare il linguaggio più semplice possibile per modellare una situazione di questo tipo.

Ovviamente, esiste un linguaggio che soddisfa i requisiti precedentemente menzionati: questo è chiamato *sistema binario*, e verrà approfondito nella [prossima lezione](03_binary.md).
