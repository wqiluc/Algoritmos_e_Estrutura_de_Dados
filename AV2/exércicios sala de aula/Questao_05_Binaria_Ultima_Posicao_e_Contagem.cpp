// QUESTÃO 5 – Busca Binária: Última Posição e Contagem
//
// Modifique a busca binária para retornar a ÚLTIMA posição em que
// determinado elemento aparece.
// Depois, use ela junto com a primeira posição (Questão 3) para
// dizer QUANTAS VEZES o elemento aparece no vetor, sem percorrer ele todo.

// ex: {1, 3, 3, 5, 5, 5, 5, 8, 10}; (procurando o 5) → primeira 3, última 6, aparece 4 vezes

// int buscaBinariaUltimaPosicao(int vetor[], int tamanho, int valor);
// int contarOcorrencias(int vetor[], int tamanho, int valor);

// Testes:
// valor 5  → primeira 3 | última 6 | aparece 4 vez(es)
// valor 3  → primeira 1 | última 2 | aparece 2 vez(es)
// valor 10 → primeira 8 | última 8 | aparece 1 vez(es)
// valor 1  → primeira 0 | última 0 | aparece 1 vez(es)
// valor 6  → valor não encontrado no vetor.

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios sala de aula/Questao_05_Binaria_Ultima_Posicao_e_Contagem.cpp" -o "AV2/exércicios sala de aula/q5.out" && "./AV2/exércicios sala de aula/q5.out"
