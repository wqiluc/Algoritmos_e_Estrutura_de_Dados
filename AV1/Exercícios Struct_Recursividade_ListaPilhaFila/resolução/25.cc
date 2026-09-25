#include <iostream>
using namespace std;

#define TAMANHO_PILHA 100

typedef struct Pilha
{
    int itens[TAMANHO_PILHA];
    int topo_pilha;
} Pilha;

void inicializarPilha(Pilha* pilha)
{
    pilha->topo_pilha = -1;
}

bool isEmpty(Pilha* pilha)
{
    return pilha->topo_pilha == -1;
}

bool isFull(Pilha* pilha)
{
    return pilha->topo_pilha == TAMANHO_PILHA - 1;
}

void push(Pilha* pilha, int valor)
{
    if (isFull(pilha))
    {
        cout << "Pilha cheia! ❌" << endl;
        return;
    }

    pilha->itens[++pilha->topo_pilha] = valor;
}

int pop(Pilha* pilha)
{
    if (isEmpty(pilha))
    {
        cout << "Pilha vazia! ❌" << endl;
        return -1;
    }

    return pilha->itens[pilha->topo_pilha--];
}

int top(Pilha* pilha)
{
    if (isEmpty(pilha))
    {
        cout << "Pilha vazia! ❌" << endl;
        return -1;
    }

    return pilha->itens[pilha->topo_pilha];
}

int main()
{
    Pilha pilha;
    inicializarPilha(&pilha);

    int opcao;
    int valor;

    do
    {
        cout << "\n1 - Push\n2 - Pop\n3 - Top\n4 - Está vazia?\n0 - Sair\nEscolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                cout << "Digite o valor: ";
                cin >> valor;
                push(&pilha, valor);
                break;

            case 2:

                if (!isEmpty(&pilha))
                {
                    cout << "Removido: " << pop(&pilha) << endl;
                }

                else
                {
                    pop(&pilha);
                }

                break;

            case 3:

                if (!isEmpty(&pilha))
                {
                    cout << "Topo: " << top(&pilha) << endl;
                }

                else
                {
                    top(&pilha);
                }

                break;

            case 4:

                cout << (isEmpty(&pilha) ? "A pilha está vazia." : "A pilha NÃO está vazia.") << endl;
                break;
        }
    } 
    while (opcao != 0);
    return 0;
}