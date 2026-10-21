#include <iostream>
#include <vector>
using namespace std;

int buscaBinaria(int vetor[], int tamanho_vetor, int valor)
{
    int inicio = 0;
    int final = tamanho_vetor - 1; 
    int meio;

    while (inicio <= final)
    {
        meio = (inicio + final) / 2;

        if (vetor[meio] == valor)
        {
            return meio;
        }

        else if(vetor[meio] < valor)
        {
            inicio = meio + 1;
        }
        
        else
        {
            final = meio - 1;
        }
    }
    return -1;
}