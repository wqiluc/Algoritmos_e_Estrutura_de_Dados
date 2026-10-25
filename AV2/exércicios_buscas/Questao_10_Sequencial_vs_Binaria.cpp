// QUESTÃO 10 – Sequencial x Binária: Quem Ganha? (💻 código + ✏️ papel)
//
// Monte um vetor ORDENADO de tamanho n com os pares 2, 4, 6, ..., 2n
// (vetor[i] = 2 * (i + 1)), alocado dinamicamente:
//
// int *vetor = new int[n];   ...   delete[] vetor;
//
// Implemente as duas buscas contando os ACESSOS ao vetor
// (cada volta do laço = 1 acesso):
//
// int buscaSequencial(int vetor[], int tamanho_vetor, int valor, int &acessos);
// int buscaBinaria(int vetor[], int tamanho_vetor, int valor, int &acessos);
//
// Para n = 10, 1.000, 100.000 e 1.000.000, busque:
//   - o ÚLTIMO elemento (2n)
//   - um valor AUSENTE (2n + 1)
// e imprima uma tabela:
//
//         n | seq (último) | bin (último) | seq (ausente) | bin (ausente)
//
// a) ANTES de rodar, estime os valores da tabela no papel.
// b) Quantas vezes a binária é mais rápida para n = 1.000.000?
// c) Se o vetor viesse DESORDENADO e você fosse fazer só UMA busca, valeria a
//    pena ordenar antes para usar a binária? E se fossem 1.000 buscas?
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// a)         n | seq (último) | bin (último) | seq (ausente) | bin (ausente)
//           10 |              |              |               |
//        1.000 |              |              |               |
//      100.000 |              |              |               |
//    1.000.000 |              |              |               |
// b)
// c)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 AV2/exércicios_buscas/Questao_10_Sequencial_vs_Binaria.cpp -o AV2/exércicios_buscas/q10.out && ./AV2/exércicios_buscas/q10.out
