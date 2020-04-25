#include <cstdio>
#include <string>
#include <string.h>
using namespace std;


int ptr;
int ce = 1;

int stack[10002];

void push(int x)
{
	ptr++;
	stack[ptr] = x;
	ce = 0;
}

void pop()
{
	if (ce == 0)
	{
		printf("%d\n", stack[ptr]);
	}
	else
	{
		printf("-1\n");
	}
	ptr--;
	if (ptr <= 0)
	{
		ptr = 0;
		ce = 1;
	}
}

void size()
{
	if (ce == 1)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", ptr);
	}
}

void empty()
{
	if (ce == 1)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
}

void top()
{
	if (ce == 1)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", stack[ptr]);
	}
}
int main()
{
	int x;
	char str[8];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &str);
		if (strcmp(str, "push") == 0)
		{
			scanf("%d", &x);
			push(x);
		}
		else if (strcmp(str, "pop") == 0)
		{
			pop();
		}
		else if (strcmp(str, "size") == 0)
		{
			size();
		}
		else if (strcmp(str, "empty") == 0)
		{
			empty();
		}
		else if (strcmp(str, "top") == 0)
		{
			top();
		}
	}

}