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
#define mod 1000000007LL
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

ll a[202000];
int main()
{
    ll n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    for (int i = 0; i<n; i++)
        scanf("%lld",a+i);
    sort(a,a+n);
    ll m1 = a[n-1];
    ll m2 = a[n-2];
    ll c = (ll)(m/(k+1));
    printf("%lld",c*m2+(m-c)*m1);
}
