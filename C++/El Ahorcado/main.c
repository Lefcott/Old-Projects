#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#define lon 26
char frase[lon],rep[100],temporal[100];
char pal, glob_car, salida;
int longitud, i, j, k, inicial, acertado = 0, temp = 0, ops = 6;
int repetido=0,gano=0, k;
int cont, bkp;
char esp_tit[] = "												";
void escanear(), ganar(), munequito(), draw();
int found(char car, int pos);

void aux(int x, int y){
	HANDLE oCur;
	oCur = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posicion;
	posicion.X = x;
	posicion.Y = y;
	SetConsoleCursorPosition(oCur, posicion);
}


int main(){
	system("MODE CON COLS=119 LINES=25");
	system("cls");
	system("color 0B");
	printf ("		                                                  	JHON F. KENNEDY\n\n\n");
	printf("                      ********************\n");
	printf("                      *Juego del Ahorcado*\n");
	printf("	              ******************** \n \n");
	printf(" \n \n \n Programado por Ariel Penelas y Leandro Cotti.\n\n\n");
	printf("Introduzca la palabra a adivinar:\n\n\t\t\t");
	escanear();
	
	longitud = 0;
	inicial = 0;
	j = 0;
    
	rep[0] = ' ';
	rep[1] = '\0';
    
    do{
		system("cls");
		temp=0;
		k = 0;
		if(inicial == 0){
			for(i = 0;i < strlen(frase); i++){
				if(frase[i] == ' ') {
					temporal[i] = ' ';
				}else{
					temporal[i] = '_';
				}
				longitud++;
			}
		}
		temporal[longitud] = '\0';
		for(i=0;i<strlen(rep);i++){
			if(rep[i] == pal){
				repetido = 1;
				break;
			}else{
				repetido = 0;
			}
		}
		if(repetido == 0){
			for(i=0;i<lon;i++){
				if(frase[i] == pal && pal != 0){
					temporal[i] = pal;
					acertado++;
					temp=1;
				}
			}
		}
		if(repetido == 0){
			if(temp == 0){
				ops -= (inicial == 1) ? 1 : 0;
			}
		}else{
			printf("Ya se ha introducido esa letra");
			printf("\n\n");
		}
		inicial = 1;
		printf("\n");
		
		for(i=0;i<strlen(temporal);i++){
			printf(" %c",temporal[i]);
		}
		
		printf("\n");
		
		if(strcmp(frase,temporal) == 0){
			gano = 1;
			break;
		}
		rep[j] = pal;
		j++;
		printf("\n");
		printf("Letras acertadas: %d",acertado);
		printf("\n");
		printf("Oportunidades restantes: %d",ops);
		printf("\nLetras introducidas: ");
		for(k = 0; k < 100; k++){
			if(found(rep[k], k + 1) == 0){
				printf("%c  ", rep[k]);
			}
		}
		
		if (ops==0){break;}
		munequito();
		aux(8, 7);printf("Introduzca una letra:");
		repetido = 0;
		temp = 0;
		pal = getch();
		pal = toupper(pal);
		while(pal < 65 || pal > 90) pal = toupper(getch());
    }while(ops > 0);
	if(gano){
		printf("\n\n");
		ganar();
	}
	else{
		system("color 04");
		system("cls");
		aux(5, 2); printf("AA      AA         PPPP          AAAAAA        PPPP      AAAAAAAA   PPPP      AAA      AAAA   AAA       PPPPPP");
		aux(5, 3); printf("AA      AA        PP  PP        AA    AA       PP  P     AA         PP  PP    AA AA     AA    AA AA    PP    PP");
		aux(5, 4); printf("AA      AA       PP    PP        AA            PP   PP   AA         PP   PP   AA  AA    AA    AA  AA   PP    PP");
		aux(5, 5); printf("AAAAAAAAAA      PPPPPPPPPP        AA           PP  PP    AAAAAAA    PP  PP    AA   AA   AA    AA   AA  PP    PP");
		aux(5, 6); printf("AA      AA     PP        PP         AA         PPPP      AA         PPPPP     AA  AA    AA    AA  AA   PP    PP");
		aux(5, 7); printf("AA      AA    PP          PP    AA    AA       PP        AA         PP  PP    AA AA     AA    AA AA    PP    PP");
		aux(5, 8); printf("AA      AA   PP            PP    AAAAAA        PP        AAAAAAAA   PP   PP   AAA      AAAA   AAA       PPPPPP ");
		aux(5, 10);printf("LFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFC");
		
		printf("\n\n");
		aux(42, 15);printf("La palabra era: %s", strupr(frase));
		aux(0, 20);printf("Pulse ENTER para reiniciar o escape para salir. \n \n");
	}
	
	salida = getch();
	while(salida != 13 && salida != 27) salida = getch();
	if(salida == 13){
		repetido = 0; ops = 6; gano = 0; cont = 0; acertado = 0; pal = 0;
		int x;
		for(x = 0; x < strlen(temporal); x++){
			temporal[x] = ' ';
		}
		for(x = 0; x < strlen(frase); x++){
			frase[x] = ' ';
		}
		for(x = 0; x < 100; x++){
			rep[x] = ' ';
		}
		main();
	}
	return 0;
	
}
void escanear(){
	int cont = bkp;
	char car = getch();
	while(toupper(car) >= 65 && toupper(car) <= 90 || car == 8){
		if(car != 8 && cont <= lon - 1){
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
	if(car != 13 || cont < 3){bkp = cont; escanear();} bkp = 0;
	system("cls");
}
void ganar(){
	system("cls");
	system("color 02");
	aux(19,25);printf("Pulse ENTER para reiniciar o ESCAPE para salir.");
	for(i = 0; i < 3; i++){
		for(k = 0; k < 500; k++){
			if (kbhit()) break;
		aux(19, 6); printf("AA      AA         PPPP          AAAAAA  ");
		}
		for(k = 0; k < 500; k++){
			if (kbhit()) break;
		aux(19, 7); printf("AA      AA        PP  PP        AA    AA ");
		}
		for(k = 0; k < 500; k++){
			if (kbhit()) break;
		aux(19, 8); printf("AA      AA       PP    PP        AA      ");
		}
		for(k = 0; k < 500; k++){
			if (kbhit()) break;
		aux(19, 9); printf("AAAAAAAAAA      PPPPPPPPPP        AA     ");
		}
		for(k = 0; k < 500; k++){
			if (kbhit()) break;
		aux(19, 10);printf("AA      AA     PP        PP         AA  ");
		}
		for(k = 0; k < 500; k++){
			if (kbhit()) break;
		aux(19, 11);printf("AA      AA    PP          PP    AA    AA");
		}
		for(k = 0; k < 500; k++){
			if (kbhit()) break;
		aux(19, 12);printf("AA      AA   PP            PP    AAAAAA ");
		}
		for(k = 0; k < 500; k++){
			if (kbhit()) break;
		aux(1, 14);printf("  PPPPPP          AAAA         PPP     PP         AAAA         PPPPP        AAAAAAA ");
		}
		for(k = 0; k <500; k++){
			if (kbhit()) break;
		aux(1, 15);printf("PP               AA  AA        PPPP    PP        AA  AA        PP   PP     AA     AA");
		}
		for(k = 0; k < 500; k++){
			if (kbhit()) break;
		aux(1, 16);printf("PP              AA    AA       PP PP   PP       AA    AA       PP    PP    AA     AA");
		}
		for(k = 0; k < 500; k++){
			if (kbhit()) break;
		aux(1, 17);printf("PP   PP        AAAAAAAAAA      PP  PP  PP      AAAAAAAAAA      PP     PP   AA     AA");
		}
		for(k = 0 ; k < 500; k++){
			if (kbhit()) break;
		aux(1, 18);printf("PP     PP     AA        AA     PP   PP PP     AA        AA     PP    PP    AA     AA");
		}
		for(k = 0; k < 500; k++){
			if (kbhit())break;
		aux(1, 19);printf("PP     PP    AA          AA    PP    PPPP    AA          AA    PP   PP     AA     AA");
		}
		for(k = 0; k < 500; k++){
			if (kbhit()) break;
		aux(1, 20);printf("  PPPPPPP   AA            AA   PP     PPP   AA            AA   PPPPP        AAAAAAA ");
		}
		system("cls");
		aux(19,25);printf("Pulse ENTER para reiniciar o escape para salir.");
	}
	draw();
}
void draw(){
		aux(19, 6); printf("AA      AA         PPPP          AAAAAA  ");
		aux(19, 7); printf("AA      AA        PP  PP        AA    AA ");
		aux(19, 8); printf("AA      AA       PP    PP        AA      ");
		aux(19, 9); printf("AAAAAAAAAA      PPPPPPPPPP        AA     ");
		aux(19, 10);printf("AA      AA     PP        PP         AA  ");
		aux(19, 11);printf("AA      AA    PP          PP    AA    AA");
		aux(19, 12);printf("AA      AA   PP            PP    AAAAAA ");
		aux(1, 14);printf("  PPPPPP          AAAA         PPP     PP         AAAA         PPPPP        AAAAAAA ");
		aux(1, 15);printf("PP               AA  AA        PPPP    PP        AA  AA        PP   PP     AA     AA");
		aux(1, 16);printf("PP              AA    AA       PP PP   PP       AA    AA       PP    PP    AA     AA");
		aux(1, 17);printf("PP   PP        AAAAAAAAAA      PP  PP  PP      AAAAAAAAAA      PP     PP   AA     AA");
		aux(1, 18);printf("PP     PP     AA        AA     PP   PP PP     AA        AA     PP    PP    AA     AA");
		aux(1, 19);printf("PP     PP    AA          AA    PP    PPPP    AA          AA    PP   PP     AA     AA");
		aux(1, 20);printf("  PPPPPPP   AA            AA   PP     PPP   AA            AA   PPPPP        AAAAAAA ");
}
int found(char car, int pos){
	int x, ret = 0;
	for(x = pos; x < 100; x++){
		if(car == rep[x]){
			ret = 1;
			break;
		}
	}
	return ret;
}
void munequito(){
	aux(55, 0); printf("    _________________");
	aux(55, 1); printf("    |                |");
	aux(55, 2); printf("    |                |");
	aux(55, 3); printf("    |                |");
	aux(55, 4); printf("    |                |");
	aux(55, 5); printf("    |                |");
	aux(55, 6); printf("                     |");
	aux(55, 6); printf("    %c                |", 248);
	aux(55, 7); printf("  %c   %c              |", 248, 248);
	aux(55, 8); printf(" %c     %c             |", 248, 248);
	aux(55, 9); printf(" %c     %c             |", 248, 248);
	aux(55, 10);printf("  %c   %c              |", 248, 248);
	aux(55, 11);printf("    %c                |", 248);
	aux(55, 12);printf("   %c%s%c               |", (ops > 2) ? 47 : 0, (ops > 3) ? "|" : " ", (ops > 1) ? 92 : 0);
	aux(55, 13);printf("  %c %s %c              |", (ops > 2) ? 47 : 0, (ops > 3) ? "|" : " ", (ops > 1) ? 92 : 0);
	aux(55, 14);printf(" %c  %s  %c             |", (ops > 2) ? 47 : 0, (ops > 3) ? "|" : " ", (ops > 1) ? 92 : 0);
	aux(55, 15);printf("%c   %s   %c            |", (ops > 2) ? 47 : 0, (ops > 3) ? "|" : " ", (ops > 1) ? 92 : 0);
	aux(55, 16);printf("    %s                |", (ops > 3) ? "|" : " ");
	aux(55, 17);printf("  %s%s%s              |", (ops > 4) ? "-*" : "  ", (ops > 3) ? "|" : " ", (ops > 5) ? "-*" : "  ");
	aux(55, 18);printf("  %s   %s              |", (ops > 4) ? "|" : " ", (ops > 5) ? "|" : " ");
	aux(55, 19);printf("  %s   %s              |", (ops > 4) ? "|" : " ", (ops > 5) ? "|" : " ");
	aux(55, 20);printf("  %s   %s              |", (ops > 4) ? "|" : " ", (ops > 5) ? "|" : " ");
	aux(55, 21);printf("  %s   %s              |", (ops > 4) ? "|" : " ", (ops > 5) ? "|" : " ");
	aux(55, 21);printf("                     |");
	aux(3, 21);printf("--------------------------------------------------------------------------");
	aux(10, 16); printf("LLLLL          LLLLL  %s", (ops == 1) ? "  CCCC" : (ops == 2) ? "CCCCCC" : (ops == 3) ? "CCCCCC" : (ops == 4) ? "CC  CC" : (ops == 5) ? "CCCCCC" : (ops == 6) ? "CCCCCC" : "ERROR");
	aux(10, 17); printf("   LLLL      LLLL     %s", (ops == 1) ? " CC CC" : (ops == 2) ? "    CC" : (ops == 3) ? "    CC" : (ops == 4) ? "CC  CC" : (ops == 5) ? "CC    " : (ops == 6) ? "CC    " : "ERROR");
	aux(10, 18); printf("     LLL    LLL       %s", (ops == 1) ? "CC  CC" : (ops == 2) ? " CCC  " : (ops == 3) ? " CCC  " : (ops == 4) ? "CCCCCC" : (ops == 5) ? " CCCCC" : (ops == 6) ? "CCCCCC" : "ERROR");
	aux(10, 19); printf("        LL LL         %s", (ops == 1) ? "    CC" : (ops == 2) ? "C     " : (ops == 3) ? "    CC" : (ops == 4) ? "    CC" : (ops == 5) ? "    CC" : (ops == 6) ? "CC  CC" : "ERROR");
	aux(10, 20); printf("          L           %s", (ops == 1) ? "    CC" : (ops == 2) ? "CCCCCC" : (ops == 3) ? "CCCCCC" : (ops == 4) ? "    CC" : (ops == 5) ? "CCCCCC" : (ops == 6) ? " CCCCC" : "ERROR");
	
	printf((ops < 1) ? "\t\t    |\n|\n|\n|\n|\n|\n|\n|\n|\n|\n" : "");
}
