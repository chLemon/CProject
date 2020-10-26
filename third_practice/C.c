#include <stdio.h>
int main(int argc, char const *argv[])
{

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        //each group
        int numberType;
        scanf("%d", &numberType);

        if (numberType == 1)
        {
            int a, b, c;
            scanf("%d", &a);
            scanf("%d", &b);
            c = a + b;
            printf("%d", c);
        }
        else if (numberType == 2)
        {
            long long a, b, c;
            //TODO
        }
        else if (numberType == 3)
        {
            double a, b, c;
            //TODO
        }
    }

    return 0;
}
