// QUESTÃO 17 – Selection Sort contando trocas
//
// Ordene o vetor em ordem crescente usando Selection Sort e conte
// quantas trocas foram feitas.

// ex: {5, 4, 3, 2, 1, 6, 7, 8, 9, 10}; → 2 trocas

// int selectionSortContandoTrocas(int vetor[], int tamanho_vetor);
// → retorna o nº de trocas; só conta quando o menor NÃO é o próprio vetor[i]

// Testes:
// i = 0 → menor é o 1 → troca 5 ↔ 1 → 1 4 3 2 5 6 7 8 9 10
// i = 1 → menor é o 2 → troca 4 ↔ 2 → 1 2 3 4 5 6 7 8 9 10
// i = 2 até 8 → cada um já está no lugar → sem troca
// Total de trocas → 2

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista 1 - 2ª unidade/Questao_17_Selection_Sort_Contar_Trocas.cpp" -o "AV2/lista 1 - 2ª unidade/q17.out" && "./AV2/lista 1 - 2ª unidade/q17.out"

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

int selectionSortContandoTrocas(int vetor[], int tamanho_vetor)
{
    int trocas = 0;

    for (int i = 0; i < tamanho_vetor - 1; i++)
    {
        int indice_menor = i;

        for (int j = i + 1; j < tamanho_vetor; j++)
        {
            if (vetor[j] < vetor[indice_menor])
            {
                indice_menor = j;
            }
        }

        if (indice_menor != i)
        {
            swap(vetor[i], vetor[indice_menor]);
            trocas++;
        }
    }
    return trocas;
}

int main()
{
    int vetor[TAM_VETOR] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    int trocas = selectionSortContandoTrocas(vetor, TAM_VETOR);

    cout << "\n\t Vetor ordenado: ";
    imprimirVetor(vetor, TAM_VETOR);

    cout << "\n\t Total de trocas: " << trocas << endl;

    return 0;
}
