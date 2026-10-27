// Contexto: Modifique a busca sequencial p/ retornar todas as posições
// em que o valor procurado aparece.

// ex: [4,8,2,8,5,8,1] = valor 8;

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios sala de aula/vetor.cpp" -o "AV2/exércicios sala de aula/q1.out" && "./AV2/exércicios sala de aula/vetor.out"

#include <iostream>
using namespace std;

#define TAM_VETOR 7

int posicoesValorVetor(int vetor[], int tamanho_vetor, int valor, int posicoes[])
{
    int indice_vetor;
    int quantidade = 0;

    for(indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        if(vetor[indice_vetor] == valor)
        {
            posicoes[quantidade] = indice_vetor;
            quantidade++;
        }
    }
    return quantidade;
}


int main()
{
    int vetor[TAM_VETOR] = {4, 8, 2, 8, 5, 8, 1};
    int posicoes[TAM_VETOR];
    int valor;

    cout << "\n\t Digite o valor a ser buscado no vetor: ";
    cin >> valor;

    int quantidade = posicoesValorVetor(vetor, TAM_VETOR, valor, posicoes);

    if(quantidade > 0)
    {
        cout << "\n Valor encontrado " << quantidade << " vez(es), nos índices: ";

        int indice_posicoes;

        for(indice_posicoes = 0; indice_posicoes < quantidade; indice_posicoes++)
        {
            cout << posicoes[indice_posicoes] << " ";
        }
        cout << endl;
    }

    else
    {
        cout << "\n Valor não encontrado no vetor." << endl;
    }

    return 0;
}