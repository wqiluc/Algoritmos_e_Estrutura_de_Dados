#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct Tarefa
{
    int id;
    char descricao[50];
    int prioridade; // 1 = alta, 2 = media, 3 = baixa
} Tarefa;

typedef struct No
{
    Tarefa tarefa;
    No* proximo_pilha;
    No* proximo_fila;
} No;

typedef struct Fila
{
    No* atras_fila;
    No* frente_fila;
} Fila;

void empilharTarefas(No*& topo_pilha, Tarefa tarefa)
{
    No* novo_pilha = new No;
    novo_pilha->tarefa = tarefa;
    novo_pilha->proximo_pilha = topo_pilha;
    topo_pilha = novo_pilha;
}


Fila* criarFila()
{
    Fila* fila = new Fila;
    fila->atras_fila = fila->frente_fila = nullptr;
    return fila;
}
void enfileirarTarefas(Fila* fila, Tarefa tarefa)
{
    No* novo_fila = new No;
    novo_fila->tarefa = tarefa;
    novo_fila->proximo_fila = nullptr;

    if (!fila->atras_fila)
    {
        fila->atras_fila = fila->frente_fila = novo_fila;
    }
    else
    {
        fila->atras_fila->proximo_fila = novo_fila;
        fila->atras_fila = novo_fila;
    }
}


void imprimirPilha(No* topo_pilha)
{
    cout << "\n\t Tarefas na pilha (prioridade alta): \n";

    while (topo_pilha)
    {
        cout << "\t ID: " << topo_pilha->tarefa.id
             << " | Descricao: " << topo_pilha->tarefa.descricao
             << " | Prioridade: " << topo_pilha->tarefa.prioridade << "\n";
        topo_pilha = topo_pilha->proximo_pilha;
    }
}


void imprimirFila(Fila* fila)
{
    cout << "\n\t Tarefas na fila (prioridade media/baixa):\n";
    
    No* lugar_temporario = fila->frente_fila;

    while (lugar_temporario)
    {
        cout << "\t ID: " << lugar_temporario->tarefa.id
             << " | Descrição: " << lugar_temporario->tarefa.descricao
             << " | Prioridade: " << lugar_temporario->tarefa.prioridade << "\n";
        lugar_temporario = lugar_temporario->proximo_fila;
    }
}

int main()
{
    No* pilha = nullptr;
    Fila* fila = criarFila();
    int indice_tarefa;

    for (indice_tarefa = 0; indice_tarefa < 5; indice_tarefa++)
    {
        Tarefa tarefa;

        cout << "\n\t º" << (indice_tarefa+1) << "  Tarefa: ";

        cout << " ID: ";
        cin >> tarefa.id;

        cout << " Descrição: ";
        cin.ignore();
        cin.getline(tarefa.descricao, 50);

        cout << "\n\t Digite a Prioridade (1 = alta, 2 = media, 3 = baixa): ";
        cin >> tarefa.prioridade;

        if (tarefa.prioridade == 1)
        {
            empilharTarefas(pilha, tarefa);
        }
        else
        {
            enfileirarTarefas(fila, tarefa);
        }
    }

    imprimirPilha(pilha);
    imprimirFila(fila);

    //return 0;
    system("PAUSE");
}