// QUESTÃO 2 – Busca Binária: Posição de Inserção
//
// Modifique a busca binária para retornar a posição onde o elemento
// deveria ser inserido.
// Caso o elemento JÁ exista no vetor, retorne nulo (-1).

// ex: {1, 3, 5, 7, 9, 11, 13}; (inserindo o 6) → posição 3

// int buscaBinaria(int vetor[], int tamanho, int valor);

// Testes:
// valor 6  → posição 3
// valor 0  → posição 0
// valor 14 → posição 7
// valor 8  → posição 4
// valor 7  → -1 (já existe, não precisa ser inserido)

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios sala de aula/Questao_02_Binaria_Posicao_Insercao.cpp" -o "AV2/exércicios sala de aula/q2.out" && "./AV2/exércicios sala de aula/q2.out"
