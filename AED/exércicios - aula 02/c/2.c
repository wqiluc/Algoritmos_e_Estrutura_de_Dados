/*
 * Crie um programa recursivo que calcule o MDC (máximo divisor comum)
 * de dois números.
 */

#include <stdio.h>

void ler_numeros(int *numero1, int *numero2)
{
    printf("\n\t Digite o primeiro número: ");
    scanf("%d", numero1);

    printf("\n\t Digite o segundo número: ");
    scanf("%d", numero2);
}

int mdc_recursivo(int numero1, int numero2)
{
    if(numero2 == 0)
    {
        return numero1;
    }
    else
    {
        return mdc_recursivo(numero2, numero1 % numero2);
    }
}

int main(void)
{
    int numero1, numero2;

    ler_numeros(&numero1, &numero2);

    printf("\n\t MDC (recursivo): %d\n", mdc_recursivo(numero1, numero2));

    return 0;
}