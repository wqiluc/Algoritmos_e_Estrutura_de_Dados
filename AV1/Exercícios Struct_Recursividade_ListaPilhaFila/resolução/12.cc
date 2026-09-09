#include <iostream>
using namespace std;

int maiorElemento(int vetor[], int tamanho_vetor)
{
    if (tamanho_vetor == 1)
    {
        return vetor[0];
    }

    int maior_resto = maiorElemento(vetor + 1, tamanho_vetor - 1);

    return vetor[0] > maior_resto ? vetor[0] : maior_resto;
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