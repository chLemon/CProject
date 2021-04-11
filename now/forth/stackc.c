#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define isfull() top==100
#define isempty() top == -1

int stack[100]; //定义一个栈
int top = -1;   //初始栈顶，指向-1表示栈为空
void push(int e)
{ //把整数e压入栈中
    if (isfull())
    {
        printf("error ");
        return;
    }
    stack[++top] = e;
}
int pop()
{ //弹出栈顶的元素
    if (isempty())
    {
        printf("error ");
        return 1;
    }
    return stack[top--];
}

int main(int argc, char const *argv[])
{
    int op, e;
    while (scanf("%d", &op))
    {
        switch (op)
        {
        case -1:
            return 0;
        case 0:
            printf("%d ", pop());
            break;
        case 1:
            scanf("%d", &e);
            push(e);
            break;
        }
    }
}