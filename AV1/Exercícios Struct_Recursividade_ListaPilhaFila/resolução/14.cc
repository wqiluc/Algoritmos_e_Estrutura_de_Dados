#include <iostream>
using namespace std;

int produto(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }

    if (b < 0)
    {
        return -produto(a, -b);
    }

    return a + produto(a, b - 1);
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
