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
vector <pii> work;
int curt = 0;
int32_t main()
{
    usecppio
    int n;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        ll a, b;
        cin >> a >> b;
        work.push_back({b,a});
    }
    sort(all(work));
    for (auto it:work)
    {
        curt += it.second;
        if (curt > it.first)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}
