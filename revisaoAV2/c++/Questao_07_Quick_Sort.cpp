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
// Valor   8   3   5   1   9   2   7   0   4   6
// Índice  0   1   2   3   4   5   6   7   8   9
//
// Partição 1 (idx 0..9, pivô 6 → pos 6) → 3 5 1 2 0 4 6 9 8 7
//   esq [3,5,1,2,0,4] · dir [9,8,7] · 9 comparações

// Partição 2 (idx 0..5, pivô 4 → pos 4) → 3 1 2 0 4 5 6 9 8 7
//   esq [3,1,2,0] · dir [5] · 5 comparações

// Partição 3 (idx 0..3, pivô 0 → pos 0) → 0 1 2 3 4 5 6 9 8 7
//   esq (vazia) · dir [1,2,3] · 3 comparações

// Partição 4 (idx 1..3, pivô 3 → pos 3) → 0 1 2 3 4 5 6 9 8 7
//   esq [1,2] · dir (vazia) · 2 comparações

// Partição 5 (idx 1..2, pivô 2 → pos 2) → 0 1 2 3 4 5 6 9 8 7
//   esq [1] · dir (vazia) · 1 comparação

// Partição 6 (idx 7..9, pivô 7 → pos 7) → 0 1 2 3 4 5 6 7 8 9
//   esq (vazia) · dir [8,9] · 2 comparações

// Partição 7 (idx 8..9, pivô 9 → pos 9) → 0 1 2 3 4 5 6 7 8 9
//   esq [8] · dir (vazia) · 1 comparação


// Vetor final → 0 1 2 3 4 5 6 7 8 9
// Total: 7 partições, 23 comparações