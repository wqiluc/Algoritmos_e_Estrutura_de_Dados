#include <iostream>
#include <vector>
using namespace std;

int buscaSequencial(int vetor[], int tamanho_vetor, int valor)
{
    int indice_vetor;

    for (indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
       if (vetor[indice_vetor] == valor)
       {
            return indice_vetor;
       }
       return -1;
    }
}