// QUESTÃO 1 – Hash com Sondagem Quadrática
//
// Na sondagem linear, as colisões formam "blocos" de posições ocupadas em
// sequência (agrupamento primário), e cada nova colisão aumenta o bloco.
// A sondagem quadrática espalha as tentativas, pulando 1, 4, 9, 16... casas
// a partir da posição original:
//
//   posicao(chave, i) = (chave % TAM_TABELA + i * i) % TAM_TABELA,   i = 0, 1, 2, ...
//
// Use TAM_TABELA 11 (tamanho primo ajuda a quadrática a visitar mais posições).
// Insira 15, 26, 37, 4 e 48 (TODOS dão chave % 11 = 4!). Depois faça as buscas.
//
// ex: inserir 37 → 4 (ocupada) → 4 + 1 = 5 (ocupada) → 4 + 4 = 8 (livre)
//
// bool inserir(int tabela[], int chave);
// → imprime cada posição tentada; retorna false se não conseguir inserir
// int buscar(int tabela[], int chave, int &tentativas);
// → posição da chave ou -1 (para ao encontrar uma posição VAZIA)
// → limite as tentativas a TAM_TABELA nas duas funções
//
// Testes:
// Inserir 15 → 4 (livre)
// Inserir 26 → 4 (ocupada) → 5 (livre)
// Inserir 37 → 4 → 5 (ocupadas) → 8 (livre)
// Inserir 4  → 4 → 5 → 8 (ocupadas) → 2 (livre)       (4 + 9 = 13 → 13 % 11 = 2)
// Inserir 48 → 4 → 5 → 8 → 2 (ocupadas) → 9 (livre)   (4 + 16 = 20 → 20 % 11 = 9)
// Tabela → [2] 4 | [4] 15 | [5] 26 | [8] 37 | [9] 48 | resto: -
// Buscar 4  → 4 (15) → 5 (26) → 8 (37) → 2 (4)  → achou na posição 2, 4 tentativas
// Buscar 26 → 4 (15) → 5 (26)                   → achou na posição 5, 2 tentativas
// Buscar 59 → 4 → 5 → 8 → 2 → 9 → 7 (vazia)     → não achou, 6 tentativas  (59 % 11 = 4)
//
// Pergunta: com sondagem LINEAR, essas mesmas 5 chaves ocupariam 4, 5, 6, 7 e 8.
// Por que isso é pior para as próximas chaves que caírem em 5, 6 ou 7?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Buscas/exércicios_hash/Questao_01_Hash_Sondagem_Quadratica.cpp" -o "AV2/Buscas/exércicios_hash/q1.out" && "./AV2/Buscas/exércicios_hash/q1.out"

#include <iostream>
using namespace std;

#define TAM_TABELA 11

int tabela[TAM_TABELA];

bool inserir(int tabela[], int chave) 
{
    for (int i = 0; i < TAM_TABELA; i++) 
    {
        int posicao = (chave % TAM_TABELA + i * i) % TAM_TABELA;

        cout << "Tentativa " << i + 1 << ": posição " << posicao << endl;

        if (tabela[posicao] == -1) 
        { 
            tabela[posicao] = chave;
            return true;
        }
    }
    return false;
}

int buscar(int tabela[], int chave, int &tentativas) 
{
    tentativas = 0;

    for (int i = 0; i < TAM_TABELA; i++) 
    {
        tentativas++;

        int posicao = (chave % TAM_TABELA + i * i) % TAM_TABELA;

        cout << "Tentativa " << tentativas << ": posição " << posicao << endl;

        if (tabela[posicao] == chave) 
        {
            return posicao;
        }

        if (tabela[posicao] == -1) 
        {
            return -1; 
        }
    }
    return -1;
}

int main() 
{
    int indice, tentativas;

    for (indice = 0; indice < TAM_TABELA; indice++) 
    {
        tabela[indice] = -1; 
    }

    cout << "Inserindo 15..." << endl;
    inserir(tabela, 15);

    cout << "Inserindo 26..." << endl;
    inserir(tabela, 26);

    cout << "Inserindo 37..." << endl;
    inserir(tabela, 37);

    cout << "Inserindo 4..." << endl;
    inserir(tabela, 4);

    cout << "Inserindo 48..." << endl;
    inserir(tabela, 48);

    cout << "\nBuscando 4..." << endl;
    indice = buscar(tabela, 4, tentativas);

    if (indice != -1) 
    {
        cout << "Encontrado na posição " << indice << " em " << tentativas << " tentativas." << endl;
    } 

    else 
    {
        cout << "Não encontrado em " << tentativas << " tentativas." << endl;
    }

    cout << "\nBuscando 26..." << endl;
    indice = buscar(tabela, 26, tentativas);

    if (indice != -1) 
    {
        cout << "Encontrado na posição " << indice << " em " << tentativas << " tentativas." << endl;
    } 

    else 
    {
        cout << "Não encontrado em " << tentativas << " tentativas." << endl;
    }
}