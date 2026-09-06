#include <iostream>
#include <cstring>
using namespace std;

typedef struct AgendaTelefonica
{
    char nome_usuario[50];
    char telefone_usuario[15];
} AgendaTelefonica;

void adicionarContato(AgendaTelefonica* agenda_telefonica, int indice_dado)
{
    cout << "\nDigite o nome do " << indice_dado + 1 << "º Contato: ";
    cin >> agenda_telefonica->nome_usuario;

    cout << "Digite o telefone do " << indice_dado + 1 << "º Contato: ";
    cin >> agenda_telefonica->telefone_usuario;
}

void exibirContato(AgendaTelefonica* agenda_telefonica)
{
    cout << "\nNome: " << agenda_telefonica->nome_usuario << endl;
    cout << "Telefone: " << agenda_telefonica->telefone_usuario << endl;
}

int main()
{
    int quantidade_contatos;

    cout << "Digite a quantidade de contatos: ";
    cin >> quantidade_contatos;

    AgendaTelefonica* agenda = new AgendaTelefonica[quantidade_contatos];

    for (int indice_contato = 0; indice_contato < quantidade_contatos; indice_contato++)
    {
        adicionarContato(&agenda[indice_contato], indice_contato);
    }

    char nome_busca[50];
    cout << "\nDigite o nome do contato que deseja buscar: ";
    cin >> nome_busca;

    bool encontrado = false;

    for (int indice_contato = 0; indice_contato < quantidade_contatos; indice_contato++)
    {
        if (strcmp(agenda[indice_contato].nome_usuario, nome_busca) == 0)
        {
            cout << "\nContato encontrado:" << endl;
            exibirContato(&agenda[indice_contato]);
            encontrado = true;
        }
    }

    if (!encontrado)
    {
        cout << "\nContato não encontrado." << endl;
    }

    return 0;
}
