// QUESTÃO 4 – Busca Binária: Vetor Ordenado e Rotacionado (desafio)
//
// O vetor abaixo era {3, 5, 8, 10, 15, 18, 22, 27}, mas foi "girado": um pedaço
// do começo foi parar no fim. A busca binária normal NÃO funciona nele
// (teste: ela não acha o 3).
//
// Valor   15  18  22  27  3   5   8   10
// Índice  0   1   2   3   4   5   6   7
//
// a) Adapte a busca binária para achar um valor nesse vetor em O(log n).
//
//    Dica: em todo passo, PELO MENOS UMA das metades (inicio..meio ou meio..fim)
//    está ordenada. Descubra qual comparando vetor[inicio] com vetor[meio].
//    Depois veja se o valor está dentro do intervalo da metade ordenada:
//    se estiver, vá para ela; se não, vá para a outra.
//
//    int buscaBinariaRotacionada(int vetor[], int tamanho_vetor, int valor);
//    → retorna a posição ou -1
//
// b) Usando busca binária, ache o índice do MENOR elemento (o "ponto de rotação").
//
//    Dica: compare vetor[meio] com vetor[fim]. Se vetor[meio] > vetor[fim],
//    o menor está à direita do meio; senão, está no meio ou à esquerda dele.
//
//    int indiceDoMenor(int vetor[], int tamanho_vetor);
//
// No main, leia o valor do teclado e mostre o resultado da a) e da b).
//
// Testes a):
// valor 22 → posição 2
// valor 3  → posição 4
// valor 10 → posição 7
// valor 15 → posição 0
// valor 27 → posição 3
// valor 8  → posição 6
// valor 20 → -1 (valor não encontrado)
// valor 1  → -1 (valor não encontrado)
//
// Testes b):
// {15, 18, 22, 27, 3, 5, 8, 10} → índice 4 (valor 3)
// {6, 7, 1, 2, 3, 4, 5}         → índice 2 (valor 1)
// {1, 2, 3, 4}                  → índice 0 (não foi rotacionado)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Buscas/exércicios_binárias/Questao_04_Binaria_Vetor_Rotacionado.cpp" -o "AV2/Buscas/exércicios_binárias/q4.out" && "./AV2/Buscas/exércicios_binárias/q4.out"
