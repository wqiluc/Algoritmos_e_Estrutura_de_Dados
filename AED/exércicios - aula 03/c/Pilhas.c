/*
 * Pilha encadeada (stack) em C padrão.
 * Demonstra empilhar (push) e desempilhar (pop) usando malloc/free,
 * aplicados à inversão de uma palavra digitada pelo usuário.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALAVRA 100

typedef struct No
{
    char dado;
    struct No *prox;
} No;

No *empilhar(No *topo, char valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = topo;
    return novo;
}

No *desempilhar(No *topo, char *valor)
{
    if(!topo)
    {
        return NULL;
    }
    else
    {
        No *temp = topo;
        *valor = topo->dado;
        topo = topo->prox;
        free(temp);
        return topo;
    }
}

void inverter_palavra(char palavra[])
{
    No *pilha = NULL;
    int indice_letra;

    for(indice_letra = 0; palavra[indice_letra] != '\0'; indice_letra++)
    {
        pilha = empilhar(pilha, palavra[indice_letra]);
    }

    printf("Palavra invertida: ");

    while(pilha)
    {
        char letra;
        pilha = desempilhar(pilha, &letra);
        printf("%c", letra);
    }

    printf("\n");
}

int main(void)
{
    char palavra[MAX_PALAVRA];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    inverter_palavra(palavra);

    return 0;
}
