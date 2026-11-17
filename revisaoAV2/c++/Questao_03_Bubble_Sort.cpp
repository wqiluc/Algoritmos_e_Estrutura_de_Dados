// QUESTÃO 03 – Bubble Sort (0,5)✅
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
// Passada 1 → 2 17 4 21 8 13 19 5 11 7
// Passada 2 → 2 4 17 21 8 13 19 5 11 7
// Passada 3 → 2 4 5 17 21 8 13 19 11 7
// Passada 4 → 2 4 5 7 17 21 8 13 19 11
// Passada 5 → 2 4 5 7 8 17 21 13 19 11
// Passada 6 → 2 4 5 7 8 11 17 21 13 19
// Passada 7 → 2 4 5 7 8 11 13 17 21 19
// Passada 8 → 2 4 5 7 8 11 13 17 19 21
// Passada 9 → -
//
// Vetor final → 2 4 5 7 8 11 13 17 19 21
//
// Pergunta: em qual passada o vetor já ficou ordenado? Com a flag `trocou`,
// em qual passada o algoritmo pararia? 
// Total: 9+8+7+6+5+4+3+2+1 = 45 comparações (n(n-1)/2) e 25 trocas.
// O vetor já ficou ordenado na passada 6. 
// O código do slide não sabe disso e faz as passadas 7, 8 e 9 mesmo assim. 
// Com a flag trocou, ele pararia depois da passada 7 (a primeira sem nenhuma troca).