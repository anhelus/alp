<!-- https://www.geeksforgeeks.org/software-engineering-classification-of-software-requirements/?ref=shm -->

La classificazione dei requisiti software è una delle priorità nel processo di sviluppo software. ORganizza i nostri requisiti in diverse categorie che li rendono ssemplici da gestire, prioritizzare e tracciare. I tipi principali di requisiti del sofwrtaare sono funzionaoli, non funzionali e di dominio.

Secondo lo standard IEEE 729, un requisito è definito come segue:

* una *condizione o capacitùà richiesta da un utente per risolvere un problema o raggiungere un obiettivop

* una condizione o capacità che deve essere posseduta da un sistema op da un suo compoennte per soddisfare un contratto, standard, specifica, o altri documenti formali
* una rappresentazione documentata di una condizione o capacità, come espresso nei punti precedenti

I requisiti software sono di tre tipi: funzionali, non funzionali e di dominio.

##### Requisiti funzionali

I requisiti funzionali descrivono quello che dovrebbe fare il software. Definiscono le funzioni o le feature che il sistema deve quindi avere. Esempi classici sono:

* autenticazione utente: il sistema deve permettere agli utenti di loggarsi usando uno username ed una password
* funzionalità di ricerca: il software deve permettere agli utenti di ricercare prodotti per nome ocategoria
* generazione di report: il sistema deve essere in grado di generare i report delle vendite per una specificata range di date

I requisiti funzionali specificano le azioni che il software deve eseguire. Qeuste sono le feature e funzionalità base che gli utenti si attendono dal software.

##### Requisiti non funzionali
I requisiti non funzionali descrivono come il software effetta un task, e non il task nello specifico. Definiscono quindi gli attributi di qualità, i criteri legati alle performance, ed eventuali vincoli. Esempi classici sono:

* performance: il sistema dovrebbe elaborare 1000 transazioni al Secondo
* usabilità: il sistma dovrebbe essere facile da usare ed avere un'interfaccia user-friendly
* affidabilità: il sistema dovrebbe garantire un uptime del 99,9%
* sicurezza: i dati dovrebbero essere cifrati durante la trasmissione e la memorizzazione

I requisiti non funzionali riguardano quindi il comportamento, la qualità ed i vincoli del sistema. Grazie ad essi, possiamo assicurare che il softawre rispetti certi standard di performance, usabilità, affidabilità e sicurezza.

##### Requisiti di dominio

I requisiti di dom,inio sono specifici per il dominio o industria nelle qali iil software opera. Includoo terminologia, regole e standard rilevanti per quello specifico dominio. Esempi sono:

* healthcare: il software deve adeguarsi alla normativa europea per la gestione dei dati dei pazienti
* finanza: il sistema deve aderire agli standard europei ed al questionario MFID per gli investimenti
* e-commerce: il software deve suportare diversi gateway di pagamento come PayPal, Satisfay, o le carte di credito.

I requisiti di dominio riflettono le specifictà ed i vincoli di una certa industrai. Si assicurano che il software sia rilevante e si adatti alle regole e standard specifiche dell'industria.

## Cosa sono i requisiti funzionali?

I requisiti funzionali sono i requisiti che l'utente finale chiede nello specifico come funzionalità di base del sitema. Potrebbero essere, ad esmpio, calcoli o manipolazioni specifici per i dati, specifici processi di business, interazione con utenti, o altre funzionalità che definiscono che funzione un sistema è probabile effettui. Queste funzioanlità devono essere necessariamente incorporate nel sistema come parte del contratto. Queste sono rappresentate o espresse nella forma dell'input da dare alò sstema, l'operazione effettuata, e dell'output atteso.

Sono i requisiti che l'utente richiede che è possibile vedere direttamente nel prodotto finale, a differneza dei requisiti non funzionali. Per esempio, in un sistema di gestione degli ospedali, un dottore dovrebbe essere in grado di recuperare l'informazione dei suoi pazienti.

Ogni requisito funzionale ad alto livello può avere diverse interazioni o dialoghi tra il sistema e il mondo esterno.

Per descrivere accuratamente i requisiti funzioanli, gli scenari applciativi devono essere numerati.

Ci sono molti modi di esprimere i requisiti funzioanli, come ad esempio il lingauggio natruarel, un linguaggio strutturato o formattato senza necessariaemnte una sintassi rigorosa, e dei lingauggi di specifica formael con una sintassi vera e propria.

I requisiti funzioanli sono ache detti *specifiche funzioanli*.

## Cosa sono i requisiti non funzionali?

I requisti non funzionali sono in pratica i vincoli in termini di qualità che il sistemad eve soddisfare a seconda del contrattodi rpogetto. I requistii funzioanli onon sono quindi correlati alle funzionalità del ssistma, ma definiscono come il sistema dovrebbe comportaris. La priorità o estensione secondo cui questi fattori sono implementati varia da un progetto all'altro. Sono chiamati anche requistii non-comportamentali, e di solito si occupano di portabilità, sicurezza, manutenibilità, affidabilità, scalabilità, performance, riusabilità e flessibilità.

I requisiti non funzionali sono classificati nei seguenti tipi:

