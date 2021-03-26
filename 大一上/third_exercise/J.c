#include <stdio.h>
/*
暴力解法
*/
int isOrdered(int p[], int n);
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        //每一组
        int n;
        scanf("%d", &n);
        int p[n];
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &p[i]);
        }
        //读取完了数据

        while (!isOrdered(p, n))
        {
            int pre, cur, next, changed = 0;
            for (int i = 1; i < n - 1; i++)
            {
                pre = p[i - 1];
                cur = p[i];
                next = p[i + 1];
                if (pre > cur && cur > next)
                {
                    int t = p[i - 1];
                    p[i - 1] = p[i + 1];
                    p[i + 1] = t;
                    result++;
                    changed = 1;
                }
            }
            if (changed)
            {
                break;
            }
        }
        if (!isOrdered(p, n))
        {
            printf("%d", result);
        }
        else
        {
            printf("-1");
        }
    }
    return 0;
}
int isOrdered(int p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (p[i] > p[i + 1])
        {
            return 0;
        }
    }

    return 1;
}