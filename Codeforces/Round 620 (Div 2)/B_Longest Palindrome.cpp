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
 
int n, m;
vector <string> v;
vector <string> self_palindromes;
vector <string> will_use;
bool got[120];
int32_t main()
{
    cin >> n >> m;
    for (int i = 0; i<n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i<n; i++)
    {
        if (got[i]) continue;
        string u;
        u = v[i];
        reverse(all(u));
        if (u == v[i])
        {
            self_palindromes.push_back(v[i]);
            got[i] = true;
            continue;
        }
        for (int j = 0; j<n; j++)
        {
            if (i == j) continue;
            if (got[j]) continue;
            if (u == v[j] && !got[j])
            {
                will_use.push_back(v[i]);
                got[i] = true; got[j] = true;
                break;
            }
        }
    }
    string ans = "";
    for (auto it:will_use)
    {
        ans += it;
    }
    string revans = ans;
    reverse(all(revans));
    if (!self_palindromes.empty())
        ans += self_palindromes[0];
    ans += revans;
    cout << ans.size() << '\n';
    if (ans.size()>0)
        cout << ans << '\n';
}