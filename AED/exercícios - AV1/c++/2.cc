#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct No 
{
    int valor;
    No* proximo_lista;
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

void inserirInicio(Lista* lista, int valor)
{
    No* novo_lista = new No;
    novo_lista->valor = valor;
    novo_lista->proximo_lista = lista->inicio_lista;
    lista->inicio_lista = novo_lista;
}


// 2)
No* removerNo(No* atual, int valor)
{
    if (!atual)
    {
        return nullptr;
    }

    if (atual->valor == valor)
    {
        No* proximo = atual->proximo_lista;
        delete atual;
        return proximo;
    }

    atual->proximo_lista = removerNo(atual->proximo_lista, valor);
    return atual;
}