// QUESTÃO EXTRA 02 – Bubble Sort (0,5)
// Ordene [23,9,15,3,31,12,6,27,18,1] mostrando todas as iterações.
//
// (Treino no estilo da Questão 03 da AV2 SI 2026.1. Na prova é NO PAPEL:
// é só escrever o vetor no fim de cada passada.)
//
// Bubble Sort do slide (SEM a flag `trocou`): a cada passada, compara
// vetor[j] com vetor[j + 1] e troca se o da esquerda for maior. Depois da
// passada k, os k últimos já estão no lugar certo.
//
// Valor   23  9   15  3   31  12  6   27  18  1
// Índice  0   1   2   3   4   5   6   7   8   9
//
// Passada 1 → 9 15 3 23 12 6 27 18 1 31 - (8 trocas)
// Passada 2 → 9 3 15 12 6 23 18 1 27 31 - (5 trocas)
// Passada 3 → 3 9 12 6 15 18 1 23 27 31 - (5 trocas)
// Passada 4 → 3 9 6 12 15 1 18 23 27 31 - (2 trocas)
// Passada 5 → 3 6 9 12 1 15 18 23 27 31 - (2 trocas)
// Passada 6 → 3 6 9 1 12 15 18 23 27 31 - (1 troca)
// Passada 7 → 3 6 1 9 12 15 18 23 27 31 - (1 troca)
// Passada 8 → 3 1 6 9 12 15 18 23 27 31 - (1 troca)
// Passada 9 → 1 3 6 9 12 15 18 23 27 31 - (1 troca)
//
// Vetor final → [1, 3, 6, 9, 12, 15, 18, 23, 27, 31]
//
// Perguntas:
// a) Em qual passada o vetor já ficou ordenado? 9
// b) Com a flag `trocou`, o algoritmo economizaria alguma passada? Por quê? não,
// toda passada faz pelo menos 1 troca, então a flag nunca fica falsa
// c) Quantas posições o 1 anda para a esquerda em cada passada? E o 31,
//    quantas posições ele anda para a direita na passada 1?
// 1 = só 1 posição por passada (índice 9 → 8 → ... → 0) / 31 = 5 (índice 4 → 9)
// d) Quantas comparações e quantas trocas o código do slide faz no total?
// 45 comparações (9+8+...+1) e 26 trocas (8+5+5+2+2+1+1+1+1)
//
// ============================================================================
// GABARITO (só olhe depois de fazer!)
// ============================================================================
//
// Passada 1 → 9 15 3 23 12 6 27 18 1 31 - (8 trocas)
// Passada 2 → 9 3 15 12 6 23 18 1 27 31 - (5 trocas)
// Passada 3 → 3 9 12 6 15 18 1 23 27 31 - (5 trocas)
// Passada 4 → 3 9 6 12 15 1 18 23 27 31 - (2 trocas)
// Passada 5 → 3 6 9 12 1 15 18 23 27 31 - (2 trocas)
// Passada 6 → 3 6 9 1 12 15 18 23 27 31 - (1 troca)
// Passada 7 → 3 6 1 9 12 15 18 23 27 31 - (1 troca)
// Passada 8 → 3 1 6 9 12 15 18 23 27 31 - (1 troca)
// Passada 9 → 1 3 6 9 12 15 18 23 27 31 - (1 troca)
//
// Vetor final → [1 3 6 9 12 15 18 23 27 31]
//
// a) Só na passada 9, a última.
// b) Não. Toda passada teve pelo menos uma troca, então a flag `trocou`
//    nunca fica falsa e o algoritmo faz as 9 passadas de qualquer jeito.
// c) O 1 anda só UMA posição por passada (índice 9 → 8 → 7 → ... → 0), por
//    isso precisa de 9 passadas. É a "tartaruga" do Bubble Sort: elemento
//    pequeno no fim é o pior caso para ele.
//    Já o 31 (a "lebre") vai do índice 4 até o índice 9 numa passada só,
//    andando 5 posições.
// d) Comparações: 9+8+7+6+5+4+3+2+1 = 45 (n(n-1)/2).
//    Trocas: 8+5+5+2+2+1+1+1+1 = 26.
