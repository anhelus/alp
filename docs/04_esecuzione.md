# Esecuzione di programmi

La macchina di von Neumann è in grado di eseguire programmi espressi in un opportuno linguaggio macchina
- per le macchine reali, il linguaggio macchina è codificato secondo codici binari o esadecimali

Si suppone che il programma da eseguiresia caricato in memoria prima dell'esecuzione. può essere quindi caricato a partire da qualche memoria di massa su cui è stato precedentemente registratot, fornito in input dal programmatore, etc

Si suppone che il programma sia suddiviso logicamente in due parti.

una parte di *dati*, di *I/O* e di supporto, calcolati e temporanei, su cui operano le istruzioni;

ed una parte logica, rappresentativa dell'insieme delle istruzioni che devono essere eseguite

# Ciclo Fetch-Decode-Execute

L'esecuzione del programma avviene ripetendo iterativamente le fasi di 

- Acquisizione (fetch) dell'istruzione da eseguire
- Interpretazione (DECODE) dell'istruzione
- Esecuzione (EXECUTE)

In pratica:

- il contenuto del PC viene caricato nel CIR
- il PC viene aggiornato con l'indirizzo dell'istruzione successiva,
- l'istruzione del CIR viene decodificata ed eseguita, eventualmente accedendo ai dati

