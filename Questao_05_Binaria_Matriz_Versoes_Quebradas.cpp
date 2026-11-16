// QUESTÃO 5 – Busca Binária: Versões Quebradas (Matriz de Builds)
//
// Um servidor de integração contínua guarda o resultado das builds de vários
// projetos. Cada LINHA é um projeto e cada COLUNA é uma versão (0 a 7):
//   0 → a build passou
//   1 → a build quebrou
// Quando um projeto quebra, ninguém conserta: ele continua quebrado em todas as
// versões seguintes. Ou seja, toda linha tem a forma 0 0 0 ... 1 1 1.
//
//              v0  v1  v2  v3  v4  v5  v6  v7
// projeto 0     0   0   0   0   0   1   1   1
// projeto 1     0   0   1   1   1   1   1   1
// projeto 2     0   0   0   0   0   0   0   0
// projeto 3     0   0   0   0   0   0   0   1
// projeto 4     1   1   1   1   1   1   1   1
//
// a) int primeiraVersaoQuebrada(int matriz[PROJETOS][VERSOES], int projeto, int &passos);
//    → busca binária na MATRIZ INTEIRA, "fingindo" que é um vetor de índices
//      0 a PROJETOS * VERSOES - 1 (igual à Questão 3). Para cada meio:
//        linha  = meio / VERSOES
//        coluna = meio % VERSOES
//    → se a linha do meio vem ANTES do projeto: vai para a DIREITA
//      se a linha do meio vem DEPOIS do projeto: vai para a ESQUERDA
//      se é a linha do projeto e caiu num 1: guarda a coluna e continua
//        procurando à ESQUERDA (pode haver um 1 antes)
//      se é a linha do projeto e caiu num 0: vai para a DIREITA
//    → retorna a coluna do primeiro 1, ou -1 se o projeto nunca quebrou
//    → `passos` devolve quantas iterações do while foram feitas
//
// b) int projetoQueQuebrouPrimeiro(int matriz[PROJETOS][VERSOES]);
//    → usa a função do item a) em cada linha
//    → retorna o projeto com a MENOR primeira versão quebrada
//      (ignore os projetos que nunca quebraram; empate → o de menor índice)
//
// c) No main:
//    → mostre uma tabela: projeto | primeira versão quebrada | quantas versões
//      quebradas (VERSOES - primeira, ou 0) | passos
//    → mostre qual projeto quebrou primeiro
//    → leia uma versão do teclado e liste quais projetos estavam quebrados nela
//      (dica: não precisa buscar de novo, use as "primeiras" que você já calculou)
//
// Use #define PROJETOS 5 e #define VERSOES 8.
//
// Testes (item a):
// projeto 0 → primeira 5,  3 quebradas, 5 passos
//   inicio=0 fim=39 meio=19 → [2][3] → linha 2 depois do projeto 0 → esquerda
//   inicio=0 fim=18 meio=9  → [1][1] → linha 1 depois do projeto 0 → esquerda
//   inicio=0 fim=8  meio=4  → [0][4] = 0 → vai para a direita
//   inicio=5 fim=8  meio=6  → [0][6] = 1 → guarda 6, vai para a esquerda
//   inicio=5 fim=5  meio=5  → [0][5] = 1 → guarda 5, vai para a esquerda → acabou, resposta 5
// projeto 1 → primeira 2,  6 quebradas, 5 passos
// projeto 2 → primeira -1, 0 quebradas, 6 passos (nunca quebrou)
// projeto 3 → primeira 7,  1 quebrada,  5 passos
// projeto 4 → primeira 0,  8 quebradas, 5 passos
//
// Testes (item b): projeto 4 (quebrou na versão 0)
//
// Testes (item c):
// versão 0 → projetos 4          (1 projeto)
// versão 2 → projetos 1, 4       (2 projetos)
// versão 4 → projetos 1, 4       (2 projetos)
// versão 5 → projetos 0, 1, 4    (3 projetos)
// versão 7 → projetos 0, 1, 3, 4 (4 projetos)
//
// Pergunta: no pior caso, quantas comparações uma busca SEQUENCIAL faria por
// linha? E a binária na matriz inteira? E se cada projeto tivesse 1024 versões?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "Questao_05_Binaria_Matriz_Versoes_Quebradas.cpp" -o q5.out && ./q5.out

