#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct people
{
    char name[25];
    char phone[15];
    int status; //用来处理重复判断的部分
} people;

people list[100];
int compar(people *p1, people *p2)
{
    return strcmp(p1->name, p2->name);
}
int main(int argc, char const *argv[])
{
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        people p;
        scanf("%s %s", p.name, p.phone);
        list[i] = p;
    }
    //排序，这个题有个很有意思的地方，就是哪一个排_1，哪一个是_2，可以根据例子看出来，并不是真的第一次出现的就是第一个，我猜出题人就用的qsort，然而这里要注意qsort是不稳定的
    qsort(list, n, sizeof(people), compar);
    //重复判断，status: -1完全重复 0不重复或第一个 1第二个名字重复 ...
    /* OJ上通过的代码的处理办法：在输入的时候按个判断有没有重复，O(n^2) */
    //TODO 不想写了

    //输出
    for (i = 0; i < n; i++)
    {
        printf("list");
    }

    return 0;
}