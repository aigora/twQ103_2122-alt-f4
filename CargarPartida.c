#include <stdio.h>
#define TAM_MAX 300
#include<windows.h>
#define color SetConsoleTextAttribute// Para que simplemente pongamos color cada vez que cambiemos el color del texto

//Haber chavales para el tema de las preguntas deberiamos hacer un fichero (ya creado llamado preguntas), para las respuestas deberiamos hacer un blucle. Es un porro lo se.
struct TJugadores{
    char nombre[50],opcion;
    int monedas;
};
void preguntas(char R_Correcta, int njug,struct TJugadores jugadores[]){
int i,basura;

for(i=0;i<njug;i++){
    fflush(stdin);
    printf("Respuesta del jugador %d:\n",i+1);
    gets(jugadores[i].opcion);
}
for(i=0;i<njug;i++){
    if(jugadores[i].opcion==R_Correcta){
        jugadores[i].monedas++;
    }else{
    jugadores[i].monedas--;
    }
}
printf("\n La respuesta correcta es %c",R_Correcta);
for(i=0;i<njug;i++){
    fflush(stdin);
    printf("Pesetas del jugador %d:%d",i+1,jugadores[i].monedas);
}
system("cls");
return;
}
int main(){

int op1, op2, njug, i, cont, res, cont1, cont2, res1, dificultad;
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
    color(hConsole, 10);
    printf("Esta seguro agente? Recuerde que se borraran todos los datos guardados previamente.\n");
    printf("1. Si\n2. No\n\n");
    scanf("%d", &op1);
    if (op1 == 1){
        printf("Borrando datos...\n");
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
printf("Preparaos porque la mision ya va a empezar. Los agentes ya han saltado en paracaidas y aterrizado cerca de las instalaciones.\n");

//Pregunta 1
printf("Una vez en el suelo que haceis:\n");

printf("A)Recoger y guardar el paracaidas.\n");
printf("B)Hidratarse y comer algo.\n");
printf("C)Ponerse las gafas de vision nocturna.\n");
printf("D)Lanzar una bengala para poder encontrarse.\n");

//Pregunta 2
printf("Ya es de noche, tras hablar con el resto de agentes, la decisi�n tomada por el equipo es:\n");

printf("A)Dormir unas horas y entrar por la madrugada.\n");
printf("B)Dormir hasta la ma�ana y entrar de d�a.\n");
printf("C)Entrar a esa misma hora de la noche.\n");

//Pregunta 3
printf("Decididos a entrar a las instalaciones, los agentes se aseguran de fijar todas las c�maras y sus movimientos, y toman una decisi�n:\n");

printf("A)Romperlas sigilosamente.\n");
printf("B)Desactivarlas mediante un taser.\n");
printf("C)Entrar y, conociendo sus movimientos, arriesgarse a esquivarlas sin romperlas ni hackearlas.\n");

//Pregunta 4
printf("Tras decidir qu� hacer con las c�maras de vigilancia, hay que elegir una entrada:\n");

printf("A)Entrada principal.\n");
printf("B)Entrada trasera.\n");
printf("C)Zona de basura.\n");

//Pregunta 5
printf("Tras elegir la entrada m�s �ptima, encontr�is a varios basureros charlando y tom�ndose un descanso en una habitaci�n sin c�maras, qu� haceis:\n");

printf("A)Echar gas somn�fero (de larga duraci�n) y salir por la puerta m�s pr�xima al almac�n.\n");
printf("B)Matarlos con armas silenciadas y salir por la puerta m�s pr�xima al almac�n.\n");
printf("C)Entrar con sigilo y salir por la puerta m�s pr�xima al almac�n.\n");

//Pregunta 6
printf("Una vez en el almac�n, os encontr�is con que est� vac�o, pero observ�is una pantalla con n�meros y huella dactilar y una puerta cerrada, decid�s:\n");

printf("A)Intentar acertar el c�digo.\n");
printf("B)Regresar al basurero y con papel adhesivo, cogerle la huella a uno de ellos y usarla en la pantalla.\n");
printf("C)Romper el bloqueo de la puerta con cuidado.\n");

//Pregunta 7
printf("Tras abrir la puerta, os encontr�is con 4 guardas armados frente a una puerta enorme con la misma pantalla que antes (hay c�maras), decid�s:\n");

printf("A)Matarlos con las armas silenciadas, coger sus huellas y abrir.\n");
printf("B)Disparar a las c�maras con el taser, echar gas somn�fero (de larga duraci�n), coger sus huellas y abrir.\n");

//Pregunta 8
printf("Tras pasar la gran puerta, se observa un ropero y un pasillo largo que lleva a una habitaci�n, vuestra decisi�n es:");

printf("A)Entrar al ropero, cambiarse para hacerse pasar por trabajadores de las instalaciones, y seguidamente ir a la habitaci�n que hay al final del pasillo.\n");
printf("B)Volver atr�s, ponerse la ropa de guardas de los guardas dormidos, y seguidamente ir a la habitaci�n que hay al final del pasillo.\n");
printf("C)Ir directamente a la habitaci�n que hay al final del pasillo.\n");

//Pregunta 9
printf("Atraves�is la habitaci�n, os ve el director y piensa que sois nuevos, por lo que os pide que sub�is al despacho del jefe a presentaros.\n");
printf("Subiendo, veis que unos metros antes de la habitaci�n del presidente, se encuentra la f�brica de monedas y un despacho con todo tipo de archivos (el presidente os espera), decidis:\n");

printf("A)Vais a presentaros al presidente, que duda de vosotros, y seguidamente entr�is en la f�brica y despacho de archivos.\n");
printf("B)Antes de entrar al despacho del presidente, taseais las c�maras, sac�is las armas y lo amenaz�is para que os acompa�e a la f�brica y despacho de archivos.\n");
printf("C)Sabiendo que el presidente os espera, vais directos a la f�brica y despacho de archivos sin presentaros.\n");

//Pregunta 10
printf("Con el presidente a vuestra disposici�n, entr�is a los archivos y os entrega el derecho de cambio de moneda y os indica donde desactivar todas las m�quinas que hacen el cambio de peseta a euro.\n");
printf("Pero tambi�n aprovecha y pulsa el bot�n de alerta roja para que cierren todas las puertas, vuestra pr�xima decisi�n es:\n");

printf("A)Matar al presidente e intentar escapar.\n");
printf("B)Utilizar al presidente como reh�n para poder abrir las puertas y escapar.\n");
printf("C)Escapar dejando al presidente en el despacho.\n");

//Pregunta 11
printf("Os llevais al presidete en contra de su voluntad, sacais las armas largas sin silenciador y comenzais la huida (la polic�a est� avisada con incluso helic�pteros), eleg�s:\n");

printf("A)Salir por las puertas de huella por las que hab�is entrado.\n");
printf("B)Salt�is en paraca�das desde el despacho.\n");
printf("C)Bajar por los tubos del aire acondicionado hasta la zona de basura.\n");

//Pregunta 12
printf("Al llegar a la zona de basura, las puertas est�n bloqueadas y hay 3 guardas con armas largas, qu� hac�is:\n");

printf("A)Dispar�is a los guardas desde los tubos y utiliz�is la sierra el�ctrica para abrir un agujero la puerta.\n");
printf("B)Baj�is de los tubos amenaz�ndoles con matar al presidente si no os abren.\n");
printf("C)Os entreg�is y cuando os llevan fuera intent�is escapar.\n");
printf("D)Ech�is gas somn�fero a los guardas y cuando est�n dormidos utiliz�is la sierra el�ctrica para abrir un agujero la puerta.\n");

//Pregunta 13
printf("Solo vuestros compa�eros que est�n fuera saben que v�is a salir por el s�tano que hay tras la zona de la basura, os esperan ah� y hu�s:\n");

printf("A)En coche hasta la costa m�s cercana donde os espera una lancha submarino.\n");
printf("B)En coche hasta el helipuerto programado por vuestra organizaci�n donde os espera un helic�ptero.\n");
printf("C)En coche huyendo de la polic�a.\n");

//Final
printf("Consegu�s huir con �xito y con los archivos de cambio de moneda y la base del funcionamiento de las m�quinas.\n");



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
                printf("Trabajo desarrollado por el grupo Alt-f4, del grupo Q-103 en el a�o 2022.\nMiembros:\n\n- Adrian Mier Moreno.\n- Luis Miguel Fonfria Gutierrez de Tena.\n- Mario Calderon Santolaria.\n");
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

