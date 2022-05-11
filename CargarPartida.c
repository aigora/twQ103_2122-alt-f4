#include <stdio.h>
#define TAM_MAX 300
#include<windows.h>
#define color SetConsoleTextAttribute// Para que simplemente pongamos color cada vez que cambiemos el color del texto

//Haber chavales para el tema de las preguntas deberiamos hacer un fichero (ya creado llamado preguntas), para las respuestas deberiamos hacer un blucle. Es un porro lo se.
struct TJugadores{
    char nombre[50];
    int monedas;
};
void preguntas(char R_Correcta, int njug,struct TJugadores){

}
int main(){

int op1, op2, njug, i, cont, res, cont1, cont2, res1, dificultad;
char dif[50];
struct TJugadores jugadores[TAM_MAX];
FILE *f1;
HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//El handle funciona haciendo referencia a un bloque de memoria, en este caso  a hConsole(es el que da colores al texto).

color(hConsole,3);
printf("\t\t\t        **************************************************************************************\n");
printf("\t\t\t\t*Bienvenido a la base de datos del servicio de inteligencia Alt-f4, que desea hacer*\n");
printf("\t\t\t        **************************************************************************************\n\n");
color(hConsole,7);
printf("1. Nueva partida.\n2. Continuar partida.\n3. Opciones.\n\n");

scanf("%d", &op1);
switch(op1){

case 1:
    color(hConsole, 10);
    printf("Esta seguro agente? Recuerde que se borraran todos los datos guardados previamente.\n");
    printf("1. Si\n2. No\n\n");
    scanf("%d", &op1);
    if (op1 == 1){
        printf("Borrando datos...\n");
        printf("Cuantos jugadores van a haber en la partida (recuerde que el maximo son 4):\n");
        scanf("%d", &njug);
        while (4<njug){
    printf("Demasiados jugadores, recuerde que el maximo son 4.\n");
    printf("Cuantos jugadores son? El maximo de jugadores es 4.\n");
    scanf("%d",&njug);
}
printf("De acuerdo, ahora elija los nombres de los agentes secretos.\n");

for(i=0;i<njug;i++){
    printf("Indique su nombre, jugador %d\n",i+1);
    fflush(stdin);
    gets(jugadores[i].nombre);
}
printf("Son correctos los nombres de los agentes? Pon 0 si es que si y 1 si es que no.\n");
fflush(stdin);
scanf("%d",&res1);
if(res1 == 0){
printf("Perfecto, nombres guardados.\n");
} else{
    printf("Indique el numero del jugador que quiere cambiar el nombre:\n");
    fflush(stdin);
    scanf("%d", &i);
    printf("Indique el nuevo nombre del jugador %d\n",i);
    scanf("%s", &jugadores[i-1].nombre);
    fflush(stdin);
}
printf("Perfecto.Elija la dificultad de la mision.\n");
printf("Pon 0 si quieres jugar en modalidad facil, pon 1 si quieres jugar en modalidad 007 Agente secreto (dificil):\n");
scanf("%d", &dificultad);
if(dificultad==0){
    printf("Usted ha elegido modalidad facil. Los agentes tienen 5 pesetas al inicio del juego.\n");
}
else if(dificultad==1){
    printf("Usted ha elegido modalidad dificil. Los agentes tienen 3 pesetas al inicio del juego.\n");
}
printf("Preparaos porque la mision ya va a empezar. Los agentes ya han saltado en paracaidas y aterrizado cerca de las instalaciones.\n");
printf("Una vez en el suelo que haceis:\n");

printf("A)Recoger y guardar el paracaidas.\n");
printf("B)Hidratarse y comer algo.\n");
printf("C)Ponerse las gafas de vision nocturna.\n");
printf("D)Lanzar una vengala para poder encontrarse.\n");
    }
    else {
        printf("Que desea entonces:\n\n");
        printf("1. Continuar partida.\n2. Opciones.\n\n");
        scanf("%d", &op1);
        if(op1 == 1){
            printf("Recuperando base de datos...\n");
        }   else {
            printf("Menu de opciones:\n\n1. Tematica del juego.\n2. Creditos.\n\n");
            scanf("%d",&op1);
            if(op1 == 1){
                     printf("Despues de que el euro se volviera la moneda oficial del pais, hubo descontento por parte del Servicio Secreto ALT-F4.\n");
        printf("Desde las sombras se estaba preparando una mision, una mision que cambiaria la historia. Los mejores agentes que podian haber,\n");
        printf("se embarcaron a la gran aventura de corromper el estado para reinstaurar la peseta como moneda oficila.\n");
        printf("Seran capaces los agentes de cumplir con su cometido.\n");
        printf("El juego trata de un escape room de preguntas y respuestas, donde los usuarios tendran que responder bien para poder avanzar.\n");
        printf("Si se alcanza un numero maximo de fallos, dependiendo la dificultad, el agente perdera. Por tanto procura acertar y buena suerte.\n");

            }   else {
                printf("Trabajo desarrollado por el grupo Alt-f4, del grupo Q-103 en el año 2022.\nMiembros:\n\n- Adrian Mier Moreno.\n- Luis Miguel Fonfria Gutierrez de Tena.\n- Mario Calderon Santolaria.\n");
            }

        }
    }
    break;

case 2:
    color(hConsole, 10);
    printf("Cuantos jugadores hay disponibles?\n");
    scanf("%d", &njug);
    printf("Recuperando base de datos...\n\n\n");

    f1 = fopen("info.txt", "r");
    if(f1 == NULL){
        printf("Error de lectura en la base de datos.\n");
    }
    while(fscanf(f1,"%s %d", jugadores[i].nombre, &jugadores[i].monedas)!=EOF){
        i++;
        while(njug>i){
            printf("Datos no reconocidos. Cuantos jugadores hay disponibles?\n");
            scanf("%d", &njug);
        }
    }

    printf("Datos recuperados:\n");
    for(i=0;i<njug;i++){
        printf("Agente %d: %s %d pesetas\n", i+1, jugadores[i].nombre, jugadores[i].monedas);
    }
    fclose(f1);
    break;


case 3:
    color(hConsole, 10);
    printf("Menu de opciones:\n\n1. Tematica del juego.\n2. Creditos.\n\n");
    scanf("%d",&op1);
    if(op1 == 1){
        printf("Despues de que el euro se volviera la moneda oficial del pais, hubo descontento por parte del Servicio Secreto ALT-F4.\n");
        printf("Desde las sombras se estaba preparando una mision, una mision que cambiaria la historia. Los mejores agentes que podian haber,\n");
        printf("se embarcaron a la gran aventura de corromper el estado para reinstaurar la peseta como moneda oficila.\n");
        printf("Seran capaces los agentes de cumplir con su cometido.\n");
        printf("El juego trata de un escape room de preguntas y respuestas, donde los usuarios tendran que responder bien para poder avanzar.\n");
        printf("Si se alcanza un numero maximo de fallos, dependiendo la dificultad, el agente perdera. Por tanto procura acertar y buena suerte.\n");
    }   else {
                printf("Trabajo desarrollado por el grupo Alt-f4, del grupo Q-103 en el curso 2021-2022.\nMiembros:\n\n- Adrian Mier Moreno.\n- Luis Miguel Fonfria Gutierrez de Tena.\n- Mario Calderon Santolaria.\n");
        }
    break;
}

return 0;
}

