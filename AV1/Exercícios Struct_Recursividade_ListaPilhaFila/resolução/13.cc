#include <iostream>
using namespace std;

int somaDigitos(int numero)
{
    if (numero < 10 && numero > -10)
    {
        return numero;
    }

    return numero % 10 + somaDigitos(numero / 10);
}

int main()
{
    int numero;

    cout << "\n\t Digite um número inteiro: ";
    cin >> numero;

    cout << "Soma dos dígitos: " << somaDigitos(numero) << endl;

    return 0;
}