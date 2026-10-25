// QUESTÃO 1 – Busca Sequencial com Contador

// Valor   42  7   19  73  4   88  25  61
// Índice  0   1   2   3   4   5   6   7
//
// Implemente a busca sequencial que, além de retornar o índice, conta
// quantas comparações (vetor[i] == valor) foram feitas:
//
// int buscaSequencialContando(int vetor[], int tamanho_vetor, int valor, int &comparacoes);
//
// No main, leia o valor do teclado e mostre o índice e o nº de comparações.
//
// Testes:
// buscar 42 → 0
// buscar 88 → 5
// buscar 61 → 7
// buscar 50 → -1
//
// a) Quantas comparações para cada teste acima?
// b) Qual o número médio de comparações para chaves que estão no vetor?
// c) E para uma chave que NÃO está no vetor?
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// a) 42: 0 | 88: 5 | 61: 7 | 50: 8
// b) (0 + 5 + 7) / 3 = 4
// c) (8 + 8 + 8 + 8) / 4 = 8
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 AV2/exércicios_buscas/Questao_01_Sequencial_Contador.cpp -o AV2/exércicios_buscas/q1.out && ./AV2/exércicios_buscas/q1.out

#include <iostream>
using namespace std;

int buscaSequencial(int vetor[], int tamanho_vetor, int valor, int &comparacoes) 
{
    comparacoes = 0;
    int indice_vetor;

    for (indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++) 
    {
        comparacoes++;
        
        if (vetor[indice_vetor] == valor) 
        {
            return indice_vetor;
        }
    }
    return -1;
}

int main() 
{
    int vetor[] = {42, 7, 19, 73, 4, 88, 25, 61};
    int tamanho_vetor = sizeof(vetor) / sizeof(vetor[0]);
    int valor;
    int comparacoes = 0;

    cout << "\n\t Digite o valor a ser buscado: ";
    cin >> valor;

    int indice = buscaSequencial(vetor, tamanho_vetor, valor, comparacoes);

    if (indice != -1) 
    {
        cout << "Valor encontrado no índice: " << indice << endl;
    } 

    else 
    {
        cout << "Valor não encontrado." << endl;
    }

    cout << "Número de comparações: " << comparacoes << endl;

    return 0;
}