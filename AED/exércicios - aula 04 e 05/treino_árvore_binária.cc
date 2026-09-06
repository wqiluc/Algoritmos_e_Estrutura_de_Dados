#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct No 
{
    int dado;
    No* esquerda_arvore;
    No* direita_arvore;
} No;

No* criarNo(int dado)
{
    No* novo_no_arvore = new No;
    novo_no_arvore->dado = dado;
    novo_no_arvore->esquerda_arvore = NULL;
    novo_no_arvore->direita_arvore = NULL;
    return novo_no_arvore;
}

No* inserirNo(No* raiz_arvore, int dado)
{
    if(!raiz_arvore)
    {
        cout << "\n\t Árvore Vazia ❌\n";
        return criarNo(dado);
    }

    if (dado < raiz_arvore->dado)
    {
        raiz_arvore->esquerda_arvore = inserirNo(raiz_arvore->esquerda_arvore, dado);
    }

    else if (dado > raiz_arvore->dado)
    {
        raiz_arvore->direita_arvore = inserirNo(raiz_arvore->direita_arvore, dado);
    }
}

No* buscarNo(No* raiz_arvore, int dado)
{
    if (!raiz_arvore || raiz_arvore->dado == dado)
    {
        return raiz_arvore;
    }

    if (dado < raiz_arvore->dado)
    {
        return buscarNo(raiz_arvore->esquerda_arvore, dado);
    }

    else if (dado > raiz_arvore->dado)
    {
        return buscarNo(raiz_arvore->direita_arvore, dado);
    }
}


void preOrdem(No* raiz_arvore)
{
    if (!raiz_arvore)
    {
        cout << "\n\t Árvore Vazia ❌\n";
        return;
    }

    cout << raiz_arvore->dado << " ";
    preOrdem(raiz_arvore->esquerda_arvore);
    preOrdem(raiz_arvore->direita_arvore);
}


void emOrdem(No* raiz_arvore)
{
    if (!raiz_arvore)
    {
        cout << "\n\t Árvore Vazia ❌\n";
        return;
    }

    emOrdem(raiz_arvore->esquerda_arvore);
    cout << raiz_arvore->dado << " ";
    emOrdem(raiz_arvore->direita_arvore);
}


void posOrdem(No* raiz_arvore)
{
    if (!raiz_arvore)
    {
        cout << "\n\t Árvore Vazia ❌\n";
        return;
    }

    posOrdem(raiz_arvore->esquerda_arvore);
    posOrdem(raiz_arvore->direita_arvore);
    cout << raiz_arvore->dado << " ";
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
    No* encontrado_arvore = buscarNo(raiz_arvore, alvo);

    if (encontrado_arvore != NULL)
        cout << "\n\nValor " << alvo << " encontrado na árvore. ✅";
    else
        cout << "\n\nValor " << alvo << " não encontrado na árvore. ✅";

    cout << endl;
    system("PAUSE");
    return 0;
}