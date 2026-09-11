// QUESTÃO 04 – Sobre Listas (1.0 ponto)
// Implemente uma função que concatene duas listas (ligando o final da
// primeira ao início da segunda).
//
// Assinatura: No* concatenarListas(No* L1, No* L2);
// Obs. Faça todos os tratamentos necessários dentro da função, não fazer
// apenas o caminho feliz!

#include <iostream>
using namespace std;

struct No
{
    int valor;
    No* proximo;
};

No* criarNo(int valor)
{
    No* novo_no_lista = new No;
    novo_no_lista->valor = valor;
    novo_no_lista->proximo = NULL;
    return novo_no_lista;
}

void inserirFinal(No* lista, int valor)
{
    No* novo_no_lista = criarNo(valor);

    if (lista == NULL)
    {
        lista = novo_no_lista;
        return;
    }

    No* atual = lista;
    while (atual->proximo != NULL)
    {
        atual = atual->proximo;
    }
    atual->proximo = novo_no_lista;
}

No* concatenarListas(No* L1, No* L2)
{
    if (L1 == NULL && L2 == NULL)
    {
        return NULL;
    }

    if (L1 == NULL)
    {
        return L2;
    }

    // Tratamento 3: L2 vazia -> não há nada para concatenar no final de L1,
    // a lista concatenada continua sendo a própria L1.
    if (L2 == NULL)
    {
        return L1;
    }

    // Caminho feliz: percorre L1 até o último nó (aquele cujo "proximo" é
    // NULL) e liga esse último nó ao início de L2.
    No* ultimo_no_L1 = L1;
    while (ultimo_no_L1->proximo != NULL)
    {
        ultimo_no_L1 = ultimo_no_L1->proximo;
    }
    ultimo_no_L1->proximo = L2;

    return L1;
}

void imprimirLista(No* lista)
{
    while (lista != NULL)
    {
        cout << lista->valor;
        if (lista->proximo != NULL)
        {
            cout << " -> ";
        }
        lista = lista->proximo;
    }
    cout << endl;
}

int main()
{
    No* L1 = NULL;
    inserirFinal(L1, 1);
    inserirFinal(L1, 2);
    inserirFinal(L1, 3);

    No* L2 = NULL;
    inserirFinal(L2, 4);
    inserirFinal(L2, 5);

    cout << "L1: ";
    imprimirLista(L1);

    cout << "L2: ";
    imprimirLista(L2);

    No* L3 = concatenarListas(L1, L2);
    cout << "L1 concatenada com L2: ";
    imprimirLista(L3);

    // Casos extremos
    No* vazia = NULL;
    cout << "\nConcatenar(vazia, vazia): ";
    imprimirLista(concatenarListas(vazia, vazia));

    No* somenteL2 = NULL;
    inserirFinal(somenteL2, 9);
    cout << "Concatenar(vazia, L com 9): ";
    imprimirLista(concatenarListas(NULL, somenteL2));

    No* somenteL1 = NULL;
    inserirFinal(somenteL1, 7);
    cout << "Concatenar(L com 7, vazia): ";
    imprimirLista(concatenarListas(somenteL1, NULL));

    return 0;
}