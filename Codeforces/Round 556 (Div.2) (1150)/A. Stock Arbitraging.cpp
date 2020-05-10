#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)<(B)?(A):(B)
#define gcd(A,B) __gcd(A,B)
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

int buy[35], sell[35];

int main()
{
    int n, m, r;
    scanf("%d %d %d",&n,&m,&r);
    int minbuy = INT_MAX;
    int maxsell = INT_MIN;
    for (int i = 0; i<n; i++)
    {
        scanf("%d",buy+i);
        minbuy = MIN(buy[i],minbuy);
    }
    for (int i = 0; i<m; i++)
    {
        scanf("%d",sell+i);
        maxsell = MAX(sell[i],maxsell);
    }
    int t = r/minbuy;
    printf("%d",MAX(r,(r - t*minbuy + t*maxsell)));
}
