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
int good;
int val[65536];
int suf[65536];
int sufcount[5];
int cnt[5] = {0, 62952, 62952, 63939, 63939};
bool getval(int x)
{
    int ox = x;
    vector <int> num;
    while(x)
    {
        num.push_back(x%2);
        x/=2;
    }
    vector <int> dp(32, 0);
    dp[0] = 1;
    for (int i = 1; i<num.size(); i++)
    {
        if (num[i]==num[i-1]) dp[i]=dp[i-1]+1;
        else dp[i] = 1;
    }
    bool q = *(max_element(all(dp)))>=3;
    if (q) return true;
    if (ox>=65536) return false;
    while(num.size()<16)
        num.push_back(-1);
    if (num[0]==0 && num[1]!=0)
        suf[ox] = 1;
    else if (num[0]==1 && num[1]!=1)
        suf[ox] = 2;
    else if (num[0]==0 && num[1]==0 && num[2]!=0)
        suf[ox] = 3;
    else if (num[0]==1 && num[1]==1 && num[2]!=1)
        suf[ox] = 4;
    return 0;
}

int32_t main()
{
    usecppio
    for (int i = 0; i<(1<<16); i++) 
    {
        val[i] = getval(i);
        sufcount[suf[i]]++;
        if (val[i]) good++;
    }
    suf[0] = 1;
    int L, R;
    cin >> L >> R;
    int ans = 0;
    int l = L/(1<<16);
    l++;
    int r = R/(1<<16);
    if (R-L<200000)
    {
        for (int i = L; i<=R; i++)
            if (getval(i))
                ans++;
        cout << ans << '\n';
        return 0;
    }
    for (int i = L; i<l*65536; i++)
        ans += getval(i)?1:0;
    for (int i = r*65536; i<=R; i++)
        ans += getval(i)?1:0;
    for (int i = l; i<r; i++)
    {
        int tmp = 0;
        if (val[i])
            tmp = 65536;
        else if (i==0)
            tmp = 61356;
        else
            tmp += cnt[suf[i]];
        ans += tmp;
    }
    cout << ans << '\n';
}
