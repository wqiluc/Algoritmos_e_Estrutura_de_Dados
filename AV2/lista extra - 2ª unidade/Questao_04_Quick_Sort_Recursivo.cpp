// QUESTÃO 4 – Quick Sort recursivo (com valor repetido)
//
// Ordene o vetor usando Quick Sort recursivo, com o último elemento
// do trecho como pivô.

// ex: {11, 5, 8, 3, 5, 9, 2, 7, 6}; → 2 3 5 5 6 7 8 9 11

// void quickSort(int vetor[], int inicio, int final);
// → imprime o vetor depois de cada partição

// Testes:
// Pivô 6  → posição 4: 5 3 5 2 6 9 11 7 8
// Pivô 2  → posição 0: 2 3 5 5 6 9 11 7 8
// Pivô 5  → posição 2: 2 3 5 5 6 9 11 7 8
// Pivô 8  → posição 6: 2 3 5 5 6 7 8 9 11
// Pivô 11 → posição 8: 2 3 5 5 6 7 8 9 11

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_04_Quick_Sort_Recursivo.cpp -o q4.out && ./q4.out

#include <iostream>
#include <utility>
using namespace std;

#define TAM_VETOR 9

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
        if (vetor[j] < pivo) // estrito: quem é igual ao pivô fica à direita
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
    int vetor[TAM_VETOR] = {11, 5, 8, 3, 5, 9, 2, 7, 6};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    quickSort(vetor, 0, TAM_VETOR - 1);

    cout << "\n\t Vetor ordenado: ";
    imprimirVetor(vetor, TAM_VETOR);

    return 0;
}
