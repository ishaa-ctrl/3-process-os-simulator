#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    /*
     * Benchmark workload
     */
    volatile long long result = 0;

    for (long long i = 0; i < 100000000; i++)
    {
        result += i;
    }

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Benchmark Result\n");
    printf("----------------\n");
    printf("Execution time: %.6f seconds\n", cpu_time_used);
    printf("Result: %lld\n", result);

    return 0;
}
