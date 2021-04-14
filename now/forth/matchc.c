#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define isempty() top == -1
#define isfull() top == 205
#define isbrc(c) c == '(' || c == '}' || c == '{' || c == '}'
#define printe(c, i) printf("without maching %c at line %d", c, i);return 0;

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
    fp = fopen("example.txt", "r");
    int lineindex = 0;
    char line[205];
    int jump = 0;
    int i;
    while (fgets(fp, 205, line) != NULL)
    {
        //读取每一行，对每一行做操作
        lineindex++;
        jump = jump == 4 ? jump : 0;
        for (i = 0; i < strlen(line); i++)
        {
            //对每一个字符，判断jump条件，对括号做处理
            char cur = line[i];
            char pre = i == 0 ? -1 : line[i - 1];
            jump = jumpchange(jump, pre, cur);
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
                            printe('(', stc[top].lineindex);
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
                            printe(')',lineindex);
                        }

                        break;
                    }
                    case '}':
                    {
                        node n = pop();
                        if (n.brc != '{')
                        {
                            printe('}',lineindex);
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
        printe(stc[0].brc,stc[0].lineindex);

    return 0;
}

int jumpchange(int jump, char pre, char cur)
{
    //0不跳过 1字符常量 2字符串常量 3单行注释 4多行注释
    //先写从0到各个情况
    if (jump == 0)
    {
        if (pre == -1) //判断1和2即可，34都需要2个字符来确定
        {
            if (cur == '#')
                return 1;
            if (cur == '"')
                return 2;
        }
        else
        {
            if (cur == '#')
                return 1;
            if (cur == '"')
                return 2;
            if (pre == '/' && cur == '/')
                return 3;
            if (pre == '/' && cur == '*')
                return 4;
        }
    }
    else // jump不为0的情况，需要根据情况判断是否可以变回0
    {
        if (pre != -1)
        {
            //pre为-1的情况，如果jump不为0，只可能是多行注释的情况，跳过当前字符即可，在下一个字符处判断
            if (jump == 1 || jump == 3) //1和3不会改变
                return jump;
            if ((jump == 2 && cur == '"') || (jump == 4 && pre == '*' && cur == '/')) // 2和4可能改变
                return 0;
            return jump; //写这种长的if-else的时候一定要注意，每一种情况都要有一个返回值
        }
        return jump;
    }
}
