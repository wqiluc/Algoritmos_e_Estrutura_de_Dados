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
// Árvore — cada nó: trecho dividido em esquerda | direita, e embaixo (Mx ↑) o
// resultado do merge daquele nó, quando a recursão volta
//
//                       [9 2 7 4 6 | 1 5 0 8 3]                  ← D1 (raiz)
//                     M9 ↑ [0 1 2 3 4 5 6 7 8 9]
//                      /                     \
//             [9 2 7 | 4 6]               [1 5 0 | 8 3]          ← D2 · D6
//           M4 ↑ [2 4 6 7 9]            M8 ↑ [0 1 3 5 8]
//              /        \                 /          \
//        [9 2 | 7]     [4 | 6]       [1 5 | 0]      [8 | 3]      ← D3 · D5 · D7 · D9
//      M2 ↑ [2 7 9]  M3 ↑ [4 6]    M6 ↑ [0 1 5]   M7 ↑ [3 8]
//         /     \                    /     \
//     [9 | 2]   [7]              [1 | 5]   [0]                   ← D4 · D8
//   M1 ↑ [2 9]                 M5 ↑ [1 5]
//
//   LADO ESQUERDO  = idx 0..4 (resolve PRIMEIRO, inteiro → [2 4 6 7 9])
//   LADO DIREITO   = idx 5..9 (só depois que a esquerda acaba → [0 1 3 5 8])
//   MERGE FINAL    = junta os dois lados
//

// -----------------------------------------------------------------------------
// DIVISÕES (trecho → esquerda | direita), na ordem da recursão
// -----------------------------------------------------------------------------
// D1 (idx 0..9, meio 4) → [9 2 7 4 6 1 5 0 8 3] → [9 2 7 4 6] | [1 5 0 8 3]
// D2 (idx 0..4, meio 2) → [9 2 7 4 6]           → [9 2 7] | [4 6]
// D3 (idx 0..2, meio 1) → [9 2 7]               → [9 2] | [7]
// D4 (idx 0..1, meio 0) → [9 2]                 → [9] | [2]
// D5 (idx 3..4, meio 3) → [4 6]                 → [4] | [6]
// D6 (idx 5..9, meio 7) → [1 5 0 8 3]           → [1 5 0] | [8 3]
// D7 (idx 5..7, meio 6) → [1 5 0]               → [1 5] | [0]
// D8 (idx 5..6, meio 5) → [1 5]                 → [1] | [5]
// D9 (idx 8..9, meio 8) → [8 3]                 → [8] | [3]
//
// -----------------------------------------------------------------------------
// MERGES (esquerda + direita → resultado), na ordem em que a recursão executa
// -----------------------------------------------------------------------------
// Merge 1 (idx 0..1) → [9] + [2]                     → [2 9]                 · 1 comp
// Merge 2 (idx 0..2) → [2 9] + [7]                   → [2 7 9]               · 2 comp
// Merge 3 (idx 3..4) → [4] + [6]                     → [4 6]                 · 1 comp
// Merge 4 (idx 0..4) → [2 7 9] + [4 6]               → [2 4 6 7 9]           · 3 comp
// Merge 5 (idx 5..6) → [1] + [5]                     → [1 5]                 · 1 comp
// Merge 6 (idx 5..7) → [1 5] + [0]                   → [0 1 5]               · 1 comp
// Merge 7 (idx 8..9) → [8] + [3]                     → [3 8]                 · 1 comp
// Merge 8 (idx 5..9) → [0 1 5] + [3 8]               → [0 1 3 5 8]           · 4 comp
// Merge 9 (idx 0..9) → [2 4 6 7 9] + [0 1 3 5 8]     → [0 1 2 3 4 5 6 7 8 9] · 9 comp
//
// Vetor final → 0 1 2 3 4 5 6 7 8 9
// Total: 9 divisões, 9 merges, 23 comparações
//   esquerda (M1–M4) → 7 comp
//   direita  (M5–M8) → 7 comp
//   final    (M9)    → 9 comp