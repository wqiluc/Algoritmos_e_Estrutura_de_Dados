// QUESTÃO 3 – Hash de Strings com Encadeamento
//
// Até agora as chaves eram números. Para guardar NOMES, primeiro é preciso
// transformar a string num número. Use a função mais simples: somar os
// códigos ASCII de cada caractere e tirar o resto pelo tamanho da tabela.
//
//   hash("Ana") = ('A' + 'n' + 'a') % 7 = (65 + 110 + 97) % 7 = 272 % 7 = 6
//
// Use TAM_TABELA 7 e trate colisões com lista encadeada, inserindo o nome novo
// no INÍCIO da lista daquela posição (como no slide).
// Insira, nesta ordem: Ana, Bia, Caio, Davi, Lia, Ali, Eva.
//
// struct No
// {
//     string nome;
//     No* proximo;
// };
//
// int funcaoHash(string nome);              → soma dos códigos ASCII % TAM_TABELA
// void inserir(No* tabela[], string nome);  → insere no início da lista
// int buscar(No* tabela[], string nome);    → em qual nó da lista achou (1º, 2º...) ou -1
// void imprimirTabela(No* tabela[]);
// void liberarTabela(No* tabela[]);         → delete em todos os nós no fim do programa
//
// Dica: para pegar o código de um char, basta usá-lo numa conta
// (int codigo = nome[indice];).
//
// Testes:
// Ana  → 272 % 7 = 6
// Bia  → 268 % 7 = 2
// Caio → 380 % 7 = 2   (colide com Bia)
// Davi → 388 % 7 = 3
// Lia  → 278 % 7 = 5
// Ali  → 278 % 7 = 5   (colide com Lia: MESMA soma!)
// Eva  → 284 % 7 = 4
//
// Tabela:
// [0] → NULL
// [1] → NULL
// [2] → Caio → Bia → NULL
// [3] → Davi → NULL
// [4] → Eva → NULL
// [5] → Ali → Lia → NULL
// [6] → Ana → NULL
//
// Buscar "Bia" → posição 2 → olhou Caio, olhou Bia → achou no 2º nó
// Buscar "Lia" → posição 5 → olhou Ali, olhou Lia  → achou no 2º nó
// Buscar "Eva" → posição 4 → olhou Eva             → achou no 1º nó
// Buscar "Rui" → posição 3 (304 % 7) → olhou Davi  → não achou
//
// Pergunta: "Lia" e "Ali" SEMPRE vão colidir, não importa o tamanho da tabela.
// Por quê? Que mudança na função hash evitaria isso?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Buscas/exércicios_hash/Questao_03_Hash_Strings_Encadeamento.cpp" -o "AV2/Buscas/exércicios_hash/q3.out" && "./AV2/Buscas/exércicios_hash/q3.out"
