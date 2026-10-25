// QUESTÃO 9 – Busca Binária: Posição de Inserção (💻 código + ✏️ papel)
//
// Valor   5   12  18  27  33  41  56  70
// Índice  0   1   2   3   4   5   6   7
//
// Quando o valor NÃO está no vetor, a busca binária normal retorna -1. Mas,
// ao final do while, o índice "inicio" aponta exatamente para onde o valor
// DEVERIA estar para manter o vetor ordenado.
//
// a) int posicaoInsercao(int vetor[], int tamanho_vetor, int valor);
//    → retorna a posição onde valor deve entrar (se já existir, a posição dele)
//
// b) void inserirOrdenado(int vetor[], int &tamanho_vetor, int valor);
//    → usa posicaoInsercao, empurra os elementos para a direita e insere
//    (declare o vetor com capacidade 20)
//
// Testes de posicaoInsercao:
// valor 20  → 3
// valor 1   → 0
// valor 100 → 8
// valor 33  → 4
//
// Teste de inserirOrdenado: insira 20, 1 e 100 (nessa ordem) e imprima:
// 1 5 12 18 20 27 33 41 56 70 100
//
// c) No papel: monte a tabela (inicio, fim, meio, vetor[meio]) para o valor 20
//    e mostre que inicio termina em 3.
// d) Achar a posição custa O(log n). Qual a complexidade de inserirOrdenado
//    inteira? Por quê?
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// c) inicio | fim | meio | vetor[meio] | decisão
//
// d)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 AV2/exércicios_buscas/Questao_09_Binaria_Posicao_Insercao.cpp -o AV2/exércicios_buscas/q9.out && ./AV2/exércicios_buscas/q9.out
