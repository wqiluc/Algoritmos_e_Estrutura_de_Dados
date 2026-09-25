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

void inserirOrdenadoLista(Lista* lista, int valor)
{
    No* novo_lista = new No;
    novo_lista->valor = valor;

    if (!lista->inicio_lista || valor < lista->inicio_lista->valor)
    {
        novo_lista->proximo_lista = lista->inicio_lista;
        lista->inicio_lista = novo_lista;
        return;
    }

    No* lugar_temporario = lista->inicio_lista;

    while (lugar_temporario->proximo_lista && lugar_temporario->proximo_lista->valor < valor)
    {
        lugar_temporario = lugar_temporario->proximo_lista;
    }

    novo_lista->proximo_lista = lugar_temporario->proximo_lista;
    lugar_temporario->proximo_lista = novo_lista;
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
    int quantidade_valores;
    int valor;

    cout << "\n\t Quantos valores deseja inserir? ";
    cin >> quantidade_valores;

    for (int i = 0; i < quantidade_valores; i++)
    {
        cout << "Digite o " << i + 1 << "º valor: ";
        cin >> valor;
        inserirOrdenadoLista(lista, valor);

        cout << "Lista atual: ";
        mostrarLista(lista);
    }

    liberarLista(lista);
    return 0;
}
