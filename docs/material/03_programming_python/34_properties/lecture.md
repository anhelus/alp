# 32 - Le proprietà

Python offre una caratteristica chiamata prorietà o, più propriamente, [`property()`](https://docs.python.org/3/library/functions.html#property), con la quale possiamo creare dei cosiddetti *attibuti gestiti* (*managed attributes*) per la nostra classe. Questi possono essere utilizzati quando abbiiamo bisogno di modificare la loro implementazione interna senza cambiare l'interfaccia pubblica della classe: in tal senso, avremo un'API stabile, che ci aiuterà ad evitare di causare die problemi a chi usa la nostra classe.

Le proprietà sono probabilmente il modo più popolare di craer attributi gestiti velocemente e in stile pythoninc.

In questo tutorial, vedremo come:

* creare property per le nostre classi
* effettuare la validazione lazy degli attributi e fornire dei computed attributes
* evitsre l'uso di metodi setter e getter per rendere le nostre classi più Pythonic
* creare propreità di sola scrittura, lettura o entrambe
* creare delle API consistenti e retrocompatibili per le nostre classi

Scriveremo anche alcuni esempi pratici che usano le property() per validare i dati di ingresso, calcolare i valori degli attributi dinamcieamente, efettuare il log del nostro codice, ed altro ancora. Per ottenere quanto pioù possibile da questo tutiorial, dobbiamo conoscere le basi della programmazione orientata agli oggetti e dei decorator.

## Gestire gli attributi nell nostre classi

QUando definiamo una classe in un linguaggiod i programmazione orientato agli oggetti, finiremo cone alcun  e istanze ed attributi di classe . In altre parole, avremo delle variabili che sono accessibili soltanto tattraverso l'istanza, la classe, o entrambi, a seconda del linguaggio. Gli attributi rappresentano lo stato interno di un dato oggetto, che spesso dovremo acceeere o mutare.

Tipicamente, abbiamo almeno due modi di gestire un attributo. O accediamo e mutiamo l'attributo direttamente, oppure iusamo dei metodi. I metodi sono funzioni collegate ad una data clases. Qeusti forniscono i comportamenti e le azioni che un oggetto può effettuare con i sudoi dati interni ed attributi.

Se espponiamo i nostri attributi all'utente, questi diventaono parte dell'API pubblica della nostra classe. I nostri utenti accedreanno e muteranno questi attributi dirtatamente nel loro codice. Il problema arrtiva quando dobbiamo cambiare la rappresentazione interna di un dato attributo.

Diciamo che stiamo lavorando sulla classe Cerchio. L'implementazione iniziale ha un soingolo attribnuto chiamato raggio. Finiamo di codificare la classe e la rendiamo disponibile a chi userà il nsotro codice. Questi usano il Cerchio nelc odice per creare numerosi progetti ed applicazioni.

Ora supponiamo che abbiamo un utente importante che ci chiede un nuovo requisito. Non vogliono che il Cerchio memorizzi il raggio. Hnano bisogno id un attributo poubblico chiamato diametro. 

A questo punto, rimuovere il raggio per iniziare ad usare il diatmetro può romepre il codice di alcuni tra i nostri utenti. Dobbiamo gestire questa situaizone in un modo che non si limiti a rimuovere semplicemente il raggio.

I linguaggi di programmazione come Java e C++ ci incoraggiano a non esporre mai i nsotri attributi per evitare questo tipo di pronblemi. Invece, dovrammo fornire dei metodi getter e setter, conosciuti come accessori e mutatori, rispettivamente,. Questi metodi opffrono un modo per modificare l'implementazione itnerna dei nostri attributi senza cambiare la nostra API pubblica.

!!!note "Nota"
    I getter ed i setter sono spesso considerati un anti-pattern, ed un segnale di un dessign carente in termini di OOP. L'argomento principale dietro questa fraes sta nel fatto che qeusti meotdi rompono l'inscapsulamento. CI permettono dia ccedre e mutare le componenti dei nostri oggetti.

Alla fine, questi linguaggi hanno bisogno di metodi setter e getter per Hèp non forniscono un modo per cambiare l'implementazione itnerna di un attirbuto se cambia un dato rewquisito. Cambiare l'implementazione itnerna richiederebbe delle modifiche all'API, che poossono rompere il codice dell'utente finale.

## L'approccio in Python

https://realpython.com/primer-on-python-decorators/
