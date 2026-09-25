#include <iostream>
using namespace std;

#define TAMANHO_PILHA 64

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

void push(Pilha* pilha, int valor)
{
    pilha->itens[++pilha->topo_pilha] = valor;
}

int pop(Pilha* pilha)
{
    return pilha->itens[pilha->topo_pilha--];
}

// Os restos da divisão por 2 saem do bit menos significativo para o mais,
// então a pilha devolve os bits na ordem certa de leitura
void decimalParaBinario(int numero)
{
    Pilha pilha;
    inicializarPilha(&pilha);

    if (numero == 0)
    {
        cout << 0;
    }

    while (numero > 0)
    {
        push(&pilha, numero % 2);
        numero /= 2;
    }

    while (!isEmpty(&pilha))
    {
        cout << pop(&pilha);
    }
    cout << endl;
}

int main()
{
    int numero;

    cout << "\n\t Digite um número decimal (>= 0): ";
    cin >> numero;

    cout << "Binário: ";
    decimalParaBinario(numero);

    return 0;
}
