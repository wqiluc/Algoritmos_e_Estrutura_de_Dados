// Modifique a busca binária para retornar a posição onde o elemento
// deveria ser inserido.
// Caso não exista, retorne nulo.

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios sala de aula/vetordois.cpp" -o "AV2/exércicios sala de aula/vetordois.out" && "./AV2/exércicios sala de aula/vetordois.out"

#include <iostream>
using namespace std;

#define TAM_VETOR 7

int buscaBinaria(int vetor[], int tamanho, int valor)
{
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if (vetor[meio] == valor)
        {
            return -1;
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
    return inicio;
}

int main()
{
    int vetor[TAM_VETOR] = {1, 3, 5, 7, 9, 11, 13};
    int valor;
    int indice_vetor;

    cout << "\n\t Vetor: ";

    for(indice_vetor = 0; indice_vetor < TAM_VETOR; indice_vetor++)
    {
        cout << vetor[indice_vetor] << " ";
    }
    cout << endl;

    cout << "\n\t Digite o valor a ser inserido no vetor: ";
    cin >> valor;

    int posicao = buscaBinaria(vetor, TAM_VETOR, valor);

    if(posicao == -1)
    {
        cout << "\n Valor já existe no vetor, não precisa ser inserido (nulo)." << endl;
    }

    else
    {
        cout << "\n O valor " << valor << " deveria ser inserido na posição " << posicao << "." << endl;
    }

    return 0;
}