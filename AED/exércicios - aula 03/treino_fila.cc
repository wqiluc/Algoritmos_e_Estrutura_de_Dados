#include <iostream>
#include <string.h>
using namespace std;

typedef struct No 
{
    char nome[50];
    No* proximo_fila;
} No;

typedef struct 
{
    No* atras_fila;
    No* frente_fila;
} Fila;

Fila* criarFila()
{
    Fila* fila = new Fila;
    fila->frente_fila = fila->atras_fila = NULL;
    return fila;
}
void enfileirar(Fila* fila, char nome[])
{
    No* novo_fila = new No;
    strcpy(novo_fila->nome, nome);
    novo_fila->proximo_fila = NULL;

    if (!fila->atras_fila) 
    {
        fila->frente_fila = fila->atras_fila = novo_fila;
        return;
    }
    else 
    {
        fila->atras_fila->proximo_fila = novo_fila;
        fila->atras_fila = novo_fila;
    }
}
void desenfileirar(Fila* fila)
{
    if(!fila->frente_fila) 
    {
        return;
    }

    No* lugar_temporario = fila->frente_fila;
    fila->frente_fila = fila->frente_fila->proximo_fila;

    if(!fila->frente_fila) 
    {
        fila->atras_fila = NULL;
    }
    delete lugar_temporario;
}
void imprimirFila(Fila* fila)
{
    No* lugar_temporario = fila->frente_fila;

    while (lugar_temporario) 
    {
        cout << lugar_temporario->nome << " <- ";
        lugar_temporario = lugar_temporario->proximo_fila;
    }
    cout << "NULL \n";
}

int main()
{
    Fila* fila = criarFila();
    enfileirar(fila, "João");
    enfileirar(fila, "Maria");
    enfileirar(fila, "Pedro");
    imprimirFila(fila);
    desenfileirar(fila);
    imprimirFila(fila);
    desenfileirar(fila);
    imprimirFila(fila);
    desenfileirar(fila);
    imprimirFila(fila);
    return 0;
}