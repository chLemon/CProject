#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
/* 去除字符串前无意义的0，若为全0，只保留一个0 */
char *trim(char *a);
/* 翻转字符串s */
void reverse(char *s);
/* 大数减法，c=a-b */
void bigminus(char *a, char *b, char *c);
/* 字符串数字的比较，a大返回正数，b大返回负数，相等返回0 */
int compare(char *a, char *b);
char a[85], b[85];
int main(int argc, char const *argv[])
{
    char *as, *bs, *tp, c[85] = {0}, i;
    gets(a);
    gets(b);
    as = trim(a); //去除前面无意义的0
    bs = trim(b);
    if (compare(as, bs) < 0) /* a大于b的话，就交换ab */
    {
        printf("-");
        tp = as;
        as = bs;
        bs = tp;
    }
    /* 二者翻转 */
    reverse(as);
    reverse(bs);
    /* 执行减法，结果存在c里面 */
    bigminus(as, bs, c); // c = a - b;
    /* c反转去0输出 */
    reverse(c);
    trim(c);
    for (i = 0; i < strlen(c); i++)
    {
        printf("%c", c[i]);
    }

    return 0;
}
int compare(char *a, char *b)
{
    if (strlen(a) != strlen(b))
    {
        return strlen(a) - strlen(b);
    }
    return strcmp(a, b);
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
void bigminus(char *a, char *b, char *c)
{
    /* as现在一定比bs大 */
    int i;
    for (i = 0; i < strlen(a); i++)
    {
        b[i] = b[i] == 0 ? '0' : b[i];
        c[i] = a[i] - b[i];
        if (c[i] < 0) //如果ci小于0，借位+10
        {
            a[i + 1]--;
            c[i] += 10;
        }
        c[i] += '0';
    }
    c[i] = '\0';
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
    return *(a - 1);
}