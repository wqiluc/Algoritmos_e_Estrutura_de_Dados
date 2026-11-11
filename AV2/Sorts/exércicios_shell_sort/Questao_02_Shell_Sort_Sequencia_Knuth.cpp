// QUESTÃO 2 – Shell Sort: Sequência de Knuth
//
// A sequência n/2, n/4, ..., 1 (do slide) é simples, mas não é a melhor.
// Uma sequência muito usada é a de Knuth: 1, 4, 13, 40, 121, ...
// (cada termo é 3 * anterior + 1).
//
// Comece com o MAIOR termo da sequência que seja menor que n e vá descendo
// com gap = (gap - 1) / 3 até chegar em 1.
//
//   n = 15 → termos 1, 4, 13 (o 40 já passa) → gaps 13, 4, 1
//
// int gapInicialKnuth(int tamanho_vetor);              → maior termo menor que n
// int shellSortKnuth(int vetor[], int tamanho_vetor);  → imprime o vetor e os deslocamentos
//                                                        após cada gap; retorna o total
// int shellSortMetade(int vetor[], int tamanho_vetor); → a mesma coisa com gaps n/2 (Questão 1)
//
// Rode as duas versões (cada uma numa CÓPIA) com os dois vetores abaixo.
//
// Vetor A (15 elementos, embaralhado):
// {33, 7, 62, 4, 51, 21, 9, 45, 3, 40, 17, 56, 11, 38, 29}
//
// Vetor B (16 elementos, decrescente):
// {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
//
// Testes – Vetor A:
// Knuth:
//   Após gap 13 (0 deslocamentos)  → 33 7 62 4 51 21 9 45 3 40 17 56 11 38 29
//   Após gap 4  (8 deslocamentos)  → 3 7 9 4 11 21 17 45 33 38 29 56 51 40 62
//   Após gap 1  (12 deslocamentos) → 3 4 7 9 11 17 21 29 33 38 40 45 51 56 62
//   Total: 20
// Metade (n/2):
//   Após gap 7  (5 deslocamentos)  → 29 3 40 4 51 11 9 33 7 62 17 56 21 38 45
//   Após gap 3  (12 deslocamentos) → 4 3 7 9 17 11 21 33 40 29 38 45 62 51 56
//   Após gap 1  (7 deslocamentos)  → 3 4 7 9 11 17 21 29 33 38 40 45 51 56 62
//   Total: 24
// (Insertion Sort puro no vetor A: 52)
//
// Testes – Vetor B (só os totais):
// Knuth  (gaps 13, 4, 1):    22 deslocamentos
// Metade (gaps 8, 4, 2, 1):  32 deslocamentos
// (Insertion Sort puro no vetor B: 120)
//
// Perguntas:
// 1) No vetor B, com gaps 8, 4 e 2 (todos pares), um elemento numa posição PAR
//    chega a ser comparado com algum de posição ÍMPAR antes do gap 1?
//    Por que isso é um ponto fraco da sequência n/2?
// 2) Teste agora o vetor {40, 7, 33, 11, 56, 21, 45, 3, 62, 9, 38, 17, 51, 4, 29}.
//    A Knuth ainda ganha? O que isso diz sobre comparar sequências em vetores pequenos?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Sorts/exércicios_shell_sort/Questao_02_Shell_Sort_Sequencia_Knuth.cpp" -o "AV2/Sorts/exércicios_shell_sort/q2.out" && "./AV2/Sorts/exércicios_shell_sort/q2.out"
