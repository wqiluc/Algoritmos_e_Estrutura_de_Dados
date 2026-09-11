// QUESTÃO 1 – Pilhas (1.0 ponto)
// Um navegador guarda em uma pilha o histórico de páginas visitadas: toda
// vez que o usuário abre uma página nova, o endereço é empilhado no topo.
// Ao clicar em "voltar", a página do topo é removida e exibida.
//
// Struct: No { string endereco; No* proximo; }  (proximo aponta para a
// página visitada anteriormente)
//
// a) Implemente `visitarPagina`, que insere um novo endereço no topo da
//    pilha (empilha).
// b) Implemente `voltar`, que remove e retorna o endereço do topo,
//    tratando o caso em que a pilha está vazia (não há para onde voltar).

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct No 
{
    char endereço;
    No* proximo_pilha;
} No;

No* empilhar(No* topo_pilha, char endereço)
{
    No* novo_pilha = new No;
    novo_pilha->endereço = endereço;
    novo_pilha->proximo_pilha = topo_pilha;
    return novo_pilha;
}

No* desempilhar(No* topo_pilha, char endereço)
{
    if (!topo_pilha)
    {
        return topo_pilha;
    }

    No* lugar_temporario = topo_pilha;
    endereço = topo_pilha->endereço;
    topo_pilha = topo_pilha->proximo_pilha;
    delete lugar_temporario;
    return topo_pilha;
}

void visitarPagina(No*& topo_pilha, char endereço)
{
    if (!topo_pilha)
    {
        cout << "Pilha vazia, criando pilha..." << endl;
    }

    topo_pilha = empilhar(topo_pilha, endereço);
}

void voltarPagina(No*& topo_pilha)
{
    if (!topo_pilha)
    {
        cout << "Erro: nao há página para voltar." << endl;
        return;
    }

    char endereço = topo_pilha->endereço;
    topo_pilha = desempilhar(topo_pilha, endereço);
    cout << "Voltando para: " << endereço << endl;
}