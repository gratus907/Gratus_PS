#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define eps 1e-7
#define int ll
using pii = pair <int, int>;
const int mod = 1000000007;

int n, k;

vector <int> build(int x)
{
    vector <int> v = {0};
    if (x == 1) return v;
    int num = 0, nn = 1;
    int ct = 0;
    while (num+nn+1 <= x)
    {
        num += nn;
        ct++;
        nn *= k;
    }
    num++;
    x -= num;
    vector <int> tv;
    while(x)
    {
        tv.push_back(x%k);
        x/=k;
    }
    while(tv.size()<ct)
        tv.push_back(0);
    reverse(all(tv));
    for (auto it:tv)
        v.push_back(it);
    return v;
}
int32_t main()
{
    int q;
    cin >> n >> k >> q;
    if (k == 1)
    {
        while(q--)
        {
            int x, y;
            cin >> x >> y;
            cout << abs(x-y) << '\n';
        }
    }
    else
    {
        while(q--)
        {
            int x, y;
            cin >> x >> y;
            vector <int> vx = build(x);
            vector <int> vy = build(y);
            int s = 0;
            int m = min(vx.size(),vy.size());
            while(s < m)
            {
                if (vx[s] == vy[s])
                    s++;
                else break;
            }
            cout << vx.size()+vy.size()-2*s << '\n';
        }
    }
}