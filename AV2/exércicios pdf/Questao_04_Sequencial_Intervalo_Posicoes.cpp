// QUESTÃO 4 – Busca Sequencial: Busca em um Intervalo de Posições
//
// Modifique a busca sequencial para pesquisar EXCLUSIVAMENTE dentro de um
// intervalo definido por duas posições (início e fim) informadas pelo usuário.
//
// Valor   11  24  7   36  15  24  50  3
// Índice  0   1   2   3   4   5   6   7
//
// ex: {11, 24, 7, 36, 15, 24, 50, 3}; (procurando o 24 entre as posições 2 e 6) → posição 5
//
// int buscaSequencialIntervalo(int vetor[], int inicio, int fim, int valor);
// → procura só de vetor[inicio] até vetor[fim] (incluindo os dois)
// → retorna a posição encontrada ou -1
//
// No main, leia o valor, o início e o fim. Se o intervalo for inválido
// (inicio < 0, fim >= tamanho do vetor ou inicio > fim), avise e não faça a busca.
//
// Testes:
// valor 24, intervalo [2, 6]  → posição 5   (o 24 da posição 1 fica de fora)
// valor 24, intervalo [0, 7]  → posição 1
// valor 3,  intervalo [4, 7]  → posição 7
// valor 11, intervalo [1, 7]  → não encontrado no intervalo (o 11 está na posição 0)
// intervalo [5, 2]            → intervalo inválido!
// intervalo [0, 10]           → intervalo inválido!
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/exércicios pdf/Questao_04_Sequencial_Intervalo_Posicoes.cpp" -o "AV2/exércicios pdf/q4.out" && "./AV2/exércicios pdf/q4.out"

#include <iostream>
using namespace std;

#define TAM_VETOR 8

int buscaSequencialIntervalo(int vetor[], int inicio, int fim, int valor)
{
    int indice_busca_intervalo;

    for (indice_busca_intervalo = inicio; indice_busca_intervalo <= fim; indice_busca_intervalo++)
    {
        if (vetor[indice_busca_intervalo] == valor)
        {
            return indice_busca_intervalo;
        }
        
        else if(indice_busca_intervalo == fim)
        {
            return -1;
        }
    }
    return indice_busca_intervalo;
}

int main()
{
    int vetor[TAM_VETOR] = {11, 24, 7, 36, 15, 24, 50, 3};
    int valor, inicio, fim, resultado;

    cout << "\n\t Digite o valor a ser buscado: ";
    cin >> valor;
    cout << "\n\t Digite a posição inicial do intervalo: ";
    cin >> inicio;
    cout << "\n\t Digite a posição final do intervalo: ";
    cin >> fim;

    if (inicio < 0 || fim >= TAM_VETOR || inicio > fim)
    {
        cout << "\n\t Intervalo inválido!" << endl;
    }

    else
    {
        resultado = buscaSequencialIntervalo(vetor, inicio, fim, valor);

        if (resultado != -1)
        {
            cout << "\n\t O valor " << valor << " foi encontrado na posição: " << resultado << endl;
        }

        else
        {
            cout << "\n\t O valor " << valor << " não foi encontrado no intervalo!" << endl;
        }
    }
}