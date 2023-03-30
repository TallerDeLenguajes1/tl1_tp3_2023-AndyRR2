#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargar(char *names);

int main(){
char *names;
names=(char*)malloc(5*sizeof(char));
cargar(names);

for (int i = 0; i < 5; i++)
{
    printf("Nombre numero %d: ",i+1);
    printf("%c\n",*names);
    names++;
}
    return(0);
}

void cargar(char *names){
    for (int i = 0; i < 5; i++)
{
    printf("Entre el nombre numero %d: ",i+1);
    gets(names);
    names++;
}
}