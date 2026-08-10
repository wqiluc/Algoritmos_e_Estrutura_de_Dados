/*
 * Defina uma struct para estruturar dados de alunos de uma escola. Dentro dessa struct,
 * crie uma variavel para armazenar o nome do aluno, e outras para armazenar as notas de
 * matemática, física e a média dessas duas notas. Após definir a struct, crie três
 * variáveis do tipo struct que você criou. Preencha os nomes e as notas dos alunos,
 * calculando automaticamente a média deles.
 */

#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 3
#define MAX_NOME 50

typedef struct 
{
    char nome[MAX_NOME];
    float nota_Matematica;
    float nota_Fisica;
    float media;
} Aluno;

int main(void) 
{
    Aluno alunos[MAX_ALUNOS];
    int indice_aluno;

    for(indice_aluno = 0; indice_aluno < MAX_ALUNOS; indice_aluno++)
    {
        printf("\n\t Digite o nome do %dº aluno: ", indice_aluno + 1);
        scanf("%s", alunos[indice_aluno].nome);

        printf("\n\t Digite a nota de Matemática do %dº aluno: ", indice_aluno + 1);
        scanf("%f", &alunos[indice_aluno].nota_Matematica);

        printf("\n\t Digite a nota de Física do %dº aluno: ", indice_aluno + 1);
        scanf("%f", &alunos[indice_aluno].nota_Fisica);

        alunos[indice_aluno].media = (alunos[indice_aluno].nota_Matematica + alunos[indice_aluno].nota_Fisica) / 2;
    }

    for(indice_aluno = 0; indice_aluno < MAX_ALUNOS; indice_aluno++)
    {
        printf("\n\t Nome do %dº aluno: %s", indice_aluno + 1, alunos[indice_aluno].nome);

        printf("\n\t Nota de Matemática do %dº aluno: %.2f", indice_aluno + 1,
        alunos[indice_aluno].nota_Matematica);

        printf("\n\t Nota de Física do %dº aluno: %.2f", indice_aluno + 1,
        alunos[indice_aluno].nota_Fisica);

        printf("\n\t Média do %dº aluno: %.2f\n", indice_aluno + 1,
        alunos[indice_aluno].media);
    }
    return 0;
}