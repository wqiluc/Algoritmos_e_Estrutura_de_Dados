#include <iostream>
#include <string.h>
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
        return NULL;

    No* lugar_temporario = topo_pilha;
    strcpy(dado, topo_pilha->dado);
    topo_pilha = topo_pilha->proximo_pilha;
    delete lugar_temporario; 
    return topo_pilha;
}

void inverterPalvra(char palavra[])
{
    No* pilha = NULL;
    int indice;

    for (indice = 0; palavra[indice] != '\0'; indice++)
    {
        pilha = empilhar(pilha, &palavra[indice]);
    }

    cout << "\n Palavra invertida: ";
    char palavra_invertida[30];
    int indice_invertida = 0;

    while (pilha) 
    {
        pilha = desempilhar(pilha, &palavra_invertida[indice_invertida]);
        indice_invertida++;
    }
    palavra_invertida[indice_invertida] = '\0';
    cout << palavra_invertida;
}

void imprimirPilha(No* topo_pilha) 
{
    cout << "\n Pilha: ";

    while (topo_pilha) 
    {
        cout << topo_pilha->dado << " ";
        topo_pilha = topo_pilha->proximo_pilha;
    }
    cout << "\n";
}

int main()
{
    char palavra[30];
    cout << "\n Digite uma palavra: ";
    cin >> palavra;

    No* pilha = NULL;
    
    for (int indice = 0; palavra[indice] != '\0'; indice++)
        pilha = empilhar(pilha, &palavra[indice]);

    imprimirPilha(pilha);

    inverterPalvra(palavra);

    //return 0;
    system("PAUSE");
}