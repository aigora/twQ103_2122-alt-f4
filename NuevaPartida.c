#include <stdio.h>
#define TAM_MAX 300

struct TJugadores{
    char nombre[50];
    int monedas;
};

int main(){

int op1, njug, i, cont;
char dif[50];
struct TJugadores jugadores[TAM_MAX];
FILE *f1;

printf("Borrando posibles datos previamente guardados...\n");
f1 = fopen("info.txt", "w");
if(f1 == NULL){
    printf("Error en la base de datos.\n");
    return 0;
}

printf("\n\n\nBienvenidos agentes.\n");

printf("Elija la dificultad:\n");
printf("1- Facil\n2- Dificil\n\n");
scanf("%d", &op1);

printf("Cuantos agentes desean iniciar sesion? El maximo es 2.\n\n");
fflush(stdin);
scanf("%d", &njug);
while(njug < 1 || 2 < njug){
    printf("Numero no valido de jugadores. Introduzca de nuevo cuantos son:\n\n");
    scanf("%d", &njug);
}

printf("Recibido, y cuales son sus nombres?\n\n");
for(i=0;i<njug;i++){
    printf("Nombre del jugador %d\n", i+1);
    fflush(stdin);
    gets(jugadores[i].nombre);
    printf("Jugador %d: %s\n\n", i+1, jugadores[i].nombre);
}

for(i=0;i<njug;i++){
    if(op1 == 1){
        cont = 5;
        jugadores[i].monedas = cont;
        fprintf(f1,"%s %d\n", jugadores[i].nombre, jugadores[i].monedas);
    }
}


printf("Nombres registrados correctamente.\n");
printf("Como ya sabran, el grupo Alt-f4 es un sistema de inteligencia secreto diseñado para situaciones limite.\n");
printf("Ustedes han sido seleccionados para ingresar en el grupo, pero para poder convertirse en agentes reales deberan superar una serie de pruebas.\n");
printf("Dichas pruebas consistiran en 20 preguntas, con cuatro posibles respuestas en cada una.\n");
printf("Puesto que todas las monedas nacionales actuales son rastreables, nosotros trabajamos con una ya extinta, la peseta.\n");
printf("Para que se familiaricen mas con ella, durante este proceso de pruebas trabajaran con ellas.\n");


if(op1 == 1){
    printf("Puesto que la dificultad elegida es facil, se dispondra de 5 pesetas\n");
}   else{
    printf("Puesto que la dificultad elegida es dificil, se dispondra de 3 pesetas\n");
    }

printf("En el caso que se queden sin monedas, quedaran eliminados.\n");


fclose(f1);
return 0;
}
