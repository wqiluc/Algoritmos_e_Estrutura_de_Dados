// QUESTÃO 3 – Quick Sort: Partição em Três Vias (desafio)
//
// Quando o vetor tem MUITOS valores repetidos, o Quick Sort normal desperdiça
// trabalho: os iguais ao pivô vão todos para um lado e são particionados de
// novo e de novo. A partição em três vias separa o trecho em TRÊS regiões:
//
//   [ menores que o pivô | iguais ao pivô | maiores que o pivô ]
//
// e a recursão só continua nos menores e nos maiores (os iguais já estão no lugar).
//
// Algoritmo (pivô = PRIMEIRO elemento do trecho):
//   pivo = vetor[inicio]
//   menores = inicio, i = inicio, maiores = final
//   enquanto i <= maiores:
//       vetor[i] < pivo  → troca vetor[menores] com vetor[i], menores++, i++
//       vetor[i] > pivo  → troca vetor[i] com vetor[maiores], maiores--   (NÃO avança o i!)
//       vetor[i] == pivo → i++
//   no fim: [inicio..menores-1] < pivo | [menores..maiores] == pivo | [maiores+1..final] > pivo
//
// Valor   4   9   4   1   9   4   4   2   9   4   1   4
// Índice  0   1   2   3   4   5   6   7   8   9   10  11
//
// void particionar3Vias(int vetor[], int inicio, int final, int &menores, int &maiores);
// void quickSort3Vias(int vetor[], int inicio, int final);
// → imprime o trecho, o pivô, a região dos iguais e o vetor depois de cada partição
//
// Testes:
// [0..11] Pivô 4 → iguais em 3..8:  1 1 2 4 4 4 4 4 4 9 9 9
// [0..2]  Pivô 1 → iguais em 0..1:  1 1 2 4 4 4 4 4 4 9 9 9
// [9..11] Pivô 9 → iguais em 9..11: 1 1 2 4 4 4 4 4 4 9 9 9
// Total: 3 partições
//
// Perguntas:
// 1) Por que o i NÃO avança quando troca com os maiores?
// 2) Rode o Quick Sort do slide (pivô = último) no mesmo vetor e conte as
//    partições (deve dar 9). De onde vem a diferença?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Sorts/exércicios_quick_sort/Questao_03_Quick_Sort_Particao_Tres_Vias.cpp" -o "AV2/Sorts/exércicios_quick_sort/q3.out" && "./AV2/Sorts/exércicios_quick_sort/q3.out"
