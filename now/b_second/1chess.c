#include <stdio.h>

#define isin(i) (i >= 0 && i <= 18)
#define alleql(a1, a2, b1, b2, c1, c2, d1, d2) (chess[a1][a2] == chess[b1][b2] && chess[b1][b2] == chess[c1][c2] && chess[c1][c2] == chess[d1][d2])
#define isempty(i, j) (i >= 0 && i <= 18 && chess[i][j] == 0)
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
            if ((isin(i + 4) && alleql(i, j, i + 1, j, i + 2, j, i + 3, j) && (isempty(i - 1, j) || isempty(i + 4, j)))                                        //横着
                || (isin(j + 4) && alleql(i, j, i, j + 1, i, j + 2, i, j + 3) && (isempty(i, j - 1) || isempty(i, j + 4)))                                     //竖着
                || (isin(i + 4) && isin(j + 4) && alleql(i, j, i + 1, j + 1, i + 2, j + 2, i + 3, j + 3) && (isempty(i - 1, j - 1) || isempty(i + 4, j + 4)))  //右下斜
                || (isin(i + 4) && isin(j - 4) && alleql(i, j, i + 1, j - 1, i + 2, j - 2, i + 3, j - 3) && (isempty(i - 1, j + 1) || isempty(i + 4, j - 4)))) //右上斜
            {
                win_i = i;
                win_j = j;
                return chess[i][j]; //返回当前棋子的颜色
            }
        }
    return 0; //全都失败
}