* vincoli di interfaccia
* vincoli di performacne (tempo di risposta, sicurezza, spazio di memorizzazione)
* vincoli operativi
* vincoli di ciclo vitale (mantuenabibità, portabilità, etc)
* vincoli economici

Il processo dello specificare dei requisiti non funzioanli rihciede la consocenza delle funzionalità del sistema, così come della conoscenza del contesto all'interno del quale il sistema opererà.

Sono divisi in due categorie.

* Qualità di esecuzione, che consistono in cose come sicurezza ed usabiilità, osservabili a runtime.
* qualità di evoluzione, che consistono di cose come testabilità, manutenibilità, estensibilità e scalabilità, che sono integrate nella struttura statica del sistema software.

## COsa sono i domain requiremetns?

I requisiti di dominio sono i requisiti che sono caratteristici di una particolare cateogria o dominio di porogetti,. I requisiti di dominio possonoe ssere funzionali o non fnzionali. Ingegnerizzazrli è un processo continuo di definizione proattiva di tutti i requisiti per tutte le applciazioni prevedibili da sviluppare nella linea del prodotto software. Le funzioni base che un sistema di uno specifico dominioop deve necessariemnte esibire vengono in questa categoria. Pr esempio, in un software accademico che mantiene il registro di una scuola o college, la funzionalità di essere in grado dia ccedere alla lista di facolità e studenti di ogni grado è un requisito di dominio. QUesti requisiti sono quindi identificati dal modello di dominio e non sono user specific.

## Classificazione dei requisiti software

Altri tipi di classificazione Dei requiristi software possono esesre:

* requisiti utente: qeusti descrivono quello che l'utente della piattaforma cerca nel sistema software. I requisiti utente sono nroamlemntre espressi in linguaggio naturale e sono tipicamente raccolti mediante intereviste, questionari o feedback utente.
* requisiti di sitema: questi requistii specificano le caratteristiche tecniche del sistema software come la sua architettura, i requisiti hardware, i componenti software e le interfacce. I requisiti di sistema sono tipicamnte espressi in termini tecnici e sono speso usati come una base per la progettazione del sistema.
* requisiti di business. questi requisti descrono l'obiettivo di business e gli obiettivi che il sistema software deve ottenere. I requisiti di businness sono normalemnte espressi in termini di revenue, market share, customer satisfaction, ed altre metriche di business.
* requisiti di interfaccia: questi requistii specificano l'interazione tra oò soste,a spftware e sostemi o componenti esterni, come database, web service o altre applciazioni software.
* requisiti di design: quiesti requistii descrivono il disegno tecnico del sistema sofwtaere. Includono informaizoni circa l'archietttura dels oftwaree, le strutture dati, gli algoritmi, ed altri aspetti tecnici del software.

Classificando ai requisiti di software, diventa più semplice gestire, prioritizzare e documentarli in maniera efficace. Qeusto aiuta anche ad assicurare che tutti gli aspetti importanti del sistema siano consdierati durante il procesos di sviluppo.

## Vantaggi della classificazione dei requisiti software

1. migliroe organizzazione: classificare i requisiti software ci permette di aiutare ad organizzarli in gruppi che sono più semplici da gestire, prioritizzare e tracciare nel processo di sviluppo
2. comunciazione migliroata: la classificazione chiara dei requisiti rende semplice comunicarli agli stakeholder, sviluppatori, ed altri membri del team. Ciò assicura anche ch tutti siano in accordo su quello che viene richiesto.
3. qualità migliroe: classificando i requistii, dei potenziali conflitti o gap possono essere idetnificati prima nello processo di sviluppo. Questo riduce il rischio di errori, omissioni, o incomrpensioni, portando ad un software a più alta qualità.
4. tracciabilità migliraota: classfiicare i requistii aitua a stabilire la tracciabilità, che è essenziale per dimostrare la compliance con standard di quailtà o regolatori.

## svantaggi

1. complessità: classificare i requisit software può essere com,plesso, specialmente se ci sono molti stakeholder con diverse necessità o requisiti. Può anche richiedere molto tempo per identificare e classificare tutti i requisiti.
2. struttura rigida: una struttura di classificazione rigida limita l'abiitò di adattarsi ai cambi o alle evoluzioni richieste durante il procesos di sviluppo. può anche portare ad un approccio che previene l'integrazione di nuove idee.
3. misclassificazion: sbagliare la classificazione dei requisiti può portare ad errori o incomrpensioni che possono essere costosi da correggere successivamente nel processo di sviluppo

In definitiva, i vantaggi del classificare i requisiti software sono più degli svantaggi, in quanto aituano ad assicurare che il sistema softwre rispetti i requisiti di tutti gli stakeholder e venga consegnato in tempo, in budget, e con la qualità necessaria.

in conclusione, classificare i requisti software foirnsice numerosi benefici, come una migliore organizzazione, comunciazioni migliroati, una qualità migliroe, e tracciabilità migliroata. Categoirizzando in maniera sistematica i requisiti i tema di sviluppo possono essere sicuri che il software rispetti i requisiti degli stakeholder mentre osserva gli standard e fornisce efficienza ed efficacia.

