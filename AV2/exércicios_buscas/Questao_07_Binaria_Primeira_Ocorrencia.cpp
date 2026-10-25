// QUESTÃO 7 – Busca Binária: Primeira Ocorrência (💻 código + ✏️ papel)
//
// Valor   1   3   3   3   5   8   8   10  12  12  12  15
// Índice  0   1   2   3   4   5   6   7   8   9   10  11
//
// A busca binária normal retorna QUALQUER posição onde o valor aparece. Aqui
// o vetor tem repetidos e você deve retornar a PRIMEIRA (menor índice).
// Dica: quando achar, guarde o índice e continue procurando na metade
// da esquerda.
//
// a) int buscaBinariaPrimeira(int vetor[], int tamanho_vetor, int valor);
// b) int buscaBinariaUltima(int vetor[], int tamanho_vetor, int valor);
// c) int contarOcorrencias(int vetor[], int tamanho_vetor, int valor);
//    → use (a) e (b), SEM percorrer o vetor inteiro
//
// Testes:
// Valor | Primeira | Última | Ocorrências
//   3   |    1     |   3    |     3
//   8   |    5     |   6    |     2
//   12  |    8     |   10   |     3
//   1   |    0     |   0    |     1
//   15  |    11    |   11   |     1
//   7   |   -1     |  -1    |     0
//
// d) A busca binária NORMAL, procurando 3, retorna qual índice? E procurando 12?
// e) Qual a complexidade de contarOcorrencias? E se fosse feita com busca sequencial?
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// d) 3:   | 12:
// e)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 AV2/exércicios_buscas/Questao_07_Binaria_Primeira_Ocorrencia.cpp -o AV2/exércicios_buscas/q7.out && ./AV2/exércicios_buscas/q7.out
