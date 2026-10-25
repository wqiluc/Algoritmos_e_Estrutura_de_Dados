// QUESTÃO 5 – Encadeamento (✏️ papel)
//
// TAM = 7, funcaoHash(k) = k % 7, encadeamento com inserção no início
// (igual ao slide). Insira, nesta ordem:
//
// 15, 8, 22, 4, 11, 30, 7
//
// a) Desenhe a tabela com as listas.
// b) Quantas comparações para buscar o 15? E o 18?
// c) Qual a pior situação possível para essa tabela?
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// a) [0]: 7 
//    [1]: 22
//    [2]: 30
//    [3]: - 
//    [4]: 11
//    [5]: - 
//    [6]: -
// b) 15: 1 comparações | 18: 2 comparações
    // c) A pior situação possível para essa tabela seria quando todos os elementos 
    // inseridos colidem no mesmo índice da tabela, 
    // formando uma lista encadeada muito longa. 
    // Isso resultaria em uma busca linear para encontrar um elemento, 
    // aumentando significativamente o tempo de busca. 
    // Por exemplo, se todos os elementos inseridos fossem múltiplos de 7, 
    // todos eles seriam armazenados na mesma posição da tabela, 
    // tornando a busca ineficiente.
//
// Compilar e rodar:
// g++ -std=c++17 Questao_05_Encadeamento.cpp -o q5.out && ./q5.out

#include <iostream>
using namespace std;

#define TAM 7

int funcaoHash(int k) 
{
    return k % TAM;
}

int main() 
{
    int tabela[TAM] = {0}; 
    int elementos[] = {15, 8, 22, 4, 11, 30, 7};
    int n = sizeof(elementos) / sizeof(elementos[0]);

    for (int i = 0; i < n; i++) 
    {
        int index = funcaoHash(elementos[i]);

        if (tabela[index] == 0) 
        {
            tabela[index] = elementos[i];
        } 

        else 
        {
            int temp = tabela[index];
            tabela[index] = elementos[i];
        }
    }

    cout << "Tabela de Hash com Encadeamento: \n";
    
    for (int i = 0; i < TAM; i++) 
    {
        cout << "[" << i << "]: ";

        if (tabela[i] != 0) 
        {
            cout << tabela[i];
        }
        cout << endl;
    }
    return 0;
}