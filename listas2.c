#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Tnodo
{
	int valor;    
	struct Tnodo *siguiente;
}typedef Tnodo;

Tnodo * CrearNodo();
void CrearNodoV2(Tnodo **);
void CargarListaAlComienzo(Tnodo **,int);
void CargarListaAlFinal(Tnodo **,int ); 
void MostrarLista(Tnodo *);

void main(){

  srand(time(NULL));
  
  Tnodo *lista1,*lista2;
  lista1=NULL;
  lista2=NULL;
int i;
 for(i=0;i<5;i++)
 {
  CargarListaAlComienzo(&lista1,i);   
 } 

 for(i=0;i<5;i++)
{
    CargarListaAlFinal(&lista2,i);
}

  printf("muestra lista 1\n");
  MostrarLista(lista1);

  printf("muestra lista 2\n");
  MostrarLista(lista2);
  
  
  getchar();
}

Tnodo * CrearNodo()
{
	Tnodo * NNodo; 
    NNodo= (Tnodo *) malloc (sizeof(Tnodo));
	NNodo->valor = rand() % 99;
	NNodo->siguiente = NULL;
	return NNodo;
}

void CrearLista(Tnodo ** Nodo)
{
	Tnodo * NNodo; 
    NNodo= (Tnodo *) malloc (sizeof(Tnodo));
	NNodo->valor = rand() % 99;
	NNodo->siguiente = NULL;    
    *Nodo=NNodo;
}

void CargarListaAlComienzo(Tnodo ** Nodo,int valor)
{
	Tnodo * NodoAux; 
    NodoAux= (Tnodo *) malloc (sizeof(Tnodo));
	NodoAux->valor = valor;
    if (*Nodo==NULL)
    {
	    NodoAux->siguiente=NULL;
    }
    else
    {
        NodoAux->siguiente = *Nodo;
    }
    *Nodo=NodoAux;
}

void CargarListaAlFinal(Tnodo ** Nodo,int valor)
{
	Tnodo * NodoAux;
    Tnodo *Aux2=*Nodo; 
    NodoAux= (Tnodo *) malloc (sizeof(Tnodo));
	NodoAux->valor = valor;
    NodoAux->siguiente=NULL;
    if(Aux2!=NULL)
    {
        while( Aux2->siguiente!=NULL)
        {
            Aux2=Aux2->siguiente;
        }
        Aux2->siguiente=NodoAux; //estoy cargando  al final de la fila
    }    
    else
    {
     *Nodo=NodoAux; //por ser el primer nodo de la lista
    }
}
    
void MostrarLista(Tnodo *Lista)
{
    while( Lista->siguiente!=NULL)
        {
            printf("start1 %d\n",Lista->valor);
            Lista=Lista->siguiente;
        }
}

