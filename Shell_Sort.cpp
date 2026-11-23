// SHELL SORT
//
// É o INSERTION SORT COM SALTOS (gap). Em vez de comparar vizinhos, compara
// elementos que estão a GAP posições de distância. O gap começa em n / 2 e cai
// pela metade (divisão inteira!) até chegar em 1. Com gap 1 vira o Insertion
// Sort normal, mas o vetor já chega quase ordenado.
//
// Shell Sort do slide:
//   para gap de n / 2 até 1 (gap /= 2):
//       para i de gap até n - 1:
//           temp = vetor[i]
//           j = i
//           enquanto j >= gap e vetor[j - gap] > temp:
//               vetor[j] = vetor[j - gap]    → desloca gap casas para a direita
//               j -= gap
//           vetor[j] = temp
//
// No papel: com gap g, o vetor vira g SUBLISTAS intercaladas (índices
// 0, g, 2g, ... depois 1, 1+g, 1+2g, ...). Ordene cada sublista e devolva os
// valores nos mesmos índices.
//
// Gaps (divisão inteira): n = 6 ou 7 → 3, 1 · n = 8 ou 9 → 4, 2, 1
//
// ex: {12, 5, 9, 3, 10, 1, 8, 4}; (n = 8 → gaps 4, 2, 1) → 1 3 4 5 8 9 10 12
// (mesmo vetor da Questão 06 da revisão AV2: rode para conferir o papel)
//
// void shellSort(int vetor[], int tamanho_vetor);
// → para cada gap imprime as sublistas (antes → depois), o vetor no fim do
//   gap, as comparações e os deslocamentos
//
// Comparação: cada vez que testa vetor[j - gap] > temp.
// Deslocamento: cada vez que um elemento anda gap casas para a direita.
//
// Complexidade: depende da sequência de gaps. Com gaps n / 2: melhor caso
// O(n log n) (vetor já ordenado), pior caso O(n²). Não é estável (os saltos
// passam um elemento por cima de outro igual). É in-place.
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 Shell_Sort.cpp -o shell.out && ./shell.out

#include <iostream>
using namespace std;

#define TAM_VETOR 8

void imprimirVetor(int vetor[], int tamanho_vetor)
{
    for (int i = 0; i < tamanho_vetor; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void ShellSort(int vetor[], int tamamho_vetor)
{
    int total_comparacoes = 0, total_deslocamentos = 0;
    int gap;

    for (gap = tamamho_vetor / 2; gap > 0; gap /= 2)
    {
        int comparacoes = 0, deslocamentos = 0;
        int i;

        for (i = gap; i < tamamho_vetor; i++)
        {
            int temp = vetor[i];
            int j = i;

            while (j >= gap)
            {
                comparacoes++;

                if (vetor[j - gap] <= temp)
                {
                    break;
                }

                vetor[j] = vetor[j - gap];
                deslocamentos++;
                j -= gap;
            }
            vetor[j] = temp;
        }

        cout << "\n\t Gap " << gap << " → ";
        imprimirVetor(vetor, tamamho_vetor);
        cout << "\t Comparações: " << comparacoes << " · Deslocamentos: " << deslocamentos << endl;

        total_comparacoes += comparacoes;
        total_deslocamentos += deslocamentos;
    }

    cout << "\n\t Total: " << total_comparacoes << " comparações, " << total_deslocamentos << " deslocamentos" << endl;
}

int main()
{
    int vetor[TAM_VETOR] = {12, 5, 9, 3, 10, 1, 8, 4};

    cout << "\n\t Vetor Impresso: ";
    imprimirVetor(vetor, TAM_VETOR);

    ShellSort(vetor, TAM_VETOR);

    cout << "\n\t Vetor Ordenado: ";
    imprimirVetor(vetor, TAM_VETOR);

    return 0;
}