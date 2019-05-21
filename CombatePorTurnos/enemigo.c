#include<stdio.h>
#include<stdlib.h>


//FUNCION DE ATAQUE DEL ENEMIGO
//Esta primera función tiene en cuenta el porcentaje de evasión del jugador, la defensa del mismo, su salud y el ataque del enemigo.
//Todo ello hace que esta función esté equilibrada a la perfección reflejando así de manera notoria las decisiones del jugador eligiendo las estadísticas.
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
