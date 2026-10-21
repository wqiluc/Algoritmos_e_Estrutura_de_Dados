// QUESTÃO 1 – Busca Sequencial (✏️ papel)
//
// Valor   30  15  20  55  8   10
// Índice  0   1   2   3   4   5
//
// a) Quantas comparações a busca sequencial faz para achar o 55? E o 10?
//    E o 99?
// b) Qual o número médio de acessos para chaves que estão no vetor?
// c) Dá para usar busca binária nesse vetor? Rode a busca binária
//    procurando o 8 e veja o que acontece.
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// a) 55: 4 comparações | 10: 6 comparações | 99: 6 comparações
// b) média = 3.5
    // c) Não. Porque o vetor não está ordenado. 
    // A busca binária requer que o vetor esteja 
    // em ordem crescente ou decrescente para funcionar corretamente. 
    // Se tentarmos buscar o 8 usando busca binária, 
    // o resultado será incorreto, 
    // pois a lógica da busca binária depende da ordenação dos elementos 
    // para decidir qual metade do vetor continuar a busca.
//
// Compilar e rodar:
// g++ -std=c++17 Questao_01_Busca_Sequencial.cpp -o q1.out && ./q1.out

#include <iostream>
using namespace std;

int buscaSequencial(int vetor[], int tamanho_vetor, int valor)
{
    int indice_vetor;

    for (indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        if (vetor[indice_vetor] == valor)
        {
            return indice_vetor;
        }
    }
    return -1;
}

int main()
{
    int vetor[] = {30, 15, 20, 55, 8, 10};
    int tamanho_vetor = sizeof(vetor) / sizeof(vetor[0]);
    int valor;

    cout << "Digite o valor a ser buscado: ";
    cin >> valor;

    int resultado = buscaSequencial(vetor, tamanho_vetor, valor);

    if (resultado != -1)
    {
        cout << "Valor encontrado no índice: " << resultado << endl;
    }
    else
    {
        cout << "Valor não encontrado." << endl;
    }

    return 0;
}