// QUESTÃO 1 – Quick Sort: Pivô no Primeiro Elemento
//
// O slide usa o ÚLTIMO elemento do trecho como pivô. Adapte o partition para
// usar o PRIMEIRO. Faça assim (é o "espelho" do partition do slide):
//
//   pivo = vetor[inicio]
//   i = inicio
//   para j de inicio + 1 até final:
//       se vetor[j] < pivo → i++ e troca vetor[i] com vetor[j]
//   no fim, troca vetor[inicio] com vetor[i] → o pivô cai na posição i
//
// Valor   6   10  3   8   1   9   4
// Índice  0   1   2   3   4   5   6
//
// ex: {6, 10, 3, 8, 1, 9, 4}; → 1 3 4 6 8 9 10
//
// int particionar(int vetor[], int inicio, int final, int &comparacoes);
// void quickSort(int vetor[], int inicio, int final, int &comparacoes);
// → imprime o vetor depois de cada partição
// → comparacoes: quantas vezes comparou vetor[j] com o pivô
//
// Testes:
// Pivô 6  → posição 3: 4 3 1 6 10 9 8
// Pivô 4  → posição 2: 1 3 4 6 10 9 8
// Pivô 1  → posição 0: 1 3 4 6 10 9 8
// Pivô 10 → posição 6: 1 3 4 6 8 9 10
// Pivô 8  → posição 4: 1 3 4 6 8 9 10
// Total: 12 comparações
//
// Pergunta: se o vetor já estiver ordenado ({1, 3, 4, 6, 8, 9, 10}), quantas
// comparações essa versão faz? Por que o pivô no primeiro tem o mesmo problema
// do pivô no último?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Sorts/exércicios_quick_sort/Questao_01_Quick_Sort_Pivo_Primeiro.cpp" -o "AV2/Sorts/exércicios_quick_sort/q1.out" && "./AV2/Sorts/exércicios_quick_sort/q1.out"
