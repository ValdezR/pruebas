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
void CreaListaVacia(Tnodo **);
void CargaLista(Tnodo**,Tnodo*);
void CrearNodoV2(Tnodo **);
void CargarListaAlComienzo(Tnodo **,int);
void CargarListaAlFinal(Tnodo **,int ); 
void MostrarLista(Tnodo *);
void BorraNodoV2(Tnodo **,int);
void BorraNodoV1(Tnodo **,int);
void LiberarLista(Tnodo*);

void main(){

  srand(time(NULL));
  int NroNodo,Nro;
  Tnodo *lista1,*lista2,*lista3;
  Tnodo *nodoaux;
  lista1=NULL;
  lista2=NULL;
  
  CreaListaVacia(&lista3);
  nodoaux=CrearNodo();
  CargaLista(&lista3,nodoaux);  

  printf("muestra lista 3\n");
  MostrarLista(lista3);

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
  printf("indique el nodo a borrar\n");
  scanf("%d",&NroNodo);
  fflush(stdin);
  BorraNodoV2(&lista2,NroNodo);
  MostrarLista(lista2);
  printf("indique el VALOR a borrar\n");
  scanf("%d",&Nro);
  fflush(stdin);
  BorraNodoV1(&lista2,Nro);
  MostrarLista(lista2);

  LiberarLista(lista1);
  LiberarLista(lista2);

  printf("fin lista\n");
  
  getchar();
}
void CreaListaVacia(Tnodo **Lista)
{
    *Lista=NULL;
}
Tnodo * CrearNodo()
{
	Tnodo * NNodo; 
    NNodo= (Tnodo *) malloc (sizeof(Tnodo));
	NNodo->valor = rand() % 99;
	NNodo->siguiente = NULL;
	return NNodo;
}

void CargaLista(Tnodo ** Lista,Tnodo * Nodo )
{
	Tnodo * ListaAux;
    ListaAux=*Lista;
    Nodo->siguiente=ListaAux;
    *Lista=Nodo;
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
    int i=0;
    while( Lista!=NULL)
    {
        printf("NODO %d=%d\n",i,Lista->valor);
        Lista=Lista->siguiente;
        i++;
    }
}

void BorraNodoV2(Tnodo ** lista, int indice)
{
  int i;
  i=0;
  Tnodo * Aux = *lista;
  Tnodo * AuxAnterior; 
  while (Aux!=NULL && i!=indice)
  {
    AuxAnterior = Aux;
   	Aux = Aux->siguiente;
    i++;
  }
  if (Aux!=NULL)
  { //si encuentro el valor lo borro si no no hago nada
    if(Aux !=*lista)
    {//para eliminar los demas elementos
    
        AuxAnterior -> siguiente = Aux -> siguiente;
    }
    else
    { //para eliminar el primer elemento de la lista
        *lista = Aux -> siguiente;
        //ya que el primer elemento 
        //de la lista tiene que arrancar desde Aux->siguiente
    }
    free(Aux);
  }
}

void BorraNodoV1(Tnodo ** lista, int valorBorrar)
{
  Tnodo * Aux = *lista;
  Tnodo * AuxAnterior; 
  while (Aux!=NULL && Aux->valor!=valorBorrar)
  {
    AuxAnterior = Aux;
   	Aux = Aux->siguiente;
  }

  if (Aux!=NULL)
  { //si encuentro el valor lo borro si no no hago nada
    if(Aux !=*lista)
    {//para eliminar los demas elementos
        AuxAnterior -> siguiente = Aux -> siguiente;
    }
    else
    { //para eliminar el primer elemento de la lista
        *lista = Aux -> siguiente;
        //ya que el primer elemento 
        //de la lista tiene que arrancar desde Aux->siguiente
    }
    free(Aux);
  }
}

void LiberarLista(Tnodo *Lista)
{
   Tnodo *Aux;
   while( Lista!=NULL)
    {
        Aux=Lista;
        Lista=Lista->siguiente;
       // free(Aux->valor);//si fuera un string
        free(Aux);   
    }  
}