//Fase beta de lo que se podria poner como temporizador de las preguntas
#include<stdio.h>
#include <windows.h>
#include <stdlib.h>

int main(){


int segundos=0,minutos=0,horas=0;
printf("Presione la tecla enter para inicar el contador");
system("pause -> NUL");

while(1){
    segundos++;
    if(segundos==60){
        segundos=0;
        minutos++;
        if(minutos==60){
            minutos=0;
            horas++;
        }
    }
    system("cls");
    printf("\n\n\n\t\t\t(%.2d:%.2d:%.2d)",horas,minutos,segundos);
    sleep(1000);///Esto significa 1000 milisegundos de retrasos
}

return 0;
}
