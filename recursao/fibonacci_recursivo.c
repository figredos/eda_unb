#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int a = fibonacci(3);

    printf("%d", a);

    return 0;
}