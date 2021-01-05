#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
using pii = pair<ll, ll>;
int A[8];
vector<int> sw[8];
int ans = 1e9;
int32_t main()
{
    usecppio
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < k; i++)
    {
        int c; cin >> c;
        while(c--)
        {
            int x; cin >> x;
            x--;
            sw[i].push_back(x);
        }
    }
    int mp = pow(5, k);
    for (int i = 0; i < mp; i++)
    {
        vector <int> v;
        int u = i;
        int tc = 0;
        while(u)
        {
            v.push_back(u % 5);
            tc += v.back();
            u /= 5;
        }
        vector <int> res(n, 0);
        for (int j = 0; j < n; j++) res[j] = A[j];
        for (int j = 0; j < v.size(); j++)
        {
            for (int jj = 0; jj < sw[j].size(); jj++)
            {
                res[sw[j][jj]] += ((j+1)*v[j]);
                res[sw[j][jj]] %= 5;
            }
        }
        bool flag = true;
        for (int j = 1; j < res.size(); j++)
            flag &= (res[j] == res[0]);
        if (flag)
            ans = min(ans, tc);
    }
    cout << (ans > 1e6? -1 : ans) << '\n';
}