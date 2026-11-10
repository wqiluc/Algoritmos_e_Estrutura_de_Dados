// QUESTÃO 1 – Busca Sequencial: encontrar um valor
//
// Encontre o número 25 no vetor usando busca sequencial.

// ex: {15, 8, 25, 7, 12, 18, 5, 9, 30, 3}; (procurando o 25) → posição 2

// int buscaSequencial(int vetor[], int tamanho_vetor, int valor_buscado);
// → retorna a posição do valor (ou -1 se não encontrar)

// Testes:
// valor 25 → encontrado na posição 2 (3 comparações: 15, 8, 25)

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista 1 - 2ª unidade/Questao_01_Sequencial_Encontrar.cpp" -o "AV2/lista 1 - 2ª unidade/q1.out" && "./AV2/lista 1 - 2ª unidade/q1.out"

#include <iostream>
using namespace std;

#define TAM_VETOR 10
#define VALOR_BUSCADO 25

void imprimirVetor(int vetor[], int tamanho_vetor)
{
    for (int indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        cout << vetor[indice_vetor] << " ";
    }
    cout << endl;
}

int buscaSequencial(int vetor[], int tamanho_vetor, int valor_buscado)
{
    for (int indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        if (vetor[indice_vetor] == valor_buscado)
        {
            return indice_vetor;
        }
    }
    return -1;
}

int main()
{
    int vetor[TAM_VETOR] = {15, 8, 25, 7, 12, 18, 5, 9, 30, 3};

    cout << "\n\t Vetor: ";
    imprimirVetor(vetor, TAM_VETOR);

    int posicao = buscaSequencial(vetor, TAM_VETOR, VALOR_BUSCADO);

    if (posicao == -1)
    {
        cout << "\n\t O valor " << VALOR_BUSCADO << " não foi encontrado." << endl;
    }

    else
    {
        cout << "\n\t O valor " << VALOR_BUSCADO << " foi encontrado na posição " << posicao << endl;
    }

    return 0;
}
