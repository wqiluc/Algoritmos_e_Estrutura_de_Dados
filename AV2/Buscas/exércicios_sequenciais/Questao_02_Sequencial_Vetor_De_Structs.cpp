// QUESTÃO 2 – Busca Sequencial: Vetor de Structs (cadastro de alunos)
//
// Monte um cadastro de alunos num vetor de structs e implemente duas buscas
// sequenciais: uma por matrícula (int) e outra por nome (string).
//
// struct Aluno
// {
//     int matricula;
//     string nome;
//     double nota;
// };
//
// Índice  Matrícula   Nome      Nota
// 0       2031        Marina    8.5
// 1       1987        Pedro     6.5
// 2       2104        Bruna     9.2
// 3       1850        Rafael    4.7
// 4       2215        Sofia     7.8
//
// int buscarPorMatricula(Aluno alunos[], int tamanho_vetor, int matricula);
// int buscarPorNome(Aluno alunos[], int tamanho_vetor, string nome);
// → as duas retornam o ÍNDICE do aluno ou -1
//
// No main, mostre um menu simples: 1 - buscar por matrícula | 2 - buscar por nome.
// Se achar, imprima matrícula, nome e nota do aluno. Se não, "Aluno não encontrado."
//
// Testes:
// matrícula 2104 → índice 2: Bruna, nota 9.2
// matrícula 2031 → índice 0: Marina, nota 8.5
// matrícula 9999 → Aluno não encontrado.
// nome Rafael    → índice 3: matrícula 1850, nota 4.7
// nome Sofia     → índice 4: matrícula 2215, nota 7.8
// nome rafael    → Aluno não encontrado. (a comparação de string diferencia maiúscula de minúscula!)
//
// Pergunta: a busca por matrícula poderia ser binária? O que precisaria mudar no vetor?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Buscas/exércicios_sequenciais/Questao_02_Sequencial_Vetor_De_Structs.cpp" -o "AV2/Buscas/exércicios_sequenciais/q2.out" && "./AV2/Buscas/exércicios_sequenciais/q2.out"

#include <iostream>
#include <string>
using namespace std;

#define TAMANHO_VETOR 5

typedef struct Aluno
{
    int matricula;
    string nome;
    double nota;
} Aluno;

int buscarPorMatricula(Aluno alunos[], int tamanho_vetor, int matricula)
{
    int indice_matricula;

    for (indice_matricula = 0; indice_matricula < tamanho_vetor; indice_matricula++)
    {
        if (alunos[indice_matricula].matricula == matricula)
        {
            return indice_matricula;
        }
    }
    return -1;
}

int buscarPorNome(Aluno alunos[], int tamanho_vetor, string nome)
{
    int indice_nome;

    for (indice_nome = 0; indice_nome < tamanho_vetor; indice_nome++)
    {
        if (alunos[indice_nome].nome == nome)
        {
            return indice_nome;
        }
    }
    return -1;
}

int main()
{
    Aluno vetor_alunos[TAMANHO_VETOR] = 
    {
        {2031, "Marina", 8.5},
        {1987, "Pedro", 6.5},
        {2104, "Bruna", 9.2},
        {1850, "Rafael", 4.7},
        {2215, "Sofia", 7.8}
    };
    int matricula, indice;
    string nome;

    cout << "\n\t Digite a matrícula do aluno: ";
    cin >> matricula;
    cin.ignore(); // Limpa o buffer do teclado

    cout << "\n\t Digite o nome do aluno: ";
    getline(cin, nome);

    matricula = buscarPorMatricula(vetor_alunos, TAMANHO_VETOR, matricula);
    indice = buscarPorNome(vetor_alunos, TAMANHO_VETOR, nome);

    if (matricula != -1)
    {
        cout << "\n\t Aluno encontrado: " << endl;
        cout << "\n\t Matrícula: " << vetor_alunos[matricula].matricula << endl;
        cout << "\n\t Nome: " << vetor_alunos[matricula].nome << endl;
        cout << "\n\t Nota: " << vetor_alunos[matricula].nota << endl;
    }

    else
    {
        cout << "\n\t Aluno não encontrado." << endl;
    }

    if (indice != -1)
    {
        cout << "\n\t Aluno encontrado: " << endl;
        cout << "\n\t Matrícula: " << vetor_alunos[indice].matricula << endl;
        cout << "\n\t Nome: " << vetor_alunos[indice].nome << endl;
        cout << "\n\t Nota: " << vetor_alunos[indice].nota << endl;
    }

    else
    {
        cout << "\n\t Aluno não encontrado." << endl;
    }
    return 0;
}