#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct book
{
    char name[50];
    char author[20];
    char pub[30];
    char date[10];
} bookbank[500];

int bookbanksize;
int compar(struct book *b1, struct book *b2);

void get(char name[]);
void insert(struct book new);
void delete(char name[]);
void deleteOne(int i);

/*
  首先应该考虑一下怎么来存放这些书。常用的线性结构有数组和链表。
  数组优点：排序功能实现比较简单，可以直接调用qsort完成
  链表优点：操作中有大量的动态操作，并且查找是根据书名关键字查找，数组在这种查找操作上并不会有太多的优势
  如果考虑到代码的复杂度，应该选择链表；如果考虑到代码的编写难易，选择数组
*/

/*
  这里选择数组进行编码，排序使用qsort。（一般情况下，排序算法最好选择归并排序或者快速排序）
*/
int main(int argc, char const *argv[])
{
    //读入书籍信息，存入bookbank数组中
    /*
    读取文件：有两个函数，fgets(...)可以一行行的读取文件。fscanf(...)可以类似于scanf一行格式化的读取文件。
    */
    FILE *fp = fopen("books.txt", "r");
    int i = 0;
    while (fscanf(fp, "%s %s %s %s", bookbank[i].name, bookbank[i].author, bookbank[i].pub, bookbank[i].date) != EOF)
    {
        i++;
    }
    bookbanksize = i;
    fclose(fp);
    //对读入的书籍信息进行排序
    qsort(bookbank, bookbanksize, sizeof(struct book), compar);
    //然后读入用户的操作，进行处理，具体每个函数的定义见下方
    int op;        //操作
    char name[50]; //删除和查找输入的名字
    while (1)
    {
        //一直循环读入，直到输入0触发return
        scanf("%d", &op);
        switch (op)
        {
        case 0:
        { //这个大括号，是刚刚查到的冷知识：如果在case里面想要定义一个新的变量，就需要加上一个大括号
            //保存并退出
            FILE *foutp = fopen("ordered.txt", "w");
            //TODO 等等写 /* fputs函数或fprintf函数 */
            for (i = 0; i < bookbanksize; i++)
            {
                fprintf(foutp, "%s %s %s %s\n", bookbank[i].name, bookbank[i].author, bookbank[i].pub, bookbank[i].date);
            }
            fclose(foutp);
            return 0;
            break;
        }
        case 1:
        {
            //插入
            //读入书籍信息，封装成一个struct book，然后传入insert函数
            struct book new;
            scanf("%s %s %s %s", new.name, new.author, new.pub, new.date);
            insert(new);
            break;
        }
        case 2: //查找
            scanf("%s", name);
            get(name);
            break;
        case 3: //删除
            scanf("%s", name);
            delete(name);
            break;
        default:
            break;
        }
    }

    return 0;
}

int compar(struct book *b1, struct book *b2)
{
    return strcmp(b1->name, b2->name);
}

//插入操作：找到正确的位置后进行插入，数组版本，线性查找（这里是可以优化成二分法的）
void insert(struct book new)
{
    int i = 0;
    while (strlen(bookbank[i].name) != 0)
    {
        if (strcmp(new.name, bookbank[i].name) > 0)
        {
            i++;
        }
        else
        {
            break;
        }
    }
    //新书应该放在i位置，剩下所有书往后移动一个位置
    int j;
    for (int j = bookbanksize; j > i; j--)
    {
        bookbank[j] = bookbank[j - 1];
    }
    bookbank[i] = new;
    bookbanksize++;
}
//查找操作
void get(char name[])
{
    int i;
    for (i = 0; i < bookbanksize; i++)
    {
        if (strstr(bookbank[i].name, name) != NULL)
        {
            //输出当前行，各占50，20，30，10个字符，左对齐
            printf("%-50s%-20s%-30s%-10s\n", bookbank[i].name, bookbank[i].author, bookbank[i].pub, bookbank[i].date);
        }
    }
}
//删除操作，可优化的点：数组在删除多个元素的时候，后面的一个元素会移动多次，可以全部标记，然后一次性删除并移动
void delete(char name[])
{
    int i;
    for (i = 0; i < bookbanksize; i++)
    {
        if (strstr(bookbank[i].name, name) != NULL)
        {
            deleteOne(i);
            i--; //回退到前面一个，不然会少判断紧跟着的元素
        }
    }
}
void deleteOne(int i)
{
    int j;
    for (j = i; j < bookbanksize; j++)
    {
        bookbank[j] = bookbank[j + 1];
    }
    bookbanksize--;
}