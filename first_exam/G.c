#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int m;
    m = a % b;
    if (m == 0)
    {
        printf("%d", a / b);
    }
    else
    {
        printf("%d", (a / b) + 1);
    }

    return 0;
}
