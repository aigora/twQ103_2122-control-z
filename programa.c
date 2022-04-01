#include <stdio.h>
#define TAM_MAX 4

struct Dusuario {
    char nombre[50];
    char apellidos[100];
    char email[50];
    char username[50];
};
int main () {
	struct Dusuario usuarios[TAM_MAX];

    int tam_users,i=0,edad;

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

	return 0;
}
