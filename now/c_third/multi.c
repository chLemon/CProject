#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node
{
    int xishu; //系数
    int exp;   //指数
    struct node *next;
} listnode;

listnode *readlist();
int printlist(listnode *head);
int inverselist(listnode *head);
listnode *multi(listnode *head_a, listnode *head_b);
listnode *insert(listnode *head_c, listnode *head_a, listnode *head_b);

int main(int argc, char const *argv[])
{

    listnode *head_a = readlist();
    listnode *head_b = readlist();

    listnode *head_c = multi(head_a, head_b);
    printlist(head_c);
    return 0;
}

listnode *multi(listnode *head_a, listnode *head_b)
{
    listnode *head_c;
    head_c = (listnode *)malloc(sizeof(listnode));

    listnode *head_b_backup = head_b;
    while (head_a != NULL)
    {
        while (head_b != NULL)
        {
            head_c = insert(head_c, head_a, head_b);
            head_b = head_b->next;
        }
        head_b = head_b_backup;
        head_a = head_a->next;
    }

    return head_c;
}

listnode *readlist()
{
    listnode *head = (listnode *)malloc(sizeof(listnode));
    listnode *backup = head;
    char input[500];
    gets(input);
    while (sscanf(input, "%d%d", &head->xishu, &head->exp))
    {
        head->next = (listnode *)malloc(sizeof(listnode));
        head = head->next;
    }
    head->next = NULL;
    return backup;
}

int printlist(listnode *head)
{
    while (head != NULL)
    {
        printf("%d %d", head->xishu, head->exp);
        head = head->next;
    }
    printf("\n");
}

listnode *insert(listnode *head_c, listnode *head_a, listnode *head_b)
{
    listnode *new = (listnode *)malloc(sizeof(listnode));
    new->xishu = head_a->xishu * head_b->xishu;
    new->exp = head_a->xishu + head_b->xishu;
    new->next = NULL;
    //在c里找到合适的地方插入
    if (head_c == NULL || new->exp > head_c->exp)
    {
        new->next = head_c;
        return new;
    }

    listnode *pre = head_c;
    listnode *cur = head_c->next;
    while (cur != NULL) //不是最后一个
    {
        if (new->exp > cur->exp)
        {
            pre->next = new;
            new->next = cur;
            return head_c;
        }
    }
    pre->next = new;
    return head_c;
}
