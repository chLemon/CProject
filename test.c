#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX (500 + 5)
#define N (200 + 5)
int flag[200];
char pas[200];

struct node
{
    char word;
    struct node *next;
};

void add();

int main()
{
    add();

    FILE *fp, *pp;
    fp = fopen("in.txt", "r");
    pp = fopen("in_crpyt.txt", "w");

    char ch;

    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
        if (ch >= 32 || ch <= 126)
            fputc(pas[ch], pp);
        else
            fputc(ch, pp);
    }

    fclose(fp);
    fclose(pp);
    return 0;
}

void add()
{
    struct node *p, *list, *pre, *q;
    p = (struct node *)malloc(sizeof(struct node));
    p->next = NULL;
    list = p;
    char op;
    while ((op = getchar()) != '\n')
    {
        if (flag[op] == 0)
        {
            q = (struct node *)malloc(sizeof(struct node));
            q->word = op;
            q->next = NULL;
            p->next = q;
            p = p->next;
            flag[op] = 1;
        }
    }

    int i = 0;
    for (i = 32; i <= 126; i++)
    {
        op = i;
        if (flag[i] == 0)
        {
            q = (struct node *)malloc(sizeof(struct node));
            q->word = op;
            q->next = NULL;
            p->next = q;
            p = p->next;
        }
    }
    p->next = list->next;

    pre = p;
    list = list->next;
    int m, h;
    h = list->word;
    for (p = list; p != p->next;)
    {
        m = p->word;
        pre->next = p->next;
        p = p->next;
        for (i = 0; i < m - 1; i++)
        {
            pre = pre->next;
            p = p->next;
        }
        pas[m] = p->word;
    }
    pas[p->word] = h;
}