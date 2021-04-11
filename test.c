#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    return 0;
}

int f(char s[])
{
    int i = 0, j = 0;
    while (s[j]) // 一般默认的'\0'的值为0，这句话可以理解为s[j]不为'\0'时
    {
        j++;
    }
    for (j--; i < j && s[i] == s[j]; i++, j--) //从这里可以看出来，循环开始时i和j应该分别指向字符串的首尾。所以上面是j++
        ;//如果相等就什么都不做，那么如果对称，i>=j
    return i >= j;
}


左边是栈顶
S(1)        栈内元素：1
X()         1出栈，        栈内元素：
S(2)        栈内元素：2
S(3)        栈内元素：3 2
X()         3出栈          栈内元素：2
S(4)        站内元素：4 2
X()         4出栈           栈内元素2
X()         2出栈


3+x*(2.4/5-6)
//先写最外面的加号
3(x*(2.4/5-6))+
//染后写x*...
3(x(2.4/5-6)*)+
//然后是里面的除法
3(x(2.4,5/-6)*)+
//然后是里面的减法
3(x(2.4,5/6-)*)+

//最后去掉所有括号
3 x 2.4 5 / 6 - * +

3,x,2.4,5,/,6,-,*,+