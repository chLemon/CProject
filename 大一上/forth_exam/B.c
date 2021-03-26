#include <stdio.h>
double mypow(double a, int b);
int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                double s;
                s = 1.0 + 0.01 * (j+1);
                double r;
                r = mypow(s, i + 1);
                printf("%.4lf ", r);
            }
            printf("\n");
        }
    }
    return 0;
}
double mypow(double a, int b)
{
    double result = 1.0;
    for (int i = 0; i < b; i++)
    {
        result *= a;
    }
    return result;
}