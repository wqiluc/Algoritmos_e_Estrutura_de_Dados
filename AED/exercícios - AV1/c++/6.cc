#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct No 
{
    int valor;
    No* esquerda_arvore;
    No* direita_arvore;
} No;

No* criarNo(int valor)
{
    No* raiz_arvore = new No;
    raiz_arvore->valor = valor;
    raiz_arvore->esquerda_arvore = nullptr;
    raiz_arvore->direita_arvore = nullptr;
    return raiz_arvore;
}

No* inserirNo(No* raiz_arvore, int valor)
{
    if(!raiz_arvore)
    {
        return criarNo(valor);
    }

    if(valor < raiz_arvore->valor)
    {
        raiz_arvore->esquerda_arvore = inserirNo(raiz_arvore->esquerda_arvore, valor);
    }

    else if(valor > raiz_arvore->valor)
    {
        raiz_arvore->direita_arvore = inserirNo(raiz_arvore->direita_arvore, valor);
    }
}

No* buscarNo(No* raiz_arvore, int valor)
{
    if(!raiz_arvore || raiz_arvore->valor == valor)
    {
        return raiz_arvore;
    }

    if(valor < raiz_arvore->valor)
    {
        return buscarNo(raiz_arvore->esquerda_arvore, valor);
    }

    else if(valor > raiz_arvore->valor)
    {
        return buscarNo(raiz_arvore->direita_arvore, valor);
    }
}

// 2)
No* encontrarNoMinimo(No* raiz_arvore)
{
    while(raiz_arvore->esquerda_arvore != nullptr)
    {
        raiz_arvore = raiz_arvore->esquerda_arvore;
    }
    return raiz_arvore;
}

int menor(No *raiz_arvore)
{
    if(raiz_arvore->esquerda_arvore == nullptr)
    {
        return raiz_arvore->valor;
    }
    return menor(raiz_arvore->esquerda_arvore);
}