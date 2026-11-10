// QUESTÃO 7 – Hash sem tratamento de colisão (módulo 10)
//
// Insira os valores numa tabela hash de tamanho 10 usando a função
// h(chave) = chave % 10, SEM tratamento de colisão.

// ex: {15, 25, 35, 45, 55};

// int funcaoHash(int chave);                → chave % 10
// bool inserir(int tabela[], int chave);    → false se a posição já estiver ocupada
// int buscar(int tabela[], int chave);      → posição da chave (ou -1)

// Obs.: TODOS esses valores terminam em 5, então chave % 10 = 5 pra todos.
// Sem tratamento de colisão, só o primeiro (15) entra; os outros caem na
// posição 5, que já está ocupada → colisão. As questões 8 e 9 resolvem isso.

// Testes:
// Inserir 15 → 15 % 10 = 5 → inserido na posição 5
// Inserir 25 → 25 % 10 = 5 → COLISÃO (posição 5 já tem o 15)
// Inserir 35 → 35 % 10 = 5 → COLISÃO (posição 5 já tem o 15)
// Inserir 45 → 45 % 10 = 5 → COLISÃO (posição 5 já tem o 15)
// Inserir 55 → 55 % 10 = 5 → COLISÃO (posição 5 já tem o 15)
// Tabela → só [5] = 15, o resto vazio
// Buscar 15 → posição 5 | Buscar 25, 35, 45, 55 → -1

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_07_Hash_Sem_Colisao.cpp -o q7.out && ./q7.out

#include <iostream>
using namespace std;

#define TAM_TABELA 10
#define TAM_VETOR 5
#define VAZIO -1

int funcaoHash(int chave)
{
    return chave % TAM_TABELA;
}

void inicializarTabela(int tabela[])
{
    for (int indice_tabela = 0; indice_tabela < TAM_TABELA; indice_tabela++)
    {
        tabela[indice_tabela] = VAZIO;
    }
}

bool inserir(int tabela[], int chave)
{
    int posicao = funcaoHash(chave);

    cout << "\n\t Inserir " << chave << " → " << chave << " % " << TAM_TABELA << " = " << posicao;

    if (tabela[posicao] == VAZIO)
    {
        tabela[posicao] = chave;
        cout << " → inserido na posição " << posicao;
        return true;
    }

    cout << " → COLISÃO (posição " << posicao << " já tem o " << tabela[posicao] << ")";
    return false;
}

int buscar(int tabela[], int chave)
{
    int posicao = funcaoHash(chave);

    if (tabela[posicao] == chave)
    {
        return posicao;
    }
    return -1;
}

void imprimirTabela(int tabela[])
{
    for (int indice_tabela = 0; indice_tabela < TAM_TABELA; indice_tabela++)
    {
        cout << "\n\t [" << indice_tabela << "] ";

        if (tabela[indice_tabela] == VAZIO)
        {
            cout << "-";
        }

        else
        {
            cout << tabela[indice_tabela];
        }
    }
    cout << endl;
}

int main()
{
    int tabela[TAM_TABELA];
    int valores[TAM_VETOR] = {15, 25, 35, 45, 55};

    inicializarTabela(tabela);

    for (int indice_vetor = 0; indice_vetor < TAM_VETOR; indice_vetor++)
    {
        inserir(tabela, valores[indice_vetor]);
    }
    cout << endl;

    cout << "\n\t Tabela hash:";
    imprimirTabela(tabela);

    for (int indice_vetor = 0; indice_vetor < TAM_VETOR; indice_vetor++)
    {
        cout << "\n\t Buscar " << valores[indice_vetor] << " → " << buscar(tabela, valores[indice_vetor]);
    }
    cout << endl;

    return 0;
}
