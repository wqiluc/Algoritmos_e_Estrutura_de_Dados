// QUESTÃO 16 – Selection Sort mostrando cada troca
//
// Ordene o vetor em ordem crescente usando Selection Sort e mostre o
// vetor depois de CADA TROCA.

// ex: {29, 10, 14, 37, 13, 40, 2, 7, 5, 18}; → 2 5 7 10 13 14 18 29 37 40

// void selectionSort(int vetor[], int tamanho_vetor);
// → acha o menor do resto e troca com a posição i;
//   só troca (e imprime) se o menor não for o próprio vetor[i]

// Testes:
// Troca 1 (29 ↔ 2)  → 2 10 14 37 13 40 29 7 5 18
// Troca 2 (10 ↔ 5)  → 2 5 14 37 13 40 29 7 10 18
// Troca 3 (14 ↔ 7)  → 2 5 7 37 13 40 29 14 10 18
// Troca 4 (37 ↔ 10) → 2 5 7 10 13 40 29 14 37 18
// Troca 5 (40 ↔ 14) → 2 5 7 10 13 14 29 40 37 18
// Troca 6 (29 ↔ 18) → 2 5 7 10 13 14 18 40 37 29
// Troca 7 (40 ↔ 29) → 2 5 7 10 13 14 18 29 37 40

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_16_Selection_Sort_Cada_Troca.cpp -o q16.out && ./q16.out

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

void selectionSort(int vetor[], int tamanho_vetor)
{
    int numero_troca = 0;

    for (int i = 0; i < tamanho_vetor - 1; i++)
    {
        int indice_menor = i;

        for (int j = i + 1; j < tamanho_vetor; j++)
        {
            if (vetor[j] < vetor[indice_menor])
            {
                indice_menor = j;
            }
        }

        if (indice_menor != i)
        {
            numero_troca++;
            cout << "\n\t Troca " << numero_troca << " (" << vetor[i] << " ↔ " << vetor[indice_menor] << "): ";

            swap(vetor[i], vetor[indice_menor]);
            imprimirVetor(vetor, tamanho_vetor);
        }
    }
}

int main()
{
    int vetor[TAM_VETOR] = {29, 10, 14, 37, 13, 40, 2, 7, 5, 18};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    selectionSort(vetor, TAM_VETOR);

    cout << "\n\t Vetor ordenado: ";
    imprimirVetor(vetor, TAM_VETOR);

    return 0;
}
