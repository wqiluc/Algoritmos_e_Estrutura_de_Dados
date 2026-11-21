// QUESTÃO 07 – Quick Sort (1,0)✅
// Ordene [8,3,5,1,9,2,7,0,4,6]. Utilize o último elemento como pivô. Mostre
// pivôs, comparações, trocas e subvetores.
//

// PS: o pivô (por convenção do professor Maúricio; é sempre o ÚLTIMO valor = 6)

// (Prova AV2 SI 2026.1. Na prova é NO PAPEL. Não tem código para implementar:
// é só escrever o vetor no fim de cada partição.)
//
// Partition do slide (Lomuto):
//   pivo = vetor[final]
//   i = inicio - 1
//   para j de inicio até final - 1:
//       se vetor[j] < pivo → i++ e troca vetor[i] com vetor[j]
//   no fim, troca vetor[i + 1] com vetor[final] → o pivô cai na posição i + 1
//
// Valor   8   3   5   1   9   2   7   0   4 | 6
// Índice  0   1   2   3   4   5   6   7   8   9
//
// A | separa o pivô (último) do resto do subvetor.
// No fim de cada partição fica: menores | pivô | maiores
//
// Partição 1 (idx 0..9, pivô 6)
//   início → 8 3 5 1 9 2 7 0 4 | 6

//   j=1 (3<6) troca 8↔3 → 3 8 5 1 9 2 7 0 4 | 6
//   j=2 (5<6) troca 8↔5 → 3 5 8 1 9 2 7 0 4 | 6
//   j=3 (1<6) troca 8↔1 → 3 5 1 8 9 2 7 0 4 | 6
//   j=5 (2<6) troca 8↔2 → 3 5 1 2 9 8 7 0 4 | 6
//   j=7 (0<6) troca 9↔0 → 3 5 1 2 0 8 7 9 4 | 6
//   j=8 (4<6) troca 8↔4 → 3 5 1 2 0 4 7 9 8 | 6
//   pivô: troca 7↔6     → 3 5 1 2 0 4 | 6 | 9 8 7
//   9 comparações (8, 9 e 7 não são < 6), 7 trocas
//   vetor → 3 5 1 2 0 4 6 9 8 7 · esq [3,5,1,2,0,4] · dir [9,8,7]

// Partição 2 (idx 0..5, pivô 4)
//   início              → 3 5 1 2 0 | 4
//   j=0 (3<4) fica      → 3 5 1 2 0 | 4   (troca consigo mesmo)
//   j=2 (1<4) troca 5↔1 → 3 1 5 2 0 | 4
//   j=3 (2<4) troca 5↔2 → 3 1 2 5 0 | 4
//   j=4 (0<4) troca 5↔0 → 3 1 2 0 5 | 4
//   pivô: troca 5↔4     → 3 1 2 0 | 4 | 5
//   5 comparações (5 não é < 4), 4 trocas
//   vetor → 3 1 2 0 4 5 6 9 8 7 · esq [3,1,2,0] · dir [5]

// Partição 3 (idx 0..3, pivô 0)
//   início              → 3 1 2 | 0
//   ninguém é < 0, nada troca
//   pivô: troca 3↔0     → | 0 | 1 2 3
//   3 comparações, 1 troca
//   vetor → 0 1 2 3 4 5 6 9 8 7 · esq (vazia) · dir [1,2,3]

// Partição 4 (idx 1..3, pivô 3)
//   início              → 1 2 | 3
//   j=1 (1<3) fica      → 1 2 | 3
//   j=2 (2<3) fica      → 1 2 | 3
//   pivô já no lugar    → 1 2 | 3 |
//   2 comparações, 0 trocas
//   vetor → 0 1 2 3 4 5 6 9 8 7 · esq [1,2] · dir (vazia)

// Partição 5 (idx 1..2, pivô 2)
//   início              → 1 | 2
//   j=1 (1<2) fica      → 1 | 2
//   pivô já no lugar    → 1 | 2 |
//   1 comparação, 0 trocas
//   vetor → 0 1 2 3 4 5 6 9 8 7 · esq [1] · dir (vazia)
//   ([1] e o [5] da partição 2 têm 1 elemento só → não particiona)

// Partição 6 (idx 7..9, pivô 7)
//   início              → 9 8 | 7
//   ninguém é < 7, nada troca
//   pivô: troca 9↔7     → | 7 | 8 9
//   2 comparações, 1 troca
//   vetor → 0 1 2 3 4 5 6 7 8 9 · esq (vazia) · dir [8,9]

// Partição 7 (idx 8..9, pivô 9)
//   início              → 8 | 9
//   j=8 (8<9) fica      → 8 | 9
//   pivô já no lugar    → 8 | 9 |
//   1 comparação, 0 trocas
//   vetor → 0 1 2 3 4 5 6 7 8 9 · esq [8] · dir (vazia)


// Vetor final → 0 1 2 3 4 5 6 7 8 9
// Total: 7 partições, 23 comparações, 13 trocas (sem contar troca consigo mesmo)