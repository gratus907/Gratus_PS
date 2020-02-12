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
const int INF = 0x7f7f7f7f;
int arr[202020], lt[202020], ft[202020];
vector <int> pos;

bool rec(int l, int r)
{
    if (l >= r)
        return false;
    for (int i = 0; i<=(r-l)/2 + 1; i++)
    {
        int cd1 = l+i;
        int cd2 = r-i;
        if (ft[cd1]<l && lt[cd1] > r)
            return rec(l, cd1-1) || rec(cd1+1, r);
        if (ft[cd2]<l && lt[cd2] > r)
            return rec(l, cd2-1) || rec(cd2+1, r);
    }
    return true;
}

bool solve()
{
    vector <int> tmp;
    pos.clear();
    int n;
    cin >> n;
    pos.resize(n+1);
    for (int i = 1; i<=n; i++)
    {
        cin >> arr[i];
        tmp.push_back(arr[i]);
    }
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
    for (int i = 1; i<=n; i++)
        arr[i] = lower_bound(all(tmp),arr[i])-tmp.begin() + 1;
    fill(all(pos),0);
    for (int i = 1; i<=n; i++)
    {
        if (pos[arr[i]])
        {
            ft[i] = pos[arr[i]];
            pos[arr[i]] = i;
        }
        else
        {
            pos[arr[i]] = i;
            ft[i] = 0;
        }
    }
    fill(all(pos),0);
    for (int i = n; i>=1; i--)
    {
        if (pos[arr[i]])
        {
            lt[i] = pos[arr[i]];
            pos[arr[i]] = i;
        }
        else
        {
            pos[arr[i]] = i;
            lt[i] = n+1;
        }
    }
    return !rec(1, n);
}

int32_t main()
{
    srand(time(0));
    usecppio
    int t;
    cin >> t;
    while(t--)
    {
        cout << (solve()?"non-":"") << "boring\n";
    }
}