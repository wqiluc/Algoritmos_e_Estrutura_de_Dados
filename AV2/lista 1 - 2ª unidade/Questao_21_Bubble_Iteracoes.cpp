// QUESTÃO 21 – Bubble Sort: iterações (crescente)
//
// Ordene o vetor em ordem crescente com Bubble Sort, mostrando o vetor
// depois de cada passada.

// ex: {12, 3, 45, 7, 18, 9, 25, 31, 6, 11}; → 3 6 7 9 11 12 18 25 31 45

// void bubbleSort(int vetor[], int tamanho_vetor);
// → imprime o vetor depois de cada passada

// Testes:
// Passada 1 → 3 12 7 18 9 25 31 6 11 45
// Passada 2 → 3 7 12 9 18 25 6 11 31 45
// Passada 3 → 3 7 9 12 18 6 11 25 31 45
// Passada 4 → 3 7 9 12 6 11 18 25 31 45
// Passada 5 → 3 7 9 6 11 12 18 25 31 45
// Passada 6 → 3 7 6 9 11 12 18 25 31 45
// Passada 7 → 3 6 7 9 11 12 18 25 31 45
// Passada 8 → 3 6 7 9 11 12 18 25 31 45
// Passada 9 → 3 6 7 9 11 12 18 25 31 45

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista 1 - 2ª unidade/Questao_21_Bubble_Iteracoes.cpp" -o "AV2/lista 1 - 2ª unidade/q21.out" && "./AV2/lista 1 - 2ª unidade/q21.out"

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
    int vetor[TAM_VETOR] = {12, 3, 45, 7, 18, 9, 25, 31, 6, 11};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    bubbleSort(vetor, TAM_VETOR);

    return 0;
}
