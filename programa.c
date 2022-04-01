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

    printf("Bienvenido al juego Como escapar de la selva \n");
    printf("Durante toda la travesia, tendra que elegir opciones que estas le llevaran por el buen camino o.... \n");
    printf("A UNA MUERTE CATASTROFICA \n");

    do{
        printf("Este juego es para mayores de 12 anhos \n");
        printf("Escriba su edad \n");
        scanf("%d",&edad);
    }while(edad<=12);

    do{
        printf("Cuantos usuarios son (la jugabilidad maxima de este juego son 4 usuarios): \n");
        scanf("%d",&tam_users);
    }while(tam_users>4);

    while(tam_users>i){
        fflush(stdin);
        printf("Escriba su nombre jugador %d \n",i+1);
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
