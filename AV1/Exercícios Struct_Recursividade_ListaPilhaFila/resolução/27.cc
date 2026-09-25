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

void inverterString(char palavra[])
{
    Pilha pilha;
    inicializarPilha(&pilha);

    for (int i = 0; palavra[i] != '\0'; i++)
    {
        push(&pilha, palavra[i]);
    }

    // Desempilhar devolve os caracteres na ordem inversa
    int indice_palavra = 0;
    while (!isEmpty(&pilha))
    {
        palavra[indice_palavra++] = pop(&pilha);
    }
}

int main()
{
    char palavra[TAMANHO_PILHA];

    cout << "\n\t Digite uma palavra: ";
    cin >> palavra;

    inverterString(palavra);
    cout << "Invertida: " << palavra << endl;

    return 0;
}
