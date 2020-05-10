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
vector <pii> arr;
int tot;
int main()
{
    int n, l;
    scanf("%d %d",&n,&l);
    for (int i = 1; i<=n; i++)
    {
        arr.push_back({abs(l+i-1),l+i-1});
        tot += (l+i-1);
    }
    sort(all(arr));
    tot-=(arr[0].second);
    cout << tot;
}
