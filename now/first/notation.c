#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    //输入分析：只有一行一个小数，直接用一个字符串读入即可，字符数不超过100
    char input[105];
    gets(input);
    //输入数据：没有符号，小数点前后必有数字，没有无效0，数字有意义。转换成科学计数法后输出
    //思路：这题很耿直了，直接找到第一个不为0的数字，输出后加个小数点，然后一直把剩下数字原样输出。加上0.000000000000002e，e后跟的值为小数点和第一个不为0的数字之间的下标差计算出来
    int i, dol = 0, first = 0, flag = 0; // i为循环变量，dol记录小数点的下标，first记录第一个非0数的下标，flag表示是否已经遇到非0数
    for (i = 0; i < strlen(input); i++)
    {
        char c = input[i];
        if (flag) //如果已经遇到了非0数，原样输出即可
        {
            if (c == '.')
            {
                dol = i;
            }
            else
            {

                printf("%c", c);
            }
        }
        else //至今还都是0
        {
            if (c == '.') //如果遇到了小数点，记录小数点下标
            {
                dol = i;
            }
            else if (c != '0') //如果不是小数点，且不是0，即遇到了第一个非0数
            {
                first = i;
                flag = 1;
                if (i == strlen(input) - 1)
                {
                    printf("%c", c);
                }
                else
                {
                    printf("%c.", c);
                }
            } //如果是0什么都不干，i++即可
        }
    }
    int e = dol - first;
    printf("e%d", e > 0 ? e - 1 : e);

    return 0;
}