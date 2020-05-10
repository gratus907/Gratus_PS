#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define gcd(A,B) (__gcd(A,B))
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define mod 1000000007LL
#define all(x) x.begin(), x.end()
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

void query()
{
    ll n, k;
    scanf("%lld %lld",&n,&k);
    ll ans = 0;
    while(n>0)
    {
        if (n%k==0)
        {
            n/=k;
            ans ++;
        }
        else
        {
            ll t = n/k;
            ll u = t*k;
            ans += (n-u);
            n = u;
        }
    }
    printf("%lld\n",ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        query();
    }
}
