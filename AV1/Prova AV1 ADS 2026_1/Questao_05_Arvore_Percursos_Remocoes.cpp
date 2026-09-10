// QUESTÃO 05 (2.5 pontos)
//
// a) Construa a árvore binária, na ordem apresentada:
//    70, 40, 90, 20, 60, 80, 100, 10, 30, 50, 65, 85, 95, 110, 55, 52, 53, 54, 51, 57
//
// Árvore resultante (desenhada por níveis):
//
//                              70
//                    ┌──────────┴──────────┐
//                   40                     90
//              ┌─────┴─────┐          ┌─────┴─────┐
//             20           60        80            100
//           ┌──┴──┐     ┌───┴──┐       └─85       ┌──┴──┐
//          10     30   50      65                95    110
//                        └─55
//                       ┌───┴──┐
//                      52      57
//                    ┌──┴──┐
//                   51     53
//                            └─54
//
// b) Pré-ordem (raiz, esquerda, direita):
//    70, 40, 20, 10, 30, 60, 50, 55, 52, 51, 53, 54, 57, 65, 90, 80, 85, 100, 95, 110
//
// c) Pós-ordem (esquerda, direita, raiz):
//    10, 30, 20, 51, 54, 53, 52, 57, 55, 50, 65, 60, 40, 85, 80, 95, 110, 100, 90, 70
//
// d) Remoção do nó 40 (dois filhos: 20 e 60) usando o "algoritmo da
//    direita" -> substitui pelo sucessor (menor valor da subárvore direita).
//    Sucessor de 40 = menor valor de sua subárvore direita (raiz 60) = 50.
//    40 é substituído por 50, e o nó original 50 (que só tinha filho à
//    direita, 55) é removido e substituído por 55 na posição de 60->esquerda.
//
//                              70
//                    ┌──────────┴──────────┐
//                   50                     90
//              ┌─────┴─────┐          ┌─────┴─────┐
//             20           60        80            100
//           ┌──┴──┐     ┌───┴──┐       └─85       ┌──┴──┐
//          10     30   55      65                95    110
//                    ┌──┴──┐
//                   52      57
//                 ┌──┴──┐
//                51     53
//                          └─54
//
// e) Remoção do nó 50 (posição antes ocupada por 40; dois filhos: 20 e 60)
//    usando o "algoritmo da direita" -> sucessor = menor valor da subárvore
//    direita (raiz 60) = 51. 50 é substituído por 51, e o nó original 51
//    (folha) é removido de 52->esquerda.
//
//                              70
//                    ┌──────────┴──────────┐
//                   51                     90
//              ┌─────┴─────┐          ┌─────┴─────┐
//             20           60        80            100
//           ┌──┴──┐     ┌───┴──┐       └─85       ┌──┴──┐
//          10     30   55      65                95    110
//                    ┌──┴──┐
//                   52      57
//                     └──53
//                           └─54
//
// O programa abaixo constrói a árvore, imprime os percursos pedidos e
// executa as duas remoções (sempre pelo sucessor da subárvore direita),
// imprimindo a árvore (em-ordem + estrutura por níveis) após cada uma.

#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct No
{
    int valor;
    No* esquerda_arvore;
    No* direita_arvore;
};

No* criarNo(int valor)
{
    No* novo_no_arvore = new No;
    novo_no_arvore->valor = valor;
    novo_no_arvore->esquerda_arvore = NULL;
    novo_no_arvore->direita_arvore = NULL;
    return novo_no_arvore;
}

No* inserirNo(No* raiz_arvore, int valor)
{
    if (raiz_arvore == NULL)
    {
        return criarNo(valor);
    }

    if (valor < raiz_arvore->valor)
    {
        raiz_arvore->esquerda_arvore = inserirNo(raiz_arvore->esquerda_arvore, valor);
    }

    else if (valor > raiz_arvore->valor)
    {
        raiz_arvore->direita_arvore = inserirNo(raiz_arvore->direita_arvore, valor);
    }

    return raiz_arvore;
}

No* encontrarNoMinimo(No* raiz_arvore)
{
    while (raiz_arvore->esquerda_arvore != NULL)
    {
        raiz_arvore = raiz_arvore->esquerda_arvore;
    }
    return raiz_arvore;
}

