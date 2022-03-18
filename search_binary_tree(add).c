#include <stdio.h>
#include <stdlib.h>

typedef struct BT
{
    int value;
    struct BT* left;
    struct BT* right;
}binary_tree;

int is_empty(binary_tree* bt) {
    return (bt == NULL) ? 1 : 0;
}

binary_tree* create_binary_tree(int valor, binary_tree* esq, binary_tree* dir)
{
    binary_tree* bt = (binary_tree*)malloc(sizeof(binary_tree));
    bt->value = valor;
    bt->left = esq;
    bt->right = dir;
    return bt;
}

binary_tree* add(binary_tree* bt, int valor)
{
    if (bt == NULL) bt = create_binary_tree(valor, NULL, NULL);
    else if (bt->value > valor) bt->left = add(bt->left, valor);
    else bt->right = add(bt->right, valor);

    return bt;
}

int preOrder_binary_tree(binary_tree* bt)
{
    if(!is_empty(bt))
    {
        printf("  ( ");
        printf("%d", bt->value);
        preOrder_binary_tree(bt->left);

        preOrder_binary_tree(bt->right);
        printf(" )");
    }
    else printf("  ()");
}

int main()
{
    int n;
    binary_tree* bt = (binary_tree*)malloc(sizeof(binary_tree));
    bt = NULL;

    while (scanf("%d", &n) != EOF)
    {
        bt = add(bt, n);
        printf("----\nAdicionando %d\n ", n);
        preOrder_binary_tree(bt);
        printf(" \n");
    }
    printf("----\n");

    return 0;
}