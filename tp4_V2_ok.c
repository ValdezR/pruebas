#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarea
{
    int TareaID;       // Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
} typedef tarea;

// FUNCION CARGAR TAREAS
void cargarTareas(tarea **tareas, int tam)
{
    char *buffer;
    buffer = (char *)malloc(sizeof(char) * 300);
    for (int i = 0; i < tam; i++)
    {
        tareas[i]->TareaID = i + 1;

        printf("Ingrese la descripcion de la tarea %d: \n", i + 1);
        gets(buffer);
        fflush(stdin);
        tareas[i]->Descripcion = (char *)malloc(sizeof(strlen(buffer) + 1));
        strcpy(tareas[i]->Descripcion, buffer);
        do
        {
            printf("Ingrese la duracion de la tarea %d(entre 10 y 100): \n", i + 1);
            scanf("%d", &(tareas[i]->Duracion));
            fflush(stdin);

        } while (tareas[i]->Duracion > 100 || tareas[i]->Duracion < 10);
    }
    free(buffer);
}
// MOSTRAR
void mostrar(tarea *tareas)
{
    printf("NumeroID: %d \n", tareas->TareaID);
    printf("Descripcion: \n");
    puts(tareas->Descripcion);
    printf("duracion: %d\n", tareas->Duracion);
}

// FUNCION TAREAS REALIZADAS
void Realizadas(tarea **tareas, tarea **tareasRealizadas, int tam)
{
    int control;
    int j = 0;
    for (int i = 0; i < tam; i++)
    {
        mostrar(tareas[i]);
        printf("Esta tarea esta realizada (1 para si 0 para no) \n");
        scanf("%d", &control);
        if (control == 1)
        {
            tareasRealizadas[j] = tareas[i];
            j++;
            tareas[i] = NULL;
        }
    }
}
// MOSTRAR TAREAS PENDIENTES
void MostrartareasPendientes(tarea **tareas, int tam)
{
    printf("---TAREAS PENDIENTES---\n");
    for (int i = 0; i < tam; i++)
    {

        if (!(tareas[i] == NULL))
        {
            mostrar(tareas[i]);
        }
    }
}
// MOSTRAR TAREAS REALIZADAS
void MostrarTareasRealizadas(tarea **tareasRealizadas, int tam)
{
    printf("---TAREAS REALIZADAS---\n");
    for (int i = 0; i < tam; i++)
    {

        if (!(tareasRealizadas[i] == NULL))
        {
            mostrar(tareasRealizadas[i]);
        }
    }
}
// BUSCAR TAREAS POR ID
void BuscarTarea(tarea **tareasRealizadas, tarea **tareasPendientes, int id, int tam)
{
    for (int i = 0; i < tam; i++)
    {

        if (!(tareasRealizadas[i] == NULL) && tareasRealizadas[i]->TareaID == id)
        {
            mostrar(tareasRealizadas[i]);
        }
    }
    for (int i = 0; i < tam; i++)
    {

        if (!(tareasPendientes[i] == NULL) && tareasPendientes[i]->TareaID == id)
        {
            mostrar(tareasPendientes[i]);
        }
    }
}
int main()
{
    int id;
    int tam;
    tarea **tareas;
    tarea **tareasRealizadas;
    printf("Ingrese el numero de tareas: \n");
    scanf("%d", &tam);
    fflush(stdin);

    tareas = (tarea **)malloc(sizeof(tarea *) * tam);
    tareasRealizadas = (tarea **)malloc(sizeof(tarea *) * tam);

    for (int i = 0; i < tam; i++)
    {
        tareas[i] = (tarea *)malloc(sizeof(tarea));
    }
    cargarTareas(tareas, tam);

    for (int i = 0; i < tam; i++)
    {
        tareasRealizadas[i] = (tarea *)malloc(sizeof(tarea));
        tareasRealizadas[i] = NULL;
    }

    Realizadas(tareas, tareasRealizadas, tam);
    MostrartareasPendientes(tareas, tam);
    MostrarTareasRealizadas(tareasRealizadas, tam);
    printf("escriba el id de la tarea a buscar: \n");
    scanf("%d", &id);
    BuscarTarea(tareasRealizadas, tareas, id, tam);

    // LIBERAR MEMORIA
    for (int i = 0; i < tam; i++)
    {
        if (tareas[i] != NULL)
        {
            free(tareas[i]->Descripcion);
        }

        free(tareas[i]);
    }
    free(tareas);

    for (int i = 0; i < tam; i++)
    {
        if (tareasRealizadas[i] != NULL)
        {
            free(tareasRealizadas[i]->Descripcion);
        }

        free(tareasRealizadas[i]);
    }
    free(tareasRealizadas);

    return 0;
}