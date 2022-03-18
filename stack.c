#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    int valorUsuario;
    struct NO *proximo;
}no;

typedef struct Pilha
{
    no *topo;
}pilha;

void inserir(int valor, pilha *p)
{
    no *novo = (no*)malloc(sizeof(no));
    novo->valorUsuario = valor;
    novo->proximo = p->topo;
    p->topo = novo;
}

void remover(pilha *p)
{
    no *aux = p->topo;
    p->topo = aux->proximo;
    free(aux);
}

void imprimirPilha(pilha *p)
{
    no *aux = p->topo;
    while (aux != NULL)
    {
        printf("valor: %d\n", aux->valorUsuario);
        aux = aux->proximo;
    }
}

void main()
{
    pilha *p1 = (pilha*)malloc(sizeof(pilha));
    p1->topo = NULL;

    inserir(15, p1);
    inserir(10, p1);
    inserir(5, p1);
    remover(p1);
    
    imprimirPilha(p1);
}