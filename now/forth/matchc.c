#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define isempty() top == -1
#define isfull() top == 205
//����һ���ṹ�壬����2����Ա��һ�������ţ�һ�����к�
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
            char cur = line[i]; //��ǰ�ַ�
            //TODO

            if (jump)
            {
                //TODO  ����
            }
            else
            {
                //TODO �жϲ���

                /* 
                ��  ��ջ
                {   �����ĳ�������Ϊ'{'ʱ������ǰ����δƥ�������Ϊ'('ʱ�������'('�����ż������кţ� 
                )   ����ջ���жϣ���ջ
                }   ����ջ���ж�

                ÿ�����Ŷ���Ҫ����һ��
                 */
            }
        }
    }
    //���������ˣ���������ڲ�ƥ���������ʱ������������ż������кš�
    //��������ڣ�˵��û���⣬����洢��ȫ��������
    return 0;
}