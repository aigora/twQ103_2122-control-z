#include <stdio.h>
#define TAM_MAX 4
#include<stdlib.h>

struct Dusuario {
    char nombre[50];
    char apellidos[100];
    char email[50];
    char username[50];
};
int main () {
	struct Dusuario usuarios[TAM_MAX];
	char color;
    int tam_users,i=0,edad,menu=0,respuesta;
    system("COLOR 04");
    while (menu!=3)	{
    	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    	printf("\n\t\t\t\tcontrol z,\t control z,\t CONTROL Z!!!!!!!!!\n");
    	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    	printf("\n %c INICIAR PARTIDA(1)\n\n %c CONFIGURACION(2)\n\n %c SALIR(3)\n",175,175,175);
    	printf("\n\n%c Indique que desea hacer con el numero correspondiente:\t",175);
    	scanf("%d",&menu);
    	if(menu==1)	{
    			system("cls");
    			printf("Al fin te hemos encontrado!\n");
    			printf("\n");
   				printf("Bueno dejame contarte, antes de que perdieras la memoria trabajabas para la empresa de modificacion genetica 'Control Z'");
				printf("encargada de crear bacterias y virus para erradicar todas las enfermedades del mundo.\n");
				printf("\n");
    			printf("Y asi fue, hoy en dia no hay ni malaria ni COVID19  entre otras enfermedades, pero...\n");
    			printf("una alteracion genetica en uno de esos nuevos virus permitio que llegara a los humanos a los cuales transforma en... \n");
    			printf("ZOMBIES!!!!\n");
    			printf("\n");
   	 			printf("Hemos denominado al virus en cuestion 'VirusZ'\n");
    			printf("Tu mision es encontrar la cura a VirusZ antes de que el 100%% de la poblacion se convierta en zombie\n");
    			printf("\n");
    			printf("Ya que sabes lo que tienes que hacer. Hablame de ti: \n");
    			//tabular
    do{
        printf("Escriba su edad (Este juego es para mayores de 12 anhos) \n");
        scanf("%d",&edad);
    }while(edad<12);

    do{
        printf("Cuantos cientificos nos salvaran? (la jugabilidad maxima de este juego son 4 usuarios): \n");
        scanf("%d",&tam_users);
    }while(tam_users>4);

    while(tam_users>i){
        fflush(stdin);
        printf("Escriba su nombre cientifico %d \n",i+1);
        gets(usuarios[i].nombre);
        printf("Escriba sus apellidos \n");
        gets(usuarios[i].apellidos);
        printf("Escriba su email \n");
        gets(usuarios[i].email);
        printf("Escriba su username \n");
        gets(usuarios[i].username);
        i++;
	}
	for(i=0;tam_users>i;i++){
        printf("Bienvenido cientifico %s \n",usuarios[i].username);
	}

	printf("Pulse 1 si desea hacer el tutorial, pulse cualquier otra tecla si no lo necesita \n");
	scanf("%d",&respuesta);
	system("cls");
	if(respuesta == 1){
        for(i=0;tam_users>i;i++){
        printf("Bienvenido al tutorial cientifico %s \n",usuarios[i].username);
	}
        printf("Durante todo este juego tendras problemas, \n");
        printf("si los resuelves bien sobreviras, si no resuelves los suficientes bien, moriras \n");
        printf("Las preguntas se responderan con el numero 1 - 2 - 3 - 4 \n");
        printf("Entonces, para que te acostumbres a la supervivencia... \n");
        printf("El edificio en el que te acabas de despertar se está derrumbando... \n");
        printf("1- En la primera salida, no hay ningun zombie pero tardas 30 minutos en salir \n");
        printf("2- En la segunda salida, hay una horda de 6 zombies, pero tienes un AK-47 con 5 balas \n");
        printf("3- En la tercera salida, hay un comboy del gobierno que te llevara a un lugar seguro \n");
        printf("4- En la cuarta salida llegas a la terraza del edificio y tu unica opcion es lanzarte desde ahi \n");
        do{
        printf("Cual es la que tendra mayor indice de supervivencia? \n");
        scanf("%d",&respuesta);
        if(respuesta == 3){
            printf("Bien hecho, has conseguido salir del hospital");
        }else{
            printf("Has muerto de una manera catastrofica (responde la 3)");
        }
        }while(respuesta!=3);

	}
	//solo para cuando solo haya menu
		printf("\nJugar de nuevo? SI(1) NO(3)\n");
			scanf("%d",&menu);
			system("cls");
	//tabular
		}else if (menu==2)	{
			system("cls");
			fflush(stdin);

			printf("CONFIGURACION DE COLORES DE LAS LETRAS DE LA INTERFAZ\n");

			printf("Verde(V),Rojo(R),Amarillo(A),Blanco(B):\t");

			scanf("%c",&color);

			if (color=='V' || color=='v')	{
				system("COLOR 02");

			}else if (color=='r' || color=='R')	{
				system("COLOR 04");
			}else if (color=='a' || color=='A')	{
				system("COLOR 06");
			}else if (color=='b' || color=='B')	{
				system("COLOR 07");
			}
			system("cls");
		}
	}
}
