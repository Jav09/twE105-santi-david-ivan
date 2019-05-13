#include <stdio.h>
#include <stdlib.h>

int main(){
    
	int hpj=100, hpb=1000, accion, mod, ataquej=5, curacionj=5, ataqueb=5, curacionb=5;
	
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
			    printf("Tu ataque hace %i de danho al enemigo.\n", ataquej);
			    break;
			    
			case 2://CURACIÓN
			    printf("Tu salud aumenta en %i puntos.\n", curacionj);
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
		        printf("Has obtenido x de poder.\n");
		        break;
		        
		    case 2://AUMENTO DE CURACIÓN DEL JUGADOR
		        printf("Has obtenido x de curacion.\n");
		        break;
		        
		    case 3://REDUCCIÓN DE ATAQUE DEL ENEMIGO
		        printf("Se ha reducido x de poder del enemigo.\n");
		        break;
		        
		    case 4://REDUCCIÓN DE CURACIÓN DEL ENEMIGO
		        printf("Se ha reducido x la curacion del enemigo.\n");
		        break;
		}    	
		
		
	//TURNO DEL ENEMIGO
		printf("\n\nTURNO DEL ENEMIGO:\n");
		accion = rand() % 3 + 1;
		
		switch(accion){
			
			case 1://ATAQUE
			    printf("El enemigo ha decidido atacarte, te hace %i de danho\n", ataqueb);
			    break;
			
			case 2://CURACIÓN
			    printf("El Enemigo ha decidido curarse, su salud aumenta a %i.\n", hpb);
			    break;
			    
			case 3://MODIFICADORES
				accion = rand() % 4 + 4;
			
			case 4://AUMENTO ATAQUE
			    printf("El enemigo ha decidio aumentar su ataque.\nTiene %i puntos de ataque, hara mas danho con sus proximos golpes.\n", ataqueb);
				break;
				
			case 5://AUMENTO CURACIÓN
			    printf("El enemigo ha decidido aumentar su curacion.\nTiene %i puntos de curacion, recuperara mas vida la proxima vez que se cure.\n", curacionb);
				break;
				
			case 6://REDUCCIÓN ATAQUE DEL JUGADOR
			    printf("El enemigo ha decidido reducir tu ataque.\nTienes %i puntos de ataque, haras menos danho con tus proximos golpes.\n", ataquej);
				break;
				
			case 7://REDUCCIÓN CURACIÓN DEL JUGADOR
			    printf("El enemigo ha decidido reducir tu curacion.\nTienes %i puntos de curacion, tu curacion se ha visto reducida.\n", curacionj);
				break;
		}

		printf("\n\n");
		
	}while(hpj > 0 && hpb > 0);
	
return 0;
}
