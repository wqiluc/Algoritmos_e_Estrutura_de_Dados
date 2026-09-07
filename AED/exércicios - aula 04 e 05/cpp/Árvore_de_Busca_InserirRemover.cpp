#include <iostream>
#include <stdlib.h>
using namespace std;

struct No
{
    int valor;
    No* esquerda_arvore;
    No* direita_arvore;
};

No* criarNo(int valor)
{
    No* novo_no_arvore = new No;
    novo_no_arvore->valor = valor;
    novo_no_arvore->esquerda_arvore = NULL;
    novo_no_arvore->direita_arvore = NULL;
    return novo_no_arvore;
}

No* inserir(No* raiz_arvore, int valor)
{
    // TODO: implementar inserção
}

No* buscar(No* raiz_arvore, int valor)
{
    if (raiz_arvore == NULL || raiz_arvore->valor == valor)
    {
        return raiz_arvore;
    }

    if (valor < raiz_arvore->valor)
    {
        return buscar(raiz_arvore->esquerda_arvore, valor);
    }

    return buscar(raiz_arvore->direita_arvore, valor);
}

No* encontrarMinimo(No* raiz_arvore)
{
    while (raiz_arvore->esquerda_arvore != NULL)
        raiz_arvore = raiz_arvore->esquerda_arvore;
    return raiz_arvore;
}

No* remover(No* raiz_arvore, int valor)
{
    // TODO: implementar remoção
}

void preOrdem(No* raiz_arvore)
{
    if (raiz_arvore != NULL)
    {
        cout << raiz_arvore->valor << " ";
        preOrdem(raiz_arvore->esquerda_arvore);
        preOrdem(raiz_arvore->direita_arvore);
    }
}

void emOrdem(No* raiz_arvore)
{
    if (raiz_arvore != NULL)
    {
        emOrdem(raiz_arvore->esquerda_arvore);
        cout << raiz_arvore->valor << " ";
        emOrdem(raiz_arvore->direita_arvore);
    }
}

void posOrdem(No* raiz_arvore)
{
    if (raiz_arvore != NULL)
    {
        posOrdem(raiz_arvore->esquerda_arvore);
        posOrdem(raiz_arvore->direita_arvore);
        cout << raiz_arvore->valor << " ";
    }
}

int main()
{
    No* raiz_arvore = NULL;

    raiz_arvore = inserir(raiz_arvore, 50);
    raiz_arvore = inserir(raiz_arvore, 30);
    raiz_arvore = inserir(raiz_arvore, 70);
    raiz_arvore = inserir(raiz_arvore, 20);
    raiz_arvore = inserir(raiz_arvore, 40);
    raiz_arvore = inserir(raiz_arvore, 60);
    raiz_arvore = inserir(raiz_arvore, 80);

    cout << "Pre-Ordem: ";
    preOrdem(raiz_arvore);

    cout << "\nEm-Ordem: ";
    emOrdem(raiz_arvore);

    cout << "\nPos-Ordem: ";
    posOrdem(raiz_arvore);

    int alvo = 40;
    No* encontrado_arvore = buscar(raiz_arvore, alvo);

    if (encontrado_arvore != NULL)
        cout << "\n\nValor " << alvo << " encontrado na árvore.";
    else
        cout << "\n\nValor " << alvo << " não encontrado na árvore.";

    raiz_arvore = remover(raiz_arvore, 20); // Nó sem filhos
    raiz_arvore = remover(raiz_arvore, 30); // Nó com um filho
    raiz_arvore = remover(raiz_arvore, 50); // Nó com dois filhos

    cout << "\n\nArvore apos remocoes: ";
    emOrdem(raiz_arvore);

    cout << endl;
    system("PAUSE");
    return 0;
}
