// QUESTÃO 9 – Busca Binária: Vetor em Ordem Decrescente
//
// Altere a busca binária para funcionar com um vetor ordenado em ordem
// DECRESCENTE.
//
// Valor   90  78  65  52  40  33  21  8
// Índice  0   1   2   3   4   5   6   7
//
// ex: {90, 78, 65, 52, 40, 33, 21, 8}; (procurando o 33) → posição 5
//
// int buscaBinariaDecrescente(int vetor[], int tamanho_vetor, int valor);
// → retorna a posição ou -1
//
// No main, leia o valor do teclado e mostre o resultado.
//
// Testes:
// valor 52  → posição 3
// valor 33  → posição 5
// valor 90  → posição 0
// valor 8   → posição 7
// valor 50  → -1 (valor não encontrado)
// valor 100 → -1 (valor não encontrado)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios pdf/Questao_09_Binaria_Decrescente.cpp" -o "AV2/exércicios pdf/q9.out" && "./AV2/exércicios pdf/q9.out"
