// QUESTÃO EXTRA 04 – Selection Sort (0,5)
// Ordene [8,5,8,2,14,6,11,1,17,10] mostrando todas as iterações.
//
// (Treino no estilo da Questão 04 da AV2 SI 2026.1. Na prova é NO PAPEL:
// é só escrever o vetor no fim de cada iteração.)
//
// Selection Sort do slide: em cada iteração i, acha o MENOR do trecho
// vetor[i..n-1] e troca com vetor[i]. A comparação é `vetor[j] < vetor[min_idx]`
// (menor ESTRITO).
//
// O vetor tem dois 8. Para conseguir acompanhar cada um, chame o do índice 0
// de 8a e o do índice 2 de 8b (é o mesmo valor, a letra é só para rastrear).
//
// Valor   8a  5   8b  2   14  6   11  1   17  10
// Índice  0   1   2   3   4   5   6   7   8   9
//
// Iteração 1 (i = 0) → 1 5 8b 2 14 6 11 8a 17 10 - (8a ↔ 1)
// Iteração 2 (i = 1) → 1 2 8b 5 14 6 11 8a 17 10 - (5 ↔ 2)
// Iteração 3 (i = 2) → 1 2 5 8b 14 6 11 8a 17 10 - (8b ↔ 5)
// Iteração 4 (i = 3) → 1 2 5 6 14 8b 11 8a 17 10 - (8b ↔ 6)
// Iteração 5 (i = 4) → 1 2 5 6 8b 14 11 8a 17 10 - (14 ↔ 8b)
// Iteração 6 (i = 5) → 1 2 5 6 8b 8a 11 14 17 10 - (14 ↔ 8a)
// Iteração 7 (i = 6) → 1 2 5 6 8b 8a 10 14 17 11 - (11 ↔ 10)
// Iteração 8 (i = 7) → 1 2 5 6 8b 8a 10 11 17 14 - (14 ↔ 11)
// Iteração 9 (i = 8) → 1 2 5 6 8b 8a 10 11 14 17 - (17 ↔ 14)
//
// Vetor final → [1, 2, 5, 6, 8b, 8a, 10, 11, 14, 17]
//
// Perguntas:
// a) No vetor final, quem vem primeiro: 8a ou 8b? O Selection Sort é estável?
// o 8b; a ordem dos dois 8 inverteu, então o Selection NÃO é estável
// b) Em qual iteração o 8a passa para trás do 8b? Por que isso acontece?
// na iteração 1: o 1 (índice 7) troca com o 8a (índice 0) e o 8a pula direto
// para o índice 7, por cima do 8b (troca de longa distância)
// c) Na iteração 5 o trecho olhado tem os dois 8. Qual deles o algoritmo
//    escolhe como menor? Por quê?
// o 8b (índice 5): a comparação é `<` estrito, então 8 < 8 é falso e o min_idx
// fica no primeiro 8 encontrado
// d) Quantas comparações e quantas trocas reais o código do slide faz?
//    Se o vetor já entrasse ordenado, quantas comparações ele faria?
// 45 comparações (9+8+...+1) e 9 trocas reais; já ordenado continua com 45
// comparações (e 0 trocas reais): o Selection é O(n²) até no melhor caso
//
// ============================================================================
// GABARITO (só olhe depois de fazer!)
// ============================================================================
//
// Iteração 1 (i = 0) → 1 5 8b 2 14 6 11 8a 17 10 - (8a ↔ 1)
// Iteração 2 (i = 1) → 1 2 8b 5 14 6 11 8a 17 10 - (5 ↔ 2)
// Iteração 3 (i = 2) → 1 2 5 8b 14 6 11 8a 17 10 - (8b ↔ 5)
// Iteração 4 (i = 3) → 1 2 5 6 14 8b 11 8a 17 10 - (8b ↔ 6)
// Iteração 5 (i = 4) → 1 2 5 6 8b 14 11 8a 17 10 - (14 ↔ 8b)
// Iteração 6 (i = 5) → 1 2 5 6 8b 8a 11 14 17 10 - (14 ↔ 8a)
// Iteração 7 (i = 6) → 1 2 5 6 8b 8a 10 14 17 11 - (11 ↔ 10)
// Iteração 8 (i = 7) → 1 2 5 6 8b 8a 10 11 17 14 - (14 ↔ 11)
// Iteração 9 (i = 8) → 1 2 5 6 8b 8a 10 11 14 17 - (17 ↔ 14)
//
// Vetor final → [1 2 5 6 8 8 10 11 14 17]   (8b antes do 8a)
//
// a) O 8b vem primeiro. No início era 8a antes de 8b e no fim inverteu,
//    então o Selection Sort NÃO é estável.
// b) Na iteração 1. O 1 (índice 7) troca com o 8a (índice 0), e o 8a é
//    jogado direto para o índice 7, passando por cima do 8b (índice 2).
//    É a troca de LONGA distância que quebra a estabilidade (o Bubble e o
//    Insertion só mexem em vizinhos, por isso são estáveis).
// c) O 8b (índice 5). Como a comparação é `<` estrito, quando o j chega no
//    8a (índice 7), 8 < 8 é falso e o min_idx continua no primeiro 8
//    encontrado.
// d) Comparações: 9+8+7+6+5+4+3+2+1 = 45 (n(n-1)/2).
//    Trocas reais: 9 (em nenhuma iteração o menor já estava no lugar).
//    Já ordenado: continua 45 comparações (e 0 trocas reais). O Selection
//    não percebe que o vetor está ordenado: é O(n²) SEMPRE, até no melhor
//    caso.
