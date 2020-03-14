#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
#define all(x) ((x).begin()),((x).end())
#define eps 1e-6
using pii = pair<int, int>;

int occmin[5050];
int occmax[5050];
bool solve()
{
    memset(occmin, 0x7f, sizeof(occmin));
    memset(occmax, 0, sizeof(occmax));
    int n; cin >> n;
    for (int i = 1; i<=n; i++)
    {
        int x; cin >> x;
        occmin[x] = min(occmin[x], i);
        occmax[x] = max(occmax[x], i);
    }
    for (int i = 1; i<=5000; i++)
    {
        if (occmax[i]-occmin[i]>1)
            return true;
    }
    return false;
}
int32_t main()
{
    usecppio
    int t; cin >> t;
    while(t--)
    {
        cout << (solve()?"YES":"NO") << '\n';
    }
}
