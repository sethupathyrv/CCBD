#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 100000000

int main()
{
    int *a;
    int *b;
    int *c;
    a = (int *)malloc(size * sizeof(int));
    b = (int *)malloc(size * sizeof(int));
    c = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 1000;
        b[i] = rand() % 1000;
    }
    clock_t start, end;
    double cpu_time_used;
    int threadCount = 10;

    start = clock();

    for (int i = 0; i < size; i++)
    {
        c[i] = a[i] + b[i];
    }
    end = clock();

    cpu_time_used = (((double)(end - start)) / CLOCKS_PER_SEC) * 1000;
    printf("%f\n", cpu_time_used);

    exit(0);
}