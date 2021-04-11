#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int top = -1;
int isfull()
{
    return top == 99;
}

int isempty()
{
    return top == -1;
}

int main(int argc, char const *argv[])
{
    int op, item, s[105];
    while (scanf("%d ", &op) != EOF)
    {
        if (op == -1)
        {
            return 0;
        }
        else if (op == 1)
        {
            scanf("%d", &item);
            if (isfull())
            {
                printf("error ");
            }
            else
            {
                s[++top] = item;
            }
        }
        else
        {
            if (isempty())
            {
                printf("error ");
            }
            else
            {
                printf("%d ", s[top]);
                top--;
            }
        }
    }

    return 0;
}