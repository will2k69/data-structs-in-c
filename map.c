#include <stdio.h>
#include <stdlib.h>

void map(long long int (*function)(int), int *array, long long int *array_results, int len, int i)
{
    if (i == len) return;
    else
    {
        *(array_results + i) = function(*(array+i));
        map(function, array, array_results, len, i+1);
    }
}

long long int factorial(int n)
{
    if (n == 1) return 1;
    else return n * factorial(n-1);
}

void printar_array(long long int *array, int len, int i)
{
    if (i == len) return;
    else
    {
        printf("array[%d] = %lld\n", i, *(array+i));
        printar_array(array, len, i+1);
    }
}

void ler_array(int *array, int len, int i)
{
    if (i == len) return;
    else
    {
        scanf("%d", array+i);
        ler_array(array, len, i+1);
    }
}

void main()
{
    int len_array;
    printf("Digite o tamanho do array 'int': ");
    scanf("%d", &len_array);
    
    int *array = (int *)malloc(len_array * sizeof(int));
    long long int *array_results = (long long int *)malloc(len_array * sizeof(long long int));

    printf("\n\nDigite os valores do array:\n");
    ler_array(array, len_array, 0);
    map(factorial, array, array_results, len_array, 0);
    printar_array(array_results, len_array, 0);    
}