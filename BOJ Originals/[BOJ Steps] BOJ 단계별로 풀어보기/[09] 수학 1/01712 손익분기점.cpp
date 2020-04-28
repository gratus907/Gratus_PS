#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d %d %d",&a,&b,&c);
	if (b>=c)
	{
		printf("-1");
		return 0;
	}
	double ad=(double)a, bd = (double)b, cd=(double)c;
	double k = ad/(cd-bd);
	int t = a/(c-b);
	if (t == k)
	{
		printf("%d",t+1);
		return 0;
	}
	int u = (int)ceil(k);
	printf("%d",u);
}