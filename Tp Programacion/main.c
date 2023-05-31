#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>

typedef struct {

int codigo;
char nombre[20];
float precio;
float costo;
int cantidad;

}producto;

void CargarProducto(char archivito[]);
void NuevoProducto(producto productoNuevo);
void mostrarProductos(char archivito[]);
void mostrarUnProducto( producto aux);



int main()
{

char nombreArchivo[] = "Productos.bin";
int eleccion;


do{
    printf("\nIngrese la opcion que desea realizar \n");
    printf(" 0. Terminar el programa\n");
    printf(" 1. Cargar un producto\n");
    printf(" 2. \n");
    printf(" 3. \n");
    printf(" 4. \n");
    printf(" 5.\n");
    printf(" 6.\n");
    printf(" 7.\n");
    printf(" 8.\n");
    printf(" 9.\n");
    printf(" 10.\n");

    fflush(stdin);
    scanf("%i",&eleccion);

    switch(eleccion)
    {
        case 1:
            CargarProducto(nombreArchivo);


            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        default:
            if (eleccion != 0){
            printf("Esa opcion no existe\n");
            }
            break;

}

    } while (eleccion != 0);
    return 0;

}



void CargarProducto(char archivito[]){

char eleccion = 's';
producto aux;
FILE *arch;

arch = fopen(archivito,"ab");

if(arch != NULL){

  while(eleccion == 's'){

   NuevoProducto(aux);
   fwrite(&aux, sizeof(producto), 1, arch);

   printf("si desea seguir cargando escriba 's'\n");
   fflush(stdin);
   scanf("%c",&eleccion);

 }

fclose(arch);

   }

     }

void NuevoProducto(producto productoNuevo){ // cargar un producto

printf("Codigo de producto:\n");
fflush(stdin);
scanf("%i",&productoNuevo.codigo);

printf("Nombre del producto:\n");
fflush(stdin);
gets(productoNuevo.nombre);

printf("Precio de Venta:\n");
fflush(stdin);
scanf("%f",&productoNuevo.precio);

printf("Costo de produccion:\n"); //Este por ahi despues lo cambiamos por una funcion de calculo de costos.
fflush(stdin);
scanf("%f",&productoNuevo.costo);

printf("Cantidad de producto en stock:\n");
fflush(stdin);
scanf("%i",&productoNuevo.cantidad);

}
//funcion para mostrar TODOS los productos
void mostrarProductos(char archivito[])
{
producto aux;
FILE *arch;

arch=fopen(archivito,"rb");

if(arch!=NULL)
{
    while(!feof(arch))
    {
        fread(&aux,sizeof(producto),1,arch);
        if(!feof(arch))
    {
    mostrarUnProducto(aux);
    }
    fclose(arch);
}
}
}

void mostrarUnProducto ( producto aux)
{

    puts("\n-----------------------------------------------\n");
    printf("El codigo del producto es: %i\n",aux.codigo);
    printf("El nombre del producto es: %s\n",aux.nombre);
    printf("El precio del producto es: %.2f\n",aux.precio);
    printf("El costo del producto es: %.2f\n",aux.costo);
    printf("El stock del producto es: %i\n",aux.cantidad);
    puts("\n-----------------------------------------------\n");
}