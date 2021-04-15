#include <stdio.h>

#define isin(i) i >= 0 && i <= 18

int judge(int chess[19][19]);
//设置成全局变量不用传参数
int chess[19][19];
int win_i;
int win_j;

int main()
{
    //读取输入
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++)
            scanf("%d", &chess[i][j]);
    int win = judge(chess);
    if (win == 0)
        printf("No\n");
    else
        printf("%d:%d,%d", win, win_i + 1, win_j + 1);
    printf("\n");
    return 0;
}

int judge(int chess[19][19])
{
    int k;
    for (int i = 0; i < 19; i++)     //i是行
        for (int j = 0; j < 19; j++) //j是列   //从0，0开始
        {
            if (chess[i][j] == 0) //当前格有没有棋子在
                continue;
            //横着
            if (i + 4 < 19 &&)
            {
                /* code */
            }

            win_i = i;
            win_j = j;
            return chess[i][j]; //返回当前棋子的颜色

            //竖着
            for (k = 1; k < 4; k++)
            {
                if (i + k > 18 || chess[i][j] != chess[i + k][j])
                    break;
                if (k == 4 && ((i > 1 && chess[i - 1][j] == 0) || (chess[i + 4][j] == 0 && i < 15))) //有4个，且有空位
                {
                    win_i = i;
                    win_j = j;
                    return chess[i][j]; //返回当前棋子的颜色
                }
            }
            //右斜着
            for (k = 1; k < 4; k++)
            {
                if (i + k > 18 || j + k > 18 || chess[i][j] != chess[i + k][j + k])
                    break;
                if (k == 4 && ((i > 1 && j > 1 && chess[i - 1][j - 1] == 0) || (chess[i + 4][j + 4] == 0 && i < 15 && j < 15))) //有4个，且有空位
                {
                    win_i = i;
                    win_j = j;
                    return chess[i][j]; //返回当前棋子的颜色
                }
            }
            //左斜，左下角的棋子为起始位置
            for (k = 1; k < 4; k++)
            {
                if (i - k < 0 || j + k > 18 || chess[i][j] != chess[i - k][j + k])
                    break;
                if (k == 4 && ((i < 18 && j > 1 && chess[i + 1][j - 1] == 0) || (chess[i - 4][j + 4] == 0 && i > 1 && j < 15))) //有4个，且有空位
                {
                    win_i = i;
                    win_j = j;
                    return chess[i][j]; //返回当前棋子的颜色
                }
            }
        }
    return 0; //全都失败
}
