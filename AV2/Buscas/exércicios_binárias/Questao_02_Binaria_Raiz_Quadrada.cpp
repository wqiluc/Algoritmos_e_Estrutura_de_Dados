// QUESTÃO 2 – Busca Binária: Raiz Quadrada Inteira (busca na resposta)
//
// A busca binária não serve só para vetores: serve para qualquer intervalo de
// números em que dá para decidir "a resposta está à esquerda ou à direita".
//
// Calcule a raiz quadrada inteira de n (o maior x tal que x * x <= n) SEM usar
// sqrt() e sem testar um por um. Faça uma busca binária no intervalo [0, n]:
//   - se meio * meio <= n → meio é um candidato: guarde e procure à direita (inicio = meio + 1)
//   - se meio * meio >  n → meio é grande demais: procure à esquerda (fim = meio - 1)
//
// ex: n = 26 → 5 (5 * 5 = 25 <= 26, mas 6 * 6 = 36 > 26)
//
// int raizInteira(int n);
// → imprima inicio, fim e meio a cada passo
// → cuidado: meio * meio estoura o int para n grande. Use long long nas contas.
//
// No main, leia n do teclado (n >= 0) e mostre o resultado.
//
// Testes:
// n = 26 → 5
//   inicio=0 fim=26 meio=13 → 169 > 26  → fim = 12
//   inicio=0 fim=12 meio=6  → 36  > 26  → fim = 5
//   inicio=0 fim=5  meio=2  → 4  <= 26  → resposta = 2, inicio = 3
//   inicio=3 fim=5  meio=4  → 16 <= 26  → resposta = 4, inicio = 5
//   inicio=5 fim=5  meio=5  → 25 <= 26  → resposta = 5, inicio = 6  (inicio > fim: para)
// n = 49         → 7
// n = 99         → 9
// n = 0          → 0
// n = 1          → 1
// n = 2          → 1
// n = 1000000    → 1000
// n = 2147483647 → 46340 (o maior int: aqui o long long faz diferença)
//
// Pergunta: quantos passos, no máximo, a busca faz para n = 1000000?
// E quantos faria testando x = 0, 1, 2, ... até passar?
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Buscas/exércicios_binárias/Questao_02_Binaria_Raiz_Quadrada.cpp" -o "AV2/Buscas/exércicios_binárias/q2.out" && "./AV2/Buscas/exércicios_binárias/q2.out"

#include <iostream>
using namespace std;

int raizInteira(int n) 
{
    int inicio = 0;
    int fim = n;
    int meio;
    int resposta = -1;

    while (inicio <= fim) 
    {
        meio = inicio + (fim - inicio) / 2; 
        long long quadrado = static_cast<long long>(meio) * meio;

        cout << "inicio=" << inicio << " fim=" << fim << " meio=" << meio << endl;

        if (quadrado <= n) 
        {
            resposta = meio; 
            inicio = meio + 1; 
        }

        else 
        {
            fim = meio - 1; 
        }
    }

    return resposta;
}

int main() 
{
    int n;
    cout << "Digite um número inteiro não negativo: ";
    cin >> n;

    if (n < 0) 
    {
        cout << "Número inválido. Por favor, insira um número não negativo." << endl;
        return 1; 
    }

    int resultado = raizInteira(n);
    cout << "A raiz quadrada inteira de " << n << " é: " << resultado << endl;

    return 0;
}