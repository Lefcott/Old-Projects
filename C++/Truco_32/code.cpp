#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>//CORREGIR LA ELECCIÓN DE CARTAS
#define vec_num -1//DE LA MÁQUINA!!!!
#define px 65//PROGRAMADO POR 01001100 01100101 01100001
#define py 5//					01101110 01100100 01110010
#define pw 20//					01101111 00100000 01000011
#define ph 34//					01101111 01110100 01110100 01101001;
#define psql 5
#define psqsepl 3
#define psqseps 2
//Modificado: 28/9/16.														TQ: indica si el partido es a 30 o a 15.
//tab = 1: muestra de cartas; tab = 2: mesa.								tur = 1: turno del jugador; tur = 2; turno de la máquina.
//v_123_t_JM: valores carta 1, 2, 3, total, jugador o máquina.				p1, p2, p3: son banderas de cartas empardadas.
//cant(): cantidad de cartas de la máquina: *1: cuatro mejores; *2: siguientes 3; *3: negras; *4: malas.
//mM: manos ganadas por la máquina; mU: manos ganadas por el usuario. JEM: Jugador Es Mano (1 y 2).
//Pantalla: Width: 90; Height: 45;											COO: Cantar O No.
//VARIABLES DE LA MÁQUINA:													GT: el que ganó el envido.
int per = 1, mentir = 100, cantar, vpensar, m_pr = 50, med_pr = 25, max_pr = 25, irse, mdisp[3] = {1, 1, 1}, rnum;
int resp = 1, dib = 1, mazo = 0, canto = 0, most = 1;
int niv_env = 0, env_cont = 0;//1:E;2:R;3:F (niv_env).
bool NQ, flor, not_env = true, CP[3] = {true, true, true};
int palos[3][2], nums[3][2], p, selec = 1, mselec, disp[3] = {1, 1, 1}, tab = 1, tur = 1, mano = 1, mesa[6][2], mM = 0, mU = 0, tirada, JEM = 1, p1 = 0, p2 = 0, p3 = 0;
int reales[10] = {4, 5, 6, 10, 11, 12, 2, 3, 7, 1}, prim, em, cantos = 1, TQ = 1, pU = 0, pM = 0, llamar = 0, GT = 0, tantos = 0;
void dar(), aux(int x, int y), val(), tomar_tecla(), mezcla(), mover(int x1, int x2, int x3, int y, int BM, int _anim), MB_mesa(int MB), cartas(int MM);
void vaciar(int x1, int x2, int x3, int y, int BM, int _anim), ANIM(), vec_form(int val), puntajes(int x, int y, int width, int height, int sq_length, int sq_sepL);
void mat_min(), COO2(), pedir_tecla(int cantar), borrar(), resp_env(), env_res_usu();
void pensar(), jugada_maquina(), DTT(), jugar_usuario(), jugar_maquina(), setcursor(bool visible, DWORD size);
int cant(int rango), MMM(int ret), COO(), car_disp(), env_fl(int JM);
float v_123_JM(int carta, int JM), val_tot(int JM);
char cadena(int i), car, H[15], V[17];
int env_fl(int JM){
	int VT = 0, ref, p1, p2, p3, n1, n2, n3, tmp;
	if(palos[0][JM - 1] == palos[1][JM - 1] &&
		palos[1][JM - 1] == palos[2][JM - 1]){
			flor = true;
			for(int pos = 0; pos < 3; pos++){
				ref = nums[pos][JM - 1];
				VT += (ref < 3 || ref > 5) ? reales[ref] : 0;
			}
			VT += 20;
		}else{
			flor = false;
			p1 = palos[0][JM - 1]; p2 = palos[1][JM - 1]; p3 = palos[2][JM - 1];
			n1 = nums[0][JM - 1]; n2 = nums[1][JM - 1]; n3 = nums[2][JM - 1];
			if(p1 == p2){
				VT += (n1 < 3 || n1 > 5) ? reales[n1] : 0;
				VT += (n2 < 3 || n2 > 5) ? reales[n2] : 0;
			}
			if(p1 == p3){
				VT += (n1 < 3 || n1 > 5) ? reales[n1] : 0;
				VT += (n3 < 3 || n3 > 5) ? reales[n3] : 0;
			}
			if(p2 == p3){
				VT += (n2 < 3 || n2 > 5) ? reales[n2] : 0;
				VT += (n3 < 3 || n3 > 5) ? reales[n3] : 0;
			}
			if(VT > 0) VT += 20;
			if(VT == 0){
				for(int pos = 0; pos < 3; pos++){
					tmp = reales[nums[pos][JM - 1]];
					VT = (tmp > VT && tmp < 10) ? tmp : VT;
				}
			}
		}
	return VT;
}
void cant_env(){
	int prob = rand()%100 + 1;//Número aleatorio de 100 posibilidades.
	int cantar = 0;
	int val = env_fl(2);//Establezco el valor del envido de la máquina.
	cantar == (cantar <= 90) ? (val <= 7/*RANGO 1*/) ? 20 : (val >= 20 && val <= 25/*RANGO 2*/) ? 35 :
				(val >= 26 && val <= 29/*RANGO 3*/) ? 48 : (val >= 30 && val <= 33/*RANGO 4*/) : 0;
	if(cantar <= prob || true /*&& env_cont < 4 (validación)*/){//Cantar envido.
		not_env = false;
		dib = 5;
		niv_env = rand()%3 + 1;
		env_cont++;
		DTT();
		env_res_usu();
	}
}
void env_res_usu(){//Envido Respuesta Usuario.
	char tec = 0;
	while(tec != 27 && tec != 32 && tec != 13) tec = getch();
	if(tec == 32){
		if((env_cont < 4) && niv_env != 3){
			
		}else{
			
		}
	}
}
int COO(){
	int vt = v_123_JM(0, 2) + v_123_JM(1, 2) + v_123_JM(2, 2), val;
	rnum = 1 + rand() % 100;
	cantar = (vt > 25) ? 3 * vt + 1 : (vt <= 25 && vt > 15) ? (rnum < 50) ? 2 * vt + 1 : vt * (3 * rnum / 100) : (vt <= 15) ? vt + rnum / 2 : 0;
	cantar += (cantar <= 80) ? (prim == 2) ? 20 : 0 : 0;
	val = (rnum <= cantar) ? 1 : 0;
	rnum = 1 + rand() % 100;
	cantar -= (cantar >= 20) ? (rnum <= mentir) ? 20 : 0 : 0;
	cantar = (mano == 1) ? 6 : cantar;
	val = (mano == 3 && mesa[2][0] != vec_num && v_123_JM(car_disp(), 2) < v_123_JM(selec, 1)) ? 0 : val;
	val = (rnum <= mentir) ? (val == 1) ? 0 : 1 : val;
	val = (mano == 3 && mesa[2][0] != vec_num && v_123_JM(car_disp(), 2) > v_123_JM(selec, 1)) ? 1 : val;
	val = (canto == 2) ? 0 : val;
	canto = (val == 1) ? 2 : canto;
	return val;
}
void COO2(){
	int vt = v_123_JM(0, 2) + v_123_JM(1, 2) + v_123_JM(2, 2), pens = rand()%4;
	Sleep(440 + rand()%500);
	aux(3, 37);
	printf("                       ");
	aux(3, 37);
	printf((pens == 0) ? "A ver..." : (pens == 1) ? "PENSANDO..." : (pens == 2) ? "EH..." : (pens == 3) ? "MMM..." : "");
	Sleep(440 + rand()%500);
	aux(3, 37);
	printf("                       ");
	if(cantos < 4 && canto != 2 && (vt > 25 || (mano == 3 && v_123_JM(car_disp(), 2) >= 8))){
		cantos++;
		canto = 2;
		resp = 0;
		most = 0;
		pedir_tecla(0);
	}else{
		most = 1;
		resp = 1;
		aux(3, 37);
		if(vt > 12){
			printf("Quiero.");
		}else{
			mazo = 1;
			NQ = true;
			printf("No quiero.");
			cantos--;
			mU = 3;
			mM = 0;
		}
		Sleep(450);
		DTT();
	}
}
int car_disp(){
	int dev = 0;
	for(int c = 0; c < 3; c++){
		dev = (mdisp[c] == 1) ? c : dev;
	}
	return dev;
}
void mat_min(){
	if(mesa[mano - 1][0] != vec_num){
		for(int k = 0; k < 3; k++){
			if(v_123_JM(MMM(k + 1), 2) > v_123_JM(selec, 1)){
				mselec = MMM(k + 1);
				break;
			}
		}
	}
}
int MMM(int ret){
	int min = 11, max = 0, d[3] = {1, 2, 3}, pmin, pmed, pmax;
	for(int nc = 0; nc < 3; nc++){
		if(v_123_JM(nc, 2) < min){
			min = v_123_JM(nc, 2);
			pmin = nc;
		}
		if(v_123_JM(nc, 2) > max){
			max = v_123_JM(nc, 2);
			pmax = nc;
		}
	}
	d[pmin] = 0;
	d[pmax] = 0;
	pmed = d[0] + d[1] + d[2] - 1;
	return (ret == 1) ? pmin : (ret == 2) ? pmed : (ret == 3) ? pmax : 5;
}
int cant(int rango){
	int cont = 0;
	cont += (rango == 1) ? (v_123_JM(0, 2) >= 8) ? 1 : 0 : (rango == 2) ? (v_123_JM(0, 2) < 8 && v_123_JM(0, 2) >= 6) ? 1 : 0 : (rango == 3) ? (v_123_JM(0, 2) < 6 && v_123_JM(0, 2) >= 3) ? 1 : 0 : (rango == 4) ? (v_123_JM(0, 2) < 3) ? 1 : 0 : 0;
	cont += (rango == 1) ? (v_123_JM(1, 2) >= 8) ? 1 : 0 : (rango == 2) ? (v_123_JM(1, 2) < 8 && v_123_JM(1, 2) >= 6) ? 1 : 0 : (rango == 3) ? (v_123_JM(1, 2) < 6 && v_123_JM(1, 2) >= 3) ? 1 : 0 : (rango == 4) ? (v_123_JM(1, 2) < 3) ? 1 : 0 : 0;
	cont += (rango == 1) ? (v_123_JM(2, 2) >= 8) ? 1 : 0 : (rango == 2) ? (v_123_JM(2, 2) < 8 && v_123_JM(2, 2) >= 6) ? 1 : 0 : (rango == 3) ? (v_123_JM(2, 2) < 6 && v_123_JM(2, 2) >= 3) ? 1 : 0 : (rango == 4) ? (v_123_JM(2, 2) < 3) ? 1 : 0 : 0;
	return cont;
}
int main(){
	system("color F0");
	system("MODE CON COLS=90 LINES=38");
	setcursor(0,0);
	vec_form(vec_num);
	dar();
//	nums[0][1] = 9;
//	nums[1][1] = 8;
//	nums[2][1] = 7;
//	palos[0][1] = 0;
//	palos[1][1] = 0;
//	palos[2][1] = 0;
//	
//	nums[0][0] = 0;
//	nums[1][0] = 1;
//	nums[2][0] = 9;
//	palos[0][0] = 1;
//	palos[1][0] = 1;
//	palos[2][0] = 1;
	per = rand() % 3;
	cartas(1);
	tomar_tecla();
	aux(0, 20);
	return 0;
}
void puntajes(int x, int y, int width, int height, int sq_length, int sq_sepL, int sq_sepS){
	int H1, H2, V1, V2, M;
	int contU = pU, contM = pM;
	int sq_height = sq_length - 3;
	sq_sepL++; sq_sepS++;
	sq_length--;
	aux(x + 1, y - 1); printf("jugador"); aux(x + width / 2 + 3, y - 1); printf("m%cquina", 160);
	for(int x2 = x; x2 <= x + width; x2++){
		aux(x2, y);printf("_");
		aux(x2, y + 2.4 * sq_sepL + 3 * sq_height);printf("-");
	}
	for(int y2 = y + 1; y2 <= height; y2++){
		aux(x + width / 2, y2);printf("|");
	}
	int ys = y + 1, ys2 = ys + sq_height + 1, sumY = sq_sepS + sq_height;
	int c1 = 1, c5 = 2, c4 = 3, c2 = 4, c3 = 5, xs, ys3 = ys, yu = ys, ys4 = ys;
	int xm = x + (width / 2) - sq_sepL - 1, ym = ys2 + 1, xum = xm + 1, yum;
	while(contU > 0){
		c1 = (c1 == 5) ? 0 : c1;
		c2 = (c2 == 5) ? 0 : c2;
		c3 = (c3 == 5) ? 0 : c3;
		c4 = (c4 == 5) ? 0 : c4;
		c5 = (c5 == 5) ? 0 : c5;
		H1 = (c1 == 1) ? 1 : 0;
		H2 = (c2 == 1) ? 1 : 0;
		V1 = (c3 == 1) ? 1 : 0;
		V2 = (c4 == 1) ? 1 : 0;
		M = (c5 == 1) ? 1 : 0;
		c1++; c2++; c3++; c4++; c5++; 
		if(H1 == 1){
			for(xs = x + (width / 2) - sq_sepL; xs >= x + (width / 2) - sq_length - sq_sepL; xs--){
				aux(xs, ys);printf("-");
			}ys += sumY;
		}
		if(H2 == 1){
			for(xs = x + (width / 2) - sq_sepL; xs >= x + (width / 2) - sq_length - sq_sepL; xs--){
				aux(xs, ys2);printf("-");
			}ys2 += sumY;
		}
		if(V1 == 1){
			for(yu = ys3 + sq_height + 1; yu >= ys3; yu--){
				aux(xs, yu);printf("|");
			}ys3 += sumY;
		}
		if(V2 == 1){
			for(yu = ys4 + sq_height + 1; yu >= ys4 + 0; yu--){
				aux(xs + sq_length + 2, yu);printf("|");
			}ys4 += sumY;
		}
		if(M == 1){
			for(yum = ym; yum <=  ym + sq_height; yum++){
				aux(xum - 2, yum - sumY + 1);printf("**");
				xum--;
			}ym += sumY;xum = xm + 1;
		}
		contU--;
	}
	ys = y + 1, ys2 = ys + sq_height + 1, sumY = sq_sepS + sq_height;
	c1 = 1, c5 = 2, c4 = 3, c2 = 4, c3 = 5, xs, ys3 = ys, yu = ys, ys4 = ys;
	xm = x + (width / 2) + sq_sepL + 1, ym = ys2 + 1, xum = xm + 1, yum;
	while(contM > 0){
		c1 = (c1 == 5) ? 0 : c1;
		c2 = (c2 == 5) ? 0 : c2;
		c3 = (c3 == 5) ? 0 : c3;
		c4 = (c4 == 5) ? 0 : c4;
		c5 = (c5 == 5) ? 0 : c5;
		H1 = (c1 == 1) ? 1 : 0;
		H2 = (c2 == 1) ? 1 : 0;
		V1 = (c3 == 1) ? 1 : 0;
		V2 = (c4 == 1) ? 1 : 0;
		M = (c5 == 1) ? 1 : 0;
		c1++; c2++; c3++; c4++; c5++; 
		if(H1 == 1){
			for(xs = x + (width / 2) + sq_sepL; xs <= x + (width / 2) + sq_length + sq_sepL; xs++){
				aux(xs, ys);printf("-");
			}ys += sumY;
		}
		if(H2 == 1){
			for(xs = x + (width / 2) + sq_sepL; xs <= x + (width / 2) + sq_length + sq_sepL; xs++){
				aux(xs, ys2);printf("-");
			}ys2 += sumY;
		}
		if(V1 == 1){
			for(yu = ys3 + sq_height + 1; yu >= ys3; yu--){
				aux(xs - sq_length - 2, yu);printf("|");
			}ys3 += sumY;
		}
		if(V2 == 1){
			for(yu = ys4 + sq_height + 1; yu >= ys4 + 0; yu--){
				aux(xs, yu);printf("|");
			}ys4 += sumY;
		}
		if(M == 1){
			for(yum = ym; yum <=  ym + sq_height; yum++){
				aux(xum - 1, yum - sumY + 1);printf("**");
				xum++;
			}ym += sumY;xum = xm + 1;
		}
		contM--;
	}
}
void tomar_tecla(){
	int sum;
	if(tab == 1){
		aux(0, 16);
		printf("                                                        ");
		aux((selec == 0) ? 1 : (selec == 1) ? 21 : (selec == 2) ? 41 : 1, 16);
	//<Esto dibuja la línea de selección>
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176);
	//</Esto dibuja la línea de selección>
	}
	car = 0;
	while(car != 75 && car != 77 && car != 9 && car != 13 && car != 27 && car != 32)
	car = getch();
	if(tab == 1){
		if(car == 75){
			if(selec == 2){
				selec = (disp[1] == 1) ? 1 : (disp[0] == 1) ? 0 : selec;
			}else{
				if(selec == 1){
					selec = (disp[0] == 1) ? 0 : selec;
				}
			}
			Beep(261.63, 300);
		}
		if(car == 77){
			if(selec == 0){
				selec = (disp[1] == 1) ? 1 : (disp[2] == 1) ? 2 : selec;
			}else{
				if(selec == 1){
					selec = (disp[2] == 1) ? 2 : selec;
				}
			}
			Beep(293.66, 300);
		}
		if(car == 13){
			if(disp[selec] == 1){
				if(tur == 1){
					Beep(440, 300);
					jugar_usuario();
				}
			}
		}
	}
	if(car == 27){
		mazo = 1;
		resp = 1;
		mU = 0;
		mM = 3;
		most = 1;
		NQ = false;
		aux(3, 37);printf("Me voy al mazo.          ");
		Sleep(600);
		DTT();
	}
	if(car == 9 && tur == 1){
		sum = mU + mM;
		if(mesa[2][0] == vec_num && sum < 3){
			tab = (tab == 1) ? 2 : 1;
			Beep(493.88, 300);
			if(tab == 1) cartas(1); else{MB_mesa(1); cartas(2);}
		}
	}
	if(car == 32 && cantos < 4 && canto != 1){//SUBE LA APUESTA
		resp = 0;
		canto = 1;
		most = 0;
		cantos++;
		DTT();
		system("color B2");
		Sleep(2500);
		COO2();
	}
	tomar_tecla();
}
void jugar_usuario(){
	static int veces2 = 0; veces2++;
	aux(4, 0);printf("%d", veces2);Sleep(75);
	tirada = selec;
	tab = 2;
	mesa[mano - 1][0] = nums[selec][0];
	mesa[mano - 1][1] = palos[selec][0];
	disp[selec] = 0;
	MB_mesa(1);
	ANIM();
	cartas(2);
	int s;
	if(mesa[mano + 2][0] != vec_num && v_123_JM(selec, 1) > v_123_JM(mselec, 2)){
		em = (mU == mM) ? 1 : 0;
		tur = 1;
		mU++;
		(mano == 2 && (p1 == 1 || prim == 1)) ? mU = 3 : mU;
		(mano == 1) ? prim = 1 : 0;
		(mano == 3 && ((p1 == 1 && p2 == 1) || (em == 1))) ? mU = 3 : 0;
		mano += (mano < 3 && mesa[mano - 1][0] != vec_num && mesa[mano + 2][0] != vec_num) ? 1 : 0;
	}else{
		tur = 2;
		if(mesa[mano + 2][0] != vec_num && v_123_JM(selec, 1) < v_123_JM(mselec, 2)){
			em = (mU == mM) ? 1 : 0;
			mM++;
			(mano == 2 && (p1 == 1 || prim == 2)) ? mM = 3 : mM;
			(mano == 1) ? prim = 2 : 0;
			(mano == 3 && ((p1 == 1 && p2 == 1) || (em == 1))) ? mM = 3 : 0;
			mano += (mano < 3 && mesa[mano - 1][0] != vec_num && mesa[mano + 2][0] != vec_num) ? 1 : 0;
		}
		if(mesa[mano + 2][0] != vec_num && v_123_JM(selec, 1) == v_123_JM(mselec, 2)){
			if(mano == 1){
				tur = (JEM == 1) ? 1 : 2;
				p1 = 1;
			}
			if(mano == 2){
				if(p1 == 1){
					tur = (JEM == 1) ? 1 : 2;
					p2 = 1;
				}else{
					mU += (mU == 1) ? 2 : 0;
					mM += (mM == 1) ? 2 : 0;
				}
			}
			if(mano == 3){
				if(p1 == 1 && p2 == 1){
					(JEM == 1) ? mU = 3 : mM = 3;
				}else{
					(prim == 1) ? mU = 3 : mM = 3;
				}
			}
			mano += (mano < 3 && mesa[mano - 1][0] != vec_num && mesa[mano + 2][0] != vec_num) ? 1 : 0;
		}
	}
	if(tur == 2){
		s = mU + mM;
		if(mesa[mano + 2][0] == vec_num && s < 3) jugar_maquina(); else tur = 1;
	}DTT();
	selec = (disp[0] == 1) ? 0 : (disp[1] == 1) ? 1 : (disp[2] == 1) ? 2 : 1;
}
void jugar_maquina(){//COMPROBANDO EL TURNO TAMBIÉN TIRA ERROR.
	static int veces = 0; veces++;
	aux(0, 0);printf("%d", veces);
	DTT();
	jugada_maquina();
	int sum = mU + mM;
	if(sum < 3){
		if(mesa[mano - 1][0] != vec_num && v_123_JM(mselec, 2) > v_123_JM(selec, 1)){
			int em = (mU == mM) ? 1 : 0;
			tur = 2;
			mM++;
			(mano == 2 && (p1 == 1 || prim == 2)) ? mM = 3 : mM;
			(mano == 1) ? prim = 2 : 0;
			(mano == 3 && ((p1 == 1 && p2 == 1) || (em == 1))) ? mM = 3 : 0;
			sum = mU + mM;
			mano += (mano < 3 && mesa[mano - 1][0] != vec_num && mesa[mano + 2][0] != vec_num) ? 1 : 0;
			if(sum < 3){jugar_maquina();}
		}else{
			tur = 1;
			if(mesa[mano - 1][0] != vec_num && v_123_JM(mselec, 2) < v_123_JM(selec, 1)){
				em = (mU == mM) ? 1 : 0;
				(mano == 1) ? prim = 1 : 0;
				mU++;
				(mano == 2 && (p1 == 1 || prim == 1)) ? mU = 3 : mU;
				(mano == 3 && ((p1 == 1 && p2 == 1) || (em == 1))) ? mU = 3 : 0;
				mano += (mano < 3 && mesa[mano - 1][0] != vec_num && mesa[mano + 2][0] != vec_num) ? 1 : 0;
			}
		}
		if(mesa[mano - 1][0] != vec_num && v_123_JM(selec, 1) == v_123_JM(mselec, 2)){
			if(mano == 1){
				tur = (JEM == 1) ? 1 : 2;
				p1 = 1;
			}
			if(mano == 2){
				if(p1 == 1){
					tur = (JEM == 1) ? 1 : 2;
					p2 = 1;
				}else{
					mU += (mU == 1) ? 2 : 0;
					mM += (mM == 1) ? 2 : 0;
				}
			}
			if(mano == 3){
				if(p1 == 1 && p2 == 1){
					(JEM == 1) ? mU = 3 : mM = 3;
				}else{
					(prim == 1) ? mU = 3 : mM = 3;
				}
			}
			sum = mU + mM;
			mano += (mano < 3 && mesa[mano - 1][0] != vec_num && mesa[mano + 2][0] != vec_num) ? 1 : 0;
			if(sum < 3 && tur == 2) jugar_maquina();
		}
	}
	if(mesa[2][0] == vec_num) DTT();
}
void jugada_maquina(){
	if(mano == 1) cant_env();
	pensar();
	if(mazo == 0){
		aux((mano == 1) ? 6 : (mano == 2) ? 23 : (mano == 3) ? 40 : 40, 20); printf("PENSANDO...");
		Sleep(vpensar);
		aux((mano == 1) ? 6 : (mano == 2) ? 23 : (mano == 3) ? 40 : 40, 20); printf("           ");
		ANIM();
		mesa[mano  + 2][0] = nums[mselec][1];
		mesa[mano + 2][1] = palos[mselec][1];
		cartas(2);
	}else mazo = 0;
	DTT();
}
void pensar(){
	vpensar = 500;
	mselec = 0;
	pedir_tecla(1);
	rnum = 1 + rand() % 100;
	switch(mano){
		case 1:
			mselec = (rnum < m_pr) ? MMM(1) : (rnum > m_pr && rnum < m_pr + med_pr) ? MMM(2) : (rnum > m_pr + med_pr + max_pr) ? MMM(3) : mselec;
			if(mesa[0][0] != vec_num) mat_min();
		break;
		case 2:
			mat_min();
			if(prim == 2) mselec = MMM(1);
			if(p1 == 1) mselec = MMM(3);
		break;
	}
	mselec = (mdisp[mselec] == 0) ? 0 : mselec;
	while(mdisp[mselec] == 0 && mselec < 3){
		mselec++;
	}
	mdisp[mselec] = 0;
}
void pedir_tecla(int cantar){
	int oldCan = cantos, jRes;
	bool ret;
	char jCar = 0;
	cantos += (mano == 3) ? (cantar == 1) ? COO() : 0 : 0;//HACER QUE PUEDA CANTAR EN LAS 3 MANOS.
	jRes = oldCan - cantos;
	resp = (jRes != 0) ? 0 : resp;
	while(jRes != 0 || cantar == 0){
		resp = 0;
		canto = 2;
		most = 0;
		if(tab == 1) cartas(1); else DTT();
		while(jCar != 9 && jCar != 13 && jCar != 27 && jCar != 32) jCar = getch();
		if(jCar == 27){
			mazo = 1;
			resp = 1;
			cantos--;
			mU = 0;
			mM = 3;
			most = 1;
			NQ = true;
			aux(3, 37);printf("                       ");
			aux(3, 37);printf("No quiero.");
			Sleep(500);
		}
		if(jCar == 32 && cantos < 4){
			cantos++;
			most = 0;
			resp = 0;
			canto = 1;
			ret = true;
		}
		if(jCar == 13){//NO HAY QUE CONFUNDIR 'car' con 'jCar'!!!
			resp = 1;
			most = 1;
			ret = false;
			aux(3, 37);printf("                       ");
			aux(3, 37);printf("Quiero.");
			Sleep(500);
		}
		jRes = (jCar != 9) ? 0 : jRes;
		cantar = 1;
		if(jCar == 9){
			jCar = 0;
			tab = (tab == 1) ? 2 : 1;
			Beep(493.88, 300);
			if(tab == 1) cartas(1); else{MB_mesa(1); cartas(2);}
		}
		if(jCar == 13 || jCar == 32){
			if(tab == 1) cartas(1); else DTT();
		}
	}
	if(ret) COO2();
}
float v_123_JM(int carta, int JM){
	int com = carta, com2 = (JM == 1) ? 0 : 1;
	float Q;
	for(int i = 0; i < 10; i++){
		if(nums[com][com2] == i){
			Q = i;
			if(i == 8){
				if(palos[com][com2] == 1 || palos[com][com2] == 3){Q = 2.5;}
				if(palos[com][com2] == 2){Q = 8;}
				if(palos[com][com2] == 0){Q = 9;}
			}
			if(i == 9){
				if(palos[com][com2] == 2 || palos[com][com2] == 3){Q = 5.5;}
				if(palos[com][com2] == 1){Q = 10;}
				if(palos[com][com2] == 0){Q = 11;}
			}
		}
	}
	return Q;
}
float val_tot(int JM){
	return v_123_JM(0, JM) + v_123_JM(1, JM) + v_123_JM(2, JM);
}
void ANIM(){
	int destX = (mano == 1) ? 6 : (mano == 2) ? 23 : (mano == 3) ? 40 : 40;
	int destY = (tur == 1) ? 6 : 20;
	int actX = destX - 5;
	int actY = destY - 5;
	if(tur == 1){DTT();}
	while(actX < destX){
		mover(actX, 0, 0, actY, 2, 1);
		Sleep(20);
		vaciar(actX, 0, 0, actY, 2, 1);
		actX++; actY++;
	}
}
void mezcla(){
	for(int i = 0; i < 4; i++){
		mover(3, 20, 38, 10, 2, 0);
		Sleep(50);
		vaciar(3, 20, 38, 10, 1, 0);
		mover(6, 20, 32, 10, 2, 0);
		Sleep(50);
		vaciar(6, 20, 32, 10, 1, 0);
		mover(12, 18, 28, 10, 2, 0);
		Sleep(50);
		vaciar(12, 18, 28, 10, 1, 0);
		mover(22, 22, 20, 10, 2, 0);
		Sleep(25);
		vaciar(22, 22, 20, 10, 1, 0);
	}
}
void mover(int x1, int x2, int x3, int y, int BM, int _anim){
	if(_anim == 0){
		for(int i = 0; i < 3; i++){
			int DY = (i == 0) ? y : (i == 1) ? y - 2 : y - 1;
			int DX = (i == 0) ? x1 : (i == 1) ? x2 : (i == 2) ? x3 : 0;
			aux(DX, DY - 1);printf(" --------------- ");
			aux(DX, DY);printf("|               | ");
			aux(DX, DY + 1);printf("|               |");
			aux(DX, DY + 2);printf("|               |");
			aux(DX, DY + 3);printf("|               |");
			aux(DX, DY + 4);printf("|               |" );
			aux(DX, DY + 5);printf("|               |" );
			aux(DX, DY + 6);printf("|               |" );
			aux(DX, DY + 7);printf("|               |" );
			aux(DX, DY + 8);printf("|               |" );
			aux(DX, DY + 9);printf("|               |" );
			aux(DX, DY + 10);printf("|               |" );
			aux(DX, DY + 11);printf("|               |" );
			aux(DX, DY + 12);printf(" --------------- ");
		}
	}
	if(_anim == 1){
			aux(x1, y - 1);printf(" --------------- ");
			aux(x1, y);printf("|               | ");
			aux(x1, y + 1);printf("|               |");
			aux(x1, y + 2);printf("|               |");
			aux(x1, y + 3);printf("|               |");
			aux(x1, y + 4);printf("|               |" );
			aux(x1, y + 5);printf("|               |" );
			aux(x1, y + 6);printf("|               |" );
			aux(x1, y + 7);printf("|               |" );
			aux(x1, y + 8);printf("|               |" );
			aux(x1, y + 9);printf("|               |" );
			aux(x1, y + 10);printf("|               |" );
			aux(x1, y + 11);printf("|               |" );
			aux(x1, y + 12);printf(" --------------- ");
	}
}
void vaciar(int x1, int x2, int x3, int y, int BM, int _anim){
	if(_anim == 0){
		for(int k = 0; k < 3; k++){
			int DY = (k == 0) ? y : (k == 1) ? y - 2 : y - 1;
			int DX = (k == 0) ? x1 : (k == 1) ? x2 : (k == 2) ? x3 : 0;
			char es[] = "                 ";
			aux(DX, DY - 1);printf("%s", es);
			aux(DX, DY);printf("%s", es);
			aux(DX, DY + 1);printf("%s", es);
			aux(DX, DY + 2);printf("%s", es);
			aux(DX, DY + 3);printf("%s", es);
			aux(DX, DY + 4);printf("%s", es);
			aux(DX, DY + 5);printf("%s", es);
			aux(DX, DY + 6);printf("%s", es);
			aux(DX, DY + 7);printf("%s", es);
			aux(DX, DY + 8);printf("%s", es);
			aux(DX, DY + 9);printf("%s", es);
			aux(DX, DY + 10);printf("%s", es);
			aux(DX, DY + 11);printf("%s", es);
			aux(DX, DY + 12);printf("%s", es);
		}
	}
	if(_anim == 1){
			char es[] = "                 ";
			aux(x1, y - 1);printf("%s", es);
			aux(x1, y);printf("%s", es);
			aux(x1, y + 1);printf("%s", es);
			aux(x1, y + 2);printf("%s", es);
			aux(x1, y + 3);printf("%s", es);
			aux(x1, y + 4);printf("%s", es);
			aux(x1, y + 5);printf("%s", es);
			aux(x1, y + 6);printf("%s", es);
			aux(x1, y + 7);printf("%s", es);
			aux(x1, y + 8);printf("%s", es);
			aux(x1, y + 9);printf("%s", es);
			aux(x1, y + 10);printf("%s", es);
			aux(x1, y + 11);printf("%s", es);
			aux(x1, y + 12);printf("%s", es);
	}
}
void cartas(int MM){
	int suma, sumaY, lon = (MM == 1) ? 3 : 6;
	MB_mesa(2);
	if(MM == 2){MB_mesa(1);}
	for(int i = 0; i < lon; i++){
		if((MM == 1 && disp[i] == 1) || (MM == 2 && mesa[i][1] != vec_num)){
											//<Esto dibuja la forma de la carta>
			if(MM == 1){suma = (i == 1) ? 20 : (i == 2) ? 40 : 0; sumaY = 0;}
			if(MM == 2){suma = (i == 0 || i == 3) ? 6 : (i == 1 || i == 4) ? 23 : 40; sumaY = (i <= 2) ? 1 : 15;}
			aux(1 + suma, 2 + sumaY); printf("---------------");
			aux(2 + suma, 3 + sumaY); printf("%d", reales[(MM == 1) ? nums[i][0] : mesa[i][0]]);
			aux(suma, 3 + sumaY); printf("|"); aux(suma, 4 + sumaY); printf("|"); aux(suma, 5 + sumaY); printf("|");
			aux(suma, 6 + sumaY); printf("|"); aux(suma, 7 + sumaY); printf("|"); aux(suma, 8 + sumaY); printf("|");
			aux(suma, 9 + sumaY); printf("|"); aux(suma, 10 + sumaY); printf("|"); aux(suma, 11 + sumaY); printf("|");
			aux(suma, 12 + sumaY); printf("|"); aux(suma, 13 + sumaY); printf("|"); aux(suma, 14 + sumaY); printf("|");
		
			aux(15 + suma, 3 + sumaY); printf("|"); aux(15 + suma, 4 + sumaY); printf("|"); aux(15 + suma, 5 + sumaY); printf("|");
			aux(15 + suma, 6 + sumaY); printf("|"); aux(15 + suma, 7 + sumaY); printf("|"); aux(15 + suma, 8 + sumaY); printf("|");
			aux(15 + suma, 9 + sumaY); printf("|"); aux(15 + suma, 10 + sumaY); printf("|"); aux(15 + suma, 11 + sumaY); printf("|");
			aux(15 + suma, 12 + sumaY); printf("|"); aux(15 + suma, 13 + sumaY); printf("|"); aux(15 + suma, 14 + sumaY); printf("|");
			aux(1 + suma, 15 + sumaY); printf("---------------");
												//</Esto dibuja la forma de la carta>
												//<Esto dibuja el palo de la carta>
			p = (MM == 1) ? palos[i][0] : mesa[i][1];
			aux(4 + suma, 6 + sumaY); printf("%s", (p == 0) ? "LLLLLL" : (p == 1) ? "FFFFFF  " : (p == 2) ? " CCCCCC " : (p == 3) ? " LLLLLLL" : "");
			aux(4 + suma, 7 + sumaY); printf("%s", (p == 0) ? "LL    " : (p == 1) ? "FF   FF " : (p == 2) ? "CC    CC" : (p == 3) ? "LL" : "");
			aux(4 + suma, 8 + sumaY); printf("%s", (p == 0) ? "LL    " : (p == 1) ? "FF  FF  " : (p == 2) ? "CC    CC" : (p == 3) ? "LL" : "");
			aux(4 + suma, 9 + sumaY); printf("%s", (p == 0) ? "LLLL  " : (p == 1) ? "FFFFF   " : (p == 2) ? "CC    CC" : (p == 3) ? "LL" : "");
			aux(4 + suma, 10 + sumaY); printf("%s", (p == 0) ? "LL    " : (p == 1) ? "FF  FFF " : (p == 2) ? "CC    CC" : (p == 3) ? "LL" : "");
			aux(4 + suma, 11 + sumaY); printf("%s", (p == 0) ? "LL    " : (p == 1) ? "FF    FF" : (p == 2) ? "CC    CC" : (p == 3) ? "LL" : "");
			aux(4 + suma, 12 + sumaY); printf("%s", (p == 0) ? "LLLLLL" : (p == 1) ? "FFFFFFF " : (p == 2) ? " CCCCCC " : (p == 3) ? " LLLLLLL" : "");
												//</Esto dibuja el palo de la carta>
		}
	}
												//<Esto muestra los controles>
	if(MM == 1){
		env_fl(1);
		aux(1, 18);  printf("ESC: al mazo				%s", (mesa[0][0] == vec_num) ? "E: envido" : "");
		aux(13, 19); printf("				%s", (mesa[0][0] == vec_num) ? "R: real envido" : "");
		aux(13, 20); printf("				%s", (mesa[0][0] == vec_num) ? "F: falta envido" : "");
		aux(1, 20);  printf("FLECHAS: seleccionar carta");
		aux(1, 22);  printf("ENTER: jugar");
		aux(1, 24);  printf("%s %s", (cantos < 4 && canto != 1) ?
			"ESPACIO:" : "        ", (canto != 1) ? (cantos == 1) ? "truco":
			(cantos == 2) ? "retruco" : (cantos == 3) ? "vale cuatro" : "           " : "           ");
		aux(40, 24); printf("%s", (flor) ? "F: FLOR" : "");
	}
	if(tur == 1){
		DTT();
	}
}
void DTT(){
	int s = mU + mM;
	aux(3, 37);
	if(resp == 1 && most == 1){//LA VARIABLE 'mazo' ES VÁLIDA PARA EL JUG. Y LA MÁQ.
		if(!NQ){
			if(cantos > 1){
				printf((s < 3) ? "Estamos en " : "Est%cbamos en ", 160);
				printf((cantos == 2) ? "TRUCO." : (cantos == 3) ? "RETRUCO." : "VALE CUATRO.");
			}
		}else{
			printf("Fue %s no querido.", (cantos == 1) ? "TRUCO" : (cantos == 2) ? "RETRUCO" : "VALE CUATRO");
		}
	}else printf("                        ");
	if(s >= 3){
		pU += (mU > mM) ? cantos : 0;
		pM += (mU < mM) ? cantos : 0;
		(mU > mM) ? Beep(126, 375) : Beep(100, 375);
		mU = 0; mM = 0; selec = 1; mano = 1, mazo = 0;
		p1 = 0; p2 = 0; p3 = 0; em = 0, prim = 0; NQ = false;
		env_cont = 0;
		not_env = true;
		GT = 0; tantos = 0;
		JEM = (JEM == 1) ? 0 : 1;
		tur = (JEM == 1) ? 1 : 2;
		borrar();
		vec_form(vec_num);
		dar();
		disp[0] = 1; disp[1] = 1; disp[2] = 1;
		mdisp[0] = 1; mdisp[1] = 1; mdisp[2] = 1;
		system("color 07");
		Sleep(3625);
		cantos = 1;canto = 0;
		(tur == 1) ? system("color F0") : system("color B2");
		MB_mesa(1);
		mezcla();
		llamar = 1;
	}
	if(resp == 1) {(tur == 1) ? system("color F0") : system("color B2");}
	else{(canto == 2) ? system("color F0") : system("color B2");}
	dib = (not_env) ? 0 : dib;
	if(llamar == 0 && not_env){
		dib = (tur == 1) ? 1 : 0;
		dib = (resp == 0 && most == 0) ? cantos : dib;
	}most = (most == 0) ? 1 : most;
	borrar();
	//aux(3, 30); printf("mU: '%d'; mM: '%d'", mU, mM);
	aux(3, 31); printf((dib == 1) ? "LLLLLLLL FF   FF    CCCCCCCC LL   LL FFFFF   CC   CC  LLLL" : (dib == 2) ? "LLLLLLLL FFFFF   CC   CC  LLLLL  FFFF" : (dib == 3) ? "LLLLL   FFFFFF CCCCCCCC LLLLL   FF   FF  CCCCC  LLLL" :  (dib == 4) ? "LL      LL   F     CC    LLLLLL      FFFFF CC   CC     L    FFFFFFFF CCCCC    LLLLL"  : (dib == 5) ? "LLLLLL FF   FF CC      CC LL FFF     CCCCC"  : (dib == 6) ? "CCCCC   LLLLLL     F     CC       LLLLLL FF   FF CC      CC LL FFF     CCCCC"  : (dib == 6) ? "FFFFF    C     LL    FFFFFFFF    C        LLLLLL FF   FF CC      CC LL FFF     CCCCC":"");
	aux(3, 32); printf((dib == 1) ? "   LL    FF   FF       CC    LL   LL FF  FF  CCC  CC LL  LL" :(dib == 2) ? "   LL    FF  FF  CC   CC LL     FF  FF" :(dib == 3) ? "LL  LL  FF        CC    LL  LL  FF   FF CC     LL  LL" : (dib == 4) ? " LL    LL   FFF    CC    LL         FF     CC   CC    LLL      FF    CC  CC  LL   LL" : (dib == 5) ? "LL     FFF  FF  CC    CC  LL FF FF  CC   CC" : (dib == 6) ? "CC  CC  LL        FFF    CC       LL     FFF  FF  CC    CC  LL FF FF  CC   CC" : (dib == 6) ? "FF      CCC    LL       FF      CCC       LL     FFF  FF  CC    CC  LL FF FF  CC   CC":"");
	aux(3, 33); printf((dib == 1) ? "   LL    FF   FF       CC    LL   LL FFFF    CC C CC LL  LL" :(dib == 2) ? "   LL    FFFF    CC   CC LL     FF  FF" :(dib == 3) ? "LLLL    FFFF      CC    LLLL    FF   FF CC     LL  LL" : (dib == 4) ? "  LL  LL   FF FF   CC    LLLL       FF     CC   CC   LL LL     FF    CCCC    LL   LL" : (dib == 5) ? "LLLL   FF F FF   CC  CC   LL FF  FF CC   CC" : (dib == 6) ? "CCCC    LLLL     FF FF   CC       LLLL   FF F FF   CC  CC   LL FF  FF CC   CC" : (dib == 6) ? "FFFF   CC CC   LL       FF     CC CC      LLLL   FF F FF   CC  CC   LL FF  FF CC   CC":"");
	aux(3, 34); printf((dib == 1) ? "   LL    FF   FF       CC    LL   LL FF  FF  CC  CCC LL  LL" :(dib == 2) ? "   LL    FF  FF  CC   CC LL     FF  FF" :(dib == 3) ? "LL  LL  FF        CC    LL  LL  FF   FF CC     LL  LL" : (dib == 4) ? "   LLLL   FFFFFFF  CC    LL         FF     CC   CC  LLLLLLL    FF    CC  CC  LL   LL" : (dib == 5) ? "LL     FF  FFF    CCCC    LL FF FF  CC   CC" : (dib == 6) ? "CC  CC  LL      FFFFFFF  CC       LL     FF  FFF    CCCC    LL FF FF  CC   CC" : (dib == 6) ? "FF    CCCCCCC  LL       FF    CCCCCCC     LL     FF  FFF    CCCC    LL FF FF  CC   CC":"");
	aux(3, 35); printf((dib == 1) ? "   LL     FFFFF        CC     LLLLL  FF   FF CC   CC  LLLL" : (dib == 2) ? "   LL    FF   FF  CCCCC   LLLLL  FFFF" : (dib == 3) ? "LL   LL FFFFFF    CC    LL   LL  FFFFF   CCCCC  LLLL" :  (dib == 4) ? "    LL   FF     FF CCCCC LLLLLL      FFFFF  CCCCC  LL     LL   FF    CC   CC  LLLLL"  : (dib == 5) ? "LLLLLL FF   FF     CC     LL FFF     CCCCC"  : (dib == 6) ? "CC   CC LLLLLL FF     FF CCCCC    LLLLLL FF   FF     CC     LL FFF     CCCCC"  : (dib == 6) ? "FF   CC     CC LLLLL    FF   CC     CC    LLLLLL FF   FF     CC     LL FFF     CCCCC":"");
	if(llamar == 1){
		llamar = 0;
		if(tur == 2){tab = 2; cartas(2); jugar_maquina();}else{tab = 1; cartas(1);}
	}
}
void borrar(){
	aux(3, 31); printf("                                                                                    ");
	aux(3, 32); printf("                                                                                    ");
	aux(3, 33); printf("                                                                                    ");
	aux(3, 34); printf("                                                                                    ");
	aux(3, 35); printf("                                                                                    ");
}
void MB_mesa(int MB){
//M: mostrar, B: borrar;
	char esp[] = "                                                                                    ";
	system("cls");
	//LÍNEAS VERTICALES
	for(int y = 2; y <= 35; y++){aux(2, y); printf((MB == 1) ? "|%s|" : " ", esp);}
	//LÍNEAS HORIZONTALES
	aux(3, 2); printf((MB == 1) ? "------------------------------------------------------------------------------------" : " ", esp);
	
	aux(3, 36); printf((MB == 1) ? "------------------------------------------------------------------------------------" : " ", esp);
	puntajes(px, py, pw, ph, psql, psqsepl, psqseps);
}
void dar(){
	srand(time(NULL));
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			palos[j][i] = rand() % 4;
			nums[j][i] = rand() % 10;
			val();
			//aux(2, 45); Creo que esto es innecesario.
		}
	}
}
void val(){
	bool iguales;
	int cont = 0;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 2; k++){
				for(int l = 0; l < 3; l++){
					if(i != k || j != l){
						if(nums[j][i] == nums[l][k] && palos[j][i] == palos[l][k]){
							nums[l][k] = rand() % 10;
							iguales = true;
						}
					}
				}
			}
		}
	}
	if(iguales == true) val();
}
void vec_form(int val){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 2; j++){
			mesa[i][j] = val;
		}
	}
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
/*CONSIGNAS:		*Programar inteligencia artificial consiguiendo distintos modos de juego (que estos se elijan de forma aleatoria).
					*Incluir instrucciones.
					*Mostrar un menú de presentación (incluyendo créditos) y otro de fin de juego.
					*Validar los cantos.
					___Mostrar los cantos.
					___Hacer que en el turno de la máquina SOLO se pueda ver la mesa de juego.
					___Usar distintos colores para diferenciar el turno del jugador y de la máquina.
					___Mostrar animación de mezclar al momento de finalizar la mano y al de tirar una carta.
					___Hacer vector que guarde los valores de las cartas en mesa.
					___Reproducir sonidos al ejecutar acciones.
					___Mostrar y validar puntajes.
	SITUACIONES A CORREGIR:
El contrincante no quiere el retruco y en la próxima mano tira una carta, piensa, hace la animación en el lugar del jugador y dice "TU TURNO". (Seguro va a "jugar_usuario").
Es lo anterior o va a la pantalla del mazo, tira la carta, muestra la mesa y muestra la barra de selección.
En lo de 2 líneas atrás tira una carta que no aparece posteriormente y después la borra. También se invierten los colores.
El contrincante solo canta truco en la tercera mano.
Cuando las 2 primeras son pardas, gana el que es mano.*/
