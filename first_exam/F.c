#include <stdio.h>

int main()
{
    int s, a, b, m, area;
    scanf("%d", &s);
    if (s == 3)
    {
        scanf("%d", &a);
        area = a * a;
    }
    if (s == 4)
    {
        scanf("%d%d", &a, &b);
        area = a * b;
    }
    scanf("%d", &m);
    if (area <= m)
    {
        printf("ENJOY YOUR MEAL!");
    }
    else
    {
        printf("FBI WARNING!");
    }

    return 0;
}
