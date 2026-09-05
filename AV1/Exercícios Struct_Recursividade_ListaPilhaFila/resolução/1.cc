#include <iostream>
using namespace std;

typedef struct Pessoa 
{
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int main()
{
    Pessoa* pessoa = new Pessoa;

    cout << "Olá! Qual é o seu nome? ";
    cin >> pessoa->nome;

    cout << "Qual é a sua idade? ";
    cin >> pessoa->idade;

    cout << "Qual é a sua altura (em metros)? ";
    cin >> pessoa->altura;

    cout << "\nNome: " << pessoa->nome << endl;
    cout << "Idade: " << pessoa->idade << endl;
    cout << "Altura: " << pessoa->altura << "m" << endl;

    return 0;
}