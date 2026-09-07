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
    No* novo_no_arvore = new No;
    novo_no_arvore->valor = valor;
    novo_no_arvore->esquerda_arvore = NULL;
    novo_no_arvore->direita_arvore = NULL;
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

    else if (valor > raiz_arvore->valor)
    {
        return buscarNo(raiz_arvore->direita_arvore, valor);
    }
}

No* encontrarMinimoNo(No* raiz_arvore)
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
            No* filho_direito = raiz_arvore->direita_arvore;
            delete raiz_arvore;
            return filho_direito;
        }

        else if (!raiz_arvore->direita_arvore)
        {
            No* filho_esquerdo = raiz_arvore->esquerda_arvore;
            delete raiz_arvore;
            return filho_esquerdo;
        }

        No* sucessor = encontrarMinimoNo(raiz_arvore->direita_arvore);
        raiz_arvore->valor = sucessor->valor;
        raiz_arvore->direita_arvore = removerNo(raiz_arvore->direita_arvore, sucessor->valor);
    }

    return raiz_arvore;
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
    No* raiz_arvore = NULL;

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
        cout << "\n\nValor " << alvo << " não encontrado na árvore. ❌";

    raiz_arvore = removerNo(raiz_arvore, 20); // Nó sem filhos
    raiz_arvore = removerNo(raiz_arvore, 30); // Nó com um filho
    raiz_arvore = removerNo(raiz_arvore, 50); // Nó com dois filhos

    cout << "\n\nÁrvore em ordem após remoções: ";
    emOrdem(raiz_arvore);

    cout << endl;
    system("PAUSE");
    return 0;
}
