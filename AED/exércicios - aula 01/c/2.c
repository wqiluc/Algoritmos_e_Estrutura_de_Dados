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
    Aluno aluno1, aluno2, aluno3;
    int indice_aluno;

    for(indice_aluno = 0; indice_aluno < MAX_ALUNOS; indice_aluno++)
    {
        printf("\n\t Digite o nome do %dº aluno: ", indice_aluno + 1);
        scanf("%s", (indice_aluno == 0) ? aluno1.nome : (indice_aluno == 1) 
        ? aluno2.nome : aluno3.nome);

        printf("\n\t Digite a nota de Matemática do %dº aluno: ", indice_aluno + 1);
        scanf("%f", (indice_aluno == 0) ? &aluno1.nota_Matematica : (indice_aluno == 1) 
        ? &aluno2.nota_Matematica : &aluno3.nota_Matematica);

        printf("\n\t Digite a nota de Física do %dº aluno: ", indice_aluno + 1);
        scanf("%f", (indice_aluno == 0) ? &aluno1.nota_Fisica : (indice_aluno == 1) 
        ? &aluno2.nota_Fisica : &aluno3.nota_Fisica);

        if(indice_aluno == 0) 
        {
            aluno1.media = (aluno1.nota_Matematica + aluno1.nota_Fisica) / 2;
        } 

        else if(indice_aluno == 1) 
        {
            aluno2.media = (aluno2.nota_Matematica + aluno2.nota_Fisica) / 2;
        } 

        else 
        {
            aluno3.media = (aluno3.nota_Matematica + aluno3.nota_Fisica) / 2;
        }
    }

    for(indice_aluno = 0; indice_aluno < MAX_ALUNOS; indice_aluno++)
    {
        printf("\n\t Nome do %dº aluno: %s", indice_aluno + 1, (indice_aluno == 0) 
        ? aluno1.nome : (indice_aluno == 1) ? aluno2.nome : aluno3.nome);

        printf("\n\t Nota de Matemática do %dº aluno: %.2f", indice_aluno + 1, 
        (indice_aluno == 0) ? aluno1.nota_Matematica : (indice_aluno == 1) 
        ? aluno2.nota_Matematica : aluno3.nota_Matematica);

        printf("\n\t Nota de Física do %dº aluno: %.2f", indice_aluno + 1, 
        (indice_aluno == 0) ? aluno1.nota_Fisica : (indice_aluno == 1) 
        ? aluno2.nota_Fisica : aluno3.nota_Fisica);

        printf("\n\t Média do %dº aluno: %.2f\n", indice_aluno + 1, 
        (indice_aluno == 0) ? aluno1.media : (indice_aluno == 1) 
        ? aluno2.media : aluno3.media);
    }
    return 0;
}