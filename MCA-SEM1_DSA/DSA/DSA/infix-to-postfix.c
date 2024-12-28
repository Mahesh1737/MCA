#include<stdio.h>
#include<string.h>

#define MAX 100

void push(char);
char pop();

int instackp();
int incomingp(char);

char ch,stack[MAX];
int top = -1;

int main()
{
	char inf[MAX],post[MAX];
	int i,k=0;
	int isp,icp;

	printf("\nEnter the Infix Expression : ");
	scanf("%s",&inf);

	for(i=0;inf[i]!='\0';i++)
	{
		if(inf[i] != '+' && inf[i] != '-' && inf[i] != '*' && inf[i] != '/' && inf[i] != '%' && inf[i] != '^' && inf[i] != '$' && inf[i] != '(' && inf[i] != ')')
		{
			post[k] = inf[i];
			k++;
			continue;
		}

		if(inf[i] == '(')
		{
			push('(');
			continue;
		}

		if(inf[i] == ')')
		{
			ch = pop();

			while(ch != '(')
			{
				post[k] = ch;
				k++;
				ch = pop();
			}
		}
		else if(inf[i] == '+' || inf[i] == '-' || inf[i] == '*' || inf[i] == '/' || inf[i] == '%' || inf[i] == '^' || inf[i] == '$')
		{
			if(top == -1)
			{
				push(inf[i]);
				continue;
			}

			isp = instackp();
			icp = incomingp(inf[i]);

			while(isp >= icp)
			{
				post[k] = pop();
				k++;

				isp = instackp();
			}

			if(icp > isp)
			{
				push(inf[i]);
			}
		}
	}

	while(top != -1)
	{
		post[k] = pop();
		k++;
	}

	post[k] = '\0';

	printf("Postfix Expr : %s",post);

	return 0;
}

void push(char ch)
{
	stack[++top] = ch;
}

char pop()
{
	return(stack[top--]);
}

int instackp()
{
	char op;

	op = stack[top];

	switch(op)
	{
		case '+':
		case '-': return 1;

		case '*':
		case '/':
		case '%': return 2;

		case '^':
		case '$': return 3;

		default : return -1;
	}
}

int incomingp(char ch)
{
	switch(ch)
	{
		case '+':
		case '-': return 1;

		case '*':
		case '/':
		case '%': return 2;

		case '^':
		case '$': return 3;

	}
}
