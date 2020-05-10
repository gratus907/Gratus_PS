#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define mod ((long long)(1e9+7))
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

ll ans, candy[201000], accum[201000],evens[201000],odds[201000];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i<=n; i++)
    {
        scanf("%lld",candy+i);
        if (i==1)
            odds[1] = candy[1];
        accum[i] = accum[i-1]+candy[i];
        if (i%2==0)
            evens[i] += evens[i-2]+candy[i];
        if (i%2==1 && i>1)
            odds[i] += odds[i-2]+candy[i];
    }


    ll total = accum[n];
    ll oddtotal = MAX(odds[n],odds[n-1]);
    ll eventotal = MAX(evens[n],evens[n-1]);

    if (eventotal == oddtotal-candy[1])
        ans++;
    for (int i = 2; i<=n; i++)
    {
        if ((total-candy[i])%2)
            continue;
        if (i%2==0)
        {
            ll evensum = evens[i-2];
            evensum += oddtotal - odds[i-1];
            if (evensum==(total-candy[i])/2)
                ans++;
        }
        if (i%2==1)
        {
            ll oddsum = odds[i-2];
            oddsum += eventotal-evens[i-1];
            if (oddsum == (total-candy[i])/2)
                ans++;
        }
    }
    printf("%lld",ans);

}
