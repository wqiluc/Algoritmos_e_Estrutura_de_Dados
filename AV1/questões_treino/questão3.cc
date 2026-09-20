// QUESTÃO 01 – Grupo (2,0 pontos)
// Implemente uma função que receba duas filas de números inteiros e crie uma
// terceira fila intercalando seus elementos. A função deve começar pela
// primeira fila e continuar inserindo os elementos restantes quando uma das
// filas terminar. As filas originais não podem ser alteradas.
// Exemplo: F1 = [10, 30, 50] e F2 = [20, 40] → resultado = [10, 20, 30, 40, 50].
// Assinatura sugerida: Fila* intercalarFilas(Fila* F1, Fila* F2);

#include <iostream>
using namespace std;

typedef struct No
{
    int valor;
    No* proximo_fila;
} No;

typedef struct Fila
{
    No* atras_fila;
    No* frente_fila;
} Fila;

Fila* criarFila()
{
    Fila* fila = new Fila;
    fila->atras_fila = fila->frente_fila = nullptr;
    return fila;
}

void enfileirar(Fila* fila, int valor)
{
    No* novo_fila = new No;
    novo_fila->valor = valor;
    novo_fila->proximo_fila = nullptr;

    if (!fila->atras_fila)
    {
        fila->atras_fila = fila->frente_fila = novo_fila;
        return;
    }
    fila->atras_fila->proximo_fila = novo_fila;
    fila->atras_fila = novo_fila;
}

Fila* intercalarFilas(Fila* F1, Fila* F2)
{
    Fila* resultado = criarFila();
    No* p1 = F1->frente_fila;
    No* p2 = F2->frente_fila;

    while (p1 && p2)
    {
        enfileirar(resultado, p1->valor);
        enfileirar(resultado, p2->valor);
        p1 = p1->proximo_fila;
        p2 = p2->proximo_fila;
    }

    while (p1)
    {
        enfileirar(resultado, p1->valor);
        p1 = p1->proximo_fila;
    }

    while (p2)
    {
        enfileirar(resultado, p2->valor);
        p2 = p2->proximo_fila;
    }

    return resultado;
}

void imprimirFila(Fila* fila)
{
    No* lugar_temporario = fila->frente_fila;

    while (lugar_temporario)
    {
        cout << lugar_temporario->valor << " <== ";
        lugar_temporario = lugar_temporario->proximo_fila;
    }
    cout << "NULL\n";
}

int main()
{
    Fila* F1 = criarFila();
    enfileirar(F1, 10);
    enfileirar(F1, 30);
    enfileirar(F1, 50);

    Fila* F2 = criarFila();
    enfileirar(F2, 20);
    enfileirar(F2, 40);

    Fila* resultado = intercalarFilas(F1, F2);

    cout << "F1: ";
    imprimirFila(F1);
    cout << "F2: ";
    imprimirFila(F2);
    cout << "Resultado: ";
    imprimirFila(resultado);
}
