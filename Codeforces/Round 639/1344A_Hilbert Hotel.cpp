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

inline int mod(int x, int m)
{
    return ((x%m)+m)%m;
}
vector <int> arr, modclass;
bool solve()
{
    int n;
    cin >> n;
    arr.clear(), modclass.clear();
    arr.resize(n);
    modclass.resize(n);
    fill(all(modclass),-1);
    for (int i = 0; i<n; i++)
        cin >> arr[i];
    for (int i = 0; i<n; i++)
    {
        int x = i+arr[i%n];
        x = mod(x, n);
        if (modclass[x]!=-1)
            return 0;
        modclass[x] = i;
    }
    return 1;
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--)
    {
        cout << (solve()?"YES\n":"NO\n");
    }
}