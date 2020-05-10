#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimine("O3")
#define all(x) (x).begin(),(x).end()
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
	int n;
	scanf("%d",&n);
	if (n<95000)
	{
		for (int i = 0; i<n; i++)
			printf("1");
		printf("337\n");
		return;
	}
	int x = (int)sqrt(n);
	int y = (n-6*x)/x;
	int z = n-(x*y)-(6*x);
	int w = 1;
	for (int i = 0; i<x; i++)
	{
		printf("1");
	}
	printf("33");
	for (int i = 0; i<y; i++)
	{
		printf("7");
	}

	for (int i = 0; i<z; i++)
	{
		printf("1");
	}
	printf("33");
	for (int i = 0; i<w; i++)
	{
		printf("7");
	}
	printf("\n");
	return;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
}
