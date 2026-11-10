// QUESTÃO 14 – Insertion Sort só dos pares
//
// Ordene APENAS os números pares do vetor (em ordem crescente) usando
// Insertion Sort. Os ímpares ficam parados onde estão; os pares são
// ordenados entre si, ocupando as posições onde já havia pares.

// ex: {9, 8, 3, 4, 7, 6, 1, 2, 5, 0}; → 9 0 3 2 7 4 1 6 5 8

// void insertionSortPares(int vetor[], int tamanho_vetor);
// → guarda as posições onde há pares e faz o Insertion Sort só nelas

// Testes:
// Pares nas posições 1, 3, 5, 7, 9 → 8 4 6 2 0
// Pares ordenados                   → 0 2 4 6 8
// Vetor final → 9 0 3 2 7 4 1 6 5 8 (ímpares 9 3 7 1 5 não mudaram de lugar)

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_14_Insertion_Sort_Apenas_Pares.cpp -o q14.out && ./q14.out

#include <iostream>
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

void insertionSortPares(int vetor[], int tamanho_vetor)
{
    int* posicoes_pares = new int[tamanho_vetor];
    int quantidade_pares = 0;

    for (int indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        if (vetor[indice_vetor] % 2 == 0)
        {
            posicoes_pares[quantidade_pares] = indice_vetor;
            quantidade_pares++;
        }
    }

    // Insertion Sort normal, mas "pulando" pelas posições dos pares
    for (int i = 1; i < quantidade_pares; i++)
    {
        int atual = vetor[posicoes_pares[i]];
        int j = i - 1;

        while (j >= 0 && vetor[posicoes_pares[j]] > atual)
        {
            vetor[posicoes_pares[j + 1]] = vetor[posicoes_pares[j]];
            j--;
        }
        vetor[posicoes_pares[j + 1]] = atual;
    }

    delete[] posicoes_pares;
}

int main()
{
    int vetor[TAM_VETOR] = {9, 8, 3, 4, 7, 6, 1, 2, 5, 0};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    insertionSortPares(vetor, TAM_VETOR);

    cout << "\n\t Pares ordenados: ";
    imprimirVetor(vetor, TAM_VETOR);

    return 0;
}
