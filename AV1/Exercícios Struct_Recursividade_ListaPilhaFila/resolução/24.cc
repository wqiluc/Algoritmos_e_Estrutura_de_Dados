#include <iostream>
using namespace std;

typedef struct No
{
    int valor;
    No* proximo_lista;
} No;

typedef struct Lista
{
    No* inicio_lista;
} Lista;

Lista* criarLista()
{
    Lista* lista = new Lista;
    lista->inicio_lista = nullptr;
    return lista;
}

void inserirFinalLista(Lista* lista, int valor)
{
    No* novo_lista = new No;
    novo_lista->valor = valor;
    novo_lista->proximo_lista = nullptr;

    if (!lista->inicio_lista)
    {
        lista->inicio_lista = novo_lista;
        return;
    }

    No* lugar_temporario = lista->inicio_lista;

    while (lugar_temporario->proximo_lista)
    {
        lugar_temporario = lugar_temporario->proximo_lista;
    }
    lugar_temporario->proximo_lista = novo_lista;
}

// Inverte os ponteiros de cada nó, sem criar nós novos
void inverterLista(Lista* lista)
{
    No* anterior_lista = nullptr;
    No* atual_lista = lista->inicio_lista;

    while (atual_lista)
    {
        No* proximo = atual_lista->proximo_lista;
        atual_lista->proximo_lista = anterior_lista;
        anterior_lista = atual_lista;
        atual_lista = proximo;
    }

    lista->inicio_lista = anterior_lista;
}

void mostrarLista(Lista* lista)
{
    No* atual_lista = lista->inicio_lista;

    while (atual_lista)
    {
        cout << atual_lista->valor << " ";
        atual_lista = atual_lista->proximo_lista;
    }
    cout << endl;
}

void liberarLista(Lista* lista)
{
    No* atual_lista = lista->inicio_lista;

    while (atual_lista)
    {
        No* proximo = atual_lista->proximo_lista;
        delete atual_lista;
        atual_lista = proximo;
    }
    delete lista;
}

int main()
{
    Lista* lista = criarLista();
    int valores[] = {1, 2, 3, 4, 5};
    int quantidade_valores = 5;

    for (int i = 0; i < quantidade_valores; i++)
    {
        inserirFinalLista(lista, valores[i]);
    }

    cout << "Lista original: ";
    mostrarLista(lista);

    inverterLista(lista);

    cout << "Lista invertida: ";
    mostrarLista(lista);

    liberarLista(lista);
    return 0;
}
