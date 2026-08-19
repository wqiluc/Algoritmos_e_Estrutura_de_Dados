#include <iostream>
// #include <stdlib.h>
using namespace std;

typedef struct No 
{ 
    int dado;
    No* proximo_lista;
} No;

typedef struct Lista 
{
  No* inicio_lista;
} Lista;


Lista* criarlista()
{
    Lista* lista = new Lista;
    lista->inicio_lista = NULL;
    return lista;
}

void inseririnicio(Lista* lista, int numero)
{
    No* novo_no = new No;
    novo_no->dado = numero;
    novo_no->proximo_lista = lista->inicio_lista;
    lista->inicio_lista = novo_no;
}
void inserirfim(Lista* lista, int numero){}
void inserirmeio(Lista* lista, int valorNovo, int valorBusca){}

void imprimirLista(Lista* lista){}

int main(){}