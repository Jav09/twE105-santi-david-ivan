#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    
	int hpj=100, hpb=1000, accion, mod, ataquej=5, curacionj=5, ataqueb=5, curacionb=5;
	//FUNCIONES DEL JUGADOR
    int ataque(int hpb, int ataquej), curacion(int hpj, int curacionj), aumentoataque(int ataquej), aumentocuracion(int curacionj), reduccionataque(int ataqueb), reduccioncuracion(int curacionb);
    //FUNCIONES DEL ENEMIGO
	int ataqueenemigo(int hpj, int ataqueb), curacionenemigo(int hpb, int curacionb), aumentoataqueb(int ataqueb), aumentocuracionb(int curacionb), reduccionataqueb(int ataquej), reduccioncuracionb(int curacionj);

    srand(time(NULL));
	
	do{
    	do{
    		printf("TURNO DEL JUGADOR:\n");
			printf("(1)Ataque\n(2)Curacion\n(3)Modificadores\n(4)Informacion\n(5)Salir\n");
    		scanf("%i", &accion);
    		
    		if(accion == 4){//INFORMACIÓN
    		    printf("TU:\nSALUD: %i\nCURACION: %i\nPODER: %i\n\nENEMIGO:\nSALUD: %i\nCURACION: %i\nPODER: %i\n\n", hpj, curacionj, ataquej, hpb, curacionb, ataqueb);
    		    system("pause");
    		    printf("\n");
    		    }
    		    
		}while(accion == 4);
    	
    	switch(accion){
    		
    		case 1://ATAQUE
    			hpb = ataque(hpb, ataquej);
			    printf("\nEl enemigo tiene %i puntos de salud.\n", hpb);
			    break;
			    
			case 2://CURACIÓN
				hpj = curacion(hpj, curacionj);
			    printf("\nTienes %i puntos de salud.\n", hpj);
			    break;
			    
			case 3://MODIFICADORES
				printf("(1)Aumento de Ataque\n(2)Aumento de Curacion\n(3)Reduccion del Ataque enemigo\n(4)Reduccion de la Curacion del enemigo\n");
    		    scanf("%i", &mod);
    		    break;
    		    
    		case 5://salir
    		    exit(EXIT_SUCCESS);
    		    break;
		}
    	
		switch(mod){
			
			case 1://AUMENTO DE ATAQUE DEL JUGADOR
				ataquej = aumentoataque(ataquej);
		        printf("\nTienes %i puntos de ataque, haras mas danho con tus proximos golpes.\n", ataquej);
		        break;
		        
		    case 2://AUMENTO DE CURACIÓN DEL JUGADOR
		    	curacionj = aumentocuracion(curacionj);
		        printf("\nTienes %i puntos de curacion, recuperaras mas vida la proxima vez que te cures.\n", curacionj);
		        break;
		        
		    case 3://REDUCCIÓN DE ATAQUE DEL ENEMIGO
		    	ataqueb = reduccionataque(ataqueb);
		        printf("\nEl Enemigo tiene %i puntos de ataque, hara menos danho con sus proximos golpes.\n", ataqueb);
		        break;
		        
		    case 4://REDUCCIÓN DE CURACIÓN DEL ENEMIGO
		    	curacionb = reduccioncuracion(curacionb);
		        printf("\nEl Enemigo tiene %i puntos de curacion, su curacion se ha visto reducida.\n", curacionb);
		        break;
		}    	
		
		
	//TURNO DEL ENEMIGO
		printf("\n\nTURNO DEL ENEMIGO:\n");
		accion = rand() % 3 + 1;
		
		switch(accion){
			
			case 1://ATAQUE
				hpj = ataqueenemigo(hpj, ataqueb);
			    printf("\nTienes %i puntos de salud.\n", hpj);
			    break;
			
			case 2://CURACIÓN
				hpb = curacionenemigo(hpb, curacionb);
			    printf("\nEl Enemigo tiene %i puntos de salud.\n", hpb);
			    break;
			    
			case 3://MODIFICADORES
				accion = rand() % 4 + 4;
			
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
			    printf("\nTienes %i puntos de ataque, haras menos danho con tus proximos golpes.\n", ataquej);
				break;
				
			case 7://REDUCCIÓN CURACIÓN DEL ENEMIGO
				curacionj = reduccioncuracionb(curacionj);
			    printf("\nTienes %i puntos de curacion, tu curacion se ha visto reducida.\n", curacionj);
				break;
		}

		printf("\n\n");
		
	}while(hpj > 0 && hpb > 0);
	
return 0;
}




