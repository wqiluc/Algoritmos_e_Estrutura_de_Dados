// QUESTÃO 15 – Insertion Sort em ordem decrescente
//
// Ordene o vetor do MAIOR para o MENOR usando Insertion Sort.

// ex: {30, 20, 10, 40, 50, 70, 60, 90, 80, 100}; → 100 90 80 70 60 50 40 30 20 10

// void insertionSortDecrescente(int vetor[], int tamanho_vetor);
// → igual ao normal, só inverte a comparação: empurra pra direita os MENORES

// Testes:
// Vetor original → 30 20 10 40 50 70 60 90 80 100
// Vetor ordenado → 100 90 80 70 60 50 40 30 20 10

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_15_Insertion_Sort_Decrescente.cpp -o q15.out && ./q15.out

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

void insertionSortDecrescente(int vetor[], int tamanho_vetor)
{
    for (int i = 1; i < tamanho_vetor; i++)
    {
        int atual = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] < atual) // < em vez de >
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = atual;
    }
}

int main()
{
    int vetor[TAM_VETOR] = {30, 20, 10, 40, 50, 70, 60, 90, 80, 100};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    insertionSortDecrescente(vetor, TAM_VETOR);

    cout << "\n\t Vetor ordenado (decrescente): ";
    imprimirVetor(vetor, TAM_VETOR);

    return 0;
}
