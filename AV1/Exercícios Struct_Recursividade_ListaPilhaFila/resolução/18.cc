#include <iostream>
using namespace std;

int maiorElemento(int vetor[], int tamanho_vetor)
{
    int maior = vetor[0];

    for (int indice_vetor = 1; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        if (vetor[indice_vetor] > maior)
        {
            maior = vetor[indice_vetor];
        }
    }

    return maior;
}

int main()
{
    int tamanho_vetor;
    int indice_vetor;

    cout << "\n\t Digite o tamanho do vetor: ";
    cin >> tamanho_vetor;

    int* vetor = new int[tamanho_vetor];

    for (indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        cout << "Digite o " << indice_vetor + 1 << "º valor: ";
        cin >> vetor[indice_vetor];
    }

    cout << "Maior elemento: " << maiorElemento(vetor, tamanho_vetor) << endl;

    delete[] vetor;
    return 0;
}