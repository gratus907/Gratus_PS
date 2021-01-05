#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
typedef cc_hash_table<int, int, hash<int>> ht;
using pii = pair<int, int>;
const int mod = 1000000007;

class Tree
{
public:
    vector <vector<int>> adjList;
    vector <int> centroids;
    pair<string, string> hash();
    void findCentroid()
    {
        int n = adjList.size();
        vector <int> cent;
        vector <int> sz(n);
        function <void (int, int)> dfs = [&](int r, int p){
            sz[r] = 1;
            bool is_cent = true;
            for (auto v : adjList[r])
            {
                if (v != p)
                {
                    dfs(v, r);
                    sz[r] += sz[v];
                    if (sz[v] > n / 2)
                        is_cent = false;
                }
            }
            if (n - sz[r] > n / 2)
                is_cent = false;
            if (is_cent)
                centroids.push_back(r);
        };
        dfs(0, -1);
        return;
    }
};

pair<string, string> Tree::hash()
{
    if (centroids.empty()) findCentroid();
    vector <string> nodeHash(adjList.size());
    function <string (int, int)> dfs = [&](int r, int p){
        if (adjList[r].size() == 1 && adjList[r][0] == p)
            return nodeHash[r] = "10";
        for (auto it:adjList[r])
        {
            if (it != p)
                dfs(it, r);
        }
        sort(all(adjList[r]), [&nodeHash](int a, int b) -> bool{
           return nodeHash[a] < nodeHash[b];
        });
        string h = "1";
        for (auto it:adjList[r])
            h += nodeHash[it];
        h += "0";
        return nodeHash[r] = h;
    };
    pair <string, string> pss;
    int rt = centroids[0];
    dfs(rt, -1);
    pss.first = nodeHash[rt];
    nodeHash.clear();
    nodeHash.resize(adjList.size());
    if (centroids.size() == 2)
    {
        rt = centroids[1];
        dfs(rt, -1);
        pss.second = nodeHash[rt];
    }
    else pss.second = "-1";
    if (pss.first > pss.second) swap(pss.first, pss.second);
    return pss;
}

set <pair<string, string>> hashes;

Tree getTree()
{
    Tree T;
    int s; cin >> s;
    T.adjList.resize(s);
    for (int i = 0; i < s-1; i++)
    {
        int u, v; cin >> u >> v;
        T.adjList[u].push_back(v);
        T.adjList[v].push_back(u);
    }
    return T;
}
int32_t main()
{
    usecppio
    int n; cin >> n;
    while(n--)
    {
        Tree T = getTree();
        pair<string, string> ps;
        ps = T.hash();
        hashes.insert(ps);
    }/*
    for (auto ps : hashes)
        printf("Hash : {%s} {%s}\n",ps.first.c_str(), ps.second.c_str());*/
    cout << hashes.size() << '\n';
}