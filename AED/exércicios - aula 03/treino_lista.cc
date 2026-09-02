#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct No
{
    int dado;
    No* proximo_lista;
} No;

typedef struct Lista
{
    No* inicio_lista;
} Lista;

Lista* criarLista()
{
    Lista* lista = new Lista;
    lista->inicio_lista = NULL;
    return lista;
}

void inserirInicio(Lista* lista, int valor)
{
    No* novo_lista = new No;
    novo_lista->dado = valor;
    novo_lista->proximo_lista = lista->inicio_lista;
    lista->inicio_lista = novo_lista;
}

void inserirFim(Lista* lista, int valor)
{
    No* novo_lista = new No;
    novo_lista->dado = valor;
    novo_lista->proximo_lista = NULL;

    if(!lista->inicio_lista)
    {
        lista->inicio_lista = novo_lista;
        return;
    }

    No* lugar_temporario = lista->inicio_lista;

    while(lugar_temporario->proximo_lista)
        lugar_temporario = lugar_temporario->proximo_lista;
    lugar_temporario->proximo_lista = novo_lista;
}

void inserirMeio(Lista* lista, int valorNovo, int valorBusca)
{
    No* novo_lista = new No;
    novo_lista->dado = valorNovo;
    novo_lista->proximo_lista = NULL;

    No* lugar_temporario = lista->inicio_lista;

    while(lugar_temporario->proximo_lista && lugar_temporario->proximo_lista->dado != valorBusca)
    {
        lugar_temporario = lugar_temporario->proximo_lista;
    }
    lugar_temporario->proximo_lista = novo_lista->proximo_lista;
    lugar_temporario->proximo_lista = novo_lista;
}

void imprimirLista(Lista* lista)
{
    No* lugar_temporario = lista->inicio_lista;

    while(lugar_temporario)
    {
        cout << lugar_temporario->dado << " ";
        lugar_temporario = lugar_temporario->proximo_lista;
    }
    cout << endl;
}

int main()
{
    Lista* lista = criarLista();

    inserirInicio(lista, 10);
    inserirFim(lista, 20);
    inserirMeio(lista, 15, 20);

    imprimirLista(lista);

    system("pause");
    return 0;
}