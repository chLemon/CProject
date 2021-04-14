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
//����һ���ṹ�壬����2����Ա��һ�������ţ�һ�����к�
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
    //���ļ�
    FILE *fp;
    fp = fopen("example.txt", "r");
    int lineindex = 0;
    char line[205];
    int jump = 0;
    int i;
    while (fgets(fp, 205, line) != NULL)
    {
        //��ȡÿһ�У���ÿһ��������
        lineindex++;
        jump = jump == 4 ? jump : 0;
        for (i = 0; i < strlen(line); i++)
        {
            //��ÿһ���ַ����ж�jump������������������
            char cur = line[i];
            char pre = i == 0 ? -1 : line[i - 1];
            jump = jumpchange(jump, pre, cur);
            if (jump == 0)
            {
                //�������������
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
    //0������ 1�ַ����� 2�ַ������� 3����ע�� 4����ע��
    //��д��0���������
    if (jump == 0)
    {
        if (pre == -1) //�ж�1��2���ɣ�34����Ҫ2���ַ���ȷ��
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
    else // jump��Ϊ0���������Ҫ��������ж��Ƿ���Ա��0
    {
        if (pre != -1)
        {
            //preΪ-1����������jump��Ϊ0��ֻ�����Ƕ���ע�͵������������ǰ�ַ����ɣ�����һ���ַ����ж�
            if (jump == 1 || jump == 3) //1��3����ı�
                return jump;
            if ((jump == 2 && cur == '"') || (jump == 4 && pre == '*' && cur == '/')) // 2��4���ܸı�
                return 0;
            return jump; //д���ֳ���if-else��ʱ��һ��Ҫע�⣬ÿһ�������Ҫ��һ������ֵ
        }
        return jump;
    }
}
