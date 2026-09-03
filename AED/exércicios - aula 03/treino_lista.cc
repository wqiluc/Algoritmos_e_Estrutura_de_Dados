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

Lista* criarlista()
{
    Lista* lista = new Lista;
    lista->inicio_lista = NULL;
    return lista;
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
        return;
    }

    No* lugar_temporario = lista->inicio_lista;

    while (lugar_temporario)
    {
        lugar_temporario = lugar_temporario->proximo_lista;
    }
    delete lugar_temporario;
}
void inserirMeio(Lista* lista, int dadoNovo, int dadoBusca)
{
    No* novo_lista = new No;
    novo_lista->dado = dadoNovo;
    novo_lista->proximo_lista = NULL;

    No* lugar_temporario = lista->inicio_lista;

    while (lugar_temporario->proximo_lista && lugar_temporario->proximo_lista->dado != dadoBusca)
    {
        lugar_temporario = lugar_temporario->proximo_lista;
    }
    lugar_temporario->proximo_lista = novo_lista->proximo_lista;
    lugar_temporario->proximo_lista = novo_lista;
    
}
void imprimirLista(Lista* lista)
{
    No* lugar_temporario = lista->inicio_lista;

    if (!lista->inicio_lista)
    {
        cout << "Lista Vazia❌ \n";
        return;
    }

    while (lugar_temporario)
    {
        cout << lugar_temporario->dado << " <== \n";
        lugar_temporario = lugar_temporario->proximo_lista;
    }
    cout << " NULL \n";
}

int main()
{
    Lista* lista = criarlista();
    inserirInicio(lista, 10);
    inserirInicio(lista, 20);
    inserirInicio(lista, 30);
    inserirInicio(lista, 40);
    inserirFinal(lista, 50);
    inserirMeio(lista, 90, 50);

    imprimirLista(lista);

    system("PAUSE");
    return 0;
}