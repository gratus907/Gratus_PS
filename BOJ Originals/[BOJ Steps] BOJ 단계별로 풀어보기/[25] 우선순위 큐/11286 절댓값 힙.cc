#include <bits/stdc++.h>
#define lli long long int
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

priority_queue <pii, vector<pii>, greater<pii> > pq;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x;
        scanf("%d",&x);
        if (x==0)
        {
            if (pq.empty())
                printf("0\n");
            else
            {
                printf("%d\n",pq.top().second);
                pq.pop();
            }
        }
        else
            pq.push(MP(abs(x),x));

    }
}