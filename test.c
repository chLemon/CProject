#include <stdio.h>
#include <string.h>

<<<<<<< HEAD
#define MAXLINE 1000

#define EOF 0

enum color{red, yellow};

int ifred(int color);

int main(int argc, char const *argv[]){
    
    int arr[MAXLINE];

    int a = ifred(red);
    int b = ifred(yellow);
    
    printf("%d \n %d", a, b);
    
    
    return 0;
}

int ifred(int color){
    if (color == red)
    {
        return 1;
    }
    return 0;

=======
#define N 550
//数据如何存放，文件读写，数据如何处理，
int n;
struct book
{
    char name[N];
    char author[N];
    char pub[N];
    char data[N];
    int t, d; //t标记出现的时间，d标记是否被删除
} a[550];
int match(char a[], char b[]);
char re[N][N];
char num[N];
int main()
{
    FILE *in, *out;
    in = fopen("books.txt", "r");
    out = fopen("ordered.txt", "w");

    n = 1; //文件读取完成
    while (fscanf(in, "%s%s%s%s", a[n].name, a[n].author, a[n].pub, a[n].data) != EOF)
        n++;

    int op;
    int idx = 0;
    while (scanf("%d", &op), op) //控制端输入完成
    {
        if (op == 1)
        {
            scanf("%s%s%s%s", a[n].name, a[n].author, a[n].pub, a[n].data);
            a[n].t = ++idx;
            n++;
        }
        else
        {
            scanf("%s", re[++idx]);
            num[idx] = op;
        }
    }

    n--; //n为图书的总数目

    //下面第所有的书进行冒泡排序
    int i, j;
    struct book tmp;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            if (strcmp(a[j].name, a[j + 1].name) > 0)
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }

    //下面对重新储存的数组进行查找和删除操作
    for (i = 1; i <= idx; i++)
    {
        if (num[i])
        {
            if (num[i] == 2)
            {
                for (j = 1; j <= n; j++)
                {
                    if (a[j].t < i && !a[j].d && match(a[j].name, re[i]))
                        printf("%-50s%-20s%-30s%-10s\n", a[j].name, a[j].author, a[j].pub, a[j].data);
                }
            }
            else
            {
                for (j = 1; j <= n; ++j)
                    if (a[j].t < i && !a[j].d && match(a[j].name, re[i]))
                        a[j].d = 1;
            }
        }
    }

    for (i = 1; i <= n; ++i)
        if (!a[i].d)
            fprintf(out, "%-50s%-20s%-30s%-10s\n", a[i].name, a[i].author, a[i].pub, a[i].data);

    return 0;
}

int match(char a[], char b[])
{
    int l1 = strlen(a), l2 = strlen(b);
    int i, j;
    for (i = 0; i < l1; i++)
    {
        int f = 1;
        for (j = 0; j < l2; j++)
        {
            if (a[i + j] != b[j])
            {
                f = 0;
                break;
            }
        }
        if (f)
        {
            return 1;
        }
    }
    return 0;
>>>>>>> 0e9a7d60fe19b389e115213075685cb94c8d078e
}