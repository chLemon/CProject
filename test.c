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
    stc[++top] = e;
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

int main(int argc, char const *argv[])
{
    char cur = ')';
    int lineindex = 0;
    if (isbrc(cur))
    {
        all[++ia] = cur;
        switch (cur)
        {
        case '(':
        {
            node e = {'(', lineindex};
            push(e);
            break;
        }
        case '{':
        {
            if (stc[top].brc == '(')
            {
                printe('(', stc[top].lineindex);
                return 0;
            }
            node e = {'{', lineindex};
            push(e);
            break;
        }
        case ')':
        {
            printf("======%d", top);
            node n = pop();
            if (n.brc != '(')
            {
                printe(')', lineindex);
                return 0;
            }
            break;
        }
        case '}':
        {
            node n = pop();
            if (n.brc != '{')
            {
                printe('}', lineindex);
                return 0;
            }
            break;
        }
        default:
            break;
        }
    }

    return 0;
}