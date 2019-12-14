#include <iostream>
#include <conio.h>
bool E;int D,S,ST,C2,C;char car;
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
	printf("Escriba n%cmeros decimales para convertir a binario.\n",163);
	while(!E){S=0;C=0;ST=0;
		scanf("%d",&D);printf("  :");car = 0;
		while(S<D){S=P(2,C);C++;}
		while(S>0){C2=ST+S;ST+=(C2<=D)?S:0;printf("%d",(C2<=D)?1:0);S/=2;}
		printf("\nESC: salir, B: borrar valores, ENTER: repetir.\n");
		while(car!=13&&car!=66&&car!=98&&car!=27)car=getch();
		E=(car==27)?true:false;
		if(car==66||car==98)system("cls");
		if(car!=27)printf("%sEscriba n%cmeros decimales para convertir a binario.\n",(car==13)?"\n":"",163);
	}
	return 0;
}
