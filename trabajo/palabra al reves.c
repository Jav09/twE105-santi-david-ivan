#include <stdio.h>
#include <string.h>
int main ()
{
char palabra[11];
int len, i;
// Pide la palabra al usuario
printf("Escribe una palabra (m�ximo 10 letras):\n");
scanf(" %10s", palabra);
// Calcula la longitud
len = strlen(palabra);
// Empezamos por el �ltimo caracter (len - 1) y retrocedemos hasta el primero (0)
for(i = len - 1; i >= 0; i--)
printf(" %c", palabra[i]);
printf("\n");
return 0;
}
