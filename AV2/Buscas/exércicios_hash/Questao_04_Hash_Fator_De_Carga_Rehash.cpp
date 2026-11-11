// QUESTÃO 4 – Hash: Fator de Carga e Rehash (desafio)
//
// Fator de carga = quantidade de elementos / tamanho da tabela.
// Com sondagem linear, quando ele passa de ~70% as colisões disparam.
// A solução é o REHASH: criar uma tabela maior e reinserir todo mundo
// (a posição de cada chave muda, porque agora o % é por outro tamanho!).
//
// Comece com uma tabela de tamanho 5 (alocada com new) e sondagem linear
// (chave % tamanho). ANTES de cada inserção, calcule o fator de carga que a
// tabela TERIA com o novo elemento: (quantidade + 1) / tamanho.
// Se passar de 0.7:
//   1. crie uma tabela nova com o DOBRO do tamanho, toda VAZIA
//   2. percorra a tabela antiga da posição 0 até o fim, reinserindo cada chave
//      na tabela nova (com o novo tamanho no %)
//   3. libere a tabela antiga (delete[]) e passe a usar a nova
// Depois insira normalmente.
//
// Insira, nesta ordem: 12, 7, 3, 18, 22, 13.
//
// struct TabelaHash
// {
//     int* posicoes;    → alocada com new (o tamanho muda!)
//     int tamanho;
//     int quantidade;
// };
//
// void inicializar(TabelaHash &tabela, int tamanho);  → new int[tamanho], tudo VAZIO
// void rehash(TabelaHash &tabela);                    → dobra o tamanho e reinsere
// void inserir(TabelaHash &tabela, int chave);        → confere a carga, faz rehash se precisar, insere
// void imprimirTabela(TabelaHash tabela);
//
// Cuidado: (quantidade + 1) / tamanho com dois int dá divisão INTEIRA (4 / 5 = 0).
// Converta para double antes de dividir.
//
// Testes:
// Inserir 12 → carga 1/5 = 0.2 → 2 (livre)
// Inserir 7  → carga 2/5 = 0.4 → 2 (ocupada) → 3 (livre)
// Inserir 3  → carga 3/5 = 0.6 → 3 (ocupada) → 4 (livre)
// Inserir 18 → carga 4/5 = 0.8 > 0.7 → REHASH para tamanho 10:
//     reinserir 12 → 12 % 10 = 2
//     reinserir 7  → 7 % 10  = 7
//     reinserir 3  → 3 % 10  = 3
//   → agora sim: 18 % 10 = 8 (livre)
// Inserir 22 → carga 5/10 = 0.5 → 2 (ocupada) → 3 (ocupada) → 4 (livre)
// Inserir 13 → carga 6/10 = 0.6 → 3 (ocupada) → 4 (ocupada) → 5 (livre)
//
// Tabela final (tamanho 10, 6 elementos, carga 0.6):
// [0] - | [1] - | [2] 12 | [3] 3 | [4] 22 | [5] 13 | [6] - | [7] 7 | [8] 18 | [9] -
//
// Pergunta: o 7 estava na posição 3 da tabela antiga e foi para a 7 na nova.
// Por que não dá para simplesmente copiar a tabela antiga para dentro da nova?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Buscas/exércicios_hash/Questao_04_Hash_Fator_De_Carga_Rehash.cpp" -o "AV2/Buscas/exércicios_hash/q4.out" && "./AV2/Buscas/exércicios_hash/q4.out"
