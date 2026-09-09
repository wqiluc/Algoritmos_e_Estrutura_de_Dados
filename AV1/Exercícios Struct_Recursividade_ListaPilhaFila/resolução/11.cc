#include <iostream>
using namespace std;

int contarDigitos(int numero)
{
    if (numero < 10 && numero > -10)
    {
        return 1;
    }

    return 1 + contarDigitos(numero / 10);
}

int main()
{
    int numero;

    cout << "\n\t Digite um número inteiro: ";
    cin >> numero;

    cout << "Quantidade de dígitos: " << contarDigitos(numero) << endl;

    return 0;
}
