// QUESTÃO 1 – Shell Sort: Contando Deslocamentos (Shell x Insertion)
//
// Ordene o vetor com Shell Sort (gaps n/2, n/4, ..., 1, como no slide) e conte
// quantos DESLOCAMENTOS cada gap fez. Deslocamento = cada vez que executa
// vetor[j] = vetor[j - gap].
//
// Depois, ordene uma CÓPIA do vetor original com o Insertion Sort puro (que é
// o Shell indo direto para o gap 1) e compare.
//
// Valor   35  33  42  10  14  19  27  44  26  31
// Índice  0   1   2   3   4   5   6   7   8   9
//
// ex: n = 10 → gaps 5, 2 e 1
//
// int shellSort(int vetor[], int tamanho_vetor);
// → imprime o vetor e os deslocamentos depois de cada gap; retorna o total
// int insertionSort(int vetor[], int tamanho_vetor);
// → retorna o total de deslocamentos
//
// Testes:
// Após gap 5 (2 deslocamentos) → 19 27 42 10 14 35 33 44 26 31
// Após gap 2 (8 deslocamentos) → 14 10 19 27 26 31 33 35 42 44
// Após gap 1 (2 deslocamentos) → 10 14 19 26 27 31 33 35 42 44
// Shell Sort:     12 deslocamentos no total
// Insertion Sort: 22 deslocamentos
//
// Pergunta: o gap 1 do Shell É um Insertion Sort. Por que ele fez só 2
// deslocamentos, enquanto o Insertion puro fez 22?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Sorts/exércicios_shell_sort/Questao_01_Shell_Sort_Contando_Deslocamentos.cpp" -o "AV2/Sorts/exércicios_shell_sort/q1.out" && "./AV2/Sorts/exércicios_shell_sort/q1.out"