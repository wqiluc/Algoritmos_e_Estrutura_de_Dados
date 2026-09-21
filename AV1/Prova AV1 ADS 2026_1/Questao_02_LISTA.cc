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
    lista->inicio_lista = nullptr;
    return lista;
}

void inserirFinalLista(Lista* lista, int valor)
{
    No* novo_lista = new No;
    novo_lista->valor = valor;
    novo_lista->proximo_lista = nullptr;

    if(!lista->inicio_lista)
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

int contagemNumerosLista(No* no_lista, int valor, int contador_lista)
{
    if (!no_lista)
    {
        return contador_lista;
    }

    if (no_lista->valor == valor)
    {
        contador_lista++;
    }

    return contagemNumerosLista(no_lista->proximo_lista, valor, contador_lista);
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

int main()
{
    Lista* lista = criarLista();
    int valores[] = {5, 8, 5, 10, 8, 12, 5};
    int quantidade_valores = 7;

    for (int i = 0; i < quantidade_valores; i++)
    {
        inserirFinalLista(lista, valores[i]);
    }

    cout << "Lista após inserção: ";
    mostrarLista(lista);

    int valor_procurado;
    cout << "Digite um valor para contar quantas vezes ele aparece na lista: ";
    cin >> valor_procurado;

    int total = contagemNumerosLista(lista->inicio_lista, valor_procurado, 0);
    cout << "O valor " << valor_procurado << " aparece " << total << " vezes na lista." << endl;

    return 0;
}