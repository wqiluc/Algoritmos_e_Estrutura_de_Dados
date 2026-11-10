// QUESTÃO 18 – Selection Sort em ordem decrescente
//
// Ordene o vetor do MAIOR para o MENOR usando Selection Sort.

// ex: {42, 33, 60, 15, 75, 12, 25, 90, 1, 6}; → 90 75 60 42 33 25 15 12 6 1

// void selectionSortDecrescente(int vetor[], int tamanho_vetor);
// → em vez do menor, procura o MAIOR do resto e coloca na posição i

// Testes:
// Vetor original → 42 33 60 15 75 12 25 90 1 6
// Vetor ordenado → 90 75 60 42 33 25 15 12 6 1

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_18_Selection_Sort_Decrescente.cpp -o q18.out && ./q18.out

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

void selectionSortDecrescente(int vetor[], int tamanho_vetor)
{
    for (int i = 0; i < tamanho_vetor - 1; i++)
    {
        int indice_maior = i;

        for (int j = i + 1; j < tamanho_vetor; j++)
        {
            if (vetor[j] > vetor[indice_maior]) // > em vez de <
            {
                indice_maior = j;
            }
        }

        if (indice_maior != i)
        {
            swap(vetor[i], vetor[indice_maior]);
        }
    }
}

int main()
{
    int vetor[TAM_VETOR] = {42, 33, 60, 15, 75, 12, 25, 90, 1, 6};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    selectionSortDecrescente(vetor, TAM_VETOR);

    cout << "\n\t Vetor ordenado (decrescente): ";
    imprimirVetor(vetor, TAM_VETOR);

    return 0;
}