// Remove sempre pelo "algoritmo da direita": quando o nó tem dois filhos,
// usa o sucessor (menor valor da subárvore direita) no lugar do nó removido.
No* removerNo(No* raiz_arvore, int valor)
{
    if (!raiz_arvore)
    {
        return raiz_arvore;
    }

    if (valor < raiz_arvore->valor)
    {
        raiz_arvore->esquerda_arvore = removerNo(raiz_arvore->esquerda_arvore, valor);
    }

    else if (valor > raiz_arvore->valor)
    {
        raiz_arvore->direita_arvore = removerNo(raiz_arvore->direita_arvore, valor);
    }

    else
    {
        if (!raiz_arvore->esquerda_arvore)
        {
            No* filho_direito = raiz_arvore->direita_arvore;
            delete raiz_arvore;
            return filho_direito;
        }

        else if (!raiz_arvore->direita_arvore)
        {
            No* filho_esquerdo = raiz_arvore->esquerda_arvore;
            delete raiz_arvore;
            return filho_esquerdo;
        }

        No* sucessor = encontrarNoMinimo(raiz_arvore->direita_arvore);
        raiz_arvore->valor = sucessor->valor;
        raiz_arvore->direita_arvore = removerNo(raiz_arvore->direita_arvore, sucessor->valor);
    }

    return raiz_arvore;
}

void preOrdem(No* raiz_arvore)
{
    if (!raiz_arvore)
    {
        return;
    }

    cout << raiz_arvore->valor << " ";
    preOrdem(raiz_arvore->esquerda_arvore);
    preOrdem(raiz_arvore->direita_arvore);
}

void emOrdem(No* raiz_arvore)
{
    if (!raiz_arvore)
    {
        return;
    }

    emOrdem(raiz_arvore->esquerda_arvore);
    cout << raiz_arvore->valor << " ";
    emOrdem(raiz_arvore->direita_arvore);
}

void posOrdem(No* raiz_arvore)
{
    if (!raiz_arvore)
    {
        return;
    }

    posOrdem(raiz_arvore->esquerda_arvore);
    posOrdem(raiz_arvore->direita_arvore);
    cout << raiz_arvore->valor << " ";
}

// Impressão auxiliar da estrutura da árvore "deitada" (raiz à esquerda),
// só para facilitar a conferência visual das remoções.
void imprimirArvore(No* raiz_arvore, const string& prefixo = "", bool eh_esquerda = true)
{
    if (!raiz_arvore)
    {
        return;
    }

    imprimirArvore(raiz_arvore->direita_arvore, prefixo + (eh_esquerda ? "│   " : "    "), false);
    cout << prefixo << (eh_esquerda ? "└── " : "┌── ") << raiz_arvore->valor << "\n";
    imprimirArvore(raiz_arvore->esquerda_arvore, prefixo + (eh_esquerda ? "    " : "│   "), true);
}

int main()
{
    No* raiz_arvore = NULL;

    int valores[] = {70, 40, 90, 20, 60, 80, 100, 10, 30, 50, 65, 85, 95, 110, 55, 52, 53, 54, 51, 57};
    for (int valor : valores)
    {
        raiz_arvore = inserirNo(raiz_arvore, valor);
    }

    cout << "Árvore construída:\n";
    imprimirArvore(raiz_arvore);

    cout << "\nb) Pré-ordem:  ";
    preOrdem(raiz_arvore);

    cout << "\nc) Pós-ordem:  ";
    posOrdem(raiz_arvore);
    cout << "\n";

    cout << "\nd) Removendo o nó 40 (algoritmo da direita)...\n";
    raiz_arvore = removerNo(raiz_arvore, 40);
    cout << "Em-ordem após remover 40: ";
    emOrdem(raiz_arvore);
    cout << "\n";
    imprimirArvore(raiz_arvore);

    cout << "\ne) Removendo o nó 50 (algoritmo da direita)...\n";
    raiz_arvore = removerNo(raiz_arvore, 50);
    cout << "Em-ordem após remover 50: ";
    emOrdem(raiz_arvore);
    cout << "\n";
    imprimirArvore(raiz_arvore);

    return 0;
}
