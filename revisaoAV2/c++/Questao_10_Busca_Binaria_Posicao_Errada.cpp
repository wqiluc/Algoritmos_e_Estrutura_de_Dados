// QUESTÃO 10 – Busca Binária com Posição Errada (0,25)✅
//
// Um sistema financeiro utiliza busca binária para localizar contas.
// Em alguns casos, o sistema informa que encontrou a conta, mas retorna uma
// posição incorreta.
//
//   int buscaBinaria(int v[], int n, int valor)
//   {
//       int inicio = 0;
//       int fim = n - 1;
//
//       while(inicio <= fim)
//       {
//           int meio = (inicio + fim) / 2;
//
//           if(v[meio] == valor)
//               return inicio;
//
//           if(valor < v[meio])
//               fim = meio - 1;
//           else
//               inicio = meio + 1;
//       }
//       return -1;
//   }
//
// a) Explique o problema.
// b) Reescreva a função corretamente.
//
// (Prova AV2 SI 2026.1. Na prova é NO PAPEL.)
//
// Para conferir no código:
//
// int buscaBinariaBugada(int v[], int n, int valor);  → copie a função acima como está
// int buscaBinaria(int v[], int n, int valor);        → a sua versão corrigida (item b)
// → no main, para cada conta do vetor, mostre a posição que cada versão
//   retorna e marque quando forem diferentes
// → leia um número de conta do teclado e busque com as duas versões
//
// Contas (vetor ORDENADO):
// Valor   1012 1025 1033 1047 1058 1061 1079 1084 1090 1102
// Índice  0    1    2    3    4    5    6    7    8    9
//
// Testes:
// conta 1084 → correta 7,  bugada 5
// conta 1058 → correta 4,  bugada 0
// conta 1025 → correta 1,  bugada 0
// conta 1033 → correta 2,  bugada 2   (às vezes a bugada acerta!)
// conta 1102 → correta 9,  bugada 9
// conta 1050 → correta -1, bugada -1  (não existe)
//
// Pergunta (é o item a): por que a versão bugada acerta algumas contas e erra
// outras? Rastreie inicio, fim e meio para a conta 1084.
//
// Resposta: revisaoAV2/md/Prova_AV2_SI_2026_1_Respostas.md
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "revisaoAV2/c++/Questao_10_Busca_Binaria_Posicao_Errada.cpp" -o "revisaoAV2/c++/q10.out" && "./revisaoAV2/c++/q10.out"


// a)
// Quando acha a conta (v[meio] == valor), a função retorna "inicio" em vez de
// "meio". Quem foi comparado e é igual ao valor é v[meio], então a posição da
// conta é "meio". O "inicio" é só o limite esquerdo do trecho que ainda está
// sendo procurado.
// O resto da função está certo, por isso ela DETECTA que a conta existe, mas
// devolve a POSIÇÃO ERRADA. Ela só acerta por coincidência, quando inicio == meio
// (trecho com 1 ou 2 elementos).
//
// Rastreio da conta 1084:
// Passo  inicio  fim  meio  v[meio]  Decisão
// 1      0       9    4     1058     1084 > 1058 → inicio = 5
// 2      5       9    7     1084     achou! → retorna inicio = 5 (deveria ser 7)
// A posição 5 é a conta 1061: o sistema mostraria os dados de OUTRA conta.


// b) Trocar "return inicio;" por "return meio;" (função buscaBinariaCorreta abaixo)

#include <iostream>
using namespace std;

#define TAM_VETOR 10

int buscaBinariaBugada(int v[], int n, int valor)
{
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;

        if (v[meio] == valor)
            return inicio; // BUG: deveria ser meio

        if (valor < v[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    return -1;
}

int buscaBinariaCorreta(int v[], int n, int valor)
{
    int inicio = 0;
    int final = n - 1;
    int meio;

    while (inicio <= final)
    {
        meio = inicio + (final - inicio) / 2; 

        if (v[meio] == valor)
        {
            return meio; // CORREÇÃO: a conta está em meio, não em inicio
        }

        else if (v[meio] > valor)
        {
            final = meio - 1; // valor está à esquerda
        }

        else
        {
            inicio = meio + 1; // valor está à direita
        }
    }

    return -1; // não encontrou
}

int main()
{
    int vetor[TAM_VETOR] = {1012, 1025, 1033, 1047, 1058, 1061, 1079, 1084, 1090, 1102};
    int valor;
    int indice;

    cout << "\n\t Conta   Correta   Bugada\n";

    for (indice = 0; indice < TAM_VETOR; indice++)
    {
        int correta = buscaBinariaCorreta(vetor, TAM_VETOR, vetor[indice]);
        int bugada = buscaBinariaBugada(vetor, TAM_VETOR, vetor[indice]);

        cout << "\t " << vetor[indice] << "    " << correta << "         " << bugada;

        if (correta != bugada)
        {
            cout << "   <-- DIFERENTE";
        }
        cout << "\n";
    }

    cout << "\n\t Digite um número de conta: ";
    cin >> valor;

    int correta = buscaBinariaCorreta(vetor, TAM_VETOR, valor);
    int bugada = buscaBinariaBugada(vetor, TAM_VETOR, valor);

    if (correta != -1)
    {
        cout << "\n\t Conta " << valor << " encontrada na posição " << correta << " (correta)";
        cout << "\n\t A versão bugada retornou a posição " << bugada;

        if (correta != bugada)
        {
            cout << "  <-- ERRADA (v[" << bugada << "] = " << vetor[bugada] << ")";
        }
        cout << "\n";
    }

    else
    {
        cout << "\n\t Conta " << valor << " não existe (correta: " << correta << ", bugada: " << bugada << ")\n";
    }

    return 0;
}