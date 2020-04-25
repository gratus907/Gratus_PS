#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int in_stack[200020];
int top_stack;
int big_pushed; // biggest number pushed ever
char command[200020];
int seq[200020];
int comnum;
vector <int> popedseq;
int push_to_stack(int i)
{
	if (in_stack[i] == 0)
	{
		in_stack[i] =1;
		if (i > big_pushed)
			big_pushed = i;
		command[comnum] = '+';
		comnum++;
		top_stack = i;
	}
}

int pop_from_stack()
{
	int u = top_stack;
	if (in_stack[top_stack]==1)
		in_stack[top_stack] = 0;
	else
		return 0;
	command[comnum] = '-';
	comnum++;
	while(in_stack[top_stack] == 0)
		top_stack--;
	return u;
}

void print_com()
{
	for (int i = 0; i<comnum; i++)
		printf("%c\n",command[i]);
}

int main()
{
	int t,y=1;
	scanf("%d",&t);
	for (int i =0; i<t; i++)
	{
		int x;
		scanf("%d",&x);
		seq[i]=x;
	}
	for (int i = 0; i<t; i++)
	{
		while (big_pushed<seq[i])
		{
			push_to_stack(y);
			y++;
		}
		if (top_stack == seq[i])
		{
			int poped = pop_from_stack();
			popedseq.push_back(poped);
		}
	}
	for (int i = 0; i<t; i++)
	{
		if (popedseq[i] != seq[i])
		{
			printf("NO");
			return 0;
		}
	}
	print_com();
}