#include <iostream>
#include <string.h>

using namespace std;

typedef struct No
{
    char nome[30];
    No* proximo;
} No;

typedef struct Fila
{
    No* frente_fila;
    No* atras_fila;
} Fila;

Fila* criarfila()
{
    Fila* fila = new Fila;
    fila->frente_fila = fila->atras_fila = NULL;
    return fila;
}

void enfileirar(Fila* fila, const char nome[])
{
    No* no_novo = new No;
    strcpy(no_novo->nome, nome);
    no_novo->proximo = NULL;
    
    if(!fila->atras_fila)
    {
        fila->atras_fila = fila->frente_fila = no_novo;
        return;
    }
    else
    {
        fila->atras_fila->proximo = no_novo;
        fila->atras_fila = no_novo;
    }
}

void desenfileirar(Fila* fila)
{
    if(!fila->frente_fila)
    {
        return;
    }

    No* temporaria = fila->frente_fila;
    fila->frente_fila = fila->frente_fila->proximo;

    if(!fila->frente_fila)
    {
        fila->atras_fila = NULL;
    }
    delete temporaria;
}

void imprimirFila(Fila* fila) 
{
    No* temporaria = fila->frente_fila;
    while (temporaria) 
    {
        cout << temporaria->nome << " <- ";
        temporaria = temporaria->proximo;
    }
    cout << "NULL \n";
}

int main() 
{
    Fila* fila = criarfila();
    enfileirar(fila, "Ana");
    enfileirar(fila, "Bruno");
    enfileirar(fila, "Carlos");
    imprimirFila(fila);

    desenfileirar(fila);
    imprimirFila(fila);

    //return 0;
    system("PAUSE");
}