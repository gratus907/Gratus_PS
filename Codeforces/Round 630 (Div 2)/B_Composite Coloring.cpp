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

int arr[20] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 0};
bool visit[20];
void solve()
{
    memset(visit, 0, sizeof(visit));
    int n;
    int ct = 0;
    cin >> n;
    vector <int> ans;
    for (int i = 0; i<n; i++)
    {
        int x;
        int a = 0;
        cin >> x;
        for (int j = 1; j<=11; j++)
        {
            if (x%arr[j]==0)
            {
                a = j;
                if (visit[j] == 0)
                {
                    visit[j] = true;
                    ct++;
                }
                break;
            }
        }
        ans.push_back(a);
    }
    vector <int> comp = ans;
    sort(all(comp));
    map<int, int> mp;
    comp.erase(unique(all(comp)),comp.end());
    for (int i = 0; i<comp.size(); i++)
    {
        mp[comp[i]] = i+1;
    }
    cout << comp.size() << '\n';
    for (auto it:ans)
    {
        cout << mp[it] << ' ';
    }
    cout << '\n';
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--) solve();
}