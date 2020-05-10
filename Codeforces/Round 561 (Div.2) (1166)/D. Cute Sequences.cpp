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

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;
typedef pair<ll, ll> pll;
ll maxi, mini;
inline ll pow2(ll x)
{
    ll ans = (1<<(x/3));
    ans *= (1<<(x/3));
    ans *= (1<<(x-x/3-x/3));
    return ans;
}

pll maxminval(ll n, ll x1, ll m)
{
    return MP((pow2(n-2)*x1+pow2(n-2)),(pow2(n-2)*x1+pow2(n-2)*m));
}

ll arr[60];
ll rem[60];
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        memset(arr,0,sizeof(arr));
        memset(rem,0,sizeof(rem));
        ll a, b, m;
        scanf("%lld %lld %lld",&a,&b,&m);
        ll n = 2;
        bool flag = 0;
        if (a==b)
        {
            printf("1 %lld\n",a);
            continue;
        }
        while(a<=b)
        {
            pll range = maxminval(n,a,m);
            if (range.first>b)
            {
                flag = 0;
                break;
            }
            if (range.first<=b && b <= range.second)
            {
                flag = 1;
                break;
            }
            if (n>50)
            {
                flag = 0;
                break;
            }
            n++;
        }
        if (!flag)
        {
            printf("-1\n");
            continue;
        }
        else
        {
            if (n == 2)
            {
                printf("2 %lld %lld\n",a,b);
                continue;
            }
            arr[1] = a;
            for (int i = 2; i<=n; i++)
            {
                arr[i] = a*(pow2(i-2));
            }
            ll gap = b-(a*pow2(n-2));
            for (int i = 2; i<=n; i++)
            {
                rem[i] = 1;
            }
            gap -= pow2(n-2);
            for (int i = 2; i<=n-1; i++)
            {
                ll r = gap/(pow2(n-i-1));
                r = MIN(m-1,r);
                rem[i] += r;
                gap -= r*(pow2(n-i-1));
            }
            if (gap)
            {
                rem[n] += gap;
                gap = 0;
            }
            for (int i = 2; i<=n; i++)
            {
                for (int j = 2; j<i; j++)
                {
                    arr[i] += rem[j]*(pow2(i-j-1));
                }
                arr[i] += rem[i];
            }

            printf("%lld ",n);
            for (int i = 1; i<=n; i++)
                printf("%lld ",arr[i]);
            printf("\n");
        }
    }
}
