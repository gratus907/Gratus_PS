#include <bits/stdc++.h>
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
struct Fenwick
{
    int n;
    int tree[202020];
    void init()
    {
        memset(tree,0,sizeof(tree));
    }
    int sum(int p)
    {
        int ret = 0;
        for (; p > 0; p -= p & -p)
            ret += tree[p];
        return ret;
    }
    void add (int p, int val)
    {
        for (; p <= n; p += p & -p)
            tree[p] += val;
    }
} BIT;

vector <pii> ep;
int ans;
int main()
{
    int n;
    cin >> n;
    ep.resize(n);

    BIT.init();
    BIT.n = n*2;
    for (int i = 0; i<n; i++)
    {
        ep[i] = {-1, -1};
    }
    for (int i = 0; i<2*n; i++)
    {
        int x;
        cin >> x;
        if (ep[x-1].first==-1)
            ep[x-1].first = i;
        else
            ep[x-1].second = i;
    }
    sort(all(ep));
    for (int i = 0; i<n; i++)
    {
        ans += BIT.sum(ep[i].second)-BIT.sum(ep[i].first-1);
        BIT.add(ep[i].second,1);
    }
    cout << ans << '\n';
}