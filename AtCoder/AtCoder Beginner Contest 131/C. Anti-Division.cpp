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
ll a,b,c,d;
ll cdiv, ddiv;
ll udiv;
int main()
{
    cin >> a >> b >> c >> d;
    ll u = lcm(c,d);
    cdiv = (b/c)-((a-1)/c);
    ddiv = (b/d)-((a-1)/d);
    udiv = (b/u)-((a-1)/u);
    cout << ((b-a+1)-(cdiv+ddiv) + udiv) << '\n';
}
