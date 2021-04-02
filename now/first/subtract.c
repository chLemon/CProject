#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char a[85], b[85];
    gets(a);
    gets(b);
    char *as, *bs;
    as = trim(a);//去除前面无意义的0，用指针节约了一下数组复制的复杂度（然而并不重要）
    bs = trim(b);
    reverse(as);
    reverse(bs);

    if (as == 0 && bs == 0)
    {
        printf("0");
        return;
    }
    else if (as == 0)
    {
        printf("-");
        puts(bs);
    }
    else if (bs == 0)
    {
        puts(as);
    }

    char c[85] = {0};
    bigminus(a, b, c);
    return 0;
}
void reverse(char *s)
{
    int i = 0, l = strlen(s) - 1;
    char t;
    while (i < l)
    {
        t = s[l];
        s[l] = s[i];
        s[i] = t;
        i++;
        l--;
    }
}
void bigminus(char *a, char *b, char *c) //注意这里的c不是真正的字符数组了，只是当一个小整数数组在用
{
    int pos = 1;
    char *as = a, *bs = b, *cs = c, cur;
    while (*a++ != '\0')
        ;   //a处于\0之后
    a -= 2; //a处于\0之前
    while (*b++ != '\0')
        ;
    b -= 2;
    //这时候我发现，reverse函数是必须的，因为c必然是倒着的
    while (a <= as && b <= bs) //直到越界
    {
        cur = *a - *b;
        if (cur < 0)
        {
            //需要借位
            (*(a - 1))--;
            cur += 10;
        }
        *c = cur;
        //移动
        c++;
        a--;
        b--;
    }
    if (/* condition */)
    {
        /* code */
    }
}

char *trim(char *a)
{
    while (*a != '\0')
    {
        if (*a != '0')
        {
            return a;
        }
        a++;
    }
    return 0;
}