#include <stdio.h>
#define TAM_MAX 4
#include<stdlib.h>
#include <string.h>
#define TAM_MAX_GUARDADOS 300
#include <time.h>

struct Pregunta {
	char pregunta[400];
	char a[200];
	char b[200];
	char c[200];
	char correcta;
	char nose[500];//espacio tras la letra en solitario en el fichero
};
struct Dusuario {
    char nombre[50];
    char apellido[100];
    char email[50];
    char username[50];
    int puntuacion;
    char opcion;
};

//funciones de las preguntas
void pregunta(char correcta, int tam_users, struct Dusuario usuarios[])	{

    int i;
    int basura;
	char opcion;
	for(i=0;i<tam_users;i++)	{
		fflush(stdin);
		printf("Respuesta jugador %d: \n",i+1);
		scanf("%c", &usuarios[i].opcion);
	}
	for(i=0;i<tam_users;i++)	{
		if (usuarios[i].opcion == correcta) {
			usuarios[i].puntuacion++;
		}
	}
	printf("\n La opcion correcta era la %c",correcta);
	for(i=0;i<tam_users;i++)	{
		fflush(stdin);
		printf("\n Puntos jugador %d: %d",i+1,usuarios[i].puntuacion);
	}
	printf("\n Presione cualquier tecla y presione enter");
	scanf("%d",&basura); //Este scanf es para que el usuario marque el ritmo de su partida, pero para el programa no es útil (por eso se llama basura)
	fflush(stdin);
	system("cls");
	return;
}

void preguntasrandom (int a,int b,struct Pregunta textpregunta[],int tam_users,struct Dusuario usuarios[],int npreguntas)	{
    int v[20];
	int j=0;
    srand(time(NULL));
    while(j<npreguntas){
        v[j]= b+rand()%(a-b+1);
        //printf("%d \t",v[i]);
        //variable=limite_inferior+rand()%(Limite_superior + 1 -Limite_inferior)
        fflush(stdin);
		printf("%s",textpregunta[v[j]].pregunta);
        printf("%s",textpregunta[v[j]].a);
        printf("%s",textpregunta[v[j]].b);
        printf("%s",textpregunta[v[j]].c);
        pregunta(textpregunta[v[j]].correcta,tam_users,usuarios);
        fflush(stdin);
        j++;
    }
    j=0;


	return;
}

int main () {
	FILE*pfile;
	struct Dusuario usuarios[TAM_MAX]; //Estructura de los usuarios que van a jugar
	struct Dusuario usuariosg[TAM_MAX_GUARDADOS]; //Estructura de los usuarios ya guardados con sus putuaciones, todo esto está en un fichero
	struct Pregunta textpregunta[40];
	char color;
    int tam_users,i=0,edad,menu=0,respuesta,preguntas,j=0,orden,ntotalg,npreguntas;

    pfile=fopen("preguntas.txt","r");
        if(pfile==NULL){
            printf("error");
            return 0;
        }else{
            for(i=0;i<30;i++)	{
                    fflush(stdin);
					fgets(textpregunta[i].pregunta,500,pfile);
                    fgets(textpregunta[i].a,500,pfile);
                    fgets(textpregunta[i].b,500,pfile);
                    fgets(textpregunta[i].c,500,pfile);
                    fgets(&textpregunta[i].correcta,2,pfile);
                    fgets(textpregunta[i].nose,500,pfile);
                    fflush(stdin);
            }
    	}
    fclose(pfile);
    i=0;

    pfile=fopen("ficheru.txt","r");
        if(pfile==NULL){
            printf("error");
            return 0;
        }else{//Aquí se meten a los usuarios guardados dentro del struct Dusuarios usuariosg
            while(fscanf(pfile,"%s %s %s %s %d",usuariosg[i].nombre,usuariosg[i].apellido,usuariosg[i].email,usuariosg[i].username,&usuariosg[i].puntuacion)!=EOF){
                    i++;
                    ntotalg++;//número total de usuarios guardados, esto se utilizará más tarde para comprobar si el usuario que mete el usuario es antiguo o no
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
    }while(tam_users>4);//Jugabilidad máxima de 4 jugadores

	//ficheros
    i=0;
    while(tam_users>i){
            printf("Si es un nuevo usuario pulse 1 si es un usuario antiguo pulse 2 \n");
            scanf("%d",&respuesta);

        if(respuesta==1){//al ser un usuario nuevo se meten todos los datos en el struct Dusuarios usuario sin comparar de que sea antiguo
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
                usuarios[i].puntuacion=0;//Se guardaran los datos del usuario en el fichero
                fprintf(pfile,"%s %s %s %s %s %d \n",usuarios[i].nombre,usuarios[i].apellido,usuarios[i].email,usuarios[i].username,&usuarios[i].puntuacion);
                fclose(pfile);
        }
        else if(respuesta==2){
                fflush(stdin);
                printf("Digame su nombre de usuario \n");
                gets(usuarios[i].username);
                j=ntotalg;
            while(j>=0){//Aqui se oompara todos los usuarios guardados con el usuario nuevo
                orden=strcmp(usuarios[i].username,usuariosg[j].username);
                if(orden==0){
                    printf("Bienvenido %s, te echabamos de menos, su ultima puntuacion es %d\n",usuariosg[j].username,usuariosg[j].puntuacion);
                    usuarios[i].puntuacion=0;
                    break; //al encontrar al usuario ya no se necesita seguir
                }else{
                    j--;
                }
                }
            if(orden!=0){
                    printf("no encontramos su nombre de usuario \n");
                    i--;//Si no lo encuentra resta a i un -1 básicamente para que el número de usuarios sea el que se pidió con anterioridad y no sean menos
                }

            if(orden==0){
                pfile=fopen("ficheru.txt","a");
                    if(pfile==NULL){
                        printf("error");
                        return 0;}
                fprintf(pfile,"\n");//Como ya tenemos todos los datos (ya que jugó una partida con anterioridad), se guardan directamente en el fichero
                fprintf(pfile,"%s %s %s %s %d \n",usuariosg[j].nombre,usuariosg[j].apellido,usuariosg[j].email,usuarios[i].username,usuarios[i].puntuacion);
                fclose(pfile);
                }
            }

            i++;
        }
            	fflush(stdin);
            		while(npreguntas>3)	{
						printf("\n Duracion de partida corta(1), media(2) o larga(3) \t (10, 15 o 20 preguntas respectivamente)\n");
						scanf("%d",&npreguntas);
					}
            	system("cls");
            		if (npreguntas==1)	{
            			preguntasrandom(10,0,textpregunta,tam_users,usuarios,10);
					}else if (npreguntas==2)	{
						preguntasrandom(10,0,textpregunta,tam_users,usuarios,15);
					}else if (npreguntas==3)	{
						preguntasrandom(10,0,textpregunta,tam_users,usuarios,20);
					}
				fflush(stdin);
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
