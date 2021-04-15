#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX (500 + 5)
#define N (200 + 5)
int flag[500];
char pas[500];

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
    struct node *p, *list, *p0;
    p = (struct node *)malloc(sizeof(struct node));
    p->next = NULL;
    list = p;
    char op;
    while ((op = getchar()) != '\n')
    {
        if (flag[op] == 0)
        {
            p0 = (struct node *)malloc(sizeof(struct node));
            p0->word = op;
            p0->next = NULL;
            p->next = p0;
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
            p0 = (struct node *)malloc(sizeof(struct node));
            p0->word = op;
            p0->next = NULL;
            p->next = p0;
            p = p->next;
        }
    }
    p->next = list;

    struct node *q;
    q = (struct node *)malloc(sizeof(struct node));
    char m = list->word;
    for (p = list->next; p != p->next; p = q->next)
    {
        list = list->next;
        q = p;
        for (i = 0; i < p->word; i++)
        {
            q = q->next;
        }
        pas[p->word] = q->word;
    }
    pas[m] = p->word;
}