#include <bits/stdc++.h>
#define lli long long
#define int long long
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

int arr[201000];
vector <pii> v;
vector <int> v2;
int n,m,k;
int32_t main()
{
    int sum=0;
    scanf("%lld %lld %lld",&n,&m,&k);
    for (int i = 1; i<=n; i++)
    {
        scanf("%lld",arr+i);
        v.PB(MP(arr[i],i));
    }
    sort(v.begin(),v.end(),greater<pii>());
    for (int i = 0; i<m*k; i++)
    {
        sum+=v[i].first;
        v2.PB(v[i].second);
    }
    sort(v2.begin(),v2.end());
    printf("%lld\n",sum);
    for (int i = 1; i<k; i++)
        printf("%lld ",v2[i*m]-1);

}
