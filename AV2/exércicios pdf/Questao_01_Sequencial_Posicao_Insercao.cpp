// QUESTÃO 1 – Busca Sequencial: Posição de Inserção
//
// Adapte a busca sequencial para que, caso o valor procurado não seja
// encontrado, retorne a posição onde o valor poderia ser inserido para
// manter a ordem crescente do vetor.
//
// Valor   3   8   12  17  25  31  40
// Índice  0   1   2   3   4   5   6
//
// ex: {3, 8, 12, 17, 25, 31, 40}; (procurando o 20) → não encontrado, inserir na posição 4
//
// int buscaSequencialInsercao(int vetor[], int tamanho_vetor, int valor, bool &encontrado);
// → se encontrar: encontrado = true  e retorna a posição do valor
// → se não:       encontrado = false e retorna a posição de inserção
//
// No main, leia o valor do teclado e mostre o resultado.
//
// Testes:
// valor 17 → encontrado na posição 3
// valor 3  → encontrado na posição 0
// valor 20 → não encontrado, inserir na posição 4
// valor 1  → não encontrado, inserir na posição 0
// valor 50 → não encontrado, inserir na posição 7 (fim do vetor)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios pdf/Questao_01_Sequencial_Posicao_Insercao.cpp" -o "AV2/exércicios pdf/q1.out" && "./AV2/exércicios pdf/q1.out"
