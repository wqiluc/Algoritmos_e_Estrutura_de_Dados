// QUESTÃO 3 – A pegadinha do hash simples (✏️ papel)
//
// Usando o hash simples do slide (sem tratamento de colisão, TAM = 10),
// rode o main abaixo:
//
// a) Desenhe a tabela depois das 3 inserções.
// b) O que é impresso?
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// a) Índice:  0   1   2   3   4   5   6   7   8   9
//    Valor:   30  0   0   0   0   0   0   0   0   0
// b) O que é impresso é a tabela de hash simples, mostrando os índices de 0 a 9 e os valores correspondentes. No caso, apenas o índice 0 terá o valor 30, enquanto os outros índices terão o valor 0.
//
// Compilar e rodar:
// g++ -std=c++17 Questao_03_Hash_Simples.cpp -o q3.out && ./q3.out

#include <iostream>
using namespace std;

const int TAM = 10;

int funcaoHash(int valor)
{
    return valor % TAM;
}

int main()
{
    int tabela[TAM] = {0};
    int indice_hash;

    // Inserindo os valores 10, 20 e 30 na tabela
    tabela[funcaoHash(10)] = 10;
    tabela[funcaoHash(20)] = 20;
    tabela[funcaoHash(30)] = 30;

    // Imprimindo a tabela
    cout << "Tabela de Hash Simples:" << endl;
    for (indice_hash = 0; indice_hash < TAM; indice_hash++)
    {
        cout << "Índice " << indice_hash << ": " << tabela[indice_hash] << endl;
    }
    return 0;
}
