// QUESTÃO EXTRA 01 – Bubble Sort (0,5)
// Ordene [14,6,25,10,3,18,30,8,21,12] mostrando todas as iterações.
//
// (Treino no estilo da Questão 03 da AV2 SI 2026.1. Na prova é NO PAPEL:
// é só escrever o vetor no fim de cada passada.)
//
// Bubble Sort do slide (SEM a flag `trocou`): a cada passada, compara
// vetor[j] com vetor[j + 1] e troca se o da esquerda for maior. Depois da
// passada k, os k últimos já estão no lugar certo.
//
// Valor   14  6   25  10  3   18  30  8   21  12
// Índice  0   1   2   3   4   5   6   7   8   9
//
// Passada 1 → 6 14 10 3 18 25 8 21 12 30 - (7 trocas)
// Passada 2 → 6 10 3 14 18 8 21 12 25 30 - (5 trocas)
// Passada 3 → 6 3 10 14 8 18 12 21 25 30 - (3 trocas)
// Passada 4 → 3 6 10 8 14 12 18 21 25 30 - (3 trocas)
// Passada 5 → 3 6 8 10 12 14 18 21 25 30 - (2 trocas)
// Passada 6 → - (0)
// Passada 7 → - (0)
// Passada 8 → - (0)
// Passada 9 → - (0)
//
// Vetor final → [3, 6, 8, 10, 12, 14, 18, 21, 25, 30]
//
// Perguntas:
// a) Em qual passada o vetor já ficou ordenado? 5
// b) Com a flag `trocou`, em qual passada o algoritmo pararia? 6
// c) Quantas comparações e quantas trocas o código do slide faz no total? 20
// ============================================================================
// GABARITO (só olhe depois de fazer!)
// ============================================================================
//
// Passada 1 → 6 14 10 3 18 25 8 21 12 30 - (7 trocas)
// Passada 2 → 6 10 3 14 18 8 21 12 25 30 - (5 trocas)
// Passada 3 → 6 3 10 14 8 18 12 21 25 30 - (3 trocas)
// Passada 4 → 3 6 10 8 14 12 18 21 25 30 - (3 trocas)
// Passada 5 → 3 6 8 10 12 14 18 21 25 30 - (2 trocas)
// Passada 6 → - (0)
// Passada 7 → - (0)
// Passada 8 → - (0)
// Passada 9 → - (0)
//
// Vetor final → [3 6 8 10 12 14 18 21 25 30]
//
// a) O vetor já ficou ordenado na passada 5.
// b) Com a flag `trocou`, ele pararia depois da passada 6 (a primeira sem
//    nenhuma troca). O código do slide faz as passadas 6, 7, 8 e 9 à toa.
// c) Comparações: 9+8+7+6+5+4+3+2+1 = 45 (n(n-1)/2).
//    Trocas: 7+5+3+3+2 = 20.