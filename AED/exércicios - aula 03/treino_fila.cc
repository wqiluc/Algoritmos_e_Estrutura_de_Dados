#include <iostream>
#include <string.h>
using namespace std;

typedef struct No 
{
    char nome[30];
    No* proximo_fila;
} Fila;

typedef struct Fila 
{
    No* frente_fila;
    No* atras_fila;
} Fila;

Fila* criarFila()
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

    if (!fila->atras_fila)
    {
        fila->atras_fila = fila->frente_fila = novo_fila;
        return;
    }
    else
    {
        fila->atras_fila->proximo_fila = novo_fila;
        fila->frente_fila = novo_fila;
    }
}
void desenfileirar(Fila* fila)
{
    if(!fila->frente_fila)
    {
        cout << "Fila Vazia \n";
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

    while (lugar_temporario)
    {
        cout << lugar_temporario->nome << " <== \n";
        lugar_temporario = lugar_temporario->proximo_fila;
    }
    cout << " NULL\n";
}

int main()
{
    Fila* fila = criarFila();
    enfileirar(fila, "Ana");
    enfileirar(fila, "Bruno");
    enfileirar(fila, "Carlos");
    imprimirFila(fila);

    desenfileirar(fila);
    imprimirFila(fila);

    //return 0;
    system("PAUSE");
}