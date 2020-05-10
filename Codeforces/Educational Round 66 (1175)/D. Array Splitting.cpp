#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define int long long
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

typedef pair<int, int> pii;

int arr[303030];
ll ans = 0;
int mark[303030];
vector <pii> vec;
int32_t main()
{
    usecppio
    int n, k;
    cin >> n >> k;
    for (int i = 0; i<n; i++)
        cin >> arr[i];
    int cur = 0;
    for (int i = 0; i<(n-1); i++)
    {
        cur += arr[i];
        vec.push_back({cur,i});
    }
    sort(all(vec));
    for (int i = 0; i<k-1; i++)
    {
        mark[vec[i].second] = 1;
    }
    ll u = 1;
    for (int i = 0; i<n; i++)
    {
        ans += (arr[i]*u);
        if (mark[i])
            u++;
    }
    cout << ans << '\n';
}
