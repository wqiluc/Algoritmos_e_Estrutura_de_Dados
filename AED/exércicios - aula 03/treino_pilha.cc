#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct No 
{
    char dado_pilha[30];
    No* proximo_pilha;
} No;

No* empilhar(No* topo_pilha, char dado[30])
{
    No* novo_pilha = new No;
    strcpy(novo_pilha->dado_pilha, dado);
    novo_pilha->proximo_pilha = topo_pilha;
    return novo_pilha;
}
No* desempilhar(No* topo_pilha, char dado[30])
{
    if (!topo_pilha)
    {
        return nullptr;
    }

    No* lugar_temporario = topo_pilha;
    strcpy(dado, topo_pilha->dado_pilha);
    topo_pilha = topo_pilha->proximo_pilha;
    delete lugar_temporario;
    return topo_pilha;
}

void inverterPalavra(char dado[30])
{
    No* topo_pilha = nullptr;
    char letra[30];

    for (int i = 0; dado[i] != '\0'; i++)
    {
        letra[0] = dado[i];
        letra[1] = '\0';
        topo_pilha = empilhar(topo_pilha, letra);
    }

    cout << "\n Palavra invertida: ";

    char letra_desempilhada[30];
    while (topo_pilha)
    {
        topo_pilha = desempilhar(topo_pilha, letra_desempilhada);
        cout << letra_desempilhada;
    }
    cout << "\n";
}

int main()
{
    char palavra[30];
    cout << "Digite uma palavra: ";
    cin >> palavra;
    inverterPalavra(palavra);
}