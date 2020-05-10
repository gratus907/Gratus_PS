#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) A>B?A:B
#define MIN(A,B) A<B?A:B
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

lli seq[203000];
lli bseq[203000];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i<=(n/2); i++)
    {
        scanf("%lld",&bseq[i]);
    }
    seq[1] = 0;
    seq[n] = bseq[1];
    for (int i = 2; i<=(n/2); i++)
    {
        seq[n-i+1] = MIN(bseq[i],seq[n-i+2]);
        seq[i] = bseq[i] - seq[n-i+1];
        if (seq[i] < seq[i-1])
        {
            seq[i] = seq[i-1];
            seq[n-i+1] = bseq[i] - seq[i];
        }
    }
    for (int i = 1; i<=n; i++)
    {
        printf("%lld ",seq[i]);
    }
}