# 5.6 File System

## Cos'è un file system?

Un **file system** è la componente del sistema operativo che organizza, memorizza e recupera i dati su supporti di memorizzazione (dischi, SSD, USB). Fornisce una visione astratta dei dati come **file** e **directory**, nascondendo i dettagli hardware del dispositivo.

## Il file

Un **file** è un contenitore di dati logicamente correlati, identificato da un nome. Ogni file ha:

* **nome**: leggibile dall'utente (es: `relazione.docx`);
* **estensione**: indica il tipo (`.c`, `.txt`, `.jpg`, `.pdf`);
* **percorso** (path): posizione nella gerarchia delle directory;
* **metadati**: dimensione, data di creazione, permessi, proprietario.

### Attributi tipici di un file

| Attributo | Descrizione |
|-----------|-------------|
| Nome | Identificatore simbolico |
| Dimensione | Numero di byte |
| Tipo | Regolare, directory, pipe, socket, link |
| Permessi | Lettura, scrittura, esecuzione (rwx) |
| Proprietario | Utente e gruppo |
| Timestamp | Creazione, modifica, accesso |
| Puntatori ai blocchi | Dove sono i dati su disco |

## Struttura delle directory

Le directory sono organizzate in una gerarchia **ad albero**, con una radice (root):

* **Unix/Linux**: radice `/`, separatore `/` (es: `/home/studente/documenti/`).
* **Windows**: radice `C:\`, separatore `\` (es: `C:\Users\Studente\Documenti\`).

Ogni directory contiene file e altre directory, formando una struttura che parte dalla radice.

### Path assoluti e relativi

* **Assoluto**: parte dalla radice (`/home/studente/file.txt` o `C:\Users\studente\file.txt`)
* **Relativo**: parte dalla directory corrente (`documenti/file.txt`)
* **Puntatori speciali**: `.` (directory corrente), `..` (directory padre)

## Organizzazione fisica dei dati su disco

Il disco è diviso in **blocchi** (tipicamente 4 KB). Un file occupa uno o più blocchi. Il file system deve tenere traccia di quali blocchi appartengono a quale file.

### Metodi di allocazione

#### Allocazione contigua

I blocchi di un file sono **consecutivi** sul disco.

**Vantaggi**: accesso sequenziale veloce, semplice.
**Svantaggi**: frammentazione esterna, difficile da espandere.

#### Allocazione a lista concatenata

Ogni blocco contiene un puntatore al blocco successivo.

**Vantaggi**: nessuna frammentazione esterna.
**Svantaggi**: accesso casuale lento (deve scorrere i blocchi), spazio perso per i puntatori.

#### Allocazione indicizzata (inode)

Un blocco speciale (**inode**) contiene l'elenco dei puntatori a tutti i blocchi del file.

**Vantaggi**: accesso casuale veloce, facile da espandere.
**Svantaggi**: overhead dell'inode. Usato da Unix/Linux (ext4) con una struttura a puntatori multipli (diretti, indiretti, doppiamente indiretti).

## Inode in Unix/Linux

L'**inode** è la struttura dati che descrive un file nel file system Unix. Contiene i metadati (eccetto il nome) e i puntatori ai blocchi dati.

```
inode:
  - permessi (rwxr-xr-x)
  - proprietario (UID/GID)
  - dimensione
  - timestamp
  - contatore link (nlink)
  - puntatori ai blocchi:
      [0] ... [11] → puntatori diretti (12 × 4 KB = 48 KB)
      [12] → puntatore indiretto (1 blocco indice = 1024 blocchi = 4 MB)
      [13] → puntatore doppiamente indiretto (4 GB)
      [14] → puntatore triplamente indiretto (4 TB)
```

Il **nome** del file non è nell'inode: è memorizzato in una **directory entry** (dentry), che associa nome → inode number.

## Directory in Unix/Linux

Una directory è un file speciale che contiene una lista di coppie `(nome, numero_inode)`. Quando apriamo un file (`/home/user/doc.txt`):

1. Si legge l'inode root (numero 2).
2. Si cerca `home` nella directory root → si ottiene il numero inode di `home`.
3. Si cerca `user` nell'inode di `home`.
4. Si cerca `doc.txt` nell'inode di `user`.
5. Si ottiene l'inode di `doc.txt` e si accede ai dati.

## Permessi (Unix/Linux)

I permessi sono divisi in tre classi:

| Classe | Simbolo | Descrizione |
|--------|---------|-------------|
| User | `u` | Proprietario del file |
| Group | `g` | Gruppo del file |
| Others | `o` | Tutti gli altri |

Ogni classe ha tre permessi:

| Permesso | Simbolo | Valore |
|----------|---------|--------|
| Lettura | `r` | 4 |
| Scrittura | `w` | 2 |
| Esecuzione | `x` | 1 |

Esempio: `rwxr-xr--` = proprietario (7 = rwx), gruppo (5 = r-x), altri (4 = r--).

## Tipi di file system

| File system | OS | Caratteristiche |
|-------------|----|-----------------|
| FAT32 | Windows | Semplice, max 4 GB per file |
| NTFS | Windows | Journaling, permessi, compressione, max 16 EB |
| ext4 | Linux | Journaling, inode, backward compatibile |
| ZFS | FreeBSD/Linux | Pool di storage, checksum, snapshot, compressione |
| APFS | macOS | Crittografia, cloni, space sharing |

## Journaling

I file system con **journaling** (NTFS, ext3/ext4, APFS) registrano le operazioni in un **journal** (diario) prima di applicarle. Se il sistema si blocca, al riavvio si rilegge il journal e si completano/annullano le operazioni incomplete, evitando la corruzione del file system.

## Operazioni comuni sui file

| Operazione | Descrizione | Chiamata di sistema Unix |
|------------|-------------|--------------------------|
| Creare | Crea un nuovo file | `open()` con flag O_CREAT |
| Aprire | Prepara il file per l'accesso | `open()` |
| Leggere | Legge dati dal file | `read()` |
| Scrivere | Scrive dati nel file | `write()` |
| Chiudere | Rilascia il descrittore | `close()` |
| Cancellare | Rimuove il file | `unlink()` |
| Rinominare | Cambia nome/sposta | `rename()` |
| Ottenere attributi | Legge metadati | `stat()` |

