#include <stdio.h>

#define SIZE 10

void draw(int N, int lo, int hi, const char *label)
{
    char g[SIZE][SIZE];

    for (int y = 0; y < SIZE; y++)
        for (int x = 0; x < SIZE; x++)
            g[y][x] = '.';

    // First diagonal: start at (N,0) red, then count 0 to N exclusive
    int x = N, y = 0;
    g[y][x] = 'R';
    for (int k = 0; k < N; k++)
    {
        x = x - 1;
        y = y + 1;
        if (x >= 0 && y < SIZE) g[y][x] = 'R';
    }

    // Second diagonal: start at (N+1,0) green, then the loop we are testing
    x = N + 1;
    y = 0;
    if (x < SIZE) g[y][x] = 'G';

    printf("%s\n", label);
    printf("  i values: ");
    for (int i = lo; i <= hi; i++)
    {
        printf("%d ", i);

        x = x - 1;
        y = y + 1;
        if (x >= 0 && y < SIZE)
        {
            if (i % 2 == 0)
                g[y][x] = 'B';
            else
                g[y][x] = 'G';
        }
    }
    printf("  (%d numbers)\n", hi - lo + 1);

    for (int row = SIZE - 1; row >= 0; row--)
    {
        printf("  ");
        for (int col = 0; col < SIZE; col++)
            printf("%c ", g[row][col]);
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    int N;
    printf("N: ");
    scanf("%d", &N);
    printf("\n");

    draw(N, 0, N - 1,  "OPTION 1: count from 0 to N (exclusive)");
    draw(N, 1, N + 1,  "OPTION 2: count from 1 to N+1 (inclusive)");
    draw(N, 1, N + 1,  "OPTION 3: count from 1 to N+2 (exclusive)");
    draw(N, 0, N,      "OPTION 4: count from 0 to N+1 (exclusive)");

    return 0;
}
