#include <iostream>
using namespace std;

#define TAMANHO_FILA 100

typedef struct Fila
{
    int itens[TAMANHO_FILA];
    int inicio_fila;
    int fim_fila;
} Fila;

void inicializarFila(Fila* fila)
{
    fila->inicio_fila = 0;
    fila->fim_fila = 0;
}

bool isEmpty(Fila* fila)
{
    return fila->inicio_fila == fila->fim_fila;
}

void enqueue(Fila* fila, int valor)
{
    if (fila->fim_fila == TAMANHO_FILA)
    {
        cout << "Fila cheia! ❌" << endl;
        return;
    }

    fila->itens[fila->fim_fila++] = valor;
}

int dequeue(Fila* fila)
{
    if (isEmpty(fila))
    {
        cout << "Fila vazia! ❌" << endl;
        return -1;
    }

    return fila->itens[fila->inicio_fila++];
}

int front(Fila* fila)
{
    if (isEmpty(fila))
    {
        cout << "Fila vazia! ❌" << endl;
        return -1;
    }

    return fila->itens[fila->inicio_fila];
}

int main()
{
    Fila fila;
    inicializarFila(&fila);

    int opcao;
    int valor;

    do
    {
        cout << "\n1 - Enqueue\n2 - Dequeue\n3 - Front\n4 - Está vazia?\n0 - Sair\nEscolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                cout << "Digite o valor: ";
                cin >> valor;
                enqueue(&fila, valor);
                break;
            case 2:
                if (!isEmpty(&fila))
                {
                    cout << "Removido: " << dequeue(&fila) << endl;
                }
                else
                {
                    dequeue(&fila);
                }
                break;
            case 3:
                if (!isEmpty(&fila))
                {
                    cout << "Primeiro: " << front(&fila) << endl;
                }
                else
                {
                    front(&fila);
                }
                break;
            case 4:
                cout << (isEmpty(&fila) ? "A fila está vazia." : "A fila NÃO está vazia.") << endl;
                break;
        }
    } while (opcao != 0);

    return 0;
}
