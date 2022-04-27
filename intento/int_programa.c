#include <stdio.h>
#define TAM_MAX 4
#include<stdlib.h>
#include <string.h>
#define TAM_MAX_GUARDADOS 300

struct Dusuario {
    char nombre[50];
    char apellido[100];
    char email[50];
    char username[50];
    int puntuacion;
};
int main () {
	FILE*pfile;
	struct Dusuario usuarios[TAM_MAX];
	struct Dusuario usuariosg[TAM_MAX_GUARDADOS];
	char color;
    int tam_users,i=0,edad,menu=0,respuesta;
    int j=0,orden,ntotalg;

    pfile=fopen("ficheru.txt","r");
        if(pfile==NULL){
            printf("error");
            return 0;
        }else{
            while(fscanf(pfile,"%s %s %s %s %d",usuariosg[i].nombre,usuariosg[i].apellido,usuariosg[i].email,usuariosg[i].username,&usuariosg[i].puntuacion)!=EOF){
                    i++;
                    ntotalg++;
            }
        }
        fclose(pfile);
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

	//ficheros
    i=0;
    while(tam_users>i){
            printf("Si es un nuevo usuario pulse 1 si es un usuario antiguo pulse 2 \n");
            scanf("%d",&respuesta);

        if(respuesta==1){
                fflush(stdin);
                pfile=fopen("ficheru.txt","a");
                printf("Escriba su primer nombre cientifico %d \n",i+1);
                gets(usuarios[i].nombre);
                printf("Escriba su apellido \n");
                gets(usuarios[i].apellido);
                printf("Escriba su email \n");
                gets(usuarios[i].email);
                printf("Escriba su username \n");
                gets(usuarios[i].username);
                fprintf(pfile,"%s %s %s %s %s %d \n",usuarios[i].nombre,usuarios[i].apellido,usuarios[i].email,usuarios[i].username,&usuarios[i].puntuacion);
                fclose(pfile);
        }
        else if(respuesta==2){
                fflush(stdin);
                printf("Digame su nombre de usuario \n");
                gets(usuarios[i].username);
                j=ntotalg;
            while(j>=0){
                orden=strcmp(usuarios[i].username,usuariosg[j].username);
                if(orden==0){
                    printf("Bienvenido %s, te echabamos de menos, su ultima puntuacion es %d\n",usuariosg[j].username,usuariosg[j].puntuacion);
                    usuarios[i].puntuacion=0;
                    break;
                }else{
                    j--;
                }
                }
            if(orden!=0){
                    printf("no encontramos su nombre de usuario \n");
                    i--;
                }

            if(orden==0){
                pfile=fopen("ficheru.txt","a");
                    if(pfile==NULL){
                        printf("error");
                        return 0;}
                fprintf(pfile,"\n");
                fprintf(pfile,"%s %s %s %s %d \n",usuariosg[j].nombre,usuariosg[j].apellido,usuariosg[j].email,usuarios[i].username,usuarios[i].puntuacion);
                fclose(pfile);
                }
            }

            i++;
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
