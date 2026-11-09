// QUESTÃO 3 – Busca Sequencial: Contar Ocorrências
//
// Altere a busca sequencial original para contar e retornar quantas vezes
// um valor específico aparece no vetor.
//
// Valor   5   2   7   2   9   2   5   1
// Índice  0   1   2   3   4   5   6   7
//
// ex: {5, 2, 7, 2, 9, 2, 5, 1}; (procurando o 2) → aparece 3 vezes
//
// int contarOcorrencias(int vetor[], int tamanho_vetor, int valor);
//
// No main, leia o valor do teclado e mostre o resultado.
//
// Testes:
// valor 2 → 3 vezes
// valor 5 → 2 vezes
// valor 9 → 1 vez
// valor 4 → 0 vezes (não aparece no vetor)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios pdf/Questao_03_Sequencial_Contar_Ocorrencias.cpp" -o "AV2/exércicios pdf/q3.out" && "./AV2/exércicios pdf/q3.out"

#include <iostream>
using namespace std;

#define TAMANHO_VETOR 8

int contarOcorrencias(int vetor[], int tamanho_vetor, int valor)
{
    int indice_ocorrencias;

    for (indice_ocorrencias = 0; indice_ocorrencias < tamanho_vetor; indice_ocorrencias++)
    {
        if (vetor[indice_ocorrencias] == valor)
        {
            indice_ocorrencias++;
        }
    }
    return indice_ocorrencias;
}

int main()
{
    int vetor[TAMANHO_VETOR] = {5, 2, 7, 2, 9, 2, 5, 1};
    int valor;

    cout << "Digite o valor a ser buscado: ";
    cin >> valor;

    int ocorrencias = contarOcorrencias(vetor, TAMANHO_VETOR, valor);

    cout << "O valor " << valor << " aparece " << ocorrencias << " vezes no vetor." << endl;

    return 0;
}