//FUNCION DE ATAQUE DEL JUGADOR
int ataque(int hpb, int ataquej){
	
	int a1, a2, a;
	
	srand(time(NULL));
	a1 = rand() % 5 + ataquej;
	a2 = rand() % 5 + ataquej;
	a = a1 + a2;
	
	printf("\nTienes %i de poder, tu ataque hace %i de danho al enemigo.\n\n", ataquej, a);
	system ("pause");
	
	return hpb = hpb - a;
}
//FUNCION DE CURACION DEL JUGADOR
int curacion(int hpj, int curacionj){
	
	int c1, c2, c;
	
	srand(time(NULL));
	c1 = rand() % 5 + curacionj;
	c2 = rand() % 5 + curacionj;
	c = c1 + c2;
	
	printf("\nTienes %i de curacion, tu salud aumenta en %i puntos.\n\n", curacionj, c);
	system ("pause");
	
	return hpj = hpj + c;
}
//FUNCION DE AUMENTO DE PODER DEL JUGADOR
int aumentoataque(int ataquej){
	
	int aa;
	
	aa = rand() % 4 + 2;

	printf("\nHas obtenido %i de poder.\n\n", aa);
	system ("pause");
	
	return ataquej += aa;
}
//FUNCION DE AUMENTO DE CURACION DEL JUGADOR
int aumentocuracion(int curacionj){
	
	int ac;
	
	ac = rand() % 4 + 2;

	printf("\nHas obtenido %i de curacion.\n\n", ac);
	system ("pause");
	
	return curacionj += ac;
}
//FUNCION DE REDUCCION DE ATAQUE DEL JUGADOR HACIA EL ENEMIGO
int reduccionataque(int ataqueb){
	
	int ra;
	
	ra = rand() % 4 + 2;

	printf("\nSe ha reducido %i de poder del enemigo.\n\n", ra);
	system ("pause");
	
	return ataqueb -= ra;
}
//FUNCION DE REDUCCION DE CURACION DEL JUGADOR HACIA EL ENEMIGO
int reduccioncuracion(int curacionb){
	
	int rc;
	
	rc = rand() % 4 + 2;

	printf("\nSe ha reducido %i de la curacion del enemigo.\n\n", rc);
	system ("pause");
	
	return curacionb -= rc;
}





//FUNCION DE ATAQUE DEL ENEMIGO
int ataqueenemigo(int hpj, int ataqueb){
	int a1, a2, a;
	
	printf("\nEl enemigo ha decidido atacarte.\n\n");
	system ("pause");
	srand(time(NULL));
	a1 = rand() % 5 + ataqueb;
	a2 = rand() % 5 + ataqueb;
	a = a1 + a2;
	
	printf("\nEl enemigo tiene %i de poder, su ataque te hace %i de danho.\n\n", ataqueb, a);
	system ("pause");
	
	return hpj = hpj - a;
}
//FUNCION DE CURACIÓN DEL ENEMIGO
int curacionenemigo(int hpb, int curacionb){
	int c1, c2, c;
	
	printf("\nEl enemigo ha decidido curarse.\n\n");
	system ("pause");
	srand(time(NULL));
	c1 = rand() % 5 + curacionb;
	c2 = rand() % 5 + curacionb;
	c = c1 + c2;
	
	printf("\nEl enemigo tiene %i de curacion, su salud aumenta en %i puntos.\n\n", curacionb, c);
	system ("pause");
	
	return hpb = hpb + c;
}

//FUNCION DE AUMENTO DE PODER DEL ENEMIGO
int aumentoataqueb(int ataqueb){
	
	int aa;
	
	printf("\nEl enemigo ha decidido aumentar su poder.\n\n");
	system ("pause");
	aa = rand() % 4 + 2;

	printf("\nEl enemigo ha obtenido %i de poder.\n\n", aa);
	system ("pause");
	
	return ataqueb += aa;
}
//FUNCION DE AUMENTO DE CURACIÓN DEL ENEMIGO
int aumentocuracionb(int curacionb){
	
	int ac;
	
	printf("\nEl enemigo ha decidido aumentar su curacion.\n\n");
	system ("pause");
	ac = rand() % 4 + 2;

	printf("\nEl enemigo ha obtenido %i de curacion.\n\n", ac);
	system ("pause");
	
	return curacionb += ac;
}
//FUNCION DE REDUCCION DE ATAQUE DEL ENEMIGO HACIA EL JUGADOR
int reduccionataqueb(int ataquej){
	
	int ra;
	
	printf("\nEl enemigo ha decidido reducir tu ataque.\n\n");
	system ("pause");
	ra = rand() % 4 + 2;

	printf("\nSe ha reducido %i de tu poder.\n\n", ra);
	system ("pause");
	
	return ataquej -= ra;
}
//FUNCION DE REDUCCION DE CURACION DEL ENEMIGO HACIA EL JUGADOR
int reduccioncuracionb(int curacionj){
	
	int rc;
	
	printf("\nEl enemigo ha decidido reducir tu curacion.\n\n");
	system ("pause");
	rc = rand() % 4 + 2;

	printf("\nSe ha reducido %i de la curacion del enemigo.\n\n", rc);
	system ("pause");
	
	return curacionj -= rc;
}
