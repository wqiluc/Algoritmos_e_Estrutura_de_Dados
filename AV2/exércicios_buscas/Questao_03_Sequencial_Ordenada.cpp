// QUESTÃO 3 – Busca Sequencial em Vetor Ordenado
//
// Valor   3   9   14  21  30  47  52  68  75  90
// Índice  0   1   2   3   4   5   6   7   8   9
//
// Se o vetor está ordenado, a busca sequencial pode PARAR ANTES do fim:
// assim que encontrar um elemento MAIOR que o valor buscado, o valor com
// certeza não está no vetor.
//
// int buscaSequencialOrdenada(int vetor[], int tamanho_vetor, int valor);
//
// Testes:
// buscar 47 → 5
// buscar 3 → 0
// buscar 22 → -1
// buscar 1 → -1
// buscar 100 → -1
//
// a) Quantos elementos são visitados ao buscar 22? E 1? E 100?
// b) Quantos a busca sequencial NORMAL visitaria para buscar 22?
// c) Essa melhoria muda a complexidade de pior caso? Por quê?
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// a) 22: 3 | 1: 1 | 100: 10
// b) 22: 10
// c) Não, a complexidade de pior caso ainda é O(n), pois no pior caso, o valor pode estar no último elemento ou não estar presente.
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 AV2/exércicios_buscas/Questao_03_Sequencial_Ordenada.cpp -o AV2/exércicios_buscas/q3.out && ./AV2/exércicios_buscas/q3.out

#include <iostream>
using namespace std;

#define TAM_VETOR 10

int buscaSequencialOrdenada(int vetor[], int tamanho_vetor, int valor)
{
    int indice_vetor;

    for(indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        if(vetor[indice_vetor] == valor)
        {
            return indice_vetor;
        }

        else if(vetor[indice_vetor] > valor)
        {
            return -1;
        }
    }
    return -1;
}

int main()
{
    int vetor[TAM_VETOR] = {3, 9, 14, 21, 30, 47, 52, 68, 75, 90};
    int valor;

    cout << "\n\t Digite o valor a ser buscado no vetor: ";
    cin >> valor;

    int resultado = buscaSequencialOrdenada(vetor, TAM_VETOR, valor);

    if(resultado != -1)
    {
        cout << "\n Valor encontrado no índice: " << resultado << endl;
    }

    else
    {
        cout << "\n Valor não encontrado." << endl;
    }

    return 0;
}