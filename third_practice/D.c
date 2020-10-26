#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int temp[500];
        int i = 0;
        while (n != 0)
        {
            temp[i] = n % 3;
            i++;
            n /= 3;
        }
        i--;
        if (i >= 5)
        {
            printf("LONG");
        }
        for (i; i >= 0; i--)
        {
            printf("%d", temp[i]);
        }
    }
    return 0;
}
