#include <stdio.h>
#define TAM_MAX 4
struct Dusuario {
    char nombre[50];
    char apellido[100];
    char email[50];
    char username[50];
    int puntuacion;
};
int main(){
    FILE*pfile;
    int i=0,tam_us_guardados=300,tam_users,j,respuesta,w=0;
    struct Dusuario usuarios[TAM_MAX];
    struct Dusuario usuariosg[tam_us_guardados];
    pfile=fopen("ficheru.txt","r");
        if(pfile==NULL){
            printf("error");
            return 0;
        }else{
            while(fscanf(pfile,"%s %s %s %s %s %d",usuariosg[i].nombre,usuariosg[i].apellido,usuariosg[i].email,usuariosg[i].username,&usuariosg[i].puntuacion)!=EOF){
                    i++;
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
            fprintf(pfile,"%s %s %s %s %s %d",usuarios[i].nombre,usuarios[i].apellido,usuarios[i].email,usuarios[i].username,&usuarios[i].puntuacion);
            fclose(pfile);
            }
            else if(respuesta==2){
                fflush(stdin);
                pfile=fopen("ficheru.txt","r");
                if(pfile==NULL){
                    printf("error");
                    return 0;
                }else{
                        j=0;
                        while(fscanf(pfile,"%s %s %s %s %s %d",usuariosg[j].nombre,usuariosg[j].apellido,usuariosg[j].email,usuariosg[j].username,&usuariosg[j].puntuacion)!=EOF){
                        j++;
                        }
                }
                printf("Digame su nombre de usuario \n");
                gets(usuarios[i].username);
                for(j=0;j<10;j++){
                if(usuarios[i].username==usuariosg[j].username){
                    w++;
                    break;
                    }
                fclose(pfile);
                }if(w==1){
                    pfile=fopen("ficheru.txt","r");
                    printf("Bienvenido %s su máxima putuación es de %d, vamos a ver si la puede mejorar \n",usuariosg[j].username,usuariosg[j].puntuacion);
                    fclose(pfile);
                }else if(w==0);{
                    printf("no existe ningun usuario con tal nickname, intentelo de nuevo \n");
                    i--;
                }

            }
        i++;
        }

    return 0;
}

