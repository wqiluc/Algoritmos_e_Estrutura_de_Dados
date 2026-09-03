#include <iostream>
#include <stdlib.h>
#include <string.h> // STRCPY
using namespace std;

typedef struct No
{
    char dado[30];
    No* proximo_pilha;
} No;


No* empilhar(No* topo_pilha, char* dado)
{
    No* novo_pilha = new No;
    strcpy(novo_pilha->dado, dado);
    novo_pilha->proximo_pilha = topo_pilha;
    return novo_pilha;
}
No* desempilhar(No* topo_pilha, char* dado)
{
    if (!topo_pilha)
    {
        cout << "Topo Vazio \n";
        return NULL;
    }

    No* lugar_temporario = topo_pilha;
    *dado = topo_pilha->dado[0];
    topo_pilha = topo_pilha->proximo_pilha;
    delete lugar_temporario;
    return topo_pilha;
}
void inverterPalavra(const char* dado)
{
    No* pilha = NULL;

    for (int i = 0; dado[i] != '\0'; i++)
    {
        char letra[2] = { dado[i], '\0' };
        pilha = empilhar(pilha, letra);
    }
    cout << "\n Palavra invertida: ";
    char c;

    while (pilha)
    {
        pilha = desempilhar(pilha, &c);
        cout << c;
    }
    cout << " \n";
}

int main()
{
    inverterPalavra("Algóritmos");
    return 0;
}