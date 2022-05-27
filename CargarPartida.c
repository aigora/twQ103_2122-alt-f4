#include <stdio.h>
#define TAM_MAX 300
#include<windows.h>
#define color SetConsoleTextAttribute// Para que simplemente pongamos color cada vez que cambiemos el color del texto


struct TJugadores{
    char nombre[50];
    int monedas, opcion;
};


void preguntas(int R_Correcta, int njug,struct TJugadores jugadores[]){
int i;


for(i=0;i<njug;i++){
    if(jugadores[i].monedas>0){
    fflush(stdin);
    printf("Respuesta del jugador %d:\n",i+1);
    scanf("%d",&jugadores[i].opcion);
    }else if(jugadores[i].monedas<=0){
    jugadores[i].monedas=0;
    printf("\nEl agente %s ha caido en combate\n",jugadores[i].nombre);
    }
}
for(i=0;i<njug;i++){
    if(jugadores[i].opcion==R_Correcta){
        jugadores[i].monedas++;
    }else{
    jugadores[i].monedas--;
    }
}
printf("\n La respuesta correcta es %d)\n",R_Correcta);
for(i=0;i<njug;i++){
    printf("\nPesetas del agente %s:%d\n",jugadores[i].nombre,jugadores[i].monedas);
}
return;
}
int main(){

int op1, op2, njug, i, cont, res, cont1, cont2, res1, dificultad, respuesta;
char dif[50];
struct TJugadores jugadores[TAM_MAX];
FILE *f1;
HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//El handle funciona haciendo referencia a un bloque de memoria, en este caso  a hConsole(es el que da colores al texto).

color(hConsole,3);
printf("\t\t\t        ************************************************************************************\n");
printf("\t\t\t\t*Bienvenido a la base de datos del servicio de inteligencia Alt-f4, que desea hacer*\n");
printf("\t\t\t        ************************************************************************************\n\n");
color(hConsole,7);
printf("1. ==> Nueva partida.\n2. ==> Continuar partida.\n3. ==> Opciones.\n\n");

scanf("%d", &op1);
switch(op1){

case 1:
    color(hConsole, 5);
    printf("Esta seguro agente? Recuerde que se borraran todos los datos guardados previamente.\n");
    printf("1. Si\n2. No\n\n");
    scanf("%d", &op1);
    if (op1 == 1){
        printf("Borrando datos...\n");
        f1 = fopen("marcador.txt", "w");
        if(f1 == NULL){
            printf("Error de lectura en la base de datos.\n");
            return 0;
        }
        printf("Cuantos jugadores va a haber en la partida (recuerde que el maximo son 4):\n");
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
    for(i=0;i<njug;i++){
        jugadores[i].monedas=5;
    }
}
else if(dificultad==1){
    printf("Usted ha elegido modalidad dificil. Los agentes tienen 3 pesetas al inicio del juego.\n");
    for(i=0;i<njug;i++){
        jugadores[i].monedas=3;
    }
}
//for(i=0;i<njug;i++){
 //   fprintf("%s %d", jugadores[i].nombre, jugadores[i].monedas);
//}
color(hConsole, 10);

printf("Preparaos porque la mision ya va a empezar. Los agentes ya han saltado en paracaidas y aterrizado cerca de las instalaciones.\n");


//Pregunta 1
printf("Una vez en el suelo que haceis:\n\n");

printf("1)Recoger y guardar el paracaidas.\n");
printf("2)Hidratarse y comer algo.\n");
printf("3)Ponerse las gafas de vision nocturna.\n");
printf("4)Lanzar una bengala para poder encontrarse.\n\n");

preguntas(1,njug,jugadores);

//Pregunta 2
printf("\n\nYa es de noche, tras hablar con el resto de agentes, la decision tomada por el equipo es:\n\n");

printf("1)Dormir unas horas y entrar por la madrugada.\n");
printf("2)Dormir hasta la mañana y entrar de día.\n");
printf("3)Entrar a esa misma hora de la noche.\n\n");

preguntas(1,njug,jugadores);

//Pregunta 3
printf("Decididos a entrar a las instalaciones, los agentes se aseguran de fijar todas las camaras y sus movimientos, y toman una decision:\n");

printf("1)Romperlas sigilosamente.\n");
printf("2)Desactivarlas mediante un taser.\n");
printf("3)Entrar y, conociendo sus movimientos, arriesgarse a esquivarlas sin romperlas ni hackearlas.\n");

preguntas(2,njug,jugadores);

//Pregunta 4
printf("Tras decidir que hacer con las camaras de vigilancia, hay que elegir una entrada:\n");

printf("1)Entrada principal.\n");
printf("2)Entrada trasera.\n");
printf("3)Zona de basura.\n");

preguntas(3,njug,jugadores);

//Pregunta 5
printf("Tras elegir la entrada mas optima, encontrais a varios basureros charlando y tomándose un descanso en una habitación sin camaras, que haceis:\n");

printf("1)Echar gas somnifero (de larga duracion) y salir por la puerta mas proxima al almacen.\n");
printf("2)Matarlos con armas silenciadas y salir por la puerta mas proxima al almacen.\n");
printf("3)Entrar con sigilo y salir por la puerta más proxima al almacen.\n");

preguntas(1,njug,jugadores);

//Pregunta 6
printf("Una vez en el almacén, os encontráis con que esta vacio, pero observais una pantalla con numeros y huella dactilar y una puerta cerrada, decidis:\n");

printf("1)Intentar acertar el codigo.\n");
printf("2)Regresar al basurero y con papel adhesivo, cogerle la huella a uno de ellos y usarla en la pantalla.\n");
printf("3)Romper el bloqueo de la puerta con cuidado.\n");

preguntas(2,njug,jugadores);

//Pregunta 7
printf("Tras abrir la puerta, os encontráis con 4 guardas armados frente a una puerta enorme con la misma pantalla que antes (hay camaras), decidis:\n");

printf("1)Matarlos con las armas silenciadas, coger sus huellas y abrir.\n");
printf("2)Disparar a las cámaras con el taser, echar gas somnifero (de larga duracion), coger sus huellas y abrir.\n");

preguntas(2,njug,jugadores);

//Pregunta 8
printf("Tras pasar la gran puerta, se observa un ropero y un pasillo largo que lleva a una habitacion, vuestra decision es:");

printf("1)Entrar al ropero, cambiarse para hacerse pasar por trabajadores de las instalaciones, y seguidamente ir a la habitacion que hay al final del pasillo.\n");
printf("2)Volver atras, ponerse la ropa de guardas de los guardas dormidos, y seguidamente ir a la habitación que hay al final del pasillo.\n");
printf("3)Ir directamente a la habitacion que hay al final del pasillo.\n");

preguntas(1,njug,jugadores);

//Pregunta 9
printf("Atravesais la habitacion, os ve el director y piensa que sois nuevos, por lo que os pide que subais al despacho del jefe a presentaros.\n");
printf("Subiendo, veis que unos metros antes de la habitación del presidente, se encuentra la fabrica de monedas y un despacho con todo tipo de archivos (el presidente os espera), decidis:\n");

printf("1)Vais a presentaros al presidente, que duda de vosotros, y seguidamente entrais en la fabrica y despacho de archivos.\n");
printf("2)Antes de entrar al despacho del presidente, taseais las camaras, sacais las armas y lo amenazais para que os acompañe a la fabrica y despacho de archivos.\n");
printf("3)Sabiendo que el presidente os espera, vais directos a la fabrica y despacho de archivos sin presentaros.\n");

preguntas(2,njug,jugadores);

//Pregunta 10
printf("Con el presidente a vuestra disposición, entrais a los archivos y os entrega el derecho de cambio de moneda y os indica donde desactivar todas las maquinas que hacen el cambio de peseta a euro.\n");
printf("Pero tambien aprovecha y pulsa el boton de alerta roja para que cierren todas las puertas, vuestra próxima decision es:\n");

printf("1)Matar al presidente e intentar escapar.\n");
printf("2)Utilizar al presidente como rehen para poder abrir las puertas y escapar.\n");
printf("3)Escapar dejando al presidente en el despacho.\n");

preguntas(2,njug,jugadores);

//Pregunta 11
printf("Os llevais al presidete en contra de su voluntad, sacais las armas largas sin silenciador y comenzais la huida (la policia está avisada con incluso helicopteros), elegis:\n");

printf("1)Salir por las puertas de huella por las que habeis entrado.\n");
printf("2)Saltais en paracaídas desde el despacho.\n");
printf("3)Bajar por los conductos del aire acondicionado hasta la zona de basura.\n");

preguntas(3,njug,jugadores);

//Pregunta 12
printf("Al llegar a la zona de basura, las puertas están bloqueadas y hay 3 guardas con armas largas, que haceis:\n");

printf("1)Disparais a los guardas desde los tubos y utilizais la sierra electrica para abrir un agujero la puerta.\n");
printf("2)Bajais de los conductos amenazandoles con matar al presidente si no os abren.\n");
printf("3)Os entregais y cuando os llevan fuera intentais escapar.\n");
printf("4)Echais gas somnifero a los guardas y cuando estén dormidos utilizais la sierra electrica para abrir un agujero la puerta.\n");

preguntas(4,njug,jugadores);

//Pregunta 13
printf("Solo vuestros compañeros que están fuera saben que vais a salir por el sótano que hay tras la zona de la basura, os esperan ahi y huis:\n");

printf("1)En coche hasta la costa mas cercana donde os espera una lancha submarino.\n");
printf("2)En coche hasta el helipuerto programado por vuestra organizacion donde os espera un helicoptero.\n");
printf("3)En coche huyendo de la policia.\n");

preguntas(1,njug,jugadores);

//Final
printf("Conseguis huir con exito y con los archivos de cambio de moneda y la base del funcionamiento de las maquinas. La peseta renacera en este pais.\n");
printf("Estadisticas del juego:\n");
for(i=0;i<njug;i++){
   if(jugadores[i].monedas>0)
        printf("El agente %s ha hacabado con %d pesetas.\n",jugadores[i].nombre,jugadores[i].monedas);
   else
    printf("El agente %s cayo en combate.",jugadores[i].nombre);
}


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
        printf("Desde las sombras se estaba preparando una mision, una mision que cambiaria la historia. Los mejores agentes que podia haber,\n");
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
        printf("Desde las sombras se estaba preparando una mision, una mision que cambiaria la historia. Los mejores agentes que podia haber,\n");
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

