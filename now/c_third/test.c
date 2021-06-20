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
    p = (struct node *)malloc(sizeof(struct node)); //创建链表的头节点，这个节点之后没有意义
    p->next = NULL;                                 //本题可省略，一般 创建一个新节点，然后把next设置成NULL，是为了在遍历链表的时候方便地判断有没有到结尾
    list = p;                                       //头结点备份
    char op;
    while ((op = getchar()) != '\n')
    {
        if (flag[op] == 0)
        {
            q = (struct node *)malloc(sizeof(struct node)); //创建一个新的节点，op存放在该节点的word，next置位NULL
            q->word = op;
            q->next = NULL;
            p->next = q; //把刚刚创建的节点连接到链表的最后面
            p = p->next; //p指向链表最后面的节点（刚刚创建的节点）
            flag[op] = 1;
        }
    }

    int i = 0;
    for (i = 32; i <= 126; i++)
    {
        op = i;
        if (flag[i] == 0)
        {
            q = (struct node *)malloc(sizeof(struct node)); //创建一个新的节点，op存放在该节点的word，next置位NULL
            q->word = op;
            q->next = NULL;
            p->next = q; //把刚刚创建的节点连接到链表的最后面
            p = p->next; //p指向链表最后面的节点（刚刚创建的节点）
        }
    }
    p->next = list->next; //把头结点的下一个节点连接在链表的末尾，头结点的word未指定，没有任何意义，相当于删除了头结点。
    /* 
    【做题的时候可以不用太考虑free的问题】
    如果要free，可以用下面的方法，可以之后留意一下书和PPT上有没有更好的写法
    q = list;
    p->next = list->next;
    free(q);
     */

    /* 至此形成了题目要求的环 */
    pre = p;           //p现在是第一个字符前的那个字符
    list = list->next; //让list指向第一个字符的节点，即示例中h所在的节点
    int m, h;
    h = list->word; //存一下第一个字母，即例子中的h
    for (p = list; p != p->next;)
    {
        m = p->word; //当前字符的ASCII码                     第一轮：第一个字符的ASCII码，例子中的h           
        pre->next = p->next;        //删除当前字符
                     /* 这里free()的时候报了异常，不知道为什么 */
        p = p->next;                //移动到下一个字符，例子中的e
        for (i = 0; i < m - 1; i++) //继续移动，注意已经移动了1次
        {
            pre = pre->next;
            p = p->next;
        }                 //p现在是移动m次后的那个字母，pre跟着移动，pre最终就是p前面的那个字母
        pas[m] = p->word; //h用移动后的字母编码
        //现在p就是移动后的字母，即例子中的w，pre是o，重复上述过程即可
    }
    pas[p->word] = h; //最后一个字母用第一个编码
}