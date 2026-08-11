/*
 * Crie um programa que leia uma string (pode utilizar a biblioteca <string.h>)
 * e apresente a string invertida. Faça utilizando algoritmo recursivo.
 */

#include <stdio.h>
#include <string.h>

#define MAX_STRING 100

int ler_string(char *str)
{
    printf("\n\t Digite alguma coisa (string): ");
    return scanf("%s", str);
}

void inverter_string_recursivo(char *str, int indice_inicio, int indice_fim)
{
    if(indice_inicio >= indice_fim)
    {
        return;
    }
    else
    {
        char caractere_temporario = str[indice_inicio];
        str[indice_inicio] = str[indice_fim];
        str[indice_fim] = caractere_temporario;

        inverter_string_recursivo(str, indice_inicio + 1, indice_fim - 1);
    }
}

int main(void)
{
    char str_original[MAX_STRING];
    char str_recursiva[MAX_STRING];

    ler_string(str_original);

    strcpy(str_recursiva, str_original);

    inverter_string_recursivo(str_recursiva, 0, strlen(str_recursiva) - 1);

    printf("\n\t String original: %s", str_original);
    printf("\n\t String invertida (recursivo): %s\n", str_recursiva);

    return 0;
}