#include <iostream>
using namespace std;

typedef struct Retangulo
{
    float base_retangulo;
    float altura_retangulo;
} Retangulo;

float calcularArea(Retangulo retangulo)
{
    return retangulo.base_retangulo * retangulo.altura_retangulo;
}

float calcularPerimetro(Retangulo retangulo)
{
    return 2 * (retangulo.base_retangulo + retangulo.altura_retangulo);
}

int main()
{
    Retangulo retangulo;

    cout << "Digite a base do retângulo: ";
    cin >> retangulo.base_retangulo;

    cout << "Digite a altura do retângulo: ";
    cin >> retangulo.altura_retangulo;

    cout << "\nÁrea: " << calcularArea(retangulo) << endl;
    cout << "Perímetro: " << calcularPerimetro(retangulo) << endl;

    return 0;
}