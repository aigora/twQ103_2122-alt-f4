#include<stdio.h>
#include<windows.h>
#define color SetConsoleTextAttribute

//Esto es simplemente para saber los numeros de los colores para las letras
int main(){

int i;
HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

for(i=1;i<243;i++){
    color(hConsole,i);
    printf("Hola %d\n",i);
}

return 0;
}
