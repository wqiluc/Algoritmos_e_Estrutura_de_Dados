/*
 * Crie um programa que leia a venda de 10 produtos (use um vetor). De cada produto
 * queremos saber o nome, preço, quantidade de um produto vendido, e mostre também o
 * valor total das vendas. Use structs para estruturar os dados.
 */

#include <array>
#include <iostream>
#include <string>

constexpr int TOTAL_PRODUTOS = 10;

struct Produto
{
    std::string nome;
    float preco;
    int quantidade;
    float total_vendas;
};

int main(void)
{
    std::array<Produto, TOTAL_PRODUTOS> produtos;
    float valor_total_vendas = 0.0;

    for (int indice_produto = 0; indice_produto < TOTAL_PRODUTOS; indice_produto++)
    {
        Produto &produto = produtos[indice_produto];

        std::cout << "\n\t Digite o nome do produto " << indice_produto + 1 << ": ";
        std::getline(std::cin >> std::ws, produto.nome);

        std::cout << "\n\t Digite o preço do produto " << indice_produto + 1 << ": ";
        std::cin >> produto.preco;

        std::cout << "\n\t Digite a quantidade vendida do produto " << indice_produto + 1 << ": ";
        std::cin >> produto.quantidade;

        produto.total_vendas = produto.preco * produto.quantidade;
        valor_total_vendas += produto.total_vendas;
    }

    std::cout << "\n\t Resumo das vendas:\n";

    for (const Produto &produto : produtos)
    {
        std::cout  
            << "\n\t Produto: " << produto.nome 
            << " | Preço: " << produto.preco
            << " | Quantidade: " << produto.quantidade
            << " | Total Vendas: R$" << produto.total_vendas << "\n";
    }

    std::cout << "\n\t Valor total das vendas: R$" << valor_total_vendas << "\n";
    return 0;
}