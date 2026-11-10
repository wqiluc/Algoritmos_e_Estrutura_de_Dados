// QUESTÃO 25 – Selection Sort: iterações (crescente)
//
// Ordene o vetor em ordem crescente com Selection Sort, mostrando o
// vetor depois de cada iteração (cada posição i preenchida).

// ex: {29, 10, 14, 37, 13, 40, 2, 7, 5, 18}; → 2 5 7 10 13 14 18 29 37 40

// void selectionSort(int vetor[], int tamanho_vetor);
// → imprime o vetor depois de cada iteração, dizendo qual troca foi feita

// Testes:
// Iteração 1 (troca 29 ↔ 2)  → 2 10 14 37 13 40 29 7 5 18
// Iteração 2 (troca 10 ↔ 5)  → 2 5 14 37 13 40 29 7 10 18
// Iteração 3 (troca 14 ↔ 7)  → 2 5 7 37 13 40 29 14 10 18
// Iteração 4 (troca 37 ↔ 10) → 2 5 7 10 13 40 29 14 37 18
// Iteração 5 (sem troca)     → 2 5 7 10 13 40 29 14 37 18
// Iteração 6 (troca 40 ↔ 14) → 2 5 7 10 13 14 29 40 37 18
// Iteração 7 (troca 29 ↔ 18) → 2 5 7 10 13 14 18 40 37 29
// Iteração 8 (troca 40 ↔ 29) → 2 5 7 10 13 14 18 29 37 40
// Iteração 9 (sem troca)     → 2 5 7 10 13 14 18 29 37 40

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_25_Selection_Iteracoes.cpp -o q25.out && ./q25.out

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
    int vetor[TAM_VETOR] = {29, 10, 14, 37, 13, 40, 2, 7, 5, 18};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    selectionSort(vetor, TAM_VETOR);

    return 0;
}
