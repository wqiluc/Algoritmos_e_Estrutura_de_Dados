// QUESTÃO 5 – Merge Sort recursivo
//
// Ordene o vetor usando Merge Sort recursivo.

// ex: {14, 6, 11, 3, 9, 2, 8, 5}; → 2 3 5 6 8 9 11 14

// void mergeSort(int vetor[], int esquerda, int direita);
// → imprime o trecho resultante de cada intercalação

// Testes (ordem das intercalações):
// 6 14
// 3 11
// 3 6 11 14
// 2 9
// 5 8
// 2 5 8 9
// 2 3 5 6 8 9 11 14

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_05_Merge_Sort_Recursivo.cpp -o q5.out && ./q5.out

#include <iostream>
using namespace std;

#define TAM_VETOR 8

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
    int vetor[TAM_VETOR] = {14, 6, 11, 3, 9, 2, 8, 5};

    cout << "\n\t Vetor original: ";
    imprimirTrecho(vetor, 0, TAM_VETOR - 1);

    mergeSort(vetor, 0, TAM_VETOR - 1);

    cout << "\n\t Vetor ordenado: ";
    imprimirTrecho(vetor, 0, TAM_VETOR - 1);

    return 0;
}
