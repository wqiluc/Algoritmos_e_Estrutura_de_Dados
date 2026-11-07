// QUESTÃO 6 – Busca Binária: Versão Recursiva
//
// Faça uma adaptação na busca binária para funcionar de maneira recursiva
// (sem while/for: a função chama a si mesma com a metade certa do vetor).
//
// Valor   2   5   9   14  20  27  33  41  48
// Índice  0   1   2   3   4   5   6   7   8
//
// ex: {2, 5, 9, 14, 20, 27, 33, 41, 48}; (procurando o 33) → posição 6
//
// int buscaBinariaRecursiva(int vetor[], int inicio, int fim, int valor);
// → primeira chamada no main: buscaBinariaRecursiva(vetor, 0, TAM_VETOR - 1, valor)
// → retorna a posição ou -1
//
// No main, leia o valor do teclado e mostre o resultado.
//
// Testes:
// valor 20 → posição 4   (achado logo na 1ª chamada)
// valor 2  → posição 0
// valor 48 → posição 8
// valor 33 → posição 6
// valor 10 → -1 (valor não encontrado)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios pdf/Questao_06_Binaria_Recursiva.cpp" -o "AV2/exércicios pdf/q6.out" && "./AV2/exércicios pdf/q6.out"
