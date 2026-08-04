/*
 * Crie um programa que leia e apresente os dados de 3 funcionários. Crie uma struct que
 * contenha o nome, idade, salário e a data de nascimento. O que se sabe é que a data de
 * nascimento é do tipo Data, ou seja, uma outra struct que contem os seguintes membros:
 * dia e ano, ambos do tipo inteiro; e mês do tipo string. Crie um vetor de struct para
 * registrar os dados dos 3 funcionários.
 */

#include <array>
#include <iostream>
#include <string>

constexpr int TOTAL_FUNCIONARIOS = 3;
constexpr int TOTAL_MESES = 12;

const std::array<std::string, TOTAL_MESES> meses_validos =
{
    "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
    "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
};

typedef struct Data
{
    int dia;
    std::string mes;
    int ano;
} Data;

typedef struct Funcionario
{
    std::string nome;
    int idade;
    float salario;
    Data data_nascimento;
} Funcionario;

bool mes_e_valido(const std::string &mes)
{
    for (const std::string &mes_valido : meses_validos)
    {
        if (mes == mes_valido)
        {
            return true;
        }
    }
    return false;
}

int main(void)
{
    std::array<Funcionario, TOTAL_FUNCIONARIOS> funcionarios;

    for (int indice_funcionario = 0; indice_funcionario < TOTAL_FUNCIONARIOS; indice_funcionario++)
    {
        Funcionario &funcionario = funcionarios[indice_funcionario];

        std::cout << "\n\t Digite o nome do funcionário " << indice_funcionario + 1 << ": ";
        std::getline(std::cin >> std::ws, funcionario.nome);

        std::cout << "\n\t Digite a idade do funcionário " << indice_funcionario + 1 << ": ";
        std::cin >> funcionario.idade;

        std::cout << "\n\t Digite o salário do funcionário " << indice_funcionario + 1 << ": ";
        std::cin >> funcionario.salario;

        bool dia_valido = false; // inicializa a variável de controle como falso 
        // para o loop de validação do dia
        do
        {
            std::cout << "\n\t Digite o dia de nascimento do funcionário " << indice_funcionario + 1 << ": ";
            std::cin >> funcionario.data_nascimento.dia;

            dia_valido = funcionario.data_nascimento.dia >= 1 && funcionario.data_nascimento.dia <= 31;

            if (!dia_valido)
            {
                std::cout << "\n\t Dia inválido! Digite um valor entre 1 e 31.\n";
            }
        }
        
        while (!dia_valido);

        bool mes_valido = false;

        do
        {
            std::cout << "\n\t Digite o mês de nascimento do funcionário " << indice_funcionario + 1 << ": ";
            std::getline(std::cin >> std::ws, funcionario.data_nascimento.mes);

            mes_valido = mes_e_valido(funcionario.data_nascimento.mes);

            if (!mes_valido)
            {
                std::cout << "\n\t Mês inválido! Digite um mês entre Janeiro e Dezembro.\n";
            }
        }

        while (!mes_valido);

        std::cout << "\n\t Digite o ano de nascimento do funcionário " << indice_funcionario + 1 << ": ";
        std::cin >> funcionario.data_nascimento.ano;
    }

    std::cout << "\n\t Dados dos funcionários: \n";

    for (const Funcionario &funcionario : funcionarios)
    {
        std::cout << "\n\t Nome: " << funcionario.nome << "\n";
        std::cout << "\n\t Idade: " << funcionario.idade << "\n";
        std::cout << "\n\t Salário: " << funcionario.salario << "\n";
        std::cout << "\n\t Data de Nascimento: " << funcionario.data_nascimento.dia << "/"
                   << funcionario.data_nascimento.mes << "/" << funcionario.data_nascimento.ano << "\n";
    }
    return 0;
}