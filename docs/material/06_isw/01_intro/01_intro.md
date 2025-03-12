# 6.1 - L'Ingegneria del Software

Avete mai scritto un programma? Se state leggendo questo documento, la risposta è, presumibilmente, *sì*. Adesso, possiamo avere diverse situazioni, sinteticamente raggruppabili in due diverse casistiche. 

1. Avete scritto software abbastanza basilare, contenuto in una manciata di file sorgenti.
2. Avete scritto anche software complesso, con dipendenze multiple, magari stipulando contratti specifici con committenti, o lavorando in un team.

Nel primo caso, è probabile che siate riusciti ad organizzare il tutto semplicemente "tenendo a mente" i requisiti base del software e le relazioni che intercorrono tra funzioni, script, e via discorrendo. Nel secondo caso, invece, è plausibile che abbiate dovuto in qualche modo utilizzare tecniche e strumenti per strutturare al meglio il vostro lavoro, utilizzando magari dei processi agili, interagendo con i clienti alla scoperta dei requisiti, oppure ancora testando e manutenendo il software.

E' quindi chiaro come progetti software più complessi implichino una gestione necessariamente più strutturata: in tal senso, la disciplina dell'*Ingegneria del Software* si occupa proprio di fornire gli strumenti e le tecniche necessarie a produrre software di qualità e che rispecchino i requisiti posti dall'utente. Per approfondire il concetto, dobbiamo partire da due definizioni. In primis, abbiamo il concetto di *software*:

!!!quote "Il software"
    Per software si intende un programma, o un insieme di programma, che soddisfano uno o più requisiti dell'utente.

Abbiamo poi il concetto di *ingegneria* o, per meglio dire, *ingegnerizzazione*:

!!!quote "Ingegnerizzazione"
    L'*ingegnerizzazione* è un processo che prevede la progettazione e realizzazione di un manufatto, bene, o servizio atto a soddisfare un particolare scopo, trovando una soluzione efficace in termini di costi ad un determinato problema.

L'Ingegneria del Software (ISW) è quindi il processo di progettazione, sviluppo, test e manutenzione di  un software. L'ISW è quindi un approccio *sistematico* e *disciplinato* allo sviluppo software, mirato alla creazione di software di alta qualità, affidabile e manutenibile.

L'ISW è un campo in rapida evoluzione, nel quale vengono costantemente sviluppati e proposti nuovi tool e tecnologie per migliorare lo sviluppo software, utilizzando i quali è possibile creare software di alta qualità, affidabile e manutenibile, rispettando contestualmente i requisiti posti dagli utenti, creando programmi consistenti, funzionali e, soprattutto, rispettosi dei vincoli di sviluppo.

!!!warning "Le dimensioni contano"
    Ricollegandoci a quanto abbiamo detto prima, l'ISW "mostrano i muscoli" soprattutto nel caso di progetti di grandi dimensioni, perdendo senso nel caso siano applicati a programmi "limitati".

##### Principi chiave dell'ISW

Riassumiamo in breve alcuni dei principi alla base dei concetti dell'ISW.

| Principio | Breve descrizione |
| --------- | ----------------- |
| **Modularità** | Suddividere il software in componenti di piccola dimensione, sviluppabili, testabili e, soprattutto, riutilizzabili in maniera indipendente. |
| **Astrazione** | Nascondere i dettagli implementativi di ciascun componente software, esponendo agli altri componenti soltanto le funzionalità necessarie. |
| **Incapsulamento** | Racchiudere i dati e le funzioni di un oggetto in una singola unità, proteggendone lo stato interno da interferenze esterne. |
| **Riutilizzabilità** | Creare componenti che possano essere utilizzati in più progetti, risparmiando di conseguenza tempo e risorse. |
| **Manutenibilità** | Aggiornare e migliorare il software in maniera regolare, allo scopo di risolvere bug, aggiungere nuove feature, e risolvere eventuali vulnerabilità. |
| **Test** | Verificare che il software rispetti i requisiti indicati, e risulti essere scevro da bug. |
| **Design pattern** | Proporre dei pattern per la soluzione di problemi ricorrenti della progettazione del software. |
| **Sviluppo Agile** | Usare processi di sviluppo iterativi ed incrementali, focalizzandosi su soddisfazione dell'utente, rilascio rapido di nuove versioni e flessibilità. |
| **Integrazione continua** | Integrare in maniera rapida e continua i cambiamenti nel sorgente, rilasciandoli il prima possibile in ambiente di produzione. |

##### Obiettivi dell'ISW

Possiamo anche definire una serie di obiettivi che l'ISW vuole peseguire.

