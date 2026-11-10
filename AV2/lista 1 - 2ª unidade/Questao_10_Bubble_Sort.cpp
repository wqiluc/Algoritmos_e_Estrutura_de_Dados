// QUESTÃO 10 – Bubble Sort
//
// Ordene o vetor em ordem crescente usando Bubble Sort.

// ex: {9, 7, 5, 3, 1, 2, 4, 6, 8, 0}; → 0 1 2 3 4 5 6 7 8 9

// void bubbleSort(int vetor[], int tamanho_vetor);
// → compara vizinhos e troca se o da esquerda for maior;
//   a cada passada o maior que sobrou "borbulha" pro fim

// Testes:
// Vetor original → 9 7 5 3 1 2 4 6 8 0
// Vetor ordenado → 0 1 2 3 4 5 6 7 8 9

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista 1 - 2ª unidade/Questao_10_Bubble_Sort.cpp" -o "AV2/lista 1 - 2ª unidade/q10.out" && "./AV2/lista 1 - 2ª unidade/q10.out"

#include <iostream>
#include <utility>
using namespace std;

#define TAM_VETOR 10

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
        // o fim do vetor (últimas "passada" posições) já está ordenado
        for (int j = 0; j < tamanho_vetor - 1 - passada; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                swap(vetor[j], vetor[j + 1]);
            }
        }
    }
}

int main()
{
    int vetor[TAM_VETOR] = {9, 7, 5, 3, 1, 2, 4, 6, 8, 0};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    bubbleSort(vetor, TAM_VETOR);

    cout << "\n\t Vetor ordenado: ";
    imprimirVetor(vetor, TAM_VETOR);

    return 0;
}
