// QUESTÃO 24 – Insertion Sort: iterações (crescente)
//
// Ordene o vetor em ordem crescente com Insertion Sort, mostrando o
// vetor depois de cada inserção.

// ex: {30, 20, 10, 40, 50, 70, 60, 90, 80, 100}; → 10 20 30 40 50 60 70 80 90 100

// void insertionSort(int vetor[], int tamanho_vetor);
// → imprime o vetor depois de inserir cada elemento no lugar certo

// Testes:
// Iteração 1 (insere 20)  → 20 30 10 40 50 70 60 90 80 100
// Iteração 2 (insere 10)  → 10 20 30 40 50 70 60 90 80 100
// Iteração 3 (insere 40)  → 10 20 30 40 50 70 60 90 80 100
// Iteração 4 (insere 50)  → 10 20 30 40 50 70 60 90 80 100
// Iteração 5 (insere 70)  → 10 20 30 40 50 70 60 90 80 100
// Iteração 6 (insere 60)  → 10 20 30 40 50 60 70 90 80 100
// Iteração 7 (insere 90)  → 10 20 30 40 50 60 70 90 80 100
// Iteração 8 (insere 80)  → 10 20 30 40 50 60 70 80 90 100
// Iteração 9 (insere 100) → 10 20 30 40 50 60 70 80 90 100
// (vetor quase ordenado → a maioria das inserções nem mexe em nada)

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista 1 - 2ª unidade/Questao_24_Insertion_Iteracoes.cpp" -o "AV2/lista 1 - 2ª unidade/q24.out" && "./AV2/lista 1 - 2ª unidade/q24.out"

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
    int vetor[TAM_VETOR] = {30, 20, 10, 40, 50, 70, 60, 90, 80, 100};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    insertionSort(vetor, TAM_VETOR);

    return 0;
}
