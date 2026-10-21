// QUESTÃO 2 – Busca Binária (✏️ papel)
//
// Valor   2   5   8   12  16  23  38  56  72  91
// Índice  0   1   2   3   4   5   6   7   8   9
//
// Faça a tabela (inicio, fim, meio, vetor[meio], decisão) para:
// a) buscar 23
// b) buscar 91
// c) buscar 7
// d) Qual o número MÁXIMO de acessos para um vetor de 10 elementos?
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// a) buscar 23
//    inicio | fim | meio | vetor[meio] | decisão
//    resposta: 5
// b) buscar 91
//    inicio | fim | meio | vetor[meio] | decisão
//    resposta: 9
// c) buscar 7
//    inicio | fim | meio | vetor[meio] | decisão
//    resposta: -1
// d) máximo = 4 acessos
//
// Compilar e rodar:
// g++ -std=c++17 Questao_02_Busca_Binaria.cpp -o q2.out && ./q2.out

#include <iostream>
using namespace std;

int buscaBinaria(int vetor[], int tamanho_vetor, int valor)
{
    int inicio = 0;
    int final = tamanho_vetor - 1;
    int meio;

    while (inicio <= final)
    {
        meio = (inicio + final) / 2;
        
        if(vetor[meio] == valor)
        {
            return meio;
        }
        else if(vetor[meio] < valor)
        {
            inicio = meio + 1;
        }
        else
        {
            final = meio - 1;
        }
    }
    return -1;
}

int main()
{
    int vetor[10] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int tamanho_vetor = sizeof(vetor) / sizeof(vetor[0]);
    int valor;

    cout << "\n\t Digite um valor a ser buscado: ";
    cin >> valor;

    int resultado = buscaBinaria(vetor, tamanho_vetor, valor);

    if (resultado != -1)
    {
        cout << "\n\t Valor encontrado no índice: " << resultado << endl;
    }
    else
    {
        cout << "\n\t Valor não encontrado no vetor." << endl;
    }

    return 0;
}
   