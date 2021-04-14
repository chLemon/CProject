#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define isempty() top == -1
#define isfull() top == 205
#define isbrc(c) c == '(' || c == '}' || c == '{' || c == '}'
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

int main(int argc, char const *argv[])
{
    //打开文件
    FILE *fp;
    fp = fopen("example.txt", "r");
    int lineindex = 0;
    char line[205];
    int jump = 0;
    int i;
    while (fgets(fp, 205, line) != NULL)
    {
        //读取每一行，对每一行做操作
        lineindex++;
        for (i = 0; i < strlen(line); i++)
        {
            //对每一个字符，判断jump条件，对括号做处理
            char cur = line[i];
            char pre = i == 0 ? -1 : line[i - 1];
            jumpchange(jump, pre, cur);
            if (jump == 0)
            {
                //不该跳过的情况
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
                            printe();
                        }
                        node e = {'{', lineindex};
                        push(e);
                    }
                    break;
                    case ')':
                    {
                        node n = pop();
                        if (n.brc != '(')
                        {
                            printe();
                        }

                        break;
                    }
                    case '}':
                    {
                        node n = pop();
                        if (n.brc != '{')
                        {
                            printe();
                        }
                        break;
                    }
                    default:
                        break;
                    }
                }
            }
        }
    }
    all[++ia] = '\0';
    if (isempty())
        for (i = 0; i < strlen(all); i++)
            printf("%c", all[i]);
    else
        printe();

    return 0;
}