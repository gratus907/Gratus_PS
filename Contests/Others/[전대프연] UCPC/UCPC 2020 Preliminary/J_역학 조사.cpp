#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int n, m;
vector <vector<int>> gathering;
int virus[101010];
int clean[101010];
int simul[101010];
int32_t main()
{
    usecppio
    cin >> n >> m;
    for (int i = 0; i<m; i++)
    {
        int k; cin >> k;
        vector <int> tmpv;
        for (int j = 0; j<k; j++)
        {
            int x; cin >> x;
            tmpv.push_back(x);
        }
        gathering.push_back(tmpv);
    }
    for (int i = 1; i<=n; i++)
        cin >> virus[i];
    for (int i = 1; i<=n; i++)
    {
        if (virus[i] == 0)
            clean[i] = 0;
        else
            clean[i] = 1;
    }
    for (int i = m-1; i>=0; i--)
    {
        bool sick = true;
        for (auto ind:gathering[i])
        {
            if (!clean[ind]) sick = 0;
        }
        if (!sick)
        {
            for (auto ind:gathering[i])
            {
                clean[ind] = false;
            }
        }
    }
    // Simulation phase
    for (int i = 1; i<=n; i++)
    {
        if (clean[i]) simul[i] = 1;
    }
    for (auto vit : gathering)
    {
        bool sick = false;
        for (auto ind:vit)
            if (clean[ind] || simul[ind])
                sick = true;
        if (sick)
            for (auto ind:vit)
                simul[ind] = 1;
    }
    for (int i = 1; i<=n; i++)
    {
        if (simul[i]!=virus[i])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 1; i<=n; i++)
    {
        cout << clean[i] << ' ';
    }
    cout << '\n';
}