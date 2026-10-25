// QUESTÃO 6 – Busca Binária Passo a Passo (💻 código + ✏️ papel)
//
// Valor   4   11  17  23  29  36  42  50  63  77  85  98
// Índice  0   1   2   3   4   5   6   7   8   9   10  11
//
// Implemente a busca binária iterativa que IMPRIME cada passo no formato:
//
// inicio | fim | meio | vetor[meio] | decisão
//
// onde decisão é "achou", "vai p/ direita" ou "vai p/ esquerda".
//
// int buscaBinariaPassoAPasso(int vetor[], int tamanho_vetor, int valor);
//
// a) Faça a tabela no papel para buscar 63, 4 e 40.
// b) Rode o programa e confira com a sua tabela.
// c) Qual o número MÁXIMO de acessos para um vetor de 12 elementos?
// d) Cite um valor do vetor que precisa do número máximo de acessos.
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// a) buscar 63
//    inicio | fim | meio | vetor[meio] | decisão
//
//    buscar 4
//    inicio | fim | meio | vetor[meio] | decisão
//
//    buscar 40
//    inicio | fim | meio | vetor[meio] | decisão
//
// c)
// d)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 AV2/exércicios_buscas/Questao_06_Binaria_Passo_a_Passo.cpp -o AV2/exércicios_buscas/q6.out && ./AV2/exércicios_buscas/q6.out
