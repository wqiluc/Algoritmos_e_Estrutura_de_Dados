#include <iostream>
//#include <stdlib.h>
using namespace std;

typedef struct No
{
    int valor;
    No* prox;
} No;

typedef struct Lista
{
    No* inicio;
} Lista;

Lista* criarLista()
{
    Lista* l = new Lista; 
    l->inicio = NULL;
    return l;
}

void inserirInicio(Lista* lista, int valor)
{
    No* novo = new No;
    novo->valor = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}


void inserirFim(Lista* lista, int valor)
{
    No* novo = new No;
    novo->valor = valor;
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


void inserirMeio(Lista* lista, int valorNovo, int valorBusca)
{
    No* novo = new No;
    novo->valor = valorNovo;

    No* temp = lista->inicio;

    while (temp->prox && temp->prox->valor != valorBusca)
    {
        temp = temp->prox;
    }
    
    temp->prox = novo->prox; 
    temp->prox = novo;
}

void imprimirLista(Lista* lista)
{
    No* temp = lista->inicio;

    while (temp)
    {
        cout << temp->valor << " -> ";
        temp = temp->prox;
    }
    cout << "NULL \n";
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