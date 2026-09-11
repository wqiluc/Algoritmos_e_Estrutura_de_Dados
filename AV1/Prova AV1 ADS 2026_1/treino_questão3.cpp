// QUESTÃO 03 – Árvores Binárias (1.5 pontos)
// Crie uma função recursiva para verificar se a árvore é uma ABB válida
// (Árvore Binária de Busca).

#include <iostream>
#include <climits>
using namespace std;
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

bool ehABBValida(No* raiz_arvore, long long minimo = LLONG_MIN, long long maximo = LLONG_MAX)
{
    if (raiz_arvore == NULL)
    {
        return true;
    }

    if (raiz_arvore->valor <= minimo || raiz_arvore->valor >= maximo)
    {
        return false;
    }

    return ehABBValida(raiz_arvore->esquerda_arvore, minimo, raiz_arvore->valor) &&
           ehABBValida(raiz_arvore->direita_arvore, raiz_arvore->valor, maximo);
}

int main()
{
    No* arvore_valida = nullptr;
    arvore_valida = inserirNo(arvore_valida, 50);
    arvore_valida = inserirNo(arvore_valida, 30);
    arvore_valida = inserirNo(arvore_valida, 70);
    arvore_valida = inserirNo(arvore_valida, 20);
    arvore_valida = inserirNo(arvore_valida, 40);

    cout << "Árvore válida é ABB? " << (ehABBValida(arvore_valida) ? "Sim" : "Não") << endl;

    No* arvore_invalida = criarNo(50);
    arvore_invalida->esquerda_arvore = criarNo(30);
    arvore_invalida->direita_arvore = criarNo(70);
    arvore_invalida->direita_arvore->esquerda_arvore = criarNo(40); // inválido: 40 < 50

    cout << "Árvore inválida é ABB? " << (ehABBValida(arvore_invalida) ? "Sim" : "Não") << endl;

    return 0;
}