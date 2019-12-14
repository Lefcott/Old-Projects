#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define xDib 25
#define yDib 1
#define ret 25
#define s1 100
#define s2 50
#define s3 40
#define s4 30
#define s5 20
#define puntX 5
#define puntY 0
#define nom_lon 30
#define intentos 3
#define msjtm 15
void aux(int x, int y), dib(), flecha(int mov, int lon), flecha_u(), puntos(), rank(), dib_rank(int x, int y), may_noms();
void vec_form(int val, int vec), nombre(), menu(), setcursor(bool visible, DWORD size), fin(), inst();
int MMC(), prim_esp(), cant_letras();
bool S;
bool esp_ok();
int x = xDib, y = yDib + 1, p = 0, m1, m2, M1, M2, ints = intentos, jugs = 3, ps[15], disp[15], tmp_pos, jugar = 1, jug_ac = 0;
int xDir = 1, yDir = 1, gLon = 2, n_cont = 0, tmpSum, UM_cont = -1;
char noms[15][nom_lon], ord_noms[15][nom_lon], ps_ord[15];
char car, car_nom;
int main(){
	setcursor(false, 0);
	srand(time(NULL));
	system("color F0");
	system("MODE CON COLS=102 LINES=34");
	menu();
	vec_form(1, 1);
	vec_form(1, 2);
	if(!S){
		while(jugar == 1){
			aux(puntX, puntY);printf("Puntos: %d", p);
			aux(puntX, puntY + 1);printf("Intentos: %d", ints);
			if(kbhit()){
				car = getch();
				if(car == 13){
					puntos();
					ints -= (ints > 0) ? 1 : 0;
					aux(puntX, puntY + 1);printf("Intentos: %d", ints);
					Sleep(2000);
					flecha(1, 0);
				}
			}
			aux(x, y);    printf("     ");
			aux(x, y + 1);printf("     ");
			aux(x, y + 2);printf("     ");
			dib();
			if(ints != 0) Sleep(ret);
			else{
				ints = intentos;
				if(jugs > 1) nombre();
				system("cls");
				ps[jug_ac] = p;
				p = 0;
				gLon = 2;
				if(jug_ac < jugs - 1) jug_ac++;
				else{
					jugar = 0;
				}
			}
		}
		if(jugs > 1) rank();
		dib_rank(20, 1);
		for(int i = 0; i < 15; i++){
			ps[i] = 0;
		}
		fin();
	}
	return 0;
}
void menu(){
	system("cls");
	aux(1, 1);printf("LLLLLLL  FF  CCC     LLLL         F      CC       LLLL    FF         C      LLL   LL   FFFF   CCCCC");
	aux(1, 2);printf("  LL     FF  CC CC  LL  LL       FFF     CC       LL LL   FF        CCC     LLLL  LL  FF     CC   CC");
	aux(1, 3);printf("  LL     FF  CC CC  LL  LL      FF FF    CC       LLLL    FF       CC CC    LL LL LL  FF     CC   CC");
	aux(1, 4);printf("  LL     FF  CCC    LL  LL     FFFFFFF   CC       LL  LL  FF      CCCCCCC   LL   LLL  FF     CC   CC");
	aux(1, 5);printf("  LL     FF  CC CC   LLLL     FF     FF  CCCCC    LLLL    FFFFF  CC     CC  LL    LL   FFFF   CCCCC");
	aux(37, 9);printf("ENTER: JUGAR");
	aux(37, 13);printf("ESCAPE: SALIR");
	aux(12, 20);printf("Programado por Leandro Cotti y Ariel Penelas.");
	aux(12, 22);printf("Idea prncipal por la profesora Graciela N. Llosa.");
	char men_car = 0; bool ran_ok; int old_jugs, res_jugs;
	while(men_car == 0 || men_car == 75 || men_car == 77){
		men_car = 0;
		if(!ran_ok){
			aux(37, 11);printf("ESPACIO: VER INSTRUCCIONES     JUGADORES: %c<%s%d%s>%c", 174,
			(jugs < 10) ? "  " : "   ", jugs, (jugs  < 10) ? "  " : "   ", 175);
			aux(89, 11);printf((jugs < 10) ? "  " : "");
			ran_ok = true;
		}
		while(men_car != 27 && men_car != 32 && men_car != 13  &&
			men_car != 75 && men_car != 77) men_car = getch();
			S = (men_car == 27) ? true : false;
			old_jugs = jugs;
			jugs += (men_car == 75 && jugs > 1) ? -1 : (men_car == 77 && jugs < 15) ? 1 : 0;
			res_jugs = jugs - old_jugs;
			ran_ok = (res_jugs != 0) ? false : true;
	}
	if(men_car != 32) system("cls"); else inst();
}
void inst(){
	char in_car = 0;
	system("cls");
	aux(0, 0); printf("INSTRUCCIONES:\n\tCada jugador tiene %d intentos para embocar el tiro\n\t", intentos);
	printf("y hacer la mayor cantidad de puntos posible.\n\tSe tira con ENTER.\n\t");
	printf("Si el usuario emboca el tiro en la zona de 100 puntos, tendr%c un intento m%cs.\n\n\t\t", 160, 160);
	printf("Presione ENTER para continuar...");
	while(in_car != 13) in_car = getch();
	menu();
}
void fin(){
	char fin_car = 0;
	while(fin_car != 27 && fin_car != 13) fin_car = getch();
	if(fin_car == 27){
		int fin_cont = 0, xR = 0, yR = 0;
		while(fin_cont < 50){
			fin_cont++;
			aux(xR, yR); printf("               ");
			xR = 67 + rand()%5;
			yR = 3 + rand()%10;
			aux(xR, yR); printf("JUEGO TERMINADO");
		}Sleep(50);
	}
	S = false;
	jugar = 1; jug_ac = 0; p = 0;
	if(fin_car == 13) vec_form(1, 2);
	(fin_car == 13) ? main() : getch();
}
void aux(int x, int y){
	HANDLE oCur;
	oCur = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posicion;
	posicion.X = x;
	posicion.Y = y;
	SetConsoleCursorPosition(oCur, posicion);
}

