#include <stdio.h>
int findGCD(int a, int b);
int main()
{
    int p, q;
    scanf("%d%d", &p, &q);

    int n = p * q;
    int f = (p - 1) * (q - 1);

    //先找e
    for (int e = 2; e < f; e++)
    {
        if (findGCD(e, f) == 1)
        {
            for (int d = 2; d < f; d++)
            {
                int a = e * d;
                if (((a - 1) % f) == 0)
                {
                    printf("(%d,%d),(%d,%d)\n", n, e, n, d);
                }
            }
        }
    }

    return 0;
}
int findGCD(int a, int b)
{
    int min = a;
    if (a > b)
    {
        min = b;
    }
    for (int i = 1; i <= b; i++)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            return i;
        }
    }
}
