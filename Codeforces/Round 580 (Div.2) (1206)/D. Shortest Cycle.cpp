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
#define int ll
#define INF 987654321LL
struct Edge
{
	int u;
	int v;
	int weight;
};
int n;
int arr[101010];
vector <int> ctbit[70];
list <pii> graph[101010];
vector <int> relavent;
vector <Edge> edge;
void addEdge ( int u, int v, int w )
{
	graph[u].push_back( make_pair( v, w ));
	graph[v].push_back( make_pair( u, w ));
	Edge e { u, v, w };
	edge.push_back (  e );
}

int ShortestPath ( int u, int v )
{
	set< pair<int, int> > setds;

	vector<int> dist(101010, INF);

	setds.insert(make_pair(0, u));
	dist[u] = 0;

	while (!setds.empty())
	{
		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());

		int u = tmp.second;

		for (auto i = graph[u].begin(); i != graph[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;

			if (dist[v] > dist[u] + weight)
			{
				if (dist[v] != INF)
					setds.erase(setds.find(make_pair(dist[v], v)));

				dist[v] = dist[u] + weight;
				setds.insert(make_pair(dist[v], v));
			}
		}
	}

	return dist[v] ;
}
void removeEdge ( int u, int v, int w )
{
	graph[u].remove(make_pair( v, w ));
	graph[v].remove(make_pair(u, w ));
}
int FindMinimumCycle ( )
{
	int min_cycle = INT_MAX;
	int E = edge.size();
	for ( int i = 0 ; i < E  ; i++ )
	{
		Edge e = edge[i];

		removeEdge( e.u, e.v, e.weight ) ;

		// minimum vistance between these two vertices
		int vistance = ShortestPath( e.u, e.v );

		min_cycle = min( min_cycle, vistance + e.weight );

		addEdge( e.u, e.v, e.weight );
	}

	return min_cycle ;
}
int32_t main()
{
	//usecppio
	cin >> n;
	for (int i = 1; i<=n; i++)
	{
		cin >> arr[i];
		for (int b = 0; b<64; b++)
		{
			if (arr[i] & (1LL << b))
			{
				ctbit[b].push_back(i);
			}
		}
	}
	for (int i = 0; i<64; i++)
	{
		if (ctbit[i].size()>2)
		{
			cout << 3;
			return 0;
		}
	}
	for (int i = 0; i<64; i++)
	{
		if (ctbit[i].size()<2)
			continue;
		else
		{
			addEdge(ctbit[i][0],ctbit[i][1],1);
			relavent.push_back(ctbit[i][0]);
			relavent.push_back(ctbit[i][1]);
		}
	}
	int ans = 987654321;
	sort(all(relavent));
	relavent.erase(unique(all(relavent)),relavent.end());
	ans = min(ans, FindMinimumCycle());
	if (ans == 987654321)
		cout << -1;
	else cout << ans;
}
