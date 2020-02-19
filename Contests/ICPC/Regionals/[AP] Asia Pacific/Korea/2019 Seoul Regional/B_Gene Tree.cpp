#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
using pii = pair<int, int>;

struct info
{
    int dsum, sqsum, leaf;
};
vector <pii> Tree[101010]; // (dest, weight)
int dist_from_root[101010], parent[101010];
int ans[101010];
info checker[101010];
bool visit[101010];
int root = 1;
int n;
queue <int> q;
void weight()
{
    dist_from_root[root] = 0;
    q.push(root);
    visit[root] = true;
    parent[root] = -1;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto it:Tree[x])
        {
            if (!visit[it.first])
            {
                parent[it.first] = x;
                dist_from_root[it.first] = dist_from_root[x]+it.second;
                q.push(it.first);
                visit[it.first] = true;
            }
        }
    }
}
info func(int cur)
{
    if (Tree[cur].size() == 1)
    {
        checker[cur] = {0, 0, 1};
    }
    else 
    {
        vector <pii> v;
        for (auto it:Tree[cur])
            if (it.first!=parent[cur])
                v.push_back(it);
        info iA = func(v[0].first);
        info iB = func(v[1].first);
        int nn = iA.leaf + iB.leaf;
        int sr = iA.dsum + iB.dsum + (iA.leaf)*(v[0].second)+(iB.leaf)*(v[1].second);
        int sqr = iA.sqsum + iB.sqsum + (iA.leaf)*(v[0].second*v[0].second)
        +(iB.leaf)*(v[1].second*v[1].second) + 2*(iA.dsum*v[0].second + iB.dsum*v[1].second);

        int res = (iB.leaf)*(iA.sqsum+(iA.leaf)*(v[0].second*v[0].second) + 2*iA.dsum*v[0].second);
        res += (iA.leaf)*(iB.sqsum+(iB.leaf)*(v[1].second*v[1].second)+ 2*iB.dsum*v[1].second);   
        res += (2*(iA.leaf*v[0].second+iA.dsum)*(iB.leaf*v[1].second+iB.dsum));  
        ans[cur] = res;
        checker[cur]= {sr,sqr,nn};
    }
    return checker[cur];
}

int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i<n; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        Tree[s].push_back({e,t});
        Tree[e].push_back({s,t});
    }
    for (int i = 1; i<=n; i++)
    {
        if (Tree[i].size() == 1) 
        {
            root = i; 
            Tree[root].push_back({0, 0});
            Tree[0].push_back({0, 0});
            break;
        }
    }
    weight();
    func(root);
    int final = 0;

    for (int i = 1; i<=n; i++)
    {
        final += ans[i];
    }
    cout << final << '\n';
}