#include <iostream>
using namespace std;

#define PROJETOS 5
#define VERSOES 8

int primeiraVersaoQuebrada(int matriz[PROJETOS][VERSOES], int projeto, int &passos)
{
    int inicio = 0;
    int final = (PROJETOS * VERSOES) - 1;
    int meio;
    int linha, coluna;

    int posicao = -1;
    passos = 0;

    while (inicio <= final)
    {
        meio = (inicio + final) / 2;
        passos++;

        linha = meio / VERSOES;
        coluna = meio % VERSOES;

        cout << "inicio=" << inicio << " fim=" << final << " meio=" << meio
             << " → [" << linha << "][" << coluna << "] = " << matriz[linha][coluna] << endl;

        if (linha < projeto)
        {
            inicio = meio + 1;
        }

        else if (linha > projeto)
        {
            final = meio - 1;
        }

        else if (matriz[linha][coluna] == 1)
        {
            posicao = coluna;
            final = meio - 1;
        }

        else
        {
            inicio = meio + 1;
        }
    }
    return posicao;
}

int projetoQueQuebrouPrimeiro(int matriz[PROJETOS][VERSOES])
{
    int projetoPrimeiro = -1;
    int menorVersao = VERSOES;
    int passos;

    for (int p = 0; p < PROJETOS; p++)
    {
        int primeira = primeiraVersaoQuebrada(matriz, p, passos);

        if (primeira != -1 && primeira < menorVersao)
        {
            menorVersao = primeira;
            projetoPrimeiro = p;
        }
    }
    return projetoPrimeiro;
}

int main()
{
    int matriz[PROJETOS][VERSOES] =
    {
        {0, 0, 0, 0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };

    int primeiras[PROJETOS];
    int passos[PROJETOS];

    for (int p = 0; p < PROJETOS; p++)
    {
        cout << "--- projeto " << p << " ---" << endl;
        primeiras[p] = primeiraVersaoQuebrada(matriz, p, passos[p]);
    }

    cout << endl << "projeto | primeira | quebradas | passos" << endl;
    for (int p = 0; p < PROJETOS; p++)
    {
        int quebradas = (primeiras[p] == -1) ? 0 : VERSOES - primeiras[p];

        cout << "   " << p << "    |    " << primeiras[p]
             << (primeiras[p] == -1 ? "    |     " : "     |     ") << quebradas
             << "     |   " << passos[p] << endl;
    }

    cout << endl << "--- item b ---" << endl;
    int primeiro = projetoQueQuebrouPrimeiro(matriz);

    if (primeiro == -1)
    {
        cout << "Nenhum projeto quebrou." << endl;
    }

    else
    {
        cout << "Projeto que quebrou primeiro: " << primeiro
             << " (versão " << primeiras[primeiro] << ")" << endl;
    }

    int versao;
    cout << endl << "Digite uma versão (0 a " << VERSOES - 1 << "): ";
    cin >> versao;

    if (versao < 0 || versao >= VERSOES)
    {
        cout << "Versão inválida." << endl;
        return 0;
    }

    int quantidade = 0;
    cout << "Projetos quebrados na versão " << versao << ": ";

    for (int p = 0; p < PROJETOS; p++)
    {
        if (primeiras[p] != -1 && primeiras[p] <= versao)
        {
            if (quantidade > 0)
            {
                cout << ", ";
            }
            
            cout << p;
            quantidade++;
        }
    }

    if (quantidade == 0)
    {
        cout << "nenhum";
    }
    cout << " (" << quantidade << " projeto" << (quantidade == 1 ? "" : "s") << ")" << endl;

    return 0;
}