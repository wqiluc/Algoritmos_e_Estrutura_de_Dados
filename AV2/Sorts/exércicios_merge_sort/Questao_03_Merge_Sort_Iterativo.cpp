// QUESTÃO 3 – Merge Sort Iterativo (Bottom-Up) (desafio)
//
// O Merge Sort do slide é recursivo (de cima para baixo: divide até sobrar 1).
// A versão iterativa faz o caminho inverso, sem recursão, de baixo para cima:
//
//   largura 1: intercala pares de blocos de 1 → blocos ordenados de 2
//   largura 2: intercala pares de blocos de 2 → blocos ordenados de 4
//   largura 4: intercala pares de blocos de 4 → blocos ordenados de 8
//   ... até a largura ser >= n
//
// Use dois for: o de fora dobra a largura (1, 2, 4, 8...) e o de dentro anda
// pelo vetor de 2 * largura em 2 * largura, intercalando [esquerda..meio] com
// [meio+1..direita]. CUIDADO com o fim do vetor:
//   meio    = esquerda + largura - 1
//   direita = o menor entre (esquerda + 2 * largura - 1) e (n - 1)
//   se não existir metade direita (meio >= n - 1), não tem o que intercalar
//
// Valor   14  7   3   12  9   11  6   2   5
// Índice  0   1   2   3   4   5   6   7   8
//
// void intercalar(int vetor[], int esquerda, int meio, int direita);  → o mesmo do slide
// void mergeSortIterativo(int vetor[], int tamanho_vetor);
// → imprime o vetor depois de cada largura
//
// Testes:
// Após largura 1 → 7 14 3 12 9 11 2 6 5
// Após largura 2 → 3 7 12 14 2 6 9 11 5
// Após largura 4 → 2 3 6 7 9 11 12 14 5
// Após largura 8 → 2 3 5 6 7 9 11 12 14
//
// Teste também com {38, 27, 43, 3, 9, 82, 10} (o da aula):
// Após largura 1 → 27 38 3 43 9 82 10
// Após largura 2 → 3 27 38 43 9 10 82
// Após largura 4 → 3 9 10 27 38 43 82
//
// Perguntas:
// 1) O 5 (último elemento) ficou sozinho até a largura 8. Por quê?
// 2) As intercalações aqui são as mesmas da versão recursiva? (Compare com a
//    Questão 6 da "lista extra", que usa um vetor de tamanho ímpar.)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Sorts/exércicios_merge_sort/Questao_03_Merge_Sort_Iterativo.cpp" -o "AV2/Sorts/exércicios_merge_sort/q3.out" && "./AV2/Sorts/exércicios_merge_sort/q3.out"
