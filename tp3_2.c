#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
srand(time(NULL));
int matriz[5][12], p[5], max=10000, min=50000, Anio,Mes,anio,mes;
for (int i = 0; i < 5; i++)
{
    p[i]=0;
    for (int j = 0; j < 12; j++)
    {
        matriz[i][j]=10000+rand()%40000;
        p[i]=p[i]+matriz[i][j];
        if (matriz[i][j]>max)
        {
            max=matriz[i][j];
            Anio=i+1;
            Mes=j+1;
        }
        if (matriz[i][j]<min)
        {
            min=matriz[i][j];
            anio=i+1;
            mes=j+1;
        }
    }
}

for (int i = 0; i < 5; i++)
{
    for (int j = 0; j < 12; j++)
    {
        printf("%d ",matriz[i][j]);
    }
    p[i]=p[i]/12;
    printf("Promedio: %d ",p[i]);
    printf("\n");
}

printf("El valor maximo es: %d , anio: %d, mes: %d\n",max,Anio,Mes);
printf("El valor minimo es: %d , anio: %d, mes: %d\n",min,anio,mes);
    return(0);
}