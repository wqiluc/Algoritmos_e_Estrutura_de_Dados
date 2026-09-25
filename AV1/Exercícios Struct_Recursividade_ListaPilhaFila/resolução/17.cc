#include <iostream>
using namespace std;

void contagemRegressiva(int numero)
{
    for (int contador = numero; contador > 0; contador--)
    {
        cout << contador << " ";
    }

    if (numero >= 0)
    {
        cout << "Contagem regressiva finalizada!!" << endl;
    }
}

int main()
{
    int numero;

    cout << "\n\t Digite um número: ";
    cin >> numero;

    contagemRegressiva(numero);
    cout << endl;

    return 0;
}
