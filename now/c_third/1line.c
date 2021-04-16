#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define isempty() (t == -1)
typedef struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
} line;
typedef struct ListNode
{
    line line;
    ListNode *next;
} ListNode;

int main(int argc, char const *argv[])
{
    /* 用链表连接，维护下链表的数量即可，其实这题可以用并查集啊 */
    int n , i;
    scanf("%d", n);
    for ( i = 0; i < n; i++)
    {
        
    }
    
    int t = 0, i;
    while (scanf("%d %d %d %d", l.x1, l.y1, l.x2, l.y2) != EOF)
    {
        if (isempty())
        {
            ls[t++] = l;
        }
        else
        {
            //遍历看一下，能连到谁后面，能连到谁前面
            for (i = 0; i < t; i++)
            {
            }
        }
    }

    return 0;
}