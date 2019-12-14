#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
char frase[60],rep[100],temporal[100];
char pal, glob_car;
int longitud,i,j,inicial,acertado=0,temp=0,oportunidades=5;
int repetido=0,gano=0, k;
int cont;
int exit = 0;
char esp_tit[] = "												";
void escanear(), ganar(), munequito();

void aux(int x, int y){
	HANDLE oCur;
	oCur = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posicion;
	posicion.X = x;
	posicion.Y = y;
	SetConsoleCursorPosition(oCur, posicion);
}


int main() {
	printf ("%sJHON F. KENNEDY\n\n\n", esp_tit);
	printf("                      ********************\n");
	printf("                      *Juego del Ahorcado*\n");
	printf("	              ******************** \n \n");
	printf("       \n		Programado por Ariel Penelas y Leandro Cotti.\n\n\n");
	
	printf("Introduzca la palabra a adivinar:\n\n\t\t\t");
	escanear();
	system("cls");
	system("color 07");
	
	longitud = 0;
	inicial = 0;
	j = 0;
    
	rep[0] = ' ';
	rep[1] = '\0';
    
    do{
		system("cls");
		temp=0;
		if(inicial == 0){
			for(i=0;i<strlen(frase);i++){
				if(frase[i] == ' ') {
					temporal[i] = ' ';
					longitud++;
				}else{
					temporal[i] = '_';
						longitud++;
				}
			}
		}
		inicial = 1;
		temporal[longitud] = '\0';
		for(i=0;i<strlen(rep);i++){
			if(rep[i] == toupper(pal)){
				repetido = 1;
				break;
			}else{
				repetido = 0;
			}
		}

		if(repetido == 0){
			for(i=0;i<strlen(frase);i++){
				if(frase[i] == toupper(pal)) {
					temporal[i] = toupper(pal);
					acertado++;
					temp=1;
				}
			}
		}

		if(repetido == 0){
			if(temp == 0){
				oportunidades -= 1;
			}
		}else{
			printf("Ya se ha introducido esa letra");
			printf("\n\n");
		}
		
		printf("\n");
		
		for(i=0;i<strlen(temporal);i++) {
			printf(" %c",temporal[i]);
		}
		
		printf("\n");
		
		if(strcmp(frase,temporal) == 0) {
			gano = 1;
			break;
		}
		
		printf("\n");
		printf("Letras acertadas: %d",acertado);
		printf("\n");
		printf("Oportunidades restantes: %d",oportunidades);
		printf("\n");
		
		rep[j] = toupper(pal);
		j++;
		
		if (oportunidades==0){break;}
		
		printf("\nIntroduzca una letra:\n\n\t\t\t");munequito();
		pal = getch();
		while(toupper(pal) < 65 || toupper(pal) > 90){pal = getch();}
    }while(oportunidades != 0);
    
    
	if(gano){
		printf("\n\n");
		ganar();
	}
	else{
		system("color 04");
		printf("\n\n");
		printf("HAS PERDIDO.");
	}
	
	printf("\n\n\t");
	getch();
	return 0;
}
void escanear(){
	int cont = 0;
	char car = getch();
	while(toupper(car) >= 65 && toupper(car) <= 90){
		if(car != 8){
			frase[cont] = toupper(car);
			printf("*");
			cont++;
		}
		else{
			if(cont > 0) cont--; 
			else cont = cont;
			
			printf("\b \b");
			frase[cont] = ' ';
		}
		car = getch();
	}
	if(car != 13){escanear();}
	system("cls");
}
void ganar(){
	system("cls");
	system("color 02");
	aux(19,25);printf("Pulse enter para reiniciar o escape para salir.");
	while(k>=0){
	for(k=0;k<5000;k++){
		if (kbhit()) exit = 1;
	aux(19,6);printf("AA      AA         PPPP          AAAAAA  ");
	}
	for(k=0;k<5000;k++){
		if (kbhit()) exit = 1;
	aux(19,7);printf("AA      AA        PP  PP        AA    AA ");
	}
	for(k=0;k<5000;k++){
		if (kbhit()) exit = 1;
	aux(19,8);printf("AA      AA       PP    PP        AA      ");
	}
	for(k=0;k<5000;k++){
		if (kbhit()) exit = 1;
	aux(19,9);printf("AAAAAAAAAA      PPPPPPPPPP        AA     ");
	}
	for(k=0;k<5000;k++){
		if (kbhit()) exit = 1;
	aux(19,10);printf("AA      AA     PP        PP         AA  ");
	}
	for(k=0;k<5000;k++){
		if (kbhit()) exit = 1;
	aux(19,11);printf("AA      AA    PP          PP    AA    AA");
	}
	for(k=0;k<5000;k++){
		if (kbhit()) exit = 1;
	aux(19,12);printf("AA      AA   PP            PP    AAAAAA ");
	}
	for(k=0;k<5000;k++){
		if (kbhit()) exit = 1;
	aux(1,14);printf("  PPPPPP          AAAA         PPP     PP         AAAA         PPPPP        AAAAAAA ");
	}
	for(k=0;k<5000;k++){
		if (kbhit()) exit = 1;
	aux(1,15);printf("PP               AA  AA        PPPP    PP        AA  AA        PP   PP     AA     AA");
	}
	for(k=0;k<5000;k++){
		if (kbhit()) exit = 1;
	aux(1,16);printf("PP              AA    AA       PP PP   PP       AA    AA       PP    PP    AA     AA");
	}
	for(k=0;k<5000;k++){
		if (kbhit()) exit = 1;
	aux(1,17);printf("PP   PP        AAAAAAAAAA      PP  PP  PP      AAAAAAAAAA      PP     PP   AA     AA");
	}
	for(k=0;k<5000;k++){
		if (kbhit()) exit = 1;
	aux(1,18);printf("PP     PP     AA        AA     PP   PP PP     AA        AA     PP    PP    AA     AA");
	}
	for(k=0;k<5000;k++){
		if (kbhit()) exit = 1;
	aux(1,19);printf("PP     PP    AA          AA    PP    PPPP    AA          AA    PP   PP     AA     AA");
	}
	for(k=0;k<5000;k++){
		if (kbhit()) exit = 1;
	aux(1,20);printf("  PPPPPPP   AA            AA   PP     PPP   AA            AA   PPPPP        AAAAAAA ");
	}
	if (kbhit()) exit = 1;
	system("cls");
	aux(19,25);printf("Pulse enter para reiniciar o escape para salir.");
	}
}
void munequito(){
	printf("\t\t  같같�  ");
	printf((oportunidades < 0) ? "\t\t 같   같" : "\t\t 같XXX같");
	printf((oportunidades < 0) ? "\t\t같     같" : "\t\t같XXXXX같");
	printf((oportunidades < 0) ? "\t\t 같   같" : "\t\t 같XXX같");
	printf("\t\t  같같�  ");
	
	printf((oportunidades < 1) ? "\t\t    |\n|\n|\n|\n|\n|\n|\n|\n|\n|\n" : "");
}


