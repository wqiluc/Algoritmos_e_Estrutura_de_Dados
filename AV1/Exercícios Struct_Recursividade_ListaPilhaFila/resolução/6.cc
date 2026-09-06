#include <iostream>
using namespace std;

typedef struct Livro
{
    char titulo_livro[50];
    char autor_livro[50];
    int ano_publicacao_livro;
} Livro;

void cadastrarLivro(Livro* livro, int indice_livro)
{
    cout << "\nDigite o título do " << indice_livro + 1 << "º Livro: ";
    cin >> livro->titulo_livro;

    cout << "Digite o autor do " << indice_livro + 1 << "º Livro: ";
    cin >> livro->autor_livro;

    cout << "Digite o ano de publicação do " << indice_livro + 1 << "º Livro: ";
    cin >> livro->ano_publicacao_livro;
}

void exibirLivro(Livro* livro)
{
    cout << "\nTítulo: " << livro->titulo_livro << endl;
    cout << "Autor: " << livro->autor_livro << endl;
    cout << "Ano: " << livro->ano_publicacao_livro << endl;
}

int main()
{
    int quantidade_livros;

    cout << "Digite a quantidade de livros: ";
    cin >> quantidade_livros;

    Livro* livros = new Livro[quantidade_livros];

    for (int indice_livro = 0; indice_livro < quantidade_livros; indice_livro++)
    {
        cadastrarLivro(&livros[indice_livro], indice_livro);
    }

    int ano_referencia;
    cout << "\nDigite o ano de referência: ";
    cin >> ano_referencia;

    cout << "\nLivros publicados após " << ano_referencia << ":" << endl;

    for (int indice_livro = 0; indice_livro < quantidade_livros; indice_livro++)
    {
        if (livros[indice_livro].ano_publicacao_livro > ano_referencia)
        {
            exibirLivro(&livros[indice_livro]);
        }
    }

    return 0;
}