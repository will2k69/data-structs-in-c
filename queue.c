#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10//more or less...

typedef struct p2
{
    int dynamicSize;
    int currentSize;
    int tail;
    int head;
    int* values;//array
}queue;

int is_empty(queue* q) {
    return (q->currentSize == 0) ? 1 : 0;
}

int dequeue(queue* q)//remove e retorna o elemento da fila
{
    if (is_empty(q))
    {
        printf("Queue underflow.\n");
        return -1;
    }
    else
    {
        int dequeued = *(q->values+q->head);
        q->head = (q->head + 1) % q->dynamicSize;
        q->currentSize--;
        return dequeued;
    }
}

void enqueue(queue* q, int valor)
{
    if (q->currentSize == q->dynamicSize)
    {
        q->dynamicSize += 10;
        q->values = (int*)realloc(q->values, q->dynamicSize * sizeof(int));
        enqueue(q, valor);
    }
    else
    {
        q->tail = (q->tail + 1) % q->dynamicSize;
        *(q->values+q->tail) = valor;
        q->currentSize++;
    }
}

void print_queue(queue* q)
{
    if (q->currentSize == 0)
        printf("Empty queue.\n");
    else
    {
        for (int i = q->head; i < q->head + q->currentSize; i++)
            printf("%d\n", *(q->values+i));
    }
}

queue* create_queue()
{
    queue* new_queue = (queue*)malloc(sizeof(queue));
    new_queue->currentSize = 0;
    new_queue->dynamicSize = MAX_SIZE;//lembre-se que a ideia aqui eh a dinamicidade, ou seja, a qualquer momento o 'enqueue' pode aumentar esse tamanho com 'realloc'
    new_queue->head = 0;
    new_queue->tail = MAX_SIZE-1;
    new_queue->values = (int*)malloc(MAX_SIZE * sizeof(int));

    return new_queue;
}

int main()
{
    queue* q = create_queue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("dequeue feito:%d\n", dequeue(q));
    print_queue(q);

    return 0;
}