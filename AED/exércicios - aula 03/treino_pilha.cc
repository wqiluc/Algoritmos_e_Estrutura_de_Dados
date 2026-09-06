#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct No 
{
    int valor;
    No* proximo_pilha;
} No;

No* empilhar(No* topo_pilha, int valor)
{
    No* novo_pilha = new No;
    novo_pilha->valor = valor;
    novo_pilha->proximo_pilha = topo_pilha;
    return novo_pilha;
}
No* desempilhar(No* topo_pilha, int valor)
{
    if (!topo_pilha)
    {
        return NULL;
    }

    No* lugar_temporario = topo_pilha;
    valor = topo_pilha->valor;
    topo_pilha = topo_pilha->proximo_pilha;
    delete lugar_temporario;
    return topo_pilha;
}
void inverterPalavra(char palavra[])
{
    No* pilha = nullptr;
    int indice_pilha;

    for (indice_pilha = 0; palavra[indice_pilha] != '\0'; indice_pilha++)
    {
        pilha = empilhar(pilha, palavra[indice_pilha]);
    }

    cout << "\n\t Palavra Invertida: ";
    char palavra_invertida;

    while (pilha)
    {
        pilha = desempilhar(pilha, palavra_invertida);
        cout << palavra_invertida;
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