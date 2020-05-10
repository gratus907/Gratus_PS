#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)<(B)?(A):(B)
#define gcd(A,B) __gcd(A,B)
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
typedef pair<ll,ll> pll;

vector <pii> bus;
int main()
{
    int n, t;
    scanf("%d%d",&n,&t);
    for (int i = 1; i<=n; i++)
    {
        int s, d;
        scanf("%d%d",&s,&d);
        for (int j = 0; s+d*j < 102000; j++)
        {
            bus.PB(MP(s+d*j,i));
            if (s+d*j==t)
            {
                printf("%d",i);
                return 0;
            }
        }
    }
    sort(bus.begin(), bus.end());
    pii x = bus[lower_bound(bus.begin(), bus.end(), MP(t, 0)) - bus.begin()];
    int u = x.second;
    printf("%d",u);
}
