#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void aux(int x, int y);
void dibujar(int ficha, int jug);
int tic [3][3]={'2','2','2','2','2','2','2','2','2'},i,j,k,ta,ta1,ta2,ta3,ta4,ta5,ta6,ta7,a,b;
char op,tateti,valor,jugador,valor2;
int te(), c(), dev_fil_col(int action, int num, int tecla);

main(){

	printf("\n");
	do{
		system("cls");
		printf ("                                                    JHON F. KENNEDY\n\n\n");
		printf("                      ********************\n");
		printf("                      *Juego del TA-TE-TI*\n");
		printf("                      ********************\n\n\n");
		printf("							Aguante INDEPENDIENTE                     ");
		printf("			Juego hecho por Penelas, Ariel");
//		for(i=0;i<3;i++){
//			printf("\n");
//			for(j=0;j<3;j++){
//				if(tic[i][j]==1)
//					printf("X|");
//				else if(tic[i][j]==0)
//					printf("O|");
//				else
//					printf("%c|",tic[i][j]);
//			}
//		printf("\n------------");
//		printf("\n");
//
//      }
		for(k = 49; k <= 57; k++){
		
			dibujar(k, tic[dev_fil_col(1, k, 0)][dev_fil_col(2, k, 0)]);
		}
		if(jugador==1){
			printf("\n");     
			printf("\n jugador X>");
			c();
			jugador=0;
			te();
        }else if(jugador==0){
				printf("\n");
				printf("\n jugador O>");
				c();
				jugador=1;
				te();
		}             
	}while(tateti!=1);
	printf(" gano %c \n",op);
	char op2 = getch();
}

te(){
	ta=tic[0][0]+tic[0][1]+tic[0][2];
	ta1=tic[1][0]+tic[1][1]+tic[1][2];
	ta2=tic[2][0]+tic[2][1]+tic[2][2];
	ta3=tic[0][0]+tic[1][0]+tic[2][0];
	ta4=tic[0][0]+tic[1][1]+tic[2][1];
	ta5=tic[0][2]+tic[1][2]+tic[2][2];
	ta6=tic[0][0]+tic[1][1]+tic[2][2];
	ta7=tic[2][0]+tic[1][1]+tic[0][2];
                  
	if(ta==0 || ta1==0 || ta2==0 || ta3==0 || ta4==0 || ta5==0 || ta6==0 ||ta7==0){
		tateti=1;
		op='O';
    }
                                     
	if(ta==3 || ta1==3 || ta2==3 || ta3==3 || ta4==3 || ta5==3 || ta6==3||ta7==3){
		tateti=1;
		op='O';
                                     
    }
	return;       
	main();
}
c(){
	valor = getch();
	tic[dev_fil_col(1, valor, 1)][dev_fil_col(2, valor, 1)] = jugador;
	return;
}
int dev_fil_col(int action, int num, int tecla){//ACCIÓN 1: DEVOLVER FILA; ACCIÓN 2: COLUMNA;
	int fil = 0, col = 0;
	if(num == '1' || num == '2' || num == '3'){ fil = 0; col = num - (tecla == 1) ? 49 : 1; }
	if(num == '4' || valor == '5' || num == '6'){ fil = 1; col = num - (tecla == 1) ? 52 : 4; }
	if(valor == '7' || valor == '8' || num == '9'){ fil = 2; col = num - (tecla == 1) ? 55 : 7; }
	return (action == 1) ? fil : col;
}
void dibujar(int ficha, int jug){
	int xAux = (ficha == '1' || ficha == '4' || ficha == '7') ? 10:
				(ficha == '2' || ficha == '5' || ficha == '8') ? 24:
				(ficha == '3' || ficha == '6' || ficha == '9') ? 38 : 0;
	int yAux = (ficha == '1' || ficha == '2' || ficha == '3') ? 5:
				(ficha == '4' || ficha == '5' || ficha == '6') ? 12:
				(ficha == '7' || ficha == '8' || ficha == '9') ? 19 : 0;
	aux(xAux, yAux);		printf("------------");
	aux(xAux, yAux + 1);	printf((jug == 1) ? "|          |" : (jug == 0) ? "| 00    00 |" : "|          |");
	aux(xAux, yAux + 2);	printf((jug == 1) ? "|    00    |" : (jug == 0) ? "|   0000   |" : "|          |");
	aux(xAux, yAux + 3);	printf((jug == 1) ? "|  00  00  |" : (jug == 0) ? "|   0000   |" : "|          |");
	aux(xAux, yAux + 4);	printf((jug == 1) ? "|    00    |" : (jug == 0) ? "| 00    00 |" : "|          |");
	aux(xAux, yAux + 5);	printf("------------");
}

void aux(int x, int y){
	HANDLE oCur;
	oCur = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posicion;
	posicion.X = x;
	posicion.Y = y;
	SetConsoleCursorPosition(oCur, posicion);
}
