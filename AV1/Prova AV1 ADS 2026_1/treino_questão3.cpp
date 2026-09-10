// QUESTÃO 03 – Árvores Binárias (1.5 pontos)
// Crie uma função recursiva para verificar se a árvore é uma ABB válida
// (Árvore Binária de Busca).

#include <iostream>
#include <climits>

typedef struct No 
{
    int valor;
    No* direita_arvore;
    No* esquerda_arvore;
} No;

No* criarNo(int valor)
{
    No* novo_no_arvore = new No;
    novo_no_arvore->direita_arvore = nullptr;
    novo_no_arvore->esquerda_arvore = nullptr;
    novo_no_arvore->valor = valor;
    return novo_no_arvore;
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

    else if (valor > raiz_arvore->valor)
    {
        return buscarNo(raiz_arvore->direita_arvore, valor);
    }
}
No* encontrarNominimo(No* raiz_arvore)
{
    while (raiz_arvore->esquerda_arvore != NULL)
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
        No* sucessor = encontrarNominimo(raiz_arvore->direita_arvore);
        raiz_arvore->valor = sucessor->valor;
        raiz_arvore->direita_arvore = removerNo(raiz_arvore->direita_arvore, sucessor->valor);
    }
}

bool ehABBvalida(No* raiz_arvore, long long valor_minimo = LLONG_MIN, long long valor_maximo = LLONG_MAX)
{
    if (raiz_arvore == nullptr)
    {
        return true;
    }
}

int main(){}