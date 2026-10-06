#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double execution_time;

    start = clock();

    volatile long long result = 0;

    for (long long i = 0; i < 100000000; i++)
    {
        result += i;
    }

    end = clock();

    execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Standalone Benchmark\n");
    printf("--------------------\n");
    printf("Execution time: %.6f seconds\n", execution_time);
    printf("Result: %lld\n", result);

    return 0;
}
