#include <iostream>
using namespace std;

#define TAMANHO_FILA 5

typedef struct FilaCircular
{
    int itens[TAMANHO_FILA];
    int inicio_fila;
    int fim_fila;
    int quantidade_fila;
} FilaCircular;

void inicializarFila(FilaCircular* fila)
{
    fila->inicio_fila = 0;
    fila->fim_fila = 0;
    fila->quantidade_fila = 0;
}

bool isEmpty(FilaCircular* fila)
{
    return fila->quantidade_fila == 0;
}

bool isFull(FilaCircular* fila)
{
    return fila->quantidade_fila == TAMANHO_FILA;
}

// O % faz o índice "dar a volta" no vetor, reaproveitando as posições liberadas
void enqueue(FilaCircular* fila, int valor)
{
    if (isFull(fila))
    {
        cout << "Fila cheia! ❌" << endl;
        return;
    }

    fila->itens[fila->fim_fila] = valor;
    fila->fim_fila = (fila->fim_fila + 1) % TAMANHO_FILA;
    fila->quantidade_fila++;
}

int dequeue(FilaCircular* fila)
{
    if (isEmpty(fila))
    {
        cout << "Fila vazia! ❌" << endl;
        return -1;
    }

    int valor = fila->itens[fila->inicio_fila];
    fila->inicio_fila = (fila->inicio_fila + 1) % TAMANHO_FILA;
    fila->quantidade_fila--;
    return valor;
}

void mostrarFila(FilaCircular* fila)
{
    cout << "Fila: ";
    for (int i = 0; i < fila->quantidade_fila; i++)
    {
        cout << fila->itens[(fila->inicio_fila + i) % TAMANHO_FILA] << " ";
    }
    cout << endl;
}

int main()
{
    FilaCircular fila;
    inicializarFila(&fila);

    int opcao;
    int valor;

    do
    {
        cout << "\n1 - Enqueue\n2 - Dequeue\n3 - Exibir fila\n0 - Sair\nEscolha uma opção: ";
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
                mostrarFila(&fila);
                break;
        }
    } while (opcao != 0);

    return 0;
}
