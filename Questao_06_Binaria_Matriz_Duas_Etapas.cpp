// QUESTÃO 6 – Busca Binária: Matriz em Duas Etapas
//
// Um depósito guarda produtos em prateleiras. Cada LINHA é uma prateleira com os
// códigos dos produtos em ordem crescente, e cada prateleira começa com um código
// maior que o último da prateleira anterior (igual à matriz da Questão 3).
//
//                 col 0  col 1  col 2  col 3  col 4  col 5
// prateleira 0      3      5      8     11     14     17
// prateleira 1     20     22     27     31     35     38
// prateleira 2     41     44     46     50     53     59
// prateleira 3     62     65     70     71     77     80
// prateleira 4     84     88     90     93     97     99
//
// Desta vez NÃO use o truque do índice único (meio / COLUNAS, meio % COLUNAS).
// Faça a busca em DUAS etapas:
//
// Etapa 1 – descobrir a prateleira:
// int buscarLinha(int matriz[][COLUNAS], int valor, int &passos);
//    → busca binária só na COLUNA 0 (o primeiro código de cada prateleira)
//    → procura a ÚLTIMA linha cujo primeiro código é <= valor
//      (quando matriz[meio][0] <= valor: guarda meio e vai para a DIREITA;
//       senão: vai para a ESQUERDA)
//    → retorna a linha, ou -1 se o valor for menor que matriz[0][0]
//
// Etapa 2 – procurar dentro da prateleira:
// int buscarNaLinha(int matriz[][COLUNAS], int linha, int valor, int &passos);
//    → busca binária normal só naquela linha
//    → retorna a coluna, ou -1
//
// bool buscaDuasEtapas(int matriz[][COLUNAS], int valor, int &linha, int &coluna);
//    → chama as duas etapas (se a etapa 1 der -1, nem faz a etapa 2)
//    → imprima, a cada passo: a etapa, inicio, fim, meio e a célula visitada
//    → no final, mostre o total de passos (etapa 1 + etapa 2)
//
// Use #define LINHAS 5 e #define COLUNAS 6.
// No main, leia o valor do teclado e mostre o resultado.
//
// Testes:
// valor 50 → linha 2, coluna 3 (2 + 3 = 5 passos)
//   [etapa 1] inicio=0 fim=4 meio=2 → [2][0] = 41 → <= 50, guarda 2, direita
//   [etapa 1] inicio=3 fim=4 meio=3 → [3][0] = 62 → > 50, esquerda → prateleira 2
//   [etapa 2] inicio=0 fim=5 meio=2 → [2][2] = 46 → menor, direita
//   [etapa 2] inicio=3 fim=5 meio=4 → [2][4] = 53 → maior, esquerda
//   [etapa 2] inicio=3 fim=3 meio=3 → [2][3] = 50 → achou!
// valor 3   → linha 0, coluna 0 (3 + 2 = 5 passos)
// valor 62  → linha 3, coluna 0 (3 + 2 = 5 passos)
// valor 17  → linha 0, coluna 5 (3 + 3 = 6 passos)
// valor 99  → linha 4, coluna 5 (3 + 3 = 6 passos)
// valor 1   → não encontrado    (etapa 1 dá -1 em 2 passos, nem entra na etapa 2)
// valor 40  → não encontrado    (etapa 1 aponta a prateleira 1, etapa 2 não acha: 3 + 3)
// valor 100 → não encontrado    (etapa 1 aponta a prateleira 4, etapa 2 não acha: 3 + 3)
//
// Perguntas:
// 1) A etapa 1 sempre roda até inicio > fim, mesmo quando acha o valor exato
//    na coluna 0 (veja o valor 62). Por quê?
// 2) Compare com a Questão 3: as duas são O(log(LINHAS * COLUNAS))? Qual faz
//    menos passos no pior caso para esta matriz 5x6?
// 3) Se cada prateleira tivesse uma quantidade DIFERENTE de produtos, qual das
//    duas abordagens continuaria funcionando? Por quê?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "Questao_06_Binaria_Matriz_Duas_Etapas.cpp" -o q6.out && ./q6.out

#include <iostream>
using namespace std;

#define LINHAS 5
#define COLUNAS 6

// suas funções aqui

int main()
{
    int matriz[LINHAS][COLUNAS] =
    {
        {3, 5, 8, 11, 14, 17},
        {20, 22, 27, 31, 35, 38},
        {41, 44, 46, 50, 53, 59},
        {62, 65, 70, 71, 77, 80},
        {84, 88, 90, 93, 97, 99}
    };

    // sua solução aqui

    return 0;
}
