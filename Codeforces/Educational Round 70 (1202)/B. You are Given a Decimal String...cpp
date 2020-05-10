#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimine("O3")
#define all(x) (x).begin(),(x).end()
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int tb[10][10][10];
int u[2020202];
string str;
int slen;
int chk(int i, int j, int gap)
{
	if (min(i, j) == 0 && gap == 0)
		return 1;
	if (i == 0 && j == 0)
		return (gap==0?1:-1);
	if (i == j)
	{
		int u = 0;
		for (int iter = 1; iter < 13; iter++)
		{
			u = u+i;
			u %= 10;
			if (u==(gap%10))
			{
				return iter;
			}
		}
		return -1;
	}
	if (i*j == 0)
	{
		int p = max(i, j);
		int u = 0;
		for (int iter = 1; iter < 13; iter++)
		{
			u = u+p;
			u %= 10;
			if (u==gap)
			{
				return iter;
			}
		}
		return -1;
	}
	int ans = INT_MAX;
	if (gap == 0)
		gap = 10;
	while(true)
	{
		if (j > i)
			swap(i, j);
		for (int a = gap/i; a>=0; a--)
		{
			if ((gap-(a*i))%j==0)
			{
				int b = (gap-(a*i))/j;
				ans = min(ans, a+b);
			}
		}
		gap += 10;
		if (gap > 1000 && ans == INT_MAX)
			return -1;
		if (gap > 1000)
			return ans;
	}
}

int cnt(int i, int j)
{
	int res = 0;
	for (int id = (u[0]==0); id<slen; id++)
	{
		int tp = tb[i][j][u[id]];
		if (tp==-1)
			return -1;
		res += (tb[i][j][u[id]]-1);
	}
	return res;
}

int anstb[10][10];
int main()
{
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<10; j++)
		{
			for (int k = 0; k<10; k++)
			{
				tb[i][j][k] = chk(i,j,k);
			}
		}
	}
	cin >> str;
	slen = str.length();
	u[0] = str[0]-'0';
	for (int id = 1; id <slen; id++)
	{
		u[id] = (str[id]-'0')-(str[id-1]-'0');
		if (u[id]<0)
			u[id]+=10;
	}
	for (int i = 0; i<10; i++)
		for (int j = 0; j<=i; j++)
			anstb[i][j] = cnt(i, j);
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<10; j++)
		{
			printf("%d ",i>=j?anstb[i][j]:anstb[j][i]);
		}
		printf("\n");
	}
}
