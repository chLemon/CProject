#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define isempty() top == -1
#define isfull() top == 205
//定义一个结构体，包含2个成员，一个是括号，一个是行号
typedef struct node
{
    char brc;
    int lineindex;
} node;

node stc[205];
node all[205];

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
    FILE *fp;
    fp = fopen("example.txt", "r");
    int lineindex = 1;
    char line[205];
    int jump = 0;
    int i;
    while (fgets(fp, 205, line) != NULL)
    {
        for (i = 0; i < strlen(line); i++)
        {
            char cur = line[i]; //当前字符
            //TODO

            if (jump)
            {
                //TODO  跳过
            }
            else
            {
                //TODO 判断部分

                /* 
                （  入栈
                {   当检测的程序括号为'{'时，若其前序尚未匹配的括号为'('时，输出该'('左括号及所在行号； 
                )   根据栈顶判断，出栈
                }   根据栈顶判断

                每个括号都需要保存一下
                 */
            }
        }
    }
    //程序处理完了，如果还存在不匹配的左括号时，输出该左括号及所在行号。
    //如果不存在，说明没问题，输出存储的全部的括号
    return 0;
}