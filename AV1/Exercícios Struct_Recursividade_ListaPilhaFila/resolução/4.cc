#include <iostream>
using namespace std;

typedef struct Carro
{
    char modelo_carro[30];
    int ano_carro;
    float preco_carro;
} Carro;

void lerCarro(Carro* carro, int indice_carro)
{
    cout << "\nDigite o modelo do " << indice_carro + 1 << "º Carro: ";
    cin >> carro->modelo_carro;

    cout << "Digite o ano do " << indice_carro + 1 << "º Carro: ";
    cin >> carro->ano_carro;

    cout << "Digite o preço do " << indice_carro + 1 << "º Carro: ";
    cin >> carro->preco_carro;
}

void exibirCarro(Carro* carro, int indice_carro)
{
    cout << "\nCarro " << indice_carro + 1 << ":" << endl;
    cout << "Modelo: " << carro->modelo_carro << endl;
    cout << "Ano: " << carro->ano_carro << endl;
    cout << "Preço: R$ " << carro->preco_carro << endl;
}

int main()
{
    Carro* carros = new Carro[5];

    for (int indice_carro = 0; indice_carro < 5; indice_carro++)
    {
        lerCarro(&carros[indice_carro], indice_carro);
    }

    for (int indice_carro = 0; indice_carro < 5; indice_carro++)
    {
        exibirCarro(&carros[indice_carro], indice_carro);
    }

    return 0;
}
