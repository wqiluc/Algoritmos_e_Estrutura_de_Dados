// QUESTÃO 12 – Bubble Sort em ordem decrescente
//
// Ordene o vetor do MAIOR para o MENOR usando Bubble Sort.

// ex: {12, 3, 45, 7, 18, 9, 25, 31, 6, 11}; → 45 31 25 18 12 11 9 7 6 3

// void bubbleSortDecrescente(int vetor[], int tamanho_vetor);
// → igual ao normal, só inverte a comparação: troca se o da esquerda for MENOR
//   (assim o menor que sobrou "borbulha" pro fim)

// Testes:
// Vetor original → 12 3 45 7 18 9 25 31 6 11
// Vetor ordenado → 45 31 25 18 12 11 9 7 6 3

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista 1 - 2ª unidade/Questao_12_Bubble_Sort_Decrescente.cpp" -o "AV2/lista 1 - 2ª unidade/q12.out" && "./AV2/lista 1 - 2ª unidade/q12.out"

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

void bubbleSortDecrescente(int vetor[], int tamanho_vetor)
{
    for (int passada = 0; passada < tamanho_vetor - 1; passada++)
    {
        for (int j = 0; j < tamanho_vetor - 1 - passada; j++)
        {
            if (vetor[j] < vetor[j + 1]) // < em vez de >
            {
                swap(vetor[j], vetor[j + 1]);
            }
        }
    }
}

int main()
{
    int vetor[TAM_VETOR] = {12, 3, 45, 7, 18, 9, 25, 31, 6, 11};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    bubbleSortDecrescente(vetor, TAM_VETOR);

    cout << "\n\t Vetor ordenado (decrescente): ";
    imprimirVetor(vetor, TAM_VETOR);

    return 0;
}
