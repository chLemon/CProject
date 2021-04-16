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
    //排序，这个题不能用快排，因为快排不稳定
    qsort(list, n, sizeof(people), compar);
    //重复判断，status: -1完全重复 0不重复或第一个 1第二个名字重复 ...
    
    //输出
    char *prename = list[0].name, *prephone = list[0].phone;
    printf("%s %s", prename, prephone);
    int b = 0;
    for (i = 1; i < n; i++)
    {
        if (list[i].name == prename && list[i].phone != prephone)
        {
            printf("list")
        }
    }

    return 0;
}