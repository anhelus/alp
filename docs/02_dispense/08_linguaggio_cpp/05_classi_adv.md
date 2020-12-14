## Copia di oggetti

Lo stnadard C++ prevede uno strumento apposito per effettuare la copia degli oggetti, chiamato **costuttore di copia**, che condivide le stesse particolarità della firma di un costruttore ordinario, ma si caratterizza per il fatto che il primo dei suoi parametri è un riferimetno ad un oggetto della stessa classe, mentre i parametri aggiuntivi, se presenti, sono opzionali.

Il compilatore provvede alla generazione autoamtica di un costruttore di copia.

Vediamo un costruttore di copia per la nostra classe.

```cpp
PersonaBase(const Persona& other);

Persona::PersonaBase(comst PersonaBase& other)
{
	nome = other.getNome();
	cognome = other.getCognome();
	eta = other.getEta();
}
```

L'uso standard di un costruttore di copia è quindi il seguente:

```cpp
PersonaBase truce("truce", "baldazzi", 18);
PersonaBase truceClone(truce);
```

E' importante sottolineare come il const viene usato perché un rvalue associato ad una const reference può sopravvivere al di là dell'istruzione in cui è contenuto. In altre parole, il costruttore di copia può essere usato non solo su un lvalue, ma anche sul risultato di un'espressione:

```cpp
PersonaBase copiaPersona(persona("pippo", "de pippi", 1));	// Ok
```

Nella precedente, alla varaibile copiaPersona viene assegnato il risultato di un'espressione, cioè un valore temporaneo. Se non usassimo il qualificatore cosnt, avremmo un errore di compilazione.

!!!note "Nota"
	C++ non impone l'uso della parola chiave `const` in un costruttore di copia. Omettendola, però, non è possibile utilizzare la forma precedente.

### semantica del costruttore di copia

il costruttore di copia non è differente da quello generato in maniera automatica dal compilatore. Infatti, la semantica generalmente applicata è quella della copia *membro a membro*.

Ciò non vale però quando una classe contiene dati membro che sono puntatori o reference: in questo caso, la copia si definisce come *superficiale* (shallow). in questo caso, un'istanza della classe eed una sua copia shallow sono legate, perché una modofica fatta ad un dato membro puntatore o reference di una si riflette automaticamente nell'altra.

In questi casi è necessario quindi implementare una deep copy:

```cpp
class PersonaBase {
	// ...
	private:
		int *puntatoreEta;
}

PersonaBase::PersonaBase(const PersonaBase& other)
{
	// shallow copy
	nome = other.getNome();
	cognome = other.getNome();
	eta = other.getEta();
	// deep copy
	puntatoreEta = new int;
	if (other.puntatoreEta != nullptr) {
		*puntatoreEta = *(other.puntatoreEta);
	}
}
```

Nella deep copy, viene prima allcoata la memoria per l'attributo puntatoreEta, e successivamente viene copiato in essa il valore puntato da other.ptr.

### Operatore di assegnamento di copia

Quando si parla di copia, oltre al costruttore, occorre tenere in conto un altro costrutto, ovvero l'operatore di assegnamento di copia `=`.

Questo entra in gioco ogni volta che ad un oggetto viene riassegnato un valore in una fase successiva alla sua dichiarazione.

AD esempio:

```cpp
PersonaBase piero("piero", "scamarcio", 18);
PersonaBase tizio("una", "persona", 22);
tizio = piero;
```

In C++, gli operatori son assimilabili a delle funzioni operanti su argomenti di tipo ben preciso; per questo, è possibile effettuarne l'overload. Tuttavia, possiamo definire questo operatore come membro di una classe:

```cpp
PersonaBase& operator=(const PersonaBase& other);

operator=(const PersonaBase& other) {
	nome = other.getNome();
	cognome = other.getCognome();
	eta = other.getEta();
	return *this;
}
```

Notiamo come la firma dell'operatore `=` presenti delle analogie con quella del costruttore di copia, e la sua implementazione è identica; ciò che cambia nei fatti è l'istruzione return *this.

Notiamo inoltre che l'operatore di assegnamento viene generato automaticamente dal compilatore, e quindi valgono le considerazioni fatte altrove.

## Costruttore di spostamento

Utilizzare in modo eccessivo il costruttore di copia causa un degrado delle prestazioni generali del programma. Di conseguenza, onde evitare eccessivi decadimenti nelle prestazioni, gli ultimi standard hanno introdotto delle opportune modifiche con il *costruttore di spostamento*.

## ALLOCAZIONE DINAMICA
