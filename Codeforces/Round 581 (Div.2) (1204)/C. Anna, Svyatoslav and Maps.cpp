#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
#define INF 987654321
int graph[120][120];
int dist[120][120];
int path[1010101];
int n, m;
vector <int> goodsub;
void Floyd_Warshall()
{
	for (int i = 1; i<=n; i++)
		for (int j = 1; j<=n; j++)
			for (int k = 1; k<=n; k++)
				dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1; i<=n; i++)
	{
		for (int j = 1; j<=n; j++)
		{
			scanf("%1d",&graph[i][j]);
		}
	}
	for (int i = 0; i<120; i++)
	{
		for (int j = 0; j<120; j++)
		{
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}
	for (int i = 0; i<120; i++)
	{
		for (int j = 0; j<120; j++)
		{
			if (graph[i][j])
				dist[i][j] = 1;
		}
	}
	Floyd_Warshall();
	scanf("%d",&m);
	for (int i = 1; i<=m; i++)
	{
		scanf("%d",path+i);
	}
	goodsub.push_back(1);
	while(goodsub.back()!=m)
	{
		int curback = goodsub.back();
		int rstart = min(curback+n,m);
		while(dist[path[curback]][path[rstart]]!=(rstart-curback))
			rstart--;
		goodsub.push_back(rstart);
	}
	printf("%d\n",(int)goodsub.size());
	for (auto it:goodsub)
	{
		printf("%d ",path[it]);
	}
}
