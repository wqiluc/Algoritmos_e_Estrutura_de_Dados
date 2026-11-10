// QUESTÃO 2 – Busca Sequencial: contar ocorrências
//
// Conte quantas vezes o número 7 aparece no vetor.

// ex: {7, 3, 5, 7, 9, 2, 7, 1, 4, 6}; (contando o 7) → 3 vezes

// int contarOcorrencias(int vetor[], int tamanho_vetor, int valor_buscado);
// → percorre o vetor inteiro e retorna quantas vezes o valor aparece

// Testes:
// valor 7 → aparece 3 vezes (posições 0, 3 e 6)

// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/lista 1 - 2ª unidade/Questao_02_Sequencial_Contar_Ocorrencias.cpp" -o "AV2/lista 1 - 2ª unidade/q2.out" && "./AV2/lista 1 - 2ª unidade/q2.out"

#include <iostream>
using namespace std;

#define TAM_VETOR 10
#define VALOR_BUSCADO 7

void imprimirVetor(int vetor[], int tamanho_vetor)
{
    for (int indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        cout << vetor[indice_vetor] << " ";
    }
    cout << endl;
}

int contarOcorrencias(int vetor[], int tamanho_vetor, int valor_buscado)
{
    int contador = 0;

    for (int indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        if (vetor[indice_vetor] == valor_buscado)
        {
            contador++;
        }
    }
    return contador;
}

int main()
{
    int vetor[TAM_VETOR] = {7, 3, 5, 7, 9, 2, 7, 1, 4, 6};

    cout << "\n\t Vetor: ";
    imprimirVetor(vetor, TAM_VETOR);

    int quantidade = contarOcorrencias(vetor, TAM_VETOR, VALOR_BUSCADO);

    cout << "\n\t O valor " << VALOR_BUSCADO << " aparece " << quantidade << " vezes." << endl;

    return 0;
}
