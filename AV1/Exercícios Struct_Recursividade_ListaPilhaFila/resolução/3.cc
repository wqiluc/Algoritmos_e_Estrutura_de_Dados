#include <iostream>
using namespace std;

typedef struct Produto
{
    char nome_produto[30];
    int codigo_produto;
    float preco_produto;
} Produto;

void exibirProduto(int indice_produto)
{
    static Produto produtos[5];
    int indice_produto;

        for (indice_produto = 0; indice_produto < 5; indice_produto++)
        {
            cout << "\nDigite o nome do produto " << indice_produto + 1 << ": ";
            cin >> produtos[indice_produto].nome_produto;
            cout << "Digite o código do produto " << indice_produto + 1 << ": ";
            cin >> produtos[indice_produto].codigo_produto;
            cout << "Digite o preço do produto " << indice_produto + 1 << ": ";
            cin >> produtos[indice_produto].preco_produto;
        }

    cout << "\nNome do produto: " << produtos[indice_produto].nome_produto << endl;
    cout << "Código do produto: " << produtos[indice_produto].codigo_produto << endl;
    cout << "Preço do produto: R$ " << produtos[indice_produto].preco_produto << endl;
}

int main()
{
    int indice_produtos;

    for (indice_produtos = 0; indice_produtos < 5; indice_produtos++)
    {
        exibirProduto(indice_produtos);
    }

    return 0;
}