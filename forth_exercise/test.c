#include <stdio.h>

int main()
{
   
    int aa[20000];
    int k = 5;



    int cur;

    int appeared = 0;

    for (int i = 0; i < k; i++)
    {
        //判断相等
        if (cur == aa[k])
        {   
            //相等
            appeared = 1;
            break;
        }else
        {
            //不相等
            continue;
        }
    }
    
    if (!appeared)
    {
        //没出现过，就输出
        printf();
        aa[k]=cur;
        k++;
    }
    

    



   return 0;
}
