//A ver chavales aqui hay que empezar a hacer el codigo del menu y el flujograma

#include<stdio.h>
#include<windows.h>
#define TAM_MAX 100
#define color SetConsoleTextAttribute


struct TJugador{
    char nombre[50];

};
int main(){

int jug,i;
char res1, res2;
struct TJugador jugador[TAM_MAX];

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
color(hConsole,190);
printf("\n\n\t\t\t TRIVIAL BY ALT-F4");
printf("\t\t\t -----------------\n");
color(hConsole,3);
printf("1- El juego consiste en avanzar respondiendo preguntas. Si aciertas avanzas a la siguiente pregunta y consigues una 'peseta', por el contrario si falla se le quitara una 'peseta'.\n");
printf("2- Debe responder antes de que se acabe el tiempo, si no contesta en el tiempo permitido se considerara como fallida.\n");
printf("3- Con las 'pesetas' podra comprar comodines para utilizarlos en las preguntas.\n");
printf("4- Se le daran una serie de opciones con una letra representando a cada una, su respuesta debe ser dicha letra y en mayuscula.\n");
printf("5- Si se queda sin monedas pierde automaticamente.\n");
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
    scanf("%s", &jugador[i].nombre);
}

for(i=0;i<jug;i++){
    printf("Jugador %d: %s\n",i+1,jugador[i].nombre);
}
do{
printf("Son correctos estos nombres?\n");
fflush(stdin);
scanf("%s", &res1);

switch(res1) {
    case 'si':
    printf("Nombres guardados.\n");
    break;

    case 'no':
    printf("Indique el numero del jugador que quiere cambiar el nombre:\n");
    scanf("%d", &i);
    printf("Indique el nuevo nombre del jugador %d\n",i);
    scanf("%s", &jugador[i-1].nombre);
    for(i=0;i<jug;i++){
    printf("Jugador %d: %s\n",i+1,jugador[i].nombre);
}
    break;
}
}
color(hConsole,55);
printf("Perfecto, elija un nivel de dificultad.\n");
printf("A - Facil.\n");
printf("B - Dificil.\n");
scanf("%s", &res2);

printf("%s", res2);


return 0;
}
