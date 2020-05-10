#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
int a, b;
int ans = 0;
inline int ksum(int l, int r, int k)
{
    int s = r*(r+1)/2;
    int t = (l-1)*l/2;
    return (s-t)*k;
}

int ask(int x)
{
    int res = 0;
    int s = (a-1)/x + 1;
    for (int i = s*x; i<=b; i+=x)
    {
        if (i/x < x)
            continue;
        if (i == x*x)
            res += x;
        else
        {
            res += x;
            res += i/x;
        }
    }
    return res;
}
int32_t main()
{
    cin >> a >> b;
    for (int i = 1; i*i<=b; i++)
    {
        //printf("%lld : %lld\n",i,ask(i));
        ans += ask(i);
    }
    cout << ans;
}
