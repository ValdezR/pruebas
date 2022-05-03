#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Trabajo{ 
    int TareaID;    //Numerado en ciclo iterativo 
    char *Descripcion;  // 
    int Duracion; // entre 10 – 100 
}typedef Tarea;

struct TNodo{
    Tarea T;
    struct TNodo *siguiente;
} typedef Nodo;

//********************DECLARO FUNCIONES***********************************

void CrearListaVacia(Nodo **);
void CargarTareaAlComienzo(Nodo **Cabecera, int i, char *Buff);
void InsertarTareAlFinal(Nodo **Cabecera);
void ControlTareas(Nodo **Pendientes, Nodo **Realizadas);
void MostrarLista(Nodo *);
void LiberarLista(Nodo *);
Nodo * QuitarTarea(Nodo **Listado);
void InsertarNodoEnLista(Nodo **ListadoDeTareas, Nodo * nodo);
//*********************MAIN***********************************************

int main(){

    int CantidadTareasACargar;
    char *Buff;
    
    int ContadorTareasRealizadas = 0;
    //char *PalabraClave;

    Buff = (char *) malloc(100 * sizeof(char));

    srand(time(NULL));
    Nodo *TareasPendientes, *TareasRealizadas;
    
    CrearListaVacia(&TareasPendientes);
    CrearListaVacia(&TareasRealizadas);

    printf("\nIngrese la cantidad de tareas a cargar: ");
    scanf("%d", &CantidadTareasACargar);
    getchar();

    for (int i = 0; i < CantidadTareasACargar; i++)
    {
        CargarTareaAlComienzo(&TareasPendientes, i, Buff);
    }

    ControlTareas(&TareasPendientes, &TareasRealizadas);

    printf("\n*****LISTA DE TAREAS REALIZADAS*****\n");
    MostrarLista(TareasRealizadas);

    printf("\n*****LISTA DE TAREAS PENDIENTES*****\n");
    MostrarLista(TareasPendientes);


    


    
    // puts("\n*****BUSCADOR DE TAREA*****");

    // printf("\nIngrese la palabra clave: ");
    // gets(Buff);

    // PalabraClave = (char *) malloc(strlen(Buff)+1 * sizeof(char));
    // strcpy(PalabraClave, Buff);

    // for (int i = 0; i < cantidadTareas; i++)
    // {
    //     if (!strcmp(PalabraClave, TareasPendientes[i]->Descripcion))
    //     {
    //         printf("Tarea Pendiente");
    //         printf("\nTarea: %d", TareasPendientes[i]->TareaID);
    //         printf("\nDescripcion: %s", TareasPendientes[i]->Descripcion);
    //         printf("\nDuracion: %d\n", TareasPendientes[i]->Duracion);
    //     } 
    // }


    free(Buff);

    LiberarLista(TareasPendientes);
    
    LiberarLista(TareasRealizadas);

    // free(PalabraClave);

    getchar();
    return 0;
}

//**************************FUNCIONES******************

void CrearListaVacia(Nodo **Lista){
    *Lista=NULL;
}

void CargarTareaAlComienzo(Nodo **Cabecera, int i, char *Buff){
    Nodo *TareaACargar;
    TareaACargar = (Nodo *) malloc(sizeof(Nodo));

    TareaACargar->T.TareaID = i+1;
    printf("\nTarea %d", TareaACargar->T.TareaID);
    printf("\nDescripcion: ");
    gets(Buff);
    TareaACargar->T.Descripcion = (char *) malloc(strlen(Buff)+1 * sizeof(char));
    strcpy(TareaACargar->T.Descripcion, Buff);
    TareaACargar->T.Duracion = 10 + rand() % 100 - 10;
    printf("Duracion: %d\n", TareaACargar->T.Duracion);
    
    TareaACargar->siguiente=*Cabecera;
    *Cabecera=TareaACargar;   
}


Nodo * QuitarTarea(Nodo **Listado)
{
    // sacar el nodo listas
    Nodo * aux = *Listado;
    // dejar la lista estable
    *Listado = aux->siguiente;
    // Poner el nodo como si estuviera libre
    aux->siguiente = NULL;
    // devolver el nodo quitado
    return aux;    
}

void InsertarNodoEnLista(Nodo **ListadoDeTareas, Nodo *nodo)
{
    nodo->siguiente = *ListadoDeTareas;
    *ListadoDeTareas = nodo;
}

void ControlTareas(Nodo **Pendientes, Nodo **Realizadas){
    int ControlTarea; //1=Si, 0=No
    Nodo *Aux;
    Nodo *RecorredorDeLista = *Pendientes;

    printf("\n*****CONTROL DE TAREAS*****\n");
    
    while (RecorredorDeLista){    
        printf("\nTarea %d", RecorredorDeLista->T.TareaID);
        printf("\nDescripcion: %s", RecorredorDeLista->T.Descripcion);
        printf("\nDuracion: %d\n", RecorredorDeLista->T.Duracion);

        printf("\n¿La tarea se realizo (Si = 1, No = 0? ");
        scanf("%d", &ControlTarea);
        getchar();

        if (ControlTarea == 1)
        {
            Nodo * NodoLibre = QuitarTarea(&RecorredorDeLista);
            InsertarNodoEnLista(Realizadas,NodoLibre);
        }
        else
        {
            RecorredorDeLista = RecorredorDeLista->siguiente;   
        }            
    } 
}

void MostrarLista(Nodo *Lista){
    int i=0;

    while (Lista!=NULL)
    {
        printf("\nTarea %d", Lista->T.TareaID);
        printf("\nDescripcion: %s", Lista->T.Descripcion);
        printf("\nDuracion: %d\n", Lista->T.Duracion);

        Lista = Lista->siguiente;

        i++;
    }
}

void LiberarLista(Nodo *Lista){
    Nodo *Aux;
    while (Lista != NULL)
    {
        Aux = Lista;
        Lista = Lista->siguiente;
        free(Aux->T.Descripcion);
        free(Aux);
    }
    
}