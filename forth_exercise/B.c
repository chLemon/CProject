#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int q1[n];
    int q2[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q2[i]);
    }

    for (int i = 1; i < n; i++)
    {
        if (q1[i] > q1[i - 1] && q2[i] > q2[i - 1])
        {
            continue;
        }
        else
        {
            int t = q1[i];
            q1[i] = q2[i];
            q2[i] = t;
            if (q1[i] > q1[i - 1] && q2[i] > q2[i - 1])
            {
                continue;
            }
            else
            {
                printf("no");
                return 0;
            }
        }
    }
    printf("yes");
    return 0;
}
