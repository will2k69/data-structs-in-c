#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int valor;
    struct lista *next;
}node;

node* remov(node *head, int value)
{
    node* previous = NULL;
    node* current = head;
    while (current->valor != value && current != NULL)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL) return head;//ELE FOI ATÉ O FINAL DA LISTA E NÃO ENCONTROU O 'value'
    if (previous == NULL)
        head = current->next;//ELE PAROU NA CABEÇA DA LISTA, ENTÃO A NOVA CABEÇA É O PRÓXIMO DEPOIS DA CABEÇA
    else
        previous->next = current->next;//segue um comentário para entender melhor essa viajem :)
//(NÓ PREVIOUS)|<valor>||<previousNext>|---------->(NÓ CURRENT)|<valor>||<currentNext>|---------->(NÓ)|<valor>||<next>|
//(NÓ PREVIOUS)|<valor>||<previousNext>|--------------------------------------------------------->(NÓ)|<valor>||<next>|
    free(current);
    return head;
}

node* add(node *head, int value)
{
    node *new_node = (node*)malloc(sizeof(node));//ALOCANDO MEMORIA PARA UM NOVO NÓ
    new_node->valor = value;//INSERINDO O VALOR
    new_node->next = head;//O NEXT DO NOVO NÓ VAI APONTAR PARA A CABEÇA, MAS LEMBRE-SE QUE ELA VAI APONTAR PARA O NEW_NODE
    return new_node;//EXATAMENTE AQUI, POIS NESTE MOMENTO O HEAD DA MAIN() ESTÁ RECEBENDO O ENDEREÇO DE NEW_NODE, E ESTE PASSANDO A SER A NOVA CABEÇA.
}

void print_list(node *head)
{
    while (head != NULL)
    {
        printf("valor:%d\n", head->valor);
        head = head->next;
    }
}

int main(void)
{
    node *head = (node*)malloc(sizeof(node));
    head = NULL;

    head = add(head, 3);
    head = add(head, 10);
    head = add(head, 15);
    head = remov(head, 10);
    print_list(head);

    return 0;
}