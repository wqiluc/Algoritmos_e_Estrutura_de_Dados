// QUESTÃO 1 – Busca Binária: Contar Ocorrências em O(log n)
//
// Conte quantas vezes um valor aparece num vetor ORDENADO, sem percorrer as
// repetições uma a uma. Para isso, use DUAS buscas binárias:
//   - uma que acha a PRIMEIRA posição do valor
//     (quando achar, guarda a posição e continua procurando à ESQUERDA: fim = meio - 1)
//   - outra que acha a ÚLTIMA posição do valor
//     (quando achar, guarda a posição e continua procurando à DIREITA: inicio = meio + 1)
// A quantidade é: ultima - primeira + 1.
//
// Valor   1   2   2   2   5   5   7   9   9   9   9
// Índice  0   1   2   3   4   5   6   7   8   9   10
//
// ex: {1, 2, 2, 2, 5, 5, 7, 9, 9, 9, 9}; (procurando o 9) → posições 7 a 10, aparece 4 vezes
//
// int primeiraOcorrencia(int vetor[], int tamanho_vetor, int valor);
// int ultimaOcorrencia(int vetor[], int tamanho_vetor, int valor);
// → as duas retornam a posição ou -1
//
// int contarOcorrencias(int vetor[], int tamanho_vetor, int valor);
// → usa as duas funções acima; retorna 0 se o valor não existir
//
// No main, leia o valor do teclado e mostre o resultado.
//
// Testes:
// valor 2  → primeira 1, última 3  → aparece 3 vezes
// valor 9  → primeira 7, última 10 → aparece 4 vezes
// valor 5  → primeira 4, última 5  → aparece 2 vezes
// valor 7  → primeira 6, última 6  → aparece 1 vez
// valor 1  → primeira 0, última 0  → aparece 1 vez
// valor 4  → não encontrado        → aparece 0 vezes
// valor 10 → não encontrado        → aparece 0 vezes
//
// Pergunta: compare com a Questão 10 de "exércicios pdf" (achar o valor e
// "espalhar" para os lados). Qual é melhor quando o valor se repete MUITAS vezes?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Buscas/exércicios_binárias/Questao_01_Binaria_Contar_Ocorrencias.cpp" -o "AV2/Buscas/exércicios_binárias/q1.out" && "./AV2/Buscas/exércicios_binárias/q1.out"
