// QUESTÃO 2 – Quick Sort: Mediana de Três
//
// Com pivô = último, um vetor JÁ ORDENADO é o pior caso: cada partição só
// tira o pivô do problema e a recursão fica com profundidade n - 1 (O(n²)).
//
// A mediana de três escolhe um pivô melhor: olha o primeiro, o do meio e o
// último do trecho, e usa o valor do MEIO entre os três (a mediana).
//
//   meio = inicio + (final - inicio) / 2
//   descubra qual dos três (vetor[inicio], vetor[meio], vetor[final]) é a mediana
//   troque a mediana com vetor[final]
//   chame o partition do slide (pivô = último), sem mudar nada nele
//
// ex: trecho {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} → primeiro 1, meio 5, último 10 → mediana 5
//
// int medianaDeTres(int vetor[], int inicio, int final);  → retorna o ÍNDICE da mediana
// void quickSort(int vetor[], int inicio, int final, int nivel);
// → nivel começa em 1 na chamada do main
//
// Conte também (com variáveis globais ou por referência, você escolhe):
// → comparacoes: quantas vezes o partition comparou vetor[j] com o pivô
// → profundidade: o MAIOR nivel em que aconteceu uma partição
//
// Rode o Quick Sort do slide (pivô = último) e o com mediana de três no vetor
// ordenado {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} e compare.
//
// Testes – mediana de três no vetor ordenado (imprima cada partição):
// [0..9] Pivô 5 → posição 4
// [0..3] Pivô 2 → posição 1
// [2..3] Pivô 3 → posição 2
// [5..9] Pivô 8 → posição 7
// [5..6] Pivô 6 → posição 5
// [8..9] Pivô 9 → posição 8
//
// Comparativo no vetor ordenado:
// Pivô último:     45 comparações, profundidade 9
// Mediana de três: 19 comparações, profundidade 3
//
// Extra: teste também o vetor decrescente {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}.
// Os números mudam? (deve dar de novo 45 e 9 contra 19 e 3)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Sorts/exércicios_quick_sort/Questao_02_Quick_Sort_Mediana_De_Tres.cpp" -o "AV2/Sorts/exércicios_quick_sort/q2.out" && "./AV2/Sorts/exércicios_quick_sort/q2.out"
