#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct No 
{
    int valor;
    No* proximo_fila;
} No;

typedef struct Lista 
{
    No* inicio_lista;
} Lista;

Lista* criarLista()
{
    Lista* lista = new Lista;
    lista->inicio_lista = nullptr;
    return lista;
}

int contar_Nos(No* atual, int cont_Nos)
{
    if (!atual)
    {
        return cont_Nos;
    }

    cont_Nos++;
    cont_Nos = contar_Nos(atual->proximo_fila, cont_Nos);
    return cont_Nos;
}