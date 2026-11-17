// QUESTÃO 06 – Shell Sort (1,0)✅
// Ordene [12,5,9,3,10,1,8,4] com gaps 4, 2 e 1. Mostre gaps, comparações e
// vetor ao final de cada iteração.
//
// (Prova AV2 SI 2026.1. Na prova é NO PAPEL. Não tem código para implementar:
// é só escrever o vetor no fim de cada gap.)
//
// Shell Sort do slide (n = 8 → gaps 8/2 = 4, 4/2 = 2, 2/2 = 1, que são
// exatamente os gaps pedidos). Para cada i, guarda temp = vetor[i] e compara
// vetor[j - gap] > temp, deslocando de gap em gap.
//
// Valor   12  5   9   3   10  1   8   4
// Índice  0   1   2   3   4   5   6   7
//
// Gap 4 → 10 1 8 3 12 5 9 4
//   sublistas (0,4) (1,5) (2,6) (3,7): 12,10→10,12 - 5,1→1,5 - 9,8→8,9 = 3,4 (ok)
//   4 comparações, 3 deslocamentos


// Gap 2 → 8 1 9 3 10 4 12 5
//   pares (0,2,4,6): 10,8,12,9 → 8,9,10,12 · ímpares (1,3,5,7): 1,3,5,4 → 1,3,4,5
//   9 comparações, 4 deslocamentos


// Gap 1 → 1 3 4 5 8 9 10 12
//   (Insertion Sort normal) 16 comparações, 10 deslocamentos
//
// Vetor final → 1 3 4 5 8 9 10 12
// Total: 29 comparações, 17 deslocamentos