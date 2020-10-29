#include <stdio.h>
int main(int argc, char const *argv[])
{
    // + - * / %
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", a + b);
    printf("%d\n", a - b);
    printf("%d\n", a * b);
    if (b == 0)
    {
        printf("Divided by zero!\n");
        printf("Divided by zero!");
    }
    else
    {
        printf("%d\n", a / b);
        printf("%d", a % b);
    }

    return 0;
}
