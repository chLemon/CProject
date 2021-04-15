#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define bothlower(s) (islower(*(s - 1)) && islower(*(s + 1)) && (*(s - 1) < *(s + 1))) //两边都是小写字母，且前者小于后者
#define bothupper(s) (isupper(*(s - 1)) && isupper(*(s + 1)) && (*(s - 1) < *(s + 1))) //两边都是大写字母，且前者小于后者

int main(int argc, char const *argv[])
{
    // 读取输入，键盘输入一行的字符串
    char s[10000];
    gets(s);
    // 对字符串进行处理，并扩展
    char r[10000];
    char *sp = s, *rp = r;
    *(rp++) = *(sp++);
    while (*sp != '\0') //遍历s中的每个字符，直到字符串的最后
    {
        if (*sp == '-' && (bothlower(sp) || bothupper(sp))) //如果符合扩展条件，扩展，并删除掉-
        {
            while (*(rp - 1) != *(sp + 1) - 1)
            {
                *rp = *(rp - 1) + 1;
                rp++;
            }
        }
        else
        {
            *rp = *sp;
            rp++;
        }
        sp++;
    }
    *rp = '\0';
    //输出
    puts(r);
    return 0;
}