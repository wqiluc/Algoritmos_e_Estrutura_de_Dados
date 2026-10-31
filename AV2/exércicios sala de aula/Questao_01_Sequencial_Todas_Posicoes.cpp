// QUESTÃO 1 – Busca Sequencial: Todas as Posições
//
// Modifique a busca sequencial p/ retornar todas as posições
// em que o valor procurado aparece.

// ex: {4,8,2,8,5,8,1} = valor 8; → índices 1, 3 e 5

// void buscaSequencial(int vetor[], int tamanho_vetor, int valor);
// → imprime cada posição encontrada (ou avisa que não encontrou)

// Testes:
// valor 8 → posições 1 3 5
// valor 4 → posição 0
// valor 1 → posição 6
// valor 3 → valor não encontrado!

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios sala de aula/Questao_01_Sequencial_Todas_Posicoes.cpp" -o "AV2/exércicios sala de aula/q1.out" && "./AV2/exércicios sala de aula/q1.out"

#include <iostream>
using namespace std;

#define TAM_VETOR 7

int buscaSequencial(int vetor[], int tamanho_vetor, int valor)
{  
    int indice_vetor;

    for (indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        if(vetor[indice_vetor] == valor)
        {
            cout << "\n\t O valor: " << vetor[indice_vetor] << " encontra-se nos índices: " << indice_vetor << endl;
        }
    }
    return -1;
}

int main()
{
    int vetor[TAM_VETOR] = {4,8,2,8,5,8,1};
    int valor = 8;

    buscaSequencial(vetor, TAM_VETOR, valor);

    return 0;
}