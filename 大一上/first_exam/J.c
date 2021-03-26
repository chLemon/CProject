#include <stdio.h>

int main()
{
    int n, x, pos=0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (pos + x <= 50 && pos + x >= -50)
        {
            pos = pos + x;
        }
        else
        {
            printf("can't move, touch fish.\n");
        }
    }
    printf("%d", pos);

    return 0;
}
