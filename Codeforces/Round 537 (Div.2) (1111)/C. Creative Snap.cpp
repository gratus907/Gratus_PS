#include <bits/stdc++.h>
#define int long long
#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)<(B)?(A):(B)
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define mod 1000000007LL
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int avgers[102000];
int n,k,A,B;

int calcna(int left, int right)
{
    int na = (int)(upper_bound(avgers,avgers+k,right)-lower_bound(avgers,avgers+k,left));
    return na;
}

int burn(int left, int right)
{
    if (left==right)
    {
        int na = calcna(left,right);
        if (na==0)
            return A;
        else
            return na*B;
    }
    if (left > right)
        return 0;
    int cost=0;
    int na = calcna(left,right);
    if (na==0)
    {
        cost = A;
        return cost;
    }
    else
    {
        int singleburn = na*B*(right-left+1);
        int divcost = 0;
        divcost += (burn(left,(right+left)/2));
        divcost += (burn((right+left)/2+1,right));
        cost = MIN(singleburn,divcost);
        return cost;
    }
}

int32_t main()
{
    scanf("%lld %lld %lld %lld",&n,&k,&A,&B);
    for(int i = 0; i<k; i++)
        scanf("%lld",avgers+i);
    sort(avgers,avgers+k);
    int u;
    u = burn(1,(1<<(n)));
    printf("%lld",u);
}
