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

int n, m;
int arr[202020];
ll prefsum[202020];
ll solve(int p)
{
    ll time = prefsum[p];
    priority_queue<int> pq;
    for (int i = 1; i<p; i++)
        pq.push(arr[i]);
    ll ans = 0;
    while(time>m)
    {
        ll x = pq.top();
        time -= x;
        ans++;
        pq.pop();
    }
    return ans;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i = 1; i<=n; i++)
    {
        scanf("%d",arr+i);
        prefsum[i] = prefsum[i-1]+arr[i];
    }
    for (int i = 1; i<=n; i++)
        printf("%lld ",solve(i));
}
