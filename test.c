#include <stdio.h>

char p[21];
int mark[10] = {0};
int N;
void rearrange(int m, int n);

int main()
{
    scanf("%d", &N);
    rearrange(0, N);
    return 0;
}

void rearrange(int m, int n)
{
    int i;

    if (n == 0)
    {
        p[m] = '\0';
        puts(p);
        return;
    }

    for (i = 1; i <= N; i++)
    {
        if (mark[i] == 0)
        {
            mark[i] = 1;
            p[m] = '0' + i;
            p[m + 1] = ' ';
            rearrange(m + 2, n - 1);
            mark[i] = 0;
        }
    }
}