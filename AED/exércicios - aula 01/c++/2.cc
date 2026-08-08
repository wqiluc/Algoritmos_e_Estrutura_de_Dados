/*
 * Defina uma struct para estruturar dados de alunos de uma escola. Dentro dessa struct,
 * crie uma variavel para armazenar o nome do aluno, e outras para armazenar as notas de
 * matemática, física e a média dessas duas notas. Após definir a struct, crie três
 * variáveis do tipo struct que você criou. Preencha os nomes e as notas dos alunos,
 * calculando automaticamente a média deles.
 */

#include <array>
#include <iostream>
#include <string>

constexpr int TOTAL_ALUNOS = 3;

struct Aluno
{
    std::string nome;
    float nota_matematica;
    float nota_fisica;
    float media;
};

int main(void)
{
    std::array<Aluno, TOTAL_ALUNOS> alunos;

    for (int indice_aluno = 0; indice_aluno < TOTAL_ALUNOS; indice_aluno++)
    {
        Aluno &aluno = alunos[indice_aluno];

        std::cout << "\n\t Digite o nome do " << indice_aluno + 1 << "º aluno: ";
        std::getline(std::cin >> std::ws, aluno.nome);

        std::cout << "\n\t Digite a nota de Matemática do " << indice_aluno + 1 << "º aluno: ";
        std::cin >> aluno.nota_matematica;

        std::cout << "\n\t Digite a nota de Física do " << indice_aluno + 1 << "º aluno: ";
        std::cin >> aluno.nota_fisica;

        aluno.media = (aluno.nota_matematica + aluno.nota_fisica) / 2;
    }

    std::cout << "\n\t Dados dos alunos: \n";

    for (int indice_aluno = 0; indice_aluno < TOTAL_ALUNOS; indice_aluno++)
    {
        const Aluno &aluno = alunos[indice_aluno];

        std::cout << "\n\t Nome do " << indice_aluno + 1 << "º aluno: " << aluno.nome << "\n";
        std::cout << "\n\t Nota de Matemática do " << indice_aluno + 1 << "º aluno: " << aluno.nota_matematica << "\n";
        std::cout << "\n\t Nota de Física do " << indice_aluno + 1 << "º aluno: " << aluno.nota_fisica << "\n";
        std::cout << "\n\t Média do " << indice_aluno + 1 << "º aluno: " << aluno.media << "\n";
    }
    return 0;
}