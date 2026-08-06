# 4.3 Gerarchia di Memoria e Cache

## Il problema: velocità vs capacità

La CPU elabora i dati molto più velocemente di quanto la memoria RAM riesca a fornirglieli. Questo divario, chiamato **memory wall**, è uno dei principali colli di bottiglia dei calcolatori moderni.

| Tecnologia | Tempo di accesso tipico | Capacità tipica |
|------------|------------------------|-----------------|
| Registri CPU | ~0.3 ns (1 ciclo) | ~1 KB |
| Cache L1 | ~1 ns (3 cicli) | ~64 KB |
| Cache L2 | ~3 ns (10 cicli) | ~512 KB |
| Cache L3 | ~10 ns (40 cicli) | ~8 MB |
| RAM | ~100 ns | ~16 GB |
| SSD | ~100.000 ns (0.1 ms) | ~1 TB |
| HDD | ~10.000.000 ns (10 ms) | ~10 TB |

La soluzione è una **gerarchia di memoria**: più si sale, più la memoria è veloce, piccola e costosa per byte; più si scende, più è lenta, capiente ed economica.

## Principio di località

La gerarchia di memoria funziona grazie al **principio di località**:

* **Località temporale**: se un dato è stato usato, è probabile venga riusato a breve (es: variabili in un ciclo).
* **Località spaziale**: se un dato è stato usato, è probabile vengano usati anche dati adiacenti (es: array visitati sequenzialmente).

## La memoria cache

La **cache** è una memoria piccola e veloce che contiene copie dei dati usati più di frequente, collocata tra CPU e RAM.

### Funzionamento di base

1. La CPU chiede un dato a un indirizzo X.
2. La cache controlla se X è presente al suo interno (**cache hit**).
3. Se sì, il dato viene restituito in pochi cicli.
4. Se no (**cache miss**), il dato viene prelevato dalla RAM (centinaia di cicli) e copiato in cache per usi futuri.

L'efficacia si misura con il **tasso di hit** (hit rate): frazione di accessi risolti dalla cache. Un hit rate del 95% è tipico per una cache L1 ben dimensionata.

!!! tip "Hit rate"
    Con un hit rate del 95% e un miss che costa 100 cicli, il tempo medio di accesso è: `0.95 × 1 ciclo + 0.05 × 100 cicli = 5.95 cicli` — molto meglio di 100 cicli senza cache.

### Livelli di cache (L1, L2, L3)

* **L1**: divisa in L1I (istruzioni) e L1D (dati). Piccolissima (~32 KB per core) ma velocissima (~1 ns). Associata direttamente al core.
* **L2**: più grande (~256-512 KB per core), leggermente più lenta. Unica per dati e istruzioni.
* **L3**: condivisa tra tutti i core di un processore. Fino a 8-32 MB, più lenta ma riduce i miss che andrebbero in RAM.

### Mappatura cache

Come si decide quale blocco di RAM occupa quale posizione in cache?

* **Direttamente mappata**: ogni indirizzo di RAM può finire in una sola posizione della cache. Semplice ma soggetta a conflitti.
* **Fully associative**: ogni indirizzo può finire in qualsiasi posizione. Flessibile ma complessa.
* **Set-associative**: via di mezzo: la cache è divisa in *set*, ogni indirizzo può finire in uno specifico set in più *way*. È la soluzione più comune (4-16 way set-associative).

### Politiche di sostituzione

Quando la cache è piena e arriva un nuovo dato, quale blocco rimpiazzare?

* **LRU** (Least Recently Used): si rimuove il blocco usato meno recentemente.
* **FIFO** (First In, First Out): si rimuove il blocco più vecchio.
* **Random**: si rimuove un blocco a caso.
* **LFU** (Least Frequently Used): si rimuove il blocco usato meno frequentemente.

LRU è la più efficace per la località temporale, ma complessa da implementare in hardware.

### Politiche di scrittura

* **Write-through**: si scrive sia in cache che in RAM. Semplice, ma ogni scrittura è lenta.
* **Write-back**: si scrive solo in cache, aggiornando la RAM solo quando il blocco viene rimosso. Più veloce ma più complesso.

## Gerarchia di memoria completa

```
CPU (Registri)
  ↓ veloce, piccola, costosa
Cache L1
  ↓
Cache L2
  ↓
Cache L3
  ↓
RAM (memoria principale)
  ↓
SSD (memoria secondaria)
  ↓
HDD (memoria terziaria)
  ↓ lenta, grande, economica
```

I dati si spostano tra i livelli in blocchi di dimensione fissa, detti **cache line** (tipicamente 64 byte). Questo sfrutta la località spaziale: se accediamo a una variabile, viene caricato in cache tutto il blocco circostante.

## Memoria virtuale

La memoria virtuale è una tecnica che combina RAM e disco per dare l'illusione di una memoria grande quasi quanto il disco, ma veloce quasi quanto la RAM. Approfondiremo questo concetto nella sezione dedicata ai sistemi operativi.


