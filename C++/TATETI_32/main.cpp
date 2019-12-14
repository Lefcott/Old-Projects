#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define vec_num 0
void aux(int x, int y), dibujar(), vec_form(int val), mover(), dib_sel(bool dib);
void DLV(int x, int y, int lon), setcursor(bool visible, DWORD size), dib_menu();
int mesa[9], xP, yP, selec = 4, ex = 0, oldS, tur, ESC = 0;
int G();
int izq, der, arr, aba, ok, rem, M;
char car = 0, menu_car;
int prim_ocup(int act);
int main(){
	srand(time(NULL));
	setcursor(0, 0);
	system("cls");
	system("color F0");
	system("MODE CON COLS=66 LINES=42");
	M = 0;
	menu_car = 0;
	dib_menu();
	while(menu_car != 13 && menu_car != 27) menu_car = getch();
	ESC = (menu_car == 27) ? 1 : 0;
	while(ESC == 0){
		tur = 1;
		ex = 0;
		selec = 4;
		vec_form(vec_num);
		dibujar();
		dib_sel(true);
		mover();
	}
	if(M == 1) main();
	return 0;
}
void mover(){
	char car = 0;
	while(ex == 0){
		izq = (tur == 1) ? 75 : 65;
		der = (tur == 1) ? 77 : 68;
		arr = (tur == 1) ? 72 : 87;
		aba = (tur == 1) ? 80 : 83;
		ok = (tur == 1) ? 13 : 32;
		while(toupper(car) != ok && toupper(car) != izq && toupper(car) != der && toupper(car) != arr && toupper(car) != aba) car = getch();
		oldS = selec;
		car = toupper(car);
		if(car == ok){
			rem = (mesa[selec] == vec_num) ? 1 : 0;
			mesa[selec] = (rem == 1) ? tur : mesa[selec];
			selec = (rem == 1) ? prim_ocup(1) : selec;
			if(rem == 1) tur = (tur == 1) ? 2 : 1;
		}
		if(car == arr){
			if(selec > 2){
				selec -= 3;
			}
		}
		if(car == aba){
			if(selec < 6){
				selec += 3;
			}
		}
		if(car == izq){
			if(selec%3 != 0){
				selec--;
			}
		}
		if(car == der){
			if((selec+1)%3 != 0){
				selec++;
			}
		}
		if(oldS != selec) dib_sel(false);
		dibujar();
		if(prim_ocup(2) == 0) dib_sel(true);
		if(prim_ocup(2) == 1) ex = 1;
		ex = G();
		car = 0;
	}system("color 0F");
	car = 0;
	aux(4, 2);printf("TAB - jugar de nuevo    ESCAPE - salir    M - ir al men%c", 163);
	while(car != 9 && car != 27 && toupper(car) != 77) car = getch();
	ESC = (car == 27 || toupper(car) == 77) ? 1 : 0;
	M = (toupper(car) == 77) ? 1 : 0;
	system("color F0");
}
int G(){
	int gp, band = 0;
	band += (mesa[0] == mesa[1] && mesa[1] == mesa[2] && mesa[0] != vec_num) ? 1 : 0;
	band += (mesa[3] == mesa[4] && mesa[4] == mesa[5] && mesa[3] != vec_num) ? 1 : 0;
	band += (mesa[6] == mesa[7] && mesa[7] == mesa[8] && mesa[6] != vec_num) ? 1 : 0;
	
	band += (mesa[0] == mesa[3] && mesa[3] == mesa[6] && mesa[0] != vec_num) ? 1 : 0;
	band += (mesa[1] == mesa[4] && mesa[4] == mesa[7] && mesa[1] != vec_num) ? 1 : 0;
	band += (mesa[2] == mesa[5] && mesa[5] == mesa[8] && mesa[2] != vec_num) ? 1 : 0;
	
	band += (mesa[0] == mesa[4] && mesa[4] == mesa[8] && mesa[0] != vec_num) ? 1 : 0;
	band += (mesa[2] == mesa[4] && mesa[4] == mesa[6] && mesa[2] != vec_num) ? 1 : 0;
	aux(2, 38);
	if(tur == 1 && band == 1) printf("Gan%c C%cRCULO.", 162, 214);
	if(tur == 2 && band == 1) printf("Gan%c CRUZ.", 162);
	if(band == 0 && prim_ocup(2) == 1){
		printf("Es un empate.");
		band = 1;
	}
	return (band > 0) ? 1 : 0;
}
int prim_ocup(int act){
	int dev, count = 0;
	for(int i = 0; i < 9; i++){
		dev = i;
		count++;
		if(mesa[i] == 0) break;
	}
	if(act == 2){
		dev = (dev == 8 && mesa[8] != 0) ? 1 : 0;
	}
	return dev;
}
void dib_menu(){
	aux(1, 2);printf("LLLLLLLLLL    FF          CCCCCCCCCC  LLLLLL     FFFFFFFFFF  CC");
	aux(1, 3);printf("    LL       FFFF             CC      LL             FF      CC");
	aux(1, 4);printf("    LL      FF  FF            CC      LL             FF      CC");
	aux(1, 5);printf("    LL     FF    FF           CC      LLLL           FF      CC");
	aux(1, 6);printf("    LL    FFFFFFFFFF          CC      LL             FF      CC");
	aux(1, 7);printf("    LL   FF        FF         CC      LL             FF      CC");
	aux(1, 8);printf("    LL  FF          FF        CC      LLLLLL         FF      CC");
	aux(5, 10);printf("Programado por Leandro Cotti y Ariel Penelas.");
	aux(23, 13);printf("(ENTER) jugar");
	aux(23, 15);printf("(ESCAPE) salir");
	aux(2, 18);printf("CONTROLES:");
	aux(4, 22);printf("Jugador 1 (cruz):");
	aux(5, 24);printf("FLECHAS: seleccionar lugar.");
	aux(5, 25);printf("ENTER: jugar.");
	aux(4, 29);printf("Jugador 2 (c%crculo):", 161);
	aux(5, 31);printf("W, A, S y D: seleccionar lugar.");
	aux(5, 32);printf("ESPACIO: jugar.");
}
void dib_sel(bool dib){
	if(dib){
		xP = (selec == 0 || selec == 3 || selec == 6) ? 14 : (selec == 1 || selec == 4 || selec == 7) ? 28 : 41;
		yP = (selec < 3) ? 3 : (selec < 6) ? 14 : 25;
	}else{
		xP = (oldS == 0 || oldS == 3 || oldS == 6) ? 14 : (oldS == 1 || oldS == 4 || oldS == 7) ? 28 : 41;
		yP = (oldS < 3) ? 3 : (oldS < 6) ? 14 : 25;
	 }
	aux(xP, yP + 3); printf((dib == 1) ?  " -------- " : "          ");
	aux(xP, yP + 4); printf((dib == 1) ?  "|        |" : "          ");
	aux(xP, yP + 5); printf((dib == 1) ?  "|        |" : "          ");
	aux(xP, yP + 6); printf((dib == 1) ?  "|        |" : "          ");
	aux(xP, yP + 7); printf((dib == 1) ?  "|        |" : "          ");
	aux(xP, yP + 8); printf((dib == 1) ?  "|        |" : "          ");
	aux(xP, yP + 9); printf((dib == 1) ?  "|        |" : "          ");
	aux(xP, yP + 10); printf((dib == 1) ? " -------- " : "          ");
}
void dibujar(){
	system("cls");
	aux(13, 15);printf("----------------------------------------");
	aux(13, 26);printf("----------------------------------------");
	DLV(26, 4, 34);
	DLV(39, 4, 34);
	for(int pos = 0; pos < 9; pos++){
		xP = (pos == 0 || pos == 3 || pos == 6) ? 15 : (pos == 1 || pos == 4 || pos == 7) ? 28 : 41;
		yP = (pos < 3) ? 4 : (pos < 6) ? 15 : 26;
		aux(xP, yP + 2); printf((mesa[pos] == 1) ? " X      X" :(mesa[pos] == 2) ? "    OO   " : "");
		aux(xP, yP + 3); printf((mesa[pos] == 1) ? "  X    X" : (mesa[pos] == 2) ? "  OO  OO  " : "");
		aux(xP, yP + 4); printf((mesa[pos] == 1) ? "   X  X" :  (mesa[pos] == 2) ? " OO    OO " : "");
		aux(xP, yP + 5); printf((mesa[pos] == 1) ? "    XX" :   (mesa[pos] == 2) ? "OO      OO" : "");
		aux(xP, yP + 6); printf((mesa[pos] == 1) ? "    XX" :   (mesa[pos] == 2) ? " OO    OO " : "");
		aux(xP, yP + 7); printf((mesa[pos] == 1) ? "   X  X" :  (mesa[pos] == 2) ? "  OO  OO  " : "");
		aux(xP, yP + 8); printf((mesa[pos] == 1) ? "  X    X" : (mesa[pos] == 2) ? "    OO    " : "");
		aux(xP, yP + 9); printf((mesa[pos] == 1) ? " X      X" :(mesa[pos] == 2) ? "          " : "");
	}
}
void DLV(int x, int y, int lon){
	for(int i =  y; i < lon + y; i++){
		aux(x, i);
		printf("|");
	}
}
void vec_form(int val){
	for(int i = 0; i < 9; i++){
		mesa[i] = val;
	}
}
void aux(int x, int y){
	HANDLE oCur;
	oCur = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posicion;
	posicion.X = x;
	posicion.Y = y;
	SetConsoleCursorPosition(oCur, posicion);
}
void setcursor(bool visible, DWORD size){ // set bool visible = 0 - invisible, bool visible = 1 - visible
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if(size == 0)
	{
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}


