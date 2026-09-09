#include <iostream>
using namespace std;

void contagemRegressiva(int numero)
{
    if (numero < 0)
    {
        return;
    }

    if (numero == 0)
    {
        cout << "Contagem regressiva finalizada!!" << endl;
        return;
    }

    cout << numero << " ";
    contagemRegressiva(numero - 1);
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
