#include <stdio.h>

int main(){

int op1,dif;
char res1;
printf("Bienvenido a la base de datos de el servicio de inteligencia Alt-f4, que desea hacer:\n\n");
printf("1. Nueva partida.\n2. Continuar partida.\n3. Opciones.\n\n");

scanf("%d", &op1);
switch(op1){

case 1:
    printf("Esta seguro agente? Recuerde que se borraran todos los datos guardados previamente.\n");
    printf("1. Si\n2. No\n\n");
    scanf("%d", &op1);
    if (op1 == 1){
        printf("Borrando datos...\n");
    }
    else {
        printf("Que desea entonces:\n\n");
        printf("1. Continuar partida.\n2. Opciones.\n\n");
        scanf("%d", &op1);
        if(op1 == 1){
            printf("Recuperando base de datos...\n");
        }   else {
            printf("Menu de opciones:\n\n1. Dificultad.\n2. Creditos.\n\n");
            scanf("%d",&op1);
            if(op1 == 1){
                printf("Elija la dificultad:\n\n1. Facil.\n2. Dificil\n\n");
                scanf("%d",&dif);
                while(3 < dif && dif < 0){
                    printf("Vuelva a introducir el numero asignado a la dificultad deseada.\n");
                    scanf("%d", dif);
                }
                if(dif == 1){
                    printf("Ha elegido jugar en modo facil.\n");
                }   else {
                    printf("Ha elegido jugar en modo dificil\n");
                }
            }   else {
                printf("Trabajo desarrollado por el grupo Alt-f4, del grupo Q-103 en el año 2022.\nMiembros:\n\n- Adrian Mier Moreno.\n- Luis Miguel Fonfria Gutierrez de Tena.\n- Mario Calderon Santolaria.\n");
            }

        }
    }
    break;

case 2:
    printf("Recuperando base de datos...\n");
    break;


case 3:
    printf("Menu de opciones:\n\n1. Dificultad.\n2. Creditos.\n\n");
    scanf("%d",&op1);
    if(op1 == 1){
        printf("Elija la dificultad:\n\n1. Facil.\n2. Dificil\n\n");
        scanf("%d",&dif);
        while(3 < dif && dif < 0){
            printf("Vuelva a introducir el numero asignado a la dificultad deseada.\n");
            scanf("%d", dif);
        }
        if(dif == 1){
            printf("Ha elegido jugar en modo facil.\n");
        }   else {
            printf("Ha elegido jugar en modo dificil\n");
        }
    }   else {
                printf("Trabajo desarrollado por el grupo Alt-f4, del grupo Q-103 en el año 2022.\nMiembros:\n\n- Adrian Mier Moreno.\n- Luis Miguel Fonfria Gutierrez de Tena.\n- Mario Calderon Santolaria.\n");
        }
    break;
}

return 0;
}
