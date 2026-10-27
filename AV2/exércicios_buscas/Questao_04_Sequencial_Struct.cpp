// QUESTÃO 4 – Busca Sequencial em Vetor de Struct (💻 código + ✏️ papel)
//
// struct Aluno
// {
//     int matricula;
//     string nome;
//     float nota;
// };
//
// Aluno turma[] = 
// {
//     {1023, "Ana",   8.5},
//     {1007, "Bruno", 6.0},
//     {1051, "Carla", 9.2},
//     {1012, "Diego", 7.4},
//     {1038, "Eva",   5.8}
// };
//
// a) Implemente a busca por matrícula, retornando um PONTEIRO para o aluno
//    encontrado (ou nullptr se não existir):
//
//    Aluno* buscarPorMatricula(Aluno turma[], int tamanho, int matricula);✅
//
// b) Implemente a busca por nome, retornando o ÍNDICE (ou -1):
//
//    int buscarPorNome(Aluno turma[], int tamanho, string nome);✅
//
// c) No main, leia uma matrícula e mostre nome e nota do aluno, ou
//    "Aluno não encontrado". Depois, faça o mesmo lendo um nome.✅
//
// Testes:
// buscarPorMatricula(turma, 5, 1051) → Carla, 9.2
// buscarPorMatricula(turma, 5, 1007) → Bruno, 6.0
// buscarPorMatricula(turma, 5, 9999) → nullptr
// buscarPorNome(turma, 5, "Diego"). → 3
// buscarPorNome(turma, 5, "Zeca") → -1
//
// d) Dá para usar busca binária por matrícula nesse vetor? O que precisaria mudar?
//
// ✏️ Sua resposta:
// d) Sim, mas só se o vetor estiver ORDENADO por matrícula. Do jeito que está
//    (1023, 1007, 1051, 1012, 1038) não está, então a busca binária descartaria
//    a metade errada e poderia não achar o aluno. Precisaria ordenar a turma por
//    matrícula antes (1007, 1012, 1023, 1038, 1051), ou já inserir ordenado, e
//    comparar turma[meio].matricula com a matrícula buscada. A busca cai de O(n)
//    para O(log n), mas ordenar custa O(n log n), então compensa quando há muitas buscas.
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 AV2/exércicios_buscas/Questao_04_Sequencial_Struct.cpp -o AV2/exércicios_buscas/q4.out && ./AV2/exércicios_buscas/q4.out

#include <iostream>
#include <iomanip>
using namespace std;

#define TAM_TURMA 5

struct Aluno
{
    int matricula;
    char nome[50];
    float nota;
};

Aluno turma[] = 
{
    {1023, "Ana",   8.5},
    {1007, "Bruno", 6.0},
    {1051, "Carla", 9.2},
    {1012, "Diego", 7.4},
    {1038, "Eva",   5.8}
};

// a)
Aluno* buscarPorMatricula(Aluno turma[], int tamanho, int matricula)
{
    int indice_aluno;

    for (indice_aluno = 0; indice_aluno < tamanho; indice_aluno++)
    {
        if (turma[indice_aluno].matricula == matricula)
        {
            return &turma[indice_aluno];
        }
    }
    return nullptr;
}

// b)
int buscarPorNome(Aluno turma[], int tamanho, string nome)
{
    int indice_aluno;

    for (indice_aluno = 0; indice_aluno < tamanho; indice_aluno++)
    {
        if (nome == turma[indice_aluno].nome)
        {
            return indice_aluno;
        }
    }
    return -1;
}

// c)
int main()
{
    int matricula;
    string nome;

    cout << fixed << setprecision(1);

    cout << "\n\t Digite a matrícula do aluno: ";
    cin >> matricula;

    Aluno* aluno = buscarPorMatricula(turma, TAM_TURMA, matricula);

    if (aluno != nullptr)
    {
        cout << "\n Nome: " << aluno->nome << " | Nota: " << aluno->nota << endl;
    }

    else
    {
        cout << "\n Aluno não encontrado." << endl;
    }

    cout << "\n\t Digite o nome do aluno: ";
    cin >> nome;

    int indice_aluno = buscarPorNome(turma, TAM_TURMA, nome);

    if (indice_aluno != -1)
    {
        cout << "\n Nome: " << turma[indice_aluno].nome << " | Nota: " << turma[indice_aluno].nota << endl;
    }

    else
    {
        cout << "\n Aluno não encontrado." << endl;
    }

    return 0;
}