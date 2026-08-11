/*
 * Crie um programa que leia uma string (pode utilizar a biblioteca <string.h>)
 * e apresente a string invertida. Faça utilizando algoritmo recursivo.
 */

#include <iostream>
#include <string>

std::string ler_string()
{
    std::string str;

    std::cout << "\n\t Digite alguma coisa (string): ";
    std::cin >> str;

    return str;
}

std::string inverter_string_recursivo(const std::string &str, int indice_inicio, int indice_fim)
{
    if (indice_inicio >= indice_fim)
    {
        return str;
    }
    else
    {
        std::string str_invertida = str;
        char caractere_temporario = str_invertida[indice_inicio];
        str_invertida[indice_inicio] = str_invertida[indice_fim];
        str_invertida[indice_fim] = caractere_temporario;
        // mescla as letras da string, chamando a função recursivamente
        // para os próximos índices

        return inverter_string_recursivo(str_invertida, indice_inicio + 1, indice_fim - 1);
    }
}

int main(void)
{
    std::string str_original = ler_string();
    std::string str_invertida = inverter_string_recursivo(str_original, 0, str_original.length() - 1);

    std::cout << "\n\t String original: " << str_original;
    std::cout << "\n\t String invertida (recursivo): " << str_invertida << "\n";

    return 0;
}
