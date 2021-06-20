#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a1, a2, a3;
    char op1, op2, op3;
    //为了保证计算顺序，在最开始加上一个0+
    a1 = 0;
    op1 = '+';
    while (op1 != '=')
    {
        scanf("%d %c", &a2, &op2);
        //一口气把乘除计算完毕
        while (op2 == '*' || op2 == '/')
        {
            scanf("%d %c", &a3, &op3);
            if (op2 == '*')
                a2 *= a3;
            else if (op2 == '/')
                a2 /= a3;
            op2 = op3;
        }
        if (op1 == '+')
            a1 += a2;
        else if (op1 == '-')
            a1 -= a2;
        op1 = op2;
    }
    printf("%d", a1);
    return 0;
}