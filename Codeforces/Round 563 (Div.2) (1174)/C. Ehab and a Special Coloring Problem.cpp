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

const int BIGNUM = 101010;
int arr[101010];
int pcount = 1;
int p[BIGNUM];
bool is_composite[BIGNUM];
void sieve()
{
    for (int i = 2; i <= BIGNUM; i++)
    {
        if (!is_composite[i])
        {
            p[pcount++] = i;
            for (int j = i * 2; j <= BIGNUM; j += i)
                is_composite[j] = true;
        }
    }
}

int least_prime_div(int k)
{
    for (int i = 1; i<=pcount; i++)
    {
        if (k%p[i]==0)
        {
            return i;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    sieve();
    for (int i = 2; i<=n; i++)
    {
        printf("%d ",least_prime_div(i));
    }
}
