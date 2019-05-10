#include<stdio.h>
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
