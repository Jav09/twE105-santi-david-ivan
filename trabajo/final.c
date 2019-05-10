#include<stdio.h>
//#include <time.h>
#include <stdlib.h>
#include"dificultad.h"
#include"stats.h"
#include"partida.h"
int main()
{
	int elige, dif=2, hpj=100, ataquej=10, curacionj=10, defensaj=10, evasionj=10, hpb=500, ataqueb=30, curacionb=30;
	printf("Insetar aqui introduccion e instrucciones.\n");
	system("pause");
	system("cls");

	do{
	    printf("(1)Empezar el Juego\n(2)Dificultad\n(3)Salir\n");
	    scanf("%i", &elige);

	    switch(elige){
		case 1:
			stats(&hpj, &ataquej, &curacionj, &evasionj, &defensaj);
			partida(hpj, ataquej, curacionj, defensaj, evasionj, hpb, ataqueb, curacionb, dif);
		    break;

		case 2:
			dificultad(&hpb, &ataqueb, &curacionb, &dif);
			break;

		case 3:
			exit(EXIT_SUCCESS);
			break;
        }
        system("cls");
	}while(elige != 1);	
return 0;	
}

