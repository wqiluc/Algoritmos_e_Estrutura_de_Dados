// QUESTÃO 22 – Insertion Sort: iterações (crescente)
//
// Ordene o vetor em ordem crescente com Insertion Sort, mostrando o
// vetor depois de cada inserção.

// ex: {22, 11, 99, 88, 9, 7, 42, 65, 33, 10}; → 7 9 10 11 22 33 42 65 88 99

// void insertionSort(int vetor[], int tamanho_vetor);
// → imprime o vetor depois de inserir cada elemento no lugar certo

// Testes:
// Iteração 1 (insere 11) → 11 22 99 88 9 7 42 65 33 10
// Iteração 2 (insere 99) → 11 22 99 88 9 7 42 65 33 10
// Iteração 3 (insere 88) → 11 22 88 99 9 7 42 65 33 10
// Iteração 4 (insere 9)  → 9 11 22 88 99 7 42 65 33 10
// Iteração 5 (insere 7)  → 7 9 11 22 88 99 42 65 33 10
// Iteração 6 (insere 42) → 7 9 11 22 42 88 99 65 33 10
// Iteração 7 (insere 65) → 7 9 11 22 42 65 88 99 33 10
// Iteração 8 (insere 33) → 7 9 11 22 33 42 65 88 99 10
// Iteração 9 (insere 10) → 7 9 10 11 22 33 42 65 88 99

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista 1 - 2ª unidade/Questao_22_Insertion_Iteracoes.cpp" -o "AV2/lista 1 - 2ª unidade/q22.out" && "./AV2/lista 1 - 2ª unidade/q22.out"

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
    int vetor[TAM_VETOR] = {22, 11, 99, 88, 9, 7, 42, 65, 33, 10};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    insertionSort(vetor, TAM_VETOR);

    return 0;
}
