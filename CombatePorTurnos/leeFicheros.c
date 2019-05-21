#include<stdio.h>
void leeFichero(char nombreFichero[150]){
	
	FILE *pf;
	char texto;
	
	printf("\n");
	
	pf = fopen(nombreFichero,"r");
	
	while((texto = fgetc(pf)) != EOF)
	{
		printf("%c",texto);
	}
    
    fclose(pf);
    
    printf("\n\n");
}
