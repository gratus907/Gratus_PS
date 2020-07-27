#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// Koosaga MCMF LIBRARY ------------------------
const int MAXN = 1010;
struct edg{ int pos, cap, rev, cost; };
vector<edg> gph[MAXN];
void clear(){
	for(int i=0; i<MAXN; i++) gph[i].clear();
}
void add_edge(int s, int e, int x, int c){
	gph[s].push_back({e, x, (int)gph[e].size(), c});
	gph[e].push_back({s, 0, (int)gph[s].size()-1, -c});
}
int dist[MAXN], pa[MAXN], pe[MAXN];
bool inque[MAXN];
bool spfa(int src, int sink){
	memset(dist, 0x3f, sizeof(dist));
	memset(inque, 0, sizeof(inque));
	queue<int> que;
	dist[src] = 0;
	inque[src] = 1;
	que.push(src);
	bool ok = 0;
	while(!que.empty()){
		int x = que.front();
		que.pop();
		if(x == sink) ok = 1;
		inque[x] = 0;
		for(int i=0; i<gph[x].size(); i++){
			edg e = gph[x][i];
			if(e.cap > 0 && dist[e.pos] > dist[x] + e.cost){
				dist[e.pos] = dist[x] + e.cost;
				pa[e.pos] = x;
				pe[e.pos] = i;
				if(!inque[e.pos]){
					inque[e.pos] = 1;
					que.push(e.pos);
				}
			}
		}
	}
	return ok;
}
int match(int src, int sink){
	int ret = 0;
	while(spfa(src, sink)){
		int cap = 1e9;
		for(int pos = sink; pos != src; pos = pa[pos]){
			cap = min(cap, gph[pa[pos]][pe[pos]].cap);
		}
		ret += dist[sink] * cap;
		for(int pos = sink; pos != src; pos = pa[pos]){
			int rev = gph[pa[pos]][pe[pos]].rev;
			gph[pa[pos]][pe[pos]].cap -= cap;
			gph[pos][rev].cap += cap;
		}
	}
	return ret;
}
// Library ends here --------------------------------


int32_t main()
{
    usecppio
    int n, m;
    cin >> n >> m;
    int S = 1005, E = 1006;
    add_edge(S, 1, 2, 0);
    add_edge(n, E, 2, 0);
    for (int i= 0; i<m; i++)
    {
        int p, q, l;
        cin >> p >> q >> l;
        add_edge(p, q, 1, l);
        add_edge(q, p, 1, l);
    }
    auto P = match(S, E);
    cout << P << '\n';
}