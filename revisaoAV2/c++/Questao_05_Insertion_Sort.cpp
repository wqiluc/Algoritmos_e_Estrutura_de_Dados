// QUESTÃO 05 – Insertion Sort (0,5)
// Ordene [19,6,15,3,22,8,11,1,17,5] mostrando todas as iterações.
//
// (Prova AV2 SI 2026.1. Na prova é NO PAPEL. Não tem código para implementar:
// é só escrever o vetor no fim de cada iteração.)
//
// Insertion Sort do slide: em cada iteração i, pega key = vetor[i], empurra
// para a direita os MAIORES que a key e encaixa a key no buraco.
//
// Valor   19  6   15  3   22  8   11  1   17  5
// Índice  0   1   2   3   4   5   6   7   8   9
//
// A barrinha | separa a parte JÁ ORDENADA (esquerda) da parte que falta
// (direita). Ela fica logo depois do índice i e anda uma casa por iteração.
//
// Início → 19 | 6 15 3 22 8 11 1 17 5
//
// Iteração 1 (i = 1) → 6 19 | 15 3 22 8 11 1 17 5
// Iteração 2 (i = 2) → 6 15 19 | 3 22 8 11 1 17 5
// Iteração 3 (i = 3) → 3 6 15 19 | 22 8 11 1 17 5
// Iteração 4 (i = 4) → 3 6 15 19 22 | 8 11 1 17 5
// Iteração 5 (i = 5) → 3 6 8 15 19 22 | 11 1 17 5
// Iteração 6 (i = 6) → 3 6 8 11 15 19 22 | 1 17 5
// Iteração 7 (i = 7) → 1 3 6 8 11 15 19 22 | 17 5
// Iteração 8 (i = 8) → 1 3 6 8 11 15 17 19 22 | 5
// Iteração 9 (i = 9) → 1 3 5 6 8 11 15 17 19 22 |
//
// Vetor final → [1, 3, 5, 6, 8, 11, 15, 17, 19, 22]


// ============================================================
// GABARITO (só olha depois de fazer!)
// ============================================================
//
// Iteração 1 (i = 1) → 6 19 | 15 3 22 8 11 1 17 5
// Iteração 2 (i = 2) → 6 15 19 | 3 22 8 11 1 17 5
// Iteração 3 (i = 3) → 3 6 15 19 | 22 8 11 1 17 5
// Iteração 4 (i = 4) → 3 6 15 19 22 | 8 11 1 17 5
// Iteração 5 (i = 5) → 3 6 8 15 19 22 | 11 1 17 5
// Iteração 6 (i = 6) → 3 6 8 11 15 19 22 | 1 17 5
// Iteração 7 (i = 7) → 1 3 6 8 11 15 19 22 | 17 5
// Iteração 8 (i = 8) → 1 3 6 8 11 15 17 19 22 | 5
// Iteração 9 (i = 9) → 1 3 5 6 8 11 15 17 19 22 |
//
// Vetor final → [1, 3, 5, 6, 8, 11, 15, 17, 19, 22]

#include <iostream>
using namespace std;

#define TAM_VETOR 10

void insertionSort(int vetor[], int tamanho_vetor)
{
    for (int i = 1; i < tamanho_vetor; i++)
    {
        int key = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > key)
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = key;
    }
}

int main()
{
    int vetor[TAM_VETOR] = {19, 6, 15, 3, 22, 8, 11, 1, 17, 5};
    int tamanho_vetor = sizeof(vetor) / sizeof(vetor[0]);

    insertionSort(vetor, tamanho_vetor);

    cout << endl << "Vetor final → ";
    for (int i = 0; i < tamanho_vetor; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << endl;

    return 0;
}
