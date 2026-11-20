// QUESTÃO EXTRA 03 – Selection Sort (0,5)
// Ordene [3,16,8,11,29,13,21,15,26,24] mostrando todas as iterações.
//
// (Treino no estilo da Questão 04 da AV2 SI 2026.1. Na prova é NO PAPEL:
// é só escrever o vetor no fim de cada iteração.)
//
// Selection Sort do slide: em cada iteração i, acha o MENOR do trecho
// vetor[i..n-1] e troca com vetor[i]. O código do slide faz a troca mesmo
// quando o menor já está em vetor[i] (troca o elemento com ele mesmo).
//
// Valor   3   16  8   11  29  13  21  15  26  24
// Índice  0   1   2   3   4   5   6   7   8   9
//
// Iteração 1 (i = 0) → 3 16 8 11 29 13 21 15 26 24 - (menor = 3, já no lugar)
// Iteração 2 (i = 1) → 3 8 16 11 29 13 21 15 26 24 - (16 ↔ 8)
// Iteração 3 (i = 2) → 3 8 11 16 29 13 21 15 26 24 - (16 ↔ 11)
// Iteração 4 (i = 3) → 3 8 11 13 29 16 21 15 26 24 - (16 ↔ 13)
// Iteração 5 (i = 4) → 3 8 11 13 15 16 21 29 26 24 - (29 ↔ 15)
// Iteração 6 (i = 5) → 3 8 11 13 15 16 21 29 26 24 - (menor = 16, já no lugar)
// Iteração 7 (i = 6) → 3 8 11 13 15 16 21 29 26 24 - (menor = 21, já no lugar)
// Iteração 8 (i = 7) → 3 8 11 13 15 16 21 24 26 29 - (29 ↔ 24)
// Iteração 9 (i = 8) → 3 8 11 13 15 16 21 24 26 29 - (menor = 26, já no lugar)
//
// Vetor final → [3, 8, 11, 13, 15, 16, 21, 24, 26, 29]
//
// Perguntas:
// a) Em quais iterações o menor JÁ estava na posição i (troca consigo mesmo)?
// 1, 6, 7 e 9 (o vetor não muda: repete a linha de cima)
// b) Em qual iteração o vetor ficou ordenado? O algoritmo para ali?
// na 8, mas não para: o Selection não tem flag e sempre faz as n-1 = 9 iterações
// c) Acompanhe o 16: em quais iterações ele muda de lugar e por quais
//    índices ele passa até chegar na posição final?
// nas iterações 2, 3 e 4: índice 1 → 2 → 3 → 5 (ele estava em vetor[i] e foi
// jogado para onde o menor estava)
// d) Quantas comparações e quantas trocas REAIS o código do slide faz?
// 45 comparações (9+8+...+1) e 5 trocas reais (iterações 2, 3, 4, 5 e 8);
// o código executa 9 trocas, mas 4 são do elemento com ele mesmo
//
// ============================================================================
// GABARITO (só olhe depois de fazer!)
// ============================================================================
//
// Iteração 1 (i = 0) → 3 16 8 11 29 13 21 15 26 24 - (menor = 3, já no lugar)
// Iteração 2 (i = 1) → 3 8 16 11 29 13 21 15 26 24 - (16 ↔ 8)
// Iteração 3 (i = 2) → 3 8 11 16 29 13 21 15 26 24 - (16 ↔ 11)
// Iteração 4 (i = 3) → 3 8 11 13 29 16 21 15 26 24 - (16 ↔ 13)
// Iteração 5 (i = 4) → 3 8 11 13 15 16 21 29 26 24 - (29 ↔ 15)
// Iteração 6 (i = 5) → 3 8 11 13 15 16 21 29 26 24 - (menor = 16, já no lugar)
// Iteração 7 (i = 6) → 3 8 11 13 15 16 21 29 26 24 - (menor = 21, já no lugar)
// Iteração 8 (i = 7) → 3 8 11 13 15 16 21 24 26 29 - (29 ↔ 24)
// Iteração 9 (i = 8) → 3 8 11 13 15 16 21 24 26 29 - (menor = 26, já no lugar)
//
// Vetor final → [3 8 11 13 15 16 21 24 26 29]
//
// a) Iterações 1, 6, 7 e 9. Nelas o vetor NÃO muda: na prova, é só repetir
//    o vetor da linha de cima. Não pule a linha!
// b) Ficou ordenado na iteração 8, mas o algoritmo NÃO para: o Selection
//    Sort não tem flag `trocou`, então faz a iteração 9 de qualquer jeito.
//    Ele sempre faz as n-1 iterações.
// c) O 16 muda de lugar nas iterações 2, 3 e 4: índice 1 → 2 → 3 → 5.
//    Em nenhuma delas ele era o menor: ele só estava em vetor[i] e foi
//    jogado para onde o menor estava. O Selection só garante a posição i;
//    o resto do vetor pode ficar mais bagunçado.
// d) Comparações: 9+8+7+6+5+4+3+2+1 = 45 (n(n-1)/2, sempre).
//    Trocas reais: 5 (iterações 2, 3, 4, 5 e 8). O código do slide executa
//    9 trocas, mas 4 são do elemento com ele mesmo.
