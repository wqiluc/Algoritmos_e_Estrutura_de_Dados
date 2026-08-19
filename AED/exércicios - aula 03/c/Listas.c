/*
 * Lista encadeada simples (lista ligada) em C padrão.
 * Demonstra inserção no início, no fim, no meio (após um valor buscado)
 * e a impressão da lista, usando malloc/free em vez de new/delete.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *prox;
} No;

No *inserir_inicio(No *lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = lista;
    return novo;
}

No *inserir_fim(No *lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;

    if(!lista)
    {
        return novo;
    }
    else
    {
        No *temp = lista;

        while(temp->prox)
        {
            temp = temp->prox;
        }

        temp->prox = novo;
        return lista;
    }
}

No *inserir_meio(No *lista, int valor_novo, int valor_busca)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = valor_novo;

    No *temp = lista;

    while(temp->prox && temp->prox->dado != valor_busca)
    {
        temp = temp->prox;
    }

    novo->prox = temp->prox;
    temp->prox = novo;
    return lista;
}

void imprimir_lista(No *lista)
{
    No *temp = lista;

    while(temp)
    {
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    }

    printf("NULL\n");
}

void liberar_lista(No *lista)
{
    No *temp = lista;

    while(temp)
    {
        No *proximo = temp->prox;
        free(temp);
        temp = proximo;
    }
}

int main(void)
{
    No *lista = NULL;

    lista = inserir_inicio(lista, 10);
    lista = inserir_inicio(lista, 20);
    lista = inserir_inicio(lista, 30);
    lista = inserir_fim(lista, 40);
    lista = inserir_fim(lista, 50);
    lista = inserir_meio(lista, 99, 10);

    imprimir_lista(lista);

    liberar_lista(lista);

    return 0;
}
