// QUESTÃO 27 – Selection Sort: iterações (crescente)
//
// Ordene o vetor em ordem crescente com Selection Sort, mostrando o
// vetor depois de cada iteração (cada posição i preenchida).

// ex: {42, 33, 60, 15, 75, 12, 25, 90, 1, 6}; → 1 6 12 15 25 33 42 60 75 90

// void selectionSort(int vetor[], int tamanho_vetor);
// → imprime o vetor depois de cada iteração, dizendo qual troca foi feita

// Testes:
// Iteração 1 (troca 42 ↔ 1)  → 1 33 60 15 75 12 25 90 42 6
// Iteração 2 (troca 33 ↔ 6)  → 1 6 60 15 75 12 25 90 42 33
// Iteração 3 (troca 60 ↔ 12) → 1 6 12 15 75 60 25 90 42 33
// Iteração 4 (sem troca)     → 1 6 12 15 75 60 25 90 42 33
// Iteração 5 (troca 75 ↔ 25) → 1 6 12 15 25 60 75 90 42 33
// Iteração 6 (troca 60 ↔ 33) → 1 6 12 15 25 33 75 90 42 60
// Iteração 7 (troca 75 ↔ 42) → 1 6 12 15 25 33 42 90 75 60
// Iteração 8 (troca 90 ↔ 60) → 1 6 12 15 25 33 42 60 75 90
// Iteração 9 (sem troca)     → 1 6 12 15 25 33 42 60 75 90

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_27_Selection_Iteracoes.cpp -o q27.out && ./q27.out

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

        cout << "\n\t Iteração " << i + 1;

        if (indice_menor != i)
        {
            cout << " (troca " << vetor[i] << " ↔ " << vetor[indice_menor] << "): ";
            swap(vetor[i], vetor[indice_menor]);
        }

        else
        {
            cout << " (sem troca): ";
        }

        imprimirVetor(vetor, tamanho_vetor);
    }
}

int main()
{
    int vetor[TAM_VETOR] = {42, 33, 60, 15, 75, 12, 25, 90, 1, 6};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    selectionSort(vetor, TAM_VETOR);

    return 0;
}
