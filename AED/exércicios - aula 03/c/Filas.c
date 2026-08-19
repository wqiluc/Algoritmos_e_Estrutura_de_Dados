/*
 * Fila encadeada (queue) em C padrão.
 * Demonstra criar a fila, enfileirar, desenfileirar e imprimir,
 * usando malloc/free em vez de new/delete.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    char nome[50];
    struct No *prox;
} No;

typedef struct
{
    No *frente;
    No *atras;
} Fila;

Fila *criar_fila(void)
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->frente = fila->atras = NULL;
    return fila;
}

void enfileirar(Fila *fila, char nome[])
{
    No *novo = (No *)malloc(sizeof(No));
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if(!fila->atras)
    {
        fila->frente = fila->atras = novo;
    }
    else
    {
        fila->atras->prox = novo;
        fila->atras = novo;
    }
}

void desenfileirar(Fila *fila)
{
    if(!fila->frente)
    {
        return;
    }
    else
    {
        No *temp = fila->frente;
        fila->frente = fila->frente->prox;

        if(!fila->frente)
        {
            fila->atras = NULL;
        }

        free(temp);
    }
}

void imprimir_fila(Fila *fila)
{
    No *temp = fila->frente;

    while(temp)
    {
        printf("%s <- ", temp->nome);
        temp = temp->prox;
    }

    printf("NULL\n");
}

void liberar_fila(Fila *fila)
{
    while(fila->frente)
    {
        desenfileirar(fila);
    }

    free(fila);
}

int main(void)
{
    Fila *fila = criar_fila();

    enfileirar(fila, "Ana");
    enfileirar(fila, "Bruno");
    enfileirar(fila, "Carlos");
    imprimir_fila(fila);

    desenfileirar(fila);
    imprimir_fila(fila);

    liberar_fila(fila);

    return 0;
}