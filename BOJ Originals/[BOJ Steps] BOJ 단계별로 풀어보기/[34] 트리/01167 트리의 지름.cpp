#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define gcd(A,B) (__gcd(A,B))
using namespace std;
typedef pair <int, int> pii;

vector <pii> tree[101010];

int maxpt;
ll visit[101010];
int V;
queue <pii> q;
ll maxdist(int r)
{
    memset(visit,-1,sizeof(visit));
    ll maxdist = -1;
    visit[r] = 0;
    q.push({r,0});
    while(!q.empty())
    {
        pii x = q.front();
        q.pop();
        for (auto it:tree[x.first])
        {
            if (visit[it.first]==-1)
            {
                q.push(it);
                visit[it.first] = visit[x.first]+it.second;
            }
        }
    }
    for (int i = 1; i<=V; i++)
    {
        maxdist = max(maxdist,visit[i]);
        if (maxdist==visit[i])
            maxpt = i;
    }
    return maxdist;
}

int main()
{
    scanf("%d",&V);
    for (int i = 1; i<=V; i++)
    {
        int u,e;
        scanf("%d",&u);
        while(true)
        {
            scanf("%d",&e);
            if (e==-1)
                break;
            else
            {
                int val;
                scanf("%d",&val);
                tree[u].push_back({e,val});
            }
        }
    }
    maxdist(1);
    ll diam = maxdist(maxpt);
    printf("%lld",diam);
}