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
    raiz_arvore->direita_arvore = nullptr;
    raiz_arvore->esquerda_arvore = nullptr;
    return raiz_arvore;
}

No* inserirNo(No* raiz_arvore, int valor)
{
    if (!raiz_arvore)
    {
        return criarNo(valor);
    }

    if (valor < raiz_arvore->valor)
    {
        raiz_arvore->esquerda_arvore = inserirNo(raiz_arvore->esquerda_arvore, valor);
    }

    else if (valor > raiz_arvore->valor)
    {
        raiz_arvore->direita_arvore = inserirNo(raiz_arvore->direita_arvore, valor);
    }

    return raiz_arvore;
}

No* buscarNo(No* raiz_arvore, int valor)
{
    if (!raiz_arvore || raiz_arvore->valor == valor)
    {
        return raiz_arvore;
    }

    if (valor < raiz_arvore->valor)
    {
        return buscarNo(raiz_arvore->esquerda_arvore, valor);
    }

    else if (valor < raiz_arvore->valor)
    {
        return buscarNo(raiz_arvore->direita_arvore, valor);
    }
}

No* encontrarNoMinimo(No* raiz_arvore)
{
    while(raiz_arvore->esquerda_arvore != nullptr)
    {
        raiz_arvore = raiz_arvore->esquerda_arvore;
    }
    return raiz_arvore;
}

No* removerNo(No* raiz_arvore, int valor)
{
    if (!raiz_arvore)
    {
        return raiz_arvore;
    }

    if (valor < raiz_arvore->valor)
    {
        raiz_arvore->esquerda_arvore = removerNo(raiz_arvore->esquerda_arvore, valor);
    }

    else if (valor > raiz_arvore->valor)
    {
        raiz_arvore->direita_arvore = removerNo(raiz_arvore->direita_arvore, valor);
    }

    else
    {
        if (!raiz_arvore->esquerda_arvore)
        {
            No* filho_direita = raiz_arvore->direita_arvore;
            delete raiz_arvore;
            return filho_direita;
        }

        else if (!raiz_arvore->direita_arvore)
        {
            No* filho_esquerda = raiz_arvore->esquerda_arvore;
            delete raiz_arvore;
            return filho_esquerda;
        }

        No* sucessor = encontrarNoMinimo(raiz_arvore->direita_arvore);
        sucessor->valor = raiz_arvore->valor;
        raiz_arvore->direita_arvore = removerNo(raiz_arvore->direita_arvore, sucessor->valor);
    }
}

int contagemDeNos(No* raiz_arvore, int contador)
{
    if (!raiz_arvore)
    {
        return contador;
    }

    contador++;
    contador = contagemDeNos(raiz_arvore->esquerda_arvore, contador);
    contador = contagemDeNos(raiz_arvore->direita_arvore, contador);
    return contador;
}

void emOrdem(No* raiz_arvore)
{
    if (!raiz_arvore)
    {
        return;
    }

    emOrdem(raiz_arvore->esquerda_arvore);
    cout << raiz_arvore->valor << " ";
    emOrdem(raiz_arvore->direita_arvore);
}

void preOrdem(No* raiz_arvore)
{
    if (!raiz_arvore)
    {
        return;
    }

    cout << raiz_arvore->valor << " ";
    preOrdem(raiz_arvore->esquerda_arvore);
    preOrdem(raiz_arvore->direita_arvore);
}

void posOrdem(No* raiz_arvore)
{
    if (!raiz_arvore)
    {
        return;
    }

    posOrdem(raiz_arvore->esquerda_arvore);
    posOrdem(raiz_arvore->direita_arvore);
    cout << raiz_arvore->valor << " ";
}

int main()
{
    No* raiz_arvore = nullptr;
    int valores[] = {50, 30, 70, 20, 40, 60, 80};

    for (int valor : valores)
    {
        raiz_arvore = inserirNo(raiz_arvore, valor);
    }

    cout << "Quantidade de nos: " << contagemDeNos(raiz_arvore, 0) << endl;

    cout << "Em ordem: ";
    emOrdem(raiz_arvore);
    cout << endl;

    cout << "Pre ordem: ";
    preOrdem(raiz_arvore);
    cout << endl;

    cout << "Pos ordem: ";
    posOrdem(raiz_arvore);
    cout << endl;

    return 0;
}