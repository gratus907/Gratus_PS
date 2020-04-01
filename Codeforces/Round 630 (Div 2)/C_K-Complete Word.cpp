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

void solve()
{
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    vector <vector<int>> equi_class;
    vector <bool> used(n, 0);
    for (int i = 0; i<n; i++)
    {
        if (used[i] == 0)
        {
            vector <int> u;
            for (int j = i; j<n; j+=k)
            {
                if (used[j]==0)
                {
                    used[j] = 1;
                    u.push_back(j);
                }
                if (used[n-1-j]==0)
                {
                    u.push_back(n-1-j);
                    used[n-1-j] = 1;
                }
            }
            equi_class.push_back(u);
        }
    }
    int change = 0;
    for (auto it:equi_class)
    {
        vector <int> occ(26, 0);
        for (auto itt:it)
            occ[s[itt]-'a']++;
        int p = it.size() - *max_element(all(occ));
        change+=p;
    }
    cout << change << '\n';
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--) solve();
}