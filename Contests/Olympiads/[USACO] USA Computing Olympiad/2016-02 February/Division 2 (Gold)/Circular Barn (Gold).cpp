#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-9
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
using pii = pair<int, int>;

int cow[101010];
int n, st, cur;
int msz = -100000, gt;
deque <int> dq;
bool got[101010], pic[101010];
int ttl;
inline int mcd(int a, int b)
{
    return (b-a+n)%n;
}
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 0; i<n; i++)
        cin >> cow[i];
    for (int i = 0; gt<n; i = (i+1)%n)
    {
        if (!pic[i])
        {
            cur += cow[i];
            pic[i] = true;
        }
        if (!got[i])
        {
            if (cur>0)
            {
                cur--; gt++;
                if (gt == n)
                    break;
                got[i] = true;
            }
            else
                st = (i+1)%n;
        }
    }
    dq.clear();
    for (int i = 0; i<n; i++)
    {
        int pos = (st+i)%n;
        for (int j = 0; j<cow[pos]; j++)
            dq.push_back(pos);
        int u = dq.front(), dt = mcd(u, pos);
        dq.pop_front();
        ttl += dt*dt;
    }
    cout << ttl << '\n';
}