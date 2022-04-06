//A ver chavales aqui hay que empezar a hacer el codigo del menu y el flujograma

#include<stdio.h>
#include<windows.h>
#define TAM 100
#define color SetConsoleTextAttribute

int main(){

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
color(hConsole,3);
printf("Bienvendo al mejor juego de preguntas que se puede encontrar, aqui te presentamos las normas:\n");
printf("1- El juego consiste en avanzar respondiendo preguntas. Si aciertas avanzas a la siguiente pregunta y consigues una 'peseta', por el contrario si falla se le quitara una 'peseta'\n");
printf("2- Debe responder antes de que se acabe el tiempo, si no contesta en el tiempo permitido se considerara como fallida\n");
printf("3- Con las 'pesetas' podra comprar comodines para utilizarlos en las preguntas\n");













return 0;
}
