#include <stdio.h>

/*
   The three readable options from question 4.
   Option 4 was cut off in the screenshot - expand it on screen and
   add it here if it differs from these.
*/

void optionA(int N)   /* count 1 to 3N+1 exclusive,  x + 2i - 1 */
{
    int x = -N * N;
    printf("  A: ");
    for (int i = 1; i < 3 * N + 1; i++)
    {
        printf("%d ", x);
        x = x + 2 * i - 1;
    }
    printf("\n");
}

void optionB(int N)   /* count 0 to 3N+1 exclusive,  x + 2i - 1 */
{
    int x = -N * N;
    printf("  B: ");
    for (int i = 0; i < 3 * N + 1; i++)
    {
        printf("%d ", x);
        x = x + 2 * i - 1;
    }
    printf("\n");
}

void optionC(int N)   /* count 1 to 3N+1 exclusive,  x + 2i */
{
    int x = -N * N;
    printf("  C: ");
    for (int i = 1; i < 3 * N + 1; i++)
    {
        printf("%d ", x);
        x = x + 2 * i;
    }
    printf("\n");
}

void optionD(int N)   /* count 0 to 3N+1 exclusive,  x + 2i */
{
    int x = -N * N;
    printf("  D: ");
    for (int i = 0; i < 3 * N + 1; i++)
    {
        printf("%d ", x);
        x = x + 2 * i;
    }
    printf("\n");
}

int main(void)
{
    int N;
    printf("N: ");
    if (scanf("%d", &N) != 1) return 0;
    printf("\n");

    optionA(N);
    optionB(N);
    optionC(N);
    optionD(N);

    printf("\n  Compare each line to the real row in the table.\n");
    printf("  Only one will match exactly.\n");

    return 0;
}
