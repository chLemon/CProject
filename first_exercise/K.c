#include <stdio.h>
#include <math.h>
//WA
int main()
{
    int x;
    scanf("%d", &x);

    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            printf("No");
            return 0;
        }
    }

    printf("Yes");
    return 0;
}
