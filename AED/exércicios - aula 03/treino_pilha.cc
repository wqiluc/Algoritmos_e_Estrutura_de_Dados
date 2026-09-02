#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

typedef struct No
{
    char dado[30];
    No* prox;
} No;

No* empilharPilha(No* topo_pilha, char dado[])
{
    No* novo = new No;
    strcpy(novo->dado, dado);
    novo->prox = topo_pilha;
    return novo;
}

No* desempilharPilha(No* topo_pilha, char dado[])
{
    if (!topo_pilha) 
    {
        cout << "\n Pilha vazia! \n";
        return NULL;
    }

    No* lugar_temporario = topo_pilha;
    strcpy(dado, topo_pilha->dado);
    topo_pilha = topo_pilha->prox;
    delete lugar_temporario;
    return topo_pilha;
}

No* empilharPalavra(char palavra[])
{
    No* pilha = NULL;

    for (int indice = 0; palavra[indice] != '\0'; indice++)
    {
        char letra[2] = {palavra[indice], '\0'};
        pilha = empilharPilha(pilha, letra);
    }

    return pilha;
}

void imprimirInvertida(No* pilha)
{
    cout << "\n Palavra invertida: ";
    char letra[2];

    while (pilha)
    {
        pilha = desempilharPilha(pilha, letra);
        cout << letra;
    }
    cout << "\n";
}

void imprimirPilha(No* topo_pilha)
{
    if (!topo_pilha) 
    {
        cout << "\n Pilha vazia! \n";
        return;
    }

    cout << "\n Elementos da pilha: ";
    No* lugar_temporario = topo_pilha;

    while (lugar_temporario)
    {
        cout << lugar_temporario->dado << " ";
        lugar_temporario = lugar_temporario->prox;
    }
    cout << "\n";
}

int main()
{
    char palavra[100];
    cout << "\n Digite uma palavra: ";
    cin >> palavra;

    No* pilha = empilharPalavra(palavra);

    cout << "\n A palavra foi armazenada na pilha. Agora vamos imprimir a pilha:\n";
    imprimirPilha(pilha);

    imprimirInvertida(pilha);

    system("PAUSE");
    return 0;
}