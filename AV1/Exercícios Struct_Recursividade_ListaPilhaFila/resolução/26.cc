#include <iostream>
#include <cstring>
using namespace std;

#define TAMANHO_PILHA 100

typedef struct Pilha
{
    char itens[TAMANHO_PILHA];
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

void push(Pilha* pilha, char caractere)
{
    pilha->itens[++pilha->topo_pilha] = caractere;
}

char pop(Pilha* pilha)
{
    return pilha->itens[pilha->topo_pilha--];
}

// Cada '(' é empilhado; cada ')' precisa desempilhar um '(' correspondente
bool parentesesBalanceados(char expressao[])
{
    Pilha pilha;
    inicializarPilha(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++)
    {
        if (expressao[i] == '(')
        {
            push(&pilha, '(');
        }
        else if (expressao[i] == ')')
        {
            if (isEmpty(&pilha))
            {
                return false;
            }
            pop(&pilha);
        }
    }

    return isEmpty(&pilha);
}

int main()
{
    char expressao[TAMANHO_PILHA];

    cout << "\n\t Digite a expressão: ";
    cin >> expressao;

    cout << (parentesesBalanceados(expressao) ? "Válido" : "Inválido") << endl;

    return 0;
}
