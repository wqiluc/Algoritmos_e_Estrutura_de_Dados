// QUESTÃO 20 – Bubble Sort: iterações (crescente)
//
// Ordene o vetor em ordem crescente com Bubble Sort, mostrando o vetor
// depois de cada passada.

// ex: {11, 2, 5, 1, 10, 8, 7, 1}; → 1 1 2 5 7 8 10 11

// void bubbleSort(int vetor[], int tamanho_vetor);
// → imprime o vetor depois de cada passada

// Testes:
// Passada 1 → 2 5 1 10 8 7 1 11
// Passada 2 → 2 1 5 8 7 1 10 11
// Passada 3 → 1 2 5 7 1 8 10 11
// Passada 4 → 1 2 5 1 7 8 10 11
// Passada 5 → 1 2 1 5 7 8 10 11
// Passada 6 → 1 1 2 5 7 8 10 11
// Passada 7 → 1 1 2 5 7 8 10 11
// (8 elementos → 7 passadas; o 1 repetido não é trocado com o outro 1)

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista 1 - 2ª unidade/Questao_20_Bubble_Iteracoes.cpp" -o "AV2/lista 1 - 2ª unidade/q20.out" && "./AV2/lista 1 - 2ª unidade/q20.out"

#include <iostream>
#include <utility>
using namespace std;

#define TAM_VETOR 8

void imprimirVetor(int vetor[], int tamanho_vetor)
{
    for (int indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        cout << vetor[indice_vetor] << " ";
    }
    cout << endl;
}

void bubbleSort(int vetor[], int tamanho_vetor)
{
    for (int passada = 0; passada < tamanho_vetor - 1; passada++)
    {
        for (int j = 0; j < tamanho_vetor - 1 - passada; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                swap(vetor[j], vetor[j + 1]);
            }
        }

        cout << "\n\t Passada " << passada + 1 << ": ";
        imprimirVetor(vetor, tamanho_vetor);
    }
}

int main()
{
    int vetor[TAM_VETOR] = {11, 2, 5, 1, 10, 8, 7, 1};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    bubbleSort(vetor, TAM_VETOR);

    return 0;
}
