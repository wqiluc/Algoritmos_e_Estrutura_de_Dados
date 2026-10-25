// QUESTÃO 2 – Busca Sequencial com Sentinela 
//
// Valor   42  7   19  73  4   88  25  61  [ ]
// Índice  0   1   2   3   4   5   6   7    8   ← posição extra p/ sentinela
//
// Na busca sequencial normal, o laço testa DUAS condições a cada volta:
// (i < tamanho_vetor) e (vetor[i] == valor). Com sentinela, você coloca o
// próprio valor buscado na posição extra (vetor[tamanho_vetor] = valor),
// garantindo que ele sempre será encontrado. Assim o laço só precisa
// testar UMA condição.
//
// int buscaSentinela(int vetor[], int tamanho_vetor, int valor);
//
// Declare o vetor com uma posição a mais:
// int vetor[9] = {42, 7, 19, 73, 4, 88, 25, 61};
// int tamanho_vetor = 8;
//
// Testes:
// buscar 73  → 3
// buscar 61  → 7
// buscar 100 → -1
//
// a) Depois do laço, como saber se achou um elemento de verdade ou a sentinela?
// b) Para buscar o 100, quantos testes de condição a versão normal faz?
//    E a versão com sentinela?
// c) Por que o vetor precisa ter uma posição a mais?
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// a)
// b) normal:   | sentinela:
// c)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 AV2/exércicios_buscas/Questao_02_Sequencial_Sentinela.cpp -o AV2/exércicios_buscas/q2.out && ./AV2/exércicios_buscas/q2.out

#include <iostream>
using namespace std;

int buscaSentinela(int vetor[], int tamanho_vetor, int valor)
{
    vetor[tamanho_vetor] = valor;
    int indice = 0;

    while (vetor[indice] != valor)
    {
        indice++;
    }

    if (indice < tamanho_vetor)
    {
        return indice; 
    }
    else
    {
        return -1; 
    }
}

int main()
{
    int vetor[9] = {42, 7, 19, 73, 4, 88, 25, 61};
    int tamanho_vetor = 8;
    int valor;

    cout << "\n\t Digite o valor a ser buscado: ";
    cin >> valor;

    int resultado = buscaSentinela(vetor, tamanho_vetor, valor);

    if (resultado != -1)
    {
        cout << "\n\t Valor encontrado no índice: " << resultado << endl;
    }
    else
    {
        cout << "\n\t Valor não encontrado." << endl;
    }

    return 0;
}