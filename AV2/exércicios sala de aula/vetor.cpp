// Contexto: Modifique a busca sequencial p/ retornar todas as posições
// em que o valor procurado aparece.

// ex: [4,8,2,8,5,8,1] = valor 8;

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios sala de aula/vetor.cpp" -o "AV2/exércicios sala de aula/vetor.out" && "./AV2/exércicios sala de aula/vetor.out"

#include <iostream>
using namespace std;

#define TAM_VETOR 7

void buscaSequencial(int vetor[], int tamanho_vetor, int valor)
{
    int indice_vetor;
    int encontrou = 0;

    for (indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        if(vetor[indice_vetor] == valor)
        {
            cout << "\n Valor encontrado na posição: " << indice_vetor << " "  << endl;
            encontrou = 1;
        }
    }
    if (!encontrou)
    {
        cout << "Valor não encontrado!" << endl;
    }
}

int main()
{
    int vetor[] = {4, 8, 2, 8, 5, 8, 1};
    int valor = 8;

    buscaSequencial(vetor, TAM_VETOR, valor);

    return 0;
}
