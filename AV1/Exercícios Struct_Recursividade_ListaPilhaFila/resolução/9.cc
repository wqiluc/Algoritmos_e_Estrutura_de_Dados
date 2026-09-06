#include <iostream>
using namespace std;

typedef struct Paciente
{
    char nome_paciente[50];
    int idade_paciente;
    char diagnostico_paciente[100];
} Paciente;

void cadastrarPaciente(Paciente* paciente, int indice_paciente)
{
    cout << "\nDigite o nome do " << indice_paciente + 1 << "º Paciente: ";
    cin >> paciente->nome_paciente;

    cout << "Digite a idade do " << indice_paciente + 1 << "º Paciente: ";
    cin >> paciente->idade_paciente;

    cout << "Digite o diagnóstico do " << indice_paciente + 1 << "º Paciente: ";
    cin >> paciente->diagnostico_paciente;
}

void exibirPaciente(Paciente* paciente)
{
    cout << "\nNome: " << paciente->nome_paciente << endl;
    cout << "Idade: " << paciente->idade_paciente << endl;
    cout << "Diagnóstico: " << paciente->diagnostico_paciente << endl;
}

int main()
{
    int quantidade_pacientes;

    cout << "Digite a quantidade de pacientes: ";
    cin >> quantidade_pacientes;

    Paciente* pacientes = new Paciente[quantidade_pacientes];

    for (int indice_paciente = 0; indice_paciente < quantidade_pacientes; indice_paciente++)
    {
        cadastrarPaciente(&pacientes[indice_paciente], indice_paciente);
    }

    cout << "\nPacientes acima de 60 anos:" << endl;

    for (int indice_paciente = 0; indice_paciente < quantidade_pacientes; indice_paciente++)
    {
        if (pacientes[indice_paciente].idade_paciente > 60)
        {
            exibirPaciente(&pacientes[indice_paciente]);
        }
    }

    return 0;
}