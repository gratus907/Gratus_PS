#include <bits/stdc++.h>
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
const bool debug = 0;
using pii = pair<int, int>;
typedef long double D;

vector <int> candidates;

bool is_square(int x)
{
    D t = x*1.0L;
    t = sqrt(t);
    int u = (int)t;
    return u*u==x?1:0;
}

int sq_inrange(int L, int R)
{
    return ((int)sqrt(1.0L*R)-(int)(sqrt(1.0L*(L-1))));
}
void solve()
{
    int L, R; cin >> L >> R;
    int u = upper_bound(all(candidates), R)-lower_bound(all(candidates),L);
    int v = sq_inrange(L, R);
    cout << u + v << '\n';
}

int32_t main()
{
    usecppio
    int q; cin >> q;
    for (int i = 2; i<=1000000; i++)
    {
        if (!is_square(i))
        {
            int u = (log(1e18)/log(i))+eps;
            for (int j = 3; j<=u; j+=2)
            {
                int po = pow(i*1.0L,j*1.0L);
                candidates.push_back(po);
            }
        }
    }
    sort(all(candidates));
    candidates.erase(unique(all(candidates)),candidates.end());
    while (q--)
        solve();
}