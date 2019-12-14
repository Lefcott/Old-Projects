#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
#define ENTER 13
#define SPACE 32
#define borrar 8
int op = 0, fila = 1, ficha = 0, disp1 = 1, disp2[3], disp3[5], disp4[7], fich_mov, jug = 1, ok, volver = 1;
int elim2[3], elim3[5], elim4[7], sig_ant(int accion, int fila, int _pos), primera_ficha();
int primera_fila(int inicio), tot_fichas();
char controles[7] = {75, 77, 72, 80, 13, 32, 8}, presion;
void funciones_tablero(int accion), select_elim(int accion), ganador(), instrucciones();
void menu(), elegir_accion_menu(), funcion_controles(int opcion), mover_fila(), mover_ficha();
void dibujar_menu(), dibujar_controles(), mostrar_controles(), jugar(), dibujar_tablero(), aux(int x, int y);
void hacer_cambio(char cntrl1[20], char cntrl2[20], char cntrl3[20],
				char cntrl4[20], char cntrl5[20], char cntrl6[20], char cntrl7[20]);
bool okelim_okuf(int accion), fila_nula(int num);
int main(){
	system("MODE CON COLS=80 LINES=25");
	menu();
	return 0;
}
void menu() {
	do{
		jug = 1;
		dibujar_menu();
		while(op < 1 || op > 5){op = getch() - 48;}
		elegir_accion_menu();
	}while(op != 5);
	exit(0);
}
void elegir_accion_menu(){
	switch(op){
		case 1: funciones_tablero(1); jugar(); break;
		case 2: funcion_controles(1); break;
		case 3: funcion_controles(2); break;
		case 4: instrucciones(); break;
	}
}
void dibujar_tablero(){
	system("cls");
	printf("\n          TURNO DEL JUGADOR %s:\n\n", (jug == 1) ? "UNO" : "DOS");
	char linea[] = "-------------------------------------------------------";
	char sep[] = "          ";
	char med_sep[] = "     ";
	printf("%s%s\n", med_sep, (fila == 1) ? linea : "");//L1
	printf("%s%s%s%s\n", sep, sep, sep, (disp1 == 1) ? " xxxx" : "");//F1
	printf("%s%s%s%s\n", sep, sep, sep, (disp1 == 1) ? " xxxx" : "");//F1
	printf("%s%s%s%s\n", sep, sep, sep, (disp1 == 1) ? " xxxx" : "");//F1
	printf("%s%s\n", med_sep, (fila == 1 || fila == 2) ? linea : "");//L2
	printf("%s%s%s %s %s %s\n", sep, sep, med_sep, (elim2[0] == 1) ? "****" : "    ",//SELECT2
					(elim2[1] == 1) ? "****" : "    ", (elim2[2] == 1) ? "****" : "    ");//SELECT2
	printf("%s%s%s%s%s%s%s%s%s%s\n", sep, sep, med_sep, (ficha == 1 && fila == 2) ? "|" : " ",//F2
					(disp2[0] == 1) ? "xxxx" : "    ", ((ficha == 1 || ficha == 2) && fila == 2) ? "|" : " ",//F2
					(disp2[1] == 1) ? "xxxx" : "    ", ((ficha == 2 || ficha == 3) && fila == 2) ? "|" : " ",//F2
					(disp2[2] == 1) ? "xxxx" : "    ", (ficha == 3 && fila == 2) ? "|" : " ");//F2
	printf("%s%s%s%s%s%s%s%s%s%s\n", sep, sep, med_sep, (ficha == 1 && fila == 2) ? "|" : " ",//F2
					(disp2[0] == 1) ? "xxxx" : "    ", ((ficha == 1 || ficha == 2) && fila == 2) ? "|" : " ",//F2
					(disp2[1] == 1) ? "xxxx" : "    ", ((ficha == 2 || ficha == 3) && fila == 2) ? "|" : " ",//F2
					(disp2[2] == 1) ? "xxxx" : "    ", (ficha == 3 && fila == 2) ? "|" : " ");//F2
	printf("%s%s%s%s%s%s%s%s%s%s\n", sep, sep, med_sep, (ficha == 1 && fila == 2) ? "|" : " ",//F2
					(disp2[0] == 1) ? "xxxx" : "    ", ((ficha == 1 || ficha == 2) && fila == 2) ? "|" : " ",//F2
					(disp2[1] == 1) ? "xxxx" : "    ", ((ficha == 2 || ficha == 3) && fila == 2) ? "|" : " ",//F2
					(disp2[2] == 1) ? "xxxx" : "    ", (ficha == 3 && fila == 2) ? "|" : " ");//F2
	printf("%s%s\n", med_sep, (fila == 2 || fila == 3) ? linea : "");//L3
	printf("%s%s %s %s %s %s %s\n", sep, sep, (elim3[0] == 1) ? "****" : "    ",//SELECT3
					(elim3[1] == 1) ? "****" : "    ", (elim3[2] == 1) ? "****" : "    ",//SELECT3
					(elim3[3] == 1) ? "****" : "    ", (elim3[4] == 1) ? "****" : "    ");//SELECT3
	printf("%s%s%s%s%s%s%s%s%s%s%s%s%s\n", sep, sep, (ficha == 1 && fila == 3) ? "|" : " ",//F3
							(disp3[0] == 1) ? "xxxx" : "    ", ((ficha == 1 || ficha == 2) && fila == 3) ? "|" : " ",//F3
							(disp3[1] == 1) ? "xxxx" : "    ", ((ficha == 2 || ficha == 3) && fila == 3) ? "|" : " ",//F3
							(disp3[2] == 1) ? "xxxx" : "    ", ((ficha == 3 || ficha == 4) && fila == 3) ? "|" : " ",//F3
							(disp3[3] == 1) ? "xxxx" : "    ", ((ficha == 4 || ficha == 5) && fila == 3) ? "|" : " ",//F3
							(disp3[4] == 1) ? "xxxx" : "    ", (ficha == 5 && fila == 3) ? "|" : " " );//F3
	printf("%s%s%s%s%s%s%s%s%s%s%s%s%s\n", sep, sep, (ficha == 1 && fila == 3) ? "|" : " ",//F3
							(disp3[0] == 1) ? "xxxx" : "    ", ((ficha == 1 || ficha == 2) && fila == 3) ? "|" : " ",//F3
							(disp3[1] == 1) ? "xxxx" : "    ", ((ficha == 2 || ficha == 3) && fila == 3) ? "|" : " ",//F3
							(disp3[2] == 1) ? "xxxx" : "    ", ((ficha == 3 || ficha == 4) && fila == 3) ? "|" : " ",//F3
							(disp3[3] == 1) ? "xxxx" : "    ", ((ficha == 4 || ficha == 5) && fila == 3) ? "|" : " ",//F3
							(disp3[4] == 1) ? "xxxx" : "    ", (ficha == 5 && fila == 3) ? "|" : " " );//F3
	printf("%s%s%s%s%s%s%s%s%s%s%s%s%s\n", sep, sep, (ficha == 1 && fila == 3) ? "|" : " ",//F3
							(disp3[0] == 1) ? "xxxx" : "    ", ((ficha == 1 || ficha == 2) && fila == 3) ? "|" : " ",//F3
							(disp3[1] == 1) ? "xxxx" : "    ", ((ficha == 2 || ficha == 3) && fila == 3) ? "|" : " ",//F3
							(disp3[2] == 1) ? "xxxx" : "    ", ((ficha == 3 || ficha == 4) && fila == 3) ? "|" : " ",//F3
							(disp3[3] == 1) ? "xxxx" : "    ", ((ficha == 4 || ficha == 5) && fila == 3) ? "|" : " ",//F3
							(disp3[4] == 1) ? "xxxx" : "    ", (ficha == 5 && fila == 3) ? "|" : " " );//F3
							
	printf("%s%s\n", med_sep, (fila == 3 || fila == 4) ? linea : "");//L4
	printf("%s%s %s %s %s %s %s %s %s\n", sep, med_sep, (elim4[0] == 1) ? "****" : "    ",//SELECT4
					(elim4[1] == 1) ? "****" : "    ", (elim4[2] == 1) ? "****" : "    ",//SELECT4
					(elim4[3] == 1) ? "****" : "    ", (elim4[4] == 1) ? "****" : "    ",//SELECT4
					(elim4[5] == 1) ? "****" : "    ", (elim4[6] == 1) ? "****" : "    ");//SELECT4
	printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n", sep, med_sep, (ficha == 1 && fila == 4) ? "|" : " ",//F4
							(disp4[0] == 1) ? "xxxx" : "    ", ((ficha == 1 || ficha == 2) && fila == 4) ? "|" : " ",//F4
							(disp4[1] == 1) ? "xxxx" : "    ", ((ficha == 2 || ficha == 3) && fila == 4) ? "|" : " ",//F4
							(disp4[2] == 1) ? "xxxx" : "    ", ((ficha == 3 || ficha == 4) && fila == 4) ? "|" : " ",//F4
							(disp4[3] == 1) ? "xxxx" : "    ", ((ficha == 4 || ficha == 5) && fila == 4) ? "|" : " ",//F4
							(disp4[4] == 1) ? "xxxx" : "    ", ((ficha == 5 || ficha == 6) && fila == 4) ? "|" : " ",//F4
							(disp4[5] == 1) ? "xxxx" : "    ", ((ficha == 6 || ficha == 7) && fila == 4) ? "|" : " ",//F4
							(disp4[6] == 1) ? "xxxx" : "    ", (ficha == 7 && fila == 4) ? "|" : " ");//F4
	printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n", sep, med_sep, (ficha == 1 && fila == 4) ? "|" : " ",//F4
							(disp4[0] == 1) ? "xxxx" : "    ", ((ficha == 1 || ficha == 2) && fila == 4) ? "|" : " ",//F4
							(disp4[1] == 1) ? "xxxx" : "    ", ((ficha == 2 || ficha == 3) && fila == 4) ? "|" : " ",//F4
							(disp4[2] == 1) ? "xxxx" : "    ", ((ficha == 3 || ficha == 4) && fila == 4) ? "|" : " ",//F4
							(disp4[3] == 1) ? "xxxx" : "    ", ((ficha == 4 || ficha == 5) && fila == 4) ? "|" : " ",//F4
							(disp4[4] == 1) ? "xxxx" : "    ", ((ficha == 5 || ficha == 6) && fila == 4) ? "|" : " ",//F4
							(disp4[5] == 1) ? "xxxx" : "    ", ((ficha == 6 || ficha == 7) && fila == 4) ? "|" : " ",//F4
							(disp4[6] == 1) ? "xxxx" : "    ", (ficha == 7 && fila == 4) ? "|" : " ");//F4
	printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n", sep, med_sep, (ficha == 1 && fila == 4) ? "|" : " ",//F4
							(disp4[0] == 1) ? "xxxx" : "    ", ((ficha == 1 || ficha == 2) && fila == 4) ? "|" : " ",//F4
							(disp4[1] == 1) ? "xxxx" : "    ", ((ficha == 2 || ficha == 3) && fila == 4) ? "|" : " ",//F4
							(disp4[2] == 1) ? "xxxx" : "    ", ((ficha == 3 || ficha == 4) && fila == 4) ? "|" : " ",//F4
							(disp4[3] == 1) ? "xxxx" : "    ", ((ficha == 4 || ficha == 5) && fila == 4) ? "|" : " ",//F4
							(disp4[4] == 1) ? "xxxx" : "    ", ((ficha == 5 || ficha == 6) && fila == 4) ? "|" : " ",//F4
							(disp4[5] == 1) ? "xxxx" : "    ", ((ficha == 6 || ficha == 7) && fila == 4) ? "|" : " ",//F4
							(disp4[6] == 1) ? "xxxx" : "    ", (ficha == 7 && fila == 4) ? "|" : " ");//F4
	printf("%s%s\n", med_sep, (fila == 4) ? linea : "");//L5
}
void jugar(){
	op = 0;
	ficha = 0;
	fila = (fila_nula(fila) == true) ? primera_fila(1) : fila;
	dibujar_tablero();
	funciones_tablero(2);
	(tot_fichas() > 0) ? mover_fila() : ganador();
}
void funciones_tablero(int accion){
	//1: formatea los vectores de disponibilidad en 1
	//2: limpia los vectores de eliminación
	//3: elimina las fichas solicitadas
	for(int i = 0; i < 7; i++){
		disp1 = (accion == 1) ? 1 : disp1;
		if(i < 3){
			disp2[i] = (accion == 1) ? 1 : disp2[i];
			elim2[i] = (accion == 2) ? 0 : elim2[i];
			disp2[i] = (accion == 3 && elim2[i] == 1) ? 0 : disp2[i];
		}
		if(i < 5){
			disp3[i] = (accion == 1) ? 1 : disp3[i];
			elim3[i] = (accion == 2) ? 0 : elim3[i];
			disp3[i] = (accion == 3 && elim3[i] == 1) ? 0 : disp3[i];
		}
		disp4[i] = (accion == 1) ? 1 : disp4[i];
		elim4[i] = (accion == 2) ? 0 : elim4[i];
		disp4[i] = (accion == 3 && elim4[i] == 1) ? 0 : disp4[i];
	}
	fila = (accion == 1) ? 1 : fila;
	if(accion == 3){funciones_tablero(2);}
}
void mover_fila(){
	presion = 0;
	while(presion != controles[5] && presion != controles[2] && presion != controles[3]){
		presion = toupper(getch());
	}
	fila = (fila_nula(fila) == true) ? primera_fila(1) : fila;
	if(controles[3] == toupper(presion)){
		fila = primera_fila(fila + 1);
	}else{
		if(controles[2] == toupper(presion)){
			(fila > 1) ? fila-- : fila;
		}else{
			if(controles[5] == presion){
				if(okelim_okuf(2) == false){
					mover_ficha();
				}
			}
		}
	}
	jugar();
}
void mover_ficha(){
	fich_mov = 1;
	ficha = (ficha == 0) ? primera_ficha() : ficha;
	dibujar_tablero();
	presion = 0;
	while(presion != controles[4] && presion != controles[5] && presion != controles[0] && presion != controles[1] && presion != controles[6]){
		presion = toupper(getch());
	}
	if(controles[1] == toupper(presion)){
		ficha = sig_ant(1, fila, ficha - 1);
	}else{
		if(controles[0] == toupper(presion)){
			if(ficha > 1){
				ficha = sig_ant(2, fila, ficha - 1);
			}
		}else{
			if(controles[5] == presion){
				select_elim(1);
			}else{
				if(controles[4] == presion){
					select_elim(2);
				}else{
					if(controles[6] == presion){
						volver = 0;
					}
				}
			}
		}
	}
	if(volver == 0){
		volver = 1;
		ficha = 0;
		funciones_tablero(2);
		dibujar_tablero();
		mover_fila();
	}
	else mover_ficha();
	
}
int primera_fila(int inicio){
	int primera = fila;
	for(int i = inicio; i <= 4; i++){
		if(fila_nula(i) == false){
			primera = i;
			i = 4;
		}
	}
	return primera;
}
bool fila_nula(int num){
	bool nula = true;
	int limite = (num == 1) ? 1 : (num == 2) ? 3 : (num == 3) ? 5 : (num == 4) ? 7 : 3;
	if(num == 1){
		if(disp1 == 1){
			nula = false;
		}
	}
	for(int i = 0; i < limite; i++){
		if(num == 2){
			if(disp2[i] == 1){
				nula = false;
				i = limite;
			}
		}
		if(num == 3){
			if(disp3[i] == 1){
				nula = false;
				i = limite;
			}
		}
		if(num == 4){
			if(disp4[i] == 1){
				nula = false;
				i = limite;
			}
		}
	}
	return nula;
}
int primera_ficha(){
	int limite = (fila == 2) ? 3 : (fila == 3) ? 5 : (fila == 4) ? 7 : 3;
	int primera;
	for(int i = 0; i < limite; i++){
		if(fila == 2){
			if(disp2[i] == 1){
				primera = i;
				i = limite;
			}
		}
		if(fila == 3){
			if(disp3[i] == 1){
				primera = i;
				i = limite;
			}
		}
		if(fila == 4){
			if(disp4[i] == 1){
				primera = i;
				i = limite;
			}
		}
	}
	return primera + 1;
}
int sig_ant(int accion, int _fila, int _pos){
	bool encontrada;
	int este = _pos;
	int sig = _pos + 1;
	int ant = _pos - 1;
	int max_fich = (_fila == 2) ? 2 : (_fila == 3) ? 4 : (_fila == 4) ? 6 : 2;
	max_fich = (accion == 3) ? 4 : max_fich;
	while(_pos < max_fich && (accion == 1)){
		if(_fila == 2){
			if(disp2[_pos + 1] == 1){
				sig = _pos + 1;
				_pos = 7;
				encontrada = true;
			}else{
				_pos += 1;
			}
		}
		if(_fila == 3){
			if(disp3[_pos + 1] == 1){
				sig = _pos + 1;
				_pos = 7;
				encontrada = true;
			}else{
				_pos += 1;
			}
		}
		if(_fila == 4){
			if(disp4[_pos + 1] == 1){
				sig = _pos + 1;
				_pos = 7;
				encontrada = true;
			}else{
				_pos += 1;
			}
		}
	}
	while(_pos > 0 && accion == 2){
		if(_fila == 2){
			if(disp2[_pos - 1] == 1){
				ant = _pos - 1;
				_pos = 0;
				encontrada = true;
			}else{
				_pos -= 1;
			}
		}
		if(_fila == 3){
			if(disp3[_pos - 1] == 1){
				ant = _pos - 1;
				_pos = 0;
				encontrada = true;
			}else{
				_pos -= 1;
			}
		}
		if(_fila == 4){
			if(disp4[_pos - 1] == 1){
				ant = _pos - 1;
				_pos = 0;
				encontrada = true;
			}else{
				_pos -= 1;
			}
		}
	}
	while(_pos < 4 && (accion == 3)){
		if(_fila == 2){
			if(disp2[_pos + 1] == 1){
				sig = _pos + 1;
				_pos = 7;
			}else{
				_pos += 1;
			}
		}
		if(_fila == 3){
			if(disp3[_pos + 1] == 1){
				sig = _pos + 1;
				_pos = 7;
			}else{
				_pos += 1;
			}
		}
		if(_fila == 4){
			if(disp4[_pos + 1] == 1){
				sig = _pos + 1;
				_pos = 7;
			}else{
				_pos += 1;
			}
		}
	}
	while(_pos > 0 && accion == 4){
		if(_fila == 2){
			if(disp2[_pos - 1] == 1){
				ant = _pos - 1;
				_pos = 0;
			}else{
				_pos -= 1;
			}
		}
		if(_fila == 3){
			if(disp3[_pos - 1] == 1){
				ant = _pos - 1;
				_pos = 0;
			}else{
				_pos -= 1;
			}
		}
		if(_fila == 4){
			if(disp4[_pos - 1] == 1){
				ant = _pos - 1;
				_pos = 0;
			}else{
				_pos -= 1;
			}
		}
	}
	sig = (encontrada == false) ? este : sig;
	ant = (encontrada == false) ? este : ant;
	return (accion == 1) ? sig + 1 : ant + 1;
}
void select_elim(int accion){
	if(accion == 1){
		if(fila == 2){ elim2[ficha - 1] = (elim2[ficha - 1] == 0) ? 1 : 0;}
		if(fila == 3){ elim3[ficha - 1] = (elim3[ficha - 1] == 0) ? 1 : 0;}
		if(fila == 4){ elim4[ficha - 1] = (elim4[ficha - 1] == 0) ? 1 : 0;}
	}else{
		if(accion == 2){
			if(okelim_okuf(1) == true){
				funciones_tablero(3);
				jug = (jug == 1) ? 2 : 1;
				jugar();
			}
		}
	}
}
void ganador(){
	system("cls\n");
	system("color 02");
	printf("   LLLL   FF   FF    CCCCCC         LL        FFF       CCCCC    LLLLL \n");
	printf("   LLLL   FF   FF   CC             LLLL       FF FF    CC   CC   LL  LL\n");
	printf("   LLLL   FF   FF   CC  CC        LL  LL      FF  FF   CC   CC   LL  LL\n");
	printf("   LLLL   FF   FF   CC    CC     LLLLLLLL     FF  FF   CC   CC   LLLL  \n");
	printf("  LLLL    FF   FF   CC    CC    LL      LL    FF FF    CC   CC   LLL   \n");
	printf("LLLL       FFFFF     CCCCCC    LL        LL   FFF       CCCCC    L LLL \n\n");
	printf("\t\t\t%s\n", (jug == 1) ? "   FF" : "   FF    ");
	printf("\t\t\t%s\n", (jug == 1) ? "  FFF" : " FFFFFFF ");
	printf("\t\t\t%s\n", (jug == 1) ? " FFFF" : "FF    FFF");
	printf("\t\t\t%s\n", (jug == 1) ? "FF FF" : "      FFF");
	printf("\t\t\t%s\n", (jug == 1) ? "   FF" : "     FFF ");
	printf("\t\t\t%s\n", (jug == 1) ? "   FF" : "   FFF   ");
	printf("\t\t\t%s\n\n", (jug == 1) ? "   FF" : "FFFFFFFFF");
	printf(" CCCCCC         LL        FFF  FF        CC\n");
	printf("CC             LLLL       FFFF FF       CCCC\n");
	printf("CC  CC        LL  LL      FF FFFF      CC  CC   \n");
	printf("CC    CC     LLLLLLLL     FF  FFF     CCCCCCCC  \n");
	printf("CC    CC    LL      LL    FF   FF    CC      CC \n");
	printf(" CCCCCC    LL        LL   FF   FF   CC        CC\n");
	printf("\n\tPulse ENTER para continuar...");
	while(getch() != 13){}
	system("cls");
	system("color 07");
	menu();
}
int tot_fichas(){
	int tot = 0;
	tot += (disp1 == 1) ? 1 : 0;
	for(int i = 0; i < 7; i++){
		if(i < 3){
			tot += (disp2[i] == 1) ? 1 : 0;
		}
		if(i < 5){
			tot += (disp3[i] == 1) ? 1 : 0;
		}
		if(i < 7){
			tot += (disp4[i] == 1) ? 1 : 0;
		}
	}
	return tot;
}
bool okelim_okuf(int accion){
	bool ok = false;
	int fich_cant = 0;
	int a_elim;
	for(int i = 0; i < 7; i++){
		if(i < 3 && fila == 2){
			if(accion == 1){
				(elim2[i] == 1) ? ok = true : ok;
			}else{
				if(disp2[i] == 1){
					fich_cant++;
					a_elim = i;
				}
			}
		}
		if(i < 5 && fila == 3){
			if(accion == 1){
				(elim3[i] == 1) ? ok = true : ok;
			}else{
				if(fila == 3){
					if(disp3[i] == 1){
						fich_cant++;
						a_elim = i;
					}
				}
			}
		}
		if(fila == 4){
			if(accion == 1){
				(elim4[i] == 1) ? ok = true : ok;
			}else{
				if(disp4[i] == 1){
					fich_cant++;
					a_elim = i;
				}
			}
		}
	}
	if(accion == 2 && fila == 1 && disp1 == 1){
		disp1 = 0;
		fich_cant = 1;
		ok = true;
	}
	ok = (fich_cant == 1) ? true : ok;
	if(accion == 2 && ok == true){
		(fila == 2) ? disp2[a_elim] = 0 : fila;
		(fila == 3) ? disp3[a_elim] = 0 : fila;
		(fila == 4) ? disp4[a_elim] = 0 : fila;
		jug = (jug == 1) ? 2 : 1;
	}
	return ok;
}
void funcion_controles(int opcion){
	op = 0;
	dibujar_controles();
	if(opcion == 1){mostrar_controles();}
	if(opcion == 2){
		hacer_cambio("IZQUIERDA", "DERECHA", "ARRIBA", "ABAJO", "EFECTUAR CAMBIOS", "SELECCIONAR FILA/FICHA", "CANCELAR MOVIMIENTO");
	}
	menu();
}
void mostrar_controles(){
	for(int i = 0; i < 7; i++){
		if(controles[i] == 75 || controles[i] == 77 || controles[i] == 72 || controles[i] == 80 || controles[i] == 8 || controles[i] == 13 || controles[i] == 32){
			printf("%s:\n\t%s\n", (i == 0) ? "IZQUIERDA" : (i == 1) ? "DERECHA" : (i == 2) ? "ARRIBA" : (i == 3) ? "ABAJO" : (i == 4) ? "EFECTUAR CAMBIOS" : (i == 5) ? "SELECCIONAR FILA/FICHA" : (i == 6) ? "CANCELAR MOVIMIENTO" : "OTRO", (controles[i] == 75) ? "Flecha izquierda" : (controles[i] == 77) ? "Flecha derecha" : (controles[i] == 72) ? "Flecha arriba" : (controles[i] == 80) ? "Flecha abajo" : (controles[i] == 13) ? "Enter" : (controles[i] == 32) ? "Espacio" : (controles[i] == 8) ? "Retroceso" : "OTRA");
		}
		else{
			printf("%s:\n\t%c\n", (i == 0) ? "IZQUIERDA" : (i == 1) ? "DERECHA" : (i == 2) ? "ARRIBA" : (i == 3) ? "ABAJO" : (i == 4) ? "EFECTUAR CAMBIOS" : (i == 5) ? "SELECCIONAR FILA/FICHA" : (i == 6) ? "CANCELAR MOVIMIENTO" : "OTRO", controles[i]);
		}
	}
	printf("\t\t\t\tPulse ENTER para continuar...");
	while(getch() != 13){}
}
void dibujar_menu(){
	system("cls");
	for(int draw_val = 0; draw_val <= 224000000; draw_val += 1){
		switch(draw_val){
			case 0:         printf("                                                   LL \n"); break;
			case 32000000:  printf("                                                  LL   \n"); break;
			case 64000000:  printf("                LLL LL LLL   FFFFFFF   CCC CC   LL  LL\n"); break;
			case 96000000:  printf("                LL LLLL LL   FFF       CC CCC   LL  LL\n"); break;
			case 128000000: printf("                LL  LL  LL   FFFFFF    CC  CC   LL  LL\n"); break;
			case 160000000: printf("                LL      LL   FFF       CC  CC   LL  LL\n"); break;
			case 184000000: printf("                LL      LL   FFFFFFF   CC  CC   LLLLLL\n\n"); break;
			case 224000000: printf("                LFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLF\n\n");
				aux(26, 11); printf("**(1) JUGAR (1)**");
				aux(21, 13); printf("**(2) VER CONTROLES (2)**");
				aux(19, 15); printf("**(3) CAMBIAR CONTROLES (3)**");
				aux(19, 17); printf("**(4) VER INSTRUCCIONES (4)**");
				aux(20, 19); printf("**(5) SALIR DEL JUEGO (5)**");
				aux(2, 21); printf("Idea principal, dise%co, animaci%cn, programaci%cn: LEANDRO COTTI\n", 164, 162, 162);
			break;
		}
	}
}
void dibujar_controles(){
	system("cls");
	for(int draw_val = 0; draw_val <= 224000000; draw_val += 1){
		switch(draw_val){
			case 0:         printf(" LLLLL   FFFFF   CCC  CC  LLLLLLLL  FFFFFFF   CCCCC   LL      FFFFFFF   CC    \n"); break;
			case 32000000:  printf("LLLLLL  FFFFFFF  CCCC CC     LL     FF   FF  CCCCCCC  LL      FF       CC CC  \n"); break;
			case 64000000:  printf("LL      FF   FF  CC CCCC     LL     FFFFFF   CC   CC  LL      FFFFFF  CC   CC \n"); break;
			case 96000000:  printf("LL      FF   FF  CC  CCC     LL     FFF      CC   CC  LL      FFFFFF    CC    \n"); break;
			case 128000000: printf("LLLLLL  FFFFFFF  CC   CC     LL     FF FFF   CC   CC  LL      FF          CC  \n"); break;
			case 160000000: printf(" LLLLL   FFFFF   CC   CC     LL     FF  FFF   CCCCC   LLLLLL  FFFFFFF  CCCC   \n\n");break;
		}
	}
}
void hacer_cambio(char cntrl1[20], char cntrl2[20], char cntrl3[20], char cntrl4[20], char cntrl5[20], char cntrl6[20], char cntrl7[20]){
	aux(18, 8); printf("ESCAPE: establecer valores por defecto.");
	aux(0, 9);
	for(int i = 0; i < 7; i++){
		printf("%s:\n", (i == 0) ? cntrl1 : (i == 1) ? cntrl2 :(i == 2) ? cntrl3 : (i == 3) ? cntrl4 : (i == 4) ? cntrl5 : (i == 5) ? cntrl6 : (i == 6) ? cntrl7 : "ERROR");
		controles[i] = getch();
		if(controles[i] != 27){
			controles[i] = getch();
			controles[i] = toupper(controles[i]);
			printf("\tOK\n");
		}else{
			controles[0] = 75; controles[1] = 77; controles[2] = 72; controles[3] = 80;
			controles[4] = 13;controles[5] = 32; controles[6] = 8;
			aux(0, 20); printf("CONTROLES ESTABLECIDOS POR DEFECTO.\n\n\t\t\t\tPresione ENTER para continuar...");
			while(getch() != 13){}
			break;
		}
	}
}
void instrucciones(){
	system("cls");
	printf("INSTRUCCIONES: \n\n\tCada jugador en su turno deber%c seleccionar una fila y sacar\n\tlas fichas que desee.\n\tEl objetivo es hacer que el oponente saque la %cltima ficha.\n\tParticipan dos jugadores y es un tablero de 16 fichas.\n\n", 160, 163);
	printf("Presione ENTER para continuar...");
	while(getch() != 13){}
	op = 0;
}
void aux(int x, int y){
	HANDLE oCur;
	oCur = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posicion;
	posicion.X = x;
	posicion.Y = y;
	SetConsoleCursorPosition(oCur, posicion);
}
