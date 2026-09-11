#include <iostream>
using namespace std;

typedef struct No
{
    int senha;
    No* proximo_fila;
} No;

typedef struct Fila
{
    No* atras_fila;
    No* frente_fila;
} Fila;

void entrarnaFila(Fila* fila, int senha)
{
    No* novo_fila = new No;
    novo_fila->senha = senha;
    novo_fila->proximo_fila = nullptr;

    if (!fila->atras_fila)
    {
        fila->atras_fila = fila->frente_fila = novo_fila;
    }
    fila->atras_fila->proximo_fila = novo_fila;
    fila->atras_fila = novo_fila;
}

void chamarProximo(Fila* fila, int senha)
{
    if (!fila->frente_fila)
    {
        return;
    }

    No* lugar_temporario = fila->frente_fila;
    fila->frente_fila = fila->frente_fila->proximo_fila;

    if (!fila->frente_fila)
    {
        fila->atras_fila = nullptr;
    }
    delete lugar_temporario;
}

int pessoasnaFila(No* novo_fila)
{
    if (!novo_fila)
    {
        return 0;
    }
    return 1 + pessoasnaFila(novo_fila->proximo_fila);
}

int main()
{
    Fila* fila = new Fila;
    fila->atras_fila = fila->frente_fila = nullptr;

    entrarnaFila(fila, 101);
    entrarnaFila(fila, 102);
    entrarnaFila(fila, 103);

    cout << "Pessoas na fila: " << pessoasnaFila(fila->frente_fila) << "\n";

    chamarProximo(fila, 0);

    cout << "Pessoas na fila: " << pessoasnaFila(fila->frente_fila) << "\n";
}