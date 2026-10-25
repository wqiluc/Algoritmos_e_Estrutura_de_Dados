// QUESTÃO 4 – Sondagem Linear (✏️ papel)
//
// TAM = 10, funcaoHash(k) = k % 10, sondagem linear. Insira, nesta ordem:
//
// 23, 43, 13, 27, 37, 9, 19
//
// a) Para cada chave, mostre as tentativas e a posição final. Desenhe a
//    tabela.
// b) Quantas tentativas para buscar o 13? E o 29 (que não existe)?
// c) Remova o 43. Como fica a posição dele? Busque o 13 de novo: quantas
//    tentativas? Por que ainda acha?
// d) E se a remoção colocasse VAZIO em vez de REMOVIDO, o que aconteceria
//    com buscar(13)?
// e) Depois da remoção, insira o 33. Onde ele entra?
// f) Qual era o fator de carga antes da remoção?
//
// ✏️ Sua resposta (resolva ANTES de rodar):
// a) Chave | funcaoHash | Tentativas | Posição final
//    23    |      3      |     1       | 3 
//    43    |      3      |     2       | 4
//    13    |      3      |     3       | 5 
//    27    |      7      |     4       | 6 
//    37    |      7      |     5       | 7 
//    9     |      9      |     6       | 8 
//    19    |      9      |     7       | 9 - 0
//
//    Índice   0   1   2   3   4   5   6   7   8   9
//    Valor    0   0   0  23  43  13   0  27  37   9
// b) 13: 3 tentativas | 29: 8 tentativas
// c) 43: REMOVIDO | 13: 3 tentativas (ainda acha porque a posição de 13 ainda está ocupada)
// d) Se a remoção colocasse VAZIO em vez de REMOVIDO, buscar(13) não encontraria o 13, pois a busca pararia ao encontrar o VAZIO, assumindo que a chave não está na tabela.
// e) 33 entraria na posição 4, pois a posição 3 está ocupada por 23, a posição 4 está ocupada por REMOVIDO (43), então ele ocuparia a próxima posição disponível, que é a posição 4.
// f) O fator de carga antes da remoção era 7/10 = 0.7, pois havia 7 elementos inseridos na tabela de tamanho 10.
//
// Compilar e rodar:
// g++ -std=c++17 Questao_04_Sondagem_Linear.cpp -o q4.out && ./q4.out

#include <iostream>
using namespace std;

#define TAM 10

int funcaoHash(int k) 
{
    return k % TAM;
}

int main() 
{
    int tabela[TAM] = {0}; 
    int chaves[] = {23, 43, 13, 27, 37, 9, 19};
    int tentativas[TAM] = {0}; 
    int posicoes[TAM] = {0}; 

    for (int i = 0; i < sizeof(chaves)/sizeof(chaves[0]); i++) 
    {
        int chave = chaves[i];
        int hash = funcaoHash(chave);
        int tentativa = 0;

        while (tabela[hash] != 0)
        {
            tentativa++;
            hash = (hash + 1) % TAM; 
        }

        tabela[hash] = chave;
        tentativas[i] = tentativa + 1;
        posicoes[i] = hash; 
    }

    for (int i = 0; i < sizeof(chaves)/sizeof(chaves[0]); i++) 
    {
        cout << "Chave: " << chaves[i] << " | Tentativas: " << tentativas[i] << " | Posição final: " << posicoes[i] << endl;
    }

    return 0;
}