// QUESTÃO 1 – Busca Sequencial: com Sentinela
//
// Na busca sequencial normal, cada volta do laço faz DUAS comparações:
// "indice < tamanho" (para não passar do fim) e "vetor[indice] == valor".
//
// A busca com sentinela elimina a primeira: antes de começar, copia o valor
// procurado para uma posição EXTRA no fim do vetor (a "sentinela"). Assim o
// laço SEMPRE para (no pior caso, na sentinela) e só precisa comparar com o valor.
// No fim, se parou na sentinela (indice == tamanho), o valor não existe.
//
// Valor   7   3   9   1   5   8   [ ]  ← posição extra para a sentinela
// Índice  0   1   2   3   4   5    6
//
// ex: {7, 3, 9, 1, 5, 8}; (procurando o 9) → posição 2
//
// int buscaSequencialNormal(int vetor[], int tamanho_vetor, int valor, int &comparacoes);
// int buscaSequencialSentinela(int vetor[], int tamanho_vetor, int valor, int &comparacoes);
// → as duas retornam a posição ou -1
// → comparacoes: conte TODAS as comparações feitas no laço
//   (na normal, conte o "indice < tamanho" E o "==", inclusive o "<" que deu
//   falso e encerrou o laço)
// → declare o vetor com TAM_VETOR + 1 posições
//
// No main, leia o valor do teclado e mostre o resultado das duas versões.
//
// Testes:
// valor 9 → posição 2  | normal: 6 comparações  | sentinela: 3 comparações
// valor 7 → posição 0  | normal: 2 comparações  | sentinela: 1 comparação
// valor 8 → posição 5  | normal: 12 comparações | sentinela: 6 comparações
// valor 4 → -1         | normal: 13 comparações | sentinela: 7 comparações (parou na sentinela, índice 6)
//
// Pergunta: por que a sentinela praticamente corta as comparações pela metade?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Buscas/exércicios_sequenciais/Questao_01_Sequencial_Sentinela.cpp" -o "AV2/Buscas/exércicios_sequenciais/q1.out" && "./AV2/Buscas/exércicios_sequenciais/q1.out"

#include <iostream>
using namespace std;

#define TAM_VETOR 6

int buscaSequencialNormal(int vetor[], int tamanho_vetor, int valor, int &comparacoes) 
{
    for (int i = 0; i < tamanho_vetor; i++) 
    {
        comparacoes++;
        if (vetor[i] == valor) 
        {
            comparacoes++;
            return i;
        }
        comparacoes++;
    }
    return -1;
}

int buscaSequencialSentinela(int vetor[], int tamanho_vetor, int valor, int &comparacoes) 
{
    vetor[tamanho_vetor] = valor;
    int indice = 0;

    while (true) 
    {
        comparacoes++;
        if (vetor[indice] == valor) 
        {
            comparacoes++;
            break;
        }
        indice++;
    }

    if (indice == tamanho_vetor) 
    {
        return -1; // Valor não encontrado = falso
    }
    return indice; // Valor encontrado
}

int main()
{
    int vetor[TAM_VETOR + 1] = {7, 3, 9, 1, 5, 8}; // Vetor com posição extra para a sentinela
    int valor, posicaoNormal, posicaoSentinela;
    int comparacoesNormal = 0, comparacoesSentinela = 0;

    cout << "\n\t Digite o valor a ser buscado: ";
    cin >> valor;

    posicaoNormal = buscaSequencialNormal(vetor, TAM_VETOR, valor, comparacoesNormal);
    posicaoSentinela = buscaSequencialSentinela(vetor, TAM_VETOR, valor, comparacoesSentinela);

    cout << "\n\t Resultados:";

    cout << "\n\t Busca Normal: ";
    if (posicaoNormal == -1) 
    {
        cout << "Valor não encontrado";
    }
    else
    {
        cout << "Valor encontrado na posição " << posicaoNormal;
    }

    cout << " (Comparações: " << comparacoesNormal << ")";

    cout << "\n\t Busca com Sentinela: ";
    
    if (posicaoSentinela == -1) 
    {
        cout << "Valor não encontrado";
    }
    else
    {
        cout << "Valor encontrado na posição " << posicaoSentinela;
    }
    return 0;
}