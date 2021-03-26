#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, count;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((a[i] & a[j]) > (a[i] ^ a[j]))
            {
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}
