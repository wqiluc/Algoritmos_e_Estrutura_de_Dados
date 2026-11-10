// QUESTÃO 19 – Bubble Sort: iterações (crescente)
//
// Ordene o vetor em ordem crescente com Bubble Sort, mostrando o vetor
// depois de cada passada.

// ex: {9, 7, 5, 3, 1, 2, 4, 6, 8, 0}; → 0 1 2 3 4 5 6 7 8 9

// void bubbleSort(int vetor[], int tamanho_vetor);
// → imprime o vetor depois de cada passada

// Testes:
// Passada 1 → 7 5 3 1 2 4 6 8 0 9
// Passada 2 → 5 3 1 2 4 6 7 0 8 9
// Passada 3 → 3 1 2 4 5 6 0 7 8 9
// Passada 4 → 1 2 3 4 5 0 6 7 8 9
// Passada 5 → 1 2 3 4 0 5 6 7 8 9
// Passada 6 → 1 2 3 0 4 5 6 7 8 9
// Passada 7 → 1 2 0 3 4 5 6 7 8 9
// Passada 8 → 1 0 2 3 4 5 6 7 8 9
// Passada 9 → 0 1 2 3 4 5 6 7 8 9
// (o 0 começa no fim e só anda 1 casa pra esquerda por passada)

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_19_Bubble_Iteracoes.cpp -o q19.out && ./q19.out

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
    int vetor[TAM_VETOR] = {9, 7, 5, 3, 1, 2, 4, 6, 8, 0};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    bubbleSort(vetor, TAM_VETOR);

    return 0;
}
