#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	int elige, dif=2, hpj=100, ataquej=5, curacionj=5, defensaj=5, evasionj=5, hpb=1000, ataqueb=30, curacionb=30;
	int juego(int hpj, int ataquej, int curacionj, int defensaj, int evasionj, int hpb, int ataqueb, int curacionb, int dif);
	void stats(int *hj, int *aj, int *cj, int *ej, int *dj), dificultad(int *hb, int *ab, int *cb, int *df);

	printf("Insetar aqui introduccion e instrucciones.\n");
	system("pause");
	system("cls");

	do{
	    printf("(1)Empezar el Juego\n(2)Dificultad\n(3)Salir\n");
	    scanf("%i", &elige);

	    switch(elige){
		case 1:
			stats(&hpj, &ataquej, &curacionj, &evasionj, &defensaj);
			juego(hpj, ataquej, curacionj, defensaj, evasionj, hpb, ataqueb, curacionb, dif);
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


void stats(int *hj, int *aj, int *cj, int *ej, int *dj){
	int puntos, elige;

	printf("Es hora de elegir tus estadisticas!\nContaras con 10 puntos a repartir entre 5 cualidades de tu personaje,\nelige bien valiente pues puede que tu partida dependa de ello!\n");
	system("pause");
	system("cls");

    for(puntos = 10; puntos > 0; puntos--){

    	printf("(1)Salud = %i\n(2)Ataque = %i\n(3)Curacion = %i\n(4)Evasion = %i\n(5)Defensa = %i\n\nPuntos %i\nElija la cualidad que desea potenciar:\n", *hj, *aj, *cj, *ej, *dj, puntos);
    	scanf("%i", &elige);

    	switch(elige){
    		case 1:
    			*hj += 50;
    			break;

    		case 2:
    			*aj += 5;
    			break;

    		case 3:
    			*cj += 5;
    			break;

    		case 4:
    			*ej += 5;
    			break;

    		case 5:
    			*dj += 5;
    			break;
    		
    		default:
    			printf("Pierdes el punto, elige bien la proxima vez.\n");
    			system("pause");
    			break;
		}
		system("cls");
	}
	printf("Estas son tus estadisticas finales, podran seguir variando durante la partida,\nno olvides revisar el apartado de informacion para mantenerte al tanto!\n\n");
	printf("(1)Salud = %i\n(2)Ataque = %i\n(3)Curacion = %i\n(4)Evasion = %i\n(5)Defensa = %i\n", *hj, *aj, *cj, *ej, *dj);
system("pause");
system("cls");
}


void dificultad(int *hb, int *ab, int *cb, int *df){
	int elige;
	printf("Elija la dificultad:\n(1)No me hagas danho\n(2)Me gustan los retos\n(3)Soy un Guerrero\n");
	scanf("%i", &elige);

	switch(elige){
		case 1:
			printf("Buena eleccion, si tienes menos de 10 anhos.\n");
			*hb = 500;
			*ab = 20;
			*cb = 20;
			*df = 1;
			break;

		case 2:
			printf("Espero tu victoria valiente.\n");
			*hb = 1000;
			*ab = 30;
			*cb = 30;
			break;

		case 3:
			printf("Ataca Guerro!!!\n");
			*hb = 2000;
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


int juego(int hpj, int ataquej, int curacionj, int defensaj, int evasionj, int hpb, int ataqueb, int curacionb, int dif){

	int accion, mod;
	//FUNCIONES DEL JUGADOR
    int ataque(int hpb, int ataquej), curacion(int hpj, int curacionj), aumentoataque(int ataquej), aumentocuracion(int curacionj), aumentoevasion(int evasionj), aumentodefensa(int defensaj);
    //FUNCIONES DEL ENEMIGO
	int ataqueenemigo(int hpj, int ataqueb, int evasionj, int defensaj), curacionenemigo(int hpb, int curacionb), aumentoataqueb(int ataqueb), aumentocuracionb(int curacionb), reduccionataqueb(int ataquej), reduccioncuracionb(int curacionj);

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
		        ataquej = 60;
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
				if(ataquej > 0 && curacionj > 0)
				accion = rand() % 4 + 4;
				if(ataquej==0||curacionj==0)
				accion = rand() % 2 + 4;
				
				if(curacionj==0)

			case 4://AUMENTO ATAQUE
				ataqueb = aumentoataqueb(ataqueb);
			    printf("\nEl enemigo tiene %i puntos de ataque, hara mas danho con sus proximos golpes.\n", ataqueb);
				break;

			case 5://AUMENTO CURACIÓN
				curacionb = aumentocuracionb(curacionb);
			    printf("\nEl enemigo tiene %i puntos de curacion, recuperara mas vida la proxima vez que se cure.\n", curacionb);
				break;

			case 6://REDUCCIÓN ATAQUE DEL JUGADOR
				ataquej = reduccionataqueb(ataquej);
				if(ataquej < 0)
		    	ataquej = 0;
			    printf("\nTienes %i puntos de ataque, haras menos danho con tus proximos golpes.\n", ataquej);
				break;

			case 7://REDUCCIÓN CURACIÓN DEL ENEMIGO
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




//FUNCION DE ATAQUE DEL JUGADOR
int ataque(int hpb, int ataquej){

	int a1, a2, a;

	a1 = rand() % 5 + ataquej;
	a2 = rand() % 5 + ataquej;
	a = a1 + a2;

	printf("\nTienes %i de poder, tu ataque hace %i de danho al enemigo.\n\n", ataquej, a);

	return hpb = hpb - a;
}
//FUNCION DE CURACION DEL JUGADOR
int curacion(int hpj, int curacionj){

	int c1, c2, c;

	c1 = rand() % 5 + curacionj;
	c2 = rand() % 5 + curacionj;
	c = c1 + c2;

	printf("\nTienes %i de curacion, tu salud aumenta en %i puntos.\n\n", curacionj, c);

	return hpj = hpj + c;
}
//FUNCION DE AUMENTO DE PODER DEL JUGADOR
int aumentoataque(int ataquej){

	int aa;

	aa = rand() % 4 + 2;

	printf("\nHas obtenido %i de poder.\n\n", aa);

	return ataquej += aa;
}
//FUNCION DE AUMENTO DE CURACION DEL JUGADOR
int aumentocuracion(int curacionj){

	int ac;

	ac = rand() % 4 + 2;

	printf("\nHas obtenido %i de curacion.\n\n", ac);

	return curacionj += ac;
}
//FUNCION DE AUMENTO DE EVASIÓN DEL JUGADOR
int aumentoevasion(int evasionj){

	int ae;

	ae = rand() % 4 + 2;

	printf("\nHas obtenido %i de evasion.\n\n", ae);

	return evasionj += ae;
}
//FUNCION DE AUMENTO DE DEFENSA DEL JUGADOR
int aumentodefensa(int defensaj){

	int ad;

	ad = rand() % 4 + 2;

	printf("\nHas obtenido %i de defensa.\n\n", ad);

	return defensaj += ad;
}





//FUNCION DE ATAQUE DEL ENEMIGO
int ataqueenemigo(int hpj, int ataqueb, int evasionj, int defensaj){
	int a, n;
	float y;
	a=0;
	printf("\nEl enemigo ha decidido atacarte.\n");
	
	n = rand() % 100 + 1;
	if(n >= evasionj){
		a = rand() % 10 + ataqueb;
		printf("El enemigo tiene %i puntos de ataque, hace %i de danho.\n", ataqueb, a);
		
		a = a*(1-(defensaj/100.0));
		printf("Tienes %i puntos de defensa, su ataque hace que %i de danho traspasen tu armadura.\n", defensaj, a);
	}
	

	else
	printf("Has esquivado el ataque del enemigo, no recibes danho.\n");
	

	return hpj = hpj - a;
}
//FUNCION DE CURACIÓN DEL ENEMIGO
int curacionenemigo(int hpb, int curacionb){
	int c;

	printf("\nEl enemigo ha decidido curarse.\n");
	c = rand() % 5 + curacionb;

	printf("El enemigo tiene %i de curacion, su salud aumenta en %i puntos.\n", curacionb, c);

	return hpb = hpb + c;
}

//FUNCION DE AUMENTO DE PODER DEL ENEMIGO
int aumentoataqueb(int ataqueb){

	int aa;

	printf("\nEl enemigo ha decidido aumentar su poder.\n");
	aa = rand() % 4 + 2;

	printf("El enemigo ha obtenido %i de poder.\n", aa);

	return ataqueb += aa;
}
//FUNCION DE AUMENTO DE CURACIÓN DEL ENEMIGO
int aumentocuracionb(int curacionb){

	int ac;

	printf("\nEl enemigo ha decidido aumentar su curacion.\n");
	ac = rand() % 4 + 2;

	printf("El enemigo ha obtenido %i de curacion.\n", ac);

	return curacionb += ac;
}
//FUNCION DE REDUCCION DE ATAQUE DEL ENEMIGO HACIA EL JUGADOR
int reduccionataqueb(int ataquej){

	int ra;

	printf("\nEl enemigo ha decidido reducir tu ataque.\n");
	ra = rand() % 4 + 2;

	printf("Se ha reducido %i de tu poder.\n", ra);

	return ataquej -= ra;
}
//FUNCION DE REDUCCION DE CURACION DEL ENEMIGO HACIA EL JUGADOR
int reduccioncuracionb(int curacionj){

	int rc;

	printf("\nEl enemigo ha decidido reducir tu curacion.\n");
	rc = rand() % 4 + 2;

	printf("Se ha reducido %i de la curacion del enemigo.\n", rc);

	return curacionj -= rc;
}
