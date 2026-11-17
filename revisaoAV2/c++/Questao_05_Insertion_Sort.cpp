// QUESTÃO 05 – Insertion Sort (0,5)✅
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
// Iteração 1 (i = 1) → 1 19 6 15 3 22 8 11 17 5
// Iteração 2 (i = 2) → 1 3 19 6 15 22 8 11 17 5
// Iteração 3 (i = 3) → 1 3 5 19 6 15 22 8 11 17
// Iteração 4 (i = 4) → 1 3 5 6 19 15 22 8 11 17
// Iteração 5 (i = 5) → 1 3 5 6 8 19 15 22 11 17
// Iteração 6 (i = 6) → 1 3 5 6 8 11 19 15 22 17
// Iteração 7 (i = 7) → 1 3 5 6 8 11 15 19 22 17
// Iteração 8 (i = 8) → 1 3 5 6 8 11 15 17 19 22
// Iteração 9 (i = 9) → 1 3 5 6 8 11 15 17 19 22
//
// Vetor final → [1, 3, 5, 6, 8, 11, 15, 17, 19, 22]