// QUESTÃO 3 – Quick Sort recursivo
//
// Ordene o vetor usando Quick Sort recursivo, com o último elemento
// do trecho como pivô.

// ex: {9, 4, 7, 2, 8, 1, 5}; → 1 2 4 5 7 8 9

// void quickSort(int vetor[], int inicio, int final);
// → imprime o vetor depois de cada partição

// Testes:
// Pivô 5 → posição 3: 4 2 1 5 8 7 9
// Pivô 1 → posição 0: 1 2 4 5 8 7 9
// Pivô 4 → posição 2: 1 2 4 5 8 7 9
// Pivô 9 → posição 6: 1 2 4 5 8 7 9
// Pivô 7 → posição 4: 1 2 4 5 7 8 9

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista extra - 2ª unidade/Questao_03_Quick_Sort_Recursivo.cpp" -o "AV2/lista extra - 2ª unidade/q3.out" && "./AV2/lista extra - 2ª unidade/q3.out"

#include <iostream>
#include <utility>
using namespace std;

#define TAM_VETOR 7

void imprimirVetor(int vetor[], int tamanho_vetor)
{
    for (int indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        cout << vetor[indice_vetor] << " ";
    }
    cout << endl;
}

int particionar(int vetor[], int inicio, int final)
{
    int pivo = vetor[final];
    int i = inicio - 1;

    for (int j = inicio; j < final; j++)
    {
        if (vetor[j] < pivo)
        {
            i++;
            swap(vetor[i], vetor[j]);
        }
    }
    swap(vetor[i + 1], vetor[final]);

    return i + 1;
}

void quickSort(int vetor[], int inicio, int final)
{
    if (inicio < final)
    {
        int posicao_pivo = particionar(vetor, inicio, final);

        cout << "\n\t Pivô " << vetor[posicao_pivo] << " → posição " << posicao_pivo << ": ";
        imprimirVetor(vetor, TAM_VETOR);

        quickSort(vetor, inicio, posicao_pivo - 1);
        quickSort(vetor, posicao_pivo + 1, final);
    }
}

int main()
{
    int vetor[TAM_VETOR] = {9, 4, 7, 2, 8, 1, 5};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    quickSort(vetor, 0, TAM_VETOR - 1);

    cout << "\n\t Vetor ordenado: ";
    imprimirVetor(vetor, TAM_VETOR);

    return 0;
}
