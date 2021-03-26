#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void removeblank(char *s);

int main(int argc, char const *argv[])
{
    //处理输入
    char input[500];
    gets(input);
    removeblank(input);
    puts(input);
    return 0;
}

void removeblank(char *s)
{
    char *p1 = s, *p2;
    while (!isblank(*p1))
        p1++;
    if (*p1)
        return;
    //p1现在是第一个出现的空格
    
    p2 = p1 + 1;
    while (p2 == ' ')
    {
        p2++;
    }
    //p2是之后第一个不是空格的，p1是空格
    while (*p2 != '\0')
    {
        if
    }

    *p2 = '\0';
}