// QUESTÃO 5 – Busca Sequencial: Última Ocorrência
//
// Altere o algoritmo da busca sequencial para retornar a posição do ÚLTIMO
// elemento encontrado, caso existam repetições do valor procurado.
//
// Valor   6   13  6   21  13  6   30
// Índice  0   1   2   3   4   5   6
//
// ex: {6, 13, 6, 21, 13, 6, 30}; (procurando o 6) → posição 5
//
// int buscaSequencialUltima(int vetor[], int tamanho_vetor, int valor);
// → retorna a posição da última ocorrência ou -1
//
// No main, leia o valor do teclado e mostre o resultado.
//
// Testes:
// valor 6  → posição 5
// valor 13 → posição 4
// valor 21 → posição 3
// valor 30 → posição 6
// valor 8  → -1 (valor não encontrado)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios pdf/Questao_05_Sequencial_Ultima_Ocorrencia.cpp" -o "AV2/exércicios pdf/q5.out" && "./AV2/exércicios pdf/q5.out"

#include <iostream>
using namespace std;

#define TAM_VETOR 7

int buscaSequencialUltima(int vetor[], int tamanho_vetor, int valor)
{
    int indiceUltimaOcorrencia = -1;

    for (int indice_busca = 0; indice_busca < tamanho_vetor; indice_busca++)
    {
        if (vetor[indice_busca] == valor)
        {
            indiceUltimaOcorrencia = indice_busca;
        }
    }
    return indiceUltimaOcorrencia;
}

int main()
{
    int vetor[TAM_VETOR] = {6, 13, 6, 21, 13, 6, 30};
    int valor;

    cout << "Digite o valor a ser buscado: ";
    cin >> valor;

    int posicao = buscaSequencialUltima(vetor, TAM_VETOR, valor);

    if (posicao != -1)
    {
        cout << "Última ocorrência do valor " << valor << " está na posição: " << posicao << endl;
    }
    else
    {
        cout << "Valor " << valor << " não encontrado no vetor." << endl;
    }

    return 0;
}