// QUESTÃO 10 – Busca Binária: Todas as Posições
//
// Faça uma versão modificada da busca binária que retorna TODAS as posições
// em que o valor aparece, considerando que existem repetições no vetor.
//
// Valor   1   3   3   3   6   8   8   10  12  12  12  12
// Índice  0   1   2   3   4   5   6   7   8   9   10  11
//
// ex: {1, 3, 3, 3, 6, 8, 8, 10, 12, 12, 12, 12}; (procurando o 12) → posições 8 9 10 11
//
// int buscaBinariaTodasPosicoes(int vetor[], int tamanho_vetor, int valor, int posicoes[]);
// → preenche posicoes[] (em ordem crescente) e retorna a quantidade encontrada
// → use a busca binária para achar o valor (não vale percorrer o vetor todo!)
//
// No main, leia o valor do teclado e mostre o resultado.
//
// Testes:
// valor 3  → 3 posição(ões): 1 2 3
// valor 12 → 4 posição(ões): 8 9 10 11
// valor 8  → 2 posição(ões): 5 6
// valor 6  → 1 posição(ões): 4
// valor 1  → 1 posição(ões): 0
// valor 7  → valor não encontrado.
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios pdf/Questao_10_Binaria_Todas_Posicoes.cpp" -o "AV2/exércicios pdf/q10.out" && "./AV2/exércicios pdf/q10.out"
