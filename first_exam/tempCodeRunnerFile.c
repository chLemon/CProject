#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int eachInt;
        scanf("%d", eachInt);
        result += eachInt * eachInt;
    }
    printf("%d", result);

    return 0;
}
