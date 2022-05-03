#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
typedef struct
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arregloTiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;
typedef struct
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos          // El tamaño de este arreglodepende de la variable "CantidadProductosAPedir"
} Cliente;
void cargarClientes(Cliente *costumer, int cantidadClientes);
void mostrarClientes(Cliente *costumer, int cantidadClientes);
void liberarMemoria(Cliente *costumer, int cantidadClientes);
int main()
{
    srand(time(NULL));
    int cantClientes;
    printf("Ingrese la cantidad de clientes a cargar: ");
    scanf("%d", &cantClientes);
    fflush(stdin);
    Cliente *costumer;
    costumer = (Cliente *)malloc(sizeof(Cliente) * cantClientes);
    cargarClientes(costumer, cantClientes);
    mostrarClientes(costumer, cantClientes);
    liberarMemoria(costumer, cantClientes);
    getchar();
    return 0;
}
void cargarClientes(Cliente *costumer, int cantidadClientes)
{
    puts("Cargar arreglo de clientes\n");
    char *auxBuffNombreCliente;
    auxBuffNombreCliente = (char *)malloc(sizeof(char) * 50);
    for (int i = 0; i < cantidadClientes; i++)
    {
        costumer[i].ClienteID = i + 1;
        printf("Ingrese el nombre del cliente %d: ", i+1);
        gets(auxBuffNombreCliente);
        fflush(stdin);
        costumer[i].NombreCliente = (char *)malloc(sizeof(char) * (strlen(auxBuffNombreCliente) + 1));
        strcpy(costumer[i].NombreCliente, auxBuffNombreCliente);
        costumer[i].CantidadProductosAPedir = (rand() % 4) + 1;
        costumer[i].Productos = (Producto *)malloc(sizeof(Producto) * (costumer[i].CantidadProductosAPedir));
        for (int j = 0; j < costumer[i].CantidadProductosAPedir; j++)
        {
            costumer[i].Productos[j].ProductoID = j + 1;
            costumer[i].Productos[j].Cantidad = (rand() % 9) + 1;
            int auxTipoProduPosi;
            auxTipoProduPosi = rand() % 4;
            costumer[i].Productos[j].TipoProducto = (char *)malloc(sizeof(char) * strlen(TiposProductos[auxTipoProduPosi] + 1));
            strcpy(costumer[i].Productos[j].TipoProducto, TiposProductos[auxTipoProduPosi]);
            costumer[i].Productos[j].PrecioUnitario = (rand() % 90) + 10;
        }
    }
    free(auxBuffNombreCliente);
}
void mostrarClientes(Cliente *costumer, int cantidadClientes)
{
    puts("Mostrar arreglo de clientes\n");
    for (int i = 0; i < cantidadClientes; i++)
    {
        printf("Cliente %d\n", i+1);
        printf("ID del cliente: %d\n", costumer[i].ClienteID);
        printf("Nombre del cliente: %s\n", costumer[i].NombreCliente);
        printf("Cantidad de productos que solicito: %d\n", costumer[i].CantidadProductosAPedir);
        puts("Productos solicitados: \n");
        for (int j = 0; j < costumer[i].CantidadProductosAPedir; j++)
        {
            printf("Producto %d\n", j+1);
            printf("ID del producto: %d\n", costumer[i].Productos[j].ProductoID);
            printf("Tipo de producto: %s\n", costumer[i].Productos[j].TipoProducto);
            printf("Cantidad del producto: %d\n", costumer[i].Productos[j].Cantidad);
            printf("Precio unitario del producto %.2f\n", costumer[i].Productos[j].PrecioUnitario);
            puts("");
        }
        puts("\n");
    }
}
void liberarMemoria(Cliente *costumer, int cantidadClientes)
{
    for (int i = 0; i < cantidadClientes; i++)
    {
        free(costumer[i].NombreCliente);
        for (int j = 0; j < costumer[i].CantidadProductosAPedir; j++)
        {
            free(costumer[i].Productos[j].TipoProducto);
        }
        free(costumer[i].Productos);
    }
    free(costumer);
}