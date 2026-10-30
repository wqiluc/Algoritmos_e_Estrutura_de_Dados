// QUESTÃO 2 – Busca Binária: Posição de Inserção
//
// Modifique a busca binária para retornar a posição onde o elemento
// deveria ser inserido.
// Caso o elemento JÁ exista no vetor, retorne nulo (-1).

// ex: {1, 3, 5, 7, 9, 11, 13}; (inserindo o 6) → posição 3

// int buscaBinaria(int vetor[], int tamanho, int valor);

// Testes:
// valor 6  → posição 3
// valor 0  → posição 0
// valor 14 → posição 7
// valor 8  → posição 4
// valor 7  → -1 (já existe, não precisa ser inserido)

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios sala de aula/Questao_02_Binaria_Posicao_Insercao.cpp" -o "AV2/exércicios sala de aula/q2.out" && "./AV2/exércicios sala de aula/q2.out"

#include <iostream>
using namespace std;

#define TAM_VETOR 7

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
            return -1;
        }

        else if (vetor[meio] < valor)
        {
            inicio = meio + 1;
        }

        else
        {
            final = meio - 1;
        }
    }
    return inicio;
}

int main()
{
    int vetor[TAM_VETOR] = {1, 3, 5, 7, 9, 11, 13};
    int valor;

    cout << "\n\t Digite um valor no vetor: ";
    cin >> valor;

    int resultado = buscaBinaria(vetor, TAM_VETOR, valor);

    if (resultado == -1)
    {
        cout << "\n\t O valor " << valor << " ja existe no vetor, nao precisa ser inserido." << endl;
    }
    else
    {
        cout << "\n\t O valor " << valor << " deve ser inserido na posicao: " << resultado << endl;
    }

    return 0;

}