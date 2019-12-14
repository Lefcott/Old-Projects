#include <iostream>
#include <windows.h>
#include <time.h>
/* Programa para comprobar probabilidades */
int num, cont2 = 0, cant = 0, patron[4];
float car = 0, sec = 0;
int main(){
	srand(time(NULL));
	for(int x = 0; true; x++){
		num = rand()%2;
		printf("\t\t%s: %d", (num == 0) ? "CARA" : "SECA", x);
		if(num == 0) car++;
		else sec++;
		printf("\tCara: %.12f % , seca: %.12f % \n", car * 100 / (car + sec), sec * 100 / (car + sec));
	}
	return 0;
}
