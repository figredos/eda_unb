#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 4;
    int f, f1, f2;
    f2 = 0;
    f1 = 1;
    f = n;

    for (int i = 2; i <= n; i++)
    {
        f = f1 + f2;

        f2 = f1;
        f1 = f;
    }

    printf("%d", f);

    return 0;
}