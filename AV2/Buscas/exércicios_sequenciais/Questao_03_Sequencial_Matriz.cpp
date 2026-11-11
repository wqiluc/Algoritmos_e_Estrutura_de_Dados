// QUESTÃO 3 – Busca Sequencial: em Matriz
//
// Adapte a busca sequencial para procurar um valor numa matriz 3x4,
// percorrendo linha por linha (da esquerda para a direita, de cima para baixo).
//
//            col 0  col 1  col 2  col 3
// linha 0      5     12      7      3
// linha 1      9      3     14      6
// linha 2     11      8      3      2
//
// ex: procurando o 14 → linha 1, coluna 2
//
// bool buscarNaMatriz(int matriz[][COLUNAS], int valor, int &linha, int &coluna);
// → retorna true e preenche linha/coluna com a PRIMEIRA ocorrência
// → retorna false se o valor não estiver na matriz
//
// int contarNaMatriz(int matriz[LINHAS][COLUNAS], int valor);
// → quantas vezes o valor aparece
//
// Use #define LINHAS 3 e #define COLUNAS 4.
// No main, leia o valor do teclado e mostre o resultado.
//
// Testes:
// valor 14 → linha 1, coluna 2 (aparece 1 vez)
// valor 3  → linha 0, coluna 3 (aparece 3 vezes: [0][3], [1][1] e [2][2])
// valor 5  → linha 0, coluna 0 (aparece 1 vez, é o primeiro elemento)
// valor 2  → linha 2, coluna 3 (aparece 1 vez, é o último elemento)
// valor 10 → não encontrado    (aparece 0 vezes)
//
// Pergunta: no pior caso, quantas comparações a busca faz numa matriz L x C?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Buscas/exércicios_sequenciais/Questao_03_Sequencial_Matriz.cpp" -o "AV2/Buscas/exércicios_sequenciais/q3.out" && "./AV2/Buscas/exércicios_sequenciais/q3.out"

#include <iostream>
using namespace std;

#define LINHAS 3
#define COLUNAS 4

bool buscarNaMatriz(int matriz[LINHAS][COLUNAS], int valor, int &linha, int &coluna)
{
    int i, j;

    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            if (matriz[i][j] == valor)
            {
                linha = i;
                coluna = j;
                return true;
            }
        }
    }
    return false;
}

int contarNaMatriz(int matriz[LINHAS][COLUNAS], int valor)
{
    int i, j, contador = 0;

    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            if (matriz[i][j] == valor)
            {
                contador++;
            }
        }
    }
    return contador;
}

int main()
{
    int matriz[LINHAS][COLUNAS] = 
    {
        {5, 12, 7, 3},
        {9, 3, 14, 6},
        {11, 8, 3, 2}
    };

    int valor;
    cout << "Digite o valor a ser buscado: ";
    cin >> valor;

    int linha, coluna;

    bool encontrado = buscarNaMatriz(matriz, valor, linha, coluna);
    int quantidade = contarNaMatriz(matriz, valor);

    if (encontrado)
    {
        cout << "Valor " << valor << " encontrado na linha " << linha << ", coluna " << coluna << endl;
        cout << "Quantidade de ocorrencias: " << quantidade << endl;
    }

    else
    {
        cout << "Valor " << valor << " nao encontrado." << endl;
        cout << "Quantidade de ocorrencias: " << quantidade << endl;
    }
    return 0;
}