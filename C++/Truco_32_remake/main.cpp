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
#define psqseps 2//UGE: usuario gana envido.
#define key_E 69//OLD son los puntos apostados antes de la apuesta no querida.
#define key_R 82
#define key_F 70
//Modificado: 21/10/16.														TQ: indica si el partido es a 30 o a 15.
//tab = 1: muestra de cartas; tab = 2: mesa.								tur = 1: turno del jugador; tur = 2; turno de la máquina.
//v_123_t_JM: valores carta 1, 2, 3, total, jugador o máquina.				p1, p2, p3: son banderas de cartas empardadas.
//cant(): cantidad de cartas de la máquina: *1: cuatro mejores; *2: siguientes 3; *3: negras; *4: malas.
//mM: manos ganadas por la máquina; mU: manos ganadas por el usuario. JEM: Jugador Es Mano (1 y 2).
//Pantalla: Width: 90; Height: 45;											
//VARIABLES DE LA MÁQUINA:													GT: el que ganó el envido (1:J;2:M).
int per = 1, mentir = 100, cantar, vpensar, m_pr = 50, med_pr = 25, max_pr = 25, irse, mdisp[3] = {1, 1, 1}, rnum;
int resp = 1, dib = 1, mazo = 0, canto = 0, most = 1, OLD, glob_niv;
int niv_env = 0/*1:E;2:R;3:F*/, env_cont = 0, oldTant = 0/*Por si no quiere envido*/, tantos, CE[4]/*Cantos de envido*/, env_sum/*Envido sumado*/;
bool NQ, flor, not_env = true, CP[3] = {true, true, true}, maq_env, UGE, querido = false, JNQE = false/*Jugador No Quiere Envido*/, resp_en, dib_resp;
bool env_disp(int nEnv/*Número de envido*/), envDisp2()/*Dice si se puede cantar algún envido*/, lo_obvio();
int palos[3][2], nums[3][2], p, selec = 1, mselec, disp[3] = {1, 1, 1}, tab = 1, tur = 1, mano = 1, mesa[6][2], mM = 0, mU = 0, tirada, JEM = 1, p1 = 0, p2 = 0, p3 = 0;
int reales[10] = {4, 5, 6, 10, 11, 12, 2, 3, 7, 1}, prim, em, cantos = 1, TQ = 2, pU = 0, pM = 0, llamar = 0, GT = 0;
void dar(), aux(int x, int y), val(), tomar_tecla(), mezcla(), mover(int x1, int x2, int x3, int y, int BM, int _anim), MB_mesa(int MB), cartas(int MM);
void truco(bool en_resp), truco_resp(), menu(), ins(), juego(), REINICIAR(), GP(int action);
void vaciar(int x1, int x2, int x3, int y, int BM, int _anim), ANIM(), vec_form(int val), puntajes(int x, int y, int width, int height, int sq_length, int sq_sepL, int sq_sepS);
void mat_min(), pedir_tecla(int cantar), borrar(), resp_env(), env_res_usu(), comment_clean(), env_proc(char tec, bool mano_env);
void pensar(), jugada_maquina(), DTT(), jugar_usuario(), jugar_maquina(), setcursor(bool visible, DWORD size);
int cant(int rango), MMM(int ret), car_disp(), env_fl(int JM), pun_gan(), suma_tantos(), main();
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
void cant_env(bool en_resp/*En respuesta*/){
	int prob, AL;//AL: aleatorio.
	int val = env_fl(2);//Establezco el valor del envido de la máquina.
	char fin_env = 0;
	bool env_prd;
	if(val >= 30 && val <= 33)
		prob = 1;
	if(val >= 26 && val <= 29)
		prob = 2;
	if(val >= 20 && val <= 25)
		prob = 5;
	if(val <= 7)
		prob = 10;
	if(en_resp) prob *= 5;
	AL = rand()%prob;
	if(AL <= prob / 2 && (env_disp(1) || env_disp(2) || env_disp(3))){//Cantar envido.
		not_env = false;
		maq_env = true;int c = 0;
		niv_env = 1;
		OLD = (tantos == 0) ? 1 : tantos;
		if(rand()%100 < 50) niv_env = rand()%2 + 1;
		if(rand()%100 < 10) niv_env = rand()%3 + 1;
		while(!env_disp(niv_env)){ niv_env = rand()%3 + 1;aux(c, 0);printf(" %d ", niv_env);c++;}
		dib = 4 + niv_env;
		glob_niv = niv_env;
		CE[env_cont] = niv_env;
		tantos += (niv_env == 1) ? 2 : (niv_env == 2) ? 3 : 0;
		tantos = (niv_env == 3) ? 15 - pun_gan() : tantos;
		env_cont++;
		oldTant = suma_tantos();
		dib_resp = true;
		DTT();
		env_res_usu();
	}else{
		comment_clean();
		if(en_resp){
			prob /= 5;
			AL = rand()%prob;
			UGE = (env_fl(1) > env_fl(2)) ? true : false;
			env_prd = (env_fl(1) == env_fl(2)) ? true : false;
			UGE = (env_prd) ? (JEM == 1) ? true : false : UGE;
			system("color F0");
			if(AL <= prob / 2 && env_fl(2) >= 20){
				aux(10, 37);
				printf("Quiero, %d.", env_fl(2));
				aux(51, 37); printf("Enter: %s", (!UGE) ? (env_prd) ? "me ganaste de mano." : "son buenas." : "");
				aux(51, 37); if(UGE) printf("Enter: %d %s.", env_fl(1), (env_prd) ? "y soy mano." : "son mejores.");
				fin_env = 0;
				pU += (UGE) ? tantos : 0;
				pM += (!UGE) ? tantos : 0;
				system("color B2");
				Sleep(650);
				system("color F0");
				env_sum = true;
				while(fin_env != 13) fin_env = getch();
				puntajes(px, py, pw, ph, psql, psqsepl, psqseps);
			}
			else{
				aux(25, 37);
				printf("No quiero.");
				pU += OLD;
				puntajes(px, py, pw, ph, psql, psqsepl, psqseps);
				env_sum = true;
				Sleep(650);
			}
			DTT();
		}
	}
}
int suma_tantos(){
	int suma = 0;
	if(env_cont == 1) suma = 1;
	else{for(int x = 0; x < env_cont - 2; x++){suma += CE[x];}}
	return suma;/*Si no se quiere cualquier envido se devuelve esta suma.*/
}
int pun_gan(){/*Devuelve los puntos del que va ganando.*/return (pU > pM) ? pU : pM;}
bool env_disp(int nEnv){
	bool disp = false;
	switch(nEnv){
		case 1:
			disp = (env_cont < 2 && glob_niv != 3 && glob_niv != 2) ? true : false;
			disp = (env_sum) ? false : disp;
		break;
		case 2:
			disp = (env_cont < 3 && glob_niv != 3) ? true : false;
			disp = (env_cont == 2 && glob_niv == 2) ? false : disp;
			disp = (env_sum) ? false : disp;
		break;
		case 3:
			disp = (glob_niv != 3) ? true : false;
			disp = (env_sum) ? false : disp;
		break;
	}
	return disp;
}
bool envDisp2(){
	int cont = 0;
	for(int x = 0; x < 3; x++){
		cont += (env_disp(x + 1)) ? 1 : 0;
	}
	return (cont > 0 && !env_sum) ? true : false;
}
void comment_clean(){
	for(int i = 0; i < 89; i++){
		aux(i, 37);
		printf(" ");
	}
}
void env_res_usu(){//Envido Respuesta Usuario.
	char tec = 0;
	env_fl(1);
	if(flor){ aux(71, 37); printf("                  ");}
	while(tec != 27 && tec != key_E && tec != key_R && tec != key_F && tec != 13 && tec != 32) tec = toupper(getch());
	env_proc(tec, false);
}
void env_proc(char tec, bool mano_env){
	int rndRs = rand()%3, m_fl;
	char fin_env2;
	bool maq_mano = false/*(SI ES MANO Y GANA)*/, env_prd = false/*Si los envidos son iguales*/, UGE2, env_prd2;
	comment_clean();
	system("color F0");
	if(tec == key_E){
		if(env_disp(1)){
			env_fl(1);
			if(!flor){
				niv_env = 1;
				dib = 5;
				CE[env_cont] = 1;
				OLD = tantos;
				OLD = (tantos == 0) ? 1 : tantos;
				tantos += 2;
				env_cont++;
				oldTant = suma_tantos();
				system("color B2");
				querido = true;
				dib = 5;
				not_env = false;
				DTT();
				Sleep(650);
				glob_niv = niv_env;
				cant_env(true);
			}else env_res_usu();
		}else env_res_usu();
	}
	if(tec == key_R){
		if(env_disp(2)){
			env_fl(1);
			if(!flor){
				niv_env = 2;
				CE[env_cont] = 2;
				OLD = tantos;
				OLD = (tantos == 0) ? 1 : tantos;
				tantos += 3;
				env_cont++;
				oldTant = suma_tantos();
				system("color B2");
				querido = true;
				dib = 6;
				not_env = false;
				DTT();
				Sleep(650);
				glob_niv = niv_env;
				cant_env(true);
			}else env_res_usu();
		}else env_res_usu();
	}
	if(tec == key_F){
		if(!mano_env){
			if(env_disp(3)){
				env_fl(1);
				if(!flor){
					niv_env = 3;
					CE[env_cont] = 3;
					OLD = tantos;
					OLD = (tantos == 0) ? 1 : tantos;
					tantos = 15 - pun_gan();
					env_cont++;
					oldTant = suma_tantos();
					system("color B2");
					querido = true;
					dib = 7;
					not_env = false;
					DTT();
					Sleep(650);
					glob_niv = niv_env;
					cant_env(true);
				}else env_res_usu();
			}else env_res_usu();
		}else{
			UGE2 = (env_fl(1) > env_fl(2)) ? true : false;
			env_prd2 = (env_fl(1) == env_fl(2)) ? true : false;
			UGE2 = (env_prd2) ? (JEM == 1) ? true : false : UGE2;
			dib = 8;
			env_sum = true;
			not_env = false;
			system("color B2");
			DTT();
			m_fl = env_fl(2);
			Sleep(650);
			if(!flor){
				DTT();
				system("color B2");
				Sleep(650);
				comment_clean();
				aux(25, 37); printf("Ok, anotate los puntos...");
				system("color F0");
				Sleep(650);
				env_sum = true;
				pU += 3;
				puntajes(px, py, pw, ph, psql, psqsepl, psqseps);
			}else{
				comment_clean();
				if(env_fl(2) > 26){
					aux(10, 37); printf("QUIERO, %d!", m_fl);
					aux(46, 37); printf("Enter: %s", (!UGE2) ? (env_prd2) ? "me ganaste de mano." : "son buenas." : "");
					aux(46, 37); if(UGE2) printf("Enter: %d %s.", env_fl(1), (env_prd2) ? "y soy mano." : "son mejores.");
					Sleep(800);
					pU += (UGE2) ? 3 : 0;
					pM += (!UGE2) ? 6 : 0;
					fin_env2 = 0;
					while(fin_env2 != 13) fin_env2 = getch();
					env_sum = true;
					DTT();
					puntajes(px, py, pw, ph, psql, psqsepl, psqseps);
					//aux(40, 24); printf("       ");
				}else{
					system("color F0");
					DTT();
				}
			}
		}
	}
	if(tec == 32){//FLOR.
		env_fl(1);
		if(flor){
			dib = 8;
			pU += 3;
			env_sum = true;
			not_env = false;
			DTT();
			Sleep(650);
		}else env_res_usu();
	}
	if(tec == 27){
		env_fl(1);
		if(!flor){
			system("color B2");
			comment_clean();
			aux(25, 37);
			printf("No quiero.");
			pM += OLD;
			env_sum = true;
			puntajes(px, py, pw, ph, psql, psqsepl, psqseps);
			Sleep(650);
			DTT();
		}else env_res_usu();
	}
	if(tec == 13){
		if(!flor){
			UGE = (env_fl(1) > env_fl(2)) ? true : false;
			env_prd = (env_fl(1) == env_fl(2)) ? true : false;
			maq_mano = (env_prd && JEM == 1) ? false : true;
			UGE = (env_prd) ? (JEM == 1) ? true : false : UGE;
			querido = true;
			resp_en = true;
			DTT();
			Sleep(650);
			comment_clean();
			aux(46, 37); printf("%s...", (rndRs == 0) ? "Eh" : (rndRs == 1) ? "MMM" : ""); Sleep(500);
			aux(46, 37); printf("%s", (UGE) ? (env_prd) ? "Me ganaste de mano." : "Son buenas." : "");
			if(!UGE) printf("%d %s.", env_fl(2), (env_prd) ? "y soy mano" : "son mejores");
			pU += (UGE) ? tantos : 0;
			pM += (!UGE) ? tantos : 0;
			puntajes(px, py, pw, ph, psql, psqsepl, psqseps);
			env_sum = true;
			env_prd = false;
			Sleep(1000);
		}else env_res_usu();
	}
	comment_clean();
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
void menu(){
	aux(15, 1); printf("LLLLLLLLLL   FFFF     CC    CC    LLLLLL    FFFFFF");
	aux(15, 2); printf("    LL       FF FF    CC    CC   LL        FF    FF");
	aux(15, 3); printf("    LL       FF  FF   CC    CC   LL        FF    FF");
	aux(15, 4); printf("    LL       FF  FF   CC    CC   LL        FF    FF");
	aux(15, 5); printf("    LL       FFFFF    CC    CC   LL        FF    FF");
	aux(15, 6); printf("    LL       FF F     CC    CC   LL        FF    FF");
	aux(15, 7); printf("    LL       FF  FF    CCCCCC     LLLLLL    FFFFFF");
	aux(15, 8); printf("LFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFCLFC");
	aux(15, 13); printf("                   ENTER: JUGAR");
	aux(15, 16); printf("                TAB: INSTRUCCIONES");
	aux(15, 19); printf("                   ESCAPE: SALIR");
	aux(27, 24); printf("PROGRAMADO POR LEANDRO COTTI.");
	aux(23, 26); printf("CARTAS DISE%cADAS POR ALEX VALDIVIEZO.", 165);
	aux(25, 28); printf("IDEA PRINCIPAL POR ARIEL PENELAS.", 165);
	
}
void ins(){
	char tec;
	int y = 0;
	system("MODE CON COLS=110 LINES=42");
	system("color F0");
	aux(0, y); printf("INSTRUCCIONES:");
	aux(2, y + 1);printf("Se reparten 3 cartas a los 2 jugadores.");
	aux(2, y + 2);printf("El objetivo es llegar a 15 puntos. Para ganar los puntos apostados un jugador deber%c ganar 2 de 3 manos.", 160);
	aux(2, y + 3);printf("Si un jugador gan%c y no se apost%c nada, se lleva 1 punto.", 162, 162);
	aux(2, y + 5);printf("El truco: un jugador puede cantar truco para subir la apuesta (entonces valdr%c 2 puntos).", 160);
	aux(2, y + 6);printf("El retruco: se canta para que la apuesta valga 3 puntos (se canta despu%cs del truco).", 130);
	aux(2, y + 7);printf("El vale cuatro: se canta para que la apuesta valga 4 puntos (se canta despu%cs del retruco).", 130);
	aux(2, y + 9);printf("El envido: cualquier envido se podr%c cantar solo antes de jugar la primera carta.", 160);
	aux(2, y + 10);printf("Si el jugador posee 2 cartas del mismo palo, el valor del envido es de 20 m%cs el la suma del valor de\n  ambas cartas (del 1 al 7 valen su n%cmero y el 10, 11 y 12 valen 0).", 160, 163);
	aux(2, y + 12);printf("Si las 3 cartas son de diferente palo, el envido toma el valor de la carta con mayor valor.");
	aux(2, y + 14);printf("Cantos disponibles para el envido: ");
	aux(2, y + 15);printf("Envido: se puede cantar como respuesta a otro envido, sumando 2 puntos a la apuesta.");
	aux(2, y + 17);printf("Real envido: se puede cantar como respuesta a un envido y un real envido, suma 3 puntos.");
	aux(2, y + 19);printf("Falta envido: se puede cantar arriba del envido y del real envido.");
	aux(2, y + 20);printf("Al que gana esta apuesta se le suman los puntos que le faltan al que va ganando para llegar a 15.");
	aux(2, y + 22);printf("Una vez querido, el que haya dicho quiero tendr%c que decir los puntos que suma el envido.", 160);
	aux(2, y + 23);printf("Si el otro jugador no los pasa, ese mismo dir%c que son buenas, y si los pasa dir%c sus tantos y \n  \"son mejores\". Ejemplo: 26 son mejores.", 160, 160);
	aux(2, y + 26);printf("El jugador desafiado a una apuesta mayor puede hacer lo siguiente:");
	aux(2, y + 27);printf("Decir quiero: acepta la apuesta.");
	aux(2, y + 28);printf("Decir no quiero: no acepta la apuesta y el jugador contrario se anotar%c los puntos apostados hasta antes de", 160);
	aux(2, y + 29);printf("subir la apuesta. Si le dijo no quiero al truco, retruco o vale cuatro, significa que ese jugador\n  se va al mazo y se reparte de nuevo.");
	aux(2, y + 32);printf("Flor: si un jugador tiene las 3 cartas del mismo palo podr%c cantar flor, y si el otro no dice nada,\n  se anota 3 puntos.", 160);
	aux(2, y + 35);printf("Si el otro jugador tambi%cn tiene flor, las posibles respuestas son las siguientes:", 130);
	aux(4, y + 36);printf("Quiero: dir%c los puntos que suma la flor y si el otro no los pasa, se anota 3 puntos.", 160);
	aux(11, y + 37);printf("En el caso de que los pase, los tiene que dar a conocer. Ejemplo: 36 son mejores.");
	aux(4, y + 38);printf("Contraflor: Se apuestan 6 puntos.");
	aux(4, y + 39);printf("Contraflor al resto: se apuesta la partida.\n\t\t\t\t\t\t");
	
	printf("Presione TAB para volver al men%c.", 163);
	tec = 0;
	while(tec != 9) tec = getch();
	main();
}
int main(){
	char com = 0;
	system("color F0");
	system("MODE CON COLS=90 LINES=38");
	setcursor(0,0);
	REINICIAR();
	menu();
	while(com != 13 && com != 9 && com != 27) com = getch();
	if(com == 13) juego();
	if(com == 9) ins();
	if(com == 27) exit(0);
	return 0;
}
void REINICIAR(){
	per = 1; mentir = 100; cantar; vpensar; m_pr = 50; med_pr = 25; max_pr = 25; irse; mdisp[0] = 1; mdisp[1] = 1; mdisp[0] = 2;rnum;
	resp = 1; dib = 1; mazo = 0; canto = 0; most = 1; OLD; glob_niv;
	niv_env = 0/*1:E;2:R;3:F*/; env_cont = 0; oldTant = 0/*Por si no quiere envido*/; tantos; CE[4]/*Cantos de envido*/; env_sum/*Envido sumado*/;
	NQ; flor; not_env = true; CP[0] = true; CP[1] = true; CP[2] = true; maq_env; UGE; querido = false; JNQE = false/*Jugador No Quiere Envido*/; resp_en; dib_resp;
	p = 0; selec = 1; mselec = 0; disp[0] = 1; disp[1] = 1; disp[2] = 1; tab = 1; tur = 1; mano = 1; mM = 0; mU = 0; tirada; JEM = 1; p1 = 0; p2 = 0; p3 = 0;
	prim; em; cantos = 1; TQ = 2; pU = 0; pM = 0; llamar = 0; GT = 0;
}
void juego(){
	system("cls");
	vec_form(vec_num);
	dar();
	pU = 0;
	pM = 0;
	JEM = 1;
	/*nums[0][1] = 0;
	nums[1][1] = 9;
	nums[2][1] = 7;
	palos[0][1] = 0;
	palos[1][1] = 0;
	palos[2][1] = 0;

	nums[0][0] = 0;
	nums[1][0] = 1;
	nums[2][0] = 8;
	palos[0][0] = 1;
	palos[1][0] = 1;
	palos[2][0] = 1;*/
	
	per = rand() % 3;
	cartas(1);
	tomar_tecla();
	aux(0, 20);
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
				aux(xum - 2, yum - sumY + 1);printf("///");
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
			xum++;
			for(yum = ym; yum <=  ym + sq_height; yum++){
				aux(xum - 1, yum - sumY + 1);printf("///");
				xum--;
			}ym += sumY;xum = xm + 1;
		}
		contM--;
	}
}
void truco(bool en_resp){
	int prob, st = val_tot(2), AL, querer = rand()%2;
	prob = (st <= 30 && st >= 27) ? 1 : prob;
	prob = (st <= 26 && st >= 23) ? 2 : prob;
	prob = (st <= 22 && st >= 19) ? 3 : prob;
	prob = (st <= 18 && st >= 15) ? 4 : prob;
	prob = (st <= 14 && st >= 11) ? 5 : prob;
	prob = (st <= 10) ? 12 : prob;
	prob *= (en_resp && prob != 1) ? cantos : 1;
	AL = rand()%prob;
	if(mano == 3 && mesa[2][0] != vec_num && v_123_JM(selec, 1) > v_123_JM(MMM(3), 2)) AL = 1;
	if(mano == 3 && mesa[2][0] != vec_num && v_123_JM(selec, 1) < v_123_JM(MMM(3), 2)) AL = 0;
	if(AL == 0 && cantos < 4 && canto != 2){
		resp = 0;
		most = 0;
		canto = 2;
		not_env = true;
		cantos++;
		DTT();
		truco_resp();
	}else{
		if(en_resp){
			resp = 1;
			comment_clean();
			system("color F0");
			if(querer || lo_obvio()){//POR AHORA!
				aux(25, 37); printf("Quiero.");
				Sleep(650);
			}else{
				aux(25, 37); printf("No quiero.");
				most = 1;
				mazo = 1;
				mU = 3;
				mM = 0;
				cantos--;
				NQ = true;
				Sleep(650);
				DTT();
			}
		}
	}
}
bool lo_obvio(){
	bool ret = false;
	ret = (mano == 1 && mesa[0][0] != vec_num && v_123_JM(2, selec) < v_123_JM(2, MMM(3))) ? true : ret;
	ret = (mano == 2 && mesa[1][0] != vec_num && v_123_JM(2, selec) < v_123_JM(2, MMM(3))) ? true : ret;
	ret = (mano == 3 && mesa[2][0] != vec_num && v_123_JM(2, selec) < v_123_JM(2, MMM(3))) ? true : ret;
	return ret;
}
void truco_resp(){
	if(canto != 1){
		char resp = 0;
		comment_clean();
		if(cantos < 4){
			aux(1, 37); printf("ESPACIO: %s.", (cantos == 2) ? "retruco" : "vale cuatro");	
		}
		aux(25, 37); printf("ENTER: quiero.   ESCAPE: no quiero.");
		while(resp != 13 && resp != 27 && resp != 32) resp = getch();
		if(resp == 27){
			mazo = 1;
			resp = 1;
			mU = 0;
			mM = 3;
			most = 1;
			NQ = true;
			comment_clean();
			aux(3, 37);printf("No quiero.");
			cantos--;
			most = 1;
			NQ = true;
			Sleep(600);
			DTT();
		}
		if(resp == 13){
			resp = 1;
			comment_clean();
			aux(3, 37);printf("Quiero");
			system("color B2");
			Sleep(300);
			DTT();
		}
		if(resp == 32){
			if(cantos < 4){
				resp = 0;
				cantos++;
				most = 0;
				canto = 1;
				not_env = true;
				system("color B2");
				DTT();
				comment_clean();
				Sleep(600);
				truco(true);
			}else truco_resp();
		}
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
	while(car != 75 && car != 77 && car != 9 && car != 13 && car != 27 && car != 32 && car != key_E && car != key_R && car != key_F)
	car = toupper(getch());
	env_fl(1);
	if(((car == key_E && env_disp(1)) || (car == key_R && env_disp(2)) || (car == key_F && env_disp(3))) && cantos == 1) env_proc(car, flor);
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
		comment_clean();
		aux(3, 37);printf("Me voy al mazo.");
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
	env_fl(1);
	if(car == 32 && cantos < 4 && canto != 1 && !(mano == 1 && flor)){//SUBE LA APUESTA
		resp = 0;
		canto = 1;
		most = 0;
		cantos++;
		not_env = true;
		DTT();
		system("color B2");
		Sleep(2500);
		truco(true);
	}
	tomar_tecla();
}
void jugar_usuario(){
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
	char QOO, fin_flor;
	bool querer;
	int rndRs = rand()%4;
	if(mano == 1 && !env_sum && cantos == 1){
		env_fl(2);
		if(!flor)
			cant_env(false);
		else{
			bool UGE2 = (env_fl(1) > env_fl(2)) ? true : false;
			bool env_prd2 = (env_fl(1) == env_fl(2)) ? true : false;
			UGE2 = (env_prd2) ? (JEM == 1) ? true : false : UGE2;
			dib = 8;
			not_env = false;
			env_sum = true;
			DTT();
			system("color F0");
			comment_clean();
			env_fl(1);
			if(flor){
				aux(5, 37); printf("C: CONTRAFLOR AL RESTO.   ESPACIO: CONTRAFLOR.   ENTER: quiero. ESCAPE: no quiero.");
				QOO = 0;
				while(QOO != 13 && QOO != 27 && QOO != 32 && QOO != 67) QOO = toupper(getch());
				if(QOO == 67){
					aux(28, 37); printf("                                                         ");
					system("color B2");
					Sleep(800);
					system("color F0");
					querer = (env_fl(2) > 32) ? true : false;
					if(querer){
						comment_clean();
						aux(30, 37); printf("QUIERO, %d!", env_fl(2));
						aux(66, 37); printf("Enter: %s", (!UGE2) ? (env_prd2) ? "me ganaste de mano." : "son buenas." : "");
						aux(66, 37); if(UGE2) printf("Enter: %d %s.", env_fl(1), (env_prd2) ? "y soy mano." : "son mejores.");
						if(UGE2) pU = 15;
						else pM = 15;
						fin_flor = 0;
						while(fin_flor != 13) fin_flor = getch();
					}else{
						comment_clean();
						aux(30, 37); printf("No quiero.");
						pU += 4;
						system("color F0");
						Sleep(800);
						DTT();
					}
				}
				if(QOO == 32){
					comment_clean();
					aux(25, 37); printf("CONTRAFLOR.");
					system("color B2");
					Sleep(800);
					system("color F0");
					querer = (env_fl(2) > 30) ? true : false;
					if(querer){
						comment_clean();
						aux(30, 37); printf("QUIERO, %d!", env_fl(2));
						aux(66, 37); printf("Enter: %s", (!UGE2) ? (env_prd2) ? "me ganaste de mano." : "son buenas." : "");
						aux(66, 37); if(UGE2) printf("Enter: %d %s.", env_fl(1), (env_prd2) ? "y soy mano." : "son mejores.");
						if(UGE2) pU += 6;
						else pM += 6;
						fin_flor = 0;
						while(fin_flor != 13) fin_flor = getch();
					}else{
						comment_clean();
						aux(30, 37); printf("No quiero.");
						pU += 4;
						system("color F0");
						Sleep(800);
						DTT();
					}
				}
				if(QOO == 13){
					comment_clean();
					aux(25, 37); printf("QUIERO, %d!", env_fl(1));
					system("color B2");
					Sleep(800);
					system("color F0");
					aux(66, 37); printf("                   ");
					aux(66, 37); printf("%s...", (rndRs == 0) ? "Eh" : (rndRs == 1) ? "MMM" : (rndRs == 2) ? "Esperame que sumo..." : ""); Sleep(500);
					aux(66, 37); printf("%s", (UGE2) ? (env_prd2) ? "Me ganaste de mano." : "Son buenas." : "");
					if(!UGE2) printf("%d %s.", env_fl(2), (env_prd2) ? "y soy mano" : "son mejores");
					pU += (UGE) ? 6 : 0;
					pM += (!UGE) ? 6 : 0;
					Sleep(650);
					comment_clean();
				}
				if(QOO == 27){
					comment_clean();
					aux(25, 37); printf("NO QUIERO.");
					system("color B2");
					Sleep(800);
					system("color F0");
					pM += 4;
				}
				puntajes(px, py, pw, ph, psql, psqsepl, psqseps);
			}else{
				aux(25, 37); printf("ENTER: ok, anotate los puntos.");
				fin_flor = 0;
				while(fin_flor != 13) fin_flor = getch();
				system("color B2");
				pM += 3;
				puntajes(px, py, pw, ph, psql, psqsepl, psqseps);
				Sleep(800);
				comment_clean();
			}
		}
	}
	if(!(mano == 1 && JEM != 1)) truco(false);
	pensar();
	if(mazo == 0 && tur == 2){
		aux((mano == 1) ? 6 : (mano == 2) ? 23 : (mano == 3) ? 40 : 40, 20); printf("PENSANDO...");
		Sleep(vpensar);
		aux((mano == 1) ? 6 : (mano == 2) ? 23 : (mano == 3) ? 40 : 40, 20); printf("           ");
		ANIM();
		mesa[mano  + 2][0] = nums[mselec][1];
		mesa[mano + 2][1] = palos[mselec][1];
		cartas(2);
	}mazo = 0;
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
	//if(ret) COO2();
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
			aux(1 + suma, 5 + sumaY); printf("%s", (p == 0) ? "          E" : (p == 1) ? " BBB"        :                              (p == 2) ? "    OOOOOO":"");
			aux(1 + suma, 6 + sumaY); printf("%s", (p == 0) ? "         EE" : (p == 1) ? "  BBBB"      : (p == 3) ? "CCCCCCCCCCCCCC": (p == 2) ? "  OOO    OOO":"");
			aux(1 + suma, 7 + sumaY); printf("%s", (p == 0) ? "        EEE" : (p == 1) ? "  BBBBB"     : (p == 3) ? "CCC        CCC": (p == 2) ? " OOO      OOO":"");
			aux(1 + suma, 8 + sumaY); printf("%s", (p == 0) ? "       EEEE" : (p == 1) ? "   BBBBB"    : (p == 3) ? "CCC        CCC": (p == 2) ? "OO    OO    OO":"");
			aux(1 + suma, 9 + sumaY); printf("%s", (p == 0) ? " EE   EEEE"  : (p == 1) ? "   BBBBBB"   : (p == 3) ? " CCC      CCC" : (p == 2) ? "OO   O  O   OO":"");
			aux(1 + suma, 10 + sumaY); printf("%s",(p == 0) ? "  EEEEEEE"   : (p == 1) ? "    BBBBB"   : (p == 3) ? "  CCCCCCCCCC"  : (p == 2) ? "OO    OO    OO":"");
			aux(1 + suma, 11 + sumaY); printf("%s",(p == 0) ? "    EEEEEEE" : (p == 1) ? "    BBBBBB"  : (p == 3) ? "     CCCC"     : (p == 2) ? " OOO      OOO":"");
			aux(1 + suma, 12 + sumaY); printf("%s",(p == 0) ? "   EEEE   EE": (p == 1) ? "     BBBBBB" : (p == 3) ? "    CCCCCC"    : (p == 2) ? "  OOO    OOO":"");
			aux(1 + suma, 13 + sumaY); printf("%s",(p == 0) ? "  EEEE"      : (p == 1) ? "     BBBBBBB": (p == 3) ? " CCCCCCCCCCCC ": (p == 2) ? "    OOOOOO":"");
			aux(1 + suma, 14 + sumaY); printf("%s",(p == 0) ? " EEEE"       : (p == 1) ? "      BBBBBB": (p == 3) ? "CCCCCCCCCCCCCC":"");
												//</Esto dibuja el palo de la carta>
		}
	}
												//<Esto muestra los controles>
	if(MM == 1){
		env_fl(1);
		aux(1, 18);  printf("ESC: al mazo				%s", (mesa[0][0] == vec_num && !flor && !env_sum) ? "E: envido" : "");
		aux(13, 19); printf("				%s", (mesa[0][0] == vec_num && !flor && !env_sum) ? "R: real envido" : "");
		aux(13, 20); printf("				%s", (mesa[0][0] == vec_num && !flor && !env_sum) ? "F: falta envido" : "");
		aux(1, 20);  printf("FLECHAS: seleccionar carta");
		aux(1, 22);  printf("ENTER: jugar");
		aux(1, 24);  printf("%s %s", (cantos < 4 && canto != 1) ?
			"ESPACIO:" : "        ", (canto != 1) ? (cantos == 1) ? "truco":
			(cantos == 2) ? "retruco" : (cantos == 3) ? "vale cuatro" : "           " : "           ");
		aux(40, 24); printf("%s", (flor && !env_sum) ? "F: FLOR" : "");
	}
	if(tur == 1){
		DTT();
	}
}
void DTT(){
	int s = mU + mM;
	bool mostQ;//MOSTRAR "QUIERO".
	if(resp == 1 && most == 1){//LA VARIABLE 'mazo' ES VÁLIDA PARA EL JUG. Y LA MÁQ.
		comment_clean();
		if(!NQ){
			if(cantos > 1){
				aux(3, 37);
				printf((s < 3) ? "Estamos en " : "Est%cbamos en ", 160);
				printf((cantos == 2) ? "TRUCO." : (cantos == 3) ? "RETRUCO." : "VALE CUATRO.");
			}
		}else{
			aux(3, 37);
			printf("Fue %s no querido.", (cantos == 1) ? "TRUCO" : (cantos == 2) ? "RETRUCO" : "VALE CUATRO");
		}
	}else comment_clean();
	if(s >= 3){
		pU += (mU > mM) ? cantos : 0;
		pM += (mU < mM) ? cantos : 0;
		(mU > mM) ? Beep(126, 375) : Beep(100, 375);
		mU = 0; mM = 0; selec = 1; mano = 1, mazo = 0;
		p1 = 0; p2 = 0; p3 = 0; em = 0, prim = 0; NQ = false;
		tantos = 0;
		env_cont = 0;
		glob_niv = 0;
		env_sum = false;
		GT = 0;
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
		llamar = 1;
		if(pU >= 15) GP(1);
		if(pM >= 15) GP(2);
		MB_mesa(1);
		mezcla();
	}
	if(resp == 1) {(tur == 1) ? system("color F0") : system("color B2");}
	else{(canto == 2) ? system("color F0") : system("color B2");}
	dib = (not_env) ? 0 : dib;
	if(llamar == 0 && not_env){
		dib = (tur == 1) ? 1 : 0;
		dib = (resp == 0 && most == 0) ? cantos : dib;
	}most = (most == 0) ? 1 : most;
	not_env = true;
	borrar();
	mostQ = (dib > 4 && maq_env) ? true : false;
	mostQ = (resp_en) ? true : mostQ;
	if(querido) system("color B2");
	if(maq_env) system("color F0");
	env_fl(1);
	//aux(3, 30); printf("mU: %d, mM: %d", mU, mM);
	aux(3, 31); printf("%s", (dib == 1) ? "LLLLLLLL FF   FF    CCCCCCCC LL   LL FFFFF   CC   CC  LLLL" : (dib == 2) ? "LLLLLLLL FFFFF   CC   CC  LLLLL  FFFF" : (dib == 3) ? "LLLLL   FFFFFF CCCCCCCC LLLLL   FF   FF  CCCCC  LLLL" :  (dib == 4) ? "LL      LL   F     CC    LLLLLL      FFFFF CC   CC     L    FFFFFFFF CCCCC    LLLLL"  : (dib == 5) ? "LLLLLL FF   FF CC      CC LL FFF     CCCCC"  : (dib == 6) ? "CCCCC   LLLLLL     F     CC       LLLLLL FF   FF CC      CC LL FFF     CCCCC"  : (dib == 7) ? "FFFFF  C     LL  FFFFFFFF  C      LLLLLL FF   FF CC      CC LL FFF     CCCCC" : (dib == 8) ? "LLLLLLL  FF        CCCCC   LLLLL":"");
	aux(3, 32); printf("%s", (dib == 1) ? "   LL    FF   FF       CC    LL   LL FF  FF  CCC  CC LL  LL" :(dib == 2) ? "   LL    FF  FF  CC   CC LL     FF  FF" :(dib == 3) ? "LL  LL  FF        CC    LL  LL  FF   FF CC     LL  LL" : (dib == 4) ? " LL    LL   FFF    CC    LL         FF     CC   CC    LLL      FF    CC  CC  LL   LL" : (dib == 5) ? "LL     FFF  FF  CC    CC  LL FF FF  CC   CC" : (dib == 6) ? "CC  CC  LL        FFF    CC       LL     FFF  FF  CC    CC  LL FF FF  CC   CC" : (dib == 7) ? "FF    CCC    LL     FF    CCC     LL     FFF  FF  CC    CC  LL FF FF  CC   CC": (dib == 8) ? "LL       FF       CC   CC  LL  LL":"");
	aux(3, 33); printf("%s", (dib == 1) ? "   LL    FF   FF       CC    LL   LL FFFF    CC C CC LL  LL" :(dib == 2) ? "   LL    FFFF    CC   CC LL     FF  FF" :(dib == 3) ? "LLLL    FFFF      CC    LLLL    FF   FF CC     LL  LL" : (dib == 4) ? "  LL  LL   FF FF   CC    LLLL       FF     CC   CC   LL LL     FF    CCCC    LL   LL" : (dib == 5) ? "LLLL   FF F FF   CC  CC   LL FF  FF CC   CC" : (dib == 6) ? "CCCC    LLLL     FF FF   CC       LLLL   FF F FF   CC  CC   LL FF  FF CC   CC" : (dib == 7) ? "FFFF CC CC   LL     FF   CC CC    LLLL   FF F FF   CC  CC   LL FF  FF CC   CC": (dib == 8) ? "LLLLL    FF       CC   CC  LLLL":"");
	aux(3, 34); printf("%s", (dib == 1) ? "   LL    FF   FF       CC    LL   LL FF  FF  CC  CCC LL  LL" :(dib == 2) ? "   LL    FF  FF  CC   CC LL     FF  FF" :(dib == 3) ? "LL  LL  FF        CC    LL  LL  FF   FF CC     LL  LL" : (dib == 4) ? "   LLLL   FFFFFFF  CC    LL         FF     CC   CC  LLLLLLL    FF    CC  CC  LL   LL" : (dib == 5) ? "LL     FF  FFF    CCCC    LL FF FF  CC   CC" : (dib == 6) ? "CC  CC  LL      FFFFFFF  CC       LL     FF  FFF    CCCC    LL FF FF  CC   CC" : (dib == 7) ? "FF  CCCCCCC  LL     FF  CCCCCCC   LL     FF  FFF    CCCC    LL FF FF  CC   CC": (dib == 8) ? "LL       FF       CC   CC  LL  LL":"");
	aux(3, 35); printf("%s", (dib == 1) ? "   LL     FFFFF        CC     LLLLL  FF   FF CC   CC  LLLL" : (dib == 2) ? "   LL    FF   FF  CCCCC   LLLLL  FFFF" : (dib == 3) ? "LL   LL FFFFFF    CC    LL   LL  FFFFF   CCCCC  LLLL" :  (dib == 4) ? "    LL   FF     FF CCCCC LLLLLL      FFFFF  CCCCC  LL     LL   FF    CC   CC  LLLLL"  : (dib == 5) ? "LLLLLL FF   FF     CC     LL FFF     CCCCC"  : (dib == 6) ? "CC   CC LLLLLL FF     FF CCCCC    LLLLLL FF   FF     CC     LL FFF     CCCCC"  : (dib == 7) ? "FF CC     CC LLLLL  FF CC     CC  LLLLLL FF   FF     CC     LL FFF     CCCCC" : (dib == 8) ? "LL       FFFFFFF   CCCCC   LL   LL":"");
	if(mostQ){
		comment_clean();
		if(dib_resp){
			if(!flor){
				if(!querido){
					aux(1, 37); if(env_disp(1)) printf("E: envido.");
					aux(14, 37); if(env_disp(2)) printf("R: real envido.");
					aux(32, 37); if(env_disp(3)) printf("F: falta envido.");
				}else{
					comment_clean();
				}
				aux(50, 37);
				printf("%suiero, %d%s", (!querido) ? "ENTER: q" : "Q", env_fl(1), (querido) ? "!" : ".");
			}
			else{
				aux(48, 37); printf("%s%s", (!querido) ? "ESPACIO: f" : "F", (!querido) ? "lor." : "LOR!");
			}
		}else dib_resp = false;
	}
	if(mostQ && !resp_en){ aux(71, 37); printf("ESCAPE: no quiero.");}
	resp_en = false;
	maq_env = (maq_env) ? false : false;
	querido = false;
	if(dib == 1) system("color F0");
	if(llamar == 1){
		llamar = 0;
		if(tur == 2){tab = 2; cartas(2); jugar_maquina();}else{tab = 1; cartas(1);}
	}
}
void GP(int action){
	int cont = 5, slTm = 50;
	char gpCar;
	system("cls");
	if(action == 1){
		system("color F2");
		if(cont == 5){ aux(10, 1); printf(" LLLLLL      FFF      CC   CC      LLL       FFFFF  CCCCCCCC  LLLLLLL"); cont--; Sleep(slTm);}
		if(cont == 4){ aux(10, 2); printf("LL          FF FF     CCC  CC     LL LL     FF         CC     LL     "); cont--; Sleep(slTm);}
		if(cont == 3){ aux(10, 3); printf("LL  LL     FFFFFFF    CC C CC    LLLLLLL     FFFF      CC     LLLLL  "); cont--; Sleep(slTm);}
		if(cont == 2){ aux(10, 4); printf("LL   LL   FF     FF   CC  CCC   LL     LL       FF     CC     LL     "); cont--; Sleep(slTm);}
		if(cont == 1){ aux(10, 5); printf(" LLLLL   FF       FF  CC   CC  LL       LL  FFFFF      CC     LLLLLLL   (:"); cont--; Sleep(slTm);}
	}else{
		system("color F4");
		if(cont == 5){ aux(12, 1); printf("LLLLL   FFFFF  CCCCC   LLLLL   FF   CCCCC  LLLLLLLL  FFFFF"); cont--; Sleep(slTm);}
		if(cont == 4){ aux(12, 2); printf("LL  LL  FF     CC  CC  LL  LL  FF  CC         LL     FF"); cont--; Sleep(slTm);}
		if(cont == 3){ aux(12, 3); printf("LLLLL   FFF    CCCC    LL  LL  FF   CCCC      LL     FFF"); cont--; Sleep(slTm);}
		if(cont == 2){ aux(12, 4); printf("LL      FF     CC  CC  LL  LL  FF      CC     LL     FF"); cont--; Sleep(slTm);}
		if(cont == 1){ aux(12, 5); printf("LL      FFFFF  CC   CC LLLLL   FF  CCCCC      LL     FFFFF   ):"); cont--; Sleep(slTm);}
	}
	aux(30, 30); printf("Presione M para ir al men%c", 163);
	gpCar = 0;
	while(gpCar != 'M') gpCar = toupper(getch());
	main();
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
	for(int i = 0; i < 4; i++){CE[i] = 0;}
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
					___Validar los cantos.
					___Mostrar los cantos.
					___Hacer que en el turno de la máquina SOLO se pueda ver la mesa de juego.
					___Usar distintos colores para diferenciar el turno del jugador y de la máquina.
					___Mostrar animación de mezclar al momento de finalizar la mano y al de tirar una carta.
					___Hacer vector que guarde los valores de las cartas en mesa.
					___Reproducir sonidos al ejecutar acciones.
					___Mostrar y validar puntajes.
	SITUACIONES A CORREGIR:
El contrincante solo canta truco en la tercera mano.
Cuando las 2 primeras son pardas, gana el que es mano.
10 de oro mata a 2 de espada.
Aparece opción de envido después de real envido.*/

