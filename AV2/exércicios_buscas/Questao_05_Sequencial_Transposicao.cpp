// QUESTÃO 5 – Busca Sequencial Auto-organizável: Transposição
//
// Valor   10  20  30  40  50
// Índice  0   1   2   3   4
//
// Toda vez que um valor é ENCONTRADO numa posição i > 0, ele troca de lugar
// com o vizinho da esquerda (vetor[i - 1]). Assim, os valores mais buscados
// vão "subindo" para o começo do vetor e ficam mais rápidos de achar.
//
// int buscaTransposicao(int vetor[], int tamanho_vetor, int valor);
// → retorna o índice onde o valor ficou DEPOIS da troca (ou -1)
//
// No main, faça as buscas abaixo NESTA ORDEM e imprima o vetor após cada uma:
// 40, 40, 40, 50, 10, 25
//
// a) No papel: como fica o vetor após cada busca? Quantas comparações cada uma fez?
// b) Qual é o vetor final?
// c) O que acontece com o vetor na busca do 25?
// d) Em que situação essa estratégia é vantajosa? E quando ela não ajuda?
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// a) Busca | Comparações | Vetor depois
//    40    |             |
//    40    |             |
//    40    |             |
//    50    |             |
//    10    |             |
//    25    |             |
// b)
// c)
// d)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 AV2/exércicios_buscas/Questao_05_Sequencial_Transposicao.cpp -o AV2/exércicios_buscas/q5.out && ./AV2/exércicios_buscas/q5.out

#include <iostream>
using namespace std;

#define TAM_VETOR 5

int buscaTransposicao(int vetor[], int tamanho_vetor, int valor)
{
    int indice_vetor;

    for (indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        if(vetor[indice_vetor] == valor)
        {
            if (indice_vetor > 0)
            {
                int auxiliar = vetor[indice_vetor];
                vetor[indice_vetor] = vetor[indice_vetor - 1];
                vetor[indice_vetor - 1] = auxiliar;

                return indice_vetor - 1;
            }
            return indice_vetor;
        }
    }
    return -1;
}

void imprimirVetor(int vetor[], int tamanho_vetor)
{
    int indice_vetor;

    for (indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        cout << vetor[indice_vetor] << " " << endl;
    }
    cout << endl;
}

int main()
{
    int vetor[TAM_VETOR] = {10,  20, 30,  40, 50};
    int buscas[] = {40, 40, 40, 50, 10, 25};
    int quantidade_buscas = sizeof(buscas) / sizeof(buscas[0]);
    int indice_busca;

    cout << "\n Vetor inicial: ";
    imprimirVetor(vetor, TAM_VETOR);

    for (indice_busca = 0; indice_busca < quantidade_buscas; indice_busca++)
    {
        int indice = buscaTransposicao(vetor, TAM_VETOR, buscas[indice_busca]);

        cout << "\n Busca " << buscas[indice_busca] << " → índice: " << indice << " | Vetor: ";
        imprimirVetor(vetor, TAM_VETOR);
    }

    return 0;
}