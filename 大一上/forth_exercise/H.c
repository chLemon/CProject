#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        long long n;
        scanf("%lld", &n);

        //经过计算，n <= 27 时 1； <= 29 2 ; <= 678 3; 17769 4; <= 914188 5; 6

        if (n <= 27)
        {
            printf("1");
        }
        else if (n <= 29)
        {
            printf("2");
        }
        else if (n <= 678)
        {
            printf("3");
        }
        else if (n <= 17769)
        {
            printf("4");
        }
        else if (n <= 914188)
        {
            printf("5");
        }
        else
        {
            printf("6");
        }
        printf("\n");
    }

    return 0;
}
// long long A(int n)
// {
//     long long temp1 = n * (n - 1);
//     if (temp1 < n)
//     {
//         return -3;
//     }
//     long long result = temp1 * (n - 2);

//     return result > temp1 ? result : -3;
// }
// long long C(int n)
// {
//     long long t1 = n * (n - 1);
//     if (t1 < n)
//     {
//         return -2;
//     }
//     long long t2 = t1 * (n - 2);
//     if (t2 < t1)
//     {
//         return -2;
//     }
//     long long t3 = t2 * (n - 3);
//     if (t3 < t2)
//     {
//         return -2;
//     }

//     return t3 / 24;
// }
