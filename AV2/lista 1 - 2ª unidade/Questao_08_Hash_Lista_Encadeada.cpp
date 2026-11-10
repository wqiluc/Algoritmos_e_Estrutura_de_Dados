// QUESTÃO 8 – Hash com colisão tratada por lista encadeada
//
// Insira 12, 22, 32 e 42 numa tabela hash de tamanho 10 (chave % 10).
// Cada posição da tabela guarda uma lista encadeada: quando dá colisão,
// o valor novo vai pro fim da lista daquela posição.
// Depois, busque o 22.

// ex: inserir {12, 22, 32, 42}; buscar 22

// void inserir(No* tabela[], int chave);   → coloca no fim da lista de chave % 10
// int buscar(No* tabela[], int chave);     → retorna em qual nó da lista achou (ou -1)

// Testes:
// Inserir 12, 22, 32, 42 → todos dão chave % 10 = 2
// Tabela → [2] → 12 → 22 → 32 → 42 → NULL (o resto vazio)
// Buscar 22 → posição 2 da tabela → olhou 12, olhou 22 → achou no 2º nó

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_08_Hash_Lista_Encadeada.cpp -o q8.out && ./q8.out

#include <iostream>
using namespace std;

#define TAM_TABELA 10
#define TAM_VETOR 4
#define VALOR_BUSCADO 22

struct No
{
    int valor;
    No* proximo;
};

int funcaoHash(int chave)
{
    return chave % TAM_TABELA;
}

void inicializarTabela(No* tabela[])
{
    for (int indice_tabela = 0; indice_tabela < TAM_TABELA; indice_tabela++)
    {
        tabela[indice_tabela] = nullptr;
    }
}

void inserir(No* tabela[], int chave)
{
    int posicao = funcaoHash(chave);

    No* novo_no = new No;
    novo_no->valor = chave;
    novo_no->proximo = nullptr;

    cout << "\n\t Inserir " << chave << " → " << chave << " % " << TAM_TABELA << " = " << posicao;

    if (tabela[posicao] == nullptr) // posição vazia: vira o primeiro nó
    {
        tabela[posicao] = novo_no;
    }

    else // colisão: anda até o último nó e pendura o novo no fim
    {
        No* atual = tabela[posicao];

        while (atual->proximo != nullptr)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo_no;

        cout << " (colisão → vai pro fim da lista)";
    }
}

int buscar(No* tabela[], int chave)
{
    int posicao = funcaoHash(chave);
    No* atual = tabela[posicao];
    int numero_no = 1;

    cout << "\n\t Buscar " << chave << " → posição " << posicao << " da tabela →";

    while (atual != nullptr)
    {
        cout << " olhou " << atual->valor;

        if (atual->valor == chave)
        {
            cout << " → achou!" << endl;
            return numero_no;
        }

        cout << ",";
        atual = atual->proximo;
        numero_no++;
    }

    cout << " fim da lista → não achou" << endl;
    return -1;
}

void imprimirTabela(No* tabela[])
{
    for (int indice_tabela = 0; indice_tabela < TAM_TABELA; indice_tabela++)
    {
        cout << "\n\t [" << indice_tabela << "]";

        for (No* atual = tabela[indice_tabela]; atual != nullptr; atual = atual->proximo)
        {
            cout << " → " << atual->valor;
        }
        cout << " → NULL";
    }
    cout << endl;
}

void liberarTabela(No* tabela[])
{
    for (int indice_tabela = 0; indice_tabela < TAM_TABELA; indice_tabela++)
    {
        No* atual = tabela[indice_tabela];

        while (atual != nullptr)
        {
            No* proximo = atual->proximo;
            delete atual;
            atual = proximo;
        }
        tabela[indice_tabela] = nullptr;
    }
}

int main()
{
    No* tabela[TAM_TABELA];
    int valores[TAM_VETOR] = {12, 22, 32, 42};

    inicializarTabela(tabela);

    for (int indice_vetor = 0; indice_vetor < TAM_VETOR; indice_vetor++)
    {
        inserir(tabela, valores[indice_vetor]);
    }
    cout << endl;

    cout << "\n\t Tabela hash:";
    imprimirTabela(tabela);

    int numero_no = buscar(tabela, VALOR_BUSCADO);

    if (numero_no == -1)
    {
        cout << "\n\t O valor " << VALOR_BUSCADO << " não foi encontrado." << endl;
    }

    else
    {
        cout << "\n\t O valor " << VALOR_BUSCADO << " está na posição " << funcaoHash(VALOR_BUSCADO)
             << " da tabela, no " << numero_no << "º nó da lista." << endl;
    }

    liberarTabela(tabela);

    return 0;
}
