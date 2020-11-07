#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int n;
        int win = 1;
        scanf("%d", &n);
        int a[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }

        int state = a[0];
        for (int j = 1; j < n; j++)
        {
            state--;
            if (state < 0)
            {
                win = 0;
                break;
            }
            state = a[j] > state ? a[j] : state;
        }
        if (win)
        {
            printf("Completed!\n");
        }
        else
        {
            printf("You lose!\n");
        }
    }

    return 0;
}
