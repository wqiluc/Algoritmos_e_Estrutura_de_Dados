#include <iostream>
using namespace std;

typedef struct No
{
    int valor;
    No* proximo_lista;
} No;

typedef struct Lista
{
    No* inicio_lista;
} Lista;

Lista* criarLista()
{
    Lista* lista = new Lista;
    lista->inicio_lista = nullptr;
    return lista;
}

void inserirInicioLista(Lista* lista, int valor)
{
    No* novo_lista = new No;
    novo_lista->valor = valor;
    novo_lista->proximo_lista = lista->inicio_lista;
    lista->inicio_lista = novo_lista;
}

void inserirFinalLista(Lista* lista, int valor)
{
    No* novo_lista = new No;
    novo_lista->valor = valor;
    novo_lista->proximo_lista = nullptr;

    if (!lista->inicio_lista)
    {
        lista->inicio_lista = novo_lista;
        return;
    }

    No* lugar_temporario = lista->inicio_lista;

    while (lugar_temporario->proximo_lista)
    {
        lugar_temporario = lugar_temporario->proximo_lista;
    }
    lugar_temporario->proximo_lista = novo_lista;
}

void removerLista(Lista* lista, int valor)
{
    No* atual_lista = lista->inicio_lista;
    No* anterior_lista = nullptr;

    while (atual_lista && atual_lista->valor != valor)
    {
        anterior_lista = atual_lista;
        atual_lista = atual_lista->proximo_lista;
    }

    if (!atual_lista)
    {
        cout << "Valor " << valor << " não encontrado na lista. ❌" << endl;
        return;
    }

    if (!anterior_lista)
    {
        lista->inicio_lista = atual_lista->proximo_lista;
    }
    else
    {
        anterior_lista->proximo_lista = atual_lista->proximo_lista;
    }

    delete atual_lista;
    cout << "Valor " << valor << " removido. ✅" << endl;
}

void mostrarLista(Lista* lista)
{
    No* atual_lista = lista->inicio_lista;

    if (!atual_lista)
    {
        cout << "Lista vazia." << endl;
        return;
    }

    while (atual_lista)
    {
        cout << atual_lista->valor << " ";
        atual_lista = atual_lista->proximo_lista;
    }
    cout << endl;
}

void liberarLista(Lista* lista)
{
    No* atual_lista = lista->inicio_lista;

    while (atual_lista)
    {
        No* proximo = atual_lista->proximo_lista;
        delete atual_lista;
        atual_lista = proximo;
    }
    delete lista;
}

int main()
{
    Lista* lista = criarLista();
    int opcao;
    int valor;

    do
    {
        cout << "\n1 - Inserir no início\n2 - Inserir no final\n3 - Remover elemento\n4 - Exibir lista\n0 - Sair\nEscolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                cout << "Digite o valor: ";
                cin >> valor;
                inserirInicioLista(lista, valor);
                break;
            case 2:
                cout << "Digite o valor: ";
                cin >> valor;
                inserirFinalLista(lista, valor);
                break;
            case 3:
                cout << "Digite o valor a remover: ";
                cin >> valor;
                removerLista(lista, valor);
                break;
            case 4:
                mostrarLista(lista);
                break;
        }
    } while (opcao != 0);

    liberarLista(lista);
    return 0;
}
