#include <iostream>
using namespace std;

typedef struct Cliente
{
    char nome_cliente[50];
    int senha_cliente;
    Cliente* proximo_fila;
} Cliente;

typedef struct Fila
{
    Cliente* inicio_fila;
    Cliente* fim_fila;
} Fila;

Fila* criarFila()
{
    Fila* fila = new Fila;
    fila->inicio_fila = nullptr;
    fila->fim_fila = nullptr;
    return fila;
}

bool isEmpty(Fila* fila)
{
    return fila->inicio_fila == nullptr;
}

void chegarCliente(Fila* fila, int senha_cliente)
{
    Cliente* novo_cliente = new Cliente;

    cout << "Nome do cliente: ";
    cin >> novo_cliente->nome_cliente;
    novo_cliente->senha_cliente = senha_cliente;
    novo_cliente->proximo_fila = nullptr;

    if (isEmpty(fila))
    {
        fila->inicio_fila = novo_cliente;
    }
    else
    {
        fila->fim_fila->proximo_fila = novo_cliente;
    }
    fila->fim_fila = novo_cliente;

    cout << novo_cliente->nome_cliente << " entrou na fila com a senha " << senha_cliente << ". 🎟️" << endl;
}

void atenderCliente(Fila* fila)
{
    if (isEmpty(fila))
    {
        cout << "Nenhum cliente na fila. ❌" << endl;
        return;
    }

    Cliente* atendido = fila->inicio_fila;
    fila->inicio_fila = atendido->proximo_fila;

    if (!fila->inicio_fila)
    {
        fila->fim_fila = nullptr;
    }

    cout << "Atendendo " << atendido->nome_cliente << " (senha " << atendido->senha_cliente << "). ✅" << endl;
    delete atendido;
}

void mostrarFila(Fila* fila)
{
    if (isEmpty(fila))
    {
        cout << "Fila vazia." << endl;
        return;
    }

    Cliente* atual = fila->inicio_fila;
    int posicao = 1;

    while (atual)
    {
        cout << posicao++ << "º - " << atual->nome_cliente << " (senha " << atual->senha_cliente << ")" << endl;
        atual = atual->proximo_fila;
    }
}

int main()
{
    Fila* fila = criarFila();
    int opcao;
    int proxima_senha = 1;

    do
    {
        cout << "\n1 - Chegada de cliente\n2 - Atender próximo\n3 - Ver fila\n0 - Sair\nEscolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                chegarCliente(fila, proxima_senha++);
                break;
            case 2:
                atenderCliente(fila);
                break;
            case 3:
                mostrarFila(fila);
                break;
        }
    } while (opcao != 0);

    while (!isEmpty(fila))
    {
        Cliente* removido = fila->inicio_fila;
        fila->inicio_fila = removido->proximo_fila;
        delete removido;
    }
    delete fila;

    return 0;
}
