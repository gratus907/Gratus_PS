#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll 
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


vector <int> ma, mb;
int T, n, m;
int A[1010], SA[1010];
int B[1010], SB[1010];
int count_elements(vector <int> & vt, int x)
{
    return upper_bound(all(vt),x)-lower_bound(all(vt),x);
}
int32_t main()
{
    usecppio
    cin >> T;
    cin >> n;
    for (int i = 1; i<=n; i++) 
    {
        cin >> A[i];
        SA[i] = SA[i-1]+A[i];
    }
    cin >> m;
    for (int i = 1; i<=m; i++) 
    {
        cin >> B[i];
        SB[i] = SB[i-1]+B[i];
    }
    for (int i = 1; i<=n; i++)
        for (int j = 0; j<i; j++)
            ma.push_back(SA[i]-SA[j]);
    for (int i = 1; i<=m; i++)
        for (int j = 0; j<i; j++)
            mb.push_back(SB[i]-SB[j]);
    sort(all(mb));
    int ans = 0;
    for (auto it:ma)
        ans += count_elements(mb,T-it);
    cout << ans << '\n';
}