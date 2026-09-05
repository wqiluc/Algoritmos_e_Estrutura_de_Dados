#include <iostream>
using namespace std;

typedef struct Aluno 
{
    char nome[50];
    int matricula;
    float nota;
} Aluno;

int main()
{
    Aluno alunos[5];
    int indice_alunos;
    float soma_notas = 0;
    float media_notas;

    for (indice_alunos = 0; indice_alunos < 5; indice_alunos++)
    {
        cout << "\nQual o nome do " << indice_alunos+1 << "º Aluno? ";
        cin >> alunos[indice_alunos].nome;

        cout << "Qual a matrícula do " << indice_alunos+1 << "º Aluno? ";
        cin >> alunos[indice_alunos].matricula;

        cout << "Qual a nota do " << indice_alunos+1 << "º Aluno? ";
        cin >> alunos[indice_alunos].nota;

        soma_notas += alunos[indice_alunos].nota;
        media_notas = alunos[indice_alunos].nota / 5;
    }

    cout << "\n A Média das notas é: " << media_notas << endl;

    return 0;
}