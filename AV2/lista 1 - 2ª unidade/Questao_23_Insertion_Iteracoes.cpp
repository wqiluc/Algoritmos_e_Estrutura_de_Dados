// QUESTÃO 23 – Insertion Sort: iterações (crescente)
//
// Ordene o vetor em ordem crescente com Insertion Sort, mostrando o
// vetor depois de cada inserção.

// ex: {9, 8, 3, 4, 7, 6, 1, 2, 5, 0}; → 0 1 2 3 4 5 6 7 8 9

// void insertionSort(int vetor[], int tamanho_vetor);
// → imprime o vetor depois de inserir cada elemento no lugar certo

// Testes:
// Iteração 1 (insere 8) → 8 9 3 4 7 6 1 2 5 0
// Iteração 2 (insere 3) → 3 8 9 4 7 6 1 2 5 0
// Iteração 3 (insere 4) → 3 4 8 9 7 6 1 2 5 0
// Iteração 4 (insere 7) → 3 4 7 8 9 6 1 2 5 0
// Iteração 5 (insere 6) → 3 4 6 7 8 9 1 2 5 0
// Iteração 6 (insere 1) → 1 3 4 6 7 8 9 2 5 0
// Iteração 7 (insere 2) → 1 2 3 4 6 7 8 9 5 0
// Iteração 8 (insere 5) → 1 2 3 4 5 6 7 8 9 0
// Iteração 9 (insere 0) → 0 1 2 3 4 5 6 7 8 9

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista 1 - 2ª unidade/Questao_23_Insertion_Iteracoes.cpp" -o "AV2/lista 1 - 2ª unidade/q23.out" && "./AV2/lista 1 - 2ª unidade/q23.out"

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

        while (j >= 0 && vetor[j] > atual)
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = atual;

        cout << "\n\t Iteração " << i << " (insere " << atual << "): ";
        imprimirVetor(vetor, tamanho_vetor);
    }
}

int main()
{
    int vetor[TAM_VETOR] = {9, 8, 3, 4, 7, 6, 1, 2, 5, 0};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    insertionSort(vetor, TAM_VETOR);

    return 0;
}
