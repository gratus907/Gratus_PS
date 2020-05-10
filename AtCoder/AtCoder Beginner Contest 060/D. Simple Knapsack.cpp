#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll item[4][102];
int pt[4] = {1,1,1,1};
int main()
{
    ll n,w;
    ll w0 = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    for (int i = 1; i<=n; i++)
    {
        ll wi, vi;
        cin >> wi >> vi;
        if (i==1)
        {
            item[0][1] = vi;
            w0 = wi;
            pt[0]++;
        }
        else
        {
            item[wi-w0][pt[wi-w0]] = vi;
            pt[wi-w0]++;
        }
    }
    sort(item[0]+1, item[0]+n, greater<ll>());
    sort(item[1]+1, item[1]+n, greater<ll>());
    sort(item[2]+1, item[2]+n, greater<ll>());
    sort(item[3]+1, item[3]+n, greater<ll>());
    for (int i = 2; i<=n; i++)
    {
        item[0][i] = item[0][i-1]+item[0][i];
        item[1][i] = item[1][i-1]+item[1][i];
        item[2][i] = item[2][i-1]+item[2][i];
        item[3][i] = item[3][i-1]+item[3][i];

    }
    ll ans = 0;
    for (int a = 0; a<=n; a++)
    {
        if (a*w0>w)
            break;
        for (int b = 0; b<=n; b++)
        {
            if (a*w0 + (b*(w0+1))>w)
                break;
            for (int c = 0; c<=n; c++)
            {
                if (a*w0 + (b*(w0+1)) + c*(w0+2)>w)
                    break;
                for (int d = 0; d<=n; d++)
                {
                    if (a*w0 + (b*(w0+1)) + c*(w0+2)+d*(w0+3)>w)
                        break;
                    ans = max(ans,item[0][a]+item[1][b]+item[2][c]+item[3][d]);
                }
            }
        }
    }
    printf("%lld",ans);
}
