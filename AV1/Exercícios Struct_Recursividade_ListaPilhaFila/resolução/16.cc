#include <iostream>
#include <cstring>
using namespace std;

#define TAMANHO_PALAVRA 100

void digitarPalavra(char palavra[])
{
    cout << "\n\t Digite uma palavra: ";
    cin >> palavra;
}

bool ehPalindromo(char palavra[], int inicio, int fim)
{
    if (inicio >= fim)
    {
        return true;
    }

    if (palavra[inicio] != palavra[fim])
    {
        return false;
    }

    return ehPalindromo(palavra, inicio + 1, fim - 1);
}

void ehPalindromo(char palavra[])
{
    if (ehPalindromo(palavra, 0, strlen(palavra) - 1))
    {
        cout << "\"" << palavra << "\" é um palíndromo!" << endl;
    }
    else
    {
        cout << "\"" << palavra << "\" não é um palíndromo." << endl;
    }
}

int main()
{
    char palavra[TAMANHO_PALAVRA];

    digitarPalavra(palavra);
    ehPalindromo(palavra);

    return 0;
}
