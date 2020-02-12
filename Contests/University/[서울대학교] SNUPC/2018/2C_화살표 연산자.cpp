#include <bits/stdc++.h>
using namespace std;

int c;
int main()
{
	int x, n;
	scanf("%d%d",&x,&n);
	if(n %2 == 1 && n > 1)
	{
		printf("ERROR");
		return 0;
	}
	if (n==1)
	{
		while( 0 < -x )
		{
			c++;
			if (c == 100000)
			{
				printf("INFINITE");
				return 0;
			}
		}
		printf("%d",c);
		return 0;
	}
	while( 0 < (x -=(n/2)) )
	{
		c++;
		if (c == 100000)
		{
			printf("INFINITE");
			return 0;
		}
	}
	printf("%d",c);
	return 0;
}