// QUESTÃO 2 – Hash Duplo (Double Hashing)
//
// Na sondagem linear e na quadrática, chaves que caem na mesma posição seguem
// EXATAMENTE o mesmo caminho de tentativas (agrupamento secundário).
// No hash duplo, o tamanho do pulo depende da própria chave, usando uma
// segunda função hash:
//
//   h1(chave) = chave % 11
//   h2(chave) = 7 - (chave % 7) → nunca dá 0 (fica entre 1 e 7)
//   posicao(chave, i) = (h1 + i * h2) % 11,    i = 0, 1, 2, ...
//
// Use TAM_TABELA 11. Insira 14, 25, 36, 47 e 9. Depois faça as buscas.
//
// ex: inserir 25 → h1 = 3, h2 = 7 - 4 = 3 → 3 (ocupada) → 3 + 3 = 6 (livre)
//
// int hash1(int chave);
// int hash2(int chave);
// bool inserir(int tabela[], int chave);                → imprime h1, h2 e cada posição tentada
// int buscar(int tabela[], int chave, int &tentativas); → posição da chave ou -1
//
// Testes:
// Inserir 14 → h1=3, h2=7 → 3 (livre)
// Inserir 25 → h1=3, h2=3 → 3 (ocupada) → 6 (livre)
// Inserir 36 → h1=3, h2=6 → 3 (ocupada) → 9 (livre)
// Inserir 47 → h1=3, h2=2 → 3 (ocupada) → 5 (livre)
// Inserir 9  → h1=9, h2=5 → 9 (ocupada) → 3 (ocupada) → 8 (livre)   (9 + 5 = 14 → 3; 9 + 10 = 19 → 8)
// Tabela → [3] 14 | [5] 47 | [6] 25 | [8] 9 | [9] 36 | resto: -
// Buscar 9  → 9 (36) → 3 (14) → 8 (9)              → achou na posição 8, 3 tentativas
// Buscar 47 → 3 (14) → 5 (47)                      → achou na posição 5, 2 tentativas
// Buscar 58 → h1=3, h2=5 → 3 (14) → 8 (9) → 2 (vazia) → não achou, 3 tentativas
//
// Pergunta: 14, 25, 36 e 47 colidiram TODOS na posição 3. Quantas tentativas
// cada um precisou? Compare com a Questão 1 (quadrática), em que todos seguiam
// o mesmo caminho 4 → 5 → 8 → 2 → 9.
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Buscas/exércicios_hash/Questao_02_Hash_Duplo.cpp" -o "AV2/Buscas/exércicios_hash/q2.out" && "./AV2/Buscas/exércicios_hash/q2.out"

#include <iostream>
using namespace std;

#define TAM_TABELA 11

int hash1(int chave) 
{
    return chave % TAM_TABELA;
}

int insertir(int tabela[], int chave) 
{
    int h1 = hash1(chave);
    int h2 = 7 - (chave % 7);
    int i = 0;
    int posicao;

    cout << "Inserindo " << chave << " → h1=" << h1 << ", h2=" << h2;

    do 
    {
        posicao = (h1 + i * h2) % TAM_TABELA;
        cout << " → " << posicao;

        if (tabela[posicao] == -1) 
        {
            tabela[posicao] = chave;
            cout << " (livre)" << endl;
            return posicao;
        } 

        else 
        {
            cout << " (ocupada)";
        }
        i++;
    } 
    while (i < TAM_TABELA);

    cout << " → Tabela cheia!" << endl;
    return -1; // Tabela cheia
}

int buscar(int tabela[], int chave, int &tentativas) 
{
    int h1 = hash1(chave);
    int h2 = 7 - (chave % 7);
    int i = 0;
    int posicao;

    tentativas = 0;

    do 
    {
        posicao = (h1 + i * h2) % TAM_TABELA;
        tentativas++;

        if (tabela[posicao] == chave) 
        {
            return posicao; // Achou a chave
        } 

        else if (tabela[posicao] == -1) 
        {
            return -1; // Não achou a chave
        }
        i++;
    } 
    while (i < TAM_TABELA);

    return -1; // Não achou a chave
}

int main() 
{
    int tabela[TAM_TABELA];

    for (int i = 0; i < TAM_TABELA; i++) 
    {
        tabela[i] = -1; // Inicializa a tabela com -1 (vazia)
    }

    // Inserir chaves
    insertir(tabela, 14);
    insertir(tabela, 25);
    insertir(tabela, 36);
    insertir(tabela, 47);
    insertir(tabela, 9);

    // Buscar chaves
    int tentativas;
    int pos;

    pos = buscar(tabela, 9, tentativas);
    if (pos != -1) 
    {
        cout << "Buscar 9 → achou na posição " << pos << ", " << tentativas << " tentativas" << endl;
    }
    else 
    {
        cout << "Buscar 9 → não achou, " << tentativas << " tentativas" << endl;
    }

    pos = buscar(tabela, 47, tentativas);
    if (pos != -1) 
    {
        cout << "Buscar 47 → achou na posição " << pos << ", " << tentativas << " tentativas" << endl;
    }
    else 
    {
        cout << "Buscar 47 → não achou, " << tentativas << " tentativas" << endl;
    }

    pos = buscar(tabela, 58, tentativas);
    if (pos != -1) 
    {
        cout << "Buscar 58 → achou na posição " << pos << ", " << tentativas << " tentativas" << endl;
    }
    else 
    {
        cout << "Buscar 58 → não achou, " << tentativas << " tentativas" << endl;
    }
    return 0;
}