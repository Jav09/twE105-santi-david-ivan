#include<stdio.h>
#include <stdlib.h>
#include"dificultad.h"
#include"stats.h"
#include"partida.h"
#include"leeFicheros.h"

//Este es el menú principal del juego, a partir de aqui el resto se completa con funciones.

int main(){
	
	int elige, dif=2, hpj=500, ataquej=10, curacionj=10, defensaj=10, evasionj=10, hpb=500, ataqueb=30, curacionb=30;
	leeFichero("hinstrucciones.txt");
	system("pause");
	system("cls");

	do{
		printf("MENU:\n(1)Empezar el Juego\n(2)Dificultad\n(3)Salir\n");
	    scanf("%i", &elige);
		
		//3 opciones, empezar el juego, elegir la dificultad o salir.
		
	    switch(elige){
		case 1:
			leeFichero("historia.txt");
			stats(&hpj, &ataquej, &curacionj, &evasionj, &defensaj); //Funcion de las estadisticas del jugador con punteros. (stats.c)
			partida(hpj, ataquej, curacionj, defensaj, evasionj, hpb, ataqueb, curacionb, dif); //Funcion del juego en si. (partida.c)
		    break;

		case 2:
			leeFichero("historia_dif.txt");
			dificultad(&hpb, &ataqueb, &curacionb, &dif); //Funcion para elegir la dificultad. (dificultad.c)
			break;

		case 3:
			exit(EXIT_SUCCESS);
			break;
        }
        system("cls");
	}while(elige != 1);	
return 0;	
}

