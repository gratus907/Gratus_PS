#include <bits/stdc++.h>
#define lli long long int
#define bignum (int)1e9
using namespace std;

bitset <24> b;

void remove()
{
	int i;
	scanf("%d",&i);
	b.set(i,0);
}

void check()
{
	int i;
	scanf("%d",&i);
	printf("%d\n",b.test(i));
}

void toggle()
{
	int i;
	scanf("%d",&i);
	b.flip(i);
}

void add()
{
	int i;
	scanf("%d",&i);
	b.set(i);
}

int main()
{
	int m;
	scanf("%d",&m);
	while(m--)
	{
		char action[13];
		scanf("%s",action);

		if (action[0] == 'r')
			remove();
		else if (action[0] == 'c')
			check();
		else if (action[0] == 't')
			toggle();
		else if (action[0] == 'e')
			b.reset();
		else if (action[1] == 'l')
			b.set();
		else if (action[1] == 'd')
			add();
	}
}