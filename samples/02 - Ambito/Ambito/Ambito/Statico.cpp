#include<stdio.h> 

int incrementa() {
	int contatore = 0;
	contatore++;
	return contatore;
}

int main() {
	printf("Il valore del contatore � %d \n", incrementa());
	printf("Il valore del contatore � %d \n", incrementa());
	return 0;
}