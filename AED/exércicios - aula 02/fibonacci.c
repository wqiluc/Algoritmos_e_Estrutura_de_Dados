#include <stdio.h>

#define INDICE_TERMO_INICIAL 3

int fibonacci(int numero_fibonacci)
{

    printf("\n\t Digite o numero de termos da sequencia de Fibonacci: ");
    scanf("%d", &numero_fibonacci);

    if(numero_fibonacci <= 0)
    {
        printf("\n\t O número de termos deve ser maior que zero. \n");
        return 1;
    }
    else
    {
        int primeiro_termo = 0, segundo_termo = 1, proximo_termo;
        int indice_termo;

        printf("\n\t Sequencia de Fibonacci: %d", primeiro_termo);

        if(numero_fibonacci > 1)
        {
            printf(", %d", segundo_termo);
        }

        for(indice_termo = INDICE_TERMO_INICIAL; indice_termo <= numero_fibonacci; indice_termo++)
        {
            proximo_termo = primeiro_termo + segundo_termo;
            printf(", %d", proximo_termo);

            primeiro_termo = segundo_termo;
            segundo_termo = proximo_termo;
        }

        printf("\n");
        return 0;
    }
}

int main(void)
{
    int numero_fibonacci;

    fibonacci(numero_fibonacci);

    return 0;
}