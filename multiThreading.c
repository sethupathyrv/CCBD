#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 100000000
#define threadCount 5

//current tested size limit 130000000
int *a;
int *b;
int *c;
int part = 0;

void *myThreadFun(void *vargp)
{
    int thread_part = part++;
    for (int i = thread_part * (size / threadCount); i < (thread_part + 1) * (size / threadCount); i++)
    {
        //printf("%d\t%d\n", thread_part, i);
        c[i] = a[i] + b[i];
    }
    return NULL;
}

int main()
{
    clock_t start, end;
    double cpu_time_used;
    pthread_t thread_id[threadCount];
    a = (int *)malloc(size * sizeof(int));
    b = (int *)malloc(size * sizeof(int));
    c = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 1000;
        b[i] = rand() % 1000;
    }

    printf("Before Thread\n");
    start = clock();
    for (int i = 0; i < threadCount; i++)
    {
        pthread_create(&thread_id[i], NULL, myThreadFun, NULL);
    }

    for (int i = 0; i < threadCount; i++)
    {
        pthread_join(thread_id[i], NULL);
    }
    end = clock();

    cpu_time_used = (((double)(end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("%f\n", cpu_time_used);
    printf("After Thread\n");
}