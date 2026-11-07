// QUESTÃO 7 – Busca Binária: Contando Comparações
//
// Modifique a busca binária para retornar não só a posição do elemento
// procurado, mas também quantas comparações foram realizadas para encontrá-lo.
//
// Valor   3   7   11  15  19  23  27  31  35  39  43  47  51  55  59
// Índice  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14
//
// ex: {3, 7, 11, 15, 19, 23, 27, 31, 35, 39, 43, 47, 51, 55, 59};
//     (procurando o 15) → posição 3, 2 comparações (olhou o 31, depois o 15)
//
// int buscaBinariaComparacoes(int vetor[], int tamanho_vetor, int valor, int &comparacoes);
// → retorna a posição (ou -1) e guarda em comparacoes o nº de comparações
// → conte 1 comparação a cada volta do while (cada vez que olha vetor[meio])
//
// No main, leia o valor do teclado e mostre a posição e o nº de comparações.
//
// Testes:
// valor 31 → posição 7,  1 comparação
// valor 15 → posição 3,  2 comparações
// valor 23 → posição 5,  3 comparações
// valor 3  → posição 0,  4 comparações
// valor 59 → posição 14, 4 comparações
// valor 40 → -1 (não encontrado), 4 comparações
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios pdf/Questao_07_Binaria_Contando_Comparacoes.cpp" -o "AV2/exércicios pdf/q7.out" && "./AV2/exércicios pdf/q7.out"
