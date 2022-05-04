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

//funciones de las preguntas

char pregunta(char correcta) {
    struct Dusuario usuarios[TAM_MAX];
    int i;
	char opcion;
	scanf("%c", &opcion);
	if (opcion == correcta) {
		printf("CORRECTO!!!\n");
		usuarios[i].puntuacion++;
	}
	else {
		printf("pfff un poco mal eh\n");
	}
	return opcion;
}
int main () {
	FILE*pfile;
	struct Dusuario usuarios[TAM_MAX];
	struct Dusuario usuariosg[TAM_MAX_GUARDADOS];
	char color;
    int tam_users,i=0,edad,menu=0,respuesta,preguntas;
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
                usuarios[i].puntuacion=0;
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
            //respuestas posibles
            char a,b,c;
                printf("Cuantas caras tiene un isocaedro?\n");
                printf("a) 2\n");
                printf("b) 15\n");
                printf("c) 20\n");
                pregunta('c');
                
                printf("Entre los ingredientes para desarrollar la cura necesitas agua, pero solo hay frascos con simbolos quimicos\n");
                printf("Cual eliges?\n")
                printf("a) H2SO4\n");
                printf("b) H2O\n");
                printf("c) C6H12O6 \n");
                pregunta('b');
                
                printf("De repente se te acerca un zombie, que haces?\n");
                printf("a) Acariciarlo\n");
                printf("b) Lanzarle agua\n");
                printf("c) Lanzarle acido sulfurico\n");
                pregunta('c');
                
                printf("Uno de los ingredientes mas importantes de la cura se encuentra en una caja fuerte cuya contrasenha es la capital de Azerbayan\n");
                printf("Cual eliges?\n")
                printf("a) Madrid\n");
                printf("b) Tiflis\n");
                printf("c) Baku \n");
                pregunta('c');
                
                printf("A cuantos grados corresponde un angulo llano?\n");
                printf("a) 180 \n");
                printf("b) 90\n");
                printf("c) 0\n");
                pregunta('a');
                
                printf("Para saber la cantidad de un ingrediente que hay que poner hay que resolver la siguiente ecuacion 2x= 6+4\n");
                printf("a) 5 \n");
                printf("b) 20\n");
                printf("c) 10\n");
                pregunta('a');
                
                printf("Ves un zombie en la lejania, tienes un canhon, en que angulo pondrias el canhon respecto al suelo para que el proyectil llegue al zombie?\n");
                printf("a) 0 \n");
                printf("b) 90\n");
                printf("c) 45\n");
                pregunta('c');
                
                printf("Tienes mucha sed y solo hay agua en un charco, que haces?\n");
                printf("a) Filtrarla y hervirla \n");
                printf("b) Tomar el agua del charco\n");
                printf("c) Echarle amoniaco\n");
                pregunta('a');
                
                printf("Tienes que dejar la cura en un frigorifico por 2 horas, en tu reloj solo funciona el minutero\n");
                printf("Cuantos minutos tienes que esperar?\n");
                printf("a) 2 \n");
                printf("b) 120\n");
                printf("c) 100\n");
                pregunta('b');
                
                printf("Tras pasar las 2 horas, te das cuenta de que no habias anhadido varios ingredientes\n");
                printf("Necesitas aluminio, de donde lo sacas?\n");
                printf("a) Del envoltorio de un bocata\n");
                printf("b) De un trozo de carton\n");
                printf("c) De una botella\n");
                pregunta('a');
            }

	return 0;
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
