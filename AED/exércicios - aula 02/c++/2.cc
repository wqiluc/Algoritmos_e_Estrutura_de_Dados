/*
 * Crie um programa recursivo que calcule o MDC (máximo divisor comum)
 * de dois números.
 */

#include <iostream>

void ler_numeros(int &numero1, int &numero2)
{
    std::cout << "\n\t Digite o primeiro número: ";
    std::cin >> numero1;

    std::cout << "\n\t Digite o segundo número: ";
    std::cin >> numero2;
}

int mdc_recursivo(int numero1, int numero2)
{
    if (numero2 == 0)
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

    ler_numeros(numero1, numero2);

    std::cout << "\n\t MDC (recursivo): " << mdc_recursivo(numero1, numero2) << "\n";

    return 0;
}