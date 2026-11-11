// QUESTÃO 4 – Busca Sequencial: Auto-organizável (Mover para Frente)
//
// Em muitos sistemas, os mesmos valores são buscados várias vezes. A técnica
// "mover para frente" aproveita isso: toda vez que um valor é ENCONTRADO,
// ele é levado para a posição 0, e os elementos que estavam antes dele andam
// uma casa para a direita. Assim, quem é buscado com frequência fica no começo
// e as próximas buscas por ele ficam mais rápidas.
//
// Valor   10  20  30  40  50
// Índice  0   1   2   3   4
//
// ex: buscar 40 → achou na posição 3 → o vetor vira {40, 10, 20, 30, 50}
//
// int buscaMoverParaFrente(int vetor[], int tamanho_vetor, int valor, int &comparacoes);
// → retorna a posição onde o valor ESTAVA (antes de mover) ou -1
// → comparacoes: quantas vezes comparou vetor[indice] com o valor
// → se não achar, o vetor não muda
//
// No main, faça as buscas abaixo NESTA ORDEM (no mesmo vetor) e imprima o vetor
// depois de cada uma.
//
// Testes (o vetor vai mudando de uma busca para a outra):
// buscar 40 → estava na posição 3, 4 comparações → 40 10 20 30 50
// buscar 20 → estava na posição 2, 3 comparações → 20 40 10 30 50
// buscar 40 → estava na posição 1, 2 comparações → 40 20 10 30 50
// buscar 60 → não encontrado,      5 comparações → 40 20 10 30 50
// buscar 50 → estava na posição 4, 5 comparações → 50 40 20 10 30
//
// Perguntas:
// 1) A 1ª busca pelo 40 custou 4 comparações. Quanto custou a 2ª? Por quê?
// 2) Em que situação essa técnica PIORA as buscas?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Buscas/exércicios_sequenciais/Questao_04_Sequencial_Mover_Para_Frente.cpp" -o "AV2/Buscas/exércicios_sequenciais/q4.out" && "./AV2/Buscas/exércicios_sequenciais/q4.out"

#include <iostream>
using namespace std;

#define TAMANHO_VETOR 5

int buscaMoverParaFrente(int vetor[], int tamanho_vetor, int valor, int &comparacoes)
{
    int indice_comparacoes = 0;

    for (indice_comparacoes = 0; indice_comparacoes < tamanho_vetor; indice_comparacoes++)
    {
        comparacoes++;

        if (vetor[indice_comparacoes] == valor)
        {
            int temp = vetor[indice_comparacoes];

            for (int j = indice_comparacoes; j > 0; j--)
            {
                vetor[j] = vetor[j - 1];
            }
            vetor[0] = temp;
            return indice_comparacoes; 
        }
    }
    return -1; // Valor não encontrado
}

int main()
{
    int vetor[TAMANHO_VETOR] = {10, 20, 30, 40, 50};
    int comparacoes = 0;

    // Buscar 40
    int posicao = buscaMoverParaFrente(vetor, TAMANHO_VETOR, 40, comparacoes);
    cout << "Buscar 40: estava na posição " << posicao << ", " << comparacoes << " comparações → ";
    for (int i = 0; i < TAMANHO_VETOR; i++) 
    {
        cout << vetor[i] << " ";
    }
    cout << endl;

    // Resetar comparações para a próxima busca
    comparacoes = 0;

    // Buscar 20
    posicao = buscaMoverParaFrente(vetor, TAMANHO_VETOR, 20, comparacoes);
    cout << "Buscar 20: estava na posição " << posicao << ", " << comparacoes << " comparações → ";
    for (int i = 0; i < TAMANHO_VETOR; i++) 
    {
        cout << vetor[i] << " ";
    }
    cout << endl;

    // Resetar comparações para a próxima busca
    comparacoes = 0;

    // Buscar 40 novamente
    posicao = buscaMoverParaFrente(vetor, TAMANHO_VETOR, 40, comparacoes);
    cout << "Buscar 40: estava na posição " << posicao << ", " << comparacoes << " comparações → ";
    for (int i = 0; i < TAMANHO_VETOR; i++) 
    {
        cout << vetor[i] << " ";
    }
    cout << endl;

    // Resetar comparações para a próxima busca
    comparacoes = 0;

    // Buscar 60 (não encontrado)
    posicao = buscaMoverParaFrente(vetor, TAMANHO_VETOR, 60, comparacoes);
    cout << "Buscar 60: não encontrado, " << comparacoes << " comparações → ";
    for (int i = 0; i < TAMANHO_VETOR; i++) 
    {
        cout << vetor[i] << " ";
    }
    cout << endl;

    // Resetar comparações para a próxima busca
    comparacoes = 0;

    // Buscar 50
    posicao = buscaMoverParaFrente(vetor, TAMANHO_VETOR, 50, comparacoes);
    cout << "Buscar 50: estava na posição " << posicao << ", " << comparacoes << " comparações → ";
    for (int i = 0; i < TAMANHO_VETOR; i++) 
    {
        cout << vetor[i] << " ";
    }
    cout << endl;

    return 0;
}