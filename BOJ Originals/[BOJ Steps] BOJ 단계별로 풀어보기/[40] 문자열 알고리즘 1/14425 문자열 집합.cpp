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

set <string> s;

int32_t main()
{
    usecppio
    int n, m;
    cin >> n >> m;
    for (int i = 0; i<n; i++)
    {
        string S; cin >> S;
        s.insert(S);
    }
    int cnt = 0;
    for (int i = 0; i<m; i++)
    {
        string S; cin >> S;
        cnt += (s.find(S)!=s.end());
    }
    cout << cnt << '\n';
}