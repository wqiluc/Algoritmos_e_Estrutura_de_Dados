// QUESTÃO 2 – Shell Sort intermediário
//
// Ordene o vetor usando Shell Sort, começando com gap 2.

// ex: {19, 7, 14, 3, 11, 2, 16, 5, 9}; → gaps 2 e 1

// void shellSort(int vetor[], int tamanho_vetor, int gap_inicial);
// → imprime o vetor depois de cada gap

// Testes:
// Após gap 2 → 9 2 11 3 14 5 16 7 19
// Após gap 1 → 2 3 5 7 9 11 14 16 19

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_02_Shell_Sort_Intermediario.cpp -o q2.out && ./q2.out

#include <iostream>
using namespace std;

#define TAM_VETOR 9
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
    int vetor[TAM_VETOR] = {19, 7, 14, 3, 11, 2, 16, 5, 9};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    shellSort(vetor, TAM_VETOR, GAP_INICIAL);

    return 0;
}
