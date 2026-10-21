// QUESTÃO 4 – Sondagem Linear (✏️ papel)
//
// TAM = 10, funcaoHash(k) = k % 10, sondagem linear. Insira, nesta ordem:
//
// 23, 43, 13, 27, 37, 9, 19
//
// a) Para cada chave, mostre as tentativas e a posição final. Desenhe a
//    tabela.
// b) Quantas tentativas para buscar o 13? E o 29 (que não existe)?
// c) Remova o 43. Como fica a posição dele? Busque o 13 de novo: quantas
//    tentativas? Por que ainda acha?
// d) E se a remoção colocasse VAZIO em vez de REMOVIDO, o que aconteceria
//    com buscar(13)?
// e) Depois da remoção, insira o 33. Onde ele entra?
// f) Qual era o fator de carga antes da remoção?
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// a) Chave | funcaoHash | Tentativas | Posição final
//    23    |            |            |
//    43    |            |            |
//    13    |            |            |
//    27    |            |            |
//    37    |            |            |
//    9     |            |            |
//    19    |            |            |
//
//    Índice   0   1   2   3   4   5   6   7   8   9
//    Valor    _   _   _   _   _   _   _   _   _   _
// b) 13: ___ tentativas | 29: ___ tentativas
// c) ___
// d) ___
// e) ___
// f) ___
//
// Compilar e rodar:
// g++ -std=c++17 Questao_04_Sondagem_Linear.cpp -o q4.out && ./q4.out