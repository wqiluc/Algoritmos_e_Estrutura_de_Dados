/*
 * Crie um programa que leia a venda de 10 produtos (use um vetor). De cada produto
 * queremos saber o nome, preço, quantidade de um produto vendido, e mostre também o
 * valor total das vendas. Use structs para estruturar os dados.
 */

#include <stdio.h>

#define TOTAL_PRODUTOS 10
#define MAX_NOME_PRODUTO 50

typedef struct Produto
{
    char nome[MAX_NOME_PRODUTO];
    float preco;
    int quantidade;
    struct 
    {
        float total_vendas;
    } vendas;
} Produto;

int main()
{
    Produto produtos[TOTAL_PRODUTOS];
    float valor_total_vendas = 0.0;
    int indice_produto;

    for (indice_produto = 0; indice_produto < TOTAL_PRODUTOS; indice_produto++)
    {
        printf("\n\t Digite o nome do produto %d: ", indice_produto + 1);
        scanf(" %[^\n]", produtos[indice_produto].nome);

        printf("\n\t Digite o preço do produto %d: ", indice_produto + 1);
        scanf("%f", &produtos[indice_produto].preco);

        printf("\n\t Digite a quantidade vendida do produto %d: ", indice_produto + 1);
        scanf("%d", &produtos[indice_produto].quantidade);

        produtos[indice_produto].vendas.total_vendas 
        = produtos[indice_produto].preco * produtos[indice_produto].quantidade;

        valor_total_vendas += produtos[indice_produto].vendas.total_vendas;
    }

    printf("\n\t Resumo das vendas: \n");

    for (indice_produto = 0; indice_produto < TOTAL_PRODUTOS; indice_produto++)
    {
        printf("\n\t Produto: %s | Preço: %.2f | Quantidade: %d | Total Vendas: R$%.2f\n",
               produtos[indice_produto].nome, produtos[indice_produto].preco, produtos[indice_produto].quantidade, produtos[indice_produto].vendas.total_vendas);
    }

    printf("\n\t Valor total das vendas: R$%.2f\n", valor_total_vendas);

    return 0;
}