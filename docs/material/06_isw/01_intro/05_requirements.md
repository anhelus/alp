# 6.1.5 - Requisiti del software

Immaginimo di voler tornare a costruire il nostro videogame. Prima di iniziare a programmare, è importantissimo capire *cosa* costruire.

!!!warning "Il game design"
    Ignoreremo volontariamente l'intera tematica legata al game design. Sappiate però che esiste, ed è un aspetto fondamentale della progettazione di un videogioco.

Ok, immagina di voler costruire un videogioco. Prima di iniziare a programmare come un pazzo, devi capire COSA devi costruire. I requisiti del software sono proprio questo: una descrizione dettagliata di quello che il tuo videogioco (o qualsiasi altro software) deve fare. Sono un po' come le istruzioni di montaggio di un mobile IKEA, ma molto più precise e complete.

Pensa a un videogioco come un edificio. I requisiti sono i progetti architettonici, le specifiche dei materiali, le normative di sicurezza... tutto quello che serve per costruire l'edificio correttamente.

Perché sono importanti?

Definiscono il "cosa": Senza requisiti chiari, rischi di costruire qualcosa di diverso da quello che volevi. Immagina di costruire un gioco di corse e scoprire a metà sviluppo che il cliente voleva un simulatore di Formula 1 iper-realistico, mentre tu stavi facendo un racing arcade alla Mario Kart.

Evitano fraintendimenti: Clienti (o team di design) e sviluppatori devono essere sulla stessa pagina. I requisiti servono a chiarire ogni dubbio fin dall'inizio.

Forniscono una base per il test: Come fai a sapere se il tuo videogioco funziona correttamente se non hai un elenco chiaro di cosa deve fare? I requisiti sono la base per creare i test che verificano che tutto funzioni come previsto.

Aiutano a gestire i costi e i tempi: Definire i requisiti aiuta a stimare il lavoro necessario e a evitare sorprese costose durante lo sviluppo. Se a metà sviluppo ti accorgi che devi aggiungere una funzionalità enorme che non era prevista, i tempi e i costi esplodono.

Tipi di Requisiti

I requisiti si dividono principalmente in due categorie:

Requisiti Funzionali: Definiscono cosa il software deve fare. Sono le funzionalità, le azioni, i comportamenti che il gioco deve avere.

Esempio (Call of Duty):

Il gioco deve permettere al giocatore di muovere il personaggio usando i tasti WASD (o il joystick).

Il gioco deve permettere al giocatore di sparare con diverse armi.

Il gioco deve avere una modalità multiplayer online.

Il gioco deve salvare i progressi del giocatore.

Il gioco deve permettere al giocatore di personalizzare l'equipaggiamento del personaggio.

Se il giocatore completa una missione, deve ricevere una ricompensa.

Requisiti Non Funzionali: Definiscono come il software deve funzionare. Sono le caratteristiche di qualità, le performance, i vincoli che il gioco deve rispettare.

Esempio (The Witcher 3):

Performance: Il gioco deve girare a 30 FPS (frame per secondo) su una Playstation 4 standard.

Usabilità: L'interfaccia utente deve essere intuitiva e facile da usare.

Sicurezza: Il gioco deve proteggere i dati dell'utente (password, progressi) da accessi non autorizzati.

Affidabilità: Il gioco non deve crashare più di una volta ogni 10 ore di gioco.

Portabilità: Il gioco deve essere compatibile con Windows, Playstation e Xbox.

Scalabilità: Il gioco deve poter supportare fino a 64 giocatori in modalità multiplayer contemporaneamente.

Come si scrivono i requisiti?

Non c'è una formula magica, ma ecco alcuni consigli:

Sii specifico: Evita frasi vaghe come "il gioco deve essere divertente". Definisci cosa rende il gioco divertente in termini di funzionalità e meccaniche di gioco.

Sii misurabile: I requisiti non funzionali, in particolare, devono essere misurabili. Invece di dire "il gioco deve essere veloce", specifica "il gioco deve caricare le texture in meno di 2 secondi".

Sii realistico: Non chiedere l'impossibile. Tieni conto delle risorse disponibili, dei tempi di sviluppo e delle limitazioni tecnologiche.

Coinvolgi tutti: I requisiti devono essere definiti in collaborazione con il team di design, gli sviluppatori, i tester e, se possibile, anche con i potenziali giocatori (tramite sondaggi o focus group).

Esempio concreto:

Immagina di dover definire i requisiti per un nuovo gioco di Pokémon.

Requisito Funzionale: "Il giocatore deve poter catturare i Pokémon selvatici lanciando delle Pokéball."

Requisito Non Funzionale: "La probabilità di catturare un Pokémon con una Pokéball standard deve essere del 50% se la sua salute è inferiore al 25%."

In sintesi: i requisiti sono il fondamento di qualsiasi progetto software di successo. Senza requisiti chiari, rischi di costruire un videogioco che nessuno vuole giocare, che non funziona correttamente o che costa troppo. Prenditi il tempo necessario per definire i requisiti in modo accurato e vedrai che il tuo progetto ne trarrà enormi benefici. Pensa a un gioco come Among Us che ha un requisito non funzionale di matchmaking veloce per mantenere l'engagement dei giocatori. Un matchmaking lento distruggerebbe l'esperienza di gioco, anche se le meccaniche di gioco rimanessero identiche.