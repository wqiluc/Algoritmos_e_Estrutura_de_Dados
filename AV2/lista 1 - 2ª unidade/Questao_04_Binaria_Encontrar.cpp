// QUESTÃO 4 – Busca Binária: encontrar um valor
//
// Encontre o valor 13 no vetor (ordenado) usando busca binária.
//
// Valor   2   4   6   8   10  12  13  14  16  18
// Índice  0   1   2   3   4   5   6   7   8   9

// ex: {2, 4, 6, 8, 10, 12, 13, 14, 16, 18}; (procurando o 13) → posição 6

// int buscaBinaria(int vetor[], int tamanho_vetor, int valor_buscado);
// → retorna a posição do valor (ou -1 se não encontrar)
// → imprime inicio, final e meio a cada volta do while

// Testes (passo a passo):
// inicio 0, final 9 → meio 4 (10) → 10 < 13, vai pra direita
// inicio 5, final 9 → meio 7 (14) → 14 > 13, vai pra esquerda
// inicio 5, final 6 → meio 5 (12) → 12 < 13, vai pra direita
// inicio 6, final 6 → meio 6 (13) → achou!
// valor 13 → posição 6

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista 1 - 2ª unidade/Questao_04_Binaria_Encontrar.cpp" -o "AV2/lista 1 - 2ª unidade/q4.out" && "./AV2/lista 1 - 2ª unidade/q4.out"

#include <iostream>
using namespace std;

#define TAM_VETOR 10
#define VALOR_BUSCADO 13

void imprimirVetor(int vetor[], int tamanho_vetor)
{
    for (int indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        cout << vetor[indice_vetor] << " ";
    }
    cout << endl;
}

int buscaBinaria(int vetor[], int tamanho_vetor, int valor_buscado)
{
    int inicio = 0;
    int final = tamanho_vetor - 1;

    while (inicio <= final)
    {
        int meio = (inicio + final) / 2;

        cout << "\n\t inicio " << inicio << ", final " << final
             << " → meio " << meio << " (" << vetor[meio] << ")";

        if (vetor[meio] == valor_buscado)
        {
            cout << " → achou!" << endl;
            return meio;
        }

        else if (vetor[meio] < valor_buscado)
        {
            cout << " → vai pra direita";
            inicio = meio + 1;
        }

        else
        {
            cout << " → vai pra esquerda";
            final = meio - 1;
        }
    }
    cout << endl;
    return -1;
}

int main()
{
    int vetor[TAM_VETOR] = {2, 4, 6, 8, 10, 12, 13, 14, 16, 18};

    cout << "\n\t Vetor: ";
    imprimirVetor(vetor, TAM_VETOR);

    int posicao = buscaBinaria(vetor, TAM_VETOR, VALOR_BUSCADO);

    if (posicao == -1)
    {
        cout << "\n\t O valor " << VALOR_BUSCADO << " não foi encontrado." << endl;
    }

    else
    {
        cout << "\n\t O valor " << VALOR_BUSCADO << " foi encontrado na posição " << posicao << endl;
    }

    return 0;
}
