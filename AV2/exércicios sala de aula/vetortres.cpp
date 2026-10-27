// Modifique a busca binária para retornar a primeira posição em que
// determinado elemento aparece.

// ex: {2, 4, 4, 4, 7, 9, 11}; (procurando o 4)

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios sala de aula/vetortres.cpp" -o "AV2/exércicios sala de aula/vetortres.out" && "./AV2/exércicios sala de aula/vetortres.out"

#include <iostream>
using namespace std;

#define TAM_VETOR 7

int buscaBinariaPrimeiraPosicao(int vetor[], int tamanho, int valor)
{
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;
    int primeira_posicao = -1;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if (vetor[meio] == valor)
        {
            primeira_posicao = meio;
            fim = meio - 1;
        }

        else if (vetor[meio] < valor)
        {
            inicio = meio + 1;
        }

        else
        {
            fim = meio - 1;
        }
    }
    return primeira_posicao;
}

int main()
{
    int vetor[TAM_VETOR] = {2, 4, 4, 4, 7, 9, 11};
    int valor;
    int indice_vetor;

    cout << "\n\t Vetor: ";

    for(indice_vetor = 0; indice_vetor < TAM_VETOR; indice_vetor++)
    {
        cout << vetor[indice_vetor] << " " << endl;
    }
    cout << endl;

    cout << "\n\t Digite o valor a ser buscado no vetor: ";
    cin >> valor;

    int posicao = buscaBinariaPrimeiraPosicao(vetor, TAM_VETOR, valor);

    if(posicao == -1)
    {
        cout << "\n Valor não encontrado no vetor." << endl;
    }

    else
    {
        cout << "\n A primeira ocorrência do valor " << valor << " está na posição " << posicao << "." << endl;
    }

    return 0;
}