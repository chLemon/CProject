#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    double standard;
    scanf("%lf", &standard);
    int count0 = 0, count1 = 0, count2 = 0, count3 = 0;
    for (int i = 0; i < m; i++)
    {
        double g = 0.0, b = 0.0;
        int lineState = 0;
        int t[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &t[j]);
        }

        for (int j = 0; j < n; j++)
        {
            int s = t[j];
            if (s == 0)
            {
                g += 1;
            }
            else if (s == 1)
            {
                b += 1;
            }
            else if (s == 2)
            {
                lineState = 2;
                break;
            }
            else if (s == 3)
            {
                lineState = 3;
                break;
            }
        }
        if (lineState == 0 && g / n < standard)
        {
            lineState = 1;
        }
        switch (lineState)
        {
        case 0:
            count0++;
            break;
        case 1:
            count1++;
            break;
        case 2:
            count2++;
            break;
        case 3:
            count3++;
            break;
        default:
            break;
        }
    }
    if (count0 / m > standard)
    {
        printf("your factory has produced nice zhujiao !\n");
    }
    else if (count1 > count2 && count1 > count3)
    {
        printf("bad assembly lines !\n");
    }
    else if (count2 > count1 && count2 > count3)
    {
        printf("terribly sweet !\n");
    }
    else if (count3 > count1 && count3 > count1)
    {
        printf("your zhujiao are still raw !\n");
    }

    return 0;
}
