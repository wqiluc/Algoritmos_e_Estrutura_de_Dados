// QUESTÃO 8 – Busca Binária em Vetor Decrescente (💻 código + ✏️ papel)
//
// Valor   95  88  71  64  50  42  37  21  13  6
// Índice  0   1   2   3   4   5   6   7   8   9
//
// O vetor está ordenado, mas em ordem DECRESCENTE. Adapte a busca binária
// para funcionar nele.
//
// int buscaBinariaDecrescente(int vetor[], int tamanho_vetor, int valor);
//
// Testes:
// buscar 95 → 0
// buscar 42 → 5
// buscar 6  → 9
// buscar 40 → -1
//
// a) O que muda em relação à busca binária crescente?
// b) No papel: rode a busca binária CRESCENTE (AV2/c++/Questao_02_Busca_Binaria.cpp)
//    procurando o 21 neste vetor. Monte a tabela. O que ela retorna? Por quê?
// c) Desafio: faça uma única função que descobre sozinha se o vetor é
//    crescente ou decrescente (comparando vetor[0] e vetor[tamanho_vetor - 1])
//    e busca corretamente nos dois casos.
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// a)
// b) inicio | fim | meio | vetor[meio] | decisão
//
//    retorno:
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 AV2/exércicios_buscas/Questao_08_Binaria_Decrescente.cpp -o AV2/exércicios_buscas/q8.out && ./AV2/exércicios_buscas/q8.out
