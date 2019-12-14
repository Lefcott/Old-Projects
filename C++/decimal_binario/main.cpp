#include <iostream>
#include <conio.h>
bool E;int D,S,ST,C;char car;
int GB(){
	
}
int P(int B,int E){
	int O = B;
	for(int x=0;x<E-1;x++){
		B*=O;
	}B=(E==0)?1:B;
	return B;
}
int main(){
	printf("Escriba n%cmeros decimales para convertir a binario\nESC: salir, R: borrar todo, ENTER: convertir.\n",163);
	while(!E){S=0;C=0;ST=0;
		scanf("%d",&D);printf("%d:",D);car = 0;
		while(toupper(car)!=83&&car!=27)car=getch();
		while(S<D){S=P(2,C);C++;}printf("%d\n",S);
		while(S>0){ST+=(ST+S<=D)?S:0;printf("%d",(ST<=D)?1:0);S/=2;}
		E=(car==27)?true:false;
		if(car==83)system("cls");
	}
	return 0;
}
