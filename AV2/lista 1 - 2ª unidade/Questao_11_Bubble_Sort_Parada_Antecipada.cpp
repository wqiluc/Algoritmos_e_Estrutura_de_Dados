// QUESTÃO 11 – Bubble Sort com parada antecipada
//
// Modifique o Bubble Sort para PARAR se o vetor já estiver ordenado:
// se uma passada inteira não fizer nenhuma troca, não precisa continuar.

// ex: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; → para logo na 1ª passada

// void bubbleSortComParada(int vetor[], int tamanho_vetor);
// → usa uma flag houve_troca; se terminar a passada com false, dá break

// Testes:
// Passada 1 → 1 2 3 4 5 6 7 8 9 10 (nenhuma troca → já ordenado, parou)
// Comparações → 9 (o Bubble Sort normal faria 9+8+...+1 = 45)

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista 1 - 2ª unidade/Questao_11_Bubble_Sort_Parada_Antecipada.cpp" -o "AV2/lista 1 - 2ª unidade/q11.out" && "./AV2/lista 1 - 2ª unidade/q11.out"

#include <iostream>
#include <utility>
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

void bubbleSortComParada(int vetor[], int tamanho_vetor)
{
    int comparacoes = 0;

    for (int passada = 0; passada < tamanho_vetor - 1; passada++)
    {
        bool houve_troca = false;

        for (int j = 0; j < tamanho_vetor - 1 - passada; j++)
        {
            comparacoes++;

            if (vetor[j] > vetor[j + 1])
            {
                swap(vetor[j], vetor[j + 1]);
                houve_troca = true;
            }
        }

        cout << "\n\t Passada " << passada + 1 << ": ";
        imprimirVetor(vetor, tamanho_vetor);

        if (!houve_troca)
        {
            cout << "\n\t Nenhuma troca na passada " << passada + 1 << " → vetor já ordenado, parando." << endl;
            break;
        }
    }

    cout << "\n\t Comparações feitas: " << comparacoes << endl;
}

int main()
{
    int vetor[TAM_VETOR] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "\n\t Vetor original: ";
    imprimirVetor(vetor, TAM_VETOR);

    bubbleSortComParada(vetor, TAM_VETOR);

    return 0;
}