| Obiettivo | Breve descrizione |
| --------- | ----------------- |
| **Manutenibilità** | Il software dovrebbe poter evolvere rispettando requisiti mutevoli nel tempo. |
| **Efficienza** | Il software non dovrebbe usare in maniera inefficace le capacità di calcolo dei dispositivi utilizzati. |
| **Correttezza** | Il software dovrebbe rispettare i requisiti specificati dai suoi utilizzatori. |
| **Riusabilità** | Il software dovrebbe essere suddiviso in moduli, i quali dovrebbero essere facilmente riutilizzati allo scopo di sviluppare nuovi prodotti software. |
| **Testabilità** | Il software dovrebbe essere progettato per facilitare cicli di test per valutare il rispetto dei requisiti e delle funzionalità. |
| **Affidabilità** | Il software dovrebbe essere in grado di svolgere i suoi compiti prefissati in un certo periodo di tempo. |
| **Portabilità** | Il software dovrebbe poter essere trasferito in maniera semplice da un sistema ad un altro. |
| **Adattabilità** | Il software dovrebbe garantire il rispetto di vincoli di sistema ed utente anche nel caso di modifiche sostanziali. |
| **Interoperabilità** | Diverse unità funzionali del software dovrebbero essere in grado di elaborare i dati in maniera cooperativa e non concorrente. |

##### Programmi e software

Quando parliamo di *programma* non parliamo necessariamente di (prodotto) *software*. Infatti, possiamo definire il programma come un insieme di istruzioni date ad un computer per svolgere un compito specifico; invece, il software è un programma reso disponibile per scopi solitamente commerciali, documentato, e fornito di un'apposita licenza. Di conseguenza, possiamo affermare che il programma è uno degli step nello sviluppo del software.

##### Vantaggi e svantaggi dell'ISW

I vantaggi nell'uso di un approccio sistematico e disciplinato allo sviluppo del software sono:

| Vantaggio | Breve descrizione |
| --------- | ----------------- |
| **Qualità** | Seguire i principi dell'ISW permette di ottenere software con un numero limitato di bug ed un'affidabilità più elevata. |
| **Produttività** | L'utilizzo di strumenti e metodologie moderne può rendere più lineare il processo di sviluppo, aumentando quindi la produttività degli sviluppatori. |
| **Manutenibilità** | Il software progettato e sviluppato usando le pratiche dell'ISW è più facile da manutenere ed aggiornare nel tempo. |
| **Riduzione dei costi** | Identificando e risolvendo i potenziali problemi nei primi stage del processo di sviluppo, l'ISW può aiutare a ridurre il costo nel tempo legato all'introdurre nuove feature e risolvere bug. |
| **Soddisfazione utente** | Coinvolgendo gli utenti nel processo di sviluppo, e creando del software che rispetta le loro necessità, l'ISW può aumentare la soddisfazione utente. |
| **Collaborazione** | L'uso dell'approccio agile e dell'integrazione continua permette ai team di collaborare al meglio. |
| **Scalabilità** | Un software progettato per essere scalabile può gestire un numero variabile di utenti e transazioni. |
| **Sicurezza** | Un software opportunamente testato secondo i principi definiti dall'ISW è spesso meno vulnerabile e più sicuro. |

Per ciò che riguarda gli svantaggi invece:

| Svantaggio | Breve descrizione |
| ---------- | ----------------- |
| **Costi iniziali** | Implementare un approccio sistematico e disciplinato allo sviluppo può richiedere parecchie risorse, oltre che un investimento significativo in termini di strumentazione e training. |
| **Flessibilità** | Seguire dei principi prestabiliti può comportare delle rigidità, limitando in alcune situazioni il rapido adattamento a requisiti mutevoli. |
| **Burocrazia** | Usare l'ISW può creare un ambiente burocratizzato, in cui è necessario redigere un gran numero di documenti, il che può rallentare lo sviluppo. |
| **Complessità** | Con l'aumento del numero di strumenti e meotodologie, i principi dell'ISW può diventare complessa e difficile da gestire. |
| **Creatività** | Il focus sul processo di sviluppo può limitare la creatività e l'innovazione. |
| **Curva di apprendimento** | Il processo di sviluppo può essere complesso e richiede l'apprendimento di numerosi strumenti. |
| **Dipendenza dai tool** | L'ISW fa largo affidamento a degli strumenti che, se non propriamente  configurati o incompatibili con il software in uso, possono causare diversi problemi. |
| **Manutenzione** | I processi alla base dell'ISW richiedono una manutenzione regolare per assicurarsi che il software venga eseguito in maniera efficiente. |
