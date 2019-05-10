#include<stdio.h>
#include"jugador.h"
#include"enemigo.h"
//#include<time.h>
int partida(int hpj, int ataquej, int curacionj, int defensaj, int evasionj, int hpb, int ataqueb, int curacionb, int dif)
{
int accion, mod, ayuda;

 srand(time(NULL));
	
	system("cls");
	
	switch(dif){
		case 1:
			printf("Estas jugando en la dificultad facil 'No me hagas danho'.\n");
			break;
		case 2:
			printf("Estas jugando en la dificultad normal 'Me gustan los retos'.\n");
			break;
		case 3:
			printf("Estas jugando en la dificultad dificil 'Soy un Guerrero'.\n");
	}
	
	system("pause");
	system("cls");
	
	do{
    	do{
    		printf("SALUD JUGADOR: %i                 SALUD ENEMIGO: %i\n\n", hpj, hpb);
    		printf("TURNO DEL JUGADOR:\n");
			printf("(1)Ataque\n(2)Curacion\n(3)Modificadores\n(4)Estadisticas\n(5)Rendirse\n");
    		scanf("%i", &accion);

    		if(accion == 4){//INFORMACIÓN
    		    printf("TU:\nSALUD: %i\nATAQUE: %i\nCURACION: %i\nEVASION: %i\nDEFENSA: %i\n\nENEMIGO:\nSALUD: %i\nATAQUE: %i\nCURACION: %i\n\n", hpj, ataquej, curacionj, evasionj, defensaj, hpb, ataqueb, curacionb);
    		    system("pause");
    		    printf("\n");
    		    }

		}while(accion == 4);

    	mod = 0;
    	switch(accion){

    		case 1://ATAQUE
    			hpb = ataque(hpb, ataquej);
			    printf("El enemigo tiene %i puntos de salud.\n", hpb);
			    break;

			case 2://CURACIÓN
				hpj = curacion(hpj, curacionj);
			    printf("Tienes %i puntos de salud.\n", hpj);
			    break;

			case 3://MODIFICADORES
				printf("(1)Aumento de Ataque\n(2)Aumento de Curacion\n(3)Aumento de Evasion\n(4)Aumento de Defensa\n");
    		    scanf("%i", &mod);
    		    break;

    		case 5://RENDIRSE
    		    printf("No me hagas mas danho porfavor!\n");
    		    hpj = 0;
    		    break;
    		
			default:
				printf("Pierdes el turno, elige bien la proxima vez.\n");
				break;
		}

		switch(mod){

			case 1://AUMENTO DE ATAQUE DEL JUGADOR
				ataquej = aumentoataque(ataquej);
		        if(ataquej > 60){
		        	ataquej = 60;
		        	printf("El ataque maximo es 60.\n");
		    	}
				printf("\nTienes %i puntos de ataque, haras mas danho con tus proximos golpes.\n", ataquej);
		        break;

		    case 2://AUMENTO DE CURACIÓN DEL JUGADOR
		    	curacionj = aumentocuracion(curacionj);
		    	if(curacionj > 60){
		        	curacionj = 60;
		        	printf("La curacion maxima es 60.\n");
		    	}
		        printf("\nTienes %i puntos de curacion, recuperaras mas vida la proxima vez que te cures.\n", curacionj);
		        break;

		    case 3://AUMENTO DE EVASION DEL JUGADOR
		    	evasionj = aumentoevasion(evasionj);
		    	if(evasionj > 60){
		        	evasionj = 60;
		        	printf("La evasion maxima es 60.\n");
		    	}
		    	printf("\nTienes %i puntos de evasion, la probabilidad de que esquives golpes aumenta.\n", evasionj);
		        break;

		    case 4://AUMENTO DE DEFENSA DEL JUGADOR
		    	defensaj = aumentodefensa(defensaj);
		    	if(defensaj > 60){
		        	defensaj = 60;
		        	printf("La defensa maxima es 60.\n");
		    	}
		    	printf("\nTienes %i puntos de defensa, bloqueas mas danho del enemigo.\n", defensaj);
		        break;
		}    	


	//TURNO DEL ENEMIGO
		accion=0;
		printf("\n\nTURNO DEL ENEMIGO:\n");
		accion = rand() % 3 + 1;
		system("pause");

		switch(accion){

			case 1://ATAQUE
				hpj = ataqueenemigo(hpj, ataqueb, evasionj, defensaj);
			    printf("\nTienes %i puntos de salud.\n", hpj);
			    break;

			case 2://CURACIÓN
				hpb = curacionenemigo(hpb, curacionb);
			    printf("\nEl Enemigo tiene %i puntos de salud.\n", hpb);
			    break;

			case 3://MODIFICADORES
				if(ataqueb <= 0)
				accion = 4;
				if(curacionb <= 0)
				accion = 5;
				if(ataquej <= 0)
				accion = rand() % 2 + 4;
				if(curacionj <= 0)
				accion = rand() % 2 + 4;
				if(ataqueb==60)
				accion = rand() % 3 + 5;
				if(curacionb==60){
					ayuda = rand() % 2 + 1;
					switch(ayuda){
						case 1:
						accion = 4;
						break;
						case 2:
						accion = rand() % 3 + 5;
						break;
					}
				}
				else
				accion = rand() % 4 + 4;
				

			case 4://AUMENTO ATAQUE
				ataqueb = aumentoataqueb(ataqueb);
				if(ataquej > 60)
		    	ataquej = 60;
			    printf("\nEl enemigo tiene %i puntos de ataque, hara mas danho con sus proximos golpes.\n", ataqueb);
				break;

			case 5://AUMENTO CURACIÓN
				curacionb = aumentocuracionb(curacionb);
				if(curacionj > 60)
		    	curacionj = 60;
			    printf("\nEl enemigo tiene %i puntos de curacion, recuperara mas vida la proxima vez que se cure.\n", curacionb);
				break;

			case 6://REDUCCIÓN ATAQUE DEL JUGADOR
				ataquej = reduccionataqueb(ataquej);
				if(ataquej < 0)
		    	ataquej = 0;
			    printf("\nTienes %i puntos de ataque, haras menos danho con tus proximos golpes.\n", ataquej);
				break;

			case 7://REDUCCIÓN CURACIÓN DEL JUGADOR
				curacionj = reduccioncuracionb(curacionj);
				if(curacionj < 0)
		    	curacionj = 0;
			    printf("\nTienes %i puntos de curacion, tu curacion se ha visto reducida.\n", curacionj);
				break;
		}
		
		system("pause");
		system("cls");

	}while(hpj > 0 && hpb > 0);

return 0;
}
