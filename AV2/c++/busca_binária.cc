#include <iostream>
#include <vector>
using namespace std;

int buscaBinaria(int vetor[], int tamanho_vetor, int valor)
{
    int inicio = 0;
    int fim = tamanho_vetor - 1;
    int meio;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if(vetor[meio] == valor)
        {
            return meio;
        }

        else if(vetor[meio] < valor)
        {
            inicio = meio + 1;
        }

        else
        {
            fim = meio - 1;
        }
    }
    return -1;
}