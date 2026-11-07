// QUESTÃO 1 – Busca Sequencial: Posição de Inserção
//
// Adapte a busca sequencial para que, caso o valor procurado não seja
// encontrado, retorne a posição onde o valor poderia ser inserido para
// manter a ordem crescente do vetor.
//
// Valor   3   8   12  17  25  31  40
// Índice  0   1   2   3   4   5   6
//
// ex: {3, 8, 12, 17, 25, 31, 40}; (procurando o 20) → não encontrado, inserir na posição 4
//
// int buscaSequencialInsercao(int vetor[], int tamanho_vetor, int valor, bool &encontrado);
    // → se encontrar: 
    // encontrado = true  e retorna a posição do valor
    // → se não:       
    // encontrado = false e retorna a posição de inserção
//
// No main, leia o valor do teclado e mostre o resultado.
//
// Testes:
// valor 17 → encontrado na posição 3
// valor 3  → encontrado na posição 0
// valor 20 → não encontrado, inserir na posição 4
// valor 1  → não encontrado, inserir na posição 0
// valor 50 → não encontrado, inserir na posição 7 (fim do vetor)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios pdf/Questao_01_Sequencial_Posicao_Insercao.cpp" -o "AV2/exércicios pdf/q1.out" && "./AV2/exércicios pdf/q1.out"

#include <iostream>
using namespace std;

#define TAM_VETOR 7

int buscaSequencialInsercao(int vetor[], int tamanho_vetor, int valor, bool &encontrado)
{
    int indice_insercao;

    for (indice_insercao = 0; indice_insercao < tamanho_vetor; indice_insercao++)
    {
        if(vetor[indice_insercao] == valor)
        {
            encontrado = true;
            return indice_insercao;
        }

        else if(vetor[indice_insercao] > valor)
        {
            encontrado = false;
            return indice_insercao;
        }
    }
    encontrado = false;
    return tamanho_vetor;
}

int main()
{
    int vetor[TAM_VETOR] = {3, 8, 12, 17, 25, 31, 40};
    int valor;
    bool encontrado;
    
    cout << "\n\t Digite o valor a ser buscado: ";
    cin >> valor;

    int posicao = buscaSequencialInsercao(vetor, TAM_VETOR, valor, encontrado);

    if (encontrado) 
    {
        cout << "\n\t Valor " << valor << " encontrado na posição " << posicao << endl;
    }

    else 
    {
        cout << "\n\t Valor " << valor << " não encontrado, inserir na posição " << posicao << endl;
    }
    return 0;
}