void dib(){
	aux(13,27); printf("LLLLLL  FF   FF  CCCCCC      L      FFFFFF     CCCCC   LLLLLL    %s", (jug_ac == 0) ? "   FFF  " : (jug_ac == 1) ? "FFFFFF" : (jug_ac == 2) ? "FFFFFFF" : (jug_ac == 3) ? "FF  FF" : (jug_ac == 4) ? "FFFFFFF" : (jug_ac == 5) ? "FFFFFFF" : (jug_ac == 6) ? "FFFFFFF": (jug_ac == 7) ? " FFFFF ": (jug_ac == 8) ? "FFFFFFF": (jug_ac == 9) ? "   FFF    CCCCCC ": (jug_ac == 10) ? "   FFF      FFF  " : (jug_ac == 11) ? "   FFF   FFFFFF" : (jug_ac == 12) ? "   FFF   FFFFFFF" : (jug_ac == 13) ? "   FFF   FF  FF" : (jug_ac == 14) ? "   FFF   FFFFFFF" : "");
	aux(13,28); printf("    LL  FF   FF  CC         LLL     FF   FF   CC   CC  LL  LL    %s", (jug_ac == 0) ? " FF FF  " : (jug_ac == 1) ? "    FF" : (jug_ac == 2) ? "     FF" : (jug_ac == 3) ? "FF  FF" : (jug_ac == 4) ? "FF     " : (jug_ac == 5) ? "FF     " : (jug_ac == 6) ? "    FF ": (jug_ac == 7) ? "FF   FF": (jug_ac == 8) ? "FF   FF": (jug_ac == 9) ? " FF FF   CC    CC": (jug_ac == 10) ? " FF FF    FF FF  " : (jug_ac == 11) ? " FF FF       FF" : (jug_ac == 12) ? " FF FF        FF" : (jug_ac == 13) ? " FF FF   FF  FF" : (jug_ac == 14) ? " FF FF   FF     " : "");
	aux(13,29); printf("    LL  FF   FF  CC CC     LL LL    FF    FF  CC   CC  LL LL     %s", (jug_ac == 0) ? "FF  FF  " : (jug_ac == 1) ? "  FFF " : (jug_ac == 2) ? "  FFFFF" : (jug_ac == 3) ? "FFFFFF" : (jug_ac == 4) ? "FFFFFFF" : (jug_ac == 5) ? "FFFFFFF" : (jug_ac == 6) ? "   FF  ": (jug_ac == 7) ? " FFFFF ": (jug_ac == 8) ? "FFFFFFF": (jug_ac == 9) ? "FF  FF   CC    CC": (jug_ac == 10) ? "FF  FF   FF  FF  " : (jug_ac == 11) ? "FF  FF     FFF " : (jug_ac == 12) ? "FF  FF     FFFFF" : (jug_ac == 13) ? "FF  FF   FFFFFF" : (jug_ac == 14) ? "FF  FF   FFFFFFF" : "");
	aux(13,30); printf("    LL  FF   FF  CC  CC   LLLLLLL   FF   FF   CC   CC  LL  LL    %s", (jug_ac == 0) ? "    FF  " : (jug_ac == 1) ? "FF    " : (jug_ac == 2) ? "     FF" : (jug_ac == 3) ? "    FF" : (jug_ac == 4) ? "     FF" : (jug_ac == 5) ? "FF   FF" : (jug_ac == 6) ? "  FF   ": (jug_ac == 7) ? "FF   FF": (jug_ac == 8) ? "     FF": (jug_ac == 9) ? "    FF   CC    CC": (jug_ac == 10) ? "    FF       FF  " : (jug_ac == 11) ? "    FF   FF    " : (jug_ac == 12) ? "    FF        FF" : (jug_ac == 13) ? "    FF       FF" : (jug_ac == 14) ? "    FF        FF" : "");
	aux(13,31); printf("LLLLL    FFFFF   CCCCCC  LL     LL  FFFFFF     CCCCC   LL   LL   %s", (jug_ac == 0) ? "  FFFFFF" : (jug_ac == 1) ? "FFFFFF" : (jug_ac == 2) ? "FFFFFFF" : (jug_ac == 3) ? "    FF" : (jug_ac == 4) ? "FFFFFFF" : (jug_ac == 5) ? "FFFFFFF" : (jug_ac == 6) ? " FF    ": (jug_ac == 7) ? " FFFFF ": (jug_ac == 8) ? "     FF": (jug_ac == 9) ? "  FFFFFF  CCCCCC ": (jug_ac == 10) ? "  FFFFFF   FFFFFF" : (jug_ac == 11) ? "  FFFFFF FFFFFF" : (jug_ac == 12) ? "  FFFFFF FFFFFFF" : (jug_ac == 13) ? "  FFFFFF     FF" : (jug_ac == 14) ? "  FFFFFF FFFFFFF" : "");
	aux(11,32); printf("-----------------------------------------------------------------------------");
	aux(xDib, yDib);	  printf("         ++++++++++++++++++++++++++++++");
	aux(xDib, yDib + 1);  printf("        +              %d              +", s5);
	aux(xDib, yDib + 2);  printf("       +   ++++++++++++++++++++++++++   +");
	aux(xDib, yDib + 3);  printf("      +   +            %d            +   +", s4);
	aux(xDib, yDib + 4);  printf("     +   +    ++++++++++++++++++++    +   +");
	aux(xDib, yDib + 5);  printf("    +   +    +                    +    +   +");
	aux(xDib, yDib + 6);  printf("   +   +    +          %d          +    +   +", s3);
	aux(xDib, yDib + 7);  printf("  +   +    +    ++++++++++++++++    +    +   +");
	aux(xDib, yDib + 8);  printf(" +   +    +    +       %d       +    +    +   +", s2);
	aux(xDib, yDib + 9);  printf("+   +    +    +   ++++++++++++   +    +    +   +");
	aux(xDib, yDib + 10); printf("+   +    +   +   +     %d    +   +   +    +   +", s1);
	aux(xDib, yDib + 11); printf("+   +    +    +   ++++++++++++   +    +    +   +");
	aux(xDib, yDib + 12); printf(" +   +    +    +       %d       +    +    +   +", s2);
	aux(xDib, yDib + 13); printf("  +   +    +    ++++++++++++++++    +    +   +");
	aux(xDib, yDib + 14); printf("   +   +    +                      +    +   +");
	aux(xDib, yDib + 15); printf("    +   +    +         %d         +    +   +", s3);
	aux(xDib, yDib + 16); printf("     +   +    ++++++++++++++++++++    +   +");
	aux(xDib, yDib + 17); printf("      +   +            %d            +   +", s4);
	aux(xDib, yDib + 18); printf("       +   ++++++++++++++++++++++++++   +");
	aux(xDib, yDib + 19); printf("        +              %d              +", s5);
	aux(xDib, yDib + 20); printf("         ++++++++++++++++++++++++++++++");
	flecha(2, gLon);
	aux(x, y);    printf("XX XX");
	aux(x, y + 1);printf(" XXX ");
	aux(x, y + 2);printf("XX XX");
}
void nombre(){
	flecha(1, 0);
	aux(xDib - 13, yDib + 22); printf("                  ------------------------------");
	aux(xDib - 13, yDib + 24); printf("                  ------------------------------");
	aux(xDib + 40, yDib + 23); printf("ENTER: siguiente jugador.");
	aux(xDib - 13, yDib + 23); printf("Ingrese su nombre:");
	setcursor(true, 30);
	car_nom = -1; n_cont = -1;
	while(car_nom != 13 || noms[jug_ac][0] == ' ' || noms[jug_ac][0] == 0 || strlen(noms[jug_ac]) < 2 || cant_letras() < 2){
		if(noms[jug_ac][0] == ' ' || noms[jug_ac][0] == 0 || strlen(noms[jug_ac]) < 2) n_cont = -1;
		if(strlen(noms[jug_ac]) == 1) n_cont = 0;
		car_nom = -1;
		while(!(car_nom > 96 && car_nom < 123) && !(car_nom > 64 && car_nom < 91) && car_nom != 8 && car_nom != 13 && car_nom != 32) car_nom = getch();
		tmpSum = (car_nom == 8) ? (n_cont != 0) ? 1 : 0 : 0;
		n_cont -= (n_cont == 0 && car_nom != 13 && car_nom != 8 && noms[jug_ac][0] == NULL) ? 1 : 0;
		n_cont += (car_nom != 8) ? (n_cont < nom_lon) ? 1 : 0 : (n_cont > 0) ? -1 : 0;
		noms[jug_ac][n_cont + tmpSum] = (car_nom != 13) ? (n_cont < nom_lon) ? (car_nom != 8) ? car_nom : NULL : noms[jug_ac][n_cont] : noms[jug_ac][n_cont];
		if(car_nom == 32){
			if(esp_ok()) noms[jug_ac][n_cont] = ' ';
			else{
				noms[jug_ac][n_cont] = 0;
				n_cont -= (n_cont > 0) ? 1 : 0;
			}
		}
		aux(xDib + 5, yDib + 23);printf("                              ");
		aux(xDib + 5, yDib + 23);printf("%s", noms[jug_ac]);
		aux(xDib + 5 + prim_esp(), yDib + 23);
	}
	for(int i = 14; i >= 0; i--){
		if(noms[jug_ac][i] == ' ' || noms[jug_ac][i] == NULL) noms[jug_ac][i] = NULL; else break;
	}setcursor(false, 0);
}
int cant_letras(){
	int cant = 0;
	for(int i = 0; i < nom_lon; i++){
		if(toupper(noms[jug_ac][i]) >= 65 && toupper(noms[jug_ac][i]) <= 90) cant++;
	}
	return cant;
}
bool esp_ok(){
	bool is_ok = true;
	is_ok = (n_cont > 0 && noms[jug_ac][n_cont - 1] == 32) ? false : true;
	return is_ok;
}
int prim_esp(){
	int pos2;
	bool out;
	for(int pos = nom_lon - 1; pos >= 0; pos--){
		out = ((noms[jug_ac][pos] == ' ' || noms[jug_ac][pos] == NULL)	&& (noms[jug_ac][pos - 1] != NULL)) ? true : false;
		pos2 = (out) ? pos : 1;
		if(out) break;
	}pos2 = (pos2 == 1 && noms[jug_ac][0] == NULL || noms[jug_ac][0] == 32) ? 0 : pos2;
	return pos2;
}
void rank(){
	for(int i = 0; i < jugs; i++){
		ps_ord[i] = MMC();
		strcpy(ord_noms[i], noms[tmp_pos]);
	}
	int aux1;
	char aux2[nom_lon];
	gLon = 2;
	for(int j = 0; j < jugs - 1; j++){
		for(int i = 0; i < jugs - 1; i++){
			if(ps[i] < ps[i + 1]){
				aux1 = ps[i + 1];
				ps[i + 1] = ps[i];
				ps[i] = aux1;
			}
		}
	}
}
int MMC(){//MÁXIMO ENTRE LOS DISPONIBLES.
	int M = -1;
	for(int i = 0; i < jugs; i++){
		if(disp[i] == 1 && ps[i] > M){
			M = ps[i];
			tmp_pos = i;
		}
	}
	disp[tmp_pos] = 0;
	return M;
}
void dib_rank(int x, int y){
	may_noms();
	system("cls");
	for(int i = 0; i < jugs; i++){
		aux(x, y + 2 * i);
		if(jugs > 1)
			printf("PUESTO %d: %s, con %d puntos.", i + 1, ord_noms[i], ps[i]);
		else
			printf("PUNTOS: %d", ps[0]);
		if(i == jugs - 1){
			aux(x + 2, y + 2 * i + 3); printf("ENTER: JUGAR DE NUEVO");
			aux(x + 2, y + 2 * i + 4); printf("ESCAPE: SALIR");
		}
	}
}
void may_noms(){
	int esp = 0;
	for(int i = 0; i < jugs; i++){
		for(int j = 0; j < nom_lon; j++){
			ord_noms[i][j] = (j == 0 || esp == 1) ? toupper(ord_noms[i][j]) : tolower(ord_noms[i][j]);			
			esp = (ord_noms[i][j] == ' ') ? 1 : 0;
		}
	}
}
void puntos(){
	int suma, max, min, y1 = y + 1, x2 = x + 2, dif, p_old = p;
	for(int i = 11; i < 19; i++){//IZQ_ABA 1, 2 y 3*
		min = i - 10 + xDib;
		max = i - 9 + xDib;
		min--;max += 2;
		if(x2 > min && x2 < max && y1 == i + yDib){
			p += s5;
		}
		min += 4;
		max += 5;
		if(x2 > min && x2 < max && y1 == i + yDib && i > 3 && i < 17){
			p += s4;
		}
		min += 5;
		max += 5;
		if(x2 > min && x2 < max && y1 == i + yDib && i < 14){
			p += s3;
		}
	}
	for(int i = 2; i < 10; i++){//IZQ_ARR 1, 2 y 3
		min = 9 - i + xDib;
		max = 11 - i + xDib;
		max += 2;
		if(x2 > min && x2 < max && y1 == i + yDib){
			p += s5;
		}
		min += 4;
		max += 5;
		if(x2 > min && x2 < max && y1 == i + yDib && i > 3 && i < 17){
			p += s4;
		}
		min += 5;
		max += 5;
		if(x2 > min && x2 < max && y1 == i + yDib && i > 6){
			p += s3;
		}
	}
	for(int i = 11; i < 19; i++){//DER_ABA 1, 2 y 3
		min = 43 - (i - 11) + xDib;
		max = 47 - (i - 11) + xDib;
		if(x2 > min && x2 < max && y1 == i + yDib){
			p += s5;
		}
		min -= 5;
		max -= 4;
		if(x2 > min && x2 < max && y1 == i + yDib && i < 17){
			p += s4;
		}
		min -= 5;
		max -= 5;
		if(x2 > min && x2 < max && y1 == i + yDib && i < 14){
			p += s3;
		}
	}
	for(int i = 2; i < 10; i++){//DER_ARR 1, 2 y 3
		min = 34 + i + xDib;
		max = 38 + i + xDib;
		if(x2 > min && x2 < max && y1 == i + yDib){
			p += s5;
		}
		min -= 5;
		max -= 4;
		if(x2 > min && x2 < max && y1 == i + yDib && i > 3){
			p += s4;
		}
		min -= 5;
		max -= 5;
		if(x2 > min && x2 < max && y1 == i + yDib && i > 6){
			p += s3;
		}
	}
	if(y1 == 19 + yDib || y1 == 1 + yDib){
		p += (x2 > 8 + xDib && x2 < 39 + xDib) ? s5: 0;
	}
	if(y1 == 3 + yDib || y1 == 17 + yDib){
		p += (x2 > 11 + xDib && x2 < 37 + xDib) ? s4: 0;
	}
	if(y1 == 5 + yDib || y1 == 15 + yDib){
		p += (x2 > 13 + xDib && x2 < 34 + xDib) ? s3: 0;
	}
	if(y1 == 6 + yDib || y1 == 14 + yDib){
		p += (x2 > 12 + xDib && x2 < 35 + xDib) ? s3: 0;
	}
	if(y1 == 8 + yDib || y1 == 12 + yDib){
		p += (x2 > 15 + xDib && x2 < 32 + xDib) ? s2: 0;
	}
	if(y1 == 10 + yDib){
		p += (x2 > 17 + xDib && x2 < 30 + xDib) ? s1: 0;
		p += (x2 > xDib && x2 < 4 + xDib) ? s5: 0;
		p += (x2 > 4 + xDib && x2 < 9 + xDib) ? s4: 0;
		p += (x2 > 9 + xDib && x2 < 13 + xDib) ? s3: 0;
		p += (x2 > 13 + xDib && x2 < 17 + xDib) ? s2: 0;
		p += (x2 > 30 + xDib && x2 < 34 + xDib) ? s2: 0;
		p += (x2 > 34 + xDib && x2 < 38 + xDib) ? s3: 0;
		p += (x2 > 38 + xDib && x2 < 43 + xDib) ? s4: 0;
		p += (x2 > 43 + xDib && x2 < 47 + xDib) ? s5: 0;
	}
	dif = p - p_old;
	if(dif == 100){
		ints++;
		gLon++;
		UM_cont = msjtm;
	}
	aux(puntX, puntY);printf("Puntos: %d", p);
}
void vec_form(int val, int vec){
	int num = (vec == 1) ? jugs : nom_lon;
	for(int i = 0; i < num; i++){
		disp[i] = (vec == 1) ? val : disp[i];
		if(vec == 2){
			for(int j = 0; j < jugs; j++){
				if(i < nom_lon){
					ord_noms[j][i] = NULL;
					noms[j][i] = NULL;
				}
			}
		}
	}
}
void flecha(int mov, int lon){
	if(UM_cont > 0){
		UM_cont--;
		aux(5, 22); printf("%cUn intento m%cs!", 173, 160);
	}else{
		if(UM_cont == 0){
			aux(5, 30); printf("                ");
			UM_cont = -1;
		}
	}
	switch(mov){
		case 1:
			aux(x, y);    printf("     ");
			aux(x, y + 1);printf("     ");
			aux(x, y + 2);printf("     ");
			x = xDib + rand() % 48;
			y = yDib + rand() % 20;
		break;
		case 2:
			if(xDir == 1){
				if(x < 47 + xDib)
				x += lon;
				else
				xDir = 2;
			}else{
				if(x > xDib)
				x -= lon;
				else
				xDir = 1;
			}
			if(yDir == 1){
				if(y < 20 + yDib)
				y += lon;
				else
				yDir = 2;
			}else{
				if(y > yDib)
				y -= lon;
				else
				yDir = 1;
			}
		break;
	}
}
//void flecha_u(){
//	scanf("%d", &x);
//	scanf("%d", &y);
//	x += xDib - 2;
//	y += yDib - 1;

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
