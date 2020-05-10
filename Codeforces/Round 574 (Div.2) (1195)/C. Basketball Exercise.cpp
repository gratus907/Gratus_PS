#include <bits/stdc++.h>
#define ll long long
#define int ll
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

int dp[101010][2];
int arr[101010][2];
int32_t main()
{
    usecppio
    int n;
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        cin >> arr[i][0];
    }
    for (int i = 1; i<=n; i++)
    {
        cin >> arr[i][1];
    }
    for (int i = 1; i<=n; i++)
    {
        dp[i][0] = max(dp[i-1][1]+arr[i][0], dp[i-1][0]);
        dp[i][1] = max(dp[i-1][0]+arr[i][1], dp[i-1][1]);
    }
    cout << max(dp[n][0],dp[n][1]);
}
