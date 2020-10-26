#include <stdio.h>
int main(int argc, char const *argv[])
{
    int L, n;
    scanf("%d", &L);
    scanf("%d", &n);

    int lengths[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &lengths[i]);
    }

    int count = 0;
    int sum = 1;
    for (int i = 0; i < n; i++)
    {
        sum += lengths[i];
        if (sum == L)
        {
            //如果刚好是一页
            count++;
            sum = 0;
        }
        else if (sum > L)
        {
            //如果加上当前页后会超过L，则说明应该往上划一下
            //然后再划一下，跳过当前页
            count += 2;
            sum = 0;
        }
    }
    printf("%d", count);
    return 0;
}
