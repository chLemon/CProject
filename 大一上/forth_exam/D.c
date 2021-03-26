#include <stdio.h>
int calD2(int x1, int x2, int y1, int y2);
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int x[n], y[n];
    int X[k], Y[k];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &X[i], &Y[i]);
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int minD2 = 1e7;
        for (int j = 0; j < k; j++)
        {
            int D2 = calD2(x[i], X[j], y[i], Y[j]);
            if (minD2 > D2)
            {
                minD2 = D2;
            }
        }
        result += minD2;
    }
    printf("%d", result);
    return 0;
}
int calD2(int x1, int x2, int y1, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
