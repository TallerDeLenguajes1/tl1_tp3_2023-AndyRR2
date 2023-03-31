#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Producto
{
    int ProductoID;
    int Cantidad;
    char *TipoProducto;
    float PrecioUnitario;
}typedef Producto;

struct ClienteID
{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
}typedef ClienteID;

void cargar(ClienteID *clientes,int cant,char *TiposProductos[]);
void mostrar(ClienteID *clientes, int cant);
int main(){
    srand(time(NULL));
    ClienteID *clientes;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int cant, key=1;
    printf("Entre la cantidad de clientes: ");
    scanf("%d",&cant);
    fflush(stdin);
    while (key==1)
    {
        if (1<=cant&&cant<=5)
        {
         clientes=(ClienteID*)malloc(cant*sizeof(ClienteID));
         key=0;
         }else
         {
          printf("El maximo de clientes es 5\n");
          printf("Entre la cantidad de clientes: ");
          scanf("%d",&cant);
          fflush(stdin);
        }
        cargar(clientes,cant,TiposProductos);
        mostrar(clientes,cant);
    }
free(clientes);
    return(0);
}
void cargar(ClienteID *clientes,int cant,char *TiposProductos[]){
    int num; 
    for (int i = 0; i < cant; i++)
    {
        clientes[i].ClienteID=i+1;
        clientes[i].NombreCliente=(char*)malloc(20*sizeof(char));
        printf("Entre el nombre del cliente %d: ",i+1);
        gets(clientes[i].NombreCliente);
        clientes[i].CantidadProductosAPedir=1+rand()%5;
        clientes[i].Productos=(Producto*)malloc(clientes[i].CantidadProductosAPedir*sizeof(Producto));
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID=j+1;
            clientes[i].Productos[j].Cantidad=1+rand()%9;
            num=0+rand()%4;
            clientes[i].Productos[j].TipoProducto=TiposProductos[num];
            clientes[i].Productos[j].PrecioUnitario=10+rand()%90;
        }
    }
}
void mostrar(ClienteID *clientes, int cant){
for (int i = 0; i < cant; i++)
{
    printf("Id Cliente %d: %d\n",i+1,clientes[i].ClienteID);
    printf("Nombre: ");
    puts(clientes[i].NombreCliente);
    for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
    {
        printf("Id Producto %d: %d\n",j+1,clientes[i].Productos[j].ProductoID);
        printf("Cantidad : %d\n",clientes[i].Productos[j].Cantidad);
        printf("Tipo: ");
        puts(clientes[i].Productos[j].TipoProducto);
        printf("Precio Unitario: $ %.2f\n",clientes[i].Productos[j].PrecioUnitario);
    }
}
}