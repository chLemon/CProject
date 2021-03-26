#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x;
    scanf("%d", &x);

    int a;

    a = (x ^ 114514) >> 2;

    int satisfied;
    satisfied = ((a + 521) & 1) > 0;

    printf("%d\n", a);
    if (satisfied)
    {
        printf("I can see the hint");
    }
    else
    {
        printf("HINT!");
    }

    return 0;
}
