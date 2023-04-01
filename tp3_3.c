#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMA 150
void cargar(int num, char *V[num]);
void mostrar(int num, char *V[num]);

int main(){
int num;
char *V[TAMA];
printf("Entre el numero de nombres: ");
scanf("%d",&num);
fflush(stdin);
*V=malloc(num*sizeof(char));
cargar(num,V);
mostrar(num,V);
free(*V);
    return(0);
}

void cargar(int num, char *V[num]){
for (int i = 0; i < num; i++)
{
    printf("Entre el nombre numero %d: ",i+1);
    gets(V[i]);
}
}

void mostrar(int num, char *V[num]){
for (int i = 0; i < num; i++)
{
    printf("Nombre numero %d: ",i+1);
    puts(V[i]);
}
}