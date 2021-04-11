#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX (500 + 5) //为什么是500+5？
#define N (100 + 5)	  //这是啥
char stc[MAX];
char row[MAX], all[MAX];
int top = -1;
void push(char ch);
void pop();
int isempty();
int main()
{
	FILE *fp;
	fp = fopen("example.txt", "r");

	int i = 0, j = 0;
	int line = 1;
	while ((row[i++] = fgetc(fp)) != EOF)
	{
		//没有字符常量和字符串常量的处理
		if (row[i] == '\n')
			line++;
		else if ((row[i] == '/' && row[i - 1] == '/') || (row[i] == '*' && row[i - 1] == '/'))
		{
			int flag = line;//不要乱起名字
			row[i++] = fgetc(fp);
			if (line != (flag + 1) || (row[i] != '/' || row[i - 1] != '/') || (row[i] != '*' || row[i - 1] != '/'))
				continue;//这里什么意思，没有看懂
		}
		else
		{
			if (row[i] == '(')
			{
				push(row[i]);
				all[j++] = row[i];
			}
			else if (row[i] == ')')
			{
				all[j++] = row[i];
				if (!isempty(stc) && stc[top] == '(')
					pop();
				else
				{
					printf("without maching '(' at line %d", line);
					return 0;
				}
			}

			if (row[i] == '{')
			{
				push(row[i]);
				all[j++] = row[i];
			}
			else if (row[i] == '}')
			{
				all[j++] = row[i];
				if (!isempty(stc) && stc[top] == '{')
					pop();
				else
				{
					printf("without maching '{' at line %d", line);
					return 0;
				}
			}
		}
	}
	if (!isempty(stc))
	{
		if (stc[top] == '{')
			printf("without maching '}' at line %d", line);//这个line是几了？
		else
			printf("without maching ')' at line %d", line);
	}
	else
	{
		for (i = 0; i < strlen(all); i++)
		{
			printf("%c", all[i]);
		}
	}
	return 0;
}

void push(char ch)
{
	stc[++top] = ch;
}

void pop()
{
	top--;
}

int isempty()
{
	return top == -1;
}
