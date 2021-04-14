#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define isempty() top == -1
#define isfull() top == 205
#define isbrc(c) c == '(' || c == '}' || c == '{' || c == '}'
#define printe(c, i) printf("without maching %c at line %d", c, i);

char all[205];
int ia = -1;
//定义一个结构体，包含2个成员，一个是括号，一个是行号
typedef struct node
{
    char brc;
    int lineindex;
} node;
node stc[205];
int top = -1;
int push(node e)
{
    if (top == 205)
        return -1;
    stc[top++] = e;
    return 0;
}
node pop()
{
    if (top == -1)
    {
        node n = {-1, -1};
        return n;
    }
    return stc[top--];
}

int jumpchange(int jump, char pre, char cur);
int main(int argc, char const *argv[])
{
    //打开文件
    FILE *fp;
    fp = fopen("example.c", "r");//注意：open后必须close
    char line[205];
    int lineindex = 0;
    int jump = 0;
    int i;
    while (fgets(line, 205, fp) != NULL)
    {