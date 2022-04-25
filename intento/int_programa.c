#include <stdio.h>
#include <string.h>
#define TAM_MAX 4
#define TAM_MAX_GUARDADOS 300
struct Dusuario {
    char nombre[50];
    char apellido[100];
    char email[50];
    char username[50];
    int puntuacion;
};
int main(){
    FILE*pfile;
    int i=0,tam_users,j=0,respuesta,orden,ntotalg;
    struct Dusuario usuarios[TAM_MAX];
    struct Dusuario usuariosg[TAM_MAX_GUARDADOS];
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


        do{
            printf("Cuantos cientificos nos salvaran? (la jugabilidad maxima de este juego son 4 usuarios): \n");
            scanf("%d",&tam_users);
        }while(tam_users>4);


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
                    printf("Bienvenido %s, te echabamos de menos, tu record es %d\n",usuariosg[j].username,usuariosg[j].puntuacion);
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
        return 0;
}

