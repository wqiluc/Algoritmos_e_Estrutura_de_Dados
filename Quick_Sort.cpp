// QUICK SORT
//
// Escolhe um PIVÔ (o ÚLTIMO elemento do trecho, como no slide) e PARTICIONA:
// tudo MENOR que o pivô vai para a esquerda, tudo MAIOR OU IGUAL vai para a
// direita, e o pivô cai na sua POSIÇÃO FINAL. Depois repete para cada lado.
//
// Partition do slide (Lomuto):
//   pivo = vetor[final]
//   i = inicio - 1                       → fim da região dos menores
//   para j de inicio até final - 1:
//       se vetor[j] < pivo → i++ e troca vetor[i] com vetor[j]
//   no fim, troca vetor[i + 1] com vetor[final] → o pivô cai na posição i + 1
//
// ex: {8, 3, 5, 1, 9, 2, 7, 0, 4, 6}; → 0 1 2 3 4 5 6 7 8 9
// (mesmo vetor da Questão 07 da revisão AV2: rode para conferir o papel)
//
// Complexidade: O(n log n) no médio, O(n²) no pior caso. Não é estável.
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 Quick_Sort.cpp -o quick.out && ./quick.out

#include <iostream>
using namespace std;

#define TAM_VETOR 10

void imprimirVetor(int vetor[], int tamanho_vetor)
{
    for (int indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        cout << vetor[indice_vetor] << " ";
    }
    cout << endl;
}

int particionar(int vetor[], int inicio, int final)
{
    int pivo = vetor[final];
    int i = inicio - 1;

    for (int j = inicio; j < final; j++)
    {
        if (vetor[j] < pivo)
        {
            i++;
            swap(vetor[i], vetor[j]);
        }
    }

    swap(vetor[i + 1], vetor[final]);

    return i + 1;
}

void quickSort(int vetor[], int inicio, int final)
{
    if (inicio >= final)
    {
        return;
    }

    int posicao_pivo = particionar(vetor, inicio, final);

    cout << "\n\t Pivô " << vetor[posicao_pivo] << " na posição " << posicao_pivo << " → ";
    imprimirVetor(vetor, TAM_VETOR);

    quickSort(vetor, inicio, posicao_pivo - 1);
    quickSort(vetor, posicao_pivo + 1, final);
}

int main()
{
    int vetor[TAM_VETOR] = {8, 3, 5, 1, 9, 2, 7, 0, 4, 6};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    quickSort(vetor, 0, TAM_VETOR - 1);

    cout << "\n\t Vetor ordenado: ";
    imprimirVetor(vetor, TAM_VETOR);

    return 0;
}
