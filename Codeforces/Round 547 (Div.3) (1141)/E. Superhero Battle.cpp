#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define mod 1000000007LL
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,long double> pid;

ll H;
ll n, d[210000];
ll parsum[210000];
ll roundcount = 0;
ll parsummin = INT_MAX;
int main()
{
    scanf("%lld %lld",&H,&n);
    for (int i = 0; i<n; i++)
    {
        scanf("%lld",d+i);
        if (i==0)
            parsum[i] = d[i];
        else
            parsum[i] = d[i]+parsum[i-1];
        parsummin = MIN(parsummin,parsum[i]);
    }
    ll total = parsum[n-1];
    if (total >= 0 && H+parsummin>0)
    {
        printf("-1");
        return 0;
    }
    else
    {
        ll u = H + parsummin;
        if (H+parsummin<=0)
        {
            int lp = 0;
            while(H>0)
            {
                H += d[lp%n];
                roundcount++;
                lp++;
                if (H<=0)
                {
                    printf("%lld",roundcount);
                    return 0;
                }
            }
        }
        else
        {
            ll k = u / abs(total);
            if (k>0)
                k--;
            if (k<0)
                k = 0;
            roundcount += k*n;
            H += total*k;
            int lp = 0;
            while(H>0)
            {
                H += d[lp%n];
                roundcount++;
                lp++;
                if (H<=0)
                {
                    printf("%lld",roundcount);
                    return 0;
                }
            }
        }
    }
}
