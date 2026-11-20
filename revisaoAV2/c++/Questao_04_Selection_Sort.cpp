// QUESTÃO 04 – Selection Sort (0,5)
// Ordene [23,9,14,5,18,2,20,7,12,4] mostrando todas as iterações.
//
// (Prova AV2 SI 2026.1. Na prova é NO PAPEL. Não tem código para implementar:
// é só escrever o vetor no fim de cada iteração.)
//
// Selection Sort do slide: em cada iteração i, acha o MENOR do trecho
// vetor[i..n-1] e troca com vetor[i].
//
// Valor   23  9   14  5   18  2   20  7   12  4
// Índice  0   1   2   3   4   5   6   7   8   9
//
// Iteração 1 (i = 0) → 2 9 14 5 18 23 20 7 12 4
// Iteração 2 (i = 1) → 2 4 14 5 18 23 20 7 12 9
// Iteração 3 (i = 2) → 2 4 5 14 18 23 20 7 12 9
// Iteração 4 (i = 3) → 2 4 5 7 18 23 20 14 12 9
// Iteração 5 (i = 4) → 2 4 5 7 9 23 20 14 12 18
// Iteração 6 (i = 5) → 2 4 5 7 9 12 20 14 23 18
// Iteração 7 (i = 6) → 2 4 5 7 9 12 14 20 23 18
// Iteração 8 (i = 7) → 2 4 5 7 9 12 14 18 23 20
// Iteração 9 (i = 8) → 2 4 5 7 9 12 14 18 20 23
//
// Vetor final → [2, 4, 5, 7, 9, 12, 14, 18, 20, 23]

// ============================================================
// GABARITO (só olha depois de fazer!)
// ============================================================
//
// Iteração 1 (i = 0) → 2 9 14 5 18 23 20 7 12 4
// Iteração 2 (i = 1) → 2 4 14 5 18 23 20 7 12 9
// Iteração 3 (i = 2) → 2 4 5 14 18 23 20 7 12 9
// Iteração 4 (i = 3) → 2 4 5 7 18 23 20 14 12 9
// Iteração 5 (i = 4) → 2 4 5 7 9 23 20 14 12 18
// Iteração 6 (i = 5) → 2 4 5 7 9 12 20 14 23 18
// Iteração 7 (i = 6) → 2 4 5 7 9 12 14 20 23 18
// Iteração 8 (i = 7) → 2 4 5 7 9 12 14 18 23 20
// Iteração 9 (i = 8) → 2 4 5 7 9 12 14 18 20 23
//
// Vetor final → [2, 4, 5, 7, 9, 12, 14, 18, 20, 23]
