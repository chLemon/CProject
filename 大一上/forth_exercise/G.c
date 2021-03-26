#include <stdio.h>

int main()
{
    int n, m;
    //一个矩形存x的左边界，右边界，上边界，下边界
    scanf("%d %d", &n, &m);
    int squares[4 * n];
    int nodex[m];
    int nodey[m];

    //输入矩阵
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        int xmax, xmin, ymax, ymin;
        if (x1 == x2)
        {
            xmax = x1 > x3 ? x1 : x3;
            xmin = x1 < x3 ? x1 : x3;
        }
        else
        {
            xmax = x1 > x2 ? x1 : x2;
            xmin = x1 < x2 ? x1 : x2;
        }
        if (y1 == y2)
        {
            ymax = y1 > y3 ? y1 : y3;
            ymin = y1 < y3 ? y1 : y3;
        }
        else
        {
            ymax = y1 > y2 ? y1 : y2;
            ymin = y1 < y2 ? y1 : y2;
        }

        squares[4 * i] = xmin;
        squares[4 * i + 1] = xmax;
        squares[4 * i + 2] = ymin;
        squares[4 * i + 3] = ymax;
    }
    //输入数字
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &nodex[i], &nodey[i]);
    }

    //每个矩阵计算
    for (int i = 0; i < n; i++)
    {
        int xmin = squares[4 * i];
        int xmax = squares[4 * i + 1];
        int ymin = squares[4 * i + 2];
        int ymax = squares[4 * i + 3];

        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (nodex[j] >= xmin && nodex[j] <= xmax && nodey[j] >= ymin && nodey[j] <= ymax)
            {
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
