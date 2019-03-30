#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    
	int hpj=100, hpb=1000, accion, mod, ataquej=5, curacionj=5, ataqueb=5, curacionb=5;
	
	//FUNCIONES DEL JUGADOR
    int ataque(int hpb, int ataquej), curacion(int hpj, int curacionj), aumentoataque(int ataquej), aumentocuracion(int curacionj), reduccionataque(int ataqueb), reduccioncuracion(int curacionb);
    //FUNCIONES DEL ENEMIGO
	int ataqueenemigo(int hpj, int ataqueb), curacionenemigo(int hpb, int curacionb), aumentoataqueb(int ataqueb), aumentocuracionb(int curacionb), reduccionataqueb(int ataquej), reduccioncuracionb(int curacionj);

    do{
    	do{
    		printf("TURNO DEL JUGADOR:\n");
			printf("(1)Ataque\n(2)Curacion\n(3)Modificadores\n(4)Informacion\n");
    		scanf("%i", &accion);
    		
    		if(accion == 4){//INFORMACIÓN
    		    printf("TU:\nSALUD: %i\nCURACION: %i\nPODER: %i\n\nENEMIGO:\nSALUD: %i\nCURACION: %i\nPODER: %i\n\n", hpj, curacionj, ataquej, hpb, curacionb, ataqueb);
    		    system("pause");
    		    }
    		    
		}while(accion == 4);
    	
		if(accion == 3){
    		printf("(1)Aumento de Ataque\n(2)Aumento de Curacion\n(3)Reduccion del Ataque enemigo\n(4)Reduccion de la Curacion del enemigo\n");
    		scanf("%i", &mod);
		}
		
		if(accion == 1){//ATAQUE
			hpb = ataque(hpb, ataquej);
			printf("\nEl enemigo tiene %i puntos de salud.\n", hpb);
		}
		
		if(accion == 2){//CURACIÓN
			hpj = curacion(hpj, curacionj);
			printf("\nTienes %i puntos de salud.\n", hpj);
			
		}
		
		if(mod == 1 && accion ==3){//AUMENTO DE ATAQUE
		    ataquej = aumentoataque(ataquej);
		    printf("\nTienes %i puntos de ataque, haras mas danho con tus proximos golpes.\n", ataquej);
		}
		
		if(mod == 2 && accion ==3){//AUMENTO DE CURACIÓN
		    curacionj = aumentocuracion(curacionj);
		    printf("\nTienes %i puntos de curacion, recuperaras mas vida la proxima vez que te cures.\n", curacionj);
		}
		
		if(mod == 3 && accion ==3){//REDUCCIÓN DE ATAQUE
		    ataqueb = reduccionataque(ataqueb);
		    printf("\nEl Enemigo tiene %i puntos de ataque, hara menos danho con sus proximos golpes.\n", ataqueb);
	    }
	    
	    if(mod == 4 && accion ==3){//REDUCCIÓN DE CURACIÓN
		    curacionb = reduccioncuracion(curacionb);
		    printf("\nEl Enemigo tiene %i puntos de curacion, su curacion se ha visto reducida.\n", curacionb);
		}
		
	//TURNO DEL ENEMIGO
		printf("\n\nTURNO DEL ENEMIGO:\n");
		accion = rand() % 3 + 1;
		
		if(accion == 1){//ATAQUE ENEMIGO
			hpj = ataqueenemigo(hpj, ataqueb);
			printf("\nTienes %i puntos de salud.\n", hpj);
		}
		
		if(accion == 2){//CURACIÓN ENEMIGO
			hpb = curacionenemigo(hpb, curacionb);
			printf("\nEl Enemigo tiene %i puntos de salud.\n", hpb);
		}
		
		if(accion == 3)
		    accion = rand() % 4 + 4;
		    
		if(accion == 4){//AUMENTO ATAQUE ENEMIGO
			ataqueb = aumentoataqueb(ataqueb);
			printf("\nEl enemigo tiene %i puntos de ataque, hara mas danho con sus proximos golpes.\n", ataqueb);
		}
		
		if(accion == 5){//AUMENTO CURACIÓN ENEMIGO
			curacionb = aumentocuracionb(curacionb);
			printf("\nEl enemigo tiene %i puntos de curacion, recuperara mas vida la proxima vez que se cure.\n", curacionb);
		}
		
		if(accion == 6){//REDUCCION DE ATAQUE
			ataquej = reduccionataqueb(ataquej);
			printf("\nTienes %i puntos de ataque, haras menos danho con tus proximos golpes.\n", ataquej);
		}
		
		if(accion == 7){//REDUCCION DE CURACIÓN
			curacionj = reduccioncuracionb(curacionj);
			printf("\nTienes %i puntos de curacion, tu curacion se ha visto reducida.\n", curacionj);
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
