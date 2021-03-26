#include <stdio.h>
int judgeType(int a[5]);
int compare0(int a[5], int b[5]);
int compare1(int a[5], int b[5]);
int compare2(int a[5], int b[5]);
int compare3(int a[5], int b[5]);
int compare4(int a[5], int b[5]);
int compare5(int a[5], int b[5]);
int compare6(int a[5], int b[5]);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int alice[5], bob[5];
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &alice[j]);
        }
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &bob[j]);
        }
        int statusAlice, statusBob;
        statusAlice = judgeType(alice);
        statusBob = judgeType(bob);

        if (statusAlice < statusBob)
        {
            printf("Alice");
        }
        else if (statusAlice > statusBob)
        {
            printf("Bob");
        }
        else
        {
            //类型相同
            int bigger; //0 Alice 1 Bob 2 Tie
            switch (statusAlice)
            {
            case 0:
                bigger = compare0(alice,bob);
                break;
            case 1:
                bigger = compare1(alice,bob);
                break;
            case 2:
                bigger = compare2(alice,bob);
                break;
            case 3:
                bigger = compare3(alice,bob);
                break;
            case 4:
                bigger = compare4(alice,bob);
                break;
            case 5:
                bigger = compare5(alice,bob);
                break;
            case 6:
                bigger = compare6(alice,bob);
                break;
            default:
                break;
            }
            switch (bigger)
            {
            case 0:
                printf("Alice");
                break;
            case 1:
                printf("Bob");
                break;
            case 2:
                printf("Tie");
            default:
                break;
            }
        }
    }

    return 0;
}
/*
//0 Alice 1 Bob 2 Tie
*/
int compare0(int a[5], int b[5])
{
    int fourA, fourB, sA, sB;
    if (a[0] == a[1])
    {
        fourA = a[0];
        sA = a[5];
    }
    else
    {
        fourA = a[1];
        sA = a[0];
    }
    if (b[0] == b[1])
    {
        fourB = b[0];
        sB = a[5];
    }
    else
    {
        fourB = b[1];
        sB = a[0];
    }

    if (fourA > fourB)
    {
        return 0;
    }
    else if (fourA < fourB)
    {
        return 1;
    }
    else
    {
        if (sA > sB)
        {
            return 0;
        }
        else if (sA < sB)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
}
//0 Alice 1 Bob 2 Tie
int compare1(int a[5], int b[5])
{
    int threea, threeb, twoa, twob;

    if (a[1] == a[2])
    {
        threea = a[0];
        twoa = a[3];
    }
    else
    {
        threea = a[2];
        twoa = a[0];
    }
    if (b[1] == b[2])
    {
        threeb = b[0];
        twob = b[3];
    }
    else
    {
        threeb = b[2];
        twob = b[0];
    }

    if (threea > threeb)
    {
        return 0;
    }
    else if (threea < threeb)
    {
        return 1;
    }
    else
    {
        if (twoa > twob)
        {
            return 0;
        }
        else if (twoa < twob)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
}
int compare2(int a[5], int b[5])
{
    if (a[4] > b[4])
    {
        return 0;
    }
    else if (a[4] < b[4])
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
int compare3(int a[5], int b[5])
{
    int threea, smalla, biga, threeb, smallb, bigb;
    if (a[0] == a[1] && a[1] == a[2])
    {
        threea = a[0];
        smalla = a[3];
        biga = a[4];
    }
    else if (a[1] == a[2] && a[2] == a[3])
    {
        threea = a[1];
        smalla = a[0];
        biga = a[4];
    }
    else if (a[2] == a[3] && a[3] == a[4])
    {
        threea = a[2];
        smalla = a[0];
        biga = a[1];
    }

    if (b[0] == b[1] && b[1] == b[2])
    {
        threeb = b[0];
        smallb = b[3];
        bigb = b[4];
    }
    else if (b[1] == b[2] && b[2] == b[3])
    {
        threeb = b[1];
        smallb = b[0];
        bigb = b[4];
    }
    else if (b[2] == b[3] && b[3] == b[4])
    {
        threeb = b[2];
        smallb = b[0];
        bigb = b[1];
    }

    if (threea > threeb)
    {
        return 0;
    }
    else if (threea < threeb)
    {
        return 1;
    }
    else
    {
        if (biga > bigb)
        {
            return 0;
        }
        else if (biga < bigb)
        {
            return 1;
        }
        else
        {
            if (smalla > smallb)
            {
                return 0;
            }
            else if (smalla < smallb)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
}
int compare4(int a[5], int b[5])
{
    //两对
    int two1a, two2a, sa, two1b, two2b, sb;
    if (a[0] == a[1])
    {
        two1a = a[0];
        if (a[2] == a[3])
        {
            two2a = a[2];
            sa = a[4];
        }
        else
        {
            two2a = a[3];
            sa = a[2];
        }
    }
    else
    {
        sa = a[0];
        two1a = a[1];
        two2a = a[3];
    }

    if (b[0] == b[1])
    {
        two1b = b[0];
        if (b[2] == b[3])
        {
            two2b = b[2];
            sb = b[4];
        }
        else
        {
            two2b = b[3];
            sb = b[2];
        }
    }
    else
    {
        sb = b[0];
        two1b = b[1];
        two2b = b[3];
    }

    if (two2a > two2b)
    {
        return 0;
    }
    else if (two2a < two2b)
    {
        return 1;
    }
    else
    {
        if (two1a > two1b)
        {
            return 0;
        }
        else if (two1a < two1b)
        {
            return 1;
        }
        else
        {
            if (sa > sb)
            {
                return 0;
            }
            else if (sa < sb)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
}

int compare5(int a[5], int b[5])
{
    int ta, za, xa, ca, tb, zb, xb, cb;

    if (a[0] == a[1])
    {
        ta = a[0];
        za = a[2];
        xa = a[3];
        ca = a[4];
    }
    else if (a[1] == a[2])
    {
        ta = a[1];
        za = a[0];
        xa = a[3];
        ca = a[4];
    }
    else if (a[2] == a[3])
    {
        ta = a[2];
        za = a[0];
        xa = a[1];
        ca = a[4];
    }
    else if (a[3] == a[4])
    {
        ta = a[3];
        za = a[0];
        xa = a[1];
        ca = a[2];
    }

    if (b[0] == b[1])
    {
        tb = b[0];
        zb = b[2];
        xb = b[3];
        cb = b[4];
    }
    else if (b[1] == b[2])
    {
        tb = b[1];
        zb = b[0];
        xb = b[3];
        cb = b[4];
    }
    else if (b[2] == b[3])
    {
        tb = b[2];
        zb = b[0];
        xb = b[1];
        cb = b[4];
    }
    else if (b[3] == b[4])
    {
        tb = b[3];
        zb = b[0];
        xb = b[1];
        cb = b[2];
    }

    if (ta > tb)
    {
        return 0;
    }
    else if (ta < tb)
    {
        return 1;
    }
    else
    {
        if (ca > cb)
        {
            return 0;
        }
        else if (ca < cb)
        {
            return 1;
        }
        else
        {
            if (xa > xb)
            {
                return 0;
            }
            else if (xa < xb)
            {
                return 1;
            }
            else
            {
                if (za > zb)
                {
                    return 0;
                }
                else if (za < zb)
                {
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
        }
    }
}
int compare6(int a[5], int b[5])
{
    if (a[4] > b[4])
    {
        return 0;
    }
    else if (a[4] < b[4])
    {
        return 1;
    }
    else
    {
        if (a[3] > b[3])
        {
            return 0;
        }
        else if (a[3] < b[3])
        {
            return 1;
        }
        else
        {
            if (a[2] > b[2])
            {
                return 0;
            }
            else if (a[2] < b[2])
            {
                return 1;
            }
            else
            {
                if (a[1] > b[1])
                {
                    return 0;
                }
                else if (a[1] < b[1])
                {
                    return 1;
                }
                else
                {
                    if (a[0] > b[0])
                    {
                        return 0;
                    }
                    else if (a[0] < b[0])
                    {
                        return 1;
                    }
                    else
                    {
                        return 2;
                    }
                }
            }
        }
    }
}

int judgeType(int a[5])
{
    /*
四条：0  
葫芦：1  
顺子：2  
三条：3  
两对：4  
一对：5  
散牌：6
*/
    if ((a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) || (a[1] == a[2] && a[2] == a[3] && a[3] == a[4]))
    {
        return 0;
    }

    if ((a[0] == a[1] && a[2] == a[3] && a[3] == a[4]) || (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]))
    {
        return 1;
    }
    if (a[0] + 1 == a[1] && a[1] + 1 == a[2] && a[2] + 1 == a[3] && a[3] + 1 == a[4])
    {
        return 2;
    }
    if ((a[0] == a[1] && a[1] == a[2]) || (a[1] == a[2] && a[2] == a[3]) || (a[2] == a[3] && a[3] == a[4]))
    {
        return 3;
    }
    if ((a[0] == a[1] && a[2] == a[3]) || (a[0] == a[1] && a[3] == a[4]) || (a[1] == a[2] && a[3] == a[4]))
    {
        return 4;
    }
    if ((a[0] == a[1]) || (a[1] == a[2]) || (a[2] == a[3]) || (a[3] == a[4]))
    {
        return 5;
    }
    return 6;
}
