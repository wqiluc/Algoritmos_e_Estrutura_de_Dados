// QUESTÃO 6 – Busca Binária: Elemento Mais Próximo
//
// Modifique a busca binária para, caso o valor NÃO exista no vetor,
// retornar a posição do elemento MAIS PRÓXIMO dele.
// Se existir, retorne a posição dele mesmo.
// Em caso de empate (dois vizinhos com a mesma distância), retorne o menor.

// ex: {2, 5, 9, 14, 20, 27, 35}; (procurando o 12) → posição 3 (valor 14)

// Dica: quanto valem inicio e fim quando o while termina? (lembre da Questão 2)
// Cuidado com as bordas: valor menor que todos ou maior que todos.

// int buscaBinariaMaisProximo(int vetor[], int tamanho, int valor);

// Testes:
// valor 12  → posição 3 (valor 14)
// valor 20  → posição 4 (valor 20)   [existe no vetor]
// valor 7   → posição 1 (valor 5)    [empate entre 5 e 9 → o menor]
// valor 23  → posição 4 (valor 20)
// valor 0   → posição 0 (valor 2)
// valor 100 → posição 6 (valor 35)

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios sala de aula/Questao_06_Binaria_Mais_Proximo.cpp" -o "AV2/exércicios sala de aula/q6.out" && "./AV2/exércicios sala de aula/q6.out"
