#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
/*Codificaciones:
	1: unipolar, 2: RZ, 3: NRZ_N, 4: NRZ_I, 5: manchester, 6: manchester diferencial, 7: AMI, 8: pseudoternaria.
*/
int cad[10], codif = 1, ladoD, pld;
bool rango(int tipo, char t);
char noms[8][25] = {
	"unipolar", "RZ",
	"NRZ_N", "NRZ_I",
	"manchester", "manchester diferencial",
	"AMI", "pseudoternaria"
};
char nomA[25];
void vec_form(), aux(int x, int y), tomar_tecla(), dib(), setcursor(bool visible, DWORD size);
void opc();
int get_lon();
int main(){
	setcursor(false, 0);
	system("MODE CON COLS=80 LINES=30");
	vec_form();
	opc();
	tomar_tecla();
	return 0;
}
void tomar_tecla(){
	int cont = 0;
	char tec = 0;
	while(tec != 27){
		while(!rango(1, tec) && !rango(2, tec) && tec != 27 && tec != 8) tec = getch();
		if(tec == '0' || tec == '1'){
			cad[cont] = (cad[cont] == -1) ? (tec == '0') ? 0 : 1 : cad[cont];
			ladoD = (cont == 0) ? (codif < 7) ? rand()%2 : 1 : ladoD;
			cont += (cont < 10) ? 1 : 0;
		}
		if(rango(2, tec)){
			pld = tec - 48;
			codif = (pld >= 2 && pld <= 9) ? pld - 1 : codif;
		}
		if(tec == 8){
			cont -= (cont > 0) ? 1 : 0;
			cad[cont] = -1;
		}
		tec = (tec != 27) ? 0 : 27;
		aux(0, 0); printf("%c", tec);
		dib();
	}
}
bool rango(int tipo, char t){
	bool ret;
	if(tipo == 1){
		if(t == '0' || t == '1') ret = true;
	}
	if(tipo == 2){
		if(t == '2' || t == '3' || t == '4' || t == '5' || t == '6' || t == '7' || t == '8' || t == '9')
		ret = true;
	}
	return ret;
}
void dib(){
	int lon = get_lon(), cont = 7, ac, co, val, lado, auxL = ladoD, dir, Y, lim1, lim2;
	aux(0, 0);
	for(int x = 0; x < 10 - lon; x ++){cont += 3;}
	system("cls");
	for(int x = 0; x < lon; x++){
		for(int y = 2; y < 19; y++){
			aux(cont + 6 * x, y);printf("|");
			aux(cont + 6 * (x + 1), y);printf("|");
		}
	}
	for(int x = 0; x < lon; x++){
		ac = cont + 6 * x; co = cont + 6 * (x + 1);//ac: actual, co: corrido.
		val = cad[x];
		ac++;
		aux(ac, 1);printf((val == 0) ? "     " : "  /  ");
		aux(ac, 2);printf((val == 0) ? "  O  " : " / | ");
		aux(ac, 3);printf((val == 0) ? "O   O" : "/  | ");
		aux(ac, 4);printf((val == 0) ? "O   O" : "   | ");
		aux(ac, 5);printf((val == 0) ? "  O  " : "   | ");
		ac--;
		switch(codif){
			case 1:
				for(int X = ac; X <= co; X++){
					if(X != ac && X != co){
						aux(X, 15);
						printf("-");
					}
					aux(X, (val == 1) ? 12 : 15);
					printf("*");
					if(X == co && x < lon - 1 && cad[x + 1] != val && cad[x +1] != -1){
						for(int y = 13; y < 15; y++){
							aux(X, y); printf("*");
						}
					}
				}
			break;
			case 2:
				for(int X = ac; X <= co; X++){
					if(X != ac && X != co){
						aux(X, 15);
						printf("-");
					}
					aux(X, (X <= ac + 3) ? (val == 1) ? 12 : 18 : 15);
					printf("*");
					lim1 = (val == 1) ? 13 : 15; lim2 = (val == 1) ? 16 : 19;
					if(X == ac && x != 0){
						for(int y = lim1; y < lim2; y++){
							aux(X, y); printf("*");
						}
					}
					if(X == ac + 3 && x < lon){
						for(int y = lim1; y < lim2; y++){
							aux(X, y); printf("*");
						}
					}
				}
			break;
			case 3:
				for(int X = ac; X <= co; X++){
					aux(X, (val == 0) ? 12 : 18);
					printf("*");
					if(X == co && x < lon - 1 && cad[x + 1] != val && cad[x +1] != -1){
						for(int y = 13; y < 19; y++){
							aux(X, y); printf("*");
						}
					}
					if(X != ac && X != co){
						aux(X, 15);
						printf("-");
					}
				}
			break;
			case 4:
				for(int X = ac; X <= co; X++){
					lado = (x == 0) ? 1 : lado;
					lado = (x != 0 && val == 1) ? (lado == 0) ? 1 : 0 : 0;
					dir = (X == ac) ? lado : dir;
					if(x == lon - 1 && X == 0 && val == 1) dir = (dir == 0) ? 1 : 0;
					aux(X, (dir == 1) ? 12 : 18);
					printf("*");
					if(X == ac && x < lon && val == 1){
						for(int y = 13; y < 19; y++){
							aux(X, y); printf("*");
						}
					}
					if(X != ac && X != co){
						aux(X, 15);
						printf("-");
					}
				}
			break;
			case 5:
				for(int X = ac; X <= co; X++){
					if(X != ac && X != co){
						aux(X, 15);
						printf("-");
					}
					if(val == 1) Y = (X <= ac + 3) ? 18 : 12;
					else Y = (X > ac + 3) ? 18 : 12;
					aux(X, Y);
					printf("*");
					if(x > 0){
						if(cad[x - 1] == val){
							if(X == ac && x != 0){
								for(int y = 12; y < 19; y++){
									aux(X, y); printf("*");
								}
							}
						}
					}
					if(X == ac + 3){
						for(int y = 12; y < 19; y++){
							aux(X, y); printf("*");
						}
					}
				}
			break;
			case 6:
				for(int X = ac; X <= co; X++){
					if(X != ac && X != co){
						aux(X, 15);
						printf("-");
					}
					if(X == ac || X == ac + 3){
						if(val == 0 || X == ac + 3) ladoD = (ladoD == 0) ? 1 : 0;
						Y = (ladoD == 0) ? 18 : 12;
					}
					aux(X, Y);
					printf("*");
					if(x > 0){
						if(val == 0){
							if(X == ac && x != 0){
								for(int y = 12; y < 19; y++){
									aux(X, y); printf("*");
								}
							}
						}
					}
					if(X == ac + 3){
						for(int y = 12; y < 19; y++){
							aux(X, y); printf("*");
						}
					}
				}
			break;
			case 7:
				for(int X = ac; X <= co; X++){
					if(X != ac && X != co){
						aux(X, 15);
						printf("-");
					}
					if(X == ac){
						if(val == 1){
							ladoD = (ladoD == 0) ? 1 : 0;
							Y = (ladoD == 0) ? 18 : 12;
						}else Y = 15;
					}
					aux(X, Y);
					printf("*");
					if(x > 0 && X == ac){
						lim1 = (cad[x - 1] == 1) ? (val == 1) ? (ladoD == 0) ? 12 : 18 : (val == 0) ? (ladoD == 0) ? 18 : 12 : 0 : 15;
						lim2 = (val == 1) ? (ladoD == 0) ? 18 : 12 : 15;
						if(lim2 > lim1){
							for(int y = lim1; y < lim2; y++){
								aux(X, y); printf("*");
							}
						}else{
							if(lim2 < lim1){
								for(int y = lim2; y < lim1; y++){
									aux(X, y); printf("*");
								}
							}
						}
					}
				}
			break;
			case 8:
				for(int X = ac; X <= co; X++){
					if(X != ac && X != co){
						aux(X, 15);
						printf("-");
					}
					if(X == ac){
						if(val == 0){
							ladoD = (ladoD == 0) ? 1 : 0;
							Y = (ladoD == 0) ? 18 : 12;
						}else Y = 15;
					}
					aux(X, Y);
					printf("*");
					if(x > 0 && X == ac){
						lim1 = (cad[x - 1] == 0) ? (val == 0) ? (ladoD == 0) ? 12 : 18 : (val == 1) ? (ladoD == 0) ? 18 : 12 : 0 : 15;
						lim2 = (val == 0) ? (ladoD == 0) ? 18 : 12 : 15;
						if(lim2 > lim1){
							for(int y = lim1; y < lim2; y++){
								aux(X, y); printf("*");
							}
						}else{
							if(lim2 < lim1){
								for(int y = lim2; y < lim1; y++){
									aux(X, y); printf("*");
								}
							}
						}
					}
				}
			break;
		}
	}
	ladoD = auxL;
	opc();
}
int get_lon(){
	int cont = 0;
	for(int pos = 0; pos < 10; pos++){
		if(cad[pos] >= 0) cont++;
		else break;
	}
	return cont;
}
void vec_form(){
	for(int x = 0; x < 10; x++){
		cad[x] = -1;
	}
}
void opc(){
	for(int x = 0; x < 25; x++){
		nomA[x] = toupper(noms[codif - 1][x]);
	}
	aux(8, 0);printf("Programado por Leandro F. Cotti.");
	aux(5, 21);printf("2: %s.  6: %s.", noms[0], noms[4]);
	aux(5, 22);printf("3: %s.        7: %s.", noms[1], noms[5]);
	aux(48, 23);printf("Actual: %s", nomA);
	aux(5, 23);printf("4: %s.     8: %s.", noms[2], noms[6]);
	aux(5, 24);printf("5: %s.     9: %s.", noms[3], noms[7]);
	aux(29, 26);printf("0 - 1: escribir valor.");
	aux(35, 28);printf("ESC: salir.");
}
void aux(int x, int y){
	HANDLE oCur;
	oCur = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posicion;
	posicion.X = x;
	posicion.Y = y;
	SetConsoleCursorPosition(oCur, posicion);
}
void setcursor(bool visible, DWORD size){//set bool visible = 0 - invisible, bool visible = 1 - visible
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
