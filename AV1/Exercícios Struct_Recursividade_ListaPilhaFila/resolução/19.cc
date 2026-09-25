#include <iostream>
using namespace std;

int somaDigitos(int numero)
{
    int soma = 0;

    while (numero != 0)
    {
        soma += numero % 10;
        numero /= 10;
    }

    return soma;
}

int main()
{
    int numero;

    cout << "\n\t Digite um número inteiro: ";
    cin >> numero;

    cout << "Soma dos dígitos: " << somaDigitos(numero) << endl;

    return 0;
}
