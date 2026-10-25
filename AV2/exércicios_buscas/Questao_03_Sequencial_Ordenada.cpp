// QUESTÃO 3 – Busca Sequencial em Vetor Ordenado (💻 código + ✏️ papel)
//
// Valor   3   9   14  21  30  47  52  68  75  90
// Índice  0   1   2   3   4   5   6   7   8   9
//
// Se o vetor está ordenado, a busca sequencial pode PARAR ANTES do fim:
// assim que encontrar um elemento MAIOR que o valor buscado, o valor com
// certeza não está no vetor.
//
// int buscaSequencialOrdenada(int vetor[], int tamanho_vetor, int valor);
//
// Testes:
// buscar 47  → 5
// buscar 3   → 0
// buscar 22  → -1
// buscar 1   → -1
// buscar 100 → -1
//
// a) Quantos elementos são visitados ao buscar 22? E 1? E 100?
// b) Quantos a busca sequencial NORMAL visitaria para buscar 22?
// c) Essa melhoria muda a complexidade de pior caso? Por quê?
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// a) 22:   | 1:   | 100:
// b)
// c)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 AV2/exércicios_buscas/Questao_03_Sequencial_Ordenada.cpp -o AV2/exércicios_buscas/q3.out && ./AV2/exércicios_buscas/q3.out
