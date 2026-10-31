// QUESTÃO 4 – Busca Sequencial: Valores em um Intervalo
//
// Modifique a busca sequencial p/ retornar todas as posições em que
// aparecem valores DENTRO de um intervalo [minimo, maximo] (incluindo
// os extremos).
// Se o usuário digitar minimo > maximo, troque os dois antes de buscar.

// ex: [4,8,2,8,5,8,1] = intervalo [3, 6]; → índices 0 e 4 (valores 4 e 5)

// int posicoesNoIntervalo(int vetor[], int tamanho_vetor, int minimo, int maximo, int posicoes[]);
// → preenche posicoes[] e retorna a quantidade encontrada

// Testes:
// intervalo [3, 6]  → 2 valor(es), nos índices: 0 4
// intervalo [8, 8]  → 3 valor(es), nos índices: 1 3 5
// intervalo [1, 2]  → 2 valor(es), nos índices: 2 6
// intervalo [9, 20] → nenhum valor no intervalo.
// intervalo [6, 3]  → 2 valor(es), nos índices: 0 4   (trocou os extremos)

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios sala de aula/Questao_04_Sequencial_Intervalo.cpp" -o "AV2/exércicios sala de aula/q4.out" && "./AV2/exércicios sala de aula/q4.out"


#include <iostream>
using namespace std;

#define TAM_VETOR 7

int posicoesNoIntervalo(int vetor[], int tamanho_vetor, int minimo, int maximo, int posicoes[])
{
    int indice_vetor;
    int quantidade = 0;

    if (minimo > maximo)
    {
        int auxiliar = minimo;
        minimo = maximo;
        maximo = auxiliar;
    }

    for (indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        if (vetor[indice_vetor] >= minimo && vetor[indice_vetor] <= maximo)
        {
            posicoes[quantidade] = indice_vetor;
            quantidade++;
        }
    }
    return quantidade;
}

int main()
{
    int vetor[TAM_VETOR] = {4,8,2,8,5,8,1};
    int posicoes[TAM_VETOR];
    int minimo, maximo;

    cout << "\n\t Digite o mínimo do intervalo: ";
    cin >> minimo;
    cout << "\t Digite o máximo do intervalo: ";
    cin >> maximo;

    int quantidade = posicoesNoIntervalo(vetor, TAM_VETOR, minimo, maximo, posicoes);

    if (quantidade == 0)
    {
        cout << "\n\t Nenhum valor no intervalo.\n";
    }
    else
    {
        cout << "\n\t " << quantidade << " valor(es), nos índices: ";
        
        for (int i = 0; i < quantidade; i++)
        {
            cout << posicoes[i] << " ";
        }
        cout << endl;
    }

    return 0;
}