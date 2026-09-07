#include <iostream>
#include <stdlib.h>
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
    lista->inicio_lista = NULL;
    return lista;
}

void inserirInicio(Lista* lista, int valor)
{
    No* novo_lista = new No;
    novo_lista->valor = valor;
    novo_lista->proximo_lista = lista->inicio_lista;
    lista->inicio_lista = novo_lista;
}

void inserirFim(Lista* lista, int valor)
{
    No* novo_lista = new No;
    novo_lista->valor = valor;
    novo_lista->proximo_lista = NULL;

    if (!lista->inicio_lista)
    {
        lista->inicio_lista = novo_lista;
    }

    No* lugar_temporario = lista->inicio_lista;

    while (lugar_temporario->proximo_lista)
    {
        lugar_temporario = lugar_temporario->proximo_lista;
    }
    lugar_temporario->proximo_lista = novo_lista;
}

void inserirMeio(Lista* lista, int valorNovo, int valorBusca)
{
    No* novo_lista = new No;
    novo_lista->valor = valorNovo;
    novo_lista->proximo_lista = NULL;

    No* lugar_temporario = lista->inicio_lista;

    while (lugar_temporario->proximo_lista && lugar_temporario->proximo_lista->valor != valorBusca)
    {
        lugar_temporario = lugar_temporario->proximo_lista;
    }
    lugar_temporario->proximo_lista = novo_lista->proximo_lista;
    lugar_temporario->proximo_lista = novo_lista;
}

void imprimirLista(Lista* lista)
{
    No* lugar_temporario = lista->inicio_lista;

    while (lugar_temporario)
    {
        cout << lugar_temporario->valor << " <== \n";
        lugar_temporario = lugar_temporario->proximo_lista;
    }
    cout << " ";
}

int main()
{
    Lista* lista = criarLista();
    inserirInicio(lista, 10);
    inserirInicio(lista, 20);
    inserirInicio(lista, 30);
    inserirFim(lista, 40);
    inserirFim(lista, 50);
    //imprimirLista(lista);
    inserirMeio(lista, 99, 10);
    //inserirInicio(lista, 60);
    imprimirLista(lista);

    //return 0;
    system("PAUSE");
}