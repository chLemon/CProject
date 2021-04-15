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
    while ((ch = fgetc(fp)) != NULL)
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
    struct node *p, *list;
    p = (struct node *)malloc(sizeof(struct node));
    list = p = NULL;
    int n = 0;
    char op;
    while (op = getchar() != EOF)
    {
        if (flag[op] == 0)
        {
            p->next->word = op;
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
            p->next->word = op;
            p = p->next;
        }
    }
    p->next = list;

    struct node *q;
    q = (struct node *)malloc(sizeof(struct node));
    int m = list->word;
    for (p = list->next; p != p->next; p = p->next)
    {
        q = p;
        for (i = 0; i < p->word; i++)
        {
            p = p->next;
        }
        pas[q->word] = p->word;
        free(q);
    }
    pas[m] = p->word;
}