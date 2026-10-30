// QUESTÃO 3 – Busca Binária: Primeira Posição
//
// Modifique a busca binária para retornar a primeira posição em que
// determinado elemento aparece.

// ex: {2, 4, 4, 4, 7, 9, 11}; (procurando o 4) → posição 1

// int buscaBinariaPrimeiraPosicao(int vetor[], int tamanho, int valor);

// Testes:
// valor 4  → posição 1
// valor 2  → posição 0
// valor 11 → posição 6
// valor 5  → valor não encontrado no vetor.

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios sala de aula/Questao_03_Binaria_Primeira_Posicao.cpp" -o "AV2/exércicios sala de aula/q3.out" && "./AV2/exércicios sala de aula/q3.out"

#include <iostream>
using namespace std;

#define TAM_VETOR 7

int buscaBinariaPrimeiraPosicao(int vetor[], int tamanho_vetor, int valor)
{
    int inicio = 0;
    int final = tamanho_vetor - 1;
    int meio;
    int posicao = - 1;

    while (inicio <= final)
    {
        meio = (inicio+final) / 2;

        if (vetor[meio] == valor)
        {
            posicao = meio;
            final = meio - 1;
        }

        else if (vetor[meio] < valor)
        {
            inicio = meio + 1;
        }

        else
        {
            final = meio - 1;
        }
    }
    return posicao;
}

int main()
{
    int vetor[TAM_VETOR] = {2, 4, 4, 4, 7, 9, 11};
    int valor;

    cout << "\n\t Digite um valor do vetor: ";
    cin >> valor;

    int posicao = buscaBinariaPrimeiraPosicao(vetor, TAM_VETOR, valor);

    if(posicao == -1)
    {
        cout << "\n\t Valor não encontrado no vetor.\n";
    }
    else
    {
        cout << "\n\t A primeira posição do valor " << valor << " é " << posicao << ".\n";
    }

    return 0;
}