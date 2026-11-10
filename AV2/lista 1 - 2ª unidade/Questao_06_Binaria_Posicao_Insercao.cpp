// QUESTÃO 6 – Busca Binária: posição de inserção
//
// Use a busca binária para retornar a posição onde o 27 deveria ser
// inserido para o vetor continuar ordenado.
// Caso o elemento JÁ exista no vetor, retorne -1.
//
// Valor   5   10  15  20  25  30  35  40  45  50
// Índice  0   1   2   3   4   5   6   7   8   9

// ex: {5, 10, 15, 20, 25, 30, 35, 40, 45, 50}; (inserindo o 27) → posição 5

// int posicaoInsercao(int vetor[], int tamanho_vetor, int valor);
// → quando o while termina sem achar, "inicio" é a posição de inserção

// Testes:
// inicio 0, final 9 → meio 4 (25) → 25 < 27, vai pra direita
// inicio 5, final 9 → meio 7 (40) → 40 > 27, vai pra esquerda
// inicio 5, final 6 → meio 5 (30) → 30 > 27, vai pra esquerda
// parou com inicio 5 → posição de inserção 5
// Vetor depois de inserir → 5 10 15 20 25 27 30 35 40 45 50

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_06_Binaria_Posicao_Insercao.cpp -o q6.out && ./q6.out

#include <iostream>
using namespace std;

#define TAM_VETOR 10
#define VALOR_INSERIR 27

void imprimirVetor(int vetor[], int tamanho_vetor)
{
    for (int indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        cout << vetor[indice_vetor] << " ";
    }
    cout << endl;
}

int posicaoInsercao(int vetor[], int tamanho_vetor, int valor)
{
    int inicio = 0;
    int final = tamanho_vetor - 1;

    while (inicio <= final)
    {
        int meio = (inicio + final) / 2;

        cout << "\n\t inicio " << inicio << ", final " << final
             << " → meio " << meio << " (" << vetor[meio] << ")";

        if (vetor[meio] == valor)
        {
            cout << " → já existe!" << endl;
            return -1;
        }

        else if (vetor[meio] < valor)
        {
            cout << " → vai pra direita";
            inicio = meio + 1;
        }

        else
        {
            cout << " → vai pra esquerda";
            final = meio - 1;
        }
    }
    cout << endl;
    return inicio;
}

// empurra todo mundo da posição pra frente uma casa e coloca o valor
void inserirNaPosicao(int vetor[], int tamanho_vetor, int posicao, int valor)
{
    for (int indice_vetor = tamanho_vetor; indice_vetor > posicao; indice_vetor--)
    {
        vetor[indice_vetor] = vetor[indice_vetor - 1];
    }
    vetor[posicao] = valor;
}

int main()
{
    int vetor[TAM_VETOR + 1] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50}; // +1 de espaço pro novo valor

    cout << "\n\t Vetor: ";
    imprimirVetor(vetor, TAM_VETOR);

    int posicao = posicaoInsercao(vetor, TAM_VETOR, VALOR_INSERIR);

    if (posicao == -1)
    {
        cout << "\n\t O valor " << VALOR_INSERIR << " já existe no vetor." << endl;
    }

    else
    {
        cout << "\n\t O valor " << VALOR_INSERIR << " deve ser inserido na posição: " << posicao << endl;

        inserirNaPosicao(vetor, TAM_VETOR, posicao, VALOR_INSERIR);

        cout << "\n\t Vetor depois de inserir: ";
        imprimirVetor(vetor, TAM_VETOR + 1);
    }

    return 0;
}
