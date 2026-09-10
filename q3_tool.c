#include <stdio.h>

#define MAX 64

/*
   PART 1  - paste a row from the table, see its structure.
   PART 2  - type your guessed rule, check it reproduces that row.
*/

void differences(int a[], int n)
{
    int cur[MAX], next[MAX];
    int len = n;

    for (int i = 0; i < n; i++) cur[i] = a[i];

    printf("\n  row 0 (your numbers): ");
    for (int i = 0; i < len; i++) printf("%d ", cur[i]);
    printf("  [%d numbers]\n", len);

    for (int level = 1; level <= 3 && len > 1; level++)
    {
        for (int i = 0; i < len - 1; i++)
            next[i] = cur[i + 1] - cur[i];
        len = len - 1;

        printf("  row %d (differences):  ", level);
        for (int i = 0; i < len; i++) printf("%d ", next[i]);

        int allSame = 1;
        for (int i = 1; i < len; i++)
            if (next[i] != next[0]) allSame = 0;

        if (allSame && len > 1)
            printf("  <-- CONSTANT (%d)", next[0]);
        printf("\n");

        for (int i = 0; i < len; i++) cur[i] = next[i];

        if (allSame && len > 1) break;
    }
    printf("\n");
}

int main(void)
{
    int a[MAX], n = 0, v;

    printf("PART 1 - analyse a row\n");
    printf("Type the numbers from ONE row of the table, then -999 to stop:\n");

    while (n < MAX)
    {
        if (scanf("%d", &v) != 1) break;
        if (v == -999) break;
        a[n] = v;
        n++;
    }

    if (n > 1) differences(a, n);

    printf("Look at the output above and answer these:\n");
    printf("  1. Which row went constant?  (tells you the kind of rule)\n");
    printf("  2. What are the numbers in row 1?  (that is your step size each time)\n");
    printf("  3. How many numbers were in row 0?  (that is your loop count)\n");
    printf("  4. What was the FIRST number?  (that is your starting value)\n\n");

    /* ---------------------------------------------------------------
       PART 2 - test your guess.
       Edit the three marked lines below, rebuild, and see if the output
       matches the table row you just analysed.
       --------------------------------------------------------------- */

    int N;
    printf("PART 2 - test your rule.  Enter N: ");
    if (scanf("%d", &N) != 1) return 0;

    int start = 0;          /* <-- EDIT: your starting value, in terms of N */
    int howMany = 0;        /* <-- EDIT: how many numbers to print, in terms of N */

    printf("\n  your rule for N=%d: ", N);

    int o = start;
    for (int i = 0; i < howMany; i++)
    {
        printf("%d ", o);

        int step = 0;       /* <-- EDIT: the step to add, in terms of i */
        o = o + step;
    }
    printf("\n\n  Compare this to the real row. Same? Then run it for N=2.\n");

    return 0;
}
