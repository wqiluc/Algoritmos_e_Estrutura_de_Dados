// QUESTÃO 4 – Busca Sequencial: Busca em um Intervalo de Posições
//
// Modifique a busca sequencial para pesquisar EXCLUSIVAMENTE dentro de um
// intervalo definido por duas posições (início e fim) informadas pelo usuário.
//
// Valor   11  24  7   36  15  24  50  3
// Índice  0   1   2   3   4   5   6   7
//
// ex: {11, 24, 7, 36, 15, 24, 50, 3}; (procurando o 24 entre as posições 2 e 6) → posição 5
//
// int buscaSequencialIntervalo(int vetor[], int inicio, int fim, int valor);
// → procura só de vetor[inicio] até vetor[fim] (incluindo os dois)
// → retorna a posição encontrada ou -1
//
// No main, leia o valor, o início e o fim. Se o intervalo for inválido
// (inicio < 0, fim >= tamanho do vetor ou inicio > fim), avise e não faça a busca.
//
// Testes:
// valor 24, intervalo [2, 6]  → posição 5   (o 24 da posição 1 fica de fora)
// valor 24, intervalo [0, 7]  → posição 1
// valor 3,  intervalo [4, 7]  → posição 7
// valor 11, intervalo [1, 7]  → não encontrado no intervalo (o 11 está na posição 0)
// intervalo [5, 2]            → intervalo inválido!
// intervalo [0, 10]           → intervalo inválido!
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios pdf/Questao_04_Sequencial_Intervalo_Posicoes.cpp" -o "AV2/exércicios pdf/q4.out" && "./AV2/exércicios pdf/q4.out"
