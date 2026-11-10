// QUESTÃO 1 – Shell Sort básico
//
// Ordene o vetor usando Shell Sort, começando com gap 2.

// ex: {12, 8, 15, 3, 10, 5, 7, 2}; → gaps 2 e 1

// void shellSort(int vetor[], int tamanho_vetor, int gap_inicial);
// → imprime o vetor depois de cada gap

// Testes:
// Após gap 2 → 7 2 10 3 12 5 15 8
// Após gap 1 → 2 3 5 7 8 10 12 15

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_01_Shell_Sort_Basico.cpp -o q1.out && ./q1.out

#include <iostream>
using namespace std;

#define TAM_VETOR 8
#define GAP_INICIAL 2

void imprimirVetor(int vetor[], int tamanho_vetor)
{
    for (int indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        cout << vetor[indice_vetor] << " ";
    }
    cout << endl;
}

void shellSort(int vetor[], int tamanho_vetor, int gap_inicial)
{
    for (int gap = gap_inicial; gap > 0; gap /= 2)
    {
        for (int i = gap; i < tamanho_vetor; i++)
        {
            int temp = vetor[i];
            int j;

            for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap)
            {
                vetor[j] = vetor[j - gap];
            }
            vetor[j] = temp;
        }

        cout << "\n\t Após gap " << gap << ": ";
        imprimirVetor(vetor, tamanho_vetor);
    }
}

int main()
{
    int vetor[TAM_VETOR] = {12, 8, 15, 3, 10, 5, 7, 2};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    shellSort(vetor, TAM_VETOR, GAP_INICIAL);

    return 0;
}