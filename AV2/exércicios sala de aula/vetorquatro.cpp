// Modifique a busca sequencial p/ retornar todas as posições em que
// aparecem valores DENTRO de um intervalo [minimo, maximo] (incluindo
// os extremos).
// Se o usuário digitar minimo > maximo, troque os dois antes de buscar.

// ex: [4,8,2,8,5,8,1] = intervalo [3, 6]; → índices 0 e 4 (valores 4 e 5)

// int posicoesNoIntervalo(int vetor[], int tamanho_vetor, int minimo, int maximo, int posicoes[]);
// → preenche posicoes[] e retorna a quantidade encontrada

// Testes:
// intervalo [3, 6]  → 2 valor(es), nos índices: 0 4
// intervalo [8, 8]  → 3 valor(es), nos índices: 1 3 5
// intervalo [1, 2]  → 2 valor(es), nos índices: 2 6
// intervalo [9, 20] → nenhum valor no intervalo.
// intervalo [6, 3]  → 2 valor(es), nos índices: 0 4   (trocou os extremos)

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios sala de aula/vetorquatro.cpp" -o "AV2/exércicios sala de aula/vetorquatro.out" && "./AV2/exércicios sala de aula/vetorquatro.out"