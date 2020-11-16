#include <stdio.h>
#include <math.h>


int calcola_area_quadrato() {
	int lato = 10;
	int area = lato * lato;
	lato = lato + 5;
	printf("Ho aggiornato il valore del lato a %d \n", lato);
	return area;
}

int calcola_perimetro_quadrato() {
	int lato = 10;
	int perimetro = lato * lato;
	return perimetro;
}

//int main() {
//	static int lato = 5;
//	int area = calcola_area_quadrato();
//	int perimetro = calcola_perimetro_quadrato();
//	printf("Il valore dell'area e': %d\n", area);
//	printf("Il valore del perimetro e': %d\n", perimetro);
//	printf("Il valore del lato e': %d\n", lato);
//	return 0;
//}

