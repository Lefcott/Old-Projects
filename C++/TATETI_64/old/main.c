
#include <stdio.h>
#include <conio.h>


int tic [3][3]={'1','2','3','4','5','6','7','8','9'},i,j,ta,ta1,ta2,ta3,ta4,ta5,ta6,ta7,a,b;
      char op,tateti,valor,jugador,valor2;
                   
	int te();   
	int c();
                      
      main()    
{
      
      printf("\n");
      do{
          system("cls");
            
       
    printf ("                                                    JHON F. KENNEDY\n\n\n");
    printf("                      ********************\n");
    printf("                      *Juego del TA TE TI*\n");
    printf("                      ********************\n\n\n");
 	printf("							Aguante INDEPENDIENTE (no mentira)           \n     ");
 	printf("			Juego hecho por Penelas, Ariel	\n \n		");
 	
        
for(i=0;i<3;i++) 
               {
                      
                      printf("\n");
                       
                      for(j=0;j<3;j++){
                               if(tic[i][j]==1)
                                printf("X|");
                                
                                 else if(tic[i][j]==0)
                                printf("O|");
                                
                                else
                                printf("%c|",tic[i][j]);
                                }
                                
                                
                              printf("\n------------");
                              printf("\n");
                              
                              
                                }
                if(jugador==1)
                {
                              printf("\n");
                              
               printf("\n jugador X>");
                c(jugador);
                te();
                             
                             jugador=0;
                             }
                                             
                     else if (jugador==0)
                {
                            printf("\n");
                            printf("\n jugador O>");
                            c(jugador);
                             jugador=1;
                             te();
                             }                        
                }
                
                
                  while(tateti!=1);
                      printf(" gano %c \n",op);

      char op2 = getch();
      
      }

te()
{
               
                 ta=tic[0][0]+tic[0][1]+tic[0][2];
                 ta1=tic[1][0]+tic[1][1]+tic[1][2];
                 ta2=tic[2][0]+tic[2][1]+tic[2][2];
                
                  ta3=tic[0][0]+tic[1][0]+tic[2][0];
                  ta4=tic[0][0]+tic[1][1]+tic[2][1];
                  ta5=tic[0][2]+tic[1][2]+tic[2][2];
                  ta6=tic[0][0]+tic[1][1]+tic[2][2];
                  ta7=tic[2][0]+tic[1][1]+tic[0][2];
                  
                  if(ta==0 || ta1==0 || ta2==0 || ta3==0 || ta4==0 || ta5==0 || ta6==0 ||ta7==0)
                                {
                                tateti=1;
                                op='O';
                                     }
                                     
                              if(ta==3 || ta1==3 || ta2==3 || ta3==3 || ta4==3 || ta5==3 || ta6==3||ta7==3)
                                {
                                tateti=1;
                                op='O';
                                     
                                     }
                     return;       
                         
                      main();
                      
                      
                      }
 c()
 {
             valor = getch();
              if(valor=='1')
                tic[0][0]=jugador;
                
                else if(valor=='2')
                tic[0][1]=jugador;
                
                else if(valor=='3')
                tic[0][2]=jugador;
                
                else if(valor=='4')
                tic[1][0]=jugador;
                
                else if(valor=='5')
                tic[1][1]=jugador;
                
                else if(valor=='6')
                tic[1][2]=jugador;
                
                else if(valor=='7')
                tic[2][0]=jugador;
                
                 else if(valor=='8')
                tic[2][1]=jugador;
                
               else  if(valor=='9')
                tic[2][2]=jugador;
                return;
                
                      } 

