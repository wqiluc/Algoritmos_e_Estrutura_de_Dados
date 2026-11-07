// QUESTÃO 2 – Busca Sequencial: Elementos Maiores que um Valor
//
// Crie uma busca sequencial modificada que encontre apenas elementos
// MAIORES que um dado valor informado e retorne todos esses elementos.
//
// Valor   14  3   27  9   41  6   18
// Índice  0   1   2   3   4   5   6
//
// ex: {14, 3, 27, 9, 41, 6, 18}; (maiores que 10) → 14 27 41 18
//
// int buscaMaiores(int vetor[], int tamanho_vetor, int valor, int maiores[]);
// → preenche maiores[] e retorna a quantidade encontrada
//
// No main, leia o valor do teclado e mostre o resultado.
//
// Testes:
// valor 10 → 4 elemento(s): 14 27 41 18
// valor 30 → 1 elemento(s): 41
// valor 27 → 1 elemento(s): 41          (o 27 não entra: é igual, não maior)
// valor 0  → 7 elemento(s): 14 3 27 9 41 6 18
// valor 41 → nenhum elemento maior que 41.
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios pdf/Questao_02_Sequencial_Maiores_Que.cpp" -o "AV2/exércicios pdf/q2.out" && "./AV2/exércicios pdf/q2.out"
