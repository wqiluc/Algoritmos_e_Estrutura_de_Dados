// QUESTÃO 1 – Busca Sequencial: Todas as Posições
//
// Modifique a busca sequencial p/ retornar todas as posições
// em que o valor procurado aparece.

// ex: {4,8,2,8,5,8,1} = valor 8; → índices 1, 3 e 5

// void buscaSequencial(int vetor[], int tamanho_vetor, int valor);
// → imprime cada posição encontrada (ou avisa que não encontrou)

// Testes:
// valor 8 → posições 1 3 5
// valor 4 → posição 0
// valor 1 → posição 6
// valor 3 → valor não encontrado!

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios sala de aula/Questao_01_Sequencial_Todas_Posicoes.cpp" -o "AV2/exércicios sala de aula/q1.out" && "./AV2/exércicios sala de aula/q1.out"

#include <iostream>
using namespace std;

#define TAMANHO_VETOR 7

int buscaSequencial(int vetor[], int tamanho_vetor, int valor)
{
    bool encontrado = false;

    int indice;

    for (indice = 0; indice < tamanho_vetor; indice++)
    {
        if (vetor[indice] == valor)
        {
            cout << "Valor encontrado na posição: " << indice << endl;
            encontrado = true;
        }
    }
    return encontrado;
}

int main()
{
    int vetor[TAMANHO_VETOR] = {4, 8, 2, 8, 5, 8, 1};
    int valor;

    cout << "Digite o valor a ser buscado: ";
    cin >> valor;

    if (!buscaSequencial(vetor, TAMANHO_VETOR, valor))
    {
        cout << "Valor não encontrado!" << endl;
    }
    else
    {
        cout << "Valor" << valor << " encontrado!" << endl;
    }

    return 0;
}