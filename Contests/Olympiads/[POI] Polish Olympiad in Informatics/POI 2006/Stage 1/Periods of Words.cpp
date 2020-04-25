#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define int ll
using pii = pair <int, int>;
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = 0;

int n; string S;
int dp[1010100];
vector <int> fail;
vector <int> getPi(string p)
{
    int j = 0;
    int plen = p.length();
    vector<int> pi;
    pi.resize(plen);
    for(int i = 1; i< plen; i++)
    {
        while((j > 0) && (p[i] !=  p[j]))
            j = pi[j-1];
        if(p[i] == p[j])
        {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}

int solve(int slen)
{
    if (slen < 0) 
        return INF;
    if (dp[slen]!=-1)
        return dp[slen];
    int x = fail[slen];
    if (x==0)
        return dp[slen] = slen;
    int y = solve(x-1);
    return (dp[slen] = min(x, y));
}
int32_t main()
{
    usecppio
    cin >> n >> S;
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    fail = getPi(S);
    for (int i = 0; i<n; i++)
    {
        ans += (i-solve(i));
        //printf("%lld\n",solve(i));
    }
    cout << ans << '\n';
}