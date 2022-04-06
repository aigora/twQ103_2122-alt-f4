//A ver chavales aqui hay que empezar a hacer el codigo del menu y el flujograma

#include<stdio.h>
#include<windows.h>
#define TAM 100
#define color SetConsoleTextAttribute


struct TJugador{
    char nombre;

};
int main(){

int jug,i;
struct TJugador jugador[TAM];

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
color(hConsole,3);
printf("Bienvendo al mejor juego de preguntas que se puede encontrar, aqui te presentamos las normas:\n");
printf("1- El juego consiste en avanzar respondiendo preguntas. Si aciertas avanzas a la siguiente pregunta y consigues una 'peseta', por el contrario si falla se le quitara una 'peseta'.\n");
printf("2- Debe responder antes de que se acabe el tiempo, si no contesta en el tiempo permitido se considerara como fallida.\n");
printf("3- Con las 'pesetas' podra comprar comodines para utilizarlos en las preguntas.\n");
printf("4- Se le daran una serie de opciones con una letra representando a cada una, su respuesta debe ser dicha letra y en mayuscula.\n");
printf("5- Si se queda sin monedas pierde automaticamente.\n");
printf("6- El jugador que consiga responder todas las preguntas primero es el ganador.\n");
printf(" \n");

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
    scanf("%s",&jugador[i].nombre);
}

printf("%s\n",jugador[i].nombre);










return 0;
}
