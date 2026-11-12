// QUESTÃO 3 – Busca Binária: Matriz Ordenada
//
// A matriz abaixo está ordenada linha a linha, e cada linha começa com um valor
// maior que o último da linha anterior. Ou seja: lida em sequência, ela é um
// vetor ordenado de LINHAS * COLUNAS elementos.
//
//            col 0  col 1  col 2  col 3
// linha 0      2      4      7     10
// linha 1     13     15     18     21
// linha 2     25     29     33     40
//
// Faça a busca binária "fingindo" que é um vetor de índices 0 a 11. Para cada
// meio, converta o índice em linha e coluna:
//   linha  = meio / COLUNAS
//   coluna = meio % COLUNAS
//
// ex: meio = 9 → linha 9 / 4 = 2, coluna 9 % 4 = 1 → matriz[2][1] = 29
//
// bool buscaBinariaMatriz(int matriz[][COLUNAS], int valor, int &linha, int &coluna);
// → retorna true e preenche linha/coluna, ou false se não achar
// → imprima, a cada passo: inicio, fim, meio e a célula visitada
//
// Use #define LINHAS 3 e #define COLUNAS 4 (não vale copiar a matriz para um vetor!).
// No main, leia o valor do teclado e mostre o resultado.
//
// Testes:
// valor 29 → linha 2, coluna 1
//   inicio=0 fim=11 meio=5  → [1][1] = 15 → menor, vai para a direita
//   inicio=6 fim=11 meio=8  → [2][0] = 25 → menor, vai para a direita
//   inicio=9 fim=11 meio=10 → [2][2] = 33 → maior, vai para a esquerda
//   inicio=9 fim=9  meio=9  → [2][1] = 29 → achou!
// valor 2  → linha 0, coluna 0 (3 passos: 15, 7, 2)
// valor 40 → linha 2, coluna 3 (4 passos: 15, 25, 33, 40)
// valor 18 → linha 1, coluna 2 (3 passos: 15, 25, 18)
// valor 20 → não encontrado    (4 passos: 15, 25, 18, 21)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Buscas/exércicios_binárias/Questao_03_Binaria_Matriz_Ordenada.cpp" -o "AV2/Buscas/exércicios_binárias/q3.out" && "./AV2/Buscas/exércicios_binárias/q3.out"

#include <iostream>
using namespace std;

#define LINHAS 3
#define COLUNAS 4

int buscaBinariaMatriz(int matriz[LINHAS][COLUNAS], int valor, int &linha, int &coluna) 
{
   int inicio = 0;
   int fim = LINHAS * COLUNAS - 1;
   int meio;

   while (inicio <= fim)
   {
        meio = (inicio + fim) / 2;

        linha = meio / COLUNAS;
        coluna = meio % COLUNAS;
    
        cout << "inicio=" << inicio << " fim=" << fim << " meio=" << meio
             << " → [" << linha << "][" << coluna << "] = " << matriz[linha][coluna] << endl;
    
        if (matriz[linha][coluna] == valor)
        {
             return true;
        }

        else if (matriz[linha][coluna] < valor)
        {
             inicio = meio + 1; // remove a metade esquerda
        }

        else 
        {
             fim = meio - 1; // remove a metade direita
        }
   }
   return false;
}

int main() 
{
   int matriz[LINHAS][COLUNAS] = 
   {
       {2, 4, 7, 10},
       {13, 15, 18, 21},
       {25, 29, 33, 40}
   };

   int valor;
   cout << "Digite o valor a ser buscado: ";
   cin >> valor;

   int linha, coluna;

   if (buscaBinariaMatriz(matriz, valor, linha, coluna)) 
   {
       cout << "Valor " << valor << " encontrado na linha " << linha
            << ", coluna " << coluna << "." << endl;
   } 
   
   else 
   {
       cout << "Valor " << valor << " não encontrado." << endl;
   }

   return 0;
}