// QUESTÃO 5 – Busca Binária: contando comparações
//
// Conte quantas comparações a busca binária faz para encontrar o 100.
//
// Valor   10  20  30  40  50  60  70  80  90  100
// Índice  0   1   2   3   4   5   6   7   8   9

// ex: {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; (procurando o 100) → 4 comparações

// int buscaBinariaComparacoes(int vetor[], int tamanho_vetor, int valor, int &comparacoes);
// → retorna a posição (ou -1) e guarda em comparacoes o nº de comparações
// → conta 1 comparação a cada volta do while (cada vez que olha vetor[meio])

// Testes:
// Comparação 1 → meio 4 (50)
// Comparação 2 → meio 7 (80)
// Comparação 3 → meio 8 (90)
// Comparação 4 → meio 9 (100) → achou
// valor 100 → posição 9, 4 comparações

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_05_Binaria_Contando_Comparacoes.cpp -o q5.out && ./q5.out

#include <iostream>
using namespace std;

#define TAM_VETOR 10
#define VALOR_BUSCADO 100

void imprimirVetor(int vetor[], int tamanho_vetor)
{
    for (int indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        cout << vetor[indice_vetor] << " ";
    }
    cout << endl;
}

int buscaBinariaComparacoes(int vetor[], int tamanho_vetor, int valor, int &comparacoes)
{
    int inicio = 0;
    int final = tamanho_vetor - 1;
    comparacoes = 0;

    while (inicio <= final)
    {
        int meio = (inicio + final) / 2;
        comparacoes++;

        cout << "\n\t Comparação " << comparacoes << " → meio " << meio << " (" << vetor[meio] << ")";

        if (vetor[meio] == valor)
        {
            cout << " → achou!" << endl;
            return meio;
        }

        else if (vetor[meio] < valor)
        {
            inicio = meio + 1;
        }

        else
        {
            final = meio - 1;
        }
    }
    cout << endl;
    return -1;
}

int main()
{
    int vetor[TAM_VETOR] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    cout << "\n\t Vetor: ";
    imprimirVetor(vetor, TAM_VETOR);

    int comparacoes;
    int posicao = buscaBinariaComparacoes(vetor, TAM_VETOR, VALOR_BUSCADO, comparacoes);

    cout << "\n\t Valor " << VALOR_BUSCADO << " → posição " << posicao
         << ", " << comparacoes << " comparações" << endl;

    return 0;
}
