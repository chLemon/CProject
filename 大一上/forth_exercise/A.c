#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int m[2 * n];
    for (int i = 0; i < n; i++)
    {
        //each group
        int L, R;
        scanf("%d %d", &L, &R);

        m[2 * i] = L;
        m[2 * i + 1] = R;
        for (int j = L; j <= R; j++)
        {
            //judge if the j appeared
            int appeared = 0;
            for (int k = 0; k < i; k++)
            {
                if (j >= m[k * 2] && j <= m[k * 2 + 1])
                {
                    appeared = 1;
                }
            }
            if (appeared)
            {
                continue;
            }

            int count2 = 0, count0 = 0, count7 = 0, count3 = 0;
            int now = j;
            while (now)
            {
                int cur = now % 10;
                now /= 10;
                switch (cur)
                {
                case 2:
                    count2++;
                    break;
                case 0:
                    count0++;
                    break;
                case 7:
                    count7++;
                    break;
                case 3:
                    count3++;
                    break;
                default:
                    break;
                }
            }
            int sum = count2 + count0 + count7 + count3;
            if (sum == 0 || sum == 2 || sum == 3 || sum == 7)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}
