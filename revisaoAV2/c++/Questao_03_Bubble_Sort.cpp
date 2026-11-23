// QUESTÃO 03 – Bubble Sort (0,5)
// Ordene [17,4,21,8,2,13,19,5,11,7] mostrando todas as iterações.
//
// (Prova AV2 SI 2026.1. Na prova é NO PAPEL. Não tem código para implementar:
// é só escrever o vetor no fim de cada passada.)
//
// Bubble Sort do slide (SEM a flag `trocou`): a cada passada, compara
// vetor[j] com vetor[j + 1] e troca se o da esquerda for maior. Depois da
// passada k, os k últimos já estão no lugar certo.
//
// Valor   17  4   21  8   2   13  19  5   11  7
// Índice  0   1   2   3   4   5   6   7   8   9
//
// Passada 1 → 4 17 8 2 13 19 5 11 7 21
// Passada 2 → 4 8 2 13 17 5 11 7 19 21
// Passada 3 → 4 2 8 13 5 11 7 17 19 21
// Passada 4 → 2 4 8 5 11 7 13 17 19 21
// Passada 5 → 2 4 5 8 11 7 13 17 19 21
// Passada 6 → 2 4 5 7 8 11 13 17 19 21
// Passada 7 → -
// Passada 8 → -
// Passada 9 → -
//
// Vetor final →
//
// Pergunta: em qual passada o vetor já ficou ordenado? Com a flag `trocou`,
// em qual passada o algoritmo pararia? Quantas comparações e trocas no total?
// Resposta →  Total: 9+8+7+6+5+4+3+2+1 = 45 comparações (n(n-1)/2) e 25 trocas.
// O vetor já ficou ordenado na passada 6.

// ============================================================
// GABARITO (só olha depois de fazer!)
// ============================================================
//
// Passada 1 → 4 17 8 2 13 19 5 11 7 21   (8 trocas)
// Passada 2 → 4 8 2 13 17 5 11 7 19 21   (6 trocas)
// Passada 3 → 4 2 8 13 5 11 7 17 19 21   (4 trocas)
// Passada 4 → 2 4 8 5 11 7 13 17 19 21   (4 trocas)
// Passada 5 → 2 4 5 8 7 11 13 17 19 21   (2 trocas)
// Passada 6 → 2 4 5 7 8 11 13 17 19 21   (1 troca)
// Passada 7 → nada muda                  (0 trocas)
// Passada 8 → nada muda                  (0 trocas)
// Passada 9 → nada muda                  (0 trocas)
//
// Vetor final → [2, 4, 5, 7, 8, 11, 13, 17, 19, 21]
//
// Total: 9+8+7+6+5+4+3+2+1 = 45 comparações (n(n-1)/2) e 25 trocas.
// O vetor já ficou ordenado na passada 6.
// O código do slide não sabe disso e faz as passadas 7, 8 e 9 mesmo assim.
// Com a flag trocou, ele pararia depois da passada 7 (a primeira sem nenhuma troca).

#include <iostream>
#include <utility>

using namespace std;

int bubbleSort(int vetor[], int tamanho_vetor)
{
    for (int i = 0; i < tamanho_vetor - 1; i++)
    {
        for (int j = 0; j < tamanho_vetor - 1 - i; j++)
        {
            if (vetor[j] > vetor[j+1])
            {
                swap(vetor[j], vetor[j+1]);
            }
        }
    }
}

int main()
{
    int vetor[] = {17, 4, 21, 8, 2, 13, 19, 5, 11, 7};
    int tamanho_vetor = sizeof(vetor) / sizeof(vetor[0]);

    bubbleSort(vetor, tamanho_vetor);

    for (int i = 0; i < tamanho_vetor; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << endl;

    return 0;
}
