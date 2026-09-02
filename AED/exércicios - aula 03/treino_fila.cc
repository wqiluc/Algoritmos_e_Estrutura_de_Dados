#include <iostream>
#include <string.h>
using namespace std;

typedef struct No
{
    char nome[30];
    No* proximo_fila;
} No;

typedef struct Fila
{
    No* atras_fila;
    No* frente_fila;
} Fila;

Fila* criar_fila()
{
    Fila* fila = new Fila;
    fila->atras_fila = fila->frente_fila = NULL;
    return fila;
}
void enfileirar(Fila* fila, char nome[30])
{
    No* novo_fila = new No;
    strcpy(novo_fila->nome, nome);
    novo_fila->proximo_fila = NULL;

    if(!fila->atras_fila)
    {
        fila->atras_fila = fila->frente_fila = novo_fila;
    }
    else
    {
        fila->atras_fila->proximo_fila = novo_fila;
        fila->atras_fila = novo_fila;
    }
}
void desenfileirar(Fila* fila)
{
    if (!fila->frente_fila)
    {
        cout << "Fila vazia!" << endl;
        return;
    }

    No* lugar_temporario = fila->frente_fila;
    fila->frente_fila = fila->frente_fila->proximo_fila;

    if (!fila->frente_fila)
    {
        fila->atras_fila = NULL;
    }
    delete lugar_temporario;
    
}
void imprimirFila(Fila* fila)
{
    No* lugar_temporario = fila->frente_fila;

    if (!lugar_temporario)
    {
        cout << "Fila vazia!" << endl;
        return;
    }

    while (lugar_temporario)
    {
        cout << lugar_temporario->nome << endl;
        lugar_temporario = lugar_temporario->proximo_fila;
    }
    cout << "" << endl;
}

int main()
{
    Fila* fila = criar_fila();

    enfileirar(fila, "Joao");
    enfileirar(fila, "Maria");
    enfileirar(fila, "Jose");
    enfileirar(fila, "Ana");

    imprimirFila(fila);

    desenfileirar(fila);
    desenfileirar(fila);

    imprimirFila(fila);

    desenfileirar(fila);
    desenfileirar(fila);
    desenfileirar(fila);

    system("pause");
    return 0;
}