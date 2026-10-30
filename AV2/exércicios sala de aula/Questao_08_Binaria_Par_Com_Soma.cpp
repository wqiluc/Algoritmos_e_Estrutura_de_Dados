// QUESTÃO 8 – Busca Binária: Par com Soma Alvo
//
// Dado um vetor ORDENADO e um valor alvo, encontre dois elementos
// (em posições diferentes) cuja soma seja igual ao alvo.
// Percorra o vetor com um for e, para cada vetor[i], use a busca binária
// para procurar o complemento (alvo - vetor[i]) só à DIREITA de i.
// Retorne o primeiro par encontrado (menor i).

// ex: {1, 4, 6, 9, 11, 15, 20, 23}; (alvo 15) → posições 1 e 4 (4 + 11)

// int buscaBinariaIntervalo(int vetor[], int inicio, int fim, int valor);
// → busca binária normal, mas só entre inicio e fim
// bool parComSoma(int vetor[], int tamanho, int alvo, int &posicao1, int &posicao2);
// → retorna true se achou e preenche posicao1 e posicao2

// Testes:
// alvo 15 → posições 1 e 4 (4 + 11)
// alvo 26 → posições 2 e 6 (6 + 20)
// alvo 43 → posições 6 e 7 (20 + 23)
// alvo 12 → posições 0 e 4 (1 + 11)
// alvo 8  → nenhum par encontrado.   (4 + 4 não vale: só existe um 4)
// alvo 3  → nenhum par encontrado.

// Pergunta (responda aqui antes de rodar):
// Qual a complexidade da sua solução? E a de testar todos os pares com
// dois for aninhados? Para um vetor de 1.000.000 de elementos, qual é melhor?
//
// Resposta:

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios sala de aula/Questao_08_Binaria_Par_Com_Soma.cpp" -o "AV2/exércicios sala de aula/q8.out" && "./AV2/exércicios sala de aula/q8.out"
