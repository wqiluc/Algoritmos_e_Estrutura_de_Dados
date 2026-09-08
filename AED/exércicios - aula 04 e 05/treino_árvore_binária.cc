#include <iostream>
#include <stdlib.h>
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
    novo_no_arvore->valor = valor;
    novo_no_arvore->direita_arvore = nullptr;
    novo_no_arvore->esquerda_arvore = nullptr;
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

void preOrdem(No* raiz_arvore)
{
    if (!raiz_arvore)
    {
        cout << "[Pré-Ordem] Ramo esgotado: nó nulo, nada a visitar aqui." << endl;
        return;
    }

    cout << raiz_arvore->valor << " ";
    preOrdem(raiz_arvore->esquerda_arvore);
    preOrdem(raiz_arvore->direita_arvore);
}

void emOrdem(No* raiz_arvore)
{
    if (!raiz_arvore)
    {
        cout << "[Em-Ordem] Ramo esgotado: nó nulo, nada a visitar aqui." << endl;
        return;
    }

    emOrdem(raiz_arvore->esquerda_arvore);
    cout << raiz_arvore->valor << " ";
    emOrdem(raiz_arvore->direita_arvore);
}

void posOrdem(No* raiz_arvore)
{
    if (!raiz_arvore)
    {
        cout << "[Pós-Ordem] Ramo esgotado: nó nulo, nada a visitar aqui." << endl;
        return;
    }

    posOrdem(raiz_arvore->esquerda_arvore);
    posOrdem(raiz_arvore->direita_arvore);
    cout << raiz_arvore->valor << " ";
}

int main()
{
    No* raiz_arvore = nullptr;

    raiz_arvore = inserirNo(raiz_arvore, 50);
    raiz_arvore = inserirNo(raiz_arvore, 30);
    raiz_arvore = inserirNo(raiz_arvore, 70);
    raiz_arvore = inserirNo(raiz_arvore, 20);
    raiz_arvore = inserirNo(raiz_arvore, 40);
    raiz_arvore = inserirNo(raiz_arvore, 60);
    raiz_arvore = inserirNo(raiz_arvore, 80);

    cout << "Pré-Ordem: ";
    preOrdem(raiz_arvore);

    cout << "\nEm-Ordem: ";
    emOrdem(raiz_arvore);

    cout << "\nPós-Ordem: ";
    posOrdem(raiz_arvore);

    int alvo = 40;
    No* valor_encontrado_arvore = buscarNo(raiz_arvore, alvo);

    if (valor_encontrado_arvore != NULL) 
    {
        cout << "\n\tValor " << alvo << " encontrado na árvore. ✅";
    }

    else 
    {
        cout << "\n\tValor " << alvo << " não encontrado na árvore. ❌";
    }

    cout << endl;
    system("PAUSE");
    return 0;
}