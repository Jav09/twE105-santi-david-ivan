#include<stdio.h>
void dificultad(int *hb, int *ab, int *cb, int *df){
	int elige;
	printf("Elija la dificultad:\n(1)No me hagas danho\n(2)Me gustan los retos\n(3)Soy un Guerrero\n");
	scanf("%i", &elige);
	
	//3 opciones de dificultad, se usan punteros para modificar las estad�sticas.

	switch(elige){
		case 1:
			printf("Buena eleccion, si tienes menos de 10 anhos.\n");
			*hb = 100;
			*ab = 20;
			*cb = 20;
			*df = 1;
			break;

		case 2:
			printf("Espero tu victoria valiente.\n");
			*hb = 500;
			*ab = 30;
			*cb = 30;
			break;

		case 3:
			printf("Ataca Guerro!!!\n");
			*hb = 1000;
			*ab = 40;
			*cb = 40;
			*df = 3;
			break;
			
		default:
			printf("Jugaras en la dificultad normal, si deseas cambiar esta opcion elige correctamente.\n");
	}
	system("pause");
	system("cls");
}
