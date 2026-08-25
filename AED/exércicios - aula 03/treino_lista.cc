#include <iostream>
// #include <stdlib.h>
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

Lista* criarlista()
{
   Lista* lista = new Lista;
   lista->inicio_lista = NULL;
   return (lista);
}
void inserirInicio(Lista* lista, int dado)
{
    No* novo_lista = new No;
    novo_lista->dado = dado;
    novo_lista->proximo_lista = lista->inicio_lista;
    lista->inicio_lista = novo_lista;
}

void inserirFinal(Lista* lista, int dado)
{
    No* novo_lista = new No;
    novo_lista->dado = dado;
    novo_lista->proximo_lista = NULL;

    if (!lista->inicio_lista)
    {
        lista->inicio_lista = novo_lista;
    }

    No* lugar_temporario = lista->inicio_lista;

    while (lugar_temporario)
    {
        lugar_temporario = lugar_temporario->proximo_lista;
    }
    lugar_temporario->proximo_lista = novo_lista;
}

void inserirMeio(Lista* lista, int valornovo, int valorbusca)
{
    No* novo_lista = new No;
    novo_lista->dado = valornovo;

    No* lugar_temporario = lista->inicio_lista;

    while (lugar_temporario->proximo_lista && lugar_temporario->proximo_lista->dado != valorbusca)
    {
        lugar_temporario = lugar_temporario->proximo_lista;
    }
    novo_lista->proximo_lista = lugar_temporario->proximo_lista;
    lugar_temporario->proximo_lista = novo_lista;
}
void imprimirLista(Lista* lista)
{
    No* lugar_temporario = lista->inicio_lista;

    while (lugar_temporario)
    {
        cout << lugar_temporario->dado << " <== \n";
        lugar_temporario = lugar_temporario->proximo_lista;
    }
    cout << " <== \n";
}

int main()
{
    Lista* lista = criarlista();
    inserirInicio(lista, 10);
    inserirInicio(lista, 20);
    inserirInicio(lista, 30);

    inserirMeio(lista, 40, 50);
    inserirFinal(lista, 90);

    imprimirLista(lista);

    system("PAUSE");
}