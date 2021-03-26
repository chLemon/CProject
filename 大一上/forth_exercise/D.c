#include <stdio.h>
#include <math.h>
int printSimplify(int a, int b);
int findGCD(int a, int b);
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int layer;
        layer = (sqrt(8 * n + 1) - 1) / 2;
        int layerLast = layer * (layer + 1) / 2;
        if (n == layerLast)
        {
            //layer 层的最后一个
            if ((layer & 1) == 0)
            {
                //偶数层，下1
                printSimplify(layer, 1);
            }
            else
            {
                //奇数层，上1
                printSimplify(1, layer);
            }
        }
        else
        {
            //位于layer + 1 层
            int sum = layer + 1 + 1;
            int bias = n - layerLast;
            if (((layer + 1) & 1) == 0)
            {
                printSimplify(bias, sum - bias);
            }
            else
            {
                printSimplify(sum - bias, bias);
            }
        }
    }

    return 0;
}
int printSimplify(int a, int b)
{
    int GCD;
    while ((GCD = findGCD(a, b)) != 1)
    {
        a /= GCD;
        b /= GCD;
    }
    if (b == 1)
    {
        printf("%d\n", a);
    }
    else
    {
        printf("%d / %d\n", a, b);
    }
}
int findGCD(int a, int b)
{
    int min = a > b ? b : a;
    for (int i = min; i > 0; i--)
    {
        if ((a % i) == 0 && (b % i) == 0)
        {
            return i;
        }
    }
}
