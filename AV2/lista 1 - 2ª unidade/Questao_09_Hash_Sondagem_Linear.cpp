// QUESTÃO 9 – Hash com sondagem linear
//
// Insira 17, 27, 37, 47 e 57 numa tabela hash de tamanho 10 (chave % 10).
// Se a posição estiver ocupada, tenta a próxima (posição + 1), dando a
// volta pro início quando passar do fim. Depois, busque o 37.

// ex: inserir {17, 27, 37, 47, 57}; buscar 37

// bool inserir(int tabela[], int chave);              → anda até achar uma posição vazia
// int buscar(int tabela[], int chave, int &tentativas); → posição da chave (ou -1)

// Testes:
// Inserir 17 → 7 (livre)
// Inserir 27 → 7 (ocupada) → 8 (livre)
// Inserir 37 → 7 (ocupada) → 8 (ocupada) → 9 (livre)
// Inserir 47 → 7 → 8 → 9 (ocupadas) → 0 (livre, deu a volta)
// Inserir 57 → 7 → 8 → 9 → 0 (ocupadas) → 1 (livre)
// Tabela → [0] 47 | [1] 57 | [2..6] - | [7] 17 | [8] 27 | [9] 37
// Buscar 37 → 7 (17) → 8 (27) → 9 (37) → achou na posição 9, 3 tentativas

// Compilar e rodar (com o terminal aberto dentro desta pasta):
// g++ -std=c++17 Questao_09_Hash_Sondagem_Linear.cpp -o q9.out && ./q9.out

#include <iostream>
using namespace std;

#define TAM_TABELA 10
#define TAM_VETOR 5
#define VAZIO -1
#define VALOR_BUSCADO 37

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

    cout << "\n\t Inserir " << chave << " → ";

    for (int tentativa = 0; tentativa < TAM_TABELA; tentativa++)
    {
        if (tabela[posicao] == VAZIO)
        {
            tabela[posicao] = chave;
            cout << posicao << " (livre)";
            return true;
        }

        cout << posicao << " (ocupada) → ";
        posicao = (posicao + 1) % TAM_TABELA; // sondagem linear: próxima posição, dando a volta
    }

    cout << "tabela cheia!";
    return false;
}

int buscar(int tabela[], int chave, int &tentativas)
{
    int posicao = funcaoHash(chave);
    tentativas = 0;

    cout << "\n\t Buscar " << chave << " → ";

    while (tentativas < TAM_TABELA && tabela[posicao] != VAZIO)
    {
        tentativas++;
        cout << posicao << " (" << tabela[posicao] << ")";

        if (tabela[posicao] == chave)
        {
            cout << " → achou!" << endl;
            return posicao;
        }

        cout << " → ";
        posicao = (posicao + 1) % TAM_TABELA;
    }

    cout << "não achou" << endl; // chegou numa posição vazia (ou rodou a tabela toda)
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
    int valores[TAM_VETOR] = {17, 27, 37, 47, 57};

    inicializarTabela(tabela);

    for (int indice_vetor = 0; indice_vetor < TAM_VETOR; indice_vetor++)
    {
        inserir(tabela, valores[indice_vetor]);
    }
    cout << endl;

    cout << "\n\t Tabela hash:";
    imprimirTabela(tabela);

    int tentativas;
    int posicao = buscar(tabela, VALOR_BUSCADO, tentativas);

    if (posicao == -1)
    {
        cout << "\n\t O valor " << VALOR_BUSCADO << " não foi encontrado." << endl;
    }

    else
    {
        cout << "\n\t O valor " << VALOR_BUSCADO << " está na posição " << posicao
             << " (" << tentativas << " tentativas)" << endl;
    }

    return 0;
}
