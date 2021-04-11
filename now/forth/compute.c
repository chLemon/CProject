#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N (100 + 5)

int stacknum[N];
char stackopr[N];
int numtop = -1, oprtop = -1;

int getpriority(char ch)
{
	if (ch == '+' || ch == '-')
		return 1;
	else if (ch == '*' || ch == '/')
		return 2;
	else if (ch == '(')
		return 3;
}

void compr(op)
{
	if (oprtop == -1)
	{
		stackopr[++oprtop] = op;
	}
	else if (op == ')')
	{
		while (stackopr[oprtop] != '(')
		{
			switch (stackopr[oprtop])
			{
			case '+':
				stacknum[numtop - 1] = stacknum[numtop] + stacknum[numtop - 1];
				break;
			case '-':
				stacknum[numtop - 1] = stacknum[numtop] - stacknum[numtop - 1];
				break;
			case '*':
				stacknum[numtop - 1] = stacknum[numtop] * stacknum[numtop - 1];
				break;
			case '/':
				stacknum[numtop - 1] = stacknum[numtop] / stacknum[numtop - 1];
				break;
			case '%':
				stacknum[numtop - 1] = stacknum[numtop] % stacknum[numtop - 1];
				break;
			}
			numtop--;
			oprtop--;
		}
		oprtop--;
	}
	else if (op == '=')
	{
		while (numtop != 0)    //这里判断错了，t和t2的命名就很难看出来
		{
			switch (stackopr[oprtop])
			{
			case '+':
				stacknum[numtop - 1] = stacknum[numtop] + stacknum[numtop - 1];
				break;
			case '-':
				stacknum[numtop - 1] = stacknum[numtop] - stacknum[numtop - 1];
				break;
			case '*':
				stacknum[numtop - 1] = stacknum[numtop] * stacknum[numtop - 1];
				break;
			case '/':
				stacknum[numtop - 1] = stacknum[numtop] / stacknum[numtop - 1];
				break;
			case '%':
				stacknum[numtop - 1] = stacknum[numtop] % stacknum[numtop - 1];
				break;
			}
			numtop--;
			oprtop--;
		}
	}
	else
	{
		while (getpriority(stackopr[oprtop]) >= getpriority(op) && stackopr[oprtop] != '(') 
		{
			switch (stackopr[oprtop])
			{
			case '+':
				stacknum[numtop - 1] = stacknum[numtop] + stacknum[numtop - 1];
				break;
			case '-':
				stacknum[numtop - 1] = stacknum[numtop] - stacknum[numtop - 1];  //顺序反了
				break;
			case '*':
				stacknum[numtop - 1] = stacknum[numtop] * stacknum[numtop - 1];
				break;
			case '/':
				stacknum[numtop - 1] = stacknum[numtop] / stacknum[numtop - 1];   //顺序反了
				break;
			case '%':
				stacknum[numtop - 1] = stacknum[numtop] % stacknum[numtop - 1];    //顺序反了
				break;
			}
			numtop--;
			oprtop--;
			//这样while 是不是会while到stackopr的0位置'\0'，那这个的优先级怎么判断
		}
		stackopr[++oprtop] = op;
	}
}

void compute() //这个函数希望达成的效果是：计算表达式，将最终结果放在stacknum的0位置
{
	stackopr[++oprtop] = '\0'; //这里需要修改，应该推=入栈
	char op;
	int w;
	while(scanf("%c",&op)!=EOF)    
	{
		if(isdigit(op)) 
		{
			w=op-'0';  
			while(scanf("%c",&op)!=EOF&&isdigit(op))  
			{
				w=w*10+(op-'0');       
			}                
			stacknum[++numtop]=w;           
			compr(op);             
		}
		else
		{
			compr(op);
		}
	}
}

int main()
{
	/* 输入输出应该在main里面处理 */
	compute();

	int ans;
	ans = stacknum[0];
	printf("%d", ans);
	return 0;
}
