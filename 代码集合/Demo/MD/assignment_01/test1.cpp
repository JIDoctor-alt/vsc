#include <stdio.h>
#include <time.h>

int main()
{
    int n;
    scanf("%d", &n);

    clock_t st = clock();
    long long sum = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ++sum;
    clock_t ft = clock();
    double dt = (ft - st) * 1.0 / CLOCKS_PER_SEC;

    printf("sum = %lld\n", sum);
    printf("duration: %f s\n", dt);
    
    return 0;
}