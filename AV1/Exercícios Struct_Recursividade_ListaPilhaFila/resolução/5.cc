#include <iostream>
#include <string.h>
using namespace std;

typedef struct Funcionario 
{
    char nome_funcionario[50];
    char cargo_funcionario[50];
    float salario_funcionario;
} Funcionario;

void cadastrarFuncionarios(Funcionario* funcionario, int indice_funcionario)
{
    cout << "\n Digite o nome do " << indice_funcionario+1 << "º Funcionário: ";
    cin >> funcionario->nome_funcionario;

    cout << "Digite o cargo do " << indice_funcionario+1 << "º Funcionário: ";
    cin >> funcionario->cargo_funcionario;

    cout << "Digite o salário do " << indice_funcionario+1 << "º Funcionário: ";
    cin >> funcionario->salario_funcionario;
}
void exibirFuncionarios(Funcionario* funcionario, int indice_funcionario)
{
    cout << "\nFuncionário " << indice_funcionario+1 << ":" << endl;
    cout << "Nome: " << funcionario->nome_funcionario << endl;
    cout << "Cargo: " << funcionario->cargo_funcionario << endl;
    cout << "Salário: R$ " << funcionario->salario_funcionario << endl;
}

int main()
{
    int quantidade_funcionarios;

    cout << "Digite a quantidade de funcionários: ";
    cin >> quantidade_funcionarios;

    Funcionario* funcionario = new Funcionario[quantidade_funcionarios];

    for (int indice_funcionario = 0; indice_funcionario < quantidade_funcionarios; indice_funcionario++)
    {
        cadastrarFuncionarios(&funcionario[indice_funcionario], indice_funcionario);
    }

    for (int indice_funcionario = 0; indice_funcionario < quantidade_funcionarios; indice_funcionario++)
    {
        exibirFuncionarios(&funcionario[indice_funcionario], indice_funcionario);
    }

    return 0;
}