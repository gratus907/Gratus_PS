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

int c;
int main()
{
    int a, b, k;
    scanf("%d %d %d",&a,&b,&k);
    int g = gcd(a,b);
    for (int i = g; i>=1; i--)
    {
        if (g%i==0)
            c++;
        if (c==k)
        {
            printf("%d",i);
            return 0;
        }
    }
}
