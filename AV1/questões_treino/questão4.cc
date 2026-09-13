// QUESTÃO 4 – Árvore Binária de Busca (2.0 pontos)
// Um mercado organiza o estoque em uma Árvore Binária de Busca (ABB), na
// qual cada nó guarda o código de barras de um produto.
//
// a) Construa a ABB inserindo, nesta ordem, os códigos:
//    50, 30, 70, 20, 40, 60, 80
//
// b) Implemente `buscarProduto`, que informa (true/false) se um
//    determinado código existe no estoque.
//
// c) Implemente `listarEmOrdemCrescente` (percurso em-ordem), que imprime
//    os códigos do menor para o maior — útil para gerar um relatório de
//    inventário.
//
// d) Implemente `contarProdutos`, uma função RECURSIVA que conta quantos
//    nós (produtos) existem na árvore.
//
// e) O produto de código 70 saiu de linha — repare que ele tem DOIS
//    filhos (60 e 80). Implemente a remoção desse nó da ABB, tratando os
//    três casos possíveis (nó folha, nó com um filho, nó com dois
//    filhos).

#include <iostream>
using namespace std;

typedef struct No
{
    int codigo;
    No* esquerda_arvore;
    No* direita_arvore;
} No;

No* criarNo(int codigo)
{
    No* novo_no = new No;
    novo_no->codigo = codigo;
    novo_no->esquerda_arvore = NULL;
    novo_no->direita_arvore = NULL;
    return novo_no;
}