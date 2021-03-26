#include <stdio.h>
int main()
{
  int n, m, k, a, b, c;

  while (scanf("%d %d %d", &n, &m, &k) != EOF)
  {
    scanf("%d %d %d", &a, &b, &c);
    if (n == a && m == b && k == c)
    {
      printf("fu zhi zhan tie bu xiang ma\n");
      continue;
    }
    if (k == c)
    {
      printf("zong you ren yao yong jian pan ai ge qiao\n");
      continue;
    }

    if (n == a && m == b)
    {
      printf("Ctrl+C/V tian xia di yi\n");
      continue;
    }

    int x, y, z;
    x = ((n - a) * (n - a) + (m - b) * (m - b)); //yuanxinju
    y = ((k + c) * (k + c));                     //和
    z = ((k - c) * (k - c));                     //cha
    if (x < z)
    {
      printf("zhe ci ying gai dou hui fu zhi le ba\n");
      continue;
    }

    if (x == z)
    {
      printf("oo00OO00ooo0OO0oo0OooO00oo\n");
      continue;
    }

    if (z < x && x < y)
    {
      printf("lIllIIlI11lIIIlIl1l1111\n");
      continue;
    }

    if (x == y)
    {
      printf("rrnnmnrmrnmrnrmnrmrnrm\n");
      continue;
    }

    if (y < x)
    {
      printf("qpgqopgqopgopqgpqggqpoogoo\n");
      continue;
    }
  }
  return 0;
}