//Menu del trivial del grupo ALT-F4
#include<stdio.h>
#include<windows.h>
#define TAM_MAX 300
#define color SetConsoleTextAttribute// Para que simplemente pongamos color cada vez que cambiemos el color del texto
struct TPreguntas{
  char pregunta[100], respuesta[100];
  int puntos;
};
struct TJugador{
    char nombre[50];
};

int main(){

struct TPreguntas preguntas[TAM_MAX];
int res1,jug,i,peseta,dificultad;
int puntos[jug], contador=0;
char res2,b1, respuesta;
struct TJugador jugador[TAM_MAX];

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//El handle funciona haciendo referencia a un bloque de memoria, en este caso  a hConsole(es el que da colores al texto).
color(hConsole,190);
printf("\n\n\t\t\t\t\t\t\tTRIVIAL BY ALT-F4\n");
printf("\t\t\t\t\t\t\t-----------------\n");
color(hConsole,7);
printf("NORMAS:\n");
color(hConsole,3);
printf("1- El juego consiste en avanzar respondiendo preguntas. Si aciertas avanzas a la siguiente pregunta y consigues una 'peseta', por el contrario si falla se le quitara una 'peseta'.\n");
printf("2- Con las 'pesetas' podra comprar comodines para utilizarlos en las preguntas.\n");
printf("3- Se le daran una serie de opciones con una letra representando a cada una, su respuesta debe ser dicha letra y en mayuscula.\n");
printf("4- Todos los jugadores empiezan con 5 'pesetas' en la modalidad de juego facil y con 3 en la dificil.\n");
printf("5- Si se queda sin pesetas pierde automaticamente.\n");
printf("6- El jugador que consiga responder todas las preguntas primero es el ganador.\n");
printf(" \n");

color(hConsole,6);
printf("Cuantos jugadores son? El maximo de jugadores es 4.\n");
scanf("%d",&jug);

while (4<jug){
    printf("Demasiados jugadores, recuerde que el maximo son 4.\n");
    printf("Cuantos jugadores son? El maximo de jugadores es 4.\n");
    scanf("%d",&jug);
}

printf("De acuerdo.\n");

for(i=0;i<jug;i++){
    printf("Indique su nombre, jugador %d\n",i+1);
    fflush(stdin);
    gets(jugador[i].nombre);
}

for(i=0;i<jug;i++){
    printf("Jugador %d: %s\n",i+1,jugador[i].nombre);
}

printf("Son correctos los nombres? Pon 0 si es que si y 1 si es que no.\n");
fflush(stdin);
scanf("%d",&res1);

if(res1 == 0){
printf("Perfecto, nombres guardados.\n");
} else{
    printf("Indique el numero del jugador que quiere cambiar el nombre:\n");
    fflush(stdin);
    scanf("%d", &i);
    printf("Indique el nuevo nombre del jugador %d\n",i);
    scanf("%s", &jugador[i-1].nombre);
    fflush(stdin);
    printf("Perfecto.Elija la dificultad.\n");
}

printf("Pon 0 si quieres jugar en modalidad facil, pon 1 si quieres jugar en dificil:\n");
scanf("%d", &dificultad);
if(dificultad==0){
    printf("Usted ha elegido modalidad facil. Todos los jugadores tienen 5 pesetas al inicio del juego.\n");
}
else if(dificultad==1){
    printf("Usted ha elegido modalidad dificil. Todos los jugadores tienen 3 pesetas al inicio del juego.\n");
}
printf("Hagamos una prueba:\n");
color(hConsole,10);

printf("Cuantos anios duro la segunda guerra mundial?\n");
printf("A - 3.\n");
printf("B - 6.\n");
printf("C - 5.\n");
printf("D - 11.\n");

for(i=0;i<jug;i++){
    printf("Jugador %d, elija su respuesta:\n", i+1);
    fflush(stdin);
    scanf("%s", preguntas[i].respuesta);
    printf("Respuesta de %s es: %s\n", jugador[i].nombre,preguntas[i].respuesta);
    preguntas[i].puntos=0;
}
for(i=0;i<jug;i++){
if(preguntas[i].respuesta == 'B'){
        preguntas[i].puntos=preguntas[i].puntos+1;
    }
}
printf("La respuesta correcta era la B.\n");

printf("Actualizacion de puntuaciones:\n");
for(i=0;i<jug;i++){
    printf("%s %d\n", jugador[i].nombre, preguntas[i].puntos);
}
printf("Siguiente pregunta.\n");
return 0;
}
