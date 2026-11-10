// QUESTÃO 6 – Merge Sort recursivo (tamanho ímpar)
//
// Ordene o vetor usando Merge Sort recursivo. Como o tamanho é ímpar,
// a metade da esquerda fica com 1 elemento a mais.

// ex: {12, 4, 9, 1, 7, 3, 10}; → 1 3 4 7 9 10 12

// void mergeSort(int vetor[], int esquerda, int direita);
// → imprime o trecho resultante de cada intercalação

// Testes (ordem das intercalações):
// 4 12
// 1 9
// 1 4 9 12
// 3 7
// 3 7 10
// 1 3 4 7 9 10 12

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_06_Merge_Sort_Recursivo.cpp -o q6.out && ./q6.out

#include <iostream>
using namespace std;

#define TAM_VETOR 7

void imprimirTrecho(int vetor[], int esquerda, int direita)
{
    for (int indice_vetor = esquerda; indice_vetor <= direita; indice_vetor++)
    {
        cout << vetor[indice_vetor] << " ";
    }
    cout << endl;
}

void intercalar(int vetor[], int esquerda, int meio, int direita)
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

    while (i < tamanho_esquerda && j < tamanho_direita)
    {
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
}

void mergeSort(int vetor[], int esquerda, int direita)
{
    if (esquerda >= direita)
    {
        return;
    }

    int meio = esquerda + (direita - esquerda) / 2;

    mergeSort(vetor, esquerda, meio);
    mergeSort(vetor, meio + 1, direita);

    intercalar(vetor, esquerda, meio, direita);

    cout << "\n\t Intercalação: ";
    imprimirTrecho(vetor, esquerda, direita);
}

int main()
{
    int vetor[TAM_VETOR] = {12, 4, 9, 1, 7, 3, 10};

    cout << "\n\t Vetor original: ";
    imprimirTrecho(vetor, 0, TAM_VETOR - 1);

    mergeSort(vetor, 0, TAM_VETOR - 1);

    cout << "\n\t Vetor ordenado: ";
    imprimirTrecho(vetor, 0, TAM_VETOR - 1);

    return 0;
}
