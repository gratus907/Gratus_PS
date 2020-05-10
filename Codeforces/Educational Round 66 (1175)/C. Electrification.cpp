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

int pt[202020];
int n,k;
void query()
{
    cin >> n >> k;
    for (int i = 0; i<n; i++)
    {
        cin >> pt[i];
    }
    int mndst = INT_MAX;
    int mndp = 0;
    for (int i = 0; i<(n-k); i++)
    {
        int u = (pt[i+k]-pt[i]);
        if (u<mndst)
        {
            mndst = u;
            mndp = i;
        }
    }
    cout << pt[mndp]+mndst/2 << '\n';
}
int main()
{
    usecppio
    int t;
    cin >> t;
    while(t--)
        query();
}
