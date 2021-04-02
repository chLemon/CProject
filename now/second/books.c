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

int get(char name[]);
void insert(struct book new);
void delete (struct book old);

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
    //对读入的书籍信息进行排序
    qsort(bookbank, bookbanksize, sizeof(struct book), compar);
    //然后读入用户的操作，进行处理，具体每个函数的定义见下方
    int op;         //操作
    char iarg[110]; //输入的其他东西，input argument
    while (1)
    {
        //一直循环读入，直到输入0触发return
        scanf("%d", &op);
        switch (op)
        {
        case 0: //保存并退出
            FILE *foutp = fopen("ordered.txt", "w");
            //TODO 等等写 /* fputs函数或fprintf函数 */
            return;
            break;
        case 1: //插入
            //读入书籍信息，封装成一个struct book，然后传入insert函数
            break;
        case 2: //查找
            //查找到第一个匹配的位置，然后
            break;
        case 3: //删除

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

/*
  然后规定一下插入、删除、查找函数的语义（输入和返回值）：
  query:题目要求的查找功能
    输入：书名或书名关键字
    输出：
  get:用于插入和删除的查找
    输入：书名
    输出：返回第一个匹配的下标。如果没有匹配的，则返回第一个大于它的名字的位置（这个返回值设置是为了方便insert函数的，这里返回的值刚好就是应该插入的位置）
  insert:插入
    输入：book
    输出：无
  delete:删除
    输入：书名或书名关键字
    输出：无
*/

//查找，这里用线性查找（数组其实可以优化为二分查找）
int get(char name[])
{
    int i = 0;
    while (strlen(bookbank[i].name) != 0)
    {
        if (strcmp(name, bookbank[i].name) >= 0) //等于0表示刚好相等。如果name大于了i位置的name，则无需查找，说明不存在
        {
            return i;
        }
    }
}
//插入操作：找到正确的位置后进行插入，数组版本，线性查找（这里是可以优化成二分法的）
void insert(struct book new)
{
    int i = get(new.name);
    //新书应该放在i位置，剩下所有书往后移动一个位置
    int j;
    for (int j = bookbanksize; j > i; j--)
    {
        bookbank[j] = bookbank[j - 1];
    }
    bookbank[i] = new;
    bookbanksize++;
}
//删除操作：找到正确的位置后进行插入，数组版本，线性查找（这里是可以优化成二分法的）
void delete (struct book old)
{
    int i = get(old.name);
    int j;
    for (j = i; j < bookbanksize; j++)
    {
        bookbank[j] = bookbank[j + 1];
    }
    bookbanksize--;
}