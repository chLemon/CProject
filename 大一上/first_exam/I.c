#include <stdio.h>
int findGCD(int a, int b);
int main()
{
    {
        int a, b, c, d, ra, rb;
        scanf("%d/%d %d/%d", &a, &b, &c, &d);
        if (b == d)
        {
            //直接加
            ra = a + c;
            rb = b;
        }
        else
        {
            ra = a * d + b * c;
            rb = b * d;
        }
        //约分
        while (findGCD(ra, rb) != 1)
        {
            int GCD = findGCD(ra, rb);
            ra = ra / GCD;
            rb = rb / GCD;
        }
        printf("%d/%d + %d/%d = %d/%d", a, b, c, d, ra, rb);
        return 0;
    }
}
int findGCD(int a, int b)
{
    int min;
    if (a > b)
    {
        min = b;
    }
    else
    {
        min = a;
    }
    for (int i = min; i >= 1; i--)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            return i;
        }
    }
    return 1;
}
