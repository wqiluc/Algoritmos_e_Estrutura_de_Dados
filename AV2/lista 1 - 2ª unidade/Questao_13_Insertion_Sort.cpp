// QUESTÃO 13 – Insertion Sort
//
// Ordene o vetor em ordem crescente usando Insertion Sort.

// ex: {22, 11, 99, 88, 9, 7, 42, 65, 33, 10}; → 7 9 10 11 22 33 42 65 88 99

// void insertionSort(int vetor[], int tamanho_vetor);
// → pega o elemento atual e empurra pra direita os maiores que ele
//   na parte já ordenada, até achar o lugar dele

// Testes:
// Vetor original → 22 11 99 88 9 7 42 65 33 10
// Vetor ordenado → 7 9 10 11 22 33 42 65 88 99

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_13_Insertion_Sort.cpp -o q13.out && ./q13.out

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

void insertionSort(int vetor[], int tamanho_vetor)
{
    for (int i = 1; i < tamanho_vetor; i++)
    {
        int atual = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > atual) // empurra os maiores uma casa pra direita
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = atual;
    }
}

int main()
{
    int vetor[TAM_VETOR] = {22, 11, 99, 88, 9, 7, 42, 65, 33, 10};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    insertionSort(vetor, TAM_VETOR);

    cout << "\n\t Vetor ordenado: ";
    imprimirVetor(vetor, TAM_VETOR);

    return 0;
}
