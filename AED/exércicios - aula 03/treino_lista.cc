#include <iostream>

using namespace std;

typedef struct No
{
    int dado;
    struct No* prox;
} No;

typedef struct Lista
{
    No* inicio;
} Lista;

// Inserir no início da lista
void inserirInicio(Lista* lista, int valor)
{
    No* novo = new No;
    novo->dado = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

// Inserir no final da lista
void inserirFim(Lista* lista, int valor)
{
    No* novo = new No;
    novo->dado = valor;
    novo->prox = NULL;

    if (!lista->inicio)
    {
        lista->inicio = novo;
        return;
    }

    No* temp = lista->inicio;
    while (temp->prox)
        temp = temp->prox;
    temp->prox = novo;
}

// Inserir no meio da lista, logo após o nó com valorBusca
void inserirMeio(Lista* lista, int valorNovo, int valorBusca)
{
    No* novo = new No;
    novo->dado = valorNovo;

    No* temp = lista->inicio;
    while (temp->prox && temp->prox->dado != valorBusca)
        temp = temp->prox;

    novo->prox = temp->prox;
    temp->prox = novo;
}

// Imprimir a lista
void imprimirLista(Lista* lista)
{
    No* temp = lista->inicio;
    while (temp)
    {
        cout << temp->dado << " -> ";
        temp = temp->prox;
    }
    cout << "NULL \n";
}

int main()
{
    Lista lista;
    lista.inicio = NULL;

    inserirInicio(&lista, 10);
    inserirInicio(&lista, 20);
    inserirInicio(&lista, 30);
    inserirFim(&lista, 40);
    inserirFim(&lista, 50);
    inserirMeio(&lista, 99, 10);
    imprimirLista(&lista);

    return 0;
}