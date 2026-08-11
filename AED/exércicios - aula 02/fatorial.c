#include <stdio.h>

int fatorial(int numero)
{
    printf("\n\t Digite um número inteiro positivo: ");
    scanf("%d", &numero);

    if(numero < 0)
    {
        printf("\n\t O número digitado é negativo. Por favor, digite um número inteiro positivo.\n");
        return 1;
    }
    else
    {
        int resultado = 1;

        for(int indice_numero = 1; indice_numero <= numero; indice_numero++)
        {
            resultado *= indice_numero;
        }
        
        printf("\n\t O fatorial de %d é: %d\n", numero, resultado);
        return 0;
    }
}

int main(void)
{
    int numero;
    fatorial(numero);
    return 0;
}