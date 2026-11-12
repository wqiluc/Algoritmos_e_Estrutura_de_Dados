// QUESTÃO 1 – Merge Sort: Vetor de Structs (e a estabilidade)
//
// Ordene os MESMOS alunos da Questão 3 do Shell Sort por nota em ordem
// DECRESCENTE, agora com Merge Sort recursivo.
//
// struct Aluno
// {
//     string nome;
//     int nota;
// };
//
// Índice  0     1      2      3      4      5      6     7
// Nome    Ana   Bruno  Carla  Diego  Elisa  Fabio  Gabi  Hugo
// Nota    7     9      7      6      9      8      7     6
//
// void intercalar(Aluno alunos[], int esquerda, int meio, int direita);
// void mergeSort(Aluno alunos[], int esquerda, int direita);
// → no intercalar, em caso de EMPATE, pegue o aluno da metade da ESQUERDA
//   (é isso que garante a estabilidade: use >= na comparação das notas)
// → imprima a lista ordenada no formato Nome(nota)
//
// Testes:
// Merge Sort → Bruno(9) Elisa(9) Fabio(8) Ana(7) Carla(7) Gabi(7) Diego(6) Hugo(6)
// Shell Sort → Elisa(9) Bruno(9) Fabio(8) Carla(7) Ana(7) Gabi(7) Diego(6) Hugo(6)  (Questão 3 do Shell)
//
// Perguntas:
// 1) Por que aqui Bruno ficou na frente de Elisa, e Ana na frente de Carla?
// 2) Troque o >= por > no intercalar. O resultado continua estável? Por quê?
// 3) Quando a estabilidade importa? (Pense: a lista estava em ordem alfabética
//    e você ordenou por nota. Como ficaram os empatados em cada algoritmo?)
//
// Compilar e rodar (a partir da raiz do repositório):
// g++ -std=c++17 "AV2/Sorts/exércicios_merge_sort/Questao_01_Merge_Sort_Structs_Estavel.cpp" -o "AV2/Sorts/exércicios_merge_sort/q1.out" && "./AV2/Sorts/exércicios_merge_sort/q1.out"

#include <iostream>
#include <string>
using namespace std;

#define TAM_VETOR 8

struct Aluno
{
    string nome;
    int nota;
};

void imprimirAlunos(Aluno alunos[], int tamanho_vetor)
{
    for (int indice_vetor = 0; indice_vetor < tamanho_vetor; indice_vetor++)
    {
        cout << alunos[indice_vetor].nome << "(" << alunos[indice_vetor].nota << ") ";
    }
    cout << endl;
}

void intercalar(Aluno alunos[], int esquerda, int meio, int direita)
{
    int tamanho_esquerda = meio - esquerda + 1;
    int tamanho_direita = direita - meio;

    Aluno* metade_esquerda = new Aluno[tamanho_esquerda];
    Aluno* metade_direita = new Aluno[tamanho_direita];

    for (int i = 0; i < tamanho_esquerda; i++)
    {
        metade_esquerda[i] = alunos[esquerda + i];
    }

    for (int j = 0; j < tamanho_direita; j++)
    {
        metade_direita[j] = alunos[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = esquerda;

    while (i < tamanho_esquerda && j < tamanho_direita)
    {
        if (metade_esquerda[i].nota >= metade_direita[j].nota)
        {
            alunos[k] = metade_esquerda[i];
            i++;
        }

        else
        {
            alunos[k] = metade_direita[j];
            j++;
        }
        k++;
    }

    while (i < tamanho_esquerda) // sobra da esquerda
    {
        alunos[k] = metade_esquerda[i];
        i++;
        k++;
    }

    while (j < tamanho_direita) // sobra da direita
    {
        alunos[k] = metade_direita[j];
        j++;
        k++;
    }

    delete[] metade_esquerda;
    delete[] metade_direita;
}

void mergeSort(Aluno alunos[], int esquerda, int direita)
{
    if (esquerda >= direita)
    {
        return;
    }

    int meio = esquerda + (direita - esquerda) / 2;

    mergeSort(alunos, esquerda, meio);
    mergeSort(alunos, meio + 1, direita);

    intercalar(alunos, esquerda, meio, direita);
}

int main()
{
    Aluno alunos[TAM_VETOR] = 
    {
        {"Ana", 7},
        {"Bruno", 9},
        {"Carla", 7},
        {"Diego", 6},
        {"Elisa", 9},
        {"Fabio", 8},
        {"Gabi", 7},
        {"Hugo", 6}
    };

    cout << "\n\t Lista original: ";
    imprimirAlunos(alunos, TAM_VETOR);

    mergeSort(alunos, 0, TAM_VETOR - 1);

    cout << "\n\t Merge Sort:     ";
    imprimirAlunos(alunos, TAM_VETOR);

    return 0;
}

// Respostas:
//
// 1) Porque o Merge Sort (com >=) é ESTÁVEL. Quando duas notas empatam no
//    intercalar, ele pega primeiro da metade da ESQUERDA, que contém quem
//    veio antes na lista original. Bruno (índice 1) vem antes de Elisa
//    (índice 4), e Ana (0) vem antes de Carla (2) e Gabi (6), então essa
//    ordem é mantida no resultado.
//
// 2) Não. Com > o empate cai no else e pega da metade da DIREITA primeiro,
//    ou seja, quem veio DEPOIS passa na frente. A ordem original dos
//    empatados é invertida e o algoritmo deixa de ser estável:
//    → Elisa(9) Bruno(9) Fabio(8) Gabi(7) Carla(7) Ana(7) Hugo(6) Diego(6)
//
// 3) A estabilidade importa quando a lista já está organizada por um critério
//    e você ordena por OUTRO, querendo manter o primeiro como desempate.
//    Aqui a lista estava em ordem alfabética e foi ordenada por nota:
//    → Merge Sort (estável): empatados continuam em ordem alfabética
//      (Bruno, Elisa / Ana, Carla, Gabi / Diego, Hugo).
//    → Shell Sort (instável): a ordem alfabética se perde
//      (Elisa antes de Bruno, Carla antes de Ana), porque os gaps grandes
//      fazem trocas "à distância" que pulam por cima de elementos iguais.
//    Exemplos práticos: ranking por nota com desempate por nome, ordenar
//    por várias colunas numa planilha, ordenar pedidos por status mantendo
//    a ordem de chegada.
