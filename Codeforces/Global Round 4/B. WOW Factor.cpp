#include <bits/stdc++.h>
#define int ll
#define ll long long
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

using pii = pair<int, int>;

char str[1010101];
int tw = 0;
int ans = 0;
string constructed;
int32_t main()
{
    int cw = 0;
    scanf("%s",str+1);
    int n = strlen(str+1);
    for (int i = 1; i<=n; i++)
    {
        if (str[i]=='v' && str[i-1]=='v')
        {
            constructed.push_back('w');
            tw++;
        }
        if (str[i]=='o')
            constructed.push_back('o');
    }
    for (auto it:constructed)
    {
        if (it=='w')
            cw++;
        if (it=='o')
        {
            ans += (cw * (tw-cw));
        }
    }
    printf("%lld",ans);
}
