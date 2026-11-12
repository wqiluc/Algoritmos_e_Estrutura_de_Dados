// QUESTÃO 1 – Busca Sequencial: encontrar um valor
//
// Encontre o número 25 no vetor usando busca sequencial.

// ex: {15, 8, 25, 7, 12, 18, 5, 9, 30, 3}; (procurando o 25) → posição 2

// int buscaSequencial(int vetor[], int tamanho_vetor, int valor_buscado);
// → retorna a posição do valor (ou -1 se não encontrar)

// Testes:
// valor 25 → encontrado na posição 2 (3 comparações: 15, 8, 25)

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista 1 - 2ª unidade/Questao_01_Sequencial_Encontrar.cpp" -o "AV2/lista 1 - 2ª unidade/q1.out" && "./AV2/lista 1 - 2ª unidade/q1.out"

#include <iostream>
using namespace std;

#define TAMANHO_VETOR 10

int buscaSequencial(int vetor[], int tamanho_vetor, int valor_buscado) 
{
   int indice;

   for (indice = 0; indice < tamanho_vetor; indice++) 
   {
      if (vetor[indice] == valor_buscado) 
      {
         return indice;
      }
   }
    return -1; // Valor não encontrado
}

int main() 
{
   int vetor[TAMANHO_VETOR] = {15, 8, 25, 7, 12, 18, 5, 9, 30, 3};
   int valor_buscado;

   cout << "Digite o valor a ser buscado: ";
    cin >> valor_buscado;

   int posicao = buscaSequencial(vetor, TAMANHO_VETOR, valor_buscado);

   if (posicao != -1) 
   {
      cout << "Valor " << valor_buscado << " encontrado na posição: " << posicao << endl;
   } 
   else 
   {
      cout << "Valor " << valor_buscado << " não encontrado no vetor." << endl;
   }

   return 0;
}