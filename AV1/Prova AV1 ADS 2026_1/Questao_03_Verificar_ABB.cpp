// QUESTÃO 03 – Árvores Binárias (1.5 pontos)
// Crie uma função recursiva para verificar se a árvore é uma ABB válida
// (Árvore Binária de Busca).

#include <iostream>
#include <climits>
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

No* inserirNo(No* raiz_arvore, int valor)
{
    if (raiz_arvore == NULL)
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

// Todo nó precisa estar dentro do intervalo (minimo, maximo) permitido pelos
// seus ancestrais: ao descer para a esquerda, o valor máximo permitido passa
// a ser o valor do pai; ao descer para a direita, o valor mínimo permitido
// passa a ser o valor do pai. Use long long para o intervalo não estourar
// quando o valor do nó for INT_MIN ou INT_MAX.
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
    No* arvore_valida = NULL;
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