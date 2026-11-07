// QUESTÃO 8 – Busca Binária: Vizinho Mais Próximo
//
// Ajuste a busca binária para, caso o elemento não seja encontrado, retornar
// o elemento mais próximo ao valor buscado (o vizinho mais próximo).
//
// Valor   4   10  15  22  30  41  55
// Índice  0   1   2   3   4   5   6
//
// ex: {4, 10, 15, 22, 30, 41, 55}; (procurando o 20) → não encontrado, mais próximo: 22
//
// int buscaBinariaMaisProximo(int vetor[], int tamanho_vetor, int valor, bool &encontrado);
// → se encontrar: encontrado = true  e retorna o próprio valor
// → se não:       encontrado = false e retorna o ELEMENTO mais próximo
// → em caso de empate (mesma distância para os dois vizinhos), retorne o menor
//
// No main, leia o valor do teclado e mostre o resultado.
//
// Testes:
// valor 22  → encontrado: 22
// valor 18  → não encontrado, mais próximo: 15   (15 está a 3, 22 está a 4)
// valor 20  → não encontrado, mais próximo: 22   (15 está a 5, 22 está a 2)
// valor 35  → não encontrado, mais próximo: 30   (30 está a 5, 41 está a 6)
// valor 48  → não encontrado, mais próximo: 41   (empate: 41 e 55 estão a 7 → o menor)
// valor 1   → não encontrado, mais próximo: 4    (antes do primeiro)
// valor 100 → não encontrado, mais próximo: 55   (depois do último)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios pdf/Questao_08_Binaria_Vizinho_Mais_Proximo.cpp" -o "AV2/exércicios pdf/q8.out" && "./AV2/exércicios pdf/q8.out"
