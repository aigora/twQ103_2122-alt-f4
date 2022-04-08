//Menu del trivial del grupo ALT-F4
#include<stdio.h>
#include<windows.h>
//#include <iostream>
#define TAM_MAX 100
#define color SetConsoleTextAttribute// Para que simplemente pongamos color cada vez que cambiemos el oclor del texto
void preguntas();
//struct preguntas{
    //int Rcorrecta;
   // string pregunta, respuestaA, respuestaB,respuestaC,respuestaD;   Esta en comentarios porque no tengo ni idea de porque no funciona iostream, si sabeis algo de lujo chavales
//}p[20];//No se cuantas preguntas haremos, pero pongo 20 por poner un numero
struct TJugador{
    char nombre[50];
};

int main(){

//preguntas();
int jug,i,peseta,dificultad;
char res1,res2,b1;
struct TJugador jugador[TAM_MAX];

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//El handle funciona haciendo referencia a un bloque de memoria, en este caso  a hConsole(es el que da colores al texto).
color(hConsole,190);
printf("\n\n\t\t\t\t\tTRIVIAL BY ALT-F4\n");
printf("\t\t\t\t\t-----------------\n");
color(hConsole,3);
printf("1- El juego consiste en avanzar respondiendo preguntas. Si aciertas avanzas a la siguiente pregunta y consigues una 'peseta', por el contrario si falla se le quitara una 'peseta'.\n");
printf("2- Debe responder antes de que se acabe el tiempo, si no contesta en el tiempo permitido se considerara como fallida.\n");
printf("3- Con las 'pesetas' podra comprar comodines para utilizarlos en las preguntas.\n");
printf("4- Se le daran una serie de opciones con una letra representando a cada una, su respuesta debe ser dicha letra y en mayuscula.\n");
printf("5- Todos los jugadores empiezan con 5 'pesetas' en la modalidad de juego facil y con 3 en la dificil.\n");
printf("6- Si se queda sin pesetas pierde automaticamente.\n");
printf("7- El jugador que consiga responder todas las preguntas primero es el ganador.\n");
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
printf("¿Son correctos los nombres?\n");
scanf("%s", &res1);
if(res1=='no'){
    printf("Indique el numero del jugador que quiere cambiar el nombre:\n");
    scanf("%d", &i);
    printf("Indique el nuevo nombre del jugador %d\n",i);
    scanf("%s", &jugador[i-1].nombre);
    printf("Perfecto.Elija la dificultad.\n");
}
else{
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
//void preguntas(){
//p[0].pregunta = "¿Cuantos años duro la Segunda Guerra Mundial";
//p[0].respuestaA= "A-5";
//p[0].respuestaB= "B-6";
//p[0].respuestaC= "C-7";
//p[0].respuestaD= "D-4";
//p[0].Rcorrecta= B;


printf("Siguiente pregunta.\n");
return 0;
}
