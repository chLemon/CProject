#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX (500+5)
#define N (100+5)
char pri[N][N];
int num[N];
char opr[N];
int t=-1,top2=-1;

int getpriority(char ch)
{
	if(ch=='+'||ch=='-')return 1;
	else if(ch=='*'||ch=='/')return 2;
	else if(ch=='(')return 3;
} 

void compr(op)
{
	if(top2==-1)
	{
		opr[++top2]=op;
	}
	else if(op==')')
	{
		while(opr[top2]!='(')
		{
			switch(opr[top2])
			{
				case '+':
				num[t-1]=num[t]+num[t-1];
				break;
				case '-':
				num[t-1]=num[t]-num[t-1];
				break;
				case '*':
				num[t-1]=num[t]*num[t-1];
				break;
				case '/':
				num[t-1]=num[t]/num[t-1];
				break;
				case '%':
				num[t-1]=num[t]%num[t-1];
				break;	
			}
			t--;
			top2--;
		}
		top2--;
	}
	else if(op=='=')
	{
		while(t!=0)
		{
			switch(opr[top2])
				{
					case '+':
					num[t-1]=num[t]+num[t-1];
					break;
					case '-':
					num[t-1]=num[t]-num[t-1];
					break;
					case '*':
					num[t-1]=num[t]*num[t-1];
					break;
					case '/':
					num[t-1]=num[t]/num[t-1];
					break;
					case '%':
					num[t-1]=num[t]%num[t-1];
					break;	
				}
				t--;
			top2--;
		}
	}
	else
	{
		while(getpriority(opr[top2])>=getpriority(op)&&opr[top2]!='(')
		{
			switch(opr[top2])
				{
					case '+':
					num[t-1]=num[t]+num[t-1];
					break;
					case '-':
					num[t-1]=num[t]-num[t-1];
					break;
					case '*':
					num[t-1]=num[t]*num[t-1];
					break;
					case '/':
					num[t-1]=num[t]/num[t-1];
					break;
					case '%':
					num[t-1]=num[t]%num[t-1];
					break;	
				}
				t--;
			top2--;
		}
		opr[++top2]=op;
	}
}

void compute()
{
	opr[++top2]='\0';
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
			t++;
			num[t]=w;
			compr(op);
		}
		else
		{
			compr(op);
		}
	}
}

int main ()
{
	compute();
	
	int ans;
	ans=num[0];
	printf("%d",ans);
	return 0;
}
