#include <iostream>
using namespace std;

typedef struct ContaBancaria
{
    char nome_titular[50];
    int numero_conta;
    float saldo_conta;
} ContaBancaria;

void depositar(ContaBancaria* conta, float valor_deposito)
{
    conta->saldo_conta += valor_deposito;
    cout << "Depósito realizado com sucesso. ✅💸" << endl;
}

void sacar(ContaBancaria* conta, float valor_saque)
{
    if (valor_saque <= conta->saldo_conta)
    {
        conta->saldo_conta -= valor_saque;
        cout << "Saque realizado com sucesso. 👋🏻💸" << endl;
    }
    else
    {
        cout << "Saldo insuficiente. ❌" << endl;
    }
}

void exibirSaldo(ContaBancaria conta)
{
    cout << "\nSaldo atual de " << conta.nome_titular << ": " << conta.saldo_conta << endl;
}

int main()
{
    ContaBancaria conta;

    cout << "Digite o nome do titular: ";
    cin >> conta.nome_titular;

    cout << "Digite o número da conta: ";
    cin >> conta.numero_conta;

    conta.saldo_conta = 0;

    int opcao;
    float valor;

    do
    {
        cout << "\n1 - Depositar\n2 - Sacar\n3 - Exibir saldo\n0 - Sair\nEscolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                cout << "Digite o valor do depósito: ";
                cin >> valor;
                depositar(&conta, valor);
                break;
            case 2:
                cout << "Digite o valor do saque: ";
                cin >> valor;
                sacar(&conta, valor);
                break;
            case 3:
                exibirSaldo(conta);
                break;
        }
    } while 
        (opcao != 0);

    return 0;
}
