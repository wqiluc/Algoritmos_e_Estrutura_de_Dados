#include <iostream>
using namespace std;

int produto(int a, int b)
{
    int resultado = 0;
    bool negativo = b < 0;

    if (negativo)
    {
        b = -b;
    }

    for (int contador = 0; contador < b; contador++)
    {
        resultado += a;
    }

    return negativo ? -resultado : resultado;
}

int main()
{
    int a, b;

    cout << "\n\t Digite o primeiro número: ";
    cin >> a;

    cout << "\n\tDigite o segundo número: ";
    cin >> b;

    cout << "Produto: " << produto(a, b) << endl;

    return 0;
}
