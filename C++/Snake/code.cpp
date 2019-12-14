#include <iostream>
#include <conio.h>
#include <windows.h>
#define LON 1250
int X[LON], Y[LON], dir = 0;
char tec;
void aux(int x, int y), vec_form(), jugar(), mover();
int main(){
	system("MODE CON COLS=50 LINES=25");
	vec_form();
	jugar();
	return 0;
}
void jugar(){
	tec = 0;
	while(true){
		if(kbhit()){
			tec = getch();
			dir = (tec == 77) ? 0 : (tec == 72) ? 90 : (tec == 75) ? 180 : (tec == 80) ? 270 : dir;
		}
		mover();
		Sleep(500);
	}
}
void mover(){
	for(int i = LON - 1; i > 0; i--){
		aux(X[i], Y[i]); printf(" ");
		if(X[i] != -5 && X[i + 1] != -5 && Y[i] != -5 && Y[i + 1] != -5){
			X[i + 1] = X[i];
			Y[i + 1] = Y[i];
		}
	}
	X[0] += (dir == 0) ? 1 : (dir == 180) ? -1 : 0;
	Y[0] += (dir == 270) ? 1 : (dir == 90) ? -1 : 0;
	for(int i = 0; i < LON; i ++){
		if(X[i] != -5 && Y[i] != -5){
			aux(X[i], Y[i]);
			printf("L");
		}
	}
}
void vec_form(){
	for(int i = 0; i < LON; i++){
		X[i] = -5;
		Y[i] = -5;
	}
	X[0] = 27; Y[0] = 12;
	X[1] = 26; Y[1] = 12;
	X[2] = 25; Y[2] = 12;
}
void aux(int x, int y){
	HANDLE oCur;
	oCur = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posicion;
	posicion.X = x;
	posicion.Y = y;
	SetConsoleCursorPosition(oCur, posicion);
}
