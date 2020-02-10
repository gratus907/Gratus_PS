#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define sz(v) ((int)(v).size())
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
#define int ll

inline int count_element(vector <int> & v, int x, bool incl)
{
    auto ed = v.end();
    auto st = v.begin();
    if (incl)
        ed = upper_bound(all(v),x);
    else
        ed = lower_bound(all(v),x);
    return (ed - st);
}

int seq[202020];
int indlist[202020];
int n, x, ans;
int32_t main()
{
    cin >> n >> x;
    for (int i = 0; i<n; i++) indlist[i] = n;
    vector<int> lis_front(n+1, INT_MAX);
    vector<int> lds_back(n+1, -INT_MAX);
    for (int i = 0; i<n; i++)
        cin >> seq[i];
    lis_front[0] = -1;
    lds_back[n] = INT_MAX;
    for (int i = 0; i<n; i++)
    {
        int ind = count_element(lis_front, seq[i], false);
        lis_front[ind] = seq[i];
        ans = max(ans, ind);
        indlist[i] += ind;
    }
    for (int i = n-1; i>=0; i--)
    {
        int ind = count_element(lds_back, seq[i]-x+1, false);
        ans = max(ans, indlist[i]-ind);
        int orind = count_element(lds_back, seq[i], true);
        lds_back[orind-1] = seq[i];
    }
    cout << ans << '\n';
}