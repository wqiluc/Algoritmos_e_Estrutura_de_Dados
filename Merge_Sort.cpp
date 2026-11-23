// MERGE SORT
//
// DIVIDE o vetor ao meio, repetidas vezes, até cada pedaço ter 1 elemento
// (que já está ordenado). Depois, na volta da recursão, INTERCALA (merge) os
// pedaços em ordem.
//
// Merge Sort do slide:
//   meio = esquerda + (direita - esquerda) / 2
//   a metade da esquerda vai de esquerda até meio (inclusive), então quando o
//   tamanho é ímpar a esquerda fica com 1 a mais
//   no intercalar, use <= (no empate, sai o da esquerda → estável)
//
// ex: {9, 2, 7, 4, 6, 1, 5, 0, 8, 3}; → 0 1 2 3 4 5 6 7 8 9
// (mesmo vetor da Questão 08 da revisão AV2: rode para conferir o papel)
//
// int intercalar(int vetor[], int esquerda, int meio, int direita);
// → junta vetor[esquerda..meio] e vetor[meio+1..direita] (já ordenados) e
//   retorna quantas comparações fez
// void mergeSort(int vetor[], int esquerda, int direita);
// → imprime cada divisão (na ida) e cada merge (na volta da recursão)
//
// Complexidade: O(n log n) em TODOS os casos. É estável. Não é in-place:
// precisa de vetor auxiliar do tamanho do trecho.
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 Merge_Sort.cpp -o merge.out && ./merge.out

#include <iostream>
using namespace std;

#define TAM_VETOR 10

int numero_divisao = 0;
int numero_merge = 0;
int total_comparacoes = 0;

void imprimirTrecho(int vetor[], int esquerda, int direita)
{
    cout << "[";

    for (int indice_vetor = esquerda; indice_vetor <= direita; indice_vetor++)
    {
        cout << vetor[indice_vetor];

        if (indice_vetor < direita)
        {
            cout << " ";
        }
    }

    cout << "]";
}

int intercalar(int vetor[], int esquerda, int meio, int direita)
{
    int tamanho_esquerda = meio - esquerda + 1;
    int tamanho_direita = direita - meio;

    int* metade_esquerda = new int[tamanho_esquerda];
    int* metade_direita = new int[tamanho_direita];

    for (int i = 0; i < tamanho_esquerda; i++)
    {
        metade_esquerda[i] = vetor[esquerda + i];
    }

    for (int j = 0; j < tamanho_direita; j++)
    {
        metade_direita[j] = vetor[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = esquerda;
    int comparacoes = 0;

    while (i < tamanho_esquerda && j < tamanho_direita)
    {
        comparacoes++;

        if (metade_esquerda[i] <= metade_direita[j]) // <= mantém o merge estável
        {
            vetor[k] = metade_esquerda[i];
            i++;
        }

        else
        {
            vetor[k] = metade_direita[j];
            j++;
        }
        k++;
    }

    while (i < tamanho_esquerda) // sobra da esquerda
    {
        vetor[k] = metade_esquerda[i];
        i++;
        k++;
    }

    while (j < tamanho_direita) // sobra da direita
    {
        vetor[k] = metade_direita[j];
        j++;
        k++;
    }

    delete[] metade_esquerda;
    delete[] metade_direita;

    return comparacoes;
}

void mergeSort(int vetor[], int esquerda, int direita)
{
    if (esquerda >= direita) // 1 elemento: já está ordenado
    {
        return;
    }

    int meio = esquerda + (direita - esquerda) / 2;

    // ida da recursão: só divide, não compara nada
    numero_divisao++;
    cout << "\n\t D" << numero_divisao << " (idx " << esquerda << ".." << direita << ", meio " << meio << ") → ";
    imprimirTrecho(vetor, esquerda, direita);
    cout << " → ";
    imprimirTrecho(vetor, esquerda, meio);
    cout << " | ";
    imprimirTrecho(vetor, meio + 1, direita);
    cout << endl;

    mergeSort(vetor, esquerda, meio);      // ordena a metade da esquerda
    mergeSort(vetor, meio + 1, direita);   // ordena a metade da direita

    // volta da recursão: as duas metades já estão ordenadas
    numero_merge++;
    cout << "\n\t Merge " << numero_merge << " (idx " << esquerda << ".." << direita << ") → ";
    imprimirTrecho(vetor, esquerda, meio);
    cout << " + ";
    imprimirTrecho(vetor, meio + 1, direita);

    int comparacoes = intercalar(vetor, esquerda, meio, direita);
    total_comparacoes += comparacoes;

    cout << " → ";
    imprimirTrecho(vetor, esquerda, direita);
    cout << " · " << comparacoes << " comp" << endl;
}

int main()
{
    int vetor[TAM_VETOR] = {9, 2, 7, 4, 6, 1, 5, 0, 8, 3};

    cout << "\n\t Vetor original: ";
    imprimirTrecho(vetor, 0, TAM_VETOR - 1);
    cout << endl;

    mergeSort(vetor, 0, TAM_VETOR - 1);

    cout << "\n\t Vetor ordenado: ";
    imprimirTrecho(vetor, 0, TAM_VETOR - 1);
    cout << endl;

    cout << "\n\t Total: " << numero_divisao << " divisões, " << numero_merge << " merges, " << total_comparacoes << " comparações" << endl;

    return 0;
}
