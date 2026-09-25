#include <iostream>
using namespace std;

#define TAMANHO 100

typedef struct Fila
{
    int itens[TAMANHO];
    int inicio_fila;
    int fim_fila;
    int quantidade_fila;
} Fila;

typedef struct Pilha
{
    int itens[TAMANHO];
    int topo_pilha;
} Pilha;

void inicializarFila(Fila* fila)
{
    fila->inicio_fila = 0;
    fila->fim_fila = 0;
    fila->quantidade_fila = 0;
}

bool filaVazia(Fila* fila)
{
    return fila->quantidade_fila == 0;
}

void enqueue(Fila* fila, int valor)
{
    fila->itens[fila->fim_fila] = valor;
    fila->fim_fila = (fila->fim_fila + 1) % TAMANHO;
    fila->quantidade_fila++;
}

int dequeue(Fila* fila)
{
    int valor = fila->itens[fila->inicio_fila];
    fila->inicio_fila = (fila->inicio_fila + 1) % TAMANHO;
    fila->quantidade_fila--;
    return valor;
}

void inicializarPilha(Pilha* pilha)
{
    pilha->topo_pilha = -1;
}

bool pilhaVazia(Pilha* pilha)
{
    return pilha->topo_pilha == -1;
}

void push(Pilha* pilha, int valor)
{
    pilha->itens[++pilha->topo_pilha] = valor;
}

int pop(Pilha* pilha)
{
    return pilha->itens[pilha->topo_pilha--];
}

// Esvazia a fila na pilha e depois devolve da pilha para a fila:
// o último a sair da fila vira o primeiro a voltar
void inverterFila(Fila* fila)
{
    Pilha pilha;
    inicializarPilha(&pilha);

    while (!filaVazia(fila))
    {
        push(&pilha, dequeue(fila));
    }

    while (!pilhaVazia(&pilha))
    {
        enqueue(fila, pop(&pilha));
    }
}

void mostrarFila(Fila* fila)
{
    for (int i = 0; i < fila->quantidade_fila; i++)
    {
        cout << fila->itens[(fila->inicio_fila + i) % TAMANHO] << " ";
    }
    cout << endl;
}

int main()
{
    Fila fila;
    inicializarFila(&fila);

    int quantidade_valores;
    int valor;

    cout << "\n\t Quantos valores deseja inserir na fila? ";
    cin >> quantidade_valores;

    for (int i = 0; i < quantidade_valores; i++)
    {
        cout << "Digite o " << i + 1 << "º valor: ";
        cin >> valor;
        enqueue(&fila, valor);
    }

    cout << "Fila original: ";
    mostrarFila(&fila);

    inverterFila(&fila);

    cout << "Fila invertida: ";
    mostrarFila(&fila);

    return 0;
}