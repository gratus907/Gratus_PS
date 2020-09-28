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
using pii = pair<int, int>;

vector <int> s;
vector <int> w;
vector <bool> fx;
vector <int> test;
void init(int sz)
{
    w.clear();
    w.resize(sz);
    fx.clear();
    fx.resize(sz);
    test.clear();
    test.resize(sz, 0);
}
pair<vector <int>, int> parse_input() // Read S-vector
{
    string str;
    cin >> str;
    int x; cin >> x;
    vector <int> v;
    for (int i = 0; i<str.size(); i++)
        v.push_back(str[i]-'0');
    return {v, x};
}
vector <int> recheck(vector <int> W, int x) // S-vector
{
    int n = W.size();
    vector <int> tst;
    tst.resize(n);
    for (int i = 0; i<n; i++)
    {
        if (i >= x)
        {
            if (W[i-x] == 1)
                tst[i] = 1;
        }
        if (i < n-x)
        {
            if (W[i+x] == 1)
                tst[i] = 1;
        }
    }
    return tst;
}
bool solve()
{
    auto pp = parse_input();
    s = pp.first;
    int x = pp.second;
    int n = s.size();
    init(n);
    for (int i = 0; i<x; i++)
    {
        if (i+x >= n) continue;
        w[i] = s[i+x]?1:0;
        fx[i] = true;
    }
    for (int i = n-x; i<n; i++)
    {
        if (i < x) continue;
        int cw = s[i-x]?1:0;
        if (fx[i] && (cw!=w[i]))
            return false;
        else
        {
            w[i] = s[i-x]?1:0;
            fx[i] = true;
        }
    }
    for (int i = 0; i<n; i++)
    {
        if (s[i]==0)
        {
            if (i >= x)
            {
                if (i < x) continue;
                if (fx[i-x] && w[i-x])
                    return false;
                w[i-x] = 0;
                fx[i-x] = true;
            }
            if (i < n-x)
            {
                if (i + x >= n) continue;
                if (fx[i+x] && w[i+x])
                    return false;
                w[i+x] = 0;
                fx[i+x] = true;
            }
        }
    }
    for (int i = 0; i<n; i++)
    {
        if (!fx[i])
        {
            if (i < x)
            {
                if (i + x >= n) continue;
                if (s[i+x]==1)
                    w[i] = 1;
                else w[i] = 0;
            }
            else if (i < n-x)
            {
                if (s[i+x]==1 or s[i-x] == 1)
                    w[i] = 1;
                else w[i] = 0;
            }
            else if (i >= n-x)
            {
                if (i < x) continue;
                if (s[i-x] == 1)
                    w[i] = 1;
                else w[i] = 0;
            }
            fx[i] = true;
        }
    }
    test = recheck(w, x);
    for (int i = 0; i<n; i++)
    {
        if (test[i] != s[i])
            return false;
    }
    return true;
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--)
    {
        if (!solve())
            cout << -1 << '\n';
        else
        {
            for (int c:w)
                cout << c;
            cout << '\n';
        }
    }
}