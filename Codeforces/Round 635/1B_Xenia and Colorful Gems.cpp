#include <bits/stdc++.h>
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
using pii = pair<int, int>;

vector <int> r, g, b;
inline ll fun(int p1, int p2, int p3)
{
    return (p1-p2)*(p1-p2)+(p1-p3)*(p1-p3)+(p2-p3)*(p2-p3);
}
int choose_c(int aval, int bval, vector <int>&from)
{
    //printf("Chosen : %lld %lld\n",aval, bval);
    int mid = (aval + bval)/2;

    int v = LLONG_MAX;
    auto lg = lower_bound(all(from),mid);
    auto rg = upper_bound(all(from),mid);
    if (lg!=from.begin())
        lg--;
    for (auto u = lg; u!=from.end() && u<=rg; u++)
        v = min(v, fun(aval,bval,*u));

    return v;
}
void solve()
{
    r.clear(), g.clear(), b.clear();
    int nr, ng, nb;
    cin >> nr >> ng >> nb;
    r.resize(nr), g.resize(ng), b.resize(nb);
    for (int i = 0; i<nr; i++) cin >> r[i];
    for (int i = 0; i<ng; i++) cin >> g[i];
    for (int i = 0; i<nb; i++) cin >> b[i];
    sort(all(r)), sort(all(g)), sort(all(b));
    r.erase(unique(all(r)),r.end());
    g.erase(unique(all(g)),g.end());
    b.erase(unique(all(b)),b.end());
    nr = r.size(); ng = g.size(); nb = b.size();
    int glob_min = LLONG_MAX;
    for (int i = 0; i<nr; i++)
    {
        int tmp = LLONG_MAX;
        int ca = r[i];
        auto lg = lower_bound(all(g),ca);
        auto rg = upper_bound(all(g),ca);
        if (lg!=g.begin())
            lg--;
        for (auto u = lg; u!=g.end() && u<=rg; u++)
            tmp = min(tmp, choose_c(ca, *u, b));

        auto lb = lower_bound(all(b),ca);
        auto rb = upper_bound(all(b),ca);
        if (lb!=b.begin())
            lb--;
        for (auto u = lb; u!=b.end() && u<=rb; u++)
            tmp = min(tmp, choose_c(ca, *u, g));

        glob_min = min(glob_min, tmp);
    }
    cout << glob_min << '\n';
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--) solve();
}