#include <stdio.h>

void sim(int N, int from, int minusOne, const char *label)
{
    int x = -N * N;
    printf("  %-28s : ", label);
    for (int i = from; i < 3 * N + 1; i++)
    {
        printf("%d ", x);
        x = x + (minusOne ? (2 * i - 1) : (2 * i));
    }
    printf("\n");
}

int main(void)
{
    int Ns[] = {1, 2, 3};
    for (int k = 0; k < 3; k++)
    {
        int N = Ns[k];
        printf("N = %d\n", N);
        sim(N, 0, 1, "i from 0, add (2i - 1)");
        sim(N, 1, 1, "i from 1, add (2i - 1)");
        sim(N, 0, 0, "i from 0, add (2i)");
        sim(N, 1, 0, "i from 1, add (2i)");
        printf("\n");
    }
    return 0;
}
