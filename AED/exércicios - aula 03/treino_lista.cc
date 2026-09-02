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
void inserirFinal(Lista* lista, int valor)
{
    No* novo_lista = new No;
    novo_lista->valor = valor;
    novo_lista->proximo_lista = NULL;

    if(!lista->inicio_lista)
    {
        lista->inicio_lista = novo_lista;
        return;
    }

    No* lugar_temporario = lista->inicio_lista;
    lista->inicio_lista = lista->inicio_lista->proximo_lista;

    while(lugar_temporario->proximo_lista)
        lugar_temporario = lugar_temporario->proximo_lista;
    lugar_temporario->proximo_lista = novo_lista;
}
void inserirMeio(Lista* lista, int valornovo, int valorbusca)
{
    No* novo_lista = new No;
    novo_lista->valor = valornovo;
    novo_lista->proximo_lista = NULL;

    No* lugar_temporario = lista->inicio_lista;

    while(lugar_temporario->proximo_lista && lugar_temporario->proximo_lista->valor != valorbusca)
    {
        lugar_temporario = lugar_temporario->proximo_lista;
    }
    lugar_temporario->proximo_lista = novo_lista->proximo_lista;
    lugar_temporario->proximo_lista = novo_lista;
    
}
void imprimirLista(Lista* lista)
{
    No* lugar_temporario = lista->inicio_lista;

    if(!lugar_temporario)
    {
        cout << "Lista vazia!" << endl;
        return;
    }

    while(lugar_temporario)
    {
        cout << lugar_temporario->valor << " -> ";
        lugar_temporario = lugar_temporario->proximo_lista;
    }
    cout << "NULL" << endl;
}

int main()
{
    Lista* lista = criarLista();

    inserirInicio(lista, 10);
    inserirInicio(lista, 20);
    inserirFinal(lista, 30);
    inserirMeio(lista, 25, 30);

    imprimirLista(lista);

    system("pause");
    return 0;
}