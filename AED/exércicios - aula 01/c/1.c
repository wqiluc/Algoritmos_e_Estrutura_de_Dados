/*
 * Crie um programa que leia e apresente os dados de 3 funcionários. Crie uma struct que
 * contenha o nome, idade, salário e a data de nascimento. O que se sabe é que a data de
 * nascimento é do tipo Data, ou seja, uma outra struct que contem os seguintes membros:
 * dia e ano, ambos do tipo inteiro; e mês do tipo string. Crie um vetor de struct para
 * registrar os dados dos 3 funcionários.
 */

#include <stdio.h>
#include <string.h>

 typedef struct 
{
    char nome[100];
    int idade;
    float salario;
    struct
    {
        int dia;
        char mes[20];
        int ano;
    } data_nascimento;
} Funcionario;


 int main(void)
 {
    Funcionario funcionarios[3];
    int indice_funcionario;

    for(indice_funcionario = 0; indice_funcionario < 3; indice_funcionario++)
    {
        printf("\n\t Digite o nome do funcionário %d: ", indice_funcionario + 1);
        scanf(" %[^\n]s", funcionarios[indice_funcionario].nome);

        printf("\n\t Digite a idade do funcionário %d: ", indice_funcionario + 1);
        scanf("%d", &funcionarios[indice_funcionario].idade);

        printf("\n\t Digite o salário do funcionário %d: ", indice_funcionario + 1);
        scanf("%f", &funcionarios[indice_funcionario].salario);

        printf("\n\t Digite o dia de nascimento do funcionário %d: ", indice_funcionario + 1);
        scanf("%d", &funcionarios[indice_funcionario].data_nascimento.dia);

        if(funcionarios[indice_funcionario].data_nascimento.dia < 1 
            || funcionarios[indice_funcionario].data_nascimento.dia > 31)
        {
            printf("\n\t Dia inválido! (1-31) Digite novamente: ");
            scanf("%d", &funcionarios[indice_funcionario].data_nascimento.dia);
        }

        char *meses_validos[12] = 
        {
            "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
            "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
        };
        int mes_valido, i;

        do
        {
            printf("\n\t Digite o mês de nascimento do funcionário %d: ", 
                indice_funcionario + 1);
            scanf(" %[^\n]s", funcionarios[indice_funcionario].data_nascimento.mes);

            mes_valido = 0;

            for(int indice_mes = 0; indice_mes < 12; indice_mes++)
            {
                if(strcmp(funcionarios[indice_funcionario].data_nascimento.mes,
                    meses_validos[indice_mes]) == 0)
                {
                    mes_valido = 1;
                    break;
                }
            }

            if(!mes_valido)
            {
                printf("\n\t Mês inválido!(1-12) Digite um mês entre Janeiro e Dezembro.\n");
            }
        } 
        while(!mes_valido);

        printf("\n\t Digite o ano de nascimento do funcionário %d: ", indice_funcionario + 1);
        scanf("%d", &funcionarios[indice_funcionario].data_nascimento.ano);
    }

    printf("\n\t Dados dos funcionários: \n");

    for(indice_funcionario = 0; indice_funcionario < 3; indice_funcionario++)
    {
        printf("\n\t Nome: %s\n", funcionarios[indice_funcionario].nome);
        printf("\n\t Idade: %d\n", funcionarios[indice_funcionario].idade);
        printf("\n\t Salário: %.2f\n", funcionarios[indice_funcionario].salario);
        printf("\n\t Data de Nascimento: %d/%s/%d\n", funcionarios[indice_funcionario].data_nascimento.dia, funcionarios[indice_funcionario].data_nascimento.mes, funcionarios[indice_funcionario].data_nascimento.ano);
    }
    return 0;
}