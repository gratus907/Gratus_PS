#include <bits/stdc++.h>
#include "dreaming.h"
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii=pair<int, int>;
vector <pii> Graph[101010];
int n, m;
bool vst[101010];
bool dfs_visit[101010];
vector <pii> radii; 
vector <int> cur_tree;
vector <bool> tmpvisit(101010, false);
vector <int> dt(101010, 1e8);
vector <int> par(101010, 0);
pii dist_bfs(vector <int> &par, vector<int> &dt, int root, vector<int> &Tr)
{
    queue <int> q;
    q.push(root);
    dt[root] = 0;
    par[root] = -1;
    tmpvisit[root] = true;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto it:Graph[x])
        {
            if (!tmpvisit[it.first])
            {
                dt[it.first] = dt[x]+it.second;
                tmpvisit[it.first] = true;
                q.push(it.first);
                par[it.first] = x;
            }
        }
    }
    int maxdist = 0, maxdistpoint = 0;
    for (auto nd : Tr)
    {
        if (dt[nd] >= maxdist)
        {
            maxdist = dt[nd];
            maxdistpoint = nd;
        }
        tmpvisit[nd] = 0;
    }
    return {maxdist, maxdistpoint};
}

void dfs(int r, int p)
{
    cur_tree.push_back(r);
    dfs_visit[r] = true;
    for (auto it:Graph[r])
        if (!dfs_visit[it.first])
            if (it.first != p)
                dfs(it.first, r);
}
pii decomp_tree(int root)
{
    pii p1 = dist_bfs(par, dt, root, cur_tree);
    pii p2 = dist_bfs(par, dt, p1.second, cur_tree);
    int A = p1.second, B = p2.second;
    int p = B;
    vector <int> TT; 
    while(p!=-1)
    {
        TT.push_back(p);
        p = par[p];
    }
    vector <int> RR;
    int R = INT_MAX;
    for (auto it:TT)
        R = min(R, max(dt[it], dt[B]-dt[it]));
    return {R, dt[B]};
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) 
{
    n = N, m = M;
    for (int i = 0; i<M; i++)
    {
        Graph[A[i]].push_back({B[i],T[i]});
        Graph[B[i]].push_back({A[i],T[i]});
    }
    for (int i = 0; i<N; i++)
    {
        if (vst[i]) continue;
        memset(dfs_visit, 0, sizeof(dfs_visit));
        cur_tree.clear();
        dfs(i, -1);
        for (auto it:cur_tree)
            vst[it] = true;
        radii.push_back(decomp_tree(i));
    }
    sort(all(radii),greater<pii>());
    if (radii.size()==1)
        return radii.front().second;
    else
    {
        int cand_1 = radii[0].first+radii[1].first+L;
        int cand_2 = 0;
        for (auto it:radii)
            cand_2 = max(cand_2, it.second);
        int cand_3 = 0;
        if (radii.size()>2)
            cand_3 = radii[1].first+radii[2].first+2*L;
        return max(max(cand_1, cand_2),cand_3);
    }
}
