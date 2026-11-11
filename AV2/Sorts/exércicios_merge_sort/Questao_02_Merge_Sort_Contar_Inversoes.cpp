// QUESTÃO 2 – Merge Sort: Contar Inversões
//
// Uma INVERSÃO é um par de posições (i, j) com i < j e vetor[i] > vetor[j],
// ou seja, um par que está "fora de ordem". Ela mede o quão bagunçado o vetor
// está: ordenado = 0 inversões; decrescente = o máximo, n * (n - 1) / 2.
//
// ex: {2, 4, 1, 3, 5} → pares fora de ordem: (2,1), (4,1), (4,3) → 3 inversões
//
// Testar todos os pares é O(n²). Dá para contar em O(n log n) aproveitando o
// Merge Sort: no intercalar, quando um elemento da metade DIREITA é escolhido
// enquanto ainda sobram elementos na ESQUERDA, ele forma uma inversão com
// CADA um deles (a esquerda está ordenada, então todos os que sobraram são maiores).
//
//   → ao pegar da direita: inversoes += (tamanho_esquerda - i)
//
// long long intercalarContando(int vetor[], int esquerda, int meio, int direita);
// long long contarInversoes(int vetor[], int esquerda, int direita);
// → retorna as inversões do trecho = inversões da esquerda + da direita + do intercalar
//
// Faça também a versão O(n²) com dois for, int contarInversoesForcaBruta(...),
// para conferir. ATENÇÃO: rode a força bruta ANTES, porque o Merge Sort ordena o vetor!
//
// Testes:
// {2, 4, 1, 3, 5}    → 3
// {8, 4, 2, 1}       → 6   (decrescente: 4 * 3 / 2)
// {5, 4, 3, 2, 1}    → 10  (decrescente: 5 * 4 / 2)
// {1, 2, 3, 4, 5}    → 0   (já ordenado)
// {2, 2, 1}          → 2   (os dois 2 NÃO formam inversão entre si)
// {3, 7, 2, 9, 1, 5} → 8, intercalação por intercalação:
//   3 7         (+0)
//   2 3 7       (+2: o 2 passou na frente do 3 e do 7)
//   1 9         (+1)
//   1 5 9       (+1)
//   1 2 3 5 7 9 (+4)
//
// Pergunta: por que, em caso de empate, é preciso pegar da ESQUERDA (<=)
// para não contar inversões a mais?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Sorts/exércicios_merge_sort/Questao_02_Merge_Sort_Contar_Inversoes.cpp" -o "AV2/Sorts/exércicios_merge_sort/q2.out" && "./AV2/Sorts/exércicios_merge_sort/q2.out"
