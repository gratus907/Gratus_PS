#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
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

vector <pii> edge;
vector <pii> allpair;
int n, k;
void printedge(int u, int v)
{
    cout << u << ' ' << v << '\n';
    return;
}
int32_t main()
{
    usecppio
    cin >> n;
    cin >> k;
    if (k > ((n-1)*(n-2))/2)
    {
        cout << -1;
        return 0;
    }
    int m = 0;
    int u = ((n-1)*(n-2))/2-k;
    for (int i = 2; i<=n; i++)
    {
        m++;
        edge.push_back({1,i});
    }
    for (int i = 2; i<n; i++)
    {
        for (int j = i+1; j<=n; j++)
        {
            allpair.push_back({i,j});
        }
    }
    for (int i = 0; i<u; i++)
    {
        m++;
        edge.push_back(allpair[i]);
    }
    cout << m << '\n';
    for (auto it:edge)
    {
        cout << it.first << ' ' << it.second << '\n';
    }
}
