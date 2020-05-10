#include <bits/stdc++.h>
#include <chrono>
#define int long long
#define ll long long
#define MAX(A,B) A>B?A:B
#define MIN(A,B) A>B?B:A
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/__gcd(A,B)*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
using namespace std;
using namespace std::chrono;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

ll n;
ll arr[10000100];
ll ans = LLONG_MAX;
int32_t main()
{
    ll ind[2] = {1,2};
    scanf("%lld",&n);
    for (int i = 1; i<=n; i++)
    {
        ll x;
        scanf("%lld",&x);
        if (arr[x] == 0)
        {
            arr[x] = i;
        }
        else
        {
            ll u = x;
            if (u < ans)
            {
                ans = u;
                ind[1] = i;
                ind[0] = arr[x];
            }
        }
    }
    for (int i = 1; i<=10000000; i++)
    {
        int c = 0;
        int tp[2];
        int tpind[2];
        for (int j = i; j<=10000000; j+=i)
        {
            if (arr[j])
            {
                tp[c] = j;
                tpind[c] = arr[j];
                c++;
            }
            if (c==2)
            {
                ll u = lcm(tp[0],tp[1]);
                if (u <= ans)
                {
                    ans = u;
                    ind[0] = tpind[0];
                    ind[1] = tpind[1];
                }
                break;
            }
        }
    }
    if (ind[0] > ind[1])
    {
        printf("%lld %lld",ind[1], ind[0]);
    }
    else
        printf("%lld %lld",ind[0], ind[1]);
}
