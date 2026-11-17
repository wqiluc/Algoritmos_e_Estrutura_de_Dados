// QUESTÃO 08 – Merge Sort (1,0)
// Ordene [9,2,7,4,6,1,5,0,8,3]. Mostre divisões, comparações, merges e vetor
// final.
//
// (Prova AV2 SI 2026.1. Na prova é NO PAPEL. Não tem código para implementar:
// é só escrever os vetores de cada divisão e de cada merge.)
//
// Merge Sort do slide:
//   meio = esquerda + (direita - esquerda) / 2
//   a metade da esquerda vai de esquerda até meio (inclusive), então quando o
//   tamanho é ímpar a esquerda fica com 1 a mais
//   no intercalar, use <= (no empate, sai o da esquerda)
//
// Valor   9   2   7   4   6   1   5   0   8   3
// Índice  0   1   2   3   4   5   6   7   8   9
//
// Divisões (trecho → esquerda | direita):
// [9 2 7 4 6 1 5 0 8 3] →
//
//
//
//
//
//
//
//
//
// Merges (esquerda + direita → resultado), na ordem em que a recursão executa:
// Merge 1 →
// Merge 2 →
// Merge 3 →
// Merge 4 →
// Merge 5 →
// Merge 6 →
// Merge 7 →
// Merge 8 →
// Merge 9 →
//
// Vetor final →
