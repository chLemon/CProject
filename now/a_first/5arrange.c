#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int arr[11];
int res[11];
int N;
void arrange(int D)
{
    if (D == 0)
    {
        int i;
        for (i = 0; i < N - 1; i++)
            printf("%d ", res[i]);
        printf("%d\n", res[N - 1]);
        return;
    }

    int i;
    for (i = 1; i <= N; i++)
    {
        if (arr[i] == 0)
        {
            res[N - D] = i;
            arr[i] = 1;
            arrange(D - 1);
            arr[i] = 0;
        }
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    arrange(N);
    return 0;
}