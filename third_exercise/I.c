#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int n[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &n[i]);
    }

    int a = 0, b = 0, c = 0;
    int has0 = 0;
    int min = n[0], max = n[0];
    for (int i = 0; i < N; i++)
    {
        a = a ^ n[i];
        if (n[i] == 0)
        {
            has0++;
        }

        if (min > n[i])
        {
            min = n[i];
        }
        if (max < n[i])
        {
            max = n[i];
        }
    }
    if ((a == 0) && (has0 != 1))
    {
        printf("%d %d", min, max);
        return 0;
    }
    if (has0 == 1)
    {
        if (a == 0)
        {
            printf("1 0");
        }
        else
        {
            printf("2 0");
        }
        return 0;
    }

    int p;
    for (int i = 0; i < 32; i++)
    {
        if (a & 1 == 1)
        {
            p = i;
            break;
        }
        a >>= 1;
    }

    for (int i = 0; i < N; i++)
    {
        if (((n[i] >> p) & 1) == 0)
        {
            b ^= n[i];
        }
        else
        {
            c ^= n[i];
        }
    }

    if (b == 0)
    {
        printf("1 %d", c);
        return 0;
    }
    if (c == 0)
    {
        printf("1 %d", b);
        return 0;
    }
    long long multi = b * c;
    printf("2 %lld", multi);

    return 0;
}
