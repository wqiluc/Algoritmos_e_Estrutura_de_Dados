// QUESTÃO 26 – Selection Sort: iterações (crescente)
//
// Ordene o vetor em ordem crescente com Selection Sort, mostrando o
// vetor depois de cada iteração (cada posição i preenchida).

// ex: {5, 4, 3, 2, 1, 6, 7, 8, 9, 10}; → 1 2 3 4 5 6 7 8 9 10

// void selectionSort(int vetor[], int tamanho_vetor);
// → imprime o vetor depois de cada iteração, dizendo qual troca foi feita

// Testes:
// Iteração 1 (troca 5 ↔ 1) → 1 4 3 2 5 6 7 8 9 10
// Iteração 2 (troca 4 ↔ 2) → 1 2 3 4 5 6 7 8 9 10
// Iteração 3 (sem troca)   → 1 2 3 4 5 6 7 8 9 10
// Iteração 4 (sem troca)   → 1 2 3 4 5 6 7 8 9 10
// Iteração 5 (sem troca)   → 1 2 3 4 5 6 7 8 9 10
// Iteração 6 (sem troca)   → 1 2 3 4 5 6 7 8 9 10
// Iteração 7 (sem troca)   → 1 2 3 4 5 6 7 8 9 10
// Iteração 8 (sem troca)   → 1 2 3 4 5 6 7 8 9 10
// Iteração 9 (sem troca)   → 1 2 3 4 5 6 7 8 9 10
// (já fica ordenado na 2ª, mas o Selection Sort sempre faz todas as iterações)

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista 1 - 2ª unidade/Questao_26_Selection_Iteracoes.cpp" -o "AV2/lista 1 - 2ª unidade/q26.out" && "./AV2/lista 1 - 2ª unidade/q26.out"

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
    int vetor[TAM_VETOR] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    selectionSort(vetor, TAM_VETOR);

    return 0;
}
