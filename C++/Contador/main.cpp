#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
int pant = 1, dph = 20, ini[2], hrs[2], mins[2], segs[2], tec = 0, selec = 1, pause_t[2] = {0, 0};
int act, pt2[2], p_ini[2];
float fact, mon[2], dif;
bool paused[2] = {true, true}, first = true;
int char_int(), pot(int base, int exp);
FILE *file;
char dphc[5];
bool vec_ok();
void cal_dib(), tec13(), vec_form(int val), cron(), setcursor(bool visible, DWORD size), aux(int x, int y);
int main(){
	if(first){
		first = false;
		system("MODE CON COLS=91 LINES=30");
		system("color F0");
		setcursor(false, 0);
		file = fopen("monto.txt", "r");
		fgets(dphc, 6, file);
		dph = char_int();
	}
	pant = 1;
	system("cls");
	cal_dib();
	tec = getch();
	while(tec != 13 && tec != 9) tec = getch();
	if(tec == 13){
		tec13();
	}else{
		system("cls");
		cron();
	}
	return 0;
}
void cron(){
	pant = 2;
	tec = 0;
	cal_dib();
	while(true){
		pause_t[0] = (paused[0] && p_ini[0] != 0) ? time(NULL) - p_ini[0] : pause_t[0];
		pause_t[1] = (paused[1] && p_ini[1] != 0) ? time(NULL) - p_ini[1] : pause_t[1];
		if(!kbhit()){
			if(paused[0] == false || paused[1] == false){
				cal_dib();
				Sleep(1000);
			}
		}else{
			tec = getch();
			if(tec == 13 || tec == 9 || tec == 8 || tec == 72  || tec == 80)
			break;
		}
	}
	if(tec == 13){
		paused[selec - 1] = (paused[selec - 1]) ? false : true;
		p_ini[selec - 1] = (paused[selec - 1]) ? time(NULL) : p_ini[selec - 1];
		if(ini[selec - 1] == 0){
			ini[selec - 1] = time(NULL);
			pause_t[selec - 1] = 0;
			pt2[selec - 1] = 0;
		}
		
		if(!paused[selec - 1] && ini[selec - 1] != 0){
			pt2[selec - 1] += pause_t[selec - 1];
			pause_t[selec - 1] = 0;
		}
		cron();
	}else{
		if(tec == 9)
			main();
		else{
			if(tec == 8){
				ini[selec - 1] = 0;
				pause_t[selec - 1] = 0;
				pt2[selec - 1] = 0;
				paused[selec - 1] = true;
				segs[selec - 1] = 0;
				mins[selec - 1] = 0;
				hrs[selec - 1] = 0;
				mon[selec - 1] = 0;
				cron();
			}else{
				if(tec == 72){
					selec = (selec == 2) ? 1 : 1;
					aux(24, 10);printf("                                          ");
					aux(24, 11);printf("                                          ");
				}
				else{
					if(tec == 80){
						selec = (selec == 1) ? 2 : 2;
						aux(24, 3);printf("                                          ");
						aux(24, 4);printf("                                          ");
					}
				}
				cron();
			}
		}
	}
}
void vec_form(int val){
	for(int i = 0; i < 5; i++){
		dphc[i] = val;
	}
}
void tec13(){
	vec_form(NULL);
	system("cls");
	setcursor(true, 1);
	printf("Nueva cantidad de dinero por hora (actual: $%d): ", dph);
	scanf("%s", &dphc);
	if(vec_ok()){
		file = fopen("monto.txt", "w+");
		fprintf(file, dphc);
		fclose(file);
		dph = char_int();
		if(ini[0] != 0){
			dif = (time(NULL) - ini[0] - pt2[0]);
			fact = dif / 3600.0;
			mon[0] = (ini[0] != 0) ? fact * dph : 0;
		}
		if(ini[1] != 0){
			dif = (time(NULL) - ini[1] - pt2[0]);
			fact = dif / 3600.0;
			mon[1] = (ini[1] != 0) ? fact * dph : 0;
		}
		printf("\nOK.");
		system("color 2F");
		setcursor(false, 0);
		Sleep(600);
		system("color F0");
		main();
	}
	else{
		printf("\nERROR, INGRESE NUEVAMENTE.");
		system("color C0");
		setcursor(false, 0);
		Sleep(800);
		system("color F0");
		tec13();
	}
}
bool vec_ok(){
	bool is_ok = true;
	int com = 0;
	for(int i = 0; i < 5; i++){
		com = dphc[i] - 48;
		if(!((com >= 0 && com <=9) || com == NULL - 48)){
			is_ok = false;
		}
	}
	return is_ok;
}
int char_int(){
	int suma = 0, digs = 5;
	for(int i = 4; i >= 0; i--){
		if(dphc[i] != NULL){
			suma += pot(10, digs - (i + 1)) * (dphc[i] - 48);
		}else
			digs--;
	}
	return suma;
}
void cal_dib(){
	if(pant == 1){
		system("cls");
		printf("    LLLLL  FFFF     CCCC   LL   LL   FFFF   CC     CC  LLLLLL  FFFFFFFF  CCCC     LLLL\n");
		printf("   LL      FF  FF  CC  CC  LLLL LL  FF  FF  CCCC CCCC  LL         FF     CC  CC  LL  LL\n");
		printf("   LL      FFFF    CC  CC  LL LLLL  FF  FF  CC CC  CC  LLLLL      FF     CCCC    LL  LL\n");
		printf("   LL      FF FF   CC  CC  LL  LLL  FF  FF  CC     CC  LL         FF     CC CC   LL  LL\n");
		printf("    LLLLL  FF  FF   CCCC   LL   LL   FFFF   CC     CC  LLLLLL     FF     CC  CC   LLLL\n\n\t\t\t");
		printf("Programado por Leandro Cotti\n\n\n\n\n\n");
		printf("\t\tTAB - cronometrar\n\n");
		printf("\t\tDinero por hora: $%d (presione ENTER para cambiar)", dph);
	}else{
		act = time(NULL);
		pt2[0] = (ini[0] == 0) ? 0 : pt2[0];
		pt2[1] = (ini[1] == 0) ? 0 : pt2[1];
		if(!paused[0]){
			dif = (act - ini[0] - pt2[0]);
			fact = dif / 3600.0;
			mon[0] = (ini[0] != 0) ? fact * dph : 0;
			segs[0] = (ini[0] != 0) ? (act - ini[0] - pt2[0]) % 60 : 0;
			mins[0] = (ini[0] != 0) ? ((act - ini[0] - pt2[0]) / 60) % 60 : 0;
			hrs[0] = (ini[0] != 0) ? (act - ini[0] - pt2[0]) / 3600 : 0;
		}
		if(!paused[1]){
			dif = (act - ini[1] - pt2[1]);
			fact = dif / 3600.0;
			mon[1] = (ini[1] != 0) ? fact * dph : 0;
			segs[1] = (ini[1] != 0) ? (act - ini[1] - pt2[1]) % 60 : 0;
			mins[1] = (ini[1] != 0) ? ((act - ini[1] - pt2[1]) / 60) % 60 : 0;
			hrs[1] = (ini[1] != 0) ? (act - ini[1] - pt2[1]) / 3600 : 0;
		}
		aux(0, 0);printf("M%cquina 1:\n\tTiempo: %d : %d : %d \n\tConsumido: $%.2f\n", 160, hrs[0], mins[0], segs[0], mon[0]);
		if(selec == 1){
			aux(0, 3);printf("\t\t\tENTER - %s.          \n\t\t\tBACKSPACE - reiniciar.\n\n\n", (paused[0] == false) ? "pausar" : (ini[0] == 0) ? "activar contador" : "reanudar");
		}else printf("\n\n\n\n");
		aux(0, 7);printf("M%cquina 2:\n\tTiempo: %d : %d : %d \n\tConsumido: $%.2f\n", 160, hrs[1], mins[1], segs[1], mon[1]);
		if(selec == 2){
			aux(0, 10);printf("\t\t\tENTER - %s.          \n\t\t\tBACKSPACE - reiniciar.", (paused[1] == false) ? "pausar" : (ini[1] == 0) ? "activar contador" : "reanudar");
		}
	}
}
int pot(int base, int exp){
	int old = base;
	for(int x = 0; x < exp - 1; x++){
		base *= old;
	}base = (exp == 0) ? 1 : base;
	return base;
}
void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
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
void aux(int x, int y){
	HANDLE oCur;
	oCur = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posicion;
	posicion.X = x;
	posicion.Y = y;
	SetConsoleCursorPosition(oCur, posicion);
}
