// QUESTÃO 7 – Busca Binária em Vetor Rotacionado
//
// O vetor abaixo ERA ordenado, mas foi "girado": um pedaço do começo
// foi para o final. Modifique a busca binária para encontrar a posição
// de um valor nesse vetor, SEM percorrer ele todo (continua O(log n)).
// Se não existir, retorne -1.

// ex: {15, 18, 22, 30, 41, 2, 5, 9, 12}; (procurando o 5) → posição 6

// Dica: em cada passo, pelo menos UMA das metades (inicio..meio ou
// meio..fim) está ordenada. Compare vetor[inicio] com vetor[meio] para
// descobrir qual é, e veja se o valor cabe dentro dela.
// Proibido: achar o ponto de rotação com um for antes de buscar.

// int buscaBinariaRotacionada(int vetor[], int tamanho, int valor);

// Testes:
// valor 30 → posição 3
// valor 5  → posição 6
// valor 15 → posição 0
// valor 12 → posição 8
// valor 41 → posição 4
// valor 2  → posição 5
// valor 20 → valor não encontrado no vetor.
// valor 1  → valor não encontrado no vetor.

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios sala de aula/Questao_07_Binaria_Vetor_Rotacionado.cpp" -o "AV2/exércicios sala de aula/q7.out" && "./AV2/exércicios sala de aula/q7.out"
