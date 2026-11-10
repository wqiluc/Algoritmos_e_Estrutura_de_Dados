// QUESTÃO 3 – Busca Sequencial: índice ou -1
//
// Busque o número 55 e retorne o índice dele ou -1 se não existir.

// ex: {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; (procurando o 55) → -1

// int buscaSequencial(int vetor[], int tamanho_vetor, int valor_buscado);
// → retorna a posição do valor (ou -1 se não encontrar)

// Testes:
// valor 55 → -1 (percorreu os 10 elementos e não achou)

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista 1 - 2ª unidade/Questao_03_Sequencial_Indice_Ou_Menos_Um.cpp" -o "AV2/lista 1 - 2ª unidade/q3.out" && "./AV2/lista 1 - 2ª unidade/q3.out"

#include <iostream>
using namespace std;

#define TAM_VETOR 10
#define VALOR_BUSCADO 55

void imprimirVetor(int vetor[], int tamanho_vetor)
{
    for (int indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        cout << vetor[indice_vetor] << " ";
    }
    cout << endl;
}

int buscaSequencial(int vetor[], int tamanho_vetor, int valor_buscado)
{
    for (int indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        if (vetor[indice_vetor] == valor_buscado)
        {
            return indice_vetor;
        }
    }
    return -1;
}

int main()
{
    int vetor[TAM_VETOR] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    cout << "\n\t Vetor: ";
    imprimirVetor(vetor, TAM_VETOR);

    int posicao = buscaSequencial(vetor, TAM_VETOR, VALOR_BUSCADO);

    cout << "\n\t Resultado da busca pelo " << VALOR_BUSCADO << ": " << posicao << endl;

    if (posicao == -1)
    {
        cout << "\n\t O valor " << VALOR_BUSCADO << " não está no vetor." << endl;
    }

    return 0;
}
