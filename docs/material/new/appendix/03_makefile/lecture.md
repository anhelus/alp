# 7.4 Makefile e Automazione della Build

## Cos'è Make?

**Make** è un tool di automazione che compila programmi a partire da un file di configurazione chiamato **Makefile** (o `makefile`). Make determina quali parti del programma vanno ricompilate in base alle dipendenze tra i file.

## Perché usare Make?

Compilare manualmente programmi con più file sorgente è tedioso e soggetto a errori:

```bash
gcc -c main.c -o main.o
gcc -c utils.c -o utils.o
gcc -c network.c -o network.o
gcc main.o utils.o network.o -o programma
```

Con Make basta scrivere una volta le regole e poi lanciare `make`.

## Struttura di un Makefile

Un Makefile è composto da **regole** di questa forma:

```makefile
target: dipendenze
	comandi
```

* **target**: il file da generare (eseguibile, .o).
* **dipendenze**: i file necessari per creare il target.
* **comandi**: i comandi shell per generare il target (preceduti da **TAB**, non spazi).

## Esempio base

```makefile
programma: main.o utils.o
	gcc main.o utils.o -o programma

main.o: main.c utils.h
	gcc -c main.c -o main.o

utils.o: utils.c utils.h
	gcc -c utils.c -o utils.o

clean:
	rm -f *.o programma
```

Esecuzione:

```bash
make        # compila il target "programma"
make clean  # pulisce i file oggetto e l'eseguibile
```

## Variabili

Rendono il Makefile più flessibile e leggibile:

```makefile
CC = gcc
CFLAGS = -Wall -O2
LDFLAGS =
OBJS = main.o utils.o
TARGET = programma

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
```

### Variabili automatiche

| Variabile | Significato |
|-----------|-------------|
| `$@` | Nome del target |
| `$<` | Prima dipendenza |
| `$^` | Tutte le dipendenze |
| `$*` | Nome del file senza estensione |

## Regole implicite (pattern rules)

Make ha regole predefinite per compilare `.c` in `.o`. Un Makefile minimale può essere:

```makefile
CC = gcc
CFLAGS = -Wall -O2

programma: main.o utils.o
	$(CC) $^ -o $@
```

Make sa già come trasformare `main.c` in `main.o` usando `$(CC) $(CFLAGS) -c`.

## Phony target

Alcuni target non rappresentano file reali (es: `clean`, `all`). Vanno dichiarati come **phony**:

```makefile
.PHONY: all clean

all: programma

programma: main.o utils.o
	$(CC) $^ -o $@

clean:
	rm -f *.o programma
```

Senza `.PHONY`, se esiste un file chiamato `clean`, Make penserebbe che sia aggiornato e non eseguirebbe i comandi.

## Un esempio completo

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11
LDFLAGS =
OBJS = main.o utils.o network.o
TARGET = programma

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

# debug build con flag aggiuntivi
debug: CFLAGS += -g -DDEBUG -O0
debug: clean all
```

## Makefile di esempio per il corso

Per i progetti di programmazione in C, questo Makefile è sufficiente:

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = programma

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
```

Basta salvare il codice in `programma.c` e usare:
* `make` per compilare
* `make run` per eseguire
* `make clean` per eliminare l'eseguibile

!!! tip "Make è più di un compilatore"
    Make può automatizzare qualsiasi operazione che dipenda da file: generare documentazione, eseguire test, deploy, backup. Un target `test` che lancia i test automatici è comune in molti progetti.


