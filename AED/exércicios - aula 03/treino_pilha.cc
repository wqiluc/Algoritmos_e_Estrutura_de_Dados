#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct No 
{
    int dado;
    No* proximo_pilha;
} No;

No* empilhar(No* topo_pilha, int dado)
{
    No* novo_pilha = new No;
    novo_pilha->dado = dado;
    novo_pilha->proximo_pilha = topo_pilha;
    return novo_pilha;
}

No* desempilhar(No* topo_pilha, int dado)
{
    if(!topo_pilha)
    {
        cout << "\n\t Topo vazio❌ \n";
        return;
    }

    No* lugar_temporario = topo_pilha;
    dado = topo_pilha->dado;
    topo_pilha = topo_pilha->proximo_pilha;
    delete lugar_temporario;
    return topo_pilha;
}
void inverterPalavra(char palavra[])
{
    No* pilha = nullptr;
    int indice;

    for (indice = 0; palavra[indice] != '\0'; indice++)
    {
        pilha = empilhar(pilha, palavra[indice]);
    }

    cout << "\n\t Palavra Invertida: ";
    char invertida;

    while (pilha)
    {
        pilha = desempilhar(pilha, invertida);
        cout << invertida;
    }
    cout << "\n"; 
}

int main() 
{
    char palavra[100];
    cout << "\n Digite uma palavra: ";
    cin >> palavra;
    inverterPalavra(palavra);
    
    //return 0;
    system("PAUSE